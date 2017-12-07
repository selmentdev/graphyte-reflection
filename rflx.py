import os
import os.path
import clang.cindex


class GraphyteTypeBase:
    def __init__(self, cursor):
        self.cursor = cursor
        self.annotations = [x for x in cursor.get_children() if x.kind == clang.cindex.CursorKind.ANNOTATE_ATTR]

    @property
    def access_specifier(self):
        return self.cursor.access_specifier

    @property
    def fullname(self):
        result = self.cursor.spelling
        node = self.cursor.semantic_parent
        while node is not None and not node.kind.is_translation_unit():
            result = node.spelling + '::' + result
            node = node.semantic_parent
        return '::' + result

    @property
    def safe_demangled_name(self):
        result = self.cursor.spelling
        node = self.cursor.semantic_parent
        while node is not None and not node.kind.is_translation_unit():
            result = node.spelling + '__' + result
            node = node.semantic_parent
        return result

    def emit_code(self, output):
        output.write('\n')
        output.write('//\n')
        output.write('// {0}\n'.format(self.fullname))
        output.write('//\n')
        output.write('// Attributes:\n')
        for e in self.annotations:
            output.write('// - `{0}`\n'.format(e.spelling));
        output.write('//\n')
        output.write('\n')

        pass

    def emit_forward_declaration(self, output):
        pass

class GraphyteEnum(GraphyteTypeBase):
    def __init__(self, cursor):
        GraphyteTypeBase.__init__(self, cursor)
        self.values = [x.spelling for x in cursor.get_children() if x.kind == clang.cindex.CursorKind.ENUM_CONSTANT_DECL]

    def emit_code(self, output):
        GraphyteTypeBase.emit_code(self, output)

        output.write('struct {{ {1} value; const char* name; }}\nconst __{0}_EnumValues[] = {{\n'.format(self.safe_demangled_name, self.fullname))
        for v in self.values:
            output.write('    {{ {0}::{1}, "{1}" }}\n'.format(self.fullname, v))
        output.write('};\n')
        output.write('\n')

        output.write('const char* ToString({0} value) noexcept {{\n'. format(self.fullname))
        output.write('    for (size_t i = 0; i < sizeof(__{0}_EnumValues) / sizeof(__{0}_EnumValues[0]); ++i) {{\n'.format(self.safe_demangled_name))
        output.write('        if (__{0}_EnumValues[i].value == value) {{\n'.format(self.safe_demangled_name))
        output.write('            return __{0}_EnumValues[i].name;\n'.format(self.safe_demangled_name))
        output.write('        }\n')
        output.write('    }\n')
        output.write('    return nullptr;\n')
        output.write('};\n')
        output.write('\n')

    def emit_forward_declaration(self, output):
        super(GraphyteEnum, self).emit_forward_declaration(output)

        output.write('template<> struct TypeToTypeId<{0}> final {{ \n'.format(self.fullname))
        output.write('    static constexpr const uint64_t Id = fnv1a64("{0}");\n'.format(self.fullname))
        output.write('};\n')

class GraphyteClass(GraphyteTypeBase):
    def __init__(self, cursor):
        GraphyteTypeBase.__init__(self, cursor)
        self.fields = [x for x in cursor.get_children() if x.kind == clang.cindex.CursorKind.FIELD_DECL]
        self.base_classes = [x for x in cursor.get_children() if x.kind == clang.cindex.CursorKind.CXX_BASE_SPECIFIER]

    @property
    def base_class(self):
        return self.base_classes[0] if len(self.base_classes) > 0 else None

    @property
    def base_class_ref(self):
        bc = self.base_class
        if bc is None:
            return 'nullptr'
        else:
            return 'TypeOf<{0}>'.format(bc.spelling)

    def emit_code(self, output):
        GraphyteTypeBase.emit_code(self, output)

        output.write('const Field __{0}_Fields[] = {{\n'.format(self.safe_demangled_name))
        for f in self.fields:
            output.write('    {{\n        {0},\n        TypeToTypeId<decltype(reinterpret_cast<{2}*>(nullptr)->{1})>::Id,\n        "{1}",\n        offsetof({2}, {1}),\n        sizeof(reinterpret_cast<{2}*>(nullptr)->{1})\n    }},\n'.format(
                GraphyteClass._field_access_to_string(f.access_specifier),
                f.spelling,
                self.fullname))

        output.write('    { AccessSpecifier::Invalid, 0, 0 },\n')
        output.write('};\n')

        output.write('\n')
        output.write('const Type __{0}_Type = {{\n'.format(self.safe_demangled_name))
        output.write('    {0},\n'.format(self.base_class_ref))
        output.write('    "{0}",\n'.format(self.fullname))
        output.write('    __{0}_Fields,\n'.format(self.safe_demangled_name))
        output.write('};\n')

    def emit_forward_declaration(self, output):
        super(GraphyteClass, self).emit_forward_declaration(output)

        output.write('extern const Type __{0}_Type;\n'.format(self.safe_demangled_name))
        output.write('\n')
        output.write('template<> struct TypeOfImpl<{0}> final {{\n'.format(self.fullname))
        output.write('    static const Type* GetType() noexcept {\n')
        output.write('        return &__{0}_Type;\n'.format(self.safe_demangled_name))
        output.write('    }\n')
        output.write('};\n')
        output.write('\n')

    @staticmethod
    def _field_access_to_string(kind):
        if kind == clang.cindex.AccessSpecifier.PRIVATE:
            return "AccessSpecifier::Private"
        if kind == clang.cindex.AccessSpecifier.PROTECTED:
            return "AccessSpecifier::Protected"
        if kind == clang.cindex.AccessSpecifier.PUBLIC:
            return "AccessSpecifier::Public"
        return "AccessSpecifier::Invalid";

class GraphyteReflectionSourceGenerator:
    def __init__(self):
        self.classes = []
        self.structures = []
        self.enums = []

        clang.cindex.Config.set_library_path("D:/Program Files/LLVM/bin")

        self.m_ClangIndex = clang.cindex.Index.create(True);

    def build(self, file_name, output_file_name):
        translation_unit = self.m_ClangIndex.parse(
            file_name,
            options = clang.cindex.TranslationUnit.PARSE_INCOMPLETE
                    | clang.cindex.TranslationUnit.PARSE_DETAILED_PROCESSING_RECORD
                    | clang.cindex.TranslationUnit.PARSE_PRECOMPILED_PREAMBLE
                    | clang.cindex.TranslationUnit.PARSE_SKIP_FUNCTION_BODIES,
            args = ['-fsyntax-only', '-x', 'c++']
            )
        root_node = translation_unit.cursor
        self.walk_ast(root_node, 0)

        with open(output_file_name, 'w') as output_file:
            output_file.write('// generated from {0}\n'.format(file_name))
            for e in self.enums:
                e.emit_forward_declaration(output_file)

            for c in self.classes:
                c.emit_forward_declaration(output_file)

            for e in self.enums:
                e.emit_code(output_file)

            for c in self.classes:
                c.emit_code(output_file)

    
    def walk_ast(self, node, level):
        if node is not None:
            level = level + 1
            self.visit_node(node, level)

        for childNode in node.get_children():
            self.walk_ast(childNode, level)
        level = level - 1

    def visit_node(self, node, level):
        print(str(node.kind) + ' = ' + node.spelling)
        if node.kind == clang.cindex.CursorKind.CLASS_DECL:
            self.classes.append(GraphyteClass(node))
        if node.kind == clang.cindex.CursorKind.ENUM_DECL:
            self.enums.append(GraphyteEnum(node))

def main():
    try:
        generator = GraphyteReflectionSourceGenerator()
        generator.build(os.path.join(os.getcwd(), "test.cpp"), os.path.join(os.getcwd(), "test.rxx.cxx"))
    except ValueError as err:
        print(err.message)
        print(err.args)
    except clang.cindex.TranslationUnitLoadError as err:
        print(err.message)
        print(err.args)

if __name__ == "__main__":
    main()



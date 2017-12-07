// generated from D:\github\graphyte-reflection\test.cpp
template<> struct TypeToTypeId<::Graphyte::System::MyEnum> final { 
    static constexpr const uint64_t Id = fnv1a64("::Graphyte::System::MyEnum");
};
template<> struct TypeToTypeId<::Graphyte::System::OtherKind::PrivateEnum> final { 
    static constexpr const uint64_t Id = fnv1a64("::Graphyte::System::OtherKind::PrivateEnum");
};
template<> struct TypeToTypeId<::Graphyte::System::OtherKind::PublicEnum> final { 
    static constexpr const uint64_t Id = fnv1a64("::Graphyte::System::OtherKind::PublicEnum");
};
template<> struct TypeToTypeId<::Graphyte::System::OtherKind::ProtectedEnum> final { 
    static constexpr const uint64_t Id = fnv1a64("::Graphyte::System::OtherKind::ProtectedEnum");
};
extern const Type __Graphyte__System__A_Type;

template<> struct TypeOfImpl<::Graphyte::System::A> final {
    static const Type* GetType() noexcept {
        return &__Graphyte__System__A_Type;
    }
};

extern const Type __Graphyte__System__B_Type;

template<> struct TypeOfImpl<::Graphyte::System::B> final {
    static const Type* GetType() noexcept {
        return &__Graphyte__System__B_Type;
    }
};

extern const Type __Graphyte__System__C_Type;

template<> struct TypeOfImpl<::Graphyte::System::C> final {
    static const Type* GetType() noexcept {
        return &__Graphyte__System__C_Type;
    }
};

extern const Type __Graphyte__System__D_Type;

template<> struct TypeOfImpl<::Graphyte::System::D> final {
    static const Type* GetType() noexcept {
        return &__Graphyte__System__D_Type;
    }
};

extern const Type __Graphyte__System__Test_Type;

template<> struct TypeOfImpl<::Graphyte::System::Test> final {
    static const Type* GetType() noexcept {
        return &__Graphyte__System__Test_Type;
    }
};

extern const Type __Graphyte__System__OtherKind_Type;

template<> struct TypeOfImpl<::Graphyte::System::OtherKind> final {
    static const Type* GetType() noexcept {
        return &__Graphyte__System__OtherKind_Type;
    }
};


//
// ::Graphyte::System::MyEnum
//
// Attributes:
// - `reflected, default = Value3`
//

struct { ::Graphyte::System::MyEnum value; const char* name; }
const __Graphyte__System__MyEnum_EnumValues[] = {
    { ::Graphyte::System::MyEnum::Value1, "Value1" }
    { ::Graphyte::System::MyEnum::Value2, "Value2" }
    { ::Graphyte::System::MyEnum::Value3, "Value3" }
};

const char* ToString(::Graphyte::System::MyEnum value) noexcept {
    for (size_t i = 0; i < sizeof(__Graphyte__System__MyEnum_EnumValues) / sizeof(__Graphyte__System__MyEnum_EnumValues[0]); ++i) {
        if (__Graphyte__System__MyEnum_EnumValues[i].value == value) {
            return __Graphyte__System__MyEnum_EnumValues[i].name;
        }
    }
    return nullptr;
};


//
// ::Graphyte::System::OtherKind::PrivateEnum
//
// Attributes:
// - `reflected`
//

struct { ::Graphyte::System::OtherKind::PrivateEnum value; const char* name; }
const __Graphyte__System__OtherKind__PrivateEnum_EnumValues[] = {
    { ::Graphyte::System::OtherKind::PrivateEnum::Pix1, "Pix1" }
    { ::Graphyte::System::OtherKind::PrivateEnum::Pix2, "Pix2" }
    { ::Graphyte::System::OtherKind::PrivateEnum::Pix3, "Pix3" }
};

const char* ToString(::Graphyte::System::OtherKind::PrivateEnum value) noexcept {
    for (size_t i = 0; i < sizeof(__Graphyte__System__OtherKind__PrivateEnum_EnumValues) / sizeof(__Graphyte__System__OtherKind__PrivateEnum_EnumValues[0]); ++i) {
        if (__Graphyte__System__OtherKind__PrivateEnum_EnumValues[i].value == value) {
            return __Graphyte__System__OtherKind__PrivateEnum_EnumValues[i].name;
        }
    }
    return nullptr;
};


//
// ::Graphyte::System::OtherKind::PublicEnum
//
// Attributes:
// - `reflected`
//

struct { ::Graphyte::System::OtherKind::PublicEnum value; const char* name; }
const __Graphyte__System__OtherKind__PublicEnum_EnumValues[] = {
    { ::Graphyte::System::OtherKind::PublicEnum::One, "One" }
    { ::Graphyte::System::OtherKind::PublicEnum::Two, "Two" }
    { ::Graphyte::System::OtherKind::PublicEnum::Three, "Three" }
};

const char* ToString(::Graphyte::System::OtherKind::PublicEnum value) noexcept {
    for (size_t i = 0; i < sizeof(__Graphyte__System__OtherKind__PublicEnum_EnumValues) / sizeof(__Graphyte__System__OtherKind__PublicEnum_EnumValues[0]); ++i) {
        if (__Graphyte__System__OtherKind__PublicEnum_EnumValues[i].value == value) {
            return __Graphyte__System__OtherKind__PublicEnum_EnumValues[i].name;
        }
    }
    return nullptr;
};


//
// ::Graphyte::System::OtherKind::ProtectedEnum
//
// Attributes:
// - `reflected`
//

struct { ::Graphyte::System::OtherKind::ProtectedEnum value; const char* name; }
const __Graphyte__System__OtherKind__ProtectedEnum_EnumValues[] = {
    { ::Graphyte::System::OtherKind::ProtectedEnum::One, "One" }
    { ::Graphyte::System::OtherKind::ProtectedEnum::Two, "Two" }
    { ::Graphyte::System::OtherKind::ProtectedEnum::Three, "Three" }
};

const char* ToString(::Graphyte::System::OtherKind::ProtectedEnum value) noexcept {
    for (size_t i = 0; i < sizeof(__Graphyte__System__OtherKind__ProtectedEnum_EnumValues) / sizeof(__Graphyte__System__OtherKind__ProtectedEnum_EnumValues[0]); ++i) {
        if (__Graphyte__System__OtherKind__ProtectedEnum_EnumValues[i].value == value) {
            return __Graphyte__System__OtherKind__ProtectedEnum_EnumValues[i].name;
        }
    }
    return nullptr;
};


//
// ::Graphyte::System::A
//
// Attributes:
//

const Field __Graphyte__System__A_Fields[] = {
    { AccessSpecifier::Invalid, 0, 0 },
};

const Type __Graphyte__System__A_Type = {
    nullptr,
    "::Graphyte::System::A",
    __Graphyte__System__A_Fields,
};

//
// ::Graphyte::System::B
//
// Attributes:
//

const Field __Graphyte__System__B_Fields[] = {
    { AccessSpecifier::Invalid, 0, 0 },
};

const Type __Graphyte__System__B_Type = {
    TypeOf<class Graphyte::System::A>,
    "::Graphyte::System::B",
    __Graphyte__System__B_Fields,
};

//
// ::Graphyte::System::C
//
// Attributes:
//

const Field __Graphyte__System__C_Fields[] = {
    { AccessSpecifier::Invalid, 0, 0 },
};

const Type __Graphyte__System__C_Type = {
    nullptr,
    "::Graphyte::System::C",
    __Graphyte__System__C_Fields,
};

//
// ::Graphyte::System::D
//
// Attributes:
//

const Field __Graphyte__System__D_Fields[] = {
    { AccessSpecifier::Invalid, 0, 0 },
};

const Type __Graphyte__System__D_Type = {
    TypeOf<class Graphyte::System::B>,
    "::Graphyte::System::D",
    __Graphyte__System__D_Fields,
};

//
// ::Graphyte::System::Test
//
// Attributes:
// - `reflected`
//

const Field __Graphyte__System__Test_Fields[] = {
    {
        AccessSpecifier::Public,
        TypeToTypeId<decltype(reinterpret_cast<::Graphyte::System::Test*>(nullptr)->m_PublicButHidden)>::Id,
        "m_PublicButHidden",
        offsetof(::Graphyte::System::Test, m_PublicButHidden),
        sizeof(reinterpret_cast<::Graphyte::System::Test*>(nullptr)->m_PublicButHidden)
    },
    {
        AccessSpecifier::Public,
        TypeToTypeId<decltype(reinterpret_cast<::Graphyte::System::Test*>(nullptr)->m_PublicString)>::Id,
        "m_PublicString",
        offsetof(::Graphyte::System::Test, m_PublicString),
        sizeof(reinterpret_cast<::Graphyte::System::Test*>(nullptr)->m_PublicString)
    },
    {
        AccessSpecifier::Private,
        TypeToTypeId<decltype(reinterpret_cast<::Graphyte::System::Test*>(nullptr)->m_PrivateFloat)>::Id,
        "m_PrivateFloat",
        offsetof(::Graphyte::System::Test, m_PrivateFloat),
        sizeof(reinterpret_cast<::Graphyte::System::Test*>(nullptr)->m_PrivateFloat)
    },
    {
        AccessSpecifier::Protected,
        TypeToTypeId<decltype(reinterpret_cast<::Graphyte::System::Test*>(nullptr)->m_ProtectedInteger)>::Id,
        "m_ProtectedInteger",
        offsetof(::Graphyte::System::Test, m_ProtectedInteger),
        sizeof(reinterpret_cast<::Graphyte::System::Test*>(nullptr)->m_ProtectedInteger)
    },
    { AccessSpecifier::Invalid, 0, 0 },
};

const Type __Graphyte__System__Test_Type = {
    nullptr,
    "::Graphyte::System::Test",
    __Graphyte__System__Test_Fields,
};

//
// ::Graphyte::System::OtherKind
//
// Attributes:
// - `description("Simple class descrption")`
// - `reflected`
//

const Field __Graphyte__System__OtherKind_Fields[] = {
    { AccessSpecifier::Invalid, 0, 0 },
};

const Type __Graphyte__System__OtherKind_Type = {
    TypeOf<class Graphyte::System::Test>,
    "::Graphyte::System::OtherKind",
    __Graphyte__System__OtherKind_Fields,
};

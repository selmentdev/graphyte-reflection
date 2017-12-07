#if defined(__INTELLISENSE__)
#define META(...)
#else
#define META(...)   __attribute__((__annotate__(#__VA_ARGS__)))
#endif

namespace Graphyte::System
{
    class A
    {
    };

    class B : public A
    {
    };

    class C
    {
    };

    class D : public B, public C
    {
    };

    enum META(reflected, default = Value3) MyEnum
    {
        Value1,
        Value2,
        Value3
    };

    class META(reflected) Test
    {
    public:
        void dupa();

        META(description("Description"))
        META(hide)
        std::uint32_t m_PublicButHidden;

        std::string m_PublicString;

    private:
        float m_PrivateFloat;

    protected:
        META(reflected) META(default(-1))
        std::ptrdiff_t m_ProtectedInteger;
    };

    class META(reflected) META(description("Simple class descrption")) OtherKind : public Test
    {
    private:
        enum class META(reflected) PrivateEnum
        {
            Pix1,
            Pix2,
            Pix3,
        };

    public:
        enum class META(reflected) PublicEnum
        {
            One,
            Two,
            Three
        };

    protected:
        enum class META(reflected) ProtectedEnum
        {
            One,
            Two,
            Three
        };
    };
}
#ifndef __TEST_STD_H
#define __TEST_STD_H

/* vzor pro odvozeni dalsich testu - nemodifikovat */
#include <gepro/string.h>
namespace qq {
  struct stringx { 
    const char* ptr;
    stringx() { ptr = nullptr; } 
    explicit stringx(const char* p) { ptr = p; } 
    stringx& operator =(const char* p) {ptr=p;return *this; }
    const char* c_str() const { return ptr; }
  };
  template <typename O>
  O& operator <<(O& o, const stringx& str) { o << str.c_str(); return o; }
  void _tstatbuf() {
    std::tstatbuf<1024> buf;
    char c = '|';
    short s = 23;
    int i = 111;
    long long ll = 1111111;
    float f = (float)3.14;
    double d = 3.14;
    POINT p = { 2,4 };
    cz::gepro::constchars cc("abc");
    stringx str("xyz");
    buf << s << c << i << c << ll << c << f << c << d << c << p << c << cc << c << str;
    const char* q = buf.c_str();
    UNUSED(q);
  }

}
class Test_STD : public CxxTest::TestSuite
{
public:
  void test_() {
    std::tstreambuf<4, std::string, cz::gepro::STLifacestring<std::string, char> > buf;
    buf.sputc('a');
    buf.sputc('a');
    buf.sputc('a');
    _DUMP(buf.begin());
    TS_ASSERT_EQUALS(buf.begin(), buf.sdata())
      TS_ASSERT_TEXT(buf.begin(), "aaa")
      buf.sputc('b');
    buf.sputc('b');
    buf.sputc('b');
    _DUMP(buf.begin());
    TS_ASSERT_EQUALS(buf.begin() == buf.sdata(), false)
      TS_ASSERT_TEXT(buf.begin(), "aaabbb")
      buf.sputc('c');
    _DUMP(buf.begin());
    TS_ASSERT_TEXT(buf.begin(), "aaabbbc")
      buf.sputc('c');
    _DUMP(buf.begin());
    TS_ASSERT_TEXT(buf.begin(), "aaabbbcc")
      buf.sputc('c');
    _DUMP(buf.begin());
    TS_ASSERT_TEXT(buf.begin(), "aaabbbccc")
  }
  void test_2() {
    std::tstreambuf<4, std::string, cz::gepro::STLifacestring<std::string, char> > buf;
    buf.sputc('a');
    buf.sputc('a');
    buf.sputc('a');
    buf.sputc('b');
    buf.sputc('b');
    buf.sputc('b');
    buf.sputc('c');
    buf.sputc('c');
    buf.sputc('c');
    _DUMP(buf.begin());
    TS_ASSERT_TEXT(buf.begin(), "aaabbbccc")
      std::string s = buf.GetBuffer();
    TS_ASSERT_TEXT(s.c_str(), "aaabbbccc")
  }
  void test_3() {
    std::tstatstreambuf<4> buf;
    buf.sputc('a');
    buf.sputc('a');
    buf.sputc('a');
    buf.sputc('b');
    buf.sputc('b');
    buf.sputc('b');
    buf.sputc('c');
    buf.sputc('c');
    buf.sputc('c');
    TS_ASSERT_TEXT(buf.c_str(), "aaa")
  }
  void test_2w() {
    std::tstreambuf<4, std::wstring, cz::gepro::STLifacestring<std::wstring, wchar_t>, wchar_t > buf;
    buf.sputc(L'a');
    buf.sputc(L'a');
    buf.sputc(L'a');
    buf.sputc(L'b');
    buf.sputc(L'b');
    buf.sputc(L'b');
    buf.sputc(L'c');
    buf.sputc(L'c');
    buf.sputc(L'c');
    std::wstring s = buf.GetBuffer();
    TS_ASSERT_TEXT(s.c_str(), L"aaabbbccc")
  }
  void test_3w() {
    std::tstatstreambuf<4, wchar_t> buf;
    buf.sputc(L'a');
    buf.sputc(L'a');
    buf.sputc(L'a');
    buf.sputc(L'b');
    buf.sputc(L'b');
    buf.sputc(L'b');
    buf.sputc(L'c');
    buf.sputc(L'c');
    buf.sputc(L'c');
    TS_ASSERT_TEXT(buf.c_str(), L"aaa")
  }
  void test_tstringbuf() {
    std::tstringbuf<4, std::string, cz::gepro::STLifacestring<std::string, char>, char > buf;
    buf << "aaa";
    buf << std::setprecision(10);
    TS_ASSERT_TEXT(buf.begin(), "aaa")
      buf << ' ';
    buf << "bbbccc";
    TS_ASSERT_TEXT(buf.begin(), "aaa bbbccc")
      std::string s = buf.GetBuffer();
    TS_ASSERT_TEXT(s.c_str(), "aaa bbbccc")
  }
  // overeni ze jde prelozit kombinace manipalator << pro pridane type
  void test_ostreamex() {
    std::tstringbuf<4, std::string, cz::gepro::STLifacestring<std::string, char> > buf;
    POINT p = { 1,2 };
    buf << std::setprecision(10) << p;
    buf << std::setw(10) << p;
    //buf << std::setbase(10) << p;
    buf << std::setfill('*') << p;
    //buf << std::setiosflags (std::ios::showbase | std::ios::uppercase) << p;
    buf << std::setw(10) << 10 << std::fixed;
    buf << std::setprecision(10) << std::fixed << 3.1456073;
  }
  void test_trimtstringbuf0() {
    std::tstringbuf<8, std::string, cz::gepro::STLifacestring<std::string, char> > buf;
    buf << "0123456789ABCDE";
    const char* q;
    buf.trimr(12, "..");
    q = buf.c_str();
    TS_ASSERT_TEXT(q, "0123456789..")
  }
  void test_trimtstringbuf1() {
    std::tstringbuf<8, std::string, cz::gepro::STLifacestring<std::string, char> > buf;
    buf << "0123456789";
    const char* q;
    buf.trimr(9, "..");
    q = buf.c_str();
    TS_ASSERT_TEXT(q, "0123456..")
  }
  void test_trimtstringbuf2() {
    std::tstringbuf<8, std::string, cz::gepro::STLifacestring<std::string, char> > buf;
    buf << "0123456789ABC";
    const char* q;
    buf.trimr(12, "..");
    q = buf.c_str();
    TS_ASSERT_TEXT(q, "0123456789..")
  }
  void test_trimtstatbuf() {
    std::tstatbuf<16> buf;
    buf << "0123456789ABC";
    const char* q;
    buf.trimr(12, "..");
    q = buf.c_str();
    TS_ASSERT_TEXT(q, "0123456789..")
  }
  void test_trimtstringbuf3() {
    std::tstringbuf<8, std::string,
      cz::gepro::STLifacestring<std::string, char> >
      buf;
    std::string s("0123456789ABC");
    buf << s;
    const char* q;
    buf.trimr(12, "..");
    q = buf.c_str();
    TS_ASSERT_TEXT(q, "0123456789..")
  }
  void test_trimtstatbuf3() {
    std::tstatbuf<16> buf;
    std::string s("0123456789ABC");
    buf << s;
    const char* q;
    buf.trimr(12, "..");
    q = buf.c_str();
    TS_ASSERT_TEXT(q, "0123456789..")
  }
  void test_tstatbuf() {
    std::tstatbuf<1024> buf;
    buf << "aaa";
    buf << std::setprecision(10);
    TS_ASSERT_TEXT(buf.begin(), "aaa")
      buf << ' ';
    buf << "bbbccc";
    TS_ASSERT_TEXT(buf.begin(), "aaa bbbccc")
      char c = '|';
    short s = 23;
    int i = 111;
    long long ll = 1111111;
    float f = (float)3.14;
    double d = 3.14;
    POINT p = { 2,4 };
    cz::gepro::constchars cc("abc");
    std::string str("xyz");
    buf << s << c << i << c << ll << c << f << c << d << c << p << c << cc << c << str;
    qq::_tstatbuf();
    const char* q = buf.c_str();
    UNUSED(q)
  }
  void test_tstatbufw() {
    std::tstatbuf<1024, wchar_t > buf;
    buf << L"aaa";
    buf << std::setprecision(10);
    TS_ASSERT_TEXT(buf.begin(), L"aaa")
      buf << L' ';
    buf << L"bbbccc";
    TS_ASSERT_TEXT(buf.begin(), L"aaa bbbccc")
  }
  void test_tstatbuf2() {
    std::tstatbuf<64> buf;
    POINT p = { 1,2 };
    buf << p;
    TS_ASSERT_TEXT(buf.begin(), "1,2")
  }
  void test_tstatbufw2() {
    std::tstatbuf<64, wchar_t > buf;
    POINT p = { 1,2 };
    buf << p;
    TS_ASSERT_TEXT(buf.begin(), L"1,2")
  }
  void test_statbuf() {
    char _buf[64];
    std::statbuf<> buf(_buf, 64);
    buf << "aaa";
    buf << std::setprecision(10);
    TS_ASSERT_TEXT(buf.begin(), "aaa")
      buf << ' ';
    buf << "bbbccc";
    TS_ASSERT_TEXT(buf.begin(), "aaa bbbccc")
  }
  void test_statbufw() {
    wchar_t _buf[64];
    std::statbuf<wchar_t> buf(_buf, 64);
    buf << L"aaa";
    buf << std::setprecision(10);
    TS_ASSERT_TEXT(buf.begin(), L"aaa")
      buf << L' ';
    buf << L"bbbccc";
    TS_ASSERT_TEXT(buf.begin(), L"aaa bbbccc")
  }
  void test_tstringbuf2() {
    std::tstringbuf<4, std::string, cz::gepro::STLifacestring<std::string, char> > buf;
    buf << "aaa";
    buf << std::setprecision(10);
    TS_ASSERT_TEXT(buf.begin(), "aaa")
      buf << ' ';
    buf << "bbb" << "ccc";
    TS_ASSERT_TEXT(buf.begin(), "aaa bbbccc")
      std::string s = buf.GetBuffer();
    TS_ASSERT_TEXT(s.c_str(), "aaa bbbccc")
  }
  void test_tstringbufw2() {
    std::tstringbuf<4, std::wstring, cz::gepro::STLifacestring<std::wstring, wchar_t>, wchar_t > buf;
    buf << L"aaa";
    buf << std::setprecision(10);
    TS_ASSERT_TEXT(buf.begin(), L"aaa")
      buf << L' ';
    buf << L"bbb" << L"ccc";
    TS_ASSERT_TEXT(buf.begin(), L"aaa bbbccc")
      std::wstring s = buf.GetBuffer();
    TS_ASSERT_TEXT(s.c_str(), L"aaa bbbccc")
  }

  void _test_constchars4() {
    std::tstatbuf<256> o;
    cz::gepro::constchars a("ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ");
    cz::gepro::constcharsi b("ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ");
    o << a << "|" << b;
    TS_ASSERT_TEXT(o.c_str(), "ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ|ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ")
  }
  void _test_constwchars4() {
    std::tstatbuf<256, wchar_t> o; o;
    cz::gepro::constwchars a(L"ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ");
    cz::gepro::constwcharsi b(L"ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ");
    o << a << L"|" << b;
    TS_ASSERT_TEXT(o.c_str(), L"ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ|ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ")
  }

};


#endif // __TEST_H

#ifndef __TEST_STRINGVIEW_H
#define __TEST_STRINGVIEW_H

/* vzor pro odvozeni dalsich testu - nemodifikovat */
#include <gepro/string_view>
class Test__TEST_STRINGVIEW_H : public CxxTest::TestSuite
{
public:
    void test_() {
      std::string_view a("abcd",3);
      const char* d=a.data();
      size_t l=a.length();
      TS_ASSERT_EQUALS(l, (size_t)3)
      UNUSED(d)
    }
    void test_1() {
      if(std::string_view("abc")=="xyz") TS_FAIL("Invalid compare");
    }
    void test_2() {
      typedef std::string_view cc;
      if (cc("abc") == "xyz") TS_FAIL("Invalid compare");
    }
    void test_3() {
      typedef std::string_view cc;
      if (cc("abc") != "abc") TS_FAIL("Invalid compare");
    }

};


#endif // __TEST_H

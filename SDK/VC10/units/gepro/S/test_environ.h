#ifndef __TEST_ENVIRON_H
#define __TEST_ENVIRON_H
/**  \addtogroup units
  @{
*/
#define GEPRO_ENVIRON_BUFSIZE 10
#include <gepro/environ.h>
class Test__TEST_ENVIRON_H : public CxxTest::TestSuite {
 public:
  void test_0() {
    char buf[256];
    cz::gepro::environment::set("Test__TEST_ENVIRON_H", "123456789");
    size_t r = cz::gepro::environment::get("Test__TEST_ENVIRON_H", buf, sizeof(buf));
    TS_ASSERT_EQUALS(r,(size_t)9)
    TS_ASSERT_TEXT(buf,"123456789")

    char buf2[2];
    size_t r2 = cz::gepro::environment::get("Test__TEST_ENVIRON_H", buf2, sizeof(buf2));
    TS_ASSERT_EQUALS(r2, (size_t)10)

      std::string buf3;
    size_t r3 = cz::gepro::environment::get("Test__TEST_ENVIRON_H", buf3);
    const char* q3 = buf3.c_str();
    TS_ASSERT_EQUALS(r3, (size_t)9)
    TS_ASSERT_TEXT(q3, "123456789")
      
    size_t r41=cz::gepro::environment::append("Test__TEST_ENVIRON_H", "abcdef");
    TS_ASSERT_EQUALS(r41, (size_t)15)
    std::string buf4;
    size_t r4 = cz::gepro::environment::get("Test__TEST_ENVIRON_H", buf4);
    const char* q4 = buf4.c_str();
    TS_ASSERT_EQUALS(r4, (size_t)15)
    TS_ASSERT_TEXT(q4, "123456789abcdef")

    size_t r51 = cz::gepro::environment::prepend("Test__TEST_ENVIRON_H", "xyz");
    TS_ASSERT_EQUALS(r51, (size_t)18)
    std::string buf5;
    size_t r5 = cz::gepro::environment::get("Test__TEST_ENVIRON_H", buf5);
    const char* q5 = buf5.c_str();
    TS_ASSERT_EQUALS(r5, (size_t)18)
    TS_ASSERT_TEXT(q5, "xyz123456789abcdef")

    size_t r6 = cz::gepro::environment::len("Test__TEST_ENVIRON_H");
    TS_ASSERT_EQUALS(r6, (size_t)18)

    size_t r7 = cz::gepro::environment::len("Test__TEST_ENVIRON_H2");
    TS_ASSERT_EQUALS(r7, (size_t)0)

    TS_ASSERT(cz::gepro::environment::exists("Test__TEST_ENVIRON_H"))
    TS_ASSERT(!cz::gepro::environment::exists("Test__TEST_ENVIRON_H2"));

    struct appender {
      std::vector<std::wstring> data;
      bool append(const wchar_t* str, size_t len) { data.push_back(std::wstring(str, len)); return true; }
    };
    appender a;
    cz::gepro::environment::names(a);
    size_t al = a.data.size();
    al=0;
  }
};

/** @} */

#endif  // __SIMPLETEST_H

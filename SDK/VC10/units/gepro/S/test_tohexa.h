#ifndef __TEST_TOHEXA_H
#define __TEST_TOHEXA_H

/* vzor pro odvozeni dalsich testu - nemodifikovat */
#include <gepro/tohexa.h>
class Test_TO_HEXA : public CxxTest::TestSuite
{
public:
  void test_() {
    int c = cz::gepro::tohexa(10);
    TS_ASSERT_EQUALS(c, 'A')
      int c2 = cz::gepro::tohexa(15);
    TS_ASSERT_EQUALS(c2, 'F')
  }
  void test_2() {
    char buf[2];
    char* q = cz::gepro::tohexa(10, buf);
    TS_ASSERT_SAME_DATA(buf, "0A", 2)
      TS_ASSERT_EQUALS(q, buf + 2)
  }
  void test_3() {
    char buf[2];
    char* q = cz::gepro::tohexa(8, buf);
    TS_ASSERT_SAME_DATA(buf, "08", 2)
      TS_ASSERT_EQUALS(q, buf + 2)
  }
  void test_4() {
    char buf[2];
    char* q = cz::gepro::tohexa(255, buf);
    TS_ASSERT_SAME_DATA(buf, "FF", 2)
      TS_ASSERT_EQUALS(q, buf + 2)
  }
  void test_hexadump() {
    unsigned char ptr[] = { 1,10,64,127,255 };
    char buf[32];
    size_t res = cz::gepro::hexdump(ptr, sizeof(ptr), buf, sizeof(buf), NULL, 0);
    TS_ASSERT_SAME_DATA(buf, "010A407FFF", 10)
      TS_ASSERT_EQUALS(res, (size_t)10)
  }
  void test_hexadump2() {
    unsigned char ptr[] = { 1,10,64,127,255 };
    char buf[32];
    size_t res = cz::gepro::hexdump(ptr, sizeof(ptr), buf, sizeof(buf), "0x", 2);
    TS_ASSERT_SAME_DATA(buf, "0x010x0A0x400x7F0xFF", 20)
      TS_ASSERT_EQUALS(res, (size_t)20)
  }
  void test_hexadump3() {
    unsigned char ptr[] = { 1,10,64,127,255 };
    char buf[16];
    size_t res = cz::gepro::hexdump(ptr, sizeof(ptr), buf, sizeof(buf), "0x", 2);
    TS_ASSERT_SAME_DATA(buf, "0x010x0A0x400x7", 15)
      TS_ASSERT_EQUALS(res, (size_t)15)
  }
  void test_hexadump31() {
    unsigned char ptr[] = { 1,10,64,127,255 };
    std::stringstream ss;
    cz::gepro::hexdump(ptr, sizeof(ptr), ss, "0x", 2);
    std::string s=ss.str();
    TS_ASSERT_SAME_DATA(s.c_str(), "0x010x0A0x400x7F0xFF", 20)
      TS_ASSERT_EQUALS(s.length(), (size_t)20)
  }
  void test_hexadump4() {
    unsigned char ptr[] = { 1,10,64,127,255 };
    char buf[16];
    size_t res = cz::gepro::hexdump(ptr, sizeof(ptr), buf, sizeof(buf), "\\", 1);
    TS_ASSERT_SAME_DATA(buf, "\\01\\0A\\40\\7F\\FF", 15)
      TS_ASSERT_EQUALS(res, (size_t)15)
  }
};


#endif // __TEST_H

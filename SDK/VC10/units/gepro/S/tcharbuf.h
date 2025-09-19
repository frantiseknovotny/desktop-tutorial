#ifndef __TEST_TCHARBUF_H
#define __TEST_TCHARBUF_H
class tcharbufTest : public CxxTest::TestSuite
{
public:
  void test_1() {
    char buf[4];
    cz::gepro::tcharbuf<char> b(buf, sizeof(buf));
    TS_ASSERT_EQUALS(buf, b.begin())
      TS_ASSERT_EQUALS(buf, b.end())
      TS_ASSERT_EQUALS((size_t)3, b.space())
      TS_ASSERT_EQUALS((size_t)3, b.capacity())
      TS_ASSERT_EQUALS((size_t)0, b.size())
      TS_ASSERT_EQUALS(b.first(), 0)
      TS_ASSERT_EQUALS(b.at(0), 0)
      TS_ASSERT_EQUALS(b.last(), 0)
  }
  void test_2() {
    char buf[4];
    cz::gepro::tcharbuf<char> b(buf, sizeof(buf));
    TS_ASSERT_EQUALS(buf, b.begin())
      TS_ASSERT_EQUALS(buf, b.end())
      TS_ASSERT_EQUALS((size_t)3, b.space())
      TS_ASSERT_EQUALS((size_t)3, b.capacity())
      TS_ASSERT_EQUALS((size_t)0, b.size())

      size_t l = b._append("", 0);
    TS_ASSERT_EQUALS(l, (size_t)0)
      TS_ASSERT_EQUALS(buf, b.begin())
      TS_ASSERT_EQUALS(buf, b.end())
      TS_ASSERT_EQUALS((size_t)3, b.space())
      TS_ASSERT_EQUALS((size_t)3, b.capacity())
      TS_ASSERT_EQUALS((size_t)0, b.size())

      l = b._append("1", 1);
    TS_ASSERT_EQUALS(l, (size_t)1)
      TS_ASSERT_EQUALS(buf, b.begin())
      TS_ASSERT_EQUALS(buf + 1, b.end())
      TS_ASSERT_EQUALS((size_t)2, b.space())
      TS_ASSERT_EQUALS((size_t)3, b.capacity())
      TS_ASSERT_EQUALS((size_t)1, b.size())

      l = b._append("22", 2);
    TS_ASSERT_EQUALS(l, (size_t)2)
      TS_ASSERT_EQUALS(buf, b.begin())
      TS_ASSERT_EQUALS(buf + 3, b.end())
      TS_ASSERT_EQUALS((size_t)0, b.space())
      TS_ASSERT_EQUALS((size_t)3, b.capacity())
      TS_ASSERT_EQUALS((size_t)3, b.size())
      TS_ASSERT_SAME_DATA(buf, "122", (size_t)4)

      l = b._append("3", 1);
    TS_ASSERT_EQUALS(l, (size_t)0)
      TS_ASSERT_EQUALS(buf, b.begin())
      TS_ASSERT_EQUALS(buf + 3, b.end())
      TS_ASSERT_EQUALS((size_t)0, b.space())
      TS_ASSERT_EQUALS((size_t)3, b.capacity())
      TS_ASSERT_EQUALS((size_t)3, b.size())
      TS_ASSERT_SAME_DATA(buf, "122", 4)
      TS_ASSERT_EQUALS(b.first(), '1')
      TS_ASSERT_EQUALS(b.at(0), '1')
      TS_ASSERT_EQUALS(b.last(), '2')
      TS_ASSERT_EQUALS(b.at(2), '2')
      TS_ASSERT_EQUALS(b.at(3), 0)

      b.clear();
    TS_ASSERT_EQUALS(buf, b.begin())
      TS_ASSERT_EQUALS(buf, b.end())
      TS_ASSERT_EQUALS((size_t)3, b.space())
      TS_ASSERT_EQUALS((size_t)3, b.capacity())
      TS_ASSERT_EQUALS((size_t)0, b.size())

      l = b._append("1234", 4);
    TS_ASSERT_EQUALS(l, (size_t)3)
      TS_ASSERT_EQUALS(buf, b.begin())
      TS_ASSERT_EQUALS(buf + 3, b.end())
      TS_ASSERT_EQUALS((size_t)0, b.space())
      TS_ASSERT_EQUALS((size_t)3, b.capacity())
      TS_ASSERT_EQUALS((size_t)3, b.size())
      TS_ASSERT_SAME_DATA(buf, "123", (size_t)4)
  }
  void test_1w() {
    wchar_t buf[4];
    cz::gepro::tcharbuf<wchar_t> b(buf, sizeof(buf) / sizeof(buf[0]));
    TS_ASSERT_EQUALS(buf, b.begin())
      TS_ASSERT_EQUALS(buf, b.end())
      TS_ASSERT_EQUALS((size_t)3, b.space())
      TS_ASSERT_EQUALS((size_t)3, b.capacity())
      TS_ASSERT_EQUALS((size_t)0, b.size())
  }
  void test_2w() {
    wchar_t buf[4];
    memset(buf, 0, sizeof(buf));
    cz::gepro::tcharbuf<wchar_t> b(buf, sizeof(buf) / sizeof(buf[0]));
    TS_ASSERT_EQUALS(buf, b.begin())
      TS_ASSERT_EQUALS(buf, b.end())
      TS_ASSERT_EQUALS((size_t)3, b.space())
      TS_ASSERT_EQUALS((size_t)3, b.capacity())
      TS_ASSERT_EQUALS((size_t)0, b.size())

      size_t l = b._append(L"", 0);
    TS_ASSERT_EQUALS(l, (size_t)0)
      TS_ASSERT_EQUALS(buf, b.begin())
      TS_ASSERT_EQUALS(buf, b.end())
      TS_ASSERT_EQUALS((size_t)3, b.space())
      TS_ASSERT_EQUALS((size_t)3, b.capacity())
      TS_ASSERT_EQUALS((size_t)0, b.size())

      l = b._append(L"1", 1);
    TS_ASSERT_EQUALS(l, (size_t)1)
      TS_ASSERT_EQUALS(buf, b.begin())
      TS_ASSERT_EQUALS(buf + 1, b.end())
      TS_ASSERT_EQUALS((size_t)2, b.space())
      TS_ASSERT_EQUALS((size_t)3, b.capacity())
      TS_ASSERT_EQUALS((size_t)1, b.size())

      l = b._append(L"22", 2);
    TS_ASSERT_EQUALS(l, (size_t)2)
      TS_ASSERT_EQUALS(buf, b.begin())
      TS_ASSERT_EQUALS(buf + 3, b.end())
      TS_ASSERT_EQUALS((size_t)0, b.space())
      TS_ASSERT_EQUALS((size_t)3, b.capacity())
      TS_ASSERT_EQUALS((size_t)3, b.size())
      TS_ASSERT_SAME_DATA(buf, L"122", 8)

      l = b._append(L"3", 1);
    TS_ASSERT_EQUALS(l, (size_t)0)
      TS_ASSERT_EQUALS(buf, b.begin())
      TS_ASSERT_EQUALS(buf + 3, b.end())
      TS_ASSERT_EQUALS((size_t)0, b.space())
      TS_ASSERT_EQUALS((size_t)3, b.capacity())
      TS_ASSERT_EQUALS((size_t)3, b.size())
      TS_ASSERT_SAME_DATA(buf, L"122", 8)

      b.clear();
    TS_ASSERT_EQUALS(buf, b.begin())
      TS_ASSERT_EQUALS(buf, b.end())
      TS_ASSERT_EQUALS((size_t)3, b.space())
      TS_ASSERT_EQUALS((size_t)3, b.capacity())
      TS_ASSERT_EQUALS((size_t)0, b.size())

      l = b._append(L"1234", 4);
    TS_ASSERT_EQUALS(l, (size_t)3)
      TS_ASSERT_EQUALS(buf, b.begin())
      TS_ASSERT_EQUALS(buf + 3, b.end())
      TS_ASSERT_EQUALS((size_t)0, b.space())
      TS_ASSERT_EQUALS((size_t)3, b.capacity())
      TS_ASSERT_EQUALS((size_t)3, b.size())
      TS_ASSERT_SAME_DATA(buf, L"123", 8)
  }
  void test_() {
    char buf[4];
    cz::gepro::tcharbuf<char> b(buf, sizeof(buf));
    TS_ASSERT_EQUALS(buf, b.begin())
      TS_ASSERT_EQUALS(buf, b.end())
      TS_ASSERT_EQUALS((size_t)3, b.space())
      TS_ASSERT_EQUALS((size_t)3, b.capacity())
      TS_ASSERT_EQUALS((size_t)0, b.size())

      size_t l = b._append("", 0);
    TS_ASSERT_EQUALS(l, (size_t)0)
      TS_ASSERT_EQUALS(buf, b.begin())
      TS_ASSERT_EQUALS(buf, b.end())
      TS_ASSERT_EQUALS((size_t)3, b.space())
      TS_ASSERT_EQUALS((size_t)3, b.capacity())
      TS_ASSERT_EQUALS((size_t)0, b.size())

      l = b._append('1');
    TS_ASSERT_EQUALS(l, (size_t)1)
      TS_ASSERT_EQUALS(buf, b.begin())
      TS_ASSERT_EQUALS(buf + 1, b.end())
      TS_ASSERT_EQUALS((size_t)2, b.space())
      TS_ASSERT_EQUALS((size_t)3, b.capacity())
      TS_ASSERT_EQUALS((size_t)1, b.size())

      l = b._append('2');
    TS_ASSERT_EQUALS(l, (size_t)1)
      TS_ASSERT_EQUALS(buf, b.begin())
      TS_ASSERT_EQUALS(buf + 2, b.end())
      TS_ASSERT_EQUALS((size_t)1, b.space())
      TS_ASSERT_EQUALS((size_t)3, b.capacity())
      TS_ASSERT_EQUALS((size_t)2, b.size())
      TS_ASSERT_SAME_DATA(buf, "12", (size_t)3)

      l = b._append('3');
    TS_ASSERT_EQUALS(l, (size_t)1)
      TS_ASSERT_EQUALS(buf, b.begin())
      TS_ASSERT_EQUALS(buf + 3, b.end())
      TS_ASSERT_EQUALS((size_t)0, b.space())
      TS_ASSERT_EQUALS((size_t)3, b.capacity())
      TS_ASSERT_EQUALS((size_t)3, b.size())
      TS_ASSERT_SAME_DATA(buf, "123", (size_t)4)

      l = b._append('4');
    TS_ASSERT_EQUALS(l, (size_t)0)
      TS_ASSERT_EQUALS(buf, b.begin())
      TS_ASSERT_EQUALS(buf + 3, b.end())
      TS_ASSERT_EQUALS((size_t)0, b.space())
      TS_ASSERT_EQUALS((size_t)3, b.capacity())
      TS_ASSERT_EQUALS((size_t)3, b.size())
      TS_ASSERT_SAME_DATA(buf, "123", (size_t)4)
  }
  void test_replace() {
    char buf[16];
    cz::gepro::tcharbuf<char> b(buf, sizeof(buf));
    b._append("abc.xyz", 7);
    b._replace('.', '_');
    TS_ASSERT_SAME_DATA(buf, "abc_xyz", 7)
  }
  void test_replace2() {
    char buf[16];
    cz::gepro::tcharbuf<char> b(buf, sizeof(buf));
    b._append("abc.x.y.z", 9);
    b._replace('.', '_');
    TS_ASSERT_SAME_DATA(buf, "abc_x_y_z", 9)
  }
  void test_replace3() {
    char buf[16];
    cz::gepro::tcharbuf<char> b(buf, sizeof(buf));
    b._append("abc+xyz", 7);
    b._replace('.', '_');
    TS_ASSERT_SAME_DATA(buf, "abc+xyz", 7)
  }
  void test_replace4() {
    char buf[16];
    cz::gepro::tcharbuf<char> b(buf, sizeof(buf));
    b._append(".abc+xyz", 8);
    b._replace('.', '_');
    TS_ASSERT_SAME_DATA(buf, "_abc+xyz", 8)
  }
  void test_replace5() {
    char buf[16];
    cz::gepro::tcharbuf<char> b(buf, sizeof(buf));
    b._append("abc+xyz.", 8);
    b._replace('.', '_');
    TS_ASSERT_SAME_DATA(buf, "abc+xyz_", 8)
  }
  void test_Hex() {
    cz::gepro::Hex l((__int64)10);
    cz::gepro::Hex i(10);
    cz::gepro::Hex s((short)10);
    cz::gepro::Hex c((char)10);
    TS_ASSERT_TEXT(l.begin(), "000000000000000a")
      TS_ASSERT_TEXT(i.begin(), "0000000a")
      TS_ASSERT_TEXT(s.begin(), "000a")
      TS_ASSERT_TEXT(c.begin(), "0a")
  }
  void test_compare() {
    char buf[16];
    cz::gepro::tcharbuf<char> b(buf, sizeof(buf));
    b._append("abc", 3);
    int r1 = b.compare("abc");
    int r2 = b.compare("Abc");
    int r3 = b.compare("");
    int r4 = b.compare("def");
    int r5 = b.compare("ab");
    int r6 = b.compare("abcd");
    TS_ASSERT_EQUALS(r1, 0)
      TS_ASSERT_EQUALS(r2, -1)
      TS_ASSERT_EQUALS(r3, -1)
      TS_ASSERT_EQUALS(r4, 1)
      TS_ASSERT_EQUALS(r5, -1)
      TS_ASSERT_EQUALS(r6, 1)
  }
  void test_comparew() {
    wchar_t buf[16];
    cz::gepro::tcharbuf<wchar_t> b(buf, sizeof(buf));
    b._append(L"abc", 3);
    int r1 = b.compare(L"abc");
    int r2 = b.compare(L"Abc");
    int r3 = b.compare(L"");
    int r4 = b.compare(L"def");
    int r5 = b.compare(L"ab");
    int r6 = b.compare(L"abcd");
    TS_ASSERT_EQUALS(r1, 0)
      TS_ASSERT_EQUALS(r2, -1)
      TS_ASSERT_EQUALS(r3, -1)
      TS_ASSERT_EQUALS(r4, 1)
      TS_ASSERT_EQUALS(r5, -1)
      TS_ASSERT_EQUALS(r6, 1)
  }
  void test_icompare() {
    char buf[16];
    cz::gepro::tcharbuf<char> b(buf, sizeof(buf));
    b._append("abc", 3);
    int r1 = b.icompare("abc");
    int r2 = b.icompare("Abc");
    int r3 = b.icompare("");
    int r4 = b.icompare("def");
    int r5 = b.icompare("ab");
    int r6 = b.icompare("abcd");
    TS_ASSERT_EQUALS(r1, 0)
      TS_ASSERT_EQUALS(r2, 0)
      TS_ASSERT_EQUALS(r3, -97)
      TS_ASSERT_EQUALS(r4, 3)
      TS_ASSERT_EQUALS(r5, -99)
      TS_ASSERT_EQUALS(r6, 100)
  }
  void test_icomparew() {
    wchar_t buf[16];
    cz::gepro::tcharbuf<wchar_t> b(buf, sizeof(buf));
    b._append(L"abc", 3);
    int r1 = b.icompare(L"abc");
    int r2 = b.icompare(L"Abc");
    int r3 = b.icompare(L"");
    int r4 = b.icompare(L"def");
    int r5 = b.icompare(L"ab");
    int r6 = b.icompare(L"abcd");
    TS_ASSERT_EQUALS(r1, 0)
      TS_ASSERT_EQUALS(r2, 0)
      TS_ASSERT_EQUALS(r3, -97)
      TS_ASSERT_EQUALS(r4, 3)
      TS_ASSERT_EQUALS(r5, -99)
      TS_ASSERT_EQUALS(r6, 100)
  }
  void test_trimr() {
    char buf[8];
    cz::gepro::tcharbuf<char> b(buf, sizeof(buf));
    b.append("abcdef", 6);
    b.trimr(5, "...");
    TS_ASSERT_TEXT(buf, "ab...")
  }
  void test_append() {
    char buf[16];
    cz::gepro::tcharbuf<char> b(buf, sizeof(buf));
    b.append("abc+xyz.", 8);
    TS_ASSERT_SAME_DATA(buf, "abc+xyz.", 8)
  }
  void test_append_if_not() {
    char buf[16];
    cz::gepro::tcharbuf<char> b(buf, sizeof(buf));
    b.append("abc+xyz.", 8);
    b.append_if_not('.');
    TS_ASSERT_SAME_DATA(buf, "abc+xyz.", 8)
  }
  void test_append_if_nota() {
    char buf[16];
    cz::gepro::tcharbuf<char> b(buf, sizeof(buf));
    b.append("abc+xyz", 7);
    b.append_if_not('.');
    TS_ASSERT_SAME_DATA(buf, "abc+xyz.", 8)
  }
  void test_replacep1() {
    char buf[16];
    cz::gepro::tcharbuf<char> b(buf, sizeof(buf));
    b.append("abc+xyz.", 8);
    b.replace('.', '_');
    TS_ASSERT_SAME_DATA(buf, "abc+xyz_", 8)
  }
  void test_replacep2() {
    char buf[16];
    cz::gepro::tcharbuf<char> b(buf, sizeof(buf));
    b.append("a/x/z?q=1", 9);
    b.replace('/', '+', '?');
    TS_ASSERT_SAME_DATA(buf, "a+x+z", 5)
  }
  void test_overflow() {
    char buf[16];
    cz::gepro::tcharbuf<char> b(buf, sizeof(buf));
    b.append("a/x/z?q=1", 9);
    TS_ASSERT_EQUALS(b.overflow(),false)
    b.append("a/x/z?q=1", 9);
    TS_ASSERT_EQUALS(b.overflow(), true)
    TS_ASSERT_SAME_DATA(buf, "a/x/z?q=1a/x/z?", 16)
  }

};


#endif // __TEST_H

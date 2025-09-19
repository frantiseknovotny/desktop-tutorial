#ifndef __TEST_DISK_H
#define __TEST_DISK_H
/** \file
   Testy inline asembler funkcí a jejich pøípadné nádrady v asm nebo C.
   Porovnání rychlosti øešení. 
*/

class asmDISK : public CxxTest::TestSuite
{
public:
    void test_FileExt() {
      const char* f="c:\\abc\\1.txt";
      const char* f2="abc\\1.txt";
      const char* f3="1.txt";
      const char* f4="\\\\abc\\1.txt";
      const char* f5="c:\\abc\\1";
      TS_ASSERT_TEXT(cz::gepro::FileExt(f),"txt")
      TS_ASSERT_TEXT(cz::gepro::FileExt(f2),"txt")
      TS_ASSERT_TEXT(cz::gepro::FileExt(f3),"txt")
      TS_ASSERT_TEXT(cz::gepro::FileExt(f4),"txt")
      TS_ASSERT_EQUALS(cz::gepro::FileExt(f5),(const char*)NULL)
    }
};


#endif // __TEST_H

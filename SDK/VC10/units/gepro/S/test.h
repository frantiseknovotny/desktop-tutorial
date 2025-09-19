#ifndef __TEST_H
#define __TEST_H

/* vzor pro odvozeni dalsich testu - nemodifikovat */

class Test : public CxxTest::TestSuite
{
public:
    void test_() {
      //TS_FAIL("Not implemented")
      tempfile tm;
      tm.write("ahoj",4);
      char buf[1024]="";
      size_t len=readfile(tm.name(),buf,sizeof(buf));
      TS_ASSERT_EQUALS(len, (size_t)4)
      TS_ASSERT_SAME_DATA(buf,"ahoj",4)
    }
};


#endif // __TEST_H

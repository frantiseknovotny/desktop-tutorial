#ifndef __TEST_MTIMER_H
#define __TEST_MTIMER_H
#include <windows.h>

/**	\brief	 test merice casu mtimer

*/
class Test_mtimer : public CxxTest::TestSuite
{
public:
    void test_mtimer() {
      mtimer mt;
      Sleep(1000);
      double t=mt.Latch();
      TS_ASSERT_DELTA(t,1,0.1)
      mtimer mt2;
      Sleep(1000);
      mt2.Start();
      Sleep(1000);
      t=mt.Latch();
      double t2=mt2.Latch();
      TS_ASSERT_DELTA(t,3,0.1)
      TS_ASSERT_DELTA(t2,1,0.1)


    }
    void test_mtimer2() {
      mtimer2 mt;
      Sleep(1000);
      double t=mt.Latch();
      TS_ASSERT_DELTA(t,1,0.1)
      mtimer2 mt2;
      Sleep(1000);
      mt2.Start();
      Sleep(1000);
      t=mt.Latch();
      double t2=mt2.Latch();
      TS_ASSERT_DELTA(t,3,0.1)
      TS_ASSERT_DELTA(t2,1,0.1)


    }

};
#endif
#ifndef __TEST_RECTANGLE_H
#define __TEST_RECTANGLE_H
#include <gepro/rectangle2.h>
class Test__TEST_RECTANGLE_H : public CxxTest::TestSuite {
public:
  void test_() {
    cz::gepro::rectangle r;
    TS_ASSERT(r.null())
    TS_ASSERT(r.empty())
    TS_ASSERT(r.Empty())
  }
  void test_1() {
    cz::gepro::rectangle r(1,1,1,1);
    TS_ASSERT(!r.null())
    TS_ASSERT(r.empty())
    TS_ASSERT(r.Empty())
  }
  void test_2() {
    cz::gepro::rectangle r(1, 1, 2, 2);
    TS_ASSERT(!r.IsIn(0,0))
    TS_ASSERT(r.IsIn(1,1))
    TS_ASSERT(!r.IsInOnly(1,1))
    TS_ASSERT(r.IsInEx(0,0)==0)
    TS_ASSERT(r.IsInEx(1,1)==1)
    TS_ASSERT(r.IsInEx(1.5,1.5)==2)
    TS_ASSERT(!r.empty())
    TS_ASSERT(!r.Empty())
  }
  void test_Cross0() {
    cz::gepro::rectangle r(1, 1, 2, 2);
    cz::gepro::point p1(1.1, 1.1);
    cz::gepro::point p2(1.2, 1.1);
    TS_ASSERT(r.Cross(p1,p2)==0)
    TS_ASSERT(p1.X == 1.1)
    TS_ASSERT(p1.Y == 1.1)
    TS_ASSERT(p2.X == 1.2)
    TS_ASSERT(p2.Y == 1.1)
  }
  void test_Cross1() {
    cz::gepro::rectangle r(1, 1, 2, 2);
    cz::gepro::point p1(0.9, 1.1);
    cz::gepro::point p2(1.1, 1.1);
    TS_ASSERT(r.Cross(p1, p2) == 1)
    TS_ASSERT(p1.X == 1)
    TS_ASSERT(p1.Y == 1.1)
    TS_ASSERT(p2.X == 1.1)
    TS_ASSERT(p2.Y == 1.1)
  }
  void test_Cross2() {
    cz::gepro::rectangle r(1, 1, 2, 2);
    cz::gepro::point p1(1.1, 1.1);
    cz::gepro::point p2(2.1, 1.1);
    TS_ASSERT(r.Cross(p1, p2) == 2)
    TS_ASSERT(p1.X == 1.1)
    TS_ASSERT(p1.Y == 1.1)
    TS_ASSERT(p2.X == 2)
    TS_ASSERT(p2.Y == 1.1)
  }
  void test_Cross3() {
    cz::gepro::rectangle r(1, 1, 2, 2);
    cz::gepro::point p1(0.9, 1.1);
    cz::gepro::point p2(2.1, 1.1);
    TS_ASSERT(r.Cross(p1, p2) == 3)
    TS_ASSERT(p1.X == 1)
    TS_ASSERT(p1.Y == 1.1)
    TS_ASSERT(p2.X == 2)
    TS_ASSERT(p2.Y == 1.1)
  }
  void test_Cross4() {
    cz::gepro::rectangle r(1, 1, 2, 2);
    cz::gepro::point p1(0.9, 0.9);
    cz::gepro::point p2(2.1, 0.9);
    TS_ASSERT(r.Cross(p1, p2) == 4)
    TS_ASSERT(p1.X == 0.9)
    TS_ASSERT(p1.Y == 0.9)
    TS_ASSERT(p2.X == 2.1)
    TS_ASSERT(p2.Y == 0.9)
  }
};


#endif // __TEST_H

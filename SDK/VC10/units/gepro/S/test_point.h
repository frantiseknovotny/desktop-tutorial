#ifndef __TEST_POINT_H
#define __TEST_POINT_H

#define _eps 1.0e-16
#define _eps2 1.0e-14

using namespace cz::gepro;


/** Test operatoru point.
*/
class Test_point : public CxxTest::TestSuite
{
public:
    void test_point() {
      point a(5,10);
      point b=a;

      TS_ASSERT(a==b);

      point c=a+b;

      TS_ASSERT(c==point(10,20));
      TS_ASSERT(c!=b);

      TS_ASSERT(c/5==point(2,4));

      TS_ASSERT(a*2==point(10,20));
      TS_ASSERT(2*a==point(10,20));

      point p1(5631348.378413, 447180.181388);
      point p2(56.4,67.2);
      point p3=p1-p2;
      TS_ASSERT_EQUALS(p3.X,p1.X-p2.X)
      TS_ASSERT_EQUALS(p3.Y,p1.Y-p2.Y)

      p1+=a;
      TS_ASSERT_EQUALS(p1.X,5631348.378413+a.X)
      TS_ASSERT_EQUALS(p1.Y,447180.181388+a.Y)

      p1-=a;
      TS_ASSERT_EQUALS(p1.X,5631348.378413)
      TS_ASSERT_EQUALS(p1.Y,447180.181388)

      p1+=30.5;
      TS_ASSERT_EQUALS(p1.X,5631348.378413+30.5)
      TS_ASSERT_EQUALS(p1.Y,447180.181388+30.5)

      p1-=30.5;
      TS_ASSERT_EQUALS(p1.X,5631348.378413)
      TS_ASSERT_EQUALS(p1.Y,447180.181388)

    }
};
#endif
#ifndef __TEST_G2D_H
#define __TEST_G2D_H

#define _eps 1.0e-16
#define _eps2 1.0e-14

using namespace cz::gepro;
using namespace cz::gepro::g2d; 

class Test_G2D : public CxxTest::TestSuite
{
public:
    void test_Direction() {
      double dist=0;
      double smer=Direction(point(5,10), point(10,10), dist);      //0
      TS_ASSERT_DELTA(smer,0.,_eps);
      TS_ASSERT_DELTA(dist,5.,_eps);

      smer=Direction(point(5,10), point(10,15), dist);             //PI/4
      TS_ASSERT_DELTA(smer,3.14159265358979323846/4,_eps);
      TS_ASSERT_DELTA(dist,sqrt(50.),_eps);

      smer=Direction(point(5,10), point(5,15), dist);
      TS_ASSERT_DELTA(smer,3.14159265358979323846/2,_eps);        //PI/2
      TS_ASSERT_DELTA(dist,5.,_eps);


      smer=Direction(point(5,10), point(0,15), dist);             //3PI/4
      TS_ASSERT_DELTA(smer,3*3.14159265358979323846/4,_eps);
      TS_ASSERT_DELTA(dist,sqrt(50.),_eps);

      smer=Direction(point(5,10), point(0,10), dist);             //PI
      TS_ASSERT_DELTA(smer,3.14159265358979323846,_eps);
      TS_ASSERT_DELTA(dist,5.,_eps);

      smer=Direction(point(5,10), point(0,5), dist);             //5PI/4
      TS_ASSERT_DELTA(smer,5*3.14159265358979323846/4,_eps);
      TS_ASSERT_DELTA(dist,sqrt(50.),_eps);

      smer=Direction(point(5,10), point(5,5), dist);             //1.5*PI
      TS_ASSERT_DELTA(smer,1.5*3.14159265358979323846,_eps);
      TS_ASSERT_DELTA(dist,5.,_eps);
 
      smer=Direction(point(5,10), point(10,5), dist);             //PI+3PI/4
      TS_ASSERT_DELTA(smer,7*3.14159265358979323846/4,_eps);
      TS_ASSERT_DELTA(dist,sqrt(50.),_eps);

      smer=Direction(point(5,10), point(5,10), dist);             //PI+3PI/4
      TS_ASSERT_DELTA(smer,0,_eps);
      TS_ASSERT_DELTA(dist,0.,_eps);
   }

    void test_PointLineDist() {
      double dist=PointLineDist(point(5,10), point(10,15),point(0,0));
      TS_ASSERT_DELTA(dist,sqrt(50.)/2,_eps2);

      dist=PointLineDist(point(5,10), point(5,10),point(0,0));
      TS_ASSERT_DELTA(dist,sqrt(125.),_eps2);
    }

    void test_PointSegmentDist() {
      double dist=PointSegmentDist(point(5,10), point(10,15),point(0,0));
      TS_ASSERT_DELTA(dist,sqrt(125.),_eps2);

      dist=PointSegmentDist(point(-5,0), point(5,10),point(0,0));
      TS_ASSERT_DELTA(dist,sqrt(50.)/2,_eps2);
    }

    void test_PointLineFoot() {
      point res;
      double dist=PointLineFoot(point(0,0),point(5,10), point(10,15),res);
      TS_ASSERT_DELTA(dist,-sqrt(50.)/2,_eps2);

      TS_ASSERT_DELTA(res.X,-2.5,_eps2);
      TS_ASSERT_DELTA(res.Y,2.5,_eps2);

      dist=PointLineFoot(point(-5,5),point(5,10), point(10,15),res);
      TS_ASSERT_DELTA(dist,sqrt(50.)/2,_eps2);

      TS_ASSERT_DELTA(res.X,-2.5,_eps2);
      TS_ASSERT_DELTA(res.Y,2.5,_eps2);


      dist=PointLineFoot(point(5,10),point(5,5), point(5,5),res);
      TS_ASSERT_DELTA(dist,5,_eps2);
      TS_ASSERT_DELTA(res.X,5,_eps2);
      TS_ASSERT_DELTA(res.Y,5,_eps2);
    }

    void test_Area(void) {
      point p[6];
      p[0]=point( 0, 0);
      p[1]=point(10, 0);
      p[2]=point(10,10);
      p[3]=point( 0,10);
      TS_ASSERT_DELTA(Area(p,4),100,_eps2);

      p[0]=point( 0, 0);
      p[1]=point( 0,10);
      p[2]=point(10,10);
      p[3]=point(10, 0);
      TS_ASSERT_DELTA(Area(p,4),-100,_eps2);

      p[0]=point( 10,  0);
      p[1]=point(  0, 10);
      p[2]=point(-10, 10);
      p[3]=point(  0,-10);
      TS_ASSERT_DELTA(Area(p,4),200,_eps2);

      p[0]=point( 10,  0);
      p[1]=point(  0,  0);
      p[2]=point(  0, 10);
      p[3]=point(-10,  0);
      p[4]=point(  0,  0);
      p[5]=point(  0,-10);
      TS_ASSERT_DELTA(Area(p,6),100,_eps2);
    }


    void test_Angle(void) {
      point p0 = point( 2,  1);
      point p1 = point( 1,  1);
      point p2 = point( 2,  2);
      TS_ASSERT_DELTA(AnglePos(p0,p1,p2),PI/4,_eps2);
      TS_ASSERT_DELTA(AngleNeg(p0,p1,p2),7*PI/4,_eps2);
      TS_ASSERT_DELTA(AngleConvex(p0,p1,p2),PI/4,_eps2);

      p2 = point( 1,  2);
      TS_ASSERT_DELTA(AnglePos(p0,p1,p2),PI/2,_eps2);
      TS_ASSERT_DELTA(AngleNeg(p0,p1,p2),3*PI/2,_eps2);
      TS_ASSERT_DELTA(AngleConvex(p0,p1,p2),PI/2,_eps2);

      p2 = point( 0, 2);
      TS_ASSERT_DELTA(AnglePos(p0,p1,p2),3*PI/4,_eps2);
      TS_ASSERT_DELTA(AngleNeg(p0,p1,p2),5*PI/4,_eps2);
      TS_ASSERT_DELTA(AngleConvex(p0,p1,p2),3*PI/4,_eps2);

      p2 = point( 0, 1);
      TS_ASSERT_DELTA(AnglePos(p0,p1,p2),PI,_eps2);
      TS_ASSERT_DELTA(AngleNeg(p0,p1,p2),PI,_eps2);
      TS_ASSERT_DELTA(AngleConvex(p0,p1,p2),PI,_eps2);

      p2 = point( 0, 0);
      TS_ASSERT_DELTA(AnglePos(p0,p1,p2),5*PI/4,_eps2);
      TS_ASSERT_DELTA(AngleNeg(p0,p1,p2),3*PI/4,_eps2);
      TS_ASSERT_DELTA(AngleConvex(p0,p1,p2),3*PI/4,_eps2);

      p2 = point( 1, 0);
      TS_ASSERT_DELTA(AnglePos(p0,p1,p2),3*PI/2,_eps2);
      TS_ASSERT_DELTA(AngleNeg(p0,p1,p2),PI/2,_eps2);
      TS_ASSERT_DELTA(AngleConvex(p0,p1,p2),PI/2,_eps2);

      p2 = point( 2, 0);
      TS_ASSERT_DELTA(AnglePos(p0,p1,p2),7*PI/4,_eps2);
      TS_ASSERT_DELTA(AngleNeg(p0,p1,p2),PI/4,_eps2);
      TS_ASSERT_DELTA(AngleConvex(p0,p1,p2),PI/4,_eps2);

      p2 = point( 2, 1);
      TS_ASSERT_DELTA(AnglePos(p0,p1,p2),0,_eps2);
      TS_ASSERT_DELTA(AngleNeg(p0,p1,p2),0,_eps2);
      TS_ASSERT_DELTA(AngleConvex(p0,p1,p2),0,_eps2);

      p2 = p0;
      TS_ASSERT_DELTA(AnglePos(p0,p1,p2),0,_eps2);
      TS_ASSERT_DELTA(AngleNeg(p0,p1,p2),0,_eps2);
      TS_ASSERT_DELTA(AngleConvex(p0,p1,p2),0,_eps2);
      p2 = p0 = p1;
      TS_ASSERT_DELTA(AnglePos(p0,p1,p2),0,_eps2);
      TS_ASSERT_DELTA(AngleNeg(p0,p1,p2),0,_eps2);
      TS_ASSERT_DELTA(AngleConvex(p0,p1,p2),0,_eps2);
    }

    void test_PointLineRelation(void) {
      point a = point( 1,  1);
      point b = point( 3,  3);
      point p = point( 4,  4);

      point pp;
      point lp;
      #ifdef _M_X64
      double r1 = 1.4999999999999998;
      #else
      double r1 = 1.5;
      #endif
      TS_ASSERT_DELTA(PointLineRelation(p, a, b, pp, lp), r1, _eps);
      TS_ASSERT_DELTA(pp.X,4,_eps);
      TS_ASSERT_DELTA(pp.Y,4,_eps);
      TS_ASSERT_DELTA(lp.X*lp.X,18.,_eps2);
      TS_ASSERT_DELTA(lp.Y,0,_eps);

      p = point( 3,  5);
      TS_ASSERT_DELTA(PointLineRelation(p,a,b,pp,lp),r1,_eps);
      TS_ASSERT_DELTA(pp.X,4,_eps);
      TS_ASSERT_DELTA(pp.Y,4,_eps);
      TS_ASSERT_DELTA(lp.X*lp.X,18.,_eps2);
      TS_ASSERT_DELTA(lp.Y,sqrt(2.0),_eps2);

      p = point( 5,  3);
      TS_ASSERT_DELTA(PointLineRelation(p,a,b,pp,lp),r1,_eps);
      TS_ASSERT_DELTA(pp.X,4,_eps);
      TS_ASSERT_DELTA(pp.Y,4,_eps);
      TS_ASSERT_DELTA(lp.X*lp.X,18.,_eps2);
      TS_ASSERT_DELTA(lp.Y,-sqrt(2.0),_eps2);

      p = point( 3,  3);
      TS_ASSERT_DELTA(PointLineRelation(p,a,b,pp,lp),1.,_eps);
      TS_ASSERT_DELTA(pp.X,3,_eps);
      TS_ASSERT_DELTA(pp.Y,3,_eps);
      TS_ASSERT_DELTA(lp.X*lp.X,8.,_eps2);
      TS_ASSERT_DELTA(lp.Y,0,_eps);

      p = point( 2,  4);
      TS_ASSERT_DELTA(PointLineRelation(p,a,b,pp,lp),1.,_eps);
      TS_ASSERT_DELTA(pp.X,3,_eps);
      TS_ASSERT_DELTA(pp.Y,3,_eps);
      TS_ASSERT_DELTA(lp.X*lp.X,8.,_eps2);
      TS_ASSERT_DELTA(lp.Y,sqrt(2.0),_eps2);

      p = point( 4,  2);
      TS_ASSERT_DELTA(PointLineRelation(p,a,b,pp,lp),1.,_eps);
      TS_ASSERT_DELTA(pp.X,3,_eps);
      TS_ASSERT_DELTA(pp.Y,3,_eps);
      TS_ASSERT_DELTA(lp.X*lp.X,8.,_eps2);
      TS_ASSERT_DELTA(lp.Y,-sqrt(2.0),_eps2);

      p = point( 2,  2);
      TS_ASSERT_DELTA(PointLineRelation(p,a,b,pp,lp),.5,_eps);
      TS_ASSERT_DELTA(pp.X,2,_eps);
      TS_ASSERT_DELTA(pp.Y,2,_eps);
      TS_ASSERT_DELTA(lp.X*lp.X,2.,_eps2);
      TS_ASSERT_DELTA(lp.Y,0,_eps);

      p = point( 1,  3);
      TS_ASSERT_DELTA(PointLineRelation(p,a,b,pp,lp),.5,_eps);
      TS_ASSERT_DELTA(pp.X,2,_eps);
      TS_ASSERT_DELTA(pp.Y,2,_eps);
      TS_ASSERT_DELTA(lp.X*lp.X,2.,_eps2);
      TS_ASSERT_DELTA(lp.Y,sqrt(2.0),_eps2);

      p = point( 3,  1);
      TS_ASSERT_DELTA(PointLineRelation(p,a,b,pp,lp),.5,_eps);
      TS_ASSERT_DELTA(pp.X,2,_eps);
      TS_ASSERT_DELTA(pp.Y,2,_eps);
      TS_ASSERT_DELTA(lp.X*lp.X,2.,_eps2);
      TS_ASSERT_DELTA(lp.Y,-sqrt(2.0),_eps2);

      p = point( 1,  1);
      TS_ASSERT_DELTA(PointLineRelation(p,a,b,pp,lp),0.,_eps);
      TS_ASSERT_DELTA(pp.X,1,_eps);
      TS_ASSERT_DELTA(pp.Y,1,_eps);
      TS_ASSERT_DELTA(lp.X,0,_eps2);
      TS_ASSERT_DELTA(lp.Y,0,_eps);

      p = point( 0,  2);
      TS_ASSERT_DELTA(PointLineRelation(p,a,b,pp,lp),0.,_eps);
      TS_ASSERT_DELTA(pp.X,1,_eps);
      TS_ASSERT_DELTA(pp.Y,1,_eps);
      TS_ASSERT_DELTA(lp.X,0,_eps2);
      TS_ASSERT_DELTA(lp.Y,sqrt(2.0),_eps2);

      p = point( 2,  0);
      TS_ASSERT_DELTA(PointLineRelation(p,a,b,pp,lp),0.,_eps);
      TS_ASSERT_DELTA(pp.X,1,_eps);
      TS_ASSERT_DELTA(pp.Y,1,_eps);
      TS_ASSERT_DELTA(lp.X,0,_eps2);
      TS_ASSERT_DELTA(lp.Y,-sqrt(2.0),_eps2);

      p = point( 0,  0);
      TS_ASSERT_DELTA(PointLineRelation(p,a,b,pp,lp),-0.5,_eps);
      TS_ASSERT_DELTA(pp.X,0,_eps);
      TS_ASSERT_DELTA(pp.Y,0,_eps);
      TS_ASSERT_DELTA(lp.X,-sqrt(2.0),_eps2);
      TS_ASSERT_DELTA(lp.Y,0,_eps);

      p = point( -1,  1);
      TS_ASSERT_DELTA(PointLineRelation(p,a,b,pp,lp),-0.5,_eps);
      TS_ASSERT_DELTA(pp.X,0,_eps);
      TS_ASSERT_DELTA(pp.Y,0,_eps);
      TS_ASSERT_DELTA(lp.X,-sqrt(2.0),_eps2);
      TS_ASSERT_DELTA(lp.Y,sqrt(2.0),_eps2);

      p = point( 1,  -1);
      TS_ASSERT_DELTA(PointLineRelation(p,a,b,pp,lp),-0.5,_eps);
      TS_ASSERT_DELTA(pp.X,0,_eps);
      TS_ASSERT_DELTA(pp.Y,0,_eps);
      TS_ASSERT_DELTA(lp.X,-sqrt(2.0),_eps2);
      TS_ASSERT_DELTA(lp.Y,-sqrt(2.0),_eps2);
      

      a = point( 1,  1);
      b = point( 1,  1);
      p = point( 4,  4);

      TS_ASSERT_DELTA(PointLineRelation(p,a,b,pp,lp),0,_eps);
      TS_ASSERT_DELTA(pp.X,1,_eps);
      TS_ASSERT_DELTA(pp.Y,1,_eps);
      TS_ASSERT_DELTA(lp.X,0,_eps);
      TS_ASSERT_DELTA(lp.Y,sqrt(18.0),_eps2);

    }


};


#endif // __TEST_H

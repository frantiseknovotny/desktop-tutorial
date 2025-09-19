#ifndef __TEST_MATH_H
#define __TEST_MATH_H

#define _eps 1.0e-16
#define _eps2 1.0e-14
#define _eps3 1.0e-12
#define _eps4 1.0e-10
#define _eps5 1.0e-8

using namespace cz::gepro;
using namespace cz::gepro::g2d; 


/** Test matematických konstant a funkcí definovaných v Gepru.
*/
class mathTest : public CxxTest::TestSuite
{
public:
    void test_() {
      TS_ASSERT_EQUALS(M_E,2.71828182845904523536)
      TS_ASSERT_EQUALS(M_LOG2E,1.44269504088896340736)
      TS_ASSERT_EQUALS(M_LOG10E,0.434294481903251827651)
      TS_ASSERT_EQUALS(M_LN2,0.693147180559945309417)
      TS_ASSERT_EQUALS(M_LN10,2.30258509299404568402)
      TS_ASSERT_EQUALS(M_PI,3.14159265358979323846)
      TS_ASSERT_EQUALS(M_PI_2,1.57079632679489661923)
      TS_ASSERT_EQUALS(M_PI_4,0.785398163397448309616)
      TS_ASSERT_EQUALS(M_1_PI,0.318309886183790671538)
      TS_ASSERT_EQUALS(M_2_PI,0.636619772367581343076)
      TS_ASSERT_EQUALS(M_1_SQRTPI,0.564189583547756286948)
      TS_ASSERT_EQUALS(M_2_SQRTPI,1.12837916709551257390)
      TS_ASSERT_EQUALS(M_SQRT2,1.41421356237309504880)
      TS_ASSERT_EQUALS(M_SQRT_2,0.707106781186547524401)
    }
/** Test treti odmocniny
*/
    void test_cbrt() {
      TS_ASSERT_EQUALS(cz::gepro::math::cbrt(8.0),2)
      TS_ASSERT_EQUALS(cz::gepro::math::cbrt(-8.0),-2)

      TS_ASSERT_EQUALS(cz::gepro::math::cbrt(0.008),0.2)
      TS_ASSERT_EQUALS(cz::gepro::math::cbrt(-0.008),-0.2)

      TS_ASSERT_DELTA(cz::gepro::math::cbrt(1866455.185461867),123.123,_eps3)
      TS_ASSERT_DELTA(cz::gepro::math::cbrt(-1866455.185461867),-123.123,_eps3)

      TS_ASSERT_DELTA(cz::gepro::math::cbrt(6502085863215412006.2669823839796),1866455.185461867,_eps5)
      TS_ASSERT_DELTA(cz::gepro::math::cbrt(-6502085863215412006.2669823839796),-1866455.185461867,_eps5)
    }

/** Test vypoctu korenu kubicke rovnice vcetne kvadratickeho a linearniho pripadu
*/
    void test_cubic_roots() {
      {                  //Only 1 Root Is Real
        double a=3.;
        double b=-10.;
        double c=14.;
        double d=27.;


        double r[3];
        int cnt=cz::gepro::math::cubic_roots(a,b,c,d,r);
        TS_ASSERT_EQUALS(cnt,1)

        TS_ASSERT_DELTA(r[0],-1.0,_eps2);

        double res=a*r[0]*r[0]*r[0]+b*r[0]*r[0]+c*r[0]+d;

        TS_ASSERT_DELTA(res,0.0,_eps3);


      }

      {                //All 3 Roots Are Real and Equal
        double a=1.;
        double b=6.;
        double c=12.;
        double d=8.;


        double r[3];
        int cnt=cz::gepro::math::cubic_roots(a,b,c,d,r);
        TS_ASSERT_EQUALS(cnt,1)

        TS_ASSERT_DELTA(r[0],-2.0,_eps2);

        double res=a*r[0]*r[0]*r[0]+b*r[0]*r[0]+c*r[0]+d;
        TS_ASSERT_DELTA(res,0.0,_eps2);
      }

      {                //All 3 Roots Are Real and not Equal
        double a=2.;
        double b=-4.;
        double c=-22.;
        double d=24.;


        double r[3];
        int cnt=cz::gepro::math::cubic_roots(a,b,c,d,r);
        TS_ASSERT_EQUALS(cnt,3)

        TS_ASSERT_DELTA(r[0],-3.0,_eps2);
        TS_ASSERT_DELTA(r[1],1.0,_eps2);
        TS_ASSERT_DELTA(r[2],4.0,_eps2);

        double res=a*r[0]*r[0]*r[0]+b*r[0]*r[0]+c*r[0]+d;
        TS_ASSERT_DELTA(res,0.0,_eps3);

        res=a*r[1]*r[1]*r[1]+b*r[1]*r[1]+c*r[1]+d;
        TS_ASSERT_DELTA(res,0.0,_eps3);

        res=a*r[2]*r[2]*r[2]+b*r[2]*r[2]+c*r[2]+d;
        TS_ASSERT_DELTA(res,0.0,_eps3);


     }

     {                //Quadratic
        double a=0.;
        double b=3.;
        double c=-16.;
        double d=5.;


        double r[3];
        int cnt=cz::gepro::math::cubic_roots(a,b,c,d,r);
        TS_ASSERT_EQUALS(cnt,2)

        TS_ASSERT_DELTA(r[0],1./3.,_eps);
        TS_ASSERT_DELTA(r[1],5.0,_eps);

        double res=a*r[0]*r[0]*r[0]+b*r[0]*r[0]+c*r[0]+d;
        TS_ASSERT_DELTA(res,0.0,_eps);

        res=a*r[1]*r[1]*r[1]+b*r[1]*r[1]+c*r[1]+d;
        TS_ASSERT_DELTA(res,0.0,_eps);



     }

     {                //Linear
        double a=0.;
        double b=0.;
        double c=5.;
        double d=-10.;


        double r[3];
        int cnt=cz::gepro::math::cubic_roots(a,b,c,d,r);
        TS_ASSERT_EQUALS(cnt,1)

        TS_ASSERT_DELTA(r[0],2.,_eps);

        double res=a*r[0]*r[0]*r[0]+b*r[0]*r[0]+c*r[0]+d;
        TS_ASSERT_DELTA(res,0.0,_eps);

     }


     {
        double a=  209928.7433905752600000;
        double b= -349989.7375126306400000;
        double c=  128643.2308339661500000;
        double d=  3963.4777755737305000;

        double r[3];
        int cnt=cz::gepro::math::cubic_roots(a,b,c,d,r);

        TS_ASSERT_EQUALS(cnt,3)
        
        TS_ASSERT_DELTA(r[0],-0.0285536926899147,_eps);
        TS_ASSERT_DELTA(r[1], 0.6077293582290968,_eps);
        TS_ASSERT_DELTA(r[2], 1.0880078361572485,_eps);

        double res=a*r[0]*r[0]*r[0]+b*r[0]*r[0]+c*r[0]+d;

        TS_ASSERT_DELTA(res,0.0,_eps4);

        res=a*r[1]*r[1]*r[1]+b*r[1]*r[1]+c*r[1]+d;
        TS_ASSERT_DELTA(res,0.0,_eps4);

        res=a*r[2]*r[2]*r[2]+b*r[2]*r[2]+c*r[2]+d;
        TS_ASSERT_DELTA(res,0.0,_eps4);
      }
      {
        double a= -966.84348254186250;
        double b= -1126.2274808237114;
        double c=  620.58804780497110;
        double d=  779.97204608470201;

        double r[3];
        int cnt=cz::gepro::math::cubic_roots(a,b,c,d,r);
        TS_ASSERT_EQUALS(cnt,3)

        double res=a*r[0]*r[0]*r[0]+b*r[0]*r[0]+c*r[0]+d;

        TS_ASSERT_DELTA(res,0.0,_eps4);

        res=a*r[1]*r[1]*r[1]+b*r[1]*r[1]+c*r[1]+d;
        TS_ASSERT_DELTA(res,0.0,_eps4);

        res=a*r[2]*r[2]*r[2]+b*r[2]*r[2]+c*r[2]+d;
        TS_ASSERT_DELTA(res,0.0,_eps4);
      }
      {
        double a=	-1420243.2868196990;
	    double b=	-1258625.4077912406;
	    double c=	3210177.5314981556;
	    double d=	-1234072.1883912086;


        double r[3];
        int cnt=cz::gepro::math::cubic_roots(a,b,c,d,r);
        TS_ASSERT_EQUALS(cnt,1)


        double res=a*r[0]*r[0]*r[0]+b*r[0]*r[0]+c*r[0]+d;
        TS_ASSERT_DELTA(res,0.,_eps5);
      }

    }
};


#endif // __TEST_H

#ifndef   ___SDK_GEPRO_MATH_H
#define   ___SDK_GEPRO_MATH_H
#if defined(DEBUG_PREPROC)
  #pragma message(__FILE__ "(1) : debug included")
#endif
#ifndef _INC_MATH
  #include <math.h>
#endif
#ifndef _INC_LIMITS
  #include <limits.h>
#endif
#ifndef _INC_FLOAT
  #include <float.h>
#endif

/** \file
   Matematické konstanty a operace doplnìné nebo upravené pro GEPRO.
*/


#define M_E         2.71828182845904523536   /**< Konstanta epsilon */
#define M_LOG2E     1.44269504088896340736   /**< Pøirozený logaritmus epsilon */
#define M_LOG10E    0.434294481903251827651  /**< Desítkový logaritmus epsilon */
#define M_LN2       0.693147180559945309417  /**< Pøirozený logaritmus 2 */
#define M_LN10      2.30258509299404568402   /**< Pøirozený logaritmus 10 */
#ifndef M_PI 
  #define M_PI        3.14159265358979323846 /**< Konstanta ¶ */ 
#endif
#define M_PI_2      1.57079632679489661923   /**< Konstanta ¶/2 */ 
#define M_PI_4      0.785398163397448309616  /**< Konstanta ¶/4 */ 
#define M_1_PI      0.318309886183790671538  /**< Konstanta 1/¶ */ 
#define M_2_PI      0.636619772367581343076  /**< Konstanta 2/¶ */ 
#define M_1_SQRTPI  0.564189583547756286948  /**< 1/odmocnicna ¶ */
#define M_2_SQRTPI  1.12837916709551257390   /**< 2/odmocnicna ¶ */
#define M_SQRT2     1.41421356237309504880   /**< Druhá odmocnicna 2 */
#define M_SQRT_2    0.707106781186547524401  /**< Druhá odmocnicna 2/2 */

#define M_EPS       1.0e-7 /**< mensi koeficienty u vyssich mocnin se zanedbaji kvuli stabilite*/

namespace cz {
  namespace gepro {
    namespace math {


/** sign, funkce signum
*/
template <typename T> int sign(const T& r) {
  if (r>0) return 1;
  if (r<0) return -1;
  return 0;
}

/** cbrt, funkce pro vypocet treti odmocniny (cube root)
 *ma smysl pouze v sdk.vc6 v novejsich verzich existuje std::cbrt i C cbrt v math.h
*/
template <typename T> double cbrt(const T& r) {
  return sign(r) * pow(fabs(r),1/3.);
}

/** funkce pro vypocet korenu kvadraticke rovnice
*/
template <typename T> int quadratic_roots(double a,double b,double c, T& r) {
  if (fabs(a)<M_EPS) {     //linearni nebo konst
    if (fabs(b)<M_EPS) {
     if (c==0) {
        return -1;
     }
      return 0;
    }
    r[0]=-c/b;
    return 1;
  }

  double D=b*b-4*a*c;
  if (D<0) {
    return 0;
  }
  if (D==0) {
    r[0]=-b/(2*a);
    return 1;
  }
  r[0]=(-b-sqrt(D))/(2*a);
  r[1]=(-b+sqrt(D))/(2*a);
  if (r[0]>r[1]) {
    double tmp=r[0];
    r[0]=r[1];
    r[1]=tmp;
  }
  return 2;
}

/** funkce pro vypocet korenu kubicke rovnice
//Cubic Formula, finding an exact solution to a cubic polynomial
//by Stephen R. Schmitt
//zdroj: http://mysite.verizon.net/res148h4j/javascript/script_exact_cubic.html


/** cubic_roots, koreny kubicke rovnice, a*x^3 + b*x^2 + c*x + d =0

 real a,b,c,d koeficienty
 real r[3] pole vysledku koreny jsou setridene vzestupne predpoklada se ze je naalokovane
 return int pocet korenu 1-3 
*/ 
template <typename T> int cubic_roots(double a,double b,double c,double d, T& r) {
  if (fabs(a) < M_EPS) {     //kvadratic, linear nebo konst
    return quadratic_roots(b,c,d,r);
  }
  /*     //Only 1 Root Is Real
  a=3.;
  b=-10.;
  c=14.;
  d=27.;
  */
  /*      //All 3 Roots Are Real and Equal
  a=1.;
  b=6.;
  c=12.;
  d=8.;
  */

  double A=b/a;
  double B=c/a;
  double C=d/a;

  double Q=(3*B-A*A)/9;
  double R=(9*A*B - 27*C - 2*A*A*A)/54;

  //Then a polynomial discriminant can be defined as D = Q^3 + R^2
  double D=Q*Q*Q + R*R;

  if (D>=0) {  // complex or duplicate roots

     double S = cbrt(R + sqrt(D));
     double _T = cbrt(R - sqrt(D));    //T je zaroven typ a to nejde

     r[0] = -A/3 + (S + _T);    // double root

     if (D==0) {
       return 1;
     }
     
     r[1] = -A/3 - (S + _T)/2;  // double part of complex root
     //r[2] = -A/3 - (S + _T)/2;  // double part of complex root

     double Im = fabs(sqrt(3.)*(S - _T)/2);    // complex part of root pair   
        
     //discard complex roots
     if (Im!=0) {
       return 1;  //pouze jeden koren, complexni neberem
     }

     //setridit     
     double tmp;
     if (r[1] < r[0]) { tmp=r[0]; r[0]=r[1]; r[1]=tmp; }


     return 2;    //ty stejny nepotrebujem
  } else {
     double th =acos(R/sqrt(-(Q*Q*Q)));

     r[0] = 2*sqrt(-Q) * cos(th/3) - A/3;
     r[1] = 2*sqrt(-Q) * cos((th + 2*M_PI)/3) - A/3;
     r[2] = 2*sqrt(-Q) * cos((th + 4*M_PI)/3) - A/3;
          
     double tmp;
     if (r[1] < r[0]) { tmp=r[0]; r[0]=r[1]; r[1]=tmp; }
     if (r[2] < r[1]) { tmp=r[1]; r[1]=r[2]; r[2]=tmp; }
     if (r[1] < r[0]) { tmp=r[0]; r[0]=r[1]; r[1]=tmp; }
     if (r[2] < r[1]) { tmp=r[1]; r[1]=r[2]; r[2]=tmp; }

     return 3;
  }
}


    }; //math
  };   //gepro
};     //cz


#endif

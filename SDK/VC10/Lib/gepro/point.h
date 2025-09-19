#ifndef __SDK_GEPRO_POINT_H
#define __SDK_GEPRO_POINT_H
#if defined(DEBUG_PREPROC)
  #pragma message(__FILE__ "(1) : debug included")
#endif

//#include <boost/static_assert.hpp>

namespace cz {
namespace gepro {

/** @addtogroup geometry Geometrické typy a funkce
    @{
    Souøadnice bodu
*/
struct point {
       double X;  //! souøadnice X
       double Y;  //! souøadnice Y
       point() { X=Y=0; }
       point(double const& x,double const& y) { X=x;Y=y; }
       
       /** Test na shodnost bodù 
        
         @param a  
         @param b
         
         @return 
       */
       friend int operator ==(point const& a,point const& b)  // operator porovnani
              { return ( a.X==b.X && a.Y==b.Y ); }
       friend int operator !=(point const& a,point const& b)  // operator porovnani
              { return ( a.X!=b.X || a.Y!=b.Y ); }
       friend point operator +(point const& a,point const& b) { // operator scitani
         return point(a.X+b.X,a.Y+b.Y);
       }
       friend point operator *(point const& a,double d) { // operator nasobeni
         return point(a.X*d,a.Y*d);
       }
       friend point operator *(double d,point const& a) { // operator nasobeni
         return point(a.X*d,a.Y*d);
       }
       friend point operator /(point const& a,double d) { // operator deleni
         return point(a.X/d,a.Y/d);
       }
       friend point operator -(point const& a,point const& b) { // operator rozdil
         return point(a.X-b.X,a.Y-b.Y);
       }
       point& operator +=(const point& a) { // operator pricteni bodu
         X+=a.X;
         Y+=a.Y;
         return *this;
       }
       point& operator +=(const double& d) { // operator pricteni cisla
         X+=d;
         Y+=d;
         return *this;
       }
       point& operator -=(const point& a) { // operator odecteni bodu
         X-=a.X;
         Y-=a.Y;
         return *this;
       }
       point& operator -=(const double& d) { // operator odecteni cisla
         X-=d;
         Y-=d;
         return *this;
       }

       template <int N> double get() const
       {
         BOOST_STATIC_ASSERT(false);
       }
};

template <> inline double point::get<0>() const { return X; }
template <> inline double point::get<1>() const { return Y; }

/** Souøadnice bodu ve 3D
*/
struct point3 {
       double X;  //! souøadnice X
       double Y;  //! souøadnice Y
       double Z;  //! souøadnice Z (vyska)
       point3() { X=Y=Z=0; }
       point3(double const& x,double const& y,double const& z) { X=x;Y=y;Z=z; }
       
       /** Test na shodnost bodù 
        
         @param a  
         @param b
         
         @return 
       */
       friend int operator ==(point3 const& a,point3 const& b)  // operator porovnani
              { return ( a.X==b.X && a.Y==b.Y && a.Z==b.Z); }
};


}; //gepro
}; //cz
/**
 @}
 */
#endif

#ifndef __SDK_GEPRO_POINT_H
#define __SDK_GEPRO_POINT_H
#if defined(DEBUG_PREPROC)
  #pragma message(__FILE__ "(1) : debug included")
#endif

namespace cz {
namespace gepro {

/** @addtogroup geometry Geometrické typy a funkce
    @{
    Souøadnice bodu
*/
template <typename T>
struct _point {
  typedef T value_type;
  value_type X;  //! souøadnice X
       value_type Y;  //! souøadnice Y
       _point() { X=Y=0; }
       _point(value_type const& x,value_type const& y) { X=x;Y=y; }
       
       /** Test na shodnost bodù 
        
         @param a  
         @param b
         
         @return 
       */
       friend int operator ==(_point const& a,_point const& b)  // operator porovnani
              { return ( a.X==b.X && a.Y==b.Y ); }
       friend int operator !=(_point const& a,_point const& b)  // operator porovnani
              { return ( a.X!=b.X || a.Y!=b.Y ); }
       friend _point operator +(_point const& a,_point const& b) { // operator scitani
         return _point(a.X+b.X,a.Y+b.Y);
       }
       friend _point operator *(_point const& a,value_type d) { // operator nasobeni
         return _point(a.X*d,a.Y*d);
       }
       friend _point operator *(value_type d,_point const& a) { // operator nasobeni
         return _point(a.X*d,a.Y*d);
       }
       friend _point operator /(_point const& a,value_type d) { // operator deleni
         return _point(a.X/d,a.Y/d);
       }
       friend _point operator -(_point const& a,_point const& b) { // operator rozdil
         return _point(a.X-b.X,a.Y-b.Y);
       }
       _point& operator +=(const _point& a) { // operator pricteni bodu
         X+=a.X;
         Y+=a.Y;
         return *this;
       }
       _point& operator +=(const value_type& d) { // operator pricteni cisla
         X+=d;
         Y+=d;
         return *this;
       }
       _point& operator -=(const _point& a) { // operator odecteni bodu
         X-=a.X;
         Y-=a.Y;
         return *this;
       }
       _point& operator -=(const value_type& d) { // operator odecteni cisla
         X-=d;
         Y-=d;
         return *this;
       }


};

/** Souøadnice bodu ve 3D
*/
template <typename T>
struct _point3 {
  typedef T value_type;
       value_type X;  //! souøadnice X
       value_type Y;  //! souøadnice Y
       value_type Z;  //! souøadnice Z (vyska)
       _point3() { X=Y=Z=0; }
       _point3(value_type const& x,value_type const& y,value_type const& z) { X=x;Y=y;Z=z; }
       
       /** Test na shodnost bodù 
        
         @param a  
         @param b
         
         @return 
       */
       friend int operator ==(_point3 const& a,_point3 const& b)  // operator porovnani
              { return ( a.X==b.X && a.Y==b.Y && a.Z==b.Z); }
};
typedef _point<double> point;
typedef _point3<double> point3;
}; //gepro
}; //cz
/**
 @}
 */
#endif

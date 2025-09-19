#ifndef __SDK_GEPRO_RECTANGLE_H
#define __SDK_GEPRO_RECTANGLE_H
#if defined(DEBUG_PREPROC)
#pragma message(__FILE__ "(1) : debug included")
#endif
#ifndef __SDK_GEPRO_POINT_H
#include <gepro/point2.h>
#endif
#ifndef _INC_STDLIB
#include <stdlib.h>
#endif
namespace cz {
namespace gepro {
/** @addtogroup geometry Geometrick� typy a funkce
    @{
*/
#define KOKRECT_DELTAX .000001  ///< toleran�n� p�smo doublov�ch komparac�
#define KOKRECT_DELTAY .000001
/** Obd�lnikov� v��ez
    V K�ov�kovi plati : X1 <= X2  &&  Y1 <= Y2
    TODO: dohledat zda �se to pou��v� i jinak
*/
template <typename T = double>
struct _rectangle {
  typedef T value_type;
  value_type X1;
  value_type Y1;
  value_type X2;
  value_type Y2;
  _rectangle() { X1 = X2 = Y1 = Y2 = 0; }

  /**
  Constructor - negarantuje spr�vn� set��d�n� X a Y sou�adnic podle K�ov�ka - pokud m� b�t garantov�no, mus� se zavolat Sort().
  TODO: tato funk�nost mo�n� nen� ��douc�, ale t�ko ov��it zda se n�kde nevyu��v�
  
  @param  x1 The first x value.
  @param  y1 The first y value.
  @param  x2 The second x value.
  @param  y2 The second y value.
  */
  _rectangle(value_type const& x1, value_type const& y1, value_type const& x2, value_type const& y2) {
    X1 = x1;
    X2 = x2;
    Y1 = y1;
    Y2 = y2;
  }

  /**
  Constructor - garantuje spr�vn� se�azen� sou�adnic podle K�ov�ka.
  
  @param  p1 The first point.
  @param  p2 The second point.
  */
  _rectangle(const point& p1, const point& p2) {
    if (p1.X <= p2.X) {
      X1 = p1.X;
      X2 = p2.X;
    } else {
      X1 = p2.X;
      X2 = p1.X;
    }
    if (p1.Y <= p2.Y) {
      Y1 = p1.Y;
      Y2 = p2.Y;
    } else {
      Y1 = p2.Y;
      Y2 = p1.Y;
    }
  }
  /**
     P�e�te hodnoty ze vstupn�ho stringu, odd�lova� lze zadat v delim.
     Po�ad� X1 Y1 X2 Y2, nemus� b�t zad�ny v�echny, prvn� nevyhovuj�c� delim
     ukon�� parsov�n�.

     @param str   vstupn� string s hodnotami
     @param delim (Optional) odd�lova� hodnot - default ' '
  */
  void assign(const char* str, int delim = ' ') {
    if (!str || !*str) return;
    char* p;
    X1 = strtod(str, &p);
    if (*p != delim) return;
    Y1 = strtod(++p, &p);
    if (*p != delim) return;
    X2 = strtod(++p, &p);
    if (*p != delim) return;
    Y2 = strtod(++p, (char**)NULL);
  }
  /**
  Neplatn� rectangle, sou�adnice jsou opa�n�.
  
  @returns true/false
  */
  bool invalid() const { return X1 > X2 || Y1 > Y2; }
  /**
  All rectangle, nejv�t�� mo�n�.
  
  @returns true/false
  */
  bool all() const { return X1 == -DBL_MAX && X2 == DBL_MAX && Y1 == -DBL_MAX && Y2 == DBL_MAX; }
  /**
  Constructor - na�te hodnoty ze stringu - X1,Y1,X2,Y2, nemus� b�t v�echny, viz. assign
  
  @param  str   The string.
  @param  delim (Optional) The delimiter.
  */
  explicit _rectangle(const char* str, int delim = ' ') {
    X1 = X2 = Y1 = Y2 = 0;
    assign(str, delim);
  }
  void Sort() {
    value_type d;
    if (X2 < X1) {
      d = X2;
      X2 = X1;
      X1 = d;
    }
    if (Y2 < Y1) {
      d = Y2;
      Y2 = Y1;
      Y1 = d;
    }
  }
  static void inline expand(value_type& c1, value_type& c2, value_type fac) {
    value_type d = c2 - c1;
    value_type tmp = (c1 + c2) / 2;
    d *= fac;
    d /= 2;
    c1 = tmp - d;
    c2 = tmp + d;
  }

  /**
  Expanduje sou�adnice X podle faktoru
  
  @param  fac faktor pro zv�t�en�/zmen�en�
  */
  void expand_X(value_type fac) {
    if (invalid()) return;
    expand(X1, X2, fac);
  }

  /**
  Expanduje sou�adnice Y podle faktoru
  
  @param  fac faktor pro zv�t�en�/zmen�en�
  */
  void expand_Y(value_type fac) {
    if (invalid()) return;
    expand(Y1, Y2, fac);
  }

  /**
  Test zda je rectangle pr�zdn�.
  
  @returns true/false
  */
  bool empty() const { return ((X1 == X2) || (Y1 == Y2)); }
  /**
  Test zda je rectangle pr�zdn� - bere v �vahu toleran�n� p�smo KOKRECT_DELTAX,KOKRECT_DELTAY
  
  @returns true/false
  */
  bool Empty() const {
    return (X1 < X2 + KOKRECT_DELTAX && X1 > X2 - KOKRECT_DELTAX && Y1 > Y2 - KOKRECT_DELTAY && Y1 < Y2 + KOKRECT_DELTAY);
  }

  /**
  Rectangle m� nulov� sou�adnice
  
  @returns true/false
  */
  bool null() const { return (X1 == 0 && X2 == 0 && Y1 == 0 && Y2 == 0); }
  /**
  Test zda bod le�� uvni� rectanglu (hrana je uvnit�)
  
  @typeparam T typ sou�adnic bodu (v�t�inou value_type, ale lze pou��t cokoliv co lze na value_type castovat)
  @param  x sou�adnice X
  @param  y sou�adnice Y
  
  @returns true/false.
  */
  template <typename T>
  bool IsIn(const T& x, const T& y) const {
    if ((x >= X1) && (x <= X2) && (y >= Y1) && (y <= Y2)) { return true; }
    return false;
  }
  /**
  Test zda bod le�� uvni� rectanglu (hrana je vn�)
  
  @typeparam T typ sou�adnic bodu (v�t�inou value_type, ale lze pou��t cokoliv co lze na value_type castovat)
  @param  x sou�adnice X
  @param  y sou�adnice Y
  
  @returns true/false.
  */
  template <typename T>
  bool IsInOnly(const T& x, const T& y) const {
    if ((x > X1) && (x < X2) && (y > Y1) && (y < Y2)) { return true; }
    return false;
  }
  /**
  Test zda bod le�� uvni� rectanglu 
  
  @typeparam T typ sou�adnic bodu (v�t�inou value_type, ale lze pou��t cokoliv co lze na value_type castovat)
  @param  x sou�adnice X
  @param  y sou�adnice Y
  
  @returns 
    - 2  bod le�� �ist� uvnit�
    - 1  bod le�� na hran�
    - 0  bod je vn�
  */
  template <typename T>
  int IsInEx(const T& x, const T& y) const {
    if (IsInOnly(x, y)) return 2;
    if (IsIn(x, y)) return 1;
    return 0;
  }
  /**
  Test zda bod le�� uvni� rectanglu (hrana je uvnit�)
  
  @typeparam T p�edpokl�d� se typ bod s polo�kami X,Y 
  @param  p vstupn� bod
  
  @returns true/false.
  */
  template <typename T>
  bool IsIn(const T& p) const {
    return IsIn(p.X, p.Y);
  }
  bool Contains(point const& p) const { return IsIn(p); }
  /**
  Test zda bod le�� uvni� rectanglu (hrana je uvnit�)
  
  @typeparam T typ sou�adnic bodu (v�t�inou value_type, ale lze pou��t cokoliv co lze na value_type castovat)
  @param  x sou�adnice X
  @param  y sou�adnice Y
  
  @returns true/false.
  */
  bool Contains(value_type const& x, value_type const& y) const { return IsIn(x, y); }
  /**
  Test zda rectangle le�� uvnit� rectanglu (hrana je uvnit�)
  
  @param  krc testovan� rectangle
  
  @returns true/false.
  */
  bool Contains(const _rectangle& krc) const { return (X1 <= krc.X1 && X2 >= krc.X2 && Y1 <= krc.Y1 && Y2 >= krc.Y2); }

  /**
  Test na nerovnost - p�esn� shoda sou�adnic
  
  @param  a prvn� porovn�van� rectangle
  @param  b druh� porovn�van� rectangle
  
  @returns true/false.
  */
  friend bool operator!=(const _rectangle& a, const _rectangle& b) {
    return (a.X1 != b.X1 || a.X2 != b.X2 || a.Y1 != b.Y1 || a.Y2 != b.Y2);
  }
  /**
  Test na pr�nik - hrana je vn�
  
  @param  a prvn� porovn�van� rectangle
  @param  b druh� porovn�van� rectangle
  
  @returns true/false.
  */
  friend bool operator&&(const _rectangle& a, const _rectangle& b) { return !(a.X1 > b.X2 || b.X1 > a.X2 || a.Y2 < b.Y1 || b.Y2 < a.Y1); }

  /** Nastav� sou�adnice na 0 */
  void clear() { X1 = X2 = Y1 = Y2 = 0; }

  /**
  Sjednocen� se zadan�m rectanglem, ale oproti fci Union se rectangle::null() ignoruje
  
  @param  a vstupn�
  @return this reference
  */
  _rectangle& operator|=(const _rectangle& a) {
    if (null()||invalid()) {
      *this = a;
    } else if (a.null()||a.invalid())
      ;
    else {
      if (a.X1 < X1) X1 = a.X1;
      if (a.X2 > X2) X2 = a.X2;
      if (a.Y1 < Y1) Y1 = a.Y1;
      if (a.Y2 > Y2) Y2 = a.Y2;
    }
    return *this;
  }

  /**
  Zv�t�� rectangle aby obsahoval bod p.
  
  @typeparam T p�edpokl�d� se typ bod s polo�kami X,Y 
  @param  p vstupn� bod
  */
  template <typename T>
  void ExpandToInclude(const T& p) {
    if (invalid()) return;
    if (p.X > X2) X2 = p.X;
    if (p.X < X1) X1 = p.X;
    if (p.Y > Y2) Y2 = p.Y;
    if (p.Y < Y1) Y1 = p.Y;
  }

  /**
  Expands rectangle podle dx a dy.
  
  @param  dx zv�t�en�/zmen�en� v ose X
  @param  dy zv�t�en�/zmen�en� v ose Y
  */
  void Expand(value_type dx, value_type dy) {
    if (invalid()) return;
    X1 = (value_type)X1 - dx;
    X2 = (value_type)X2 + dx;
    Y2 = (value_type)Y2 + dy;
    Y1 = (value_type)Y1 - dy;
  }

  /**
  Expands rectangle podle factoru - stejn� v obou os�ch.
  
  @param  ex faktor zv�t�en�/zmen�en�
  */
  void ExpandP(value_type ex) {
    if (invalid()) return;
    ex = ex - 1;
    value_type dx = (X2 - X1) * ex;
    value_type dy = (Y2 - Y1) * ex;
    X1 = (value_type)X1 - dx;
    X2 = (value_type)X2 + dx;
    Y2 = (value_type)Y2 + dy;
    Y1 = (value_type)Y1 - dy;
  }

  /**
  Initializuje rectangle na bod - bude empty()
  
  @typeparam T p�edpokl�d� se typ bod s polo�kami X,Y 
  @param  p vstupn� bod
  */
  template <typename T>
  void Init(const T& p) {
    X1 = X2 = p.X;
    Y1 = Y2 = p.Y;
  }

  /**
  Nastav� rectangle aby zadan� bod le�el uprost�ed
  
  @typeparam T p�edpokl�d� se typ bod s polo�kami X,Y 
  @param  p vstupn� bod
  */
  template <typename T>
  void SetCenter(const T& p) {
    value_type dx2 = (X2 - X1) / 2.;
    value_type dy2 = (Y2 - Y1) / 2.;
    X1 = p.X - dx2;
    X2 = p.X + dx2;
    Y1 = p.Y - dy2;
    Y2 = p.Y + dy2;
  }
  /**
  Sjednocen� se zadan�m rectanglem.
  
  @param  rc zadan� rectangle
  
  @returns const reference
  */
  const _rectangle& Union(const _rectangle& rc) {
    if (rc.invalid()) return *this;
    if (invalid()) {
      *this = rc;
      return *this;
    }
    if (X1 > rc.X1) X1 = rc.X1;
    if (X2 < rc.X2) X2 = rc.X2;
    if (Y1 > rc.Y1) Y1 = rc.Y1;
    if (Y2 < rc.Y2) Y2 = rc.Y2;
    return *this;
  }
  /**
  Pr�nik se zadan�m rectanglem.
  
  @param  rc zadan� rectangle
  
  @returns const reference
  */
  const _rectangle& Intersection(const _rectangle& rc) {
    if (rc.invalid()) return *this;
    if (invalid()) {
      *this = rc;
      return *this;
    }
    if (X1 < rc.X1) X1 = rc.X1;
    if (X2 > rc.X2) X2 = rc.X2;
    if (Y1 < rc.Y1) Y1 = rc.Y1;
    if (Y2 > rc.Y2) Y2 = rc.Y2;

    if (X1 >= X2) { X1 = X2 = Y1 = Y2 = 0; }
    if (Y1 >= Y2) { X1 = X2 = Y1 = Y2 = 0; }
    return *this;
  }
  /**
  Cross o��zne �se�ku zadanou dv�ma body a �tvercem rectangle.
  
  @typeparam T p�edpokl�d� se typ bod s polo�kami X,Y 
  @param  p1 prvn� bod �se�ky
  @param  p2 druh� bod �se�ky
  
  @returns  - 0 .... neexistuje prusecik usecky s kokrect, usecka uvnitr
            - 1 .... levy konec usecky byl oriznut (zmena p1)
            - 2 .... pravy konec usecky byl oriznut (zmena p2)
            - 3 .... oba konce usecky byly oriznuty (zmena p1,p2)
            - 4 .... cela usecka je mimo kokrect
    
    ecks 8.7.1996.
  */
  template <typename P>
  int Cross(P& p1,P& p2) const {
    if (invalid()) return 4;
    int kod1 = 0, kod2 = 0, ret = 0;

    if (p1.X < X1) kod1 |= 1;
    else if (p1.X > X2)
      kod1 |= 4;
    if (p1.Y < Y1) kod1 |= 2;
    else if (p1.Y > Y2)
      kod1 |= 8;

    if (p2.X < X1) kod2 |= 1;
    else if (p2.X > X2)
      kod2 |= 4;
    if (p2.Y < Y1) kod2 |= 2;
    else if (p2.Y > Y2)
      kod2 |= 8;

    if (kod1 & kod2) { return 4; }  //neni zadny prusecik
    if (kod1 | kod2) {              //jinak neni prusecik
      do {
        int flag = kod1 ^ kod2;
        if (flag & 1) {
          if (kod1 & 1) {
            p1.Y = (p2.Y - p1.Y) / (p2.X - p1.X) * (X1 - p1.X) + p1.Y;
            p1.X = X1;
            kod1 &= 4;
            if (p1.Y < Y1) kod1 |= 2;
            else if (p1.Y > Y2)
              kod1 |= 8;
            ret |= 1;
          } else {
            p2.Y = (p2.Y - p1.Y) / (p2.X - p1.X) * (X1 - p1.X) + p1.Y;
            p2.X = X1;
            kod2 &= 4;
            if (p2.Y < Y1) kod2 |= 2;
            else if (p2.Y > Y2)
              kod2 |= 8;
            ret |= 2;
          }
        } else if (flag & 2) {
          if (kod1 & 2) {
            p1.X = (p2.X - p1.X) / (p2.Y - p1.Y) * (Y1 - p1.Y) + p1.X;
            p1.Y = Y1;
            kod1 &= 8;
            if (p1.X < X1) kod1 |= 1;
            else if (p1.X > X2)
              kod1 |= 4;
            ret |= 1;
          } else {
            p2.X = (p2.X - p1.X) / (p2.Y - p1.Y) * (Y1 - p1.Y) + p1.X;
            p2.Y = Y1;
            kod2 &= 8;
            if (p2.X < X1) kod2 |= 1;
            else if (p2.X > X2)
              kod2 |= 4;
            ret |= 2;
          }
        } else if (flag & 4) {
          if (kod1 & 4) {
            p1.Y = (p2.Y - p1.Y) / (p2.X - p1.X) * (X2 - p1.X) + p1.Y;
            p1.X = X2;
            kod1 &= 1;
            if (p1.Y < Y1) kod1 |= 2;
            else if (p1.Y > Y2)
              kod1 |= 8;
            ret |= 1;
          } else {
            p2.Y = (p2.Y - p1.Y) / (p2.X - p1.X) * (X2 - p1.X) + p1.Y;
            p2.X = X2;
            kod2 &= 1;
            if (p2.Y < Y1) kod2 |= 2;
            else if (p2.Y > Y2)
              kod2 |= 8;
            ret |= 2;
          }
        } else {
          if (kod1 & 8) {
            p1.X = (p2.X - p1.X) / (p2.Y - p1.Y) * (Y2 - p1.Y) + p1.X;
            p1.Y = Y2;
            kod1 &= 2;
            if (p1.X < X1) kod1 |= 1;
            else if (p1.X > X2)
              kod1 |= 4;
            ret |= 1;
          } else {
            p2.X = (p2.X - p1.X) / (p2.Y - p1.Y) * (Y2 - p1.Y) + p1.X;
            p2.Y = Y2;
            kod2 &= 2;
            if (p2.X < X1) kod2 |= 1;
            else if (p2.X > X2)
              kod2 |= 4;
            ret |= 2;
          }
        }
        if (kod1 & kod2) { return 4; }  //neni prusecik
      } while (kod1 | kod2);
    } else
      ret = 0;
    return (ret);
  }

  /**
       V�stup na stream, po�ad� X1 Y1 X2 Y2, default odd�lova� ' '.

       @tparam O typ v�stupn�ho streamu
       @param [in,out] o v�stupn� stream
       @param delim      (Optional) odd�lova� - default ' '

       @return A reference to an O.
    */
  template <typename O>
  O& print(O& o, int delim = ' ') const {
    o << X1 << ' ' << Y1 << ' ' << X2 << ' ' << Y2;
    return o;
  }
  int print(char* buf, unsigned size) const { return _snprintf(buf, size, "X1=%.6f,Y1=%.6f,X2=%.6f,Y2=%.6f", X1, Y1, X2, Y2); }

/**
   Oper�tor v�stupu na stream.

   @tparam O typ v�stupn�ho streamu
   @param [in,out] o v�stupn� stream
   @param r          instance rectanglu

   @return stream reference
*/
#if _MSC_VER >= 1600
  template <typename O>
  friend O& operator<<(O& o, const _rectangle& r) {
    r.print(o);
    return o;
  }
#endif
};
typedef _rectangle<double> rectangle;
/** @} */
};  // namespace gepro
};  // namespace cz

#endif

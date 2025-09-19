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
/** @addtogroup geometry Geometrické typy a funkce
    @{
*/
#define KOKRECT_DELTAX .000001  ///< toleranèní pásmo doublových komparací
#define KOKRECT_DELTAY .000001
/** Obdélnikový výøez
    V Køovákovi plati : X1 <= X2  &&  Y1 <= Y2
    TODO: dohledat zda ¨se to používá i jinak
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
  Constructor - negarantuje správné setøídìní X a Y souøadnic podle Køováka - pokud má být garantováno, musí se zavolat Sort().
  TODO: tato funkènost možná není žádoucí, ale tìžko ovìøit zda se nìkde nevyužívá
  
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
  Constructor - garantuje správné seøazení souøadnic podle Køováka.
  
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
     Pøeète hodnoty ze vstupního stringu, oddìlovaè lze zadat v delim.
     Poøadí X1 Y1 X2 Y2, nemusí být zadány všechny, první nevyhovující delim
     ukonèí parsování.

     @param str   vstupní string s hodnotami
     @param delim (Optional) oddìlovaè hodnot - default ' '
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
  Neplatný rectangle, souøadnice jsou opaènì.
  
  @returns true/false
  */
  bool invalid() const { return X1 > X2 || Y1 > Y2; }
  /**
  All rectangle, nejvìtší možný.
  
  @returns true/false
  */
  bool all() const { return X1 == -DBL_MAX && X2 == DBL_MAX && Y1 == -DBL_MAX && Y2 == DBL_MAX; }
  /**
  Constructor - naète hodnoty ze stringu - X1,Y1,X2,Y2, nemusí být všechny, viz. assign
  
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
  Expanduje souøadnice X podle faktoru
  
  @param  fac faktor pro zvìtšení/zmenšení
  */
  void expand_X(value_type fac) {
    if (invalid()) return;
    expand(X1, X2, fac);
  }

  /**
  Expanduje souøadnice Y podle faktoru
  
  @param  fac faktor pro zvìtšení/zmenšení
  */
  void expand_Y(value_type fac) {
    if (invalid()) return;
    expand(Y1, Y2, fac);
  }

  /**
  Test zda je rectangle prázdný.
  
  @returns true/false
  */
  bool empty() const { return ((X1 == X2) || (Y1 == Y2)); }
  /**
  Test zda je rectangle prázdný - bere v úvahu toleranèní pásmo KOKRECT_DELTAX,KOKRECT_DELTAY
  
  @returns true/false
  */
  bool Empty() const {
    return (X1 < X2 + KOKRECT_DELTAX && X1 > X2 - KOKRECT_DELTAX && Y1 > Y2 - KOKRECT_DELTAY && Y1 < Y2 + KOKRECT_DELTAY);
  }

  /**
  Rectangle má nulové souøadnice
  
  @returns true/false
  */
  bool null() const { return (X1 == 0 && X2 == 0 && Y1 == 0 && Y2 == 0); }
  /**
  Test zda bod leží uvniø rectanglu (hrana je uvnitø)
  
  @typeparam T typ souøadnic bodu (vìtšinou value_type, ale lze použít cokoliv co lze na value_type castovat)
  @param  x souøadnice X
  @param  y souøadnice Y
  
  @returns true/false.
  */
  template <typename T>
  bool IsIn(const T& x, const T& y) const {
    if ((x >= X1) && (x <= X2) && (y >= Y1) && (y <= Y2)) { return true; }
    return false;
  }
  /**
  Test zda bod leží uvniø rectanglu (hrana je vnì)
  
  @typeparam T typ souøadnic bodu (vìtšinou value_type, ale lze použít cokoliv co lze na value_type castovat)
  @param  x souøadnice X
  @param  y souøadnice Y
  
  @returns true/false.
  */
  template <typename T>
  bool IsInOnly(const T& x, const T& y) const {
    if ((x > X1) && (x < X2) && (y > Y1) && (y < Y2)) { return true; }
    return false;
  }
  /**
  Test zda bod leží uvniø rectanglu 
  
  @typeparam T typ souøadnic bodu (vìtšinou value_type, ale lze použít cokoliv co lze na value_type castovat)
  @param  x souøadnice X
  @param  y souøadnice Y
  
  @returns 
    - 2  bod leží èistì uvnitø
    - 1  bod leží na hranì
    - 0  bod je vnì
  */
  template <typename T>
  int IsInEx(const T& x, const T& y) const {
    if (IsInOnly(x, y)) return 2;
    if (IsIn(x, y)) return 1;
    return 0;
  }
  /**
  Test zda bod leží uvniø rectanglu (hrana je uvnitø)
  
  @typeparam T pøedpokládá se typ bod s položkami X,Y 
  @param  p vstupní bod
  
  @returns true/false.
  */
  template <typename T>
  bool IsIn(const T& p) const {
    return IsIn(p.X, p.Y);
  }
  bool Contains(point const& p) const { return IsIn(p); }
  /**
  Test zda bod leží uvniø rectanglu (hrana je uvnitø)
  
  @typeparam T typ souøadnic bodu (vìtšinou value_type, ale lze použít cokoliv co lze na value_type castovat)
  @param  x souøadnice X
  @param  y souøadnice Y
  
  @returns true/false.
  */
  bool Contains(value_type const& x, value_type const& y) const { return IsIn(x, y); }
  /**
  Test zda rectangle leží uvnitø rectanglu (hrana je uvnitø)
  
  @param  krc testovaný rectangle
  
  @returns true/false.
  */
  bool Contains(const _rectangle& krc) const { return (X1 <= krc.X1 && X2 >= krc.X2 && Y1 <= krc.Y1 && Y2 >= krc.Y2); }

  /**
  Test na nerovnost - pøesná shoda souøadnic
  
  @param  a první porovnávaný rectangle
  @param  b druhý porovnávaný rectangle
  
  @returns true/false.
  */
  friend bool operator!=(const _rectangle& a, const _rectangle& b) {
    return (a.X1 != b.X1 || a.X2 != b.X2 || a.Y1 != b.Y1 || a.Y2 != b.Y2);
  }
  /**
  Test na prùnik - hrana je vnì
  
  @param  a první porovnávaný rectangle
  @param  b druhý porovnávaný rectangle
  
  @returns true/false.
  */
  friend bool operator&&(const _rectangle& a, const _rectangle& b) { return !(a.X1 > b.X2 || b.X1 > a.X2 || a.Y2 < b.Y1 || b.Y2 < a.Y1); }

  /** Nastaví souøadnice na 0 */
  void clear() { X1 = X2 = Y1 = Y2 = 0; }

  /**
  Sjednocení se zadaným rectanglem, ale oproti fci Union se rectangle::null() ignoruje
  
  @param  a vstupní
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
  Zvìtší rectangle aby obsahoval bod p.
  
  @typeparam T pøedpokládá se typ bod s položkami X,Y 
  @param  p vstupní bod
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
  
  @param  dx zvìtšení/zmenšení v ose X
  @param  dy zvìtšení/zmenšení v ose Y
  */
  void Expand(value_type dx, value_type dy) {
    if (invalid()) return;
    X1 = (value_type)X1 - dx;
    X2 = (value_type)X2 + dx;
    Y2 = (value_type)Y2 + dy;
    Y1 = (value_type)Y1 - dy;
  }

  /**
  Expands rectangle podle factoru - stejnì v obou osách.
  
  @param  ex faktor zvìtšení/zmenšení
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
  
  @typeparam T pøedpokládá se typ bod s položkami X,Y 
  @param  p vstupní bod
  */
  template <typename T>
  void Init(const T& p) {
    X1 = X2 = p.X;
    Y1 = Y2 = p.Y;
  }

  /**
  Nastaví rectangle aby zadaný bod ležel uprostøed
  
  @typeparam T pøedpokládá se typ bod s položkami X,Y 
  @param  p vstupní bod
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
  Sjednocení se zadaným rectanglem.
  
  @param  rc zadaný rectangle
  
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
  Prùnik se zadaným rectanglem.
  
  @param  rc zadaný rectangle
  
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
  Cross oøízne úseèku zadanou dvìma body a ètvercem rectangle.
  
  @typeparam T pøedpokládá se typ bod s položkami X,Y 
  @param  p1 první bod úseèky
  @param  p2 druhý bod úseèky
  
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
       Výstup na stream, poøadí X1 Y1 X2 Y2, default oddìlovaè ' '.

       @tparam O typ výstupního streamu
       @param [in,out] o výstupní stream
       @param delim      (Optional) oddìlovaè - default ' '

       @return A reference to an O.
    */
  template <typename O>
  O& print(O& o, int delim = ' ') const {
    o << X1 << ' ' << Y1 << ' ' << X2 << ' ' << Y2;
    return o;
  }
  int print(char* buf, unsigned size) const { return _snprintf(buf, size, "X1=%.6f,Y1=%.6f,X2=%.6f,Y2=%.6f", X1, Y1, X2, Y2); }

/**
   Operátor výstupu na stream.

   @tparam O typ výstupního streamu
   @param [in,out] o výstupní stream
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

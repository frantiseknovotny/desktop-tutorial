#ifndef __SDK_GEPRO_RECTANGLE_H
#define __SDK_GEPRO_RECTANGLE_H
#if defined(DEBUG_PREPROC)
#pragma message(__FILE__ "(1) : debug included")
#endif
#ifndef __SDK_GEPRO_POINT_H
#include <gepro/point.h>
#endif
#ifndef _INC_STDLIB
#include <stdlib.h>
#endif
#ifndef _CFLOAT_
#include <cfloat>
#endif
namespace cz {
namespace gepro {
/** Obdélnikový výøez
    Platí: X1 <= X2  &&  Y1 <= Y2 jinak je to invalid()
*/
struct rectangle {
  double X1;
  double Y1;
  double X2;
  double Y2;
  rectangle() { X1 = X2 = Y1 = Y2 = 0; }
  rectangle(double const& x1, double const& y1, double const& x2, double const& y2) {
    X1 = x1;
    X2 = x2;
    Y1 = y1;
    Y2 = y2;
  }
  rectangle(const point& p1, const point& p2) {
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
  explicit rectangle(const char* str, int delim = ' ') {
    X1 = X2 = Y1 = Y2 = 0;
    assign(str, delim);
  }

  /**
  Neplatný rectangle, souøadnice jsou opaènì.
  
  @returns true/false
  */
  bool invalid() const { return X1 > X2 || Y1 > Y2; }
  /**
  Null rectangle, souøadnice jsou 0.
  
  @returns true/false
  */
  bool null() const { return X1 == 0 && X2 == 0 && Y1 == 0 && Y2 == 0; }
  /**
  All rectangle, nejvìtší možný.
  
  @returns true/false
  */
  bool all() const { return X1 == -DBL_MAX && X2 == DBL_MAX && Y1 == -DBL_MAX && Y2 == DBL_MAX; }
  /** Nastavení max. rozsahu souøadnic */
  void setmax() {
    X1 = -DBL_MAX;
    X2 = DBL_MAX;
    Y1 = -DBL_MAX;
    Y2 = DBL_MAX;
  }
  /** Nulování - stav po default konstruktoru. */
  void clear() {
    X1 = 0;
    X2 = 0;
    Y1 = 0;
    Y2 = 0;
  }
  static void inline expand(double& c1, double& c2, double fac) {
    double d = c2 - c1;
    double tmp = (c1 + c2) / 2;
    d *= fac;
    d /= 2;
    c1 = tmp - d;
    c2 = tmp + d;
  }

  void expand_X(double fac) {
    if (invalid()) return;
    expand(X1, X2, fac);
  }

  void expand_Y(double fac) {
    if (invalid()) return;
    expand(Y1, Y2, fac);
  }

  bool empty() const { return ((X1 == X2) || (Y1 == Y2)); }

  template <typename T>
  bool IsIn(const T& p) const {

    if ((p.X >= X1) && (p.X <= X2) && (p.Y >= Y1) && (p.Y <= Y2)) { return true; }
    return false;
  }

  template <typename T>
  bool IsIn(const T& x, const T& y) const {
    if ((x >= X1) && (x <= X2) && (y >= Y1) && (y <= Y2)) { return true; }
    return false;
  }

  template <typename T>
  void ExpandToInclude(const T& p) {
    if (invalid()) return;
    if (p.X > X2) X2 = p.X;
    if (p.X < X1) X1 = p.X;
    if (p.Y > Y2) Y2 = p.Y;
    if (p.Y < Y1) Y1 = p.Y;
  }

  template <typename T>
  void Init(const T& p) {
    X1 = X2 = p.X;
    Y1 = Y2 = p.Y;
  }

  template <typename T>
  void SetCenter(const T& p) {
    double dx2 = (X2 - X1) / 2.;
    double dy2 = (Y2 - Y1) / 2.;
    X1 = p.X - dx2;
    X2 = p.X + dx2;
    Y1 = p.Y - dy2;
    Y2 = p.Y + dy2;
  }

  const rectangle& Union(const rectangle& rc) {
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

  const rectangle& Intersection(const rectangle& rc) {
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
/**
   Operátor výstupu na stream.

   @tparam O typ výstupního streamu
   @param [in,out] o výstupní stream
   @param r          instance rectanglu

   @return stream reference
*/
#if _MSC_VER >= 1600
  template <typename O>
  friend O& operator<<(O& o, const rectangle& r) {
    r.print(o);
    return o;
  }
#endif
};
};  // namespace gepro
};  // namespace cz

#endif

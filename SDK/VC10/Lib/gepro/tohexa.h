#ifndef ___SDK_GEPRO_TOHEXA_H
#define ___SDK_GEPRO_TOHEXA_H
#if defined(DEBUG_PREPROC)
#pragma message(__FILE__ "(1) : debug included")
#endif
#ifndef ___SDK_GEPRO_HEXA_H
#include "hexa.h"
#endif
#ifndef __SDK_GEPRO_TCHARBUF_H
#include "tcharbuf.h"
#endif
namespace cz {
namespace gepro {
/** Pøevod èísla 0-16 na hexa
  @param c  pøevádìné èíslo
  @return   ASCII znak (0-9,A-F)
*/
inline char tohexa(int c) {
  static char hexa[] = "0123456789ABCDEF";
  return hexa[c & 0xf];
}
/** Výpis èísla 0-16 v hexa tvaru
   !neukládá zakonèovací '\0'

  @param c  pøevádìné èíslo
  @param q  buffer (min. 2 znaky)
  @return   ukazatel na následující øetìzec (q+2)
*/
inline char* tohexa(int c, char* q) {
  *q++ = tohexa(c >> 4);
  *q++ = tohexa(c);
  return q;
}
template <typename O>
O& hexdump(const void* ptr, unsigned l, O& o, const char* pref, unsigned lpref) {
  const char* beg = (const char*)ptr;
  const char* end = beg + l;
  for (; beg < end; beg++) {
    if (pref) o.write(pref, lpref);
    char q[16];
    char* e = tohexa(*beg, q);
    o.write(q, (e - q));
  }
  return o;
}
inline size_t hexdump(const void* ptr, unsigned l, char* q, unsigned size, const char* pref = NULL, unsigned lpref = 0) {
  tcharbuf<char> o(q, size);
  hexdump(ptr, l, o, pref, lpref);
  return o.size();
}
}  // namespace gepro
}  // namespace cz
#endif

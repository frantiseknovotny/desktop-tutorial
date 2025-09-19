#ifndef ___SDK_GEPRO_HEXA_H
#define ___SDK_GEPRO_HEXA_H
#if defined(DEBUG_PREPROC)
#pragma message(__FILE__ "(1) : debug included")
#endif
namespace cz {
namespace gepro { /** Vrací hodnotu hexa znaku
  @param a     vstupní znak (char)
  @return
    - 0-15  OK
    - -1    není to hexa znak
*/
inline int gethexa(int a) {
  if (a >= '0' && a <= '9') {
    a -= '0';
  } else if (a >= 'A' && a <= 'F') {
    a -= 'A' - 10;
  } else if (a >= 'a' && a <= 'f') {
    a -= 'a' - 10;
  } else
    a = -1;
  return a;
}
/** test zda znak je hexa

  @param  a znak

  @returns true/false
*/
inline bool ishexa(int a) {
  if (a >= '0' && a <= '9') return true;
  if (a >= 'A' && a <= 'F') return true;
  if (a >= 'a' && a <= 'f') return true;
  return false;
}
/** Test zda všechny znaky jsou hexa

  @param  b zaèátek øetìzce
  @param  e konec øetìzce

  @returns true/false
*/
template <typename E>
bool ishexa(const E* b, const E* e) {
  for (; b < e; ++b) {
    if (!ishexa(*b)) return false;
  }
  return true;
}
/** Test zda odpovídá formát UUID pø. c91b5e63-f39f-4c54-857d-0a694e8f47fa.

  @param  b zaèátek øetìzce
  @param  e konec øetìzce

  @returns true/false
*/
template <typename E>
bool isuuid(const E* b, const E* e) {
  if (e - b != 36) return false;
  const E* k = b + 8;
  if (!ishexa(b, k)) return false;
  if (*k != '-') return false;
  b = k + 1;
  k = b + 4;
  if (!ishexa(b, k)) return false;
  if (*k != '-') return false;
  b = k + 1;
  k = b + 4;
  if (!ishexa(b, k)) return false;
  if (*k != '-') return false;
  b = k + 1;
  k = b + 4;
  if (!ishexa(b, k)) return false;
  if (*k != '-') return false;
  b = k + 1;
  k = b + 12;
  if (!ishexa(b, k)) return false;
  return true;
}
/**
   Hexadecimalni kod hodnoty

   @param a  vstupni hodnota

   @return hexadecimální kód
*/
inline int hexa(int a) {
  if (a < 9) return 0x30 | a;
  return 0x40 | (a - 9);
}
}  // namespace gepro
}  // namespace cz
#endif

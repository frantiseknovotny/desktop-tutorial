#ifndef ___SDK_GEPRO_STRING_ILESS_H
#define ___SDK_GEPRO_STRING_ILESS_H
#if defined(DEBUG_PREPROC)
  #pragma message(__FILE__ "(1) : debug included")
#endif
namespace std {
/** Insensitive comparator - boost::algorithm::ilexicographical_compare

  @typeparam S typ stringu
*/
template <typename S>
struct string_iless {
  bool operator()(const S& a, const S& b) const { return boost::algorithm::ilexicographical_compare(a, b); }
};
};
#endif

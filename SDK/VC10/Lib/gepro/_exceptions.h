#ifndef __SDK_GEPRO__EXCEPTIONS_H
#define __SDK_GEPRO__EXCEPTIONS_H
#if defined(DEBUG_PREPROC)
#pragma message(__FILE__ "(1) : debug included")
#endif

namespace cz {
namespace gepro {
/** Základ pro vyjímky gepro, nahrazuje std::exception kde nelze STL použít. */
class exceptionex {
 public:
  virtual const char* what() = 0;
};

};  // namespace gepro
};  // namespace cz

#endif

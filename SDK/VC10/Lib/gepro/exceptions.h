#ifndef __SDK_GEPRO_EXCEPTIONS_H
#define __SDK_GEPRO_EXCEPTIONS_H
#if defined(DEBUG_PREPROC)
  #pragma message(__FILE__ "(1) : debug included")
#endif
#ifndef _EXCEPTION_
  #include <exception>
#endif
#ifndef   ___GEPRO_PREPROC_H
  #include "preproc.h"
#endif
namespace cz {
namespace gepro {
/** Výjimka hlásící nedostatek pamìti u statického bufferu.
*/
class small_buffer:public std::exception {
  public:
    small_buffer():std::exception("small buffer") {}
    small_buffer(const char* _msg):std::exception(_msg) {}
};
};//gepro
};//cz 
/** Macro pro generování výjimky typu const char*,
    které vypíše text str a místo ve zdojovém kódu kde k ní došlo.
	Urèeno pro výpis výjimek, které by nemìly nastat - napø. chybné použití funkcí.
*/
#define EXCEPTIONMSG(str) throw PREPROC_LINE_QUOTE(str);
#endif 

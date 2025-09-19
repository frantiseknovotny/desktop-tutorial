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
/** V�jimka hl�s�c� nedostatek pam�ti u statick�ho bufferu.
*/
class small_buffer:public std::exception {
  public:
    small_buffer():std::exception("small buffer") {}
    small_buffer(const char* _msg):std::exception(_msg) {}
};
};//gepro
};//cz 
/** Macro pro generov�n� v�jimky typu const char*,
    kter� vyp�e text str a m�sto ve zdojov�m k�du kde k n� do�lo.
	Ur�eno pro v�pis v�jimek, kter� by nem�ly nastat - nap�. chybn� pou�it� funkc�.
*/
#define EXCEPTIONMSG(str) throw PREPROC_LINE_QUOTE(str);
#endif 

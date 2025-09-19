#ifndef __SDK_GEPRO_EXCEPTIONS2_H
#define __SDK_GEPRO_EXCEPTIONS2_H 
#ifdef __SDK_GEPRO_EXCEPTIONS3_H  
#error "Nelze kombinovat header exceptions2 a exceptions3, pouzijte vsude exception3.h"
#endif
#if defined(DEBUG_PREPROC)
  #pragma message(__FILE__ "(1) : debug included")
#endif
#ifndef __SDK_GEPRO_SMARTBUFS_H
  #include "smartbufs.h"
#endif
#ifndef   ___GEPRO_PREPROC_H
  #include "preproc.h"
#endif
#ifndef __SDK_GEPRO__EXCEPTIONS_H
#include "_exceptions.h"
#endif
namespace cz {
namespace gepro {
/** Obecná výjimka pro odeslání zprávy pomocí statického bufferu na zásobníku 1024 bytù,
    pokud není na zásobníku ani 1024 bytù, aplikace je stejnì v koncích.
*/
class exceptionmsg:public std::exception {
  public:
    tstatbufe<1024> msg;
    virtual const char* what() const {return msg.begin();}
};      
#define THROW_CMSG(x) throw PREPROC_LINE_QUOTE(x);
#define THROW_SMALLBUF(x) throw cz::gepro::small_buffer(PREPROC_LINE_QUOTE("smallbuffer:" x));
#define THROW_NOTINTERFACE(t) {cz::gepro::exceptionmsg e;e.msg << __FILE__ << "(" << __LINE__ << ") : neinicializovaný interface " << t;throw e;}
#define THROW_INVALID_PARAM(p1) {cz::gepro::exceptionmsg e;e.msg << __FILE__ << "(" << __LINE__ << ") : neplatný parametr " << p1;throw e;}
#define THROW_IO(file,fl) {char buf[256];FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM|FORMAT_MESSAGE_IGNORE_INSERTS ,NULL,GetLastError(),MAKELANGID(LANG_NEUTRAL,SUBLANG_DEFAULT),buf,sizeof(buf),NULL);\
                           cz::gepro::exceptionmsg e;e.msg << __FILE__ << "(" << __LINE__ << ") : IO error " << file << "," << fl << "," << buf;throw e;}
#define THROW_FILE_NOT_EXISTS(file) {cz::gepro::exceptionmsg e;e.msg << __FILE__ << "(" << __LINE__ << ") : Soubor neexistuje " << file;throw e;}
#define THROW_TABLE_NOTFOUND(t) {cz::gepro::exceptionmsg e;e.msg << __FILE__ << "(" << __LINE__ << ") : nenalezena tabulka " << t;throw e;}
#define THROW_ALLOCA(t) {cz::gepro::exceptionmsg e;e.msg << __FILE__ << "(" << __LINE__ << ") : nelze alokovat na stacku " << t;throw e;}
#define THROW_MSG(t)                     {cz::gepro::exceptionmsg e;e.msg << __FILE__ << "(" << __LINE__ << ") : " << t;throw e;}
#define THROW_MSG1(t,p1)                 {cz::gepro::exceptionmsg e;e.msg << __FILE__ << "(" << __LINE__ << ") : " << t << #p1"='" << p1 << "'";throw e;}
#define THROW_MSG2(t,p1,p2)              {cz::gepro::exceptionmsg e;e.msg << __FILE__ << "(" << __LINE__ << ") : " << t << #p1"='" << p1 << "'," << #p2"='" << p2 << "'";throw e;}
#define THROW_MSG3(t,p1,p2,p3)           {cz::gepro::exceptionmsg e;e.msg << __FILE__ << "(" << __LINE__ << ") : " << t << #p1"='" << p1 << "'," << #p2"='" << p2 << "'," << #p3"='" << p3 << "'";throw e;}
#define THROW_MSG4(t,p1,p2,p3,p4)        {cz::gepro::exceptionmsg e;e.msg << __FILE__ << "(" << __LINE__ << ") : " << t << #p1"='" << p1 << "'," << #p2"='" << p2 << "'," << #p3"='" << p3 << "'," << #p4"='" << p4 << "'";throw e;}
#define THROW_MSG5(t,p1,p2,p3,p4,p5)     {cz::gepro::exceptionmsg e;e.msg << __FILE__ << "(" << __LINE__ << ") : " << t << #p1"='" << p1 << "'," << #p2"='" << p2 << "'," << #p3"='" << p3 << "'," << #p4"='" << p4 << "'," << #p5"='" << p5 << "'";throw e;}
};//gepro
};//cz
#endif 

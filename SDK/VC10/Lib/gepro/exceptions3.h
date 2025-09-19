#ifndef __SDK_GEPRO_EXCEPTIONS3_H
#define __SDK_GEPRO_EXCEPTIONS3_H
#ifdef __SDK_GEPRO_EXCEPTIONS2_H
#error "Nelze kombinovat header exceptions2 a exceptions3, pouzijte vsude exception3.h"
#endif
#if defined(DEBUG_PREPROC)
#pragma message(__FILE__ "(1) : debug included")
#endif
#ifndef __SDK_GEPRO_SMARTBUFS_H
#include "smartbufs.h"
#endif
#ifndef ___GEPRO_PREPROC_H
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
class exception1024 : public cz::gepro::exceptionex {
 public:
  tstatbuf<1024> msg;
  virtual const char* what() { return msg.begin(); }
};
class exception4096 : public cz::gepro::exceptionex {
 public:
  tstatbuf<4096> msg;
  virtual const char* what() { return msg.begin(); }
};
typedef exception1024 exceptionmsg;
};  // namespace gepro
};  // namespace cz
#ifndef EXCEPTIONMSGBUFFER
#define EXCEPTIONMSGBUFFER cz::gepro::exception1024
#endif
#ifndef THROW_PARAM_PRINT
#define THROW_PARAM_PRINT(p) #p "=" << p
#endif
#define THROW_CMSG(x) throw PREPROC_LINE_QUOTE(x);
#define THROW_EMSG(x, m)                 \
  {                                      \
    EXCEPTIONMSGBUFFER e;                \
    e.msg << PREPROC_LINE_QUOTE(x) << m; \
    throw e;                             \
  }
#define THROW_EMSGP(x, p1)                                   \
  {                                                          \
    EXCEPTIONMSGBUFFER e;                                    \
    e.msg << PREPROC_LINE_QUOTE(x) << THROW_PARAM_PRINT(p1); \
    throw e;                                                 \
  }
#define THROW_EMSG1(x, m, p1)                         \
  {                                                   \
    EXCEPTIONMSGBUFFER e;                             \
    e.msg << PREPROC_LINE_QUOTE(x) << m << "," << p1; \
    throw e;                                          \
  }
#define THROW_EMSG1P(x, m, p1)                                        \
  {                                                                   \
    EXCEPTIONMSGBUFFER e;                                             \
    e.msg << PREPROC_LINE_QUOTE(x) << m << "," THROW_PARAM_PRINT(p1); \
    throw e;                                                          \
  }
#define THROW_EMSG2(x, m, p1, p2)                                  \
  {                                                                \
    EXCEPTIONMSGBUFFER e;                                          \
    e.msg << PREPROC_LINE_QUOTE(x) << m << "," << p1 << "," << p2; \
    throw e;                                                       \
  }
#define THROW_EMSG2P(x, m, p1, p2)                                                                    \
  {                                                                                                   \
    EXCEPTIONMSGBUFFER e;                                                                             \
    e.msg << PREPROC_LINE_QUOTE(x) << m << "," THROW_PARAM_PRINT(p1) << "," << THROW_PARAM_PRINT(p2); \
    throw e;                                                                                          \
  }
#ifndef THROW_SMALLBUF
/**
Generování výjinky "smallbuffer", generuje místìní ve zdrojovém kódu a je možné zadat stringovou konstantu x - nikoliv promìnnou !

@param  x text pro upøesnìní
*/
#define THROW_SMALLBUF(x) THROW_CMSG("smallbuffer " x);
#endif
#ifndef THROW_NOTINTERFACE
/**
Generování výjinky "neinicializovaný interface", generuje místìní ve zdrojovém kódu a je možné zadat stringovou konstantu x - nikoliv promìnnou !

@param  x text pro upøesnìní
*/
#define THROW_NOTINTERFACE(x) THROW_CMSG("neinicializovaný interface " x);
#endif
#ifndef THROW_NOIFACE
/**
Generování výjinky "neinicializovaný interface", generuje místìní ve zdrojovém kódu a je možné zadat stringovou konstantu x - nikoliv promìnnou !

@param  x text pro upøesnìní
*/
#define THROW_NOIFACE(x) THROW_CMSG("neinicializovaný interface " x);
#endif
#ifndef THROW_INVALID_PARAM
/**
Generování výjinky "neplatný parametr", generuje místìní ve zdrojovém kódu, název a hodnotu parametru (pokud má operator << na cz::gepro::tstatbuf) !

@param  x neplatný parametr
*/
#define THROW_INVALID_PARAM(p1) THROW_EMSGP("neplatný parametr ", p1);
#endif
#ifndef THROW_FILE_NOT_EXISTS
/**
Generování výjinky "soubor neexistuje", generuje místìní ve zdrojovém kódu a název souboru

@param  x název souboru
*/
#define THROW_FILE_NOT_EXISTS(file) THROW_EMSG("soubor neexistuje ", file);
#endif
#ifndef THROW_IO
/**
Generování výjinky "soubor neexistuje", generuje místìní ve zdrojovém kódu a název souboru

@param  x název souboru
*/
#define THROW_IO(file, fl)                                                                           \
  {                                                                                                  \
    char buf[256];                                                                                   \
    FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, NULL, GetLastError(), \
                   MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), buf, sizeof(buf), NULL);               \
    THROW_EMSG1("IO error ", file, fl);                                                              \
  }
#endif
/**
Generování výjinky "pøeteèení zásobníku", generuje místìní ve zdrojovém kódu a požadovanou velikost

@param  t požadovaní velikost
*/
#ifndef THROW_ALLOCA
#define THROW_ALLOCA(t) THROW_EMSG("pøeteèení zásobníku ", t);
#endif
#ifndef _THROW_INVALID_INDEX
/**
Generování výjinky "neplatný index", generuje místìní ve zdrojovém kódu a požadovaný index

@param  t požadovaný index
*/
#define _THROW_INVALID_INDEX(t) THROW_EMSG("neplatný index ", t);
#endif
#ifndef THROW_INVALID_INDEX
/**
Generování výjinky "neplatný index", generuje místìní ve zdrojovém kódu, požadovaný index a maximální index

@param  t požadovaný index
@param  m maximální index index
*/
#define THROW_INVALID_INDEX(t, m) THROW_EMSG1("neplatný index ", t, m);
#endif
#ifndef THROW_TABLE_NOTFOUND
#define THROW_TABLE_NOTFOUND(t) THROW_EMSG("nenalezena tabulka ", t);
#endif
#ifndef THROW_MSG
#define THROW_MSG(t) THROW_EMSG("", t)
#endif
#ifndef THROW_MSG1
#define THROW_MSG1(t, p1) THROW_EMSG1P("", t, p1)
#endif
#ifndef THROW_MSG2
#define THROW_MSG2(t, p1, p2) THROW_EMSG2P("", t, p1, p2)
#endif
#endif

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
/** Obecn� v�jimka pro odesl�n� zpr�vy pomoc� statick�ho bufferu na z�sobn�ku 1024 byt�,
    pokud nen� na z�sobn�ku ani 1024 byt�, aplikace je stejn� v konc�ch.
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
Generov�n� v�jinky "smallbuffer", generuje m�st�n� ve zdrojov�m k�du a je mo�n� zadat stringovou konstantu x - nikoliv prom�nnou !

@param  x text pro up�esn�n�
*/
#define THROW_SMALLBUF(x) THROW_CMSG("smallbuffer " x);
#endif
#ifndef THROW_NOTINTERFACE
/**
Generov�n� v�jinky "neinicializovan� interface", generuje m�st�n� ve zdrojov�m k�du a je mo�n� zadat stringovou konstantu x - nikoliv prom�nnou !

@param  x text pro up�esn�n�
*/
#define THROW_NOTINTERFACE(x) THROW_CMSG("neinicializovan� interface " x);
#endif
#ifndef THROW_NOIFACE
/**
Generov�n� v�jinky "neinicializovan� interface", generuje m�st�n� ve zdrojov�m k�du a je mo�n� zadat stringovou konstantu x - nikoliv prom�nnou !

@param  x text pro up�esn�n�
*/
#define THROW_NOIFACE(x) THROW_CMSG("neinicializovan� interface " x);
#endif
#ifndef THROW_INVALID_PARAM
/**
Generov�n� v�jinky "neplatn� parametr", generuje m�st�n� ve zdrojov�m k�du, n�zev a hodnotu parametru (pokud m� operator << na cz::gepro::tstatbuf) !

@param  x neplatn� parametr
*/
#define THROW_INVALID_PARAM(p1) THROW_EMSGP("neplatn� parametr ", p1);
#endif
#ifndef THROW_FILE_NOT_EXISTS
/**
Generov�n� v�jinky "soubor neexistuje", generuje m�st�n� ve zdrojov�m k�du a n�zev souboru

@param  x n�zev souboru
*/
#define THROW_FILE_NOT_EXISTS(file) THROW_EMSG("soubor neexistuje ", file);
#endif
#ifndef THROW_IO
/**
Generov�n� v�jinky "soubor neexistuje", generuje m�st�n� ve zdrojov�m k�du a n�zev souboru

@param  x n�zev souboru
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
Generov�n� v�jinky "p�ete�en� z�sobn�ku", generuje m�st�n� ve zdrojov�m k�du a po�adovanou velikost

@param  t po�adovan� velikost
*/
#ifndef THROW_ALLOCA
#define THROW_ALLOCA(t) THROW_EMSG("p�ete�en� z�sobn�ku ", t);
#endif
#ifndef _THROW_INVALID_INDEX
/**
Generov�n� v�jinky "neplatn� index", generuje m�st�n� ve zdrojov�m k�du a po�adovan� index

@param  t po�adovan� index
*/
#define _THROW_INVALID_INDEX(t) THROW_EMSG("neplatn� index ", t);
#endif
#ifndef THROW_INVALID_INDEX
/**
Generov�n� v�jinky "neplatn� index", generuje m�st�n� ve zdrojov�m k�du, po�adovan� index a maxim�ln� index

@param  t po�adovan� index
@param  m maxim�ln� index index
*/
#define THROW_INVALID_INDEX(t, m) THROW_EMSG1("neplatn� index ", t, m);
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

#ifndef PPG_LOGKEY
/** Oddìlovaè mezi klíèem a hodnotou logované promìnné*/
#define PPG_LOGKEY "\":\""
#endif
#ifndef PPG_LOGENTER
/** Otevírací závorka seznamu logovaných hodnot */
#define PPG_LOGENTER ":{\""
#endif
#ifndef PPG_LOGLEAVE
/** Zavírací závorka seznamu logovaných hodnot */
#define PPG_LOGLEAVE "\"}"
#endif
#ifndef PPG_LOGNEXT
/** Oddìlovaè mezi dvìma promìnnými*/
#define PPG_LOGNEXT "\",\""
#endif
#ifndef PPG_LOGPARAM0

/** Logování 1. promìnné

  @param  p název promìnné
*/
#define PPG_LOGPARAM0(p) #p << PPG_LOGKEY << p
#endif
#ifndef PPG_LOGPARAM
/** Logování 2. a další promìnné

  @param  p název promìnné
*/
#define PPG_LOGPARAM(p) PPG_LOGNEXT << #p << PPG_LOGKEY << p
#endif
#ifndef PPG_LOGSTRBUF
/** Typ streamu do nìhož se vytváøí logovaný záznam */
#define PPG_LOGSTRBUF std::stringstream
#endif
#ifndef PPG_LOGERROUT
/** Výstupná funkce pro výpis logovaného záznamu level error

  @param  l hodnota typu const char*
*/
#define PPG_LOGERROUT(l) std::cout << l;
#endif
#ifndef PPG_LOGWARNOUT
/** Výstupná funkce pro výpis logovaného záznamu level error

  @param  l hodnota typu const char*
*/
#define PPG_LOGWARNOUT(l) PPG_LOGERROUT(l)
#endif
#ifndef PPG_LOGINFOOUT
/** Výstupná funkce pro výpis logovaného záznamu level info

  @param  l hodnota typu const char*
*/
#define PPG_LOGINFOOUT(l) PPG_LOGWARNOUT(l)
#endif
#ifndef PPG_LOGDBGOUT
/** Výstupná funkce pro výpis logovaného záznamu level debug

  @param  l hodnota typu const char*
*/
#define PPG_LOGDBGOUT(l) PPG_LOGINFOOUT(l)
#endif
#ifndef PPG_LOGTRACEOUT
/** Výstupná funkce pro výpis logovaného záznamu level trace

  @param  l hodnota typu const char*
*/
#define PPG_LOGTRACEOUT(l) PPG_LOGDBGOUT(l)
#endif

#ifndef PPG_LOGERROUTPUT
/** Vyzvednutí logované hodnoty a výpis na výstup

  @param  l The void to process.
*/
#define PPG_LOGERROUTPUT(l)  \
  {                          \
    std::string s = l.str(); \
    PPG_LOGERROUT(s.c_str()) \
  }
#endif
#ifndef PPG_LOGWARNOUTPUT
/** Vyzvednutí logované hodnoty a výpis na výstup

  @param  l The void to process.
*/
#define PPG_LOGWARNOUTPUT(l)  \
  {                           \
    std::string s = l.str();  \
    PPG_LOGWARNOUT(s.c_str()) \
  }
#endif
#ifndef PPG_LOGINFOOUTPUT
/** Vyzvednutí logované hodnoty a výpis na výstup

  @param  l The void to process.
*/
#define PPG_LOGINFOOUTPUT(l)  \
  {                           \
    std::string s = l.str();  \
    PPG_LOGINFOOUT(s.c_str()) \
  }
#endif
#ifndef PPG_LOGDBGOUTPUT
/** Vyzvednutí logované hodnoty a výpis na výstup

  @param  l The void to process.
*/
#define PPG_LOGDBGOUTPUT(l)  \
  {                          \
    std::string s = l.str(); \
    PPG_LOGDBGOUT(s.c_str()) \
  }
#endif
#ifndef PPG_LOGTRACEOUTPUT
/** Vyzvednutí logované hodnoty a výpis na výstup

  @param  l The void to process.
*/
#define PPG_LOGTRACEOUTPUT(l)  \
  {                            \
    std::string s = l.str();   \
    PPG_LOGTRACEOUT(s.c_str()) \
  }
#endif
/** Výpis parametrù na stream - èíslo v názvu odpovídá poètu parametrù

  @param  p1 The first void.
*/
#define PPG_LOGPARAM1(p1) << PPG_LOGPARAM0(p1)
#define PPG_LOGPARAM2(p1, p2) << PPG_LOGPARAM0(p1) << PPG_LOGPARAM(p2)
#define PPG_LOGPARAM3(p1, p2, p3) << PPG_LOGPARAM0(p1) << PPG_LOGPARAM(p2) << PPG_LOGPARAM(p3)
#define PPG_LOGPARAM4(p1, p2, p3, p4) << PPG_LOGPARAM0(p1) << PPG_LOGPARAM(p2) << PPG_LOGPARAM(p3) << PPG_LOGPARAM(p4)
#define PPG_LOGPARAM5(p1, p2, p3, p4, p5) \
  << PPG_LOGPARAM0(p1) << PPG_LOGPARAM(p2) << PPG_LOGPARAM(p3) << PPG_LOGPARAM(p4) << PPG_LOGPARAM(p5)
#define PPG_LOGPARAM6(p1, p2, p3, p4, p5, p6) \
  << PPG_LOGPARAM0(p1) << PPG_LOGPARAM(p2) << PPG_LOGPARAM(p3) << PPG_LOGPARAM(p4) << PPG_LOGPARAM(p5) << PPG_LOGPARAM(p6)
#define PPG_LOGPARAM7(p1, p2, p3, p4, p5, p6, p7)                                                                          \
  << PPG_LOGPARAM0(p1) << PPG_LOGPARAM(p2) << PPG_LOGPARAM(p3) << PPG_LOGPARAM(p4) << PPG_LOGPARAM(p5) << PPG_LOGPARAM(p6) \
  << PPG_LOGPARAM(p7)
#define PPG_LOGPARAM8(p1, p2, p3, p4, p5, p6, p7, p8)                                                                      \
  << PPG_LOGPARAM0(p1) << PPG_LOGPARAM(p2) << PPG_LOGPARAM(p3) << PPG_LOGPARAM(p4) << PPG_LOGPARAM(p5) << PPG_LOGPARAM(p6) \
  << PPG_LOGPARAM(p7) << PPG_LOGPARAM(p8)
#define PPG_LOGPARAM9(p1, p2, p3, p4, p5, p6, p7, p8, p9)                                                                  \
  << PPG_LOGPARAM0(p1) << PPG_LOGPARAM(p2) << PPG_LOGPARAM(p3) << PPG_LOGPARAM(p4) << PPG_LOGPARAM(p5) << PPG_LOGPARAM(p6) \
  << PPG_LOGPARAM(p7) << PPG_LOGPARAM(p8) << PPG_LOGPARAM(p9)
#define PPG_LOGPARAM10(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10)                                                            \
  << PPG_LOGPARAM0(p1) << PPG_LOGPARAM(p2) << PPG_LOGPARAM(p3) << PPG_LOGPARAM(p4) << PPG_LOGPARAM(p5) << PPG_LOGPARAM(p6) \
  << PPG_LOGPARAM(p7) << PPG_LOGPARAM(p8) << PPG_LOGPARAM(p9) << PPG_LOGPARAM(p10)

/** Výpis parametrù na stream - èíslo v názvu odpovídá poètu parametrù

  @param  l  stream v nìmž se vytváøí výstup
  @param  m  vysvìtlující zpráva
  @param  p1 první a další parametry
*/
#define PPG_LOGSTREAM1(l, m, p1) l << m << PPG_LOGENTER PPG_LOGPARAM1(p1) << PPG_LOGLEAVE;
#define PPG_LOGSTREAM2(l, m, p1, p2) l << m << PPG_LOGENTER PPG_LOGPARAM2(p1, p2) << PPG_LOGLEAVE;
#define PPG_LOGSTREAM3(l, m, p1, p2, p3) l << m << PPG_LOGENTER PPG_LOGPARAM3(p1, p2, p3) << PPG_LOGLEAVE;
#define PPG_LOGSTREAM4(l, m, p1, p2, p3, p4) l << m << PPG_LOGENTER PPG_LOGPARAM4(p1, p2, p3, p4) << PPG_LOGLEAVE;
#define PPG_LOGSTREAM5(l, m, p1, p2, p3, p4, p5) l << m << PPG_LOGENTER PPG_LOGPARAM5(p1, p2, p3, p4, p5) << PPG_LOGLEAVE;
#define PPG_LOGSTREAM6(l, m, p1, p2, p3, p4, p5, p6) l << m << PPG_LOGENTER PPG_LOGPARAM6(p1, p2, p3, p4, p5, p6) << PPG_LOGLEAVE;
#define PPG_LOGSTREAM7(l, m, p1, p2, p3, p4, p5, p6, p7) l << m << PPG_LOGENTER PPG_LOGPARAM7(p1, p2, p3, p4, p5, p6, p7) << PPG_LOGLEAVE;
#define PPG_LOGSTREAM8(l, m, p1, p2, p3, p4, p5, p6, p7, p8) \
  l << m << PPG_LOGENTER PPG_LOGPARAM8(p1, p2, p3, p4, p5, p6, p7, p8) << PPG_LOGLEAVE;
#define PPG_LOGSTREAM9(l, m, p1, p2, p3, p4, p5, p6, p7, p8, p9) \
  l << m << PPG_LOGENTER PPG_LOGPARAM9(p1, p2, p3, p4, p5, p6, p7, p8, p9) << PPG_LOGLEAVE;
#define PPG_LOGSTREAM10(l, m, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10) \
  l << m << PPG_LOGENTER PPG_LOGPARAM10(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10) << PPG_LOGLEAVE;

#define PPG_SERROR0(m) PPG_LOGERROUT(m)
#define PPG_SERROR1(m, p1)   \
  {                          \
    PPG_LOGSTRBUF l;         \
    PPG_LOGSTREAM1(l, m, p1) \
    PPG_LOGERROUTPUT(l)      \
  }

#define PPG_SERROR2(m, p1, p2)   \
  {                              \
    PPG_LOGSTRBUF l;             \
    PPG_LOGSTREAM2(l, m, p1, p2) \
    PPG_LOGERROUTPUT(l)          \
  }
#define PPG_SERROR3(m, p1, p2, p3)   \
  {                                  \
    PPG_LOGSTRBUF l;                 \
    PPG_LOGSTREAM3(l, m, p1, p2, p3) \
    PPG_LOGERROUTPUT(l)              \
  }
#define PPG_SERROR4(m, p1, p2, p3, p4) \
  {                                    \
    PPG_LOGSTRBUF l;                   \
    PPG_LOGSTREAM4(l, m, p1, p2, p4)   \
    PPG_LOGERROUTPUT(l)                \
  }
#define PPG_SERROR5(m, p1, p2, p3, p4, p5) \
  {                                        \
    PPG_LOGSTRBUF l;                       \
    PPG_LOGSTREAM5(l, m, p1, p2, p4, p5)   \
    PPG_LOGERROUTPUT(l)                    \
  }
#define PPG_SERROR6(m, p1, p2, p3, p4, p5, p6) \
  {                                            \
    PPG_LOGSTRBUF l;                           \
    PPG_LOGSTREAM6(l, m, p1, p2, p4, p5, p6)   \
    PPG_LOGERROUTPUT(l)                        \
  }
#define PPG_SERROR7(m, p1, p2, p3, p4, p5, p6, p7) \
  {                                                \
    PPG_LOGSTRBUF l;                               \
    PPG_LOGSTREAM7(l, m, p1, p2, p4, p5, p6, p7)   \
    PPG_LOGERROUTPUT(l)                            \
  }
#define PPG_SERROR8(m, p1, p2, p3, p4, p5, p6, p7, p8) \
  {                                                    \
    PPG_LOGSTRBUF l;                                   \
    PPG_LOGSTREAM8(l, m, p1, p2, p4, p5, p6, p7, p8)   \
    PPG_LOGERROUTPUT(l)                                \
  }
#define PPG_SERROR9(m, p1, p2, p3, p4, p5, p6, p7, p8, p9) \
  {                                                        \
    PPG_LOGSTRBUF l;                                       \
    PPG_LOGSTREAM9(l, m, p1, p2, p4, p5, p6, p7, p8, p9)   \
    PPG_LOGERROUTPUT(l)                                    \
  }
#define PPG_SERROR10(m, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10) \
  {                                                              \
    PPG_LOGSTRBUF l;                                             \
    PPG_LOGSTREAM10(l, m, p1, p2, p4, p5, p6, p7, p8, p9, p10)   \
    PPG_LOGERROUTPUT(l)                                          \
  }
#define PPG_SWARN0(m) PPG_LOGWARNOUT(m)
#define PPG_SWARN1(m, p1)    \
  {                          \
    PPG_LOGSTRBUF l;         \
    PPG_LOGSTREAM1(l, m, p1) \
    PPG_LOGWARNOUTPUT(l)     \
  }

#define PPG_SWARN2(m, p1, p2)    \
  {                              \
    PPG_LOGSTRBUF l;             \
    PPG_LOGSTREAM2(l, m, p1, p2) \
    PPG_LOGWARNOUTPUT(l)         \
  }
#define PPG_SWARN3(m, p1, p2, p3)    \
  {                                  \
    PPG_LOGSTRBUF l;                 \
    PPG_LOGSTREAM3(l, m, p1, p2, p3) \
    PPG_LOGWARNOUTPUT(l)             \
  }
#define PPG_SWARN4(m, p1, p2, p3, p4) \
  {                                   \
    PPG_LOGSTRBUF l;                  \
    PPG_LOGSTREAM4(l, m, p1, p2, p4)  \
    PPG_LOGWARNOUTPUT(l)              \
  }
#define PPG_SWARN5(m, p1, p2, p3, p4, p5) \
  {                                       \
    PPG_LOGSTRBUF l;                      \
    PPG_LOGSTREAM5(l, m, p1, p2, p4, p5)  \
    PPG_LOGWARNOUTPUT(l)                  \
  }
#define PPG_SWARN6(m, p1, p2, p3, p4, p5, p6) \
  {                                           \
    PPG_LOGSTRBUF l;                          \
    PPG_LOGSTREAM6(l, m, p1, p2, p4, p5, p6)  \
    PPG_LOGWARNOUTPUT(l)                      \
  }
#define PPG_SWARN7(m, p1, p2, p3, p4, p5, p6, p7) \
  {                                               \
    PPG_LOGSTRBUF l;                              \
    PPG_LOGSTREAM7(l, m, p1, p2, p4, p5, p6, p7)  \
    PPG_LOGWARNOUTPUT(l)                          \
  }
#define PPG_SWARN8(m, p1, p2, p3, p4, p5, p6, p7, p8) \
  {                                                   \
    PPG_LOGSTRBUF l;                                  \
    PPG_LOGSTREAM8(l, m, p1, p2, p4, p5, p6, p7, p8)  \
    PPG_LOGWARNOUTPUT(l)                              \
  }
#define PPG_SWARN9(m, p1, p2, p3, p4, p5, p6, p7, p8, p9) \
  {                                                       \
    PPG_LOGSTRBUF l;                                      \
    PPG_LOGSTREAM9(l, m, p1, p2, p4, p5, p6, p7, p8, p9)  \
    PPG_LOGWARNOUTPUT(l)                                  \
  }
#define PPG_SWARN10(m, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10) \
  {                                                             \
    PPG_LOGSTRBUF l;                                            \
    PPG_LOGSTREAM10(l, m, p1, p2, p4, p5, p6, p7, p8, p9, p10)  \
    PPG_LOGWARNOUTPUT(l)                                        \
  }
#define PPG_SINFO0(m) PPG_LOGINFOOUT(m)
#define PPG_SINFO1(m, p1)    \
  {                          \
    PPG_LOGSTRBUF l;         \
    PPG_LOGSTREAM1(l, m, p1) \
    PPG_LOGINFOOUTPUT(l)     \
  }

#define PPG_SINFO2(m, p1, p2)    \
  {                              \
    PPG_LOGSTRBUF l;             \
    PPG_LOGSTREAM2(l, m, p1, p2) \
    PPG_LOGINFOOUTPUT(l)         \
  }
#define PPG_SINFO3(m, p1, p2, p3)    \
  {                                  \
    PPG_LOGSTRBUF l;                 \
    PPG_LOGSTREAM3(l, m, p1, p2, p3) \
    PPG_LOGINFOOUTPUT(l)             \
  }
#define PPG_SINFO4(m, p1, p2, p3, p4) \
  {                                   \
    PPG_LOGSTRBUF l;                  \
    PPG_LOGSTREAM4(l, m, p1, p2, p4)  \
    PPG_LOGINFOOUTPUT(l)              \
  }
#define PPG_SINFO5(m, p1, p2, p3, p4, p5) \
  {                                       \
    PPG_LOGSTRBUF l;                      \
    PPG_LOGSTREAM5(l, m, p1, p2, p4, p5)  \
    PPG_LOGINFOOUTPUT(l)                  \
  }
#define PPG_SINFO6(m, p1, p2, p3, p4, p5, p6) \
  {                                           \
    PPG_LOGSTRBUF l;                          \
    PPG_LOGSTREAM6(l, m, p1, p2, p4, p5, p6)  \
    PPG_LOGINFOOUTPUT(l)                      \
  }
#define PPG_SINFO7(m, p1, p2, p3, p4, p5, p6, p7) \
  {                                               \
    PPG_LOGSTRBUF l;                              \
    PPG_LOGSTREAM7(l, m, p1, p2, p4, p5, p6, p7)  \
    PPG_LOGINFOOUTPUT(l)                          \
  }
#define PPG_SINFO8(m, p1, p2, p3, p4, p5, p6, p7, p8) \
  {                                                   \
    PPG_LOGSTRBUF l;                                  \
    PPG_LOGSTREAM8(l, m, p1, p2, p4, p5, p6, p7, p8)  \
    PPG_LOGINFOOUTPUT(l)                              \
  }
#define PPG_SINFO9(m, p1, p2, p3, p4, p5, p6, p7, p8, p9) \
  {                                                       \
    PPG_LOGSTRBUF l;                                      \
    PPG_LOGSTREAM9(l, m, p1, p2, p4, p5, p6, p7, p8, p9)  \
    PPG_LOGINFOOUTPUT(l)                                  \
  }
#define PPG_SINFO10(m, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10) \
  {                                                             \
    PPG_LOGSTRBUF l;                                            \
    PPG_LOGSTREAM10(l, m, p1, p2, p4, p5, p6, p7, p8, p9, p10)  \
    PPG_LOGINFOOUTPUT(l)                                        \
  }
#define PPG_SDEBUG0(m) PPG_LOGDBGOUT(m)
#define PPG_SDEBUG1(m, p1)   \
  {                          \
    PPG_LOGSTRBUF l;         \
    PPG_LOGSTREAM1(l, m, p1) \
    PPG_LOGDBGOUTPUT(l)      \
  }

#define PPG_SDEBUG2(m, p1, p2)   \
  {                              \
    PPG_LOGSTRBUF l;             \
    PPG_LOGSTREAM2(l, m, p1, p2) \
    PPG_LOGDBGOUTPUT(l)          \
  }
#define PPG_SDEBUG3(m, p1, p2, p3)   \
  {                                  \
    PPG_LOGSTRBUF l;                 \
    PPG_LOGSTREAM3(l, m, p1, p2, p3) \
    PPG_LOGDBGOUTPUT(l)              \
  }
#define PPG_SDEBUG4(m, p1, p2, p3, p4) \
  {                                    \
    PPG_LOGSTRBUF l;                   \
    PPG_LOGSTREAM4(l, m, p1, p2, p4)   \
    PPG_LOGDBGOUTPUT(l)                \
  }
#define PPG_SDEBUG5(m, p1, p2, p3, p4, p5) \
  {                                        \
    PPG_LOGSTRBUF l;                       \
    PPG_LOGSTREAM5(l, m, p1, p2, p4, p5)   \
    PPG_LOGDBGOUTPUT(l)                    \
  }
#define PPG_SDEBUG6(m, p1, p2, p3, p4, p5, p6) \
  {                                            \
    PPG_LOGSTRBUF l;                           \
    PPG_LOGSTREAM6(l, m, p1, p2, p4, p5, p6)   \
    PPG_LOGDBGOUTPUT(l)                        \
  }
#define PPG_SDEBUG7(m, p1, p2, p3, p4, p5, p6, p7) \
  {                                                \
    PPG_LOGSTRBUF l;                               \
    PPG_LOGSTREAM7(l, m, p1, p2, p4, p5, p6, p7)   \
    PPG_LOGDBGOUTPUT(l)                            \
  }
#define PPG_SDEBUG8(m, p1, p2, p3, p4, p5, p6, p7, p8) \
  {                                                    \
    PPG_LOGSTRBUF l;                                   \
    PPG_LOGSTREAM8(l, m, p1, p2, p4, p5, p6, p7, p8)   \
    PPG_LOGDBGOUTPUT(l)                                \
  }
#define PPG_SDEBUG9(m, p1, p2, p3, p4, p5, p6, p7, p8, p9) \
  {                                                        \
    PPG_LOGSTRBUF l;                                       \
    PPG_LOGSTREAM9(l, m, p1, p2, p4, p5, p6, p7, p8, p9)   \
    PPG_LOGDBGOUTPUT(l)                                    \
  }
#define PPG_SDEBUG10(m, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10) \
  {                                                              \
    PPG_LOGSTRBUF l;                                             \
    PPG_LOGSTREAM10(l, m, p1, p2, p4, p5, p6, p7, p8, p9, p10)   \
    PPG_LOGDBGOUTPUT(l)                                          \
  }
#define PPG_STRACE0(m) PPG_LOGTRACEOUT(m)
#define PPG_STRACE1(m, p1)   \
  {                          \
    PPG_LOGSTRBUF l;         \
    PPG_LOGSTREAM1(l, m, p1) \
    PPG_LOGTRACEOUTPUT(l)    \
  }

#define PPG_STRACE2(m, p1, p2)   \
  {                              \
    PPG_LOGSTRBUF l;             \
    PPG_LOGSTREAM2(l, m, p1, p2) \
    PPG_LOGTRACEOUTPUT(l)        \
  }
#define PPG_STRACE3(m, p1, p2, p3)   \
  {                                  \
    PPG_LOGSTRBUF l;                 \
    PPG_LOGSTREAM3(l, m, p1, p2, p3) \
    PPG_LOGTRACEOUTPUT(l)            \
  }
#define PPG_STRACE4(m, p1, p2, p3, p4) \
  {                                    \
    PPG_LOGSTRBUF l;                   \
    PPG_LOGSTREAM4(l, m, p1, p2, p4)   \
    PPG_LOGTRACEOUTPUT(l)              \
  }
#define PPG_STRACE5(m, p1, p2, p3, p4, p5) \
  {                                        \
    PPG_LOGSTRBUF l;                       \
    PPG_LOGSTREAM5(l, m, p1, p2, p4, p5)   \
    PPG_LOGTRACEOUTPUT(l)                  \
  }
#define PPG_STRACE6(m, p1, p2, p3, p4, p5, p6) \
  {                                            \
    PPG_LOGSTRBUF l;                           \
    PPG_LOGSTREAM6(l, m, p1, p2, p4, p5, p6)   \
    PPG_LOGTRACEOUTPUT(l)                      \
  }
#define PPG_STRACE7(m, p1, p2, p3, p4, p5, p6, p7) \
  {                                                \
    PPG_LOGSTRBUF l;                               \
    PPG_LOGSTREAM7(l, m, p1, p2, p4, p5, p6, p7)   \
    PPG_LOGTRACEOUTPUT(l)                          \
  }
#define PPG_STRACE8(m, p1, p2, p3, p4, p5, p6, p7, p8) \
  {                                                    \
    PPG_LOGSTRBUF l;                                   \
    PPG_LOGSTREAM8(l, m, p1, p2, p4, p5, p6, p7, p8)   \
    PPG_LOGTRACEOUTPUT(l)                              \
  }
#define PPG_STRACE9(m, p1, p2, p3, p4, p5, p6, p7, p8, p9) \
  {                                                        \
    PPG_LOGSTRBUF l;                                       \
    PPG_LOGSTREAM9(l, m, p1, p2, p4, p5, p6, p7, p8, p9)   \
    PPG_LOGTRACEOUTPUT(l)                                  \
  }
#define PPG_STRACE10(m, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10) \
  {                                                              \
    PPG_LOGSTRBUF l;                                             \
    PPG_LOGSTREAM10(l, m, p1, p2, p4, p5, p6, p7, p8, p9, p10)   \
    PPG_LOGTRACEOUTPUT(l)                                        \
  }

/** Makra pro definice tøíd realizující dynamické pøipojení DLL knihoven. Pomocí maker se definují jména
    funkcí v DLL, jména v C++ a parametry, koncept def_dynalib.h z nich potom sestaví tøídu zajišující
    vyzvednutí adres funkcí a jejich obalové pro volání. 
    Rozšíøení spoèivá v pøidání maker pro funkce s více parametry.
*/
// clang-format off
#undef PROCADR0
#undef PROCADR1
#undef PROCADR2
#undef PROCADR3
#undef PROCADR4
#undef PROCADR5
#undef PROCADR6
#undef PROCADR7
#undef PROCADR8
#undef PROCADR9
#undef PROCADR10
#undef PROCADR11
#undef PROCADR12
#undef PROCADR13
#undef PROCADR14
#undef PROCADR15

#undef PROCADR0_void
#undef PROCADR1_void
#undef PROCADR2_void
#undef PROCADR3_void
#undef PROCADR4_void
#undef PROCADR5_void
#undef PROCADR6_void
#undef PROCADR7_void
#undef PROCADR8_void
#undef PROCADR9_void
#undef PROCADR10_void
#undef PROCADR11_void
#undef PROCADR12_void
#undef PROCADR13_void
#undef PROCADR14_void
#undef PROCADR15_void

#undef PROCADR1_params
#undef PROCADR2_params
#undef PROCADR3_params
#undef PROCADR4_params
#undef PROCADR5_params
#undef PROCADR6_params
#undef PROCADR7_params
#undef PROCADR8_params
#undef PROCADR9_params
#undef PROCADR10_params
#undef PROCADR11_params
#undef PROCADR12_params
#undef PROCADR13_params
#undef PROCADR14_params
#undef PROCADR15_params

#undef PROCADR1_void_params
#undef PROCADR2_void_params
#undef PROCADR3_void_params
#undef PROCADR4_void_params
#undef PROCADR5_void_params
#undef PROCADR6_void_params
#undef PROCADR7_void_params
#undef PROCADR8_void_params
#undef PROCADR9_void_params
#undef PROCADR10_void_params
#undef PROCADR11_void_params
#undef PROCADR12_void_params
#undef PROCADR13_void_params
#undef PROCADR14_void_params
#undef PROCADR15_void_params

#undef GETPROCADR0
#undef GETPROCADR1
#undef GETPROCADR2
#undef GETPROCADR3
#undef GETPROCADR4
#undef GETPROCADR5
#undef GETPROCADR6
#undef GETPROCADR7
#undef GETPROCADR8
#undef GETPROCADR9
#undef GETPROCADR10
#undef GETPROCADR11
#undef GETPROCADR12
#undef GETPROCADR13
#undef GETPROCADR14
#undef GETPROCADR15

#undef GETPROCADR0_void
#undef GETPROCADR1_void
#undef GETPROCADR2_void
#undef GETPROCADR3_void
#undef GETPROCADR4_void
#undef GETPROCADR5_void
#undef GETPROCADR6_void
#undef GETPROCADR7_void
#undef GETPROCADR8_void
#undef GETPROCADR9_void
#undef GETPROCADR10_void
#undef GETPROCADR11_void
#undef GETPROCADR12_void
#undef GETPROCADR13_void
#undef GETPROCADR14_void
#undef GETPROCADR15_void

#undef GETPROCADR1_params
#undef GETPROCADR2_params
#undef GETPROCADR3_params
#undef GETPROCADR4_params
#undef GETPROCADR5_params
#undef GETPROCADR6_params
#undef GETPROCADR7_params
#undef GETPROCADR8_params
#undef GETPROCADR9_params
#undef GETPROCADR10_params
#undef GETPROCADR11_params
#undef GETPROCADR12_params
#undef GETPROCADR13_params
#undef GETPROCADR14_params
#undef GETPROCADR15_params

#undef GETPROCADR1_void_params
#undef GETPROCADR2_void_params
#undef GETPROCADR3_void_params
#undef GETPROCADR4_void_params
#undef GETPROCADR5_void_params
#undef GETPROCADR6_void_params
#undef GETPROCADR7_void_params
#undef GETPROCADR8_void_params
#undef GETPROCADR9_void_params
#undef GETPROCADR10_void_params
#undef GETPROCADR11_void_params
#undef GETPROCADR12_void_params
#undef GETPROCADR13_void_params
#undef GETPROCADR14_void_params
#undef GETPROCADR15_void_params

#ifndef PROC_STDCALL
  #define PROC_STDCALL  __stdcall
#endif

#if defined(DEF_FUNC_TYPEDEF)
  // generování typedef
  #if DEBUG_PREPROC>2
    #pragma message("DEF_FUNC_TYPEDEF")
  #endif
  #undef DEF_FUNC_TYPEDEF
  #define PROCADR0(n,r,cn)                                                                typedef r (PROC_STDCALL* fce##cn)();
  #define PROCADR1(n,r,cn,t1,p1)                                                          typedef r (PROC_STDCALL* fce##cn)(t1 p1);
  #define PROCADR2(n,r,cn,t1,p1,t2,p2)                                                    typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2);
  #define PROCADR3(n,r,cn,t1,p1,t2,p2,t3,p3)                                              typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3);
  #define PROCADR4(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                        typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4);
  #define PROCADR5(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                                  typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5);
  #define PROCADR6(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                            typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6);
  #define PROCADR7(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                      typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7);
  #define PROCADR8(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)                typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8);
  #define PROCADR9(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)          typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9);
  #define PROCADR10(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10)                                          typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9,t10 p10);
  #define PROCADR11(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11)                                  typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9,t10 p10,t11 p11);
  #define PROCADR12(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12)                          typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9,t10 p10,t11 p11,t12 p12);
  #define PROCADR13(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13)                  typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9,t10 p10,t11 p11,t12 p12,t13 p13);
  #define PROCADR14(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13,t14,p14)          typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9,t10 p10,t11 p11,t12 p12,t13 p13,t14 p14);
  #define PROCADR15(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13,t14,p14,t15,p15)  typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9,t10 p10,t11 p11,t12 p12,t13 p13,t14 p14,t15 p15);

  #define PROCADR0_void(n,cn)                                                             typedef void (PROC_STDCALL* fce##cn)();
  #define PROCADR1_void(n,cn,t1,p1)                                                       typedef void (PROC_STDCALL* fce##cn)(t1 p1);
  #define PROCADR2_void(n,cn,t1,p1,t2,p2)                                                 typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2);
  #define PROCADR3_void(n,cn,t1,p1,t2,p2,t3,p3)                                           typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3);
  #define PROCADR4_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                     typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4);
  #define PROCADR5_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                               typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5);
  #define PROCADR6_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                         typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6);
  #define PROCADR7_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                   typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7);
  #define PROCADR8_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)             typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8);
  #define PROCADR9_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)       typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9);
  #define PROCADR10_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10)                                          typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9,t10 p10);
  #define PROCADR11_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11)                                  typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9,t10 p10,t11 p11);
  #define PROCADR12_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12)                          typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9,t10 p10,t11 p11,t12 p12);
  #define PROCADR13_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13)                  typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9,t10 p10,t11 p11,t12 p12,t13 p13);
  #define PROCADR14_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13,t14,p14)          typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9,t10 p10,t11 p11,t12 p12,t13 p13,t14 p14);
  #define PROCADR15_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13,t14,p14,t15,p15)  typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9,t10 p10,t11 p11,t12 p12,t13 p13,t14 p14,t15 p15);

  #define PROCADR1_params(n,r,cn,t1,p1)                                                   typedef r (PROC_STDCALL* fce##cn)(t1 p1,...);
  #define PROCADR2_params(n,r,cn,t1,p1,t2,p2)                                             typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,...);
  #define PROCADR3_params(n,r,cn,t1,p1,t2,p2,t3,p3)                                       typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,...);
  #define PROCADR4_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                 typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,...);
  #define PROCADR5_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                           typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,...);
  #define PROCADR6_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                     typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,...);
  #define PROCADR7_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)               typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,...);
  #define PROCADR8_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)         typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,...);
  #define PROCADR9_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)   typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9,...);

  #define PROCADR1_void_params(n,cn,t1,p1)                                                      typedef void (PROC_STDCALL* fce##cn)(t1 p1,...);
  #define PROCADR2_void_params(n,cn,t1,p1,t2,p2)                                                typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,...);
  #define PROCADR3_void_params(n,cn,t1,p1,t2,p2,t3,p3)                                          typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,...);
  #define PROCADR4_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                    typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,...);
  #define PROCADR5_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                              typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,...);
  #define PROCADR6_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                        typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,...);
  #define PROCADR7_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                  typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,...);
  #define PROCADR8_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)            typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,...);
  #define PROCADR9_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)      typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9,...);

  #define GETPROCADR0(n,r,cn)                                                                typedef r (PROC_STDCALL* fce##cn)();
  #define GETPROCADR1(n,r,cn,t1,p1)                                                          typedef r (PROC_STDCALL* fce##cn)(t1 p1);
  #define GETPROCADR2(n,r,cn,t1,p1,t2,p2)                                                    typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2);
  #define GETPROCADR3(n,r,cn,t1,p1,t2,p2,t3,p3)                                              typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3);
  #define GETPROCADR4(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                        typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4);
  #define GETPROCADR5(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                                  typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5);
  #define GETPROCADR6(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                            typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6);
  #define GETPROCADR7(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                      typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7);
  #define GETPROCADR8(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)                typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8);
  #define GETPROCADR9(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)          typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9);

  #define GETPROCADR0_void(n,cn)                                                             typedef void (PROC_STDCALL* fce##cn)();
  #define GETPROCADR1_void(n,cn,t1,p1)                                                       typedef void (PROC_STDCALL* fce##cn)(t1 p1);
  #define GETPROCADR2_void(n,cn,t1,p1,t2,p2)                                                 typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2);
  #define GETPROCADR3_void(n,cn,t1,p1,t2,p2,t3,p3)                                           typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3);
  #define GETPROCADR4_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                     typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4);
  #define GETPROCADR5_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                               typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5);
  #define GETPROCADR6_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                         typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6);
  #define GETPROCADR7_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                   typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7);
  #define GETPROCADR8_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)             typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8);
  #define GETPROCADR9_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)       typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9);

  #define GETPROCADR1_params(n,r,cn,t1,p1)                                                   typedef r (PROC_STDCALL* fce##cn)(t1 p1,...);
  #define GETPROCADR2_params(n,r,cn,t1,p1,t2,p2)                                             typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,...);
  #define GETPROCADR3_params(n,r,cn,t1,p1,t2,p2,t3,p3)                                       typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,...);
  #define GETPROCADR4_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                 typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,...);
  #define GETPROCADR5_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                           typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,...);
  #define GETPROCADR6_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                     typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,...);
  #define GETPROCADR7_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)               typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,...);
  #define GETPROCADR8_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)         typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,...);
  #define GETPROCADR9_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)   typedef r (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9,...);

  #define GETPROCADR1_void_params(n,cn,t1,p1)                                                      typedef void (PROC_STDCALL* fce##cn)(t1 p1,...);
  #define GETPROCADR2_void_params(n,cn,t1,p1,t2,p2)                                                typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,...);
  #define GETPROCADR3_void_params(n,cn,t1,p1,t2,p2,t3,p3)                                          typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,...);
  #define GETPROCADR4_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                    typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,...);
  #define GETPROCADR5_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                              typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,...);
  #define GETPROCADR6_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                        typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,...);
  #define GETPROCADR7_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                  typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,...);
  #define GETPROCADR8_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)            typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,...);
  #define GETPROCADR9_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)      typedef void (PROC_STDCALL* fce##cn)(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9,...);

#elif defined(DEF_FUNC_VARIABLE)
  // generování promìnné (funkèního pointeru) pro každý typedef
  #if DEBUG_PREPROC>2
    #pragma message("DEF_FUNC_VARIABLE")
  #endif
  #undef DEF_FUNC_VARIABLE
  #define PROCADR0(n,r,cn)                                                                fce##cn call##cn;
  #define PROCADR1(n,r,cn,t1,p1)                                                          fce##cn call##cn;
  #define PROCADR2(n,r,cn,t1,p1,t2,p2)                                                    fce##cn call##cn;
  #define PROCADR3(n,r,cn,t1,p1,t2,p2,t3,p3)                                              fce##cn call##cn;
  #define PROCADR4(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                        fce##cn call##cn;
  #define PROCADR5(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                                  fce##cn call##cn;
  #define PROCADR6(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                            fce##cn call##cn;
  #define PROCADR7(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                      fce##cn call##cn;
  #define PROCADR8(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)                fce##cn call##cn;
  #define PROCADR9(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)          fce##cn call##cn;
  #define PROCADR10(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10)                                          fce##cn call##cn;
  #define PROCADR11(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11)                                  fce##cn call##cn;
  #define PROCADR12(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12)                          fce##cn call##cn;
  #define PROCADR13(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13)                  fce##cn call##cn;
  #define PROCADR14(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13,t14,p14)          fce##cn call##cn;
  #define PROCADR15(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13,t14,p14,t15,p15)  fce##cn call##cn;

  #define PROCADR0_void(n,cn)                                                             fce##cn call##cn;
  #define PROCADR1_void(n,cn,t1,p1)                                                       fce##cn call##cn;
  #define PROCADR2_void(n,cn,t1,p1,t2,p2)                                                 fce##cn call##cn;
  #define PROCADR3_void(n,cn,t1,p1,t2,p2,t3,p3)                                           fce##cn call##cn;
  #define PROCADR4_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                     fce##cn call##cn;
  #define PROCADR5_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                               fce##cn call##cn;
  #define PROCADR6_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                         fce##cn call##cn;
  #define PROCADR7_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                   fce##cn call##cn;
  #define PROCADR8_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)             fce##cn call##cn;
  #define PROCADR9_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)       fce##cn call##cn;
  #define PROCADR10_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10)                                          fce##cn call##cn;
  #define PROCADR11_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11)                                  fce##cn call##cn;
  #define PROCADR12_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12)                          fce##cn call##cn;
  #define PROCADR13_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13)                  fce##cn call##cn;
  #define PROCADR14_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13,t14,p14)          fce##cn call##cn;
  #define PROCADR15_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13,t14,p14,t15,p15)  fce##cn call##cn;

  #define PROCADR1_params(n,r,cn,t1,p1)                                                   fce##cn call##cn;
  #define PROCADR2_params(n,r,cn,t1,p1,t2,p2)                                             fce##cn call##cn;
  #define PROCADR3_params(n,r,cn,t1,p1,t2,p2,t3,p3)                                       fce##cn call##cn;
  #define PROCADR4_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                 fce##cn call##cn;
  #define PROCADR5_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                           fce##cn call##cn;
  #define PROCADR6_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                     fce##cn call##cn;
  #define PROCADR7_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)               fce##cn call##cn;
  #define PROCADR8_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)         fce##cn call##cn;
  #define PROCADR9_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)   fce##cn call##cn;

  #define PROCADR1_void_params(n,cn,t1,p1)                                                      fce##cn call##cn;
  #define PROCADR2_void_params(n,cn,t1,p1,t2,p2)                                                fce##cn call##cn;
  #define PROCADR3_void_params(n,cn,t1,p1,t2,p2,t3,p3)                                          fce##cn call##cn;
  #define PROCADR4_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                    fce##cn call##cn;
  #define PROCADR5_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                              fce##cn call##cn;
  #define PROCADR6_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                        fce##cn call##cn;
  #define PROCADR7_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                  fce##cn call##cn;
  #define PROCADR8_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)            fce##cn call##cn;
  #define PROCADR9_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)      fce##cn call##cn;

  #define GETPROCADR0(n,r,cn)                                                                fce##cn call##cn;
  #define GETPROCADR1(n,r,cn,t1,p1)                                                          fce##cn call##cn;
  #define GETPROCADR2(n,r,cn,t1,p1,t2,p2)                                                    fce##cn call##cn;
  #define GETPROCADR3(n,r,cn,t1,p1,t2,p2,t3,p3)                                              fce##cn call##cn;
  #define GETPROCADR4(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                        fce##cn call##cn;
  #define GETPROCADR5(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                                  fce##cn call##cn;
  #define GETPROCADR6(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                            fce##cn call##cn;
  #define GETPROCADR7(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                      fce##cn call##cn;
  #define GETPROCADR8(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)                fce##cn call##cn;
  #define GETPROCADR9(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)          fce##cn call##cn;

  #define GETPROCADR0_void(n,cn)                                                             fce##cn call##cn;
  #define GETPROCADR1_void(n,cn,t1,p1)                                                       fce##cn call##cn;
  #define GETPROCADR2_void(n,cn,t1,p1,t2,p2)                                                 fce##cn call##cn;
  #define GETPROCADR3_void(n,cn,t1,p1,t2,p2,t3,p3)                                           fce##cn call##cn;
  #define GETPROCADR4_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                     fce##cn call##cn;
  #define GETPROCADR5_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                               fce##cn call##cn;
  #define GETPROCADR6_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                         fce##cn call##cn;
  #define GETPROCADR7_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                   fce##cn call##cn;
  #define GETPROCADR8_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)             fce##cn call##cn;
  #define GETPROCADR9_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)       fce##cn call##cn;

  #define GETPROCADR1_params(n,r,cn,t1,p1)                                                   fce##cn call##cn;
  #define GETPROCADR2_params(n,r,cn,t1,p1,t2,p2)                                             fce##cn call##cn;
  #define GETPROCADR3_params(n,r,cn,t1,p1,t2,p2,t3,p3)                                       fce##cn call##cn;
  #define GETPROCADR4_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                 fce##cn call##cn;
  #define GETPROCADR5_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                           fce##cn call##cn;
  #define GETPROCADR6_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                     fce##cn call##cn;
  #define GETPROCADR7_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)               fce##cn call##cn;
  #define GETPROCADR8_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)         fce##cn call##cn;
  #define GETPROCADR9_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)   fce##cn call##cn;

  #define GETPROCADR1_void_params(n,cn,t1,p1)                                                      fce##cn call##cn;
  #define GETPROCADR2_void_params(n,cn,t1,p1,t2,p2)                                                fce##cn call##cn;
  #define GETPROCADR3_void_params(n,cn,t1,p1,t2,p2,t3,p3)                                          fce##cn call##cn;
  #define GETPROCADR4_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                    fce##cn call##cn;
  #define GETPROCADR5_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                              fce##cn call##cn;
  #define GETPROCADR6_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                        fce##cn call##cn;
  #define GETPROCADR7_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                  fce##cn call##cn;
  #define GETPROCADR8_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)            fce##cn call##cn;
  #define GETPROCADR9_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)      fce##cn call##cn;

#elif defined(DEF_FUNC_VERIFY)
  // generování ovìøovacího pøíkazu pro promìnné na NULL
  #if DEBUG_PREPROC>2
    #pragma message("DEF_FUNC_VERIFY")
  #endif
  #undef DEF_FUNC_VERIFY
  #define PROCADR0(n,r,cn)                                                                if(!call##cn) ok=false;
  #define PROCADR1(n,r,cn,t1,p1)                                                          if(!call##cn) ok=false;
  #define PROCADR2(n,r,cn,t1,p1,t2,p2)                                                    if(!call##cn) ok=false;
  #define PROCADR3(n,r,cn,t1,p1,t2,p2,t3,p3)                                              if(!call##cn) ok=false;
  #define PROCADR4(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                        if(!call##cn) ok=false;
  #define PROCADR5(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                                  if(!call##cn) ok=false;
  #define PROCADR6(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                            if(!call##cn) ok=false;
  #define PROCADR7(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                      if(!call##cn) ok=false;
  #define PROCADR8(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)                if(!call##cn) ok=false;
  #define PROCADR9(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)          if(!call##cn) ok=false;
  #define PROCADR10(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10)                                          if(!call##cn) ok=false;
  #define PROCADR11(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11)                                  if(!call##cn) ok=false;
  #define PROCADR12(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12)                          if(!call##cn) ok=false;
  #define PROCADR13(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13)                  if(!call##cn) ok=false;
  #define PROCADR14(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13,t14,p14)          if(!call##cn) ok=false;
  #define PROCADR15(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13,t14,p14,t15,p15)  if(!call##cn) ok=false;

  #define PROCADR0_void(n,cn)                                                             if(!call##cn) ok=false;
  #define PROCADR1_void(n,cn,t1,p1)                                                       if(!call##cn) ok=false;
  #define PROCADR2_void(n,cn,t1,p1,t2,p2)                                                 if(!call##cn) ok=false;
  #define PROCADR3_void(n,cn,t1,p1,t2,p2,t3,p3)                                           if(!call##cn) ok=false;
  #define PROCADR4_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                     if(!call##cn) ok=false;
  #define PROCADR5_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                               if(!call##cn) ok=false;
  #define PROCADR6_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                         if(!call##cn) ok=false;
  #define PROCADR7_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                   if(!call##cn) ok=false;
  #define PROCADR8_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)             if(!call##cn) ok=false;
  #define PROCADR9_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)       if(!call##cn) ok=false;
  #define PROCADR10_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10)                                          if(!call##cn) ok=false;
  #define PROCADR11_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11)                                  if(!call##cn) ok=false;
  #define PROCADR12_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12)                          if(!call##cn) ok=false;
  #define PROCADR13_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13)                  if(!call##cn) ok=false;
  #define PROCADR14_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13,t14,p14)          if(!call##cn) ok=false;
  #define PROCADR15_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13,t14,p14,t15,p15)  if(!call##cn) ok=false;

  #define PROCADR1_params(n,r,cn,t1,p1)                                                   if(!call##cn) ok=false;
  #define PROCADR2_params(n,r,cn,t1,p1,t2,p2)                                             if(!call##cn) ok=false;
  #define PROCADR3_params(n,r,cn,t1,p1,t2,p2,t3,p3)                                       if(!call##cn) ok=false;
  #define PROCADR4_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                 if(!call##cn) ok=false;
  #define PROCADR5_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                           if(!call##cn) ok=false;
  #define PROCADR6_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                     if(!call##cn) ok=false;
  #define PROCADR7_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)               if(!call##cn) ok=false;
  #define PROCADR8_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)         if(!call##cn) ok=false;
  #define PROCADR9_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)   if(!call##cn) ok=false;

  #define PROCADR1_void_params(n,cn,t1,p1)                                                      if(!call##cn) ok=false;
  #define PROCADR2_void_params(n,cn,t1,p1,t2,p2)                                                if(!call##cn) ok=false;
  #define PROCADR3_void_params(n,cn,t1,p1,t2,p2,t3,p3)                                          if(!call##cn) ok=false;
  #define PROCADR4_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                    if(!call##cn) ok=false;
  #define PROCADR5_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                              if(!call##cn) ok=false;
  #define PROCADR6_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                        if(!call##cn) ok=false;
  #define PROCADR7_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                  if(!call##cn) ok=false;
  #define PROCADR8_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)            if(!call##cn) ok=false;
  #define PROCADR9_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)      if(!call##cn) ok=false;
#elif defined(DEF_FUNC_VERIFY_MSG)
  // generování ovìøovacího pøíkazu pro promìnné na NULL
  #if DEBUG_PREPROC>2
    #pragma message("DEF_FUNC_VERIFY_MSG")
  #endif
  #undef DEF_FUNC_VERIFY_MSG
  #define PROCADR0(n,r,cn)                                                                if(!call##cn) o << n << "\n";
  #define PROCADR1(n,r,cn,t1,p1)                                                          if(!call##cn) o << n << "\n";
  #define PROCADR2(n,r,cn,t1,p1,t2,p2)                                                    if(!call##cn) o << n << "\n";
  #define PROCADR3(n,r,cn,t1,p1,t2,p2,t3,p3)                                              if(!call##cn) o << n << "\n";
  #define PROCADR4(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                        if(!call##cn) o << n << "\n";
  #define PROCADR5(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                                  if(!call##cn) o << n << "\n";
  #define PROCADR6(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                            if(!call##cn) o << n << "\n";
  #define PROCADR7(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                      if(!call##cn) o << n << "\n";
  #define PROCADR8(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)                if(!call##cn) o << n << "\n";
  #define PROCADR9(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)          if(!call##cn) o << n << "\n";
  #define PROCADR10(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10)                                          if(!call##cn) o << n << "\n";
  #define PROCADR11(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11)                                  if(!call##cn) o << n << "\n";
  #define PROCADR12(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12)                          if(!call##cn) o << n << "\n";
  #define PROCADR13(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13)                  if(!call##cn) o << n << "\n";
  #define PROCADR14(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13,t14,p14)          if(!call##cn) o << n << "\n";
  #define PROCADR15(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13,t14,p14,t15,p15)  if(!call##cn) o << n << "\n";

  #define PROCADR0_void(n,cn)                                                             if(!call##cn) o << n << "\n";
  #define PROCADR1_void(n,cn,t1,p1)                                                       if(!call##cn) o << n << "\n";
  #define PROCADR2_void(n,cn,t1,p1,t2,p2)                                                 if(!call##cn) o << n << "\n";
  #define PROCADR3_void(n,cn,t1,p1,t2,p2,t3,p3)                                           if(!call##cn) o << n << "\n";
  #define PROCADR4_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                     if(!call##cn) o << n << "\n";
  #define PROCADR5_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                               if(!call##cn) o << n << "\n";
  #define PROCADR6_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                         if(!call##cn) o << n << "\n";
  #define PROCADR7_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                   if(!call##cn) o << n << "\n";
  #define PROCADR8_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)             if(!call##cn) o << n << "\n";
  #define PROCADR9_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)       if(!call##cn) o << n << "\n";
  #define PROCADR10_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10)                                          if(!call##cn) o << n << "\n";
  #define PROCADR11_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11)                                  if(!call##cn) o << n << "\n";
  #define PROCADR12_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12)                          if(!call##cn) o << n << "\n";
  #define PROCADR13_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13)                  if(!call##cn) o << n << "\n";
  #define PROCADR14_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13,t14,p14)          if(!call##cn) o << n << "\n";
  #define PROCADR15_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13,t14,p14,t15,p15)  if(!call##cn) o << n << "\n";

  #define PROCADR1_params(n,r,cn,t1,p1)                                                   if(!call##cn) o << n << "\n";
  #define PROCADR2_params(n,r,cn,t1,p1,t2,p2)                                             if(!call##cn) o << n << "\n";
  #define PROCADR3_params(n,r,cn,t1,p1,t2,p2,t3,p3)                                       if(!call##cn) o << n << "\n";
  #define PROCADR4_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                 if(!call##cn) o << n << "\n";
  #define PROCADR5_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                           if(!call##cn) o << n << "\n";
  #define PROCADR6_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                     if(!call##cn) o << n << "\n";
  #define PROCADR7_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)               if(!call##cn) o << n << "\n";
  #define PROCADR8_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)         if(!call##cn) o << n << "\n";
  #define PROCADR9_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)   if(!call##cn) o << n << "\n";

  #define PROCADR1_void_params(n,cn,t1,p1)                                                      if(!call##cn) o << n << "\n";
  #define PROCADR2_void_params(n,cn,t1,p1,t2,p2)                                                if(!call##cn) o << n << "\n";
  #define PROCADR3_void_params(n,cn,t1,p1,t2,p2,t3,p3)                                          if(!call##cn) o << n << "\n";
  #define PROCADR4_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                    if(!call##cn) o << n << "\n";
  #define PROCADR5_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                              if(!call##cn) o << n << "\n";
  #define PROCADR6_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                        if(!call##cn) o << n << "\n";
  #define PROCADR7_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                  if(!call##cn) o << n << "\n";
  #define PROCADR8_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)            if(!call##cn) o << n << "\n";
  #define PROCADR9_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)      if(!call##cn) o << n << "\n";
#elif defined(DEF_FUNC_VERIFY_DECL)
  // generování ovìøovacího pøíkazu pro promìnné na NULL
  #if DEBUG_PREPROC>2
    #pragma message("DEF_FUNC_VERIFY_DECL")
  #endif
  #undef DEF_FUNC_VERIFY_DECL

  #define PROCADR0(n,r,cn)                                                                bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR1(n,r,cn,t1,p1)                                                          bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR2(n,r,cn,t1,p1,t2,p2)                                                    bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR3(n,r,cn,t1,p1,t2,p2,t3,p3)                                              bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR4(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                        bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR5(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                                  bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR6(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                            bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR7(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                      bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR8(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)                bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR9(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)          bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR10(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10)                                          bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR11(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11)                                  bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR12(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12)                          bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR13(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13)                  bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR14(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13,t14,p14)          bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR15(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13,t14,p14,t15,p15)  bool Has##cn() const {return call##cn?true:false;}

  #define PROCADR0_void(n,cn)                                                             bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR1_void(n,cn,t1,p1)                                                       bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR2_void(n,cn,t1,p1,t2,p2)                                                 bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR3_void(n,cn,t1,p1,t2,p2,t3,p3)                                           bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR4_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                     bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR5_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                               bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR6_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                         bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR7_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                   bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR8_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)             bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR9_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)       bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR10_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10)                                          bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR11_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11)                                  bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR12_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12)                          bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR13_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13)                  bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR14_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13,t14,p14)          bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR15_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13,t14,p14,t15,p15)  bool Has##cn() const {return call##cn?true:false;}

  #define PROCADR1_params(n,r,cn,t1,p1)                                                   bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR2_params(n,r,cn,t1,p1,t2,p2)                                             bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR3_params(n,r,cn,t1,p1,t2,p2,t3,p3)                                       bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR4_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                 bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR5_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                           bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR6_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                     bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR7_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)               bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR8_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)         bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR9_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)   bool Has##cn() const {return call##cn?true:false;}

  #define PROCADR1_void_params(n,cn,t1,p1)                                                      bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR2_void_params(n,cn,t1,p1,t2,p2)                                                bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR3_void_params(n,cn,t1,p1,t2,p2,t3,p3)                                          bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR4_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                    bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR5_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                              bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR6_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                        bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR7_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                  bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR8_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)            bool Has##cn() const {return call##cn?true:false;}
  #define PROCADR9_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)      bool Has##cn() const {return call##cn?true:false;}

  #define GETPROCADR0(n,r,cn)                                                                bool Has##cn() const {return call##cn?true:false;}
  #define GETPROCADR1(n,r,cn,t1,p1)                                                          bool Has##cn() const {return call##cn?true:false;}
  #define GETPROCADR2(n,r,cn,t1,p1,t2,p2)                                                    bool Has##cn() const {return call##cn?true:false;}
  #define GETPROCADR3(n,r,cn,t1,p1,t2,p2,t3,p3)                                              bool Has##cn() const {return call##cn?true:false;}
  #define GETPROCADR4(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                        bool Has##cn() const {return call##cn?true:false;}
  #define GETPROCADR5(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                                  bool Has##cn() const {return call##cn?true:false;}
  #define GETPROCADR6(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                            bool Has##cn() const {return call##cn?true:false;}
  #define GETPROCADR7(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                      bool Has##cn() const {return call##cn?true:false;}
  #define GETPROCADR8(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)                bool Has##cn() const {return call##cn?true:false;}
  #define GETPROCADR9(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)          bool Has##cn() const {return call##cn?true:false;}

  #define GETPROCADR0_void(n,cn)                                                             bool Has##cn() const {return call##cn?true:false;}
  #define GETPROCADR1_void(n,cn,t1,p1)                                                       bool Has##cn() const {return call##cn?true:false;}
  #define GETPROCADR2_void(n,cn,t1,p1,t2,p2)                                                 bool Has##cn() const {return call##cn?true:false;}
  #define GETPROCADR3_void(n,cn,t1,p1,t2,p2,t3,p3)                                           bool Has##cn() const {return call##cn?true:false;}
  #define GETPROCADR4_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                     bool Has##cn() const {return call##cn?true:false;}
  #define GETPROCADR5_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                               bool Has##cn() const {return call##cn?true:false;}
  #define GETPROCADR6_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                         bool Has##cn() const {return call##cn?true:false;}
  #define GETPROCADR7_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                   bool Has##cn() const {return call##cn?true:false;}
  #define GETPROCADR8_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)             bool Has##cn() const {return call##cn?true:false;}
  #define GETPROCADR9_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)       bool Has##cn() const {return call##cn?true:false;}

  #define GETPROCADR1_params(n,r,cn,t1,p1)                                                   bool Has##cn() const {return call##cn?true:false;}
  #define GETPROCADR2_params(n,r,cn,t1,p1,t2,p2)                                             bool Has##cn() const {return call##cn?true:false;}
  #define GETPROCADR3_params(n,r,cn,t1,p1,t2,p2,t3,p3)                                       bool Has##cn() const {return call##cn?true:false;}
  #define GETPROCADR4_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                 bool Has##cn() const {return call##cn?true:false;}
  #define GETPROCADR5_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                           bool Has##cn() const {return call##cn?true:false;}
  #define GETPROCADR6_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                     bool Has##cn() const {return call##cn?true:false;}
  #define GETPROCADR7_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)               bool Has##cn() const {return call##cn?true:false;}
  #define GETPROCADR8_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)         bool Has##cn() const {return call##cn?true:false;}
  #define GETPROCADR9_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)   bool Has##cn() const {return call##cn?true:false;}

  #define GETPROCADR1_void_params(n,cn,t1,p1)                                                      bool Has##cn() const {return call##cn?true:false;}
  #define GETPROCADR2_void_params(n,cn,t1,p1,t2,p2)                                                bool Has##cn() const {return call##cn?true:false;}
  #define GETPROCADR3_void_params(n,cn,t1,p1,t2,p2,t3,p3)                                          bool Has##cn() const {return call##cn?true:false;}
  #define GETPROCADR4_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                    bool Has##cn() const {return call##cn?true:false;}
  #define GETPROCADR5_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                              bool Has##cn() const {return call##cn?true:false;}
  #define GETPROCADR6_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                        bool Has##cn() const {return call##cn?true:false;}
  #define GETPROCADR7_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                  bool Has##cn() const {return call##cn?true:false;}
  #define GETPROCADR8_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)            bool Has##cn() const {return call##cn?true:false;}
  #define GETPROCADR9_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)      bool Has##cn() const {return call##cn?true:false;}
#elif defined(DEF_FUNC_CALL)
  // generování funkce pro promìnnou (funkèní pointer) 
  #if DEBUG_PREPROC>2
    #pragma message("DEF_FUNC_CALL")
  #endif
  #undef DEF_FUNC_CALL
  #define PROCADR0(n,r,cn)                                                                r cn() {return call##cn();}
  #define PROCADR1(n,r,cn,t1,p1)                                                          r cn(t1 p1) {return call##cn(p1);}
  #define PROCADR2(n,r,cn,t1,p1,t2,p2)                                                    r cn(t1 p1,t2 p2) {return call##cn(p1,p2);}
  #define PROCADR3(n,r,cn,t1,p1,t2,p2,t3,p3)                                              r cn(t1 p1,t2 p2,t3 p3) {return call##cn(p1,p2,p3);}
  #define PROCADR4(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                        r cn(t1 p1,t2 p2,t3 p3,t4 p4) {return call##cn(p1,p2,p3,p4);}
  #define PROCADR5(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                                  r cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5) {return call##cn(p1,p2,p3,p4,p5);}
  #define PROCADR6(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                            r cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6) {return call##cn(p1,p2,p3,p4,p5,p6);}
  #define PROCADR7(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                      r cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7) {return call##cn(p1,p2,p3,p4,p5,p6,p7);}
  #define PROCADR8(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)                r cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8) {return call##cn(p1,p2,p3,p4,p5,p6,p7,p8);}
  #define PROCADR9(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)          r cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9) {return call##cn(p1,p2,p3,p4,p5,p6,p7,p8,p9);}
  #define PROCADR10(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10)                                          r cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9,t10 p10) {return call##cn(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10);}
  #define PROCADR11(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11)                                  r cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9,t10 p10,t11 p11) {return call##cn(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11);}
  #define PROCADR12(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12)                          r cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9,t10 p10,t11 p11,t12 p12) {return call##cn(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12);}
  #define PROCADR13(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13)                  r cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9,t10 p10,t11 p11,t12 p12,t13 p13) {return call##cn(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13);}
  #define PROCADR14(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13,t14,p14)          r cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9,t10 p10,t11 p11,t12 p12,t13 p13,t14 p14) {return call##cn(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14);}
  #define PROCADR15(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13,t14,p14,t15,p15)  r cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9,t10 p10,t11 p11,t12 p12,t13 p13,t14 p14,t15 p15) {return call##cn(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15);}

  #define PROCADR0_void(n,cn)                                                             void cn() {call##cn();}
  #define PROCADR1_void(n,cn,t1,p1)                                                       void cn(t1 p1) {call##cn(p1);}
  #define PROCADR2_void(n,cn,t1,p1,t2,p2)                                                 void cn(t1 p1,t2 p2) {call##cn(p1,p2);}
  #define PROCADR3_void(n,cn,t1,p1,t2,p2,t3,p3)                                           void cn(t1 p1,t2 p2,t3 p3) {call##cn(p1,p2,p3);}
  #define PROCADR4_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                     void cn(t1 p1,t2 p2,t3 p3,t4 p4) {call##cn(p1,p2,p3,p4);}
  #define PROCADR5_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                               void cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5) {call##cn(p1,p2,p3,p4,p5);}
  #define PROCADR6_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                         void cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6) {call##cn(p1,p2,p3,p4,p5,p6);}
  #define PROCADR7_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                   void cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7) {call##cn(p1,p2,p3,p4,p5,p6,p7);}
  #define PROCADR8_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)             void cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8) {call##cn(p1,p2,p3,p4,p5,p6,p7,p8);}
  #define PROCADR9_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)       void cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9) {call##cn(p1,p2,p3,p4,p5,p6,p7,p8,p9);}
  #define PROCADR10_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10)                                          void cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9,t10 p10) {return call##cn(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10);}
  #define PROCADR11_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11)                                  void cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9,t10 p10,t11 p11) {return call##cn(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11);}
  #define PROCADR12_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12)                          void cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9,t10 p10,t11 p11,t12 p12) {return call##cn(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12);}
  #define PROCADR13_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13)                  void cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9,t10 p10,t11 p11,t12 p12,t13 p13) {return call##cn(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13);}
  #define PROCADR14_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13,t14,p14)          void cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9,t11 p11,t12 p12,t13 p13,t14 p14) {return call##cn(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14);}
  #define PROCADR15_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13,t14,p14,t15,p15)  void cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9,t10 p10,t11 p11,t12 p12,t13 p13,t14 p14,t15 p15) {return call##cn(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15);}

  #define PROCADR1_params(n,r,cn,t1,p1)                                                   r cn(t1 p1,...) {va_list params;va_start(params,p1);return call##cn(p1,params);}
  #define PROCADR2_params(n,r,cn,t1,p1,t2,p2)                                             r cn(t1 p1,t2 p2,...) {va_list params;va_start(params,p2);return call##cn(p1,p2,params);}
  #define PROCADR3_params(n,r,cn,t1,p1,t2,p2,t3,p3)                                       r cn(t1 p1,t2 p2,t3 p3,...) {va_list params;va_start(params,p3);return call##cn(p1,p2,p3,params);}
  #define PROCADR4_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                 r cn(t1 p1,t2 p2,t3 p3,t4 p4,...) {va_list params;va_start(params,p4);return call##cn(p1,p2,p3,p4,params);}
  #define PROCADR5_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                           r cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,...) {va_list params;va_start(params,p5);return call##cn(p1,p2,p3,p4,p5,params);}
  #define PROCADR6_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                     r cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,...) {va_list params;va_start(params,p6);return call##cn(p1,p2,p3,p4,p5,p6,params);}
  #define PROCADR7_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)               r cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,...) {va_list params;va_start(params,p7);return call##cn(p1,p2,p3,p4,p5,p6,p7,params);}
  #define PROCADR8_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)         r cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,...) {va_list params;va_start(params,p8);return call##cn(p1,p2,p3,p4,p5,p6,p7,p8,params);}
  #define PROCADR9_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)   r cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9,...) {va_list params;va_start(params,p9);return call##cn(p1,p2,p3,p4,p5,p6,p7,p8,p9,params);}
  
  #define PROCADR1_void_params(n,cn,t1,p1)                                                      void cn(t1 p1,...) {va_list params;va_start(params,p1);call##cn(p1,params);}
  #define PROCADR2_void_params(n,cn,t1,p1,t2,p2)                                                void cn(t1 p1,t2 p2,...) {va_list params;va_start(params,p2);call##cn(p1,p2,params);}
  #define PROCADR3_void_params(n,cn,t1,p1,t2,p2,t3,p3)                                          void cn(t1 p1,t2 p2,t3 p3,...) {va_list params;va_start(params,p3);call##cn(p1,p2,p3,params);}
  #define PROCADR4_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                    void cn(t1 p1,t2 p2,t3 p3,t4 p4,...) {va_list params;va_start(params,p4);call##cn(p1,p2,p3,p4,params);}
  #define PROCADR5_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                              void cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,...) {va_list params;va_start(params,p5);call##cn(p1,p2,p3,p4,p5,params);}
  #define PROCADR6_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                        void cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,...) {va_list params;va_start(params,p6);call##cn(p1,p2,p3,p4,p5,p6,params);}
  #define PROCADR7_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                  void cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,...) {va_list params;va_start(params,p7);call##cn(p1,p2,p3,p4,p5,p6,p7,params);}
  #define PROCADR8_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)            void cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,...) {va_list params;va_start(params,p8);call##cn(p1,p2,p3,p4,p5,p6,p7,p8,params);}
  #define PROCADR9_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)      void cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9,...) {va_list params;va_start(params,p9);call##cn(p1,p2,p3,p4,p5,p6,p7,p8,p9,params);}

  #define GETPROCADR0(n,r,cn)                                                                r cn() {return call##cn();}
  #define GETPROCADR1(n,r,cn,t1,p1)                                                          r cn(t1 p1) {return call##cn(p1);}
  #define GETPROCADR2(n,r,cn,t1,p1,t2,p2)                                                    r cn(t1 p1,t2 p2) {return call##cn(p1,p2);}
  #define GETPROCADR3(n,r,cn,t1,p1,t2,p2,t3,p3)                                              r cn(t1 p1,t2 p2,t3 p3) {return call##cn(p1,p2,p3);}
  #define GETPROCADR4(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                        r cn(t1 p1,t2 p2,t3 p3,t4 p4) {return call##cn(p1,p2,p3,p4);}
  #define GETPROCADR5(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                                  r cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5) {return call##cn(p1,p2,p3,p4,p5);}
  #define GETPROCADR6(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                            r cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6) {return call##cn(p1,p2,p3,p4,p5,p6);}
  #define GETPROCADR7(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                      r cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7) {return call##cn(p1,p2,p3,p4,p5,p6,p7);}
  #define GETPROCADR8(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)                r cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8) {return call##cn(p1,p2,p3,p4,p5,p6,p7,p8);}
  #define GETPROCADR9(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)          r cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9) {return call##cn(p1,p2,p3,p4,p5,p6,p7,p8,p9);}

  #define GETPROCADR0_void(n,cn)                                                             void cn() {call##cn();}
  #define GETPROCADR1_void(n,cn,t1,p1)                                                       void cn(t1 p1) {call##cn(p1);}
  #define GETPROCADR2_void(n,cn,t1,p1,t2,p2)                                                 void cn(t1 p1,t2 p2) {call##cn(p1,p2);}
  #define GETPROCADR3_void(n,cn,t1,p1,t2,p2,t3,p3)                                           void cn(t1 p1,t2 p2,t3 p3) {call##cn(p1,p2,p3);}
  #define GETPROCADR4_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                     void cn(t1 p1,t2 p2,t3 p3,t4 p4) {call##cn(p1,p2,p3,p4);}
  #define GETPROCADR5_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                               void cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5) {call##cn(p1,p2,p3,p4,p5);}
  #define GETPROCADR6_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                         void cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6) {call##cn(p1,p2,p3,p4,p5,p6);}
  #define GETPROCADR7_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                   void cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7) {call##cn(p1,p2,p3,p4,p5,p6,p7);}
  #define GETPROCADR8_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)             void cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8) {call##cn(p1,p2,p3,p4,p5,p6,p7,p8);}
  #define GETPROCADR9_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)       void cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9) {call##cn(p1,p2,p3,p4,p5,p6,p7,p8,p9);}

  #define GETPROCADR1_params(n,r,cn,t1,p1)                                                   r cn(t1 p1,...) {va_list params;va_start(params,p1);return call##cn(p1,params);}
  #define GETPROCADR2_params(n,r,cn,t1,p1,t2,p2)                                             r cn(t1 p1,t2 p2,...) {va_list params;va_start(params,p2);return call##cn(p1,p2,params);}
  #define GETPROCADR3_params(n,r,cn,t1,p1,t2,p2,t3,p3)                                       r cn(t1 p1,t2 p2,t3 p3,...) {va_list params;va_start(params,p3);return call##cn(p1,p2,p3,params);}
  #define GETPROCADR4_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                 r cn(t1 p1,t2 p2,t3 p3,t4 p4,...) {va_list params;va_start(params,p4);return call##cn(p1,p2,p3,p4,params);}
  #define GETPROCADR5_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                           r cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,...) {va_list params;va_start(params,p5);return call##cn(p1,p2,p3,p4,p5,params);}
  #define GETPROCADR6_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                     r cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,...) {va_list params;va_start(params,p6);return call##cn(p1,p2,p3,p4,p5,p6,params);}
  #define GETPROCADR7_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)               r cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,...) {va_list params;va_start(params,p7);return call##cn(p1,p2,p3,p4,p5,p6,p7,params);}
  #define GETPROCADR8_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)         r cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,...) {va_list params;va_start(params,p8);return call##cn(p1,p2,p3,p4,p5,p6,p7,p8,params);}
  #define GETPROCADR9_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)   r cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9,...) {va_list params;va_start(params,p9);return call##cn(p1,p2,p3,p4,p5,p6,p7,p8,p9,params);}
  
  #define GETPROCADR1_void_params(n,cn,t1,p1)                                                      void cn(t1 p1,...) {va_list params;va_start(params,p1);call##cn(p1,params);}
  #define GETPROCADR2_void_params(n,cn,t1,p1,t2,p2)                                                void cn(t1 p1,t2 p2,...) {va_list params;va_start(params,p2);call##cn(p1,p2,params);}
  #define GETPROCADR3_void_params(n,cn,t1,p1,t2,p2,t3,p3)                                          void cn(t1 p1,t2 p2,t3 p3,...) {va_list params;va_start(params,p3);call##cn(p1,p2,p3,params);}
  #define GETPROCADR4_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                    void cn(t1 p1,t2 p2,t3 p3,t4 p4,...) {va_list params;va_start(params,p4);call##cn(p1,p2,p3,p4,params);}
  #define GETPROCADR5_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                              void cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,...) {va_list params;va_start(params,p5);call##cn(p1,p2,p3,p4,p5,params);}
  #define GETPROCADR6_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                        void cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,...) {va_list params;va_start(params,p6);call##cn(p1,p2,p3,p4,p5,p6,params);}
  #define GETPROCADR7_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                  void cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,...) {va_list params;va_start(params,p7);call##cn(p1,p2,p3,p4,p5,p6,p7,params);}
  #define GETPROCADR8_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)            void cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,...) {va_list params;va_start(params,p8);call##cn(p1,p2,p3,p4,p5,p6,p7,p8,params);}
  #define GETPROCADR9_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)      void cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9,...) {va_list params;va_start(params,p9);call##cn(p1,p2,p3,p4,p5,p6,p7,p8,p9,params);}
#elif defined(DEF_FUNC_GETPROCADDRESS)
  // generování GetProcAddress pro promìnné (funkèní pointery)
  #if DEBUG_PREPROC>2
    #pragma message("DEF_FUNC_GETPROCADDRESS")
  #endif
  #undef DEF_FUNC_GETPROCADDRESS
  #define PROCADR0(n,r,cn)                                                                call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR1(n,r,cn,t1,p1)                                                          call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR2(n,r,cn,t1,p1,t2,p2)                                                    call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR3(n,r,cn,t1,p1,t2,p2,t3,p3)                                              call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR4(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                        call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR5(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                                  call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR6(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                            call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR7(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                      call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR8(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)                call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR9(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)          call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR10(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10)                                          call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR11(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11)                                  call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR12(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12)                          call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR13(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13)                  call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR14(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13,t14,p14)          call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR15(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13,t14,p14,t15,p15)  call##cn=(fce##cn)GetProcAddress(module,n);

  #define PROCADR0_void(n,cn)                                                             call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR1_void(n,cn,t1,p1)                                                       call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR2_void(n,cn,t1,p1,t2,p2)                                                 call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR3_void(n,cn,t1,p1,t2,p2,t3,p3)                                           call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR4_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                     call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR5_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                               call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR6_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                         call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR7_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                   call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR8_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)             call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR9_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)       call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR10_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10)                                          call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR11_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11)                                  call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR12_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12)                          call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR13_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13)                  fcall##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR14_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13,t14,p14)          call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR15_void(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9,t10,p10,t11,p11,t12,p12,t13,p13,t14,p14,t15,p15)  call##cn=(fce##cn)GetProcAddress(module,n);

  #define PROCADR1_params(n,r,cn,t1,p1)                                                   call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR2_params(n,r,cn,t1,p1,t2,p2)                                             call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR3_params(n,r,cn,t1,p1,t2,p2,t3,p3)                                       call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR4_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                 call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR5_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                           call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR6_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                     call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR7_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)               call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR8_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)         call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR9_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)   call##cn=(fce##cn)GetProcAddress(module,n);

  #define PROCADR1_void_params(n,cn,t1,p1)                                                      call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR2_void_params(n,cn,t1,p1,t2,p2)                                                call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR3_void_params(n,cn,t1,p1,t2,p2,t3,p3)                                          call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR4_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                    call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR5_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                              call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR6_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                        call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR7_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                  call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR8_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)            call##cn=(fce##cn)GetProcAddress(module,n);
  #define PROCADR9_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)      call##cn=(fce##cn)GetProcAddress(module,n);

  #define GETPROCADR0(n,r,cn)                                                                call##cn=(fce##cn)GetProcAddress(module,n);
  #define GETPROCADR1(n,r,cn,t1,p1)                                                          call##cn=(fce##cn)GetProcAddress(module,n);
  #define GETPROCADR2(n,r,cn,t1,p1,t2,p2)                                                    call##cn=(fce##cn)GetProcAddress(module,n);
  #define GETPROCADR3(n,r,cn,t1,p1,t2,p2,t3,p3)                                              call##cn=(fce##cn)GetProcAddress(module,n);
  #define GETPROCADR4(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                        call##cn=(fce##cn)GetProcAddress(module,n);
  #define GETPROCADR5(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                                  call##cn=(fce##cn)GetProcAddress(module,n);
  #define GETPROCADR6(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                            call##cn=(fce##cn)GetProcAddress(module,n);
  #define GETPROCADR7(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                      call##cn=(fce##cn)GetProcAddress(module,n);
  #define GETPROCADR8(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)                call##cn=(fce##cn)GetProcAddress(module,n);
  #define GETPROCADR9(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)          call##cn=(fce##cn)GetProcAddress(module,n);

  #define GETPROCADR0_void(n,cn)                                                             call##cn=(fce##cn)GetProcAddress(module,n);
  #define GETPROCADR1_void(n,cn,t1,p1)                                                       call##cn=(fce##cn)GetProcAddress(module,n);
  #define GETPROCADR2_void(n,cn,t1,p1,t2,p2)                                                 call##cn=(fce##cn)GetProcAddress(module,n);
  #define GETPROCADR3_void(n,cn,t1,p1,t2,p2,t3,p3)                                           call##cn=(fce##cn)GetProcAddress(module,n);
  #define GETPROCADR4_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                     call##cn=(fce##cn)GetProcAddress(module,n);
  #define GETPROCADR5_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                               call##cn=(fce##cn)GetProcAddress(module,n);
  #define GETPROCADR6_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                         call##cn=(fce##cn)GetProcAddress(module,n);
  #define GETPROCADR7_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                   call##cn=(fce##cn)GetProcAddress(module,n);
  #define GETPROCADR8_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)             call##cn=(fce##cn)GetProcAddress(module,n);
  #define GETPROCADR9_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)       call##cn=(fce##cn)GetProcAddress(module,n);

  #define GETPROCADR1_params(n,r,cn,t1,p1)                                                   call##cn=(fce##cn)GetProcAddress(module,n);
  #define GETPROCADR2_params(n,r,cn,t1,p1,t2,p2)                                             call##cn=(fce##cn)GetProcAddress(module,n);
  #define GETPROCADR3_params(n,r,cn,t1,p1,t2,p2,t3,p3)                                       call##cn=(fce##cn)GetProcAddress(module,n);
  #define GETPROCADR4_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                 call##cn=(fce##cn)GetProcAddress(module,n);
  #define GETPROCADR5_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                           call##cn=(fce##cn)GetProcAddress(module,n);
  #define GETPROCADR6_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                     call##cn=(fce##cn)GetProcAddress(module,n);
  #define GETPROCADR7_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)               call##cn=(fce##cn)GetProcAddress(module,n);
  #define GETPROCADR8_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)         call##cn=(fce##cn)GetProcAddress(module,n);
  #define GETPROCADR9_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)   call##cn=(fce##cn)GetProcAddress(module,n);

  #define GETPROCADR1_void_params(n,cn,t1,p1)                                                      call##cn=(fce##cn)GetProcAddress(module,n);
  #define GETPROCADR2_void_params(n,cn,t1,p1,t2,p2)                                                call##cn=(fce##cn)GetProcAddress(module,n);
  #define GETPROCADR3_void_params(n,cn,t1,p1,t2,p2,t3,p3)                                          call##cn=(fce##cn)GetProcAddress(module,n);
  #define GETPROCADR4_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                    call##cn=(fce##cn)GetProcAddress(module,n);
  #define GETPROCADR5_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                              call##cn=(fce##cn)GetProcAddress(module,n);
  #define GETPROCADR6_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                        call##cn=(fce##cn)GetProcAddress(module,n);
  #define GETPROCADR7_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                  call##cn=(fce##cn)GetProcAddress(module,n);
  #define GETPROCADR8_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)            call##cn=(fce##cn)GetProcAddress(module,n);
  #define GETPROCADR9_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)      call##cn=(fce##cn)GetProcAddress(module,n);

#elif defined(DEF_FUNC_GETPROCADDRESS_DECL)
  // generování GetProcAddress pro promìnné (funkèní pointery)
  #if DEBUG_PREPROC>2
    #pragma message("DEF_FUNC_GETPROCADDRESS_DECL")
  #endif
  #undef DEF_FUNC_GETPROCADDRESS_DECL
  #define GETPROCADR0(n,r,cn)                                                                fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}
  #define GETPROCADR1(n,r,cn,t1,p1)                                                          fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}
  #define GETPROCADR2(n,r,cn,t1,p1,t2,p2)                                                    fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}
  #define GETPROCADR3(n,r,cn,t1,p1,t2,p2,t3,p3)                                              fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}
  #define GETPROCADR4(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                        fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}
  #define GETPROCADR5(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                                  fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}
  #define GETPROCADR6(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                            fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}
  #define GETPROCADR7(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                      fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}
  #define GETPROCADR8(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)                fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}
  #define GETPROCADR9(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)          fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}

  #define GETPROCADR0_void(n,cn)                                                             fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}
  #define GETPROCADR1_void(n,cn,t1,p1)                                                       fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}
  #define GETPROCADR2_void(n,cn,t1,p1,t2,p2)                                                 fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}
  #define GETPROCADR3_void(n,cn,t1,p1,t2,p2,t3,p3)                                           fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}
  #define GETPROCADR4_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                     fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}
  #define GETPROCADR5_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                               fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}
  #define GETPROCADR6_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                         fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}
  #define GETPROCADR7_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                   fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}
  #define GETPROCADR8_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)             fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}
  #define GETPROCADR9_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)       fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}

  #define GETPROCADR1_params(n,r,cn,t1,p1)                                                   fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}
  #define GETPROCADR2_params(n,r,cn,t1,p1,t2,p2)                                             fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}
  #define GETPROCADR3_params(n,r,cn,t1,p1,t2,p2,t3,p3)                                       fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}
  #define GETPROCADR4_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                 fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}
  #define GETPROCADR5_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                           fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}
  #define GETPROCADR6_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                     fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}
  #define GETPROCADR7_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)               fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}
  #define GETPROCADR8_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)         fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}
  #define GETPROCADR9_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)   fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}

  #define GETPROCADR1_void_params(n,cn,t1,p1)                                                      fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}
  #define GETPROCADR2_void_params(n,cn,t1,p1,t2,p2)                                                fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}
  #define GETPROCADR3_void_params(n,cn,t1,p1,t2,p2,t3,p3)                                          fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}
  #define GETPROCADR4_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                    fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}
  #define GETPROCADR5_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                              fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}
  #define GETPROCADR6_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                        fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}
  #define GETPROCADR7_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                  fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}
  #define GETPROCADR8_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)            fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}
  #define GETPROCADR9_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)      fce##cn GetAddr##cn() {return call##cn=(fce##cn)GetProcAddress(module,n);}
#endif

// popis parametru maker - pro více parametrù jen adekvátnì pøibývají parametry maker
#ifndef PROCADR0
  /** Definice funkce bez parametru.
    @param cn    jméno metody v C++
    @param n     jméno funkce v DLL - pøedpokládá se C konvence
    @param r     návrattový typ
  */
  #define PROCADR0(cn,n,r) 
#endif
#ifndef PROCADR1
  /** Definice funkce s jedním parametrem.
    @param cn    jméno metody v C++
    @param n     jméno funkce v DLL - pøedpokládá se C konvence
    @param r     návrattový typ
    @param t1    typ prvního parametru (obdobnì dalších pro makra PROCADRn
    @param p1    jméno prvního parametru (obdobnì dalších pro makra PROCADRn
  */
  #define PROCADR1(cn,n,r,t1,p1) 
#endif

#ifndef PROCADR0_void
  /** Definice funkce s bez parametru, bez návratové hodnoty.
    @param cn    jméno metody v C++
    @param n     jméno funkce v DLL - pøedpokládá se C konvence
  */
  #define PROCADR0_void(cn,n) 
#endif
#ifndef PROCADR1_void
  /** Definice funkce s jedním parametrem, bez návratové hodnoty.
    @param cn    jméno metody v C++
    @param n     jméno funkce v DLL - pøedpokládá se C konvence
    @param t1    typ prvního parametru (obdobnì dalších pro makra PROCADRn
    @param p1    jméno prvního parametru (obdobnì dalších pro makra PROCADRn
  */
  #define PROCADR1_void(cn,n,t1,p1) 
#endif

#ifndef PROCADR0
 #define PROCADR0(n,r,cn)                                                               
#endif

#ifndef PROCADR1
 #define PROCADR1(n,r,cn,t1,p1)                                                         
#endif

#ifndef PROCADR2
 #define PROCADR2(n,r,cn,t1,p1,t2,p2)                                                   
#endif

#ifndef PROCADR3
 #define PROCADR3(n,r,cn,t1,p1,t2,p2,t3,p3)                                             
#endif

#ifndef PROCADR4
 #define PROCADR4(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                       
#endif

#ifndef PROCADR5
 #define PROCADR5(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                                 
#endif

#ifndef PROCADR6
 #define PROCADR6(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                           
#endif

#ifndef PROCADR7
 #define PROCADR7(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                     
#endif

#ifndef PROCADR8
 #define PROCADR8(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)               
#endif

#ifndef PROCADR9
 #define PROCADR9(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)         
#endif


#ifndef PROCADR0_void
 #define PROCADR0_void(n,cn)                                                            
#endif

#ifndef PROCADR1_void
 #define PROCADR1_void(n,cn,t1,p1)                                                      
#endif

#ifndef PROCADR2_void
 #define PROCADR2_void(n,cn,t1,p1,t2,p2)                                                
#endif

#ifndef PROCADR3_void
 #define PROCADR3_void(n,cn,t1,p1,t2,p2,t3,p3)                                          
#endif

#ifndef PROCADR4_void
 #define PROCADR4_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                    
#endif

#ifndef PROCADR5_void
 #define PROCADR5_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                              
#endif

#ifndef PROCADR6_void
 #define PROCADR6_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                        
#endif

#ifndef PROCADR7_void
 #define PROCADR7_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                  
#endif

#ifndef PROCADR8_void
 #define PROCADR8_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)            
#endif

#ifndef PROCADR9_void
 #define PROCADR9_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)      
#endif


#ifndef PROCADR1_params
 #define PROCADR1_params(n,r,cn,t1,p1)                                                  
#endif

#ifndef PROCADR2_params
 #define PROCADR2_params(n,r,cn,t1,p1,t2,p2)                                            
#endif

#ifndef PROCADR3_params
 #define PROCADR3_params(n,r,cn,t1,p1,t2,p2,t3,p3)                                      
#endif

#ifndef PROCADR4_params
 #define PROCADR4_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                
#endif

#ifndef PROCADR5_params
 #define PROCADR5_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                          
#endif

#ifndef PROCADR6_params
 #define PROCADR6_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                    
#endif

#ifndef PROCADR7_params
 #define PROCADR7_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)              
#endif

#ifndef PROCADR8_params
 #define PROCADR8_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)        
#endif

#ifndef PROCADR9_params
 #define PROCADR9_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)  
#endif

  
#ifndef PROCADR1_void_params
 #define PROCADR1_void_params(n,cn,t1,p1)                                               
#endif

#ifndef PROCADR2_void_params
 #define PROCADR2_void_params(n,cn,t1,p1,t2,p2)                                         
#endif

#ifndef PROCADR3_void_params
 #define PROCADR3_void_params(n,cn,t1,p1,t2,p2,t3,p3)                                   
#endif

#ifndef PROCADR4_void_params
 #define PROCADR4_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4)                             
#endif

#ifndef PROCADR5_void_params
 #define PROCADR5_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                       
#endif

#ifndef PROCADR6_void_params
 #define PROCADR6_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                 
#endif

#ifndef PROCADR7_void_params
 #define PROCADR7_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)           
#endif

#ifndef PROCADR8_void_params
 #define PROCADR8_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)     
#endif

#ifndef PROCADR9_void_params
 #define PROCADR9_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)
#endif

#ifndef GETPROCADR0
 #define GETPROCADR0(n,r,cn)                                                               
#endif

#ifndef GETPROCADR1
 #define GETPROCADR1(n,r,cn,t1,p1)                                                         
#endif

#ifndef GETPROCADR2
 #define GETPROCADR2(n,r,cn,t1,p1,t2,p2)                                                   
#endif

#ifndef GETPROCADR3
 #define GETPROCADR3(n,r,cn,t1,p1,t2,p2,t3,p3)                                             
#endif

#ifndef GETPROCADR4
 #define GETPROCADR4(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                       
#endif

#ifndef GETPROCADR5
 #define GETPROCADR5(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                                 
#endif

#ifndef GETPROCADR6
 #define GETPROCADR6(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                           
#endif

#ifndef GETPROCADR7
 #define GETPROCADR7(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                     
#endif

#ifndef GETPROCADR8
 #define GETPROCADR8(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)               
#endif

#ifndef GETPROCADR9
 #define GETPROCADR9(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)         
#endif


#ifndef GETPROCADR0_void
 #define GETPROCADR0_void(n,cn)                                                            
#endif

#ifndef GETPROCADR1_void
 #define GETPROCADR1_void(n,cn,t1,p1)                                                      
#endif

#ifndef GETPROCADR2_void
 #define GETPROCADR2_void(n,cn,t1,p1,t2,p2)                                                
#endif

#ifndef GETPROCADR3_void
 #define GETPROCADR3_void(n,cn,t1,p1,t2,p2,t3,p3)                                          
#endif

#ifndef GETPROCADR4_void
 #define GETPROCADR4_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                    
#endif

#ifndef GETPROCADR5_void
 #define GETPROCADR5_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                              
#endif

#ifndef GETPROCADR6_void
 #define GETPROCADR6_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                        
#endif

#ifndef GETPROCADR7_void
 #define GETPROCADR7_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                  
#endif

#ifndef GETPROCADR8_void
 #define GETPROCADR8_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)            
#endif

#ifndef GETPROCADR9_void
 #define GETPROCADR9_void(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)      
#endif


#ifndef GETPROCADR1_params
 #define GETPROCADR1_params(n,r,cn,t1,p1)                                                  
#endif

#ifndef GETPROCADR2_params
 #define GETPROCADR2_params(n,r,cn,t1,p1,t2,p2)                                            
#endif

#ifndef GETPROCADR3_params
 #define GETPROCADR3_params(n,r,cn,t1,p1,t2,p2,t3,p3)                                      
#endif

#ifndef GETPROCADR4_params
 #define GETPROCADR4_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4)                                
#endif

#ifndef GETPROCADR5_params
 #define GETPROCADR5_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                          
#endif

#ifndef GETPROCADR6_params
 #define GETPROCADR6_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                    
#endif

#ifndef GETPROCADR7_params
 #define GETPROCADR7_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)              
#endif

#ifndef GETPROCADR8_params
 #define GETPROCADR8_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)        
#endif

#ifndef GETPROCADR9_params
 #define GETPROCADR9_params(n,r,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)  
#endif

  
#ifndef GETPROCADR1_void_params
 #define GETPROCADR1_void_params(n,cn,t1,p1)                                               
#endif

#ifndef GETPROCADR2_void_params
 #define GETPROCADR2_void_params(n,cn,t1,p1,t2,p2)                                         
#endif

#ifndef GETPROCADR3_void_params
 #define GETPROCADR3_void_params(n,cn,t1,p1,t2,p2,t3,p3)                                   
#endif

#ifndef GETPROCADR4_void_params
 #define GETPROCADR4_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4)                             
#endif

#ifndef GETPROCADR5_void_params
 #define GETPROCADR5_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                       
#endif

#ifndef GETPROCADR6_void_params
 #define GETPROCADR6_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                 
#endif

#ifndef GETPROCADR7_void_params
 #define GETPROCADR7_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)           
#endif

#ifndef GETPROCADR8_void_params
 #define GETPROCADR8_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)     
#endif

#ifndef GETPROCADR9_void_params
 #define GETPROCADR9_void_params(n,cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)
#endif
// clang-format on

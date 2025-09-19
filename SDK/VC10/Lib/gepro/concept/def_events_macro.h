/** Makra pro definice tøíd realizující události a jejich registrace
*/
#undef EPROCADR0
#undef EPROCADR1
#undef EPROCADR2
#undef EPROCADR3
#undef EPROCADR4
#undef EPROCADR5
#undef EPROCADR6
#undef EPROCADR7
#undef EPROCADR8
#undef EPROCADR9

#if defined(DEF_FUNC_TYPEDEF)
  // generování typedef
  #if DEBUG_PREPROC>2
    #pragma message("DEF_FUNC_TYPEDEF")
  #endif
  #undef DEF_FUNC_TYPEDEF
  #define EPROCADR0(cn)                                                                virtual void cn()=0;
  #define EPROCADR1(cn,t1,p1)                                                          virtual void cn(t1 p1)=0;
  #define EPROCADR2(cn,t1,p1,t2,p2)                                                    virtual void cn(t1 p1,t2 p2)=0;
  #define EPROCADR3(cn,t1,p1,t2,p2,t3,p3)                                              virtual void cn(t1 p1,t2 p2,t3 p3)=0;
  #define EPROCADR4(cn,t1,p1,t2,p2,t3,p3,t4,p4)                                        virtual void cn(t1 p1,t2 p2,t3 p3,t4 p4)=0;
  #define EPROCADR5(cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                                  virtual void cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5)=0;
  #define EPROCADR6(cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                            virtual void cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6)=0;
  #define EPROCADR7(cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                      virtual void cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7)=0;
  #define EPROCADR8(cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)                virtual void cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8)=0;
  #define EPROCADR9(cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)          virtual void cn(t1 p1,t2 p2,t3 p3,t4 p4,t5 p5,t6 p6,t7 p7,t8 p8,t9 p9)=0;

#elif defined(DEF_FUNC_CALL)
  // generování funkce pro promìnnou (funkèní pointer) 
  #if DEBUG_PREPROC>2
    #pragma message("DEF_FUNC_CALL")
  #endif
  #undef DEF_FUNC_CALL
#define EPROCADR0(cn)                                                \
  void Call##cn() {                                                  \
    for (auto it = regs.begin(); it != regs.end(); ++it) (*it)->cn(); \
  }
#define EPROCADR1(cn, t1, p1)                                          \
  void Call##cn(t1 p1) {                                               \
    for (auto it = regs.begin(); it != regs.end(); ++it) (*it)->cn(p1); \
  }
#define EPROCADR2(cn, t1, p1, t2, p2)                                      \
  void Call##cn(t1 p1, t2 p2) {                                            \
    for (auto it = regs.begin(); it != regs.end(); ++it) (*it)->cn(p1, p2); \
  }
#define EPROCADR3(cn, t1, p1, t2, p2, t3, p3)                                  \
  void Call##cn(t1 p1, t2 p2, t3 p3) {                                         \
    for (auto it = regs.begin(); it != regs.end(); ++it) (*it)->cn(p1, p2, p3); \
  }
#define EPROCADR4(cn, t1, p1, t2, p2, t3, p3, t4, p4)                              \
  void Call##cn(t1 p1, t2 p2, t3 p3, t4 p4) {                                      \
    for (auto it = regs.begin(); it != regs.end(); ++it) (*it)->cn(p1, p2, p3, p4); \
  }
#define EPROCADR5(cn, t1, p1, t2, p2, t3, p3, t4, p4, t5, p5)                          \
  void Call##cn(t1 p1, t2 p2, t3 p3, t4 p4, t5 p5) {                                   \
    for (auto it = regs.begin(); it != regs.end(); ++it) (*it)->cn(p1, p2, p3, p4, p5); \
  }

#endif

// popis parametru maker - pro více parametrù jen adekvátnì pøibývají parametry maker
#ifndef EPROCADR0
  /** Definice funkce bez parametru.
    @param cn    jméno metody v C++
  */
  #define EPROCADR0(cn) 
#endif
#ifndef EPROCADR1
  /** Definice funkce s jedním parametrem.
    @param cn    jméno metody v C++
    @param t1    typ prvního parametru (obdobnì dalších pro makra PROCADRn
    @param p1    jméno prvního parametru (obdobnì dalších pro makra PROCADRn
  */
  #define EPROCADR1(cn,t1,p1) 
#endif

#ifndef EPROCADR2
 #define EPROCADR2(cn,t1,p1,t2,p2)                                                   
#endif

#ifndef EPROCADR3
 #define EPROCADR3(cn,t1,p1,t2,p2,t3,p3)                                             
#endif

#ifndef EPROCADR4
 #define EPROCADR4(cn,t1,p1,t2,p2,t3,p3,t4,p4)                                       
#endif

#ifndef EPROCADR5
 #define EPROCADR5(cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5)                                 
#endif

#ifndef EPROCADR6
 #define EPROCADR6(cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6)                           
#endif

#ifndef EPROCADR7
 #define EPROCADR7(cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7)                     
#endif

#ifndef EPROCADR8
 #define EPROCADR8(cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8)               
#endif

#ifndef EPROCADR9
 #define EPROCADR9(cn,t1,p1,t2,p2,t3,p3,t4,p4,t5,p5,t6,p6,t7,p7,t8,p8,t9,p9)         
#endif


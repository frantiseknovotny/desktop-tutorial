#ifndef __MTIMER_H
#define __MTIMER_H

namespace cz {
namespace gepro {

/**	\brief	The mtimer class, mìøení èasu
  mtimer mt;
  ...
  double time=mt.Latch();
  //trvalo to time vterin


*/
class mtimer {
  double K1;
  double K3;
  double offset;

   double start;
public:

   mtimer() : K1(1),K3(65536.0*65536.0),offset(0),start(0) {
     LARGE_INTEGER li={0,0};
     QueryPerformanceFrequency(&li);
     double f=K3*li.u.HighPart+li.u.LowPart;
     K1/=f;
     K3/=f;
   
     double x=Latch();
     Start();
     double y=Latch();
     if (x>y) x=y;
     offset=x;

     Start();
   }
   
   void Start();
   double Latch();
   double GetMTime();
};

/*
inline int mtimer_init() {
   LARGE_INTEGER li={0,0};
   QueryPerformanceFrequency(&li);
   double f=K3*li.u.HighPart+li.u.LowPart;
   K1/=f;
   K3/=f;
   mtimer mt;
   double x=mt.Latch();
   mt.Start();
   double y=mt.Latch();
   if (x>y) x=y;
   offset=x;
   return 0;
}
static int mstart=mtimer_init();
*/
inline double mtimer::GetMTime(){
   LARGE_INTEGER li={0,0};
   QueryPerformanceCounter(&li);
   return K3*li.u.HighPart+K1*li.u.LowPart;
}
inline void mtimer::Start() {
   start=GetMTime();
}
inline double mtimer::Latch() {
   return GetMTime()-start-offset;
}

};//gepro
};//cz

#endif 

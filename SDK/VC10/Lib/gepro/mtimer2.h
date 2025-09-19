#ifndef __MTIMER2_H
#define __MTIMER2_H

namespace cz {
namespace gepro {

/**	\brief	The mtimer class, mìøení èasu - verze se statickou inicialilzaci
  mtimer mt;
  ...
  double time=mt.Latch();
  //trvalo to time vterin


*/
class mtimer2 {	 
  /** Statický inicializátor - zavolá se pouze jednou v rámci instance HMODULE (exe,dll)
  */
  struct initializer {
       initializer():K1(1),K3(65536.0*65536.0),offset(0),start(0) {
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
       }
       double GetMTime() const {
         LARGE_INTEGER li={0,0};
         QueryPerformanceCounter(&li);
         return K3*li.u.HighPart+K1*li.u.LowPart;
       }
       double GetLatchTime() const {return GetMTime()-offset;}
     private:
       double K1;
       double K3;
       double offset;
       double start;
       double Latch() {return GetMTime()-start-offset;}
       void Start() {start=GetMTime();}
   };
   // staticka instance inicializeru
   static const initializer& initializer_() {
     static initializer i;
     return i;
   }
   double start; ///< startovací èas
public:

   mtimer2() {Start();}
   mtimer2(const mtimer2& src):start(src.start) {}
   void Start() {start=initializer_().GetMTime();}
   double Latch() {return initializer_().GetLatchTime()-start;}
};


};//gepro
};//cz

#endif 

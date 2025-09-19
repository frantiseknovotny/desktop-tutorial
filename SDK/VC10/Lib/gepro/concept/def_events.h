#include <gepro/preproc.h>
/* Vzor pro generování interface pro dynamicky linkovane knihovny. 
   
*/
#define DEFINCLUDE_EVENTS_CONCEPT <gepro/concept/def_events_macro.h>
class DEFEVENTCLASS {
   public:
    #define DEF_FUNC_TYPEDEF
    #include DEFINCLUDE_EVENTS_CONCEPT
    #include DEFINCLUDE
};
class DEFEVENTCLASSREG {
  std::vector<DEFEVENTCLASS*> regs;

 public:
  void Add(DEFEVENTCLASS* e) {
    auto it = std::find(regs.begin(), regs.end(), e);
    if (it != regs.end()) return;
    regs.push_back(e);
  }
  void Remove(DEFEVENTCLASS* e) {
    auto it = std::find(regs.begin(), regs.end(), e);
    if (it != regs.end()) regs.erase(it);
  }
#define DEF_FUNC_CALL
#include DEFINCLUDE_EVENTS_CONCEPT
#include DEFINCLUDE
};
#undef EVENTCLASS
#undef DEFINCLUDE_EVENTS_CONCEPT
#undef DEFINCLUDE

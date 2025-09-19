#ifndef __SDK_GEPRO_TEVENTSDISPATCHER_H
#define __SDK_GEPRO_TEVENTSDISPATCHER_H
#if defined(DEBUG_PREPROC)
  #pragma message(__FILE__ "(1) : debug included")
#endif

#ifndef __SDK_GEPRO_SINGLETON_H
  #include "singleton.h"
#endif
#ifndef ___GEPRO_VECTOR_H
  #include "vector"
#endif
#ifndef ___SDK_GEPRO_STRING_H
  #include "string.h"
#endif
#ifndef ___SDK_GEPRO_SET_H
  #include "set"
#endif
#ifndef _ALGORITHM_
  #include <algorithm>
#endif
/** Template pro generování dispatcheru událostí
*/
template <class D,class I>
class EventsDispatcher:public cz::gepro::singleton<D> {
  protected:
    typedef D Derived;
    typedef cz::gepro::singleton<Derived> base_type;
    friend class cz::gepro::singleton<D>;
    typedef I value_type;
    typedef std::vector<I*> register_I;
    register_I register_;
    EventsDispatcher() {}
    void _Register(I* _i) {
      auto b=register_.begin();
      auto e=register_.end();
      for(;b!=e;b++) {
        if(_i==*b) {
          return;
        }
      } 
      register_.push_back(_i);
    }
    void _UnRegister(I* _i) {
      auto b=register_.begin();
      auto e=register_.end();
      for(;b!=e;b++) {
        if(_i==*b) {
          register_.erase(b);
          return;
        }
      } 
    }
  public:
    static void Register(I* _i) {base_type::Instance()._Register(_i);}
   static void UnRegister(I* _i) { base_type::Instance()._UnRegister(_i); }
};
template <class D,class I>
class UrlDispatcher:public cz::gepro::singleton<D> {
  protected:
  typedef D Derived;
  typedef cz::gepro::singleton<Derived> base_type;
  friend class cz::gepro::singleton<D>;
    typedef cz::gepro::set_of_value<I*> register_I;
    register_I register_;
    UrlDispatcher() {}
    void _Register(I* _i) {
      register_.add(_i->GetUrl(),_i);
    }
    void _UnRegister(I* _i) {
      register_.erase(_i);
    }
    I* find(const char* _url) {
      return  register_.find(_url);
    }
    typedef typename register_I::const_iterator const_iterator;
    const_iterator begin() const {return register_.begin();}
    const_iterator end() const {return register_.end();}
  public:
    static void Register(I* _i) { base_type::Instance()._Register(_i); }
   static void UnRegister(I* _i) { base_type::Instance()._UnRegister(_i); }
};
#endif

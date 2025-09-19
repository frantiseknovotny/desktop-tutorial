#ifndef __SDK_GEPRO_SINGLETON_H
#define __SDK_GEPRO_SINGLETON_H
#if defined(DEBUG_PREPROC)
  #pragma message(__FILE__ "(1) : debug included")
#endif
#if _MSC_VER==1200
  #ifdef DEBUG_PREPROC
    #pragma message("[INFO] disable inline for VC6")
  #endif
  #pragma inline_recursion(off)
  #pragma inline_depth(0)
#endif

#include <boost/noncopyable.hpp>
namespace cz {
namespace gepro {

// základní varianta pro singleton = složitìjší viz boost
// ************************************************************************** //
// **************                   singleton                  ************** //
// ************************************************************************** //

template<typename Derived>
class singleton:public boost::noncopyable {
public:
    static Derived& Instance() { static Derived the_inst; return the_inst; }    
protected:
    singleton()  {}
    ~singleton() {}
};


// základní varianta pro singleton s jedním parametrem
// ************************************************************************** //
// **************                   singleton                  ************** //
// Prvni volani s jednim parametrem inicializuje Derived, dalsi volani
// uz musi bytbez parametru, jinak vyjimka, druhe a dalsi volani s parametrem
// taky vyvola vyjimku.
// Typ T musi mit rozumne fungujici operator*
//
//  class xx : public cz::gepro::singleton1<xx,std::string>
//  {
//    std::string str_;
//    friend class cz::gepro::singleton1<xx, std::string>;
//  public:
//    xx(const std::string& str) : str_(str) {}
//    xx(){}
//    std::string get_str() const
//    {
//      return str_;
//    }
//  };
// ...
// std::string s = xx::Instance().get_str(); // vyjimka catch (cz::gepro::singleton1<xx, std::string>::use_uninitialized_exception& ex)
// ...
// std::string s1 = xx::Instance("ahoj").get_str(); //inicializuje a vrati "ahoj"
// std::string s2 = xx::Instance().get_str();       //vrati "ahoj"
// std::string s3 = xx::Instance("ahoj").get_str(); // vyjimka catch (cz::gepro::singleton1<xx, std::string>::second_initialization_exception& ex)
// ************************************************************************** //

template<typename Derived, typename T1>
class singleton1 :public boost::noncopyable {
public:
  static Derived& Instance()
  {
    return instance(nullptr);
  }
  static Derived& Instance(const T1& par) {
    return instance(&par);
  }

  class use_uninitialized_exception : public std::exception
  {
  public:
    use_uninitialized_exception() : std::exception("uninitialized parametric singleton") {}
  };

  class second_initialization_exception : public std::exception
  {
  public:
    second_initialization_exception() : std::exception("second initialization parametric singleton") {}
  };
protected:
  singleton1() : inst_ptr(nullptr) {}
  ~singleton1() {}
private:
  Derived* inst_ptr;
  static Derived& instance(const T1* par_ptr)
  {
    static bool first_call(true);
    if (first_call) 
    {
      if (!par_ptr)
      {
        throw(use_uninitialized_exception());
      }
      first_call = false;
    }
    else
    {
      if (par_ptr)
      {
        throw(second_initialization_exception());
      }
    }
    static Derived the_inst(*par_ptr);
    return the_inst;
  }
};

}; //gepro
}; //cz
#endif

#ifndef __SDK_GEPRO_SMARTARRAYS_H
#define __SDK_GEPRO_SMARTARRAYS_H
#if defined(DEBUG_PREPROC)
  #pragma message(__FILE__ "(1) : debug included")
#endif
#ifndef __SDK_GEPRO_EXCEPTIONS_H
  #include "exceptions.h"
#endif
namespace cz {
namespace gepro {
/** @defgroup statarrays  Statick� pole a vektory

    @{
    Hlavn� pou�it� je p�i sjednocen� interface const nebo statick�ch pol�.
*/
/** Pole const* na typ T, slou�� pro sjednocen� interface se STL containery pro statick� pole. 
    Vstupn� pole mus� b�t zd�no jako parametry konstruktoru a nelze je m�nit, 
    mus� m�t zaji�t�nu del�� �ivotnost (scoping) ne� const_T_array do n�ho� se p�ipojuje. 
    Je podporov�n pouze interface pro �ten� a vyhled�n� hodnoty v poli.
    P�edpokl�d� se pou�it� pro POD typy, netestov�no pro t��dy.

    @param T     datov� typ pole
    @param esig  pokud je 1 generuje vyj�mku, p�i p��stupu mimo rozsah pole

    \code
      typedef cz::gepro::const_T_array<int> const_int_array;
      int buf[]={1,2,3,4,5,6,7,8,9};
      const_int_array a(buf,sizeof(buf)/sizeof(buf[0]));
      TS_ASSERT_EQUALS(a.size(),9)
      TS_ASSERT_EQUALS(*a.begin(),1)
      TS_ASSERT_EQUALS(*(a.begin()+2),3)
      const_int_array::const_iterator p=a.find(6);
      TS_ASSERT_EQUALS(p,buf+5)
    \endcode
*/
template <class T,int esig=0> class const_T_array {
  public:
    typedef T value_type;
    typedef const value_type* const_iterator;
    const_T_array(const_iterator _data,unsigned _cnt):ptr_(_data),cnt_(_cnt) {}
    const_iterator begin() const {return ptr_;}
    const_iterator end() const {return ptr_+cnt_;}
    size_t size() const {return cnt_;}
    const_iterator operator[](unsigned i) {
      if(i>=size()) {
        if(esig) throw small_buffer();
        return end();
      }
      return begin()+i;
    }
    /** Vyhled�n� hodnoty v poli, vrac� iterator na nalezenou polo�ku nebo end(),
        pokud se nena�la.
    */
    const_iterator find(const T& i) {
      const_iterator b=begin();
      const_iterator e=end();
      for(;b!=e;b++) {
        if(*b==i) break;
      }
      return b;
    }
  private:
    const_iterator ptr_;
    const unsigned cnt_;

};
/** Statick� pole s interafec jako STL. 
    Oproti vektoru neuchov�v� po�et polo�ek - p�edpokl�d� se �e cel� pole je napln�n�
    platn�mi hodnotami - inicializov�no na 0, kter� lze m�nit pomoc� oper�toru []. 
    Statickou obdobu vector realizuje t��da static_T_vector.
    P�edpokl�d� se pou�it� pro POD typy, netestov�no pro t��dy.

    \code
    \endcode
*/
template <int max,class T,int esig=0> class static_T_array {
  public:
    typedef T value_type;
    typedef value_type* iterator;
    typedef const value_type* const_iterator;
    typedef T& value_reference;
    typedef unsigned size_type;
  protected:
    unsigned set(const const_T_array<value_type>& _array) {
      size_type cnt=_array.size();
      if(cnt>=max) {
        cnt=max;
      }
      memcpy(ptr_,_array.begin(),cnt*sizeof(value_type));
      ptr_[max]=0;
      return cnt;
    }
    unsigned set(const_iterator _data,size_type _cnt) {
      if(_cnt>=max) _cnt=max;
      memcpy(ptr_,_data,_cnt*sizeof(value_type));
      ptr_[max]=(value_type)0;
      return _cnt;
    }
  public:
    static_T_array() {
      memset(ptr_,0,sizeof(ptr_));
    }
    static_T_array(const const_T_array<value_type>& _array) {
      set(_array);
    }
    static_T_array(const_iterator _data,size_t _cnt) {
      set(_data,_cnt);
    }
    iterator begin() {return ptr_;}
    iterator end() {return ptr_+max;}
    size_type size() const {return max;}
    size_type capacity() const {return max;}
    value_reference operator[](unsigned i) {
      if(i>=size()) {
        if(esig) throw small_buffer();
        return ptr_[max];
      }
      return ptr_[i];
    }
    iterator find(const T& i) {
      iterator b=begin();
      iterator e=end();
      for(;b!=e;b++) {
        if(*b==i) break;
      }
      return b;
    }

  protected:
    value_type ptr_[max+1];
};
/** Statick� pole s interafec jako STL. 
    Oproti vektoru neuchov�v� po�et polo�ek - p�edpokl�d� se �e cel� pole je napln�n�
    platn�mi hodnotami - inicializov�no na 0, kter� lze m�nit pomoc� oper�toru []. 
    Statickou obdobu vector realizuje t��da static_T_vector.
    P�edpokl�d� se pou�it� pro POD typy, netestov�no pro t��dy.

    \code
    \endcode
*/
template <int max, class T, int esig = 0>
class static_T_vector : public static_T_array<max, T, esig> {
 public:
  typedef static_T_array<max, T, esig> base_type;
  typedef typename base_type::value_type value_type;
  typedef typename base_type::size_type size_type;
  typedef typename base_type::iterator iterator;
  typedef typename base_type::const_iterator const_iterator;
  typedef typename base_type::value_reference value_reference;
  static_T_vector() : static_T_array<max, T, esig>(), cnt_(0) {}
  static_T_vector(const const_T_array<value_type>& _array) : static_T_array<max, T, esig>(), cnt_(0) { cnt_ = set(_array); }
  static_T_vector(const_iterator _data, size_t _cnt) : static_T_array<max, T, esig>(), cnt_(0) { cnt_ = set(_data, _cnt); }

  size_type size() const { return cnt_; }
  iterator end() { return base_type::ptr_ + cnt_; }
  value_reference operator[](unsigned i) {
    if (i >= base_type::capacity()) {
      if (esig) throw small_buffer();
      return base_type::ptr_[max];
    }
    if (i >= size()) { cnt_ = i + 1; }
    return base_type::ptr_[i];
  }
  void push_back(value_type v) {
    if (cnt_ >= base_type::capacity()) {
      if (esig) throw small_buffer();
      return;
    }
    base_type::ptr_[cnt_++] = v;
  }

 protected:
  unsigned cnt_;
};
};//gepro
};//cz
#define SIZEOF_ARRAY(c) (sizeof(c)/sizeof(c[0]))
/**
  @}
*/
#endif // __SDK_GEPRO_SMARTBUFS_H

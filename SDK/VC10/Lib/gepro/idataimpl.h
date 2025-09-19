#ifndef __SDK_GEPRO_IDATAIMPL_H
#define __SDK_GEPRO_IDATAIMPL_H
#if defined(DEBUG_PREPROC)
  #pragma message(__FILE__ "(1) : debug included")
#endif
#ifndef __SDK_GEPRO_IDATA_H
  #include "idata.h"
#endif
#ifndef  __GEPRO_MAP_
  #include "map"
#endif

namespace cz {
namespace gepro {

template<class K,class V,class E=char>
class TIDataImplMap:public TIData<V,E> {
  public:
    typedef K key_type;
    typedef V value_type;
    typedef E char_type;
    typedef mapvector<key_type,value_type> map_type;

    virtual const char_type* GetName() {return "";}
    /** Poèet datových položek.
    */
    virtual size_t GetCount() {return data_.size();}
    /** Identifikátor datové položky podle indexu
    */
    virtual const char_type* GetId(size_t i) {return (const char_type*)data_.getkey(i);}
    /** Index datové položky podle identifikátoru
    */
    virtual size_t GetIndex(const char_type* id) {return data_.findindex(key_type(id));}
    virtual const value_type& GetValue(size_t i) {return data_.getvalue(i);}

    void insert(const key_type& _key,const value_type& _val) {data_.insert(_key,_val);}
  protected:
    map_type data_;
};

}; //gepro
}; //cz
#endif
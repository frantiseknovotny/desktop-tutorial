#ifndef __SDK_GEPRO_IDATA_H
#define __SDK_GEPRO_IDATA_H
#if defined(DEBUG_PREPROC)
  #pragma message(__FILE__ "(1) : debug included")
#endif

namespace cz {
namespace gepro {
/*  Interface pro export dat
*/
/** Hlavièka dat
*/
template<class E=char>
class TIDataHead {
  public:
    typedef E char_type;

    /** Název dat.
    */
    virtual const char_type* GetName()=0;
    /** Poèet datových položek.
    */
    virtual size_t GetCount()=0;
    /** Identifikátor datové položky podle indexu
    */
    virtual const char_type* GetId(size_t i)=0;
    /** Index datové položky podle identifikátoru
    */
    virtual size_t GetIndex(const char_type* id)=0;
};
/** Datový øádek
*/
template<class V>
class TIDataRow {
  public:
    typedef V value_type;

    /** Hodnota položky podle indexu - 
    */
    virtual const value_type& GetValue(size_t i)=0;
};
/** Interface pro poskytování dat. Každá datová položka musí být identikováná 
    jednoznaèným identifikátorem. Poskytovaná hodnota mùže být libovolný typ
    z variantu V pøedaného jako parametr.
*/
template<class V,class E=char>
class TIData:public TIDataHead<E>,public TIDataRow<V> {
  public:
};
template<class V,class E=char>
class TIDataRows:public TIDataHead<E> {
  public:
    typedef TIDataRow<V> data_row;
    typedef typename data_row::value_type value_type;
    virtual size_t GetCntRows()=0;
    virtual data_row* GetDataRow(size_t i)=0;
};

}; //gepro
}; //cz
#endif
#ifndef __SDK_GEPRO_IDATA_H
#define __SDK_GEPRO_IDATA_H
#if defined(DEBUG_PREPROC)
  #pragma message(__FILE__ "(1) : debug included")
#endif

namespace cz {
namespace gepro {
/*  Interface pro export dat
*/
/** Hlavi�ka dat
*/
template<class E=char>
class TIDataHead {
  public:
    typedef E char_type;

    /** N�zev dat.
    */
    virtual const char_type* GetName()=0;
    /** Po�et datov�ch polo�ek.
    */
    virtual size_t GetCount()=0;
    /** Identifik�tor datov� polo�ky podle indexu
    */
    virtual const char_type* GetId(size_t i)=0;
    /** Index datov� polo�ky podle identifik�toru
    */
    virtual size_t GetIndex(const char_type* id)=0;
};
/** Datov� ��dek
*/
template<class V>
class TIDataRow {
  public:
    typedef V value_type;

    /** Hodnota polo�ky podle indexu - 
    */
    virtual const value_type& GetValue(size_t i)=0;
};
/** Interface pro poskytov�n� dat. Ka�d� datov� polo�ka mus� b�t identikov�n� 
    jednozna�n�m identifik�torem. Poskytovan� hodnota m��e b�t libovoln� typ
    z variantu V p�edan�ho jako parametr.
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
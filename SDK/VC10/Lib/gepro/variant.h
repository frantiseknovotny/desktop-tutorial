#ifndef __SDK_GEPRO_VARIANT_H
#define __SDK_GEPRO_VARIANT_H
#if defined(DEBUG_PREPROC)
  #pragma message(__FILE__ "(1) : debug included")
#endif
#ifndef BOOST_VARIANT_HPP
  #include   <boost/variant.hpp>
#endif
#ifndef __SDK_GEPRO_IDATA_H
  #include "idata.h"
#endif
namespace cz {
namespace gepro {
/* Definice variantu a interface pro jeho enumeraci
*/
typedef boost::variant<int,double,const char*> variant;
typedef boost::variant<int,double,const char*,const int*> variant2;


typedef TIDataRow<variant> IDataRow;
typedef TIData<variant> IData;
typedef TIDataHead<variant> IDataHead;
typedef TIDataRows<variant> IDataRows;

typedef TIDataRow<variant2> IDataRow2;
typedef TIData<variant2> IData2;
typedef TIDataHead<variant2> IDataHead2;
typedef TIDataRows<variant2> IDataRows2;

}; //gepro
}; //cz
#endif
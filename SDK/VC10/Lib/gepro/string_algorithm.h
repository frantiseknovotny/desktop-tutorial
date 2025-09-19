#ifndef   ___SDK_GEPRO_STRING_ALGORITHM_H
#define   ___SDK_GEPRO_STRING_ALGORITHM_H

#if defined(DEBUG_PREPROC)
  #pragma message(__FILE__ "(1) : debug included")
#endif

#include <iostream>
#include <boost/algorithm/string.hpp>


namespace cz {
namespace gepro {
/**	\brief	The case_insensitive_find_and_replace template, case insensitive nalezeni vzoru ve stringu
 *a jeho pripadne prepsani, hledani nepodporuje diakritiku treba ò a Ò nenajde.

   \param	s	a parameter of type T v tom se bude hledat a prepisovat
   \param	sample	a parameter of type const char* samplehledany vzor
   \param	replace a parameter of type const char* cim se ma prepsat
   
   \return bool, true vzor byl nalezen, flase vzor nebyl nalezen
*/
template <typename T> bool ifind_and_replace(T& s,const char* sample,const char* replace) {

  boost::iterator_range<std::string::iterator> range = boost::algorithm::ifind_first( s, sample );
  if( !range.empty()) {
    if( boost::algorithm::iequals( std::string( range.begin(), range.end() ), sample ) ) {
      s.replace(range.begin(),range.end(),replace);
      return true;
    }
  }
  return false;
}

}; //gepro
}; //cz
#endif

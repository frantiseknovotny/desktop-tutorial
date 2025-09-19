#ifndef __BINARY_FIND_H
#define __BINARY_FIND_H

#include <algorithm>
namespace cz {
namespace gepro {

/**	\brief	The binary_find template, binarni vyhledavani v setridenem containeru,

    Compare muze vypdat napr.: bool my_compare(const myclass& a, const myclass& b) {
                                     return a.i<b.i;
                                   }

  \param	begin	  iterator odkud
  \param	end	    iterator kam
  \param	val	    iteraror to co se hleda
  \param	cmp	    porovnavaci funkce
  \param	found	  iterator nalezeneho prvku, pokud found==end tak se nenasel

  \return	pokud se nasel tak end, jinak nalezeny iterator, tedy vzdy iterator pro insert
  
*/

template< typename Iter, typename T, typename Compare>
Iter binary_find(Iter begin, Iter end,const T& val, Compare cmp, Iter& found)
{
    // Finds the lower bound in at most log(last - first) + 1 comparisons
    Iter i = std::lower_bound(begin, end, val, cmp);

    if( (end != i) && !cmp(val,*i)) {
        found=i;
        return end; // found
    } else {
        found=end;
        return i; // not found
    }
}

/**	\brief	The binary_find template, binarni vyhledavani v setridenem containeru,
      predpoklada, ze T ma definovany operator <

  \param	begin	iterator odkud
  \param	end	    iterator kam
  \param	val	    iteraror to co se hleda
  \param	found	iterator nalezeneho prvku, pokud found==end tak se nenasel

  \return	pokud se nasel tak end, jinak nalezeny iterator, tedy tedy vzdy iterator pro insert
  
*/

template< typename Iter, typename T>
Iter binary_find(Iter begin, Iter end,const T& val, Iter& found)
{
    // Finds the lower bound in at most log(last - first) + 1 comparisons
    Iter i = std::lower_bound(begin, end, val);

    if (i != end && !(val < *i)) {
        found=i;
        return end; // found
    } else {
        found=end;
        return i; // not found
    }
}


}; //gepro
}; //cz
#endif

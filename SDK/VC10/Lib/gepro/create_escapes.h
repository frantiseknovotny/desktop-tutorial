#ifndef __SDK_GEPRO_CREATE_ESCAPES_H
#define __SDK_GEPRO_CREATE_ESCAPES_H

#include <boost/type_traits/make_unsigned.hpp>
#include <string>

namespace cz {
  namespace gepro {

    // Create necessary escape sequences from illegal characters
    template<class Ch>
    std::basic_string<Ch> create_escapes(const std::basic_string<Ch>& s, Ch ec = '\\')
    {
      std::basic_string<Ch> result;
      typename std::basic_string<Ch>::const_iterator b = s.begin();
      typename std::basic_string<Ch>::const_iterator e = s.end();
      while (b != e)
      {
        // This assumes an ASCII superset. But so does everything in PTree.
        // We escape everything outside ASCII, because this code can't
        // handle high unicode characters.
        if (*b == 0x20 || *b == 0x21 || (*b >= 0x23 && *b <= 0x2E) ||
          (*b >= 0x30 && *b <= 0x5B) || (*b >= 0x5D && *b <= 0xFF))
          result += *b;
        else if (*b == Ch('\b')) result += Ch('\\'), result += Ch('b');
        else if (*b == Ch('\f')) result += Ch('\\'), result += Ch('f');
        else if (*b == Ch('\n')) result += Ch('\\'), result += Ch('n');
        else if (*b == Ch('\r')) result += Ch('\\'), result += Ch('r');
        else if (*b == Ch('\t')) result += Ch('\\'), result += Ch('t');
        else if (*b == Ch('/')) result += Ch('\\'), result += Ch('/');
        else if (*b == Ch('"'))  result += Ch('\\'), result += Ch('"');
        else if (*b == Ch('\\')) result += Ch('\\'), result += Ch('\\');
        else
        {
          const char* hexdigits = "0123456789ABCDEF";
          typedef typename boost::make_unsigned<Ch>::type UCh;
          unsigned long u = (std::min)(static_cast<unsigned long>(
            static_cast<UCh>(*b)),
            0xFFFFul);
          int d1 = u / 4096; u -= d1 * 4096;
          int d2 = u / 256; u -= d2 * 256;
          int d3 = u / 16; u -= d3 * 16;
          int d4 = u;
          result += ec; result += Ch('u');
          result += Ch(hexdigits[d1]); result += Ch(hexdigits[d2]);
          result += Ch(hexdigits[d3]); result += Ch(hexdigits[d4]);
        }
        ++b;
      }
      return result;
    }
  }      //gepro
} //cz

#endif
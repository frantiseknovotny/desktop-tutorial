/* Generated file, do not edit */

#pragma warning(disable:4097 4786)
#define _CRT_SECURE_NO_WARNINGS
#include <gepro/windows.h>
#include <gepro/strings/compare.h>

namespace cz {
namespace gepro {
int compare_n(const char* a,const char* b)
{
  return compare<'\n',char>(a,b);
}
bool equals_n(const char* a,const char* b)
{
  return equals<'\n',char>(a,b);
}

}; //gepro
}; //cz

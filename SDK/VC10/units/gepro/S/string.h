#ifndef __TEST_STRING_H
#define __TEST_STRING_H
/** Testy inline funkcí sjednocující použití char* a wchar_t*
*/
#define TS_ASSERT_TEXT_CSTR(a,b)\
  TS_ASSERT_EQUALS(sizeof(a)-1,b.length())\
  TS_ASSERT_SAME_DATA(a, b.c_str(),b.length())

class stringTest : public CxxTest::TestSuite
{
public:
    void test_memcpy_char() {
      char buf[256];
      sdk::gepro::memcpy(buf,"123",4);
      TS_ASSERT_TEXT(buf,"123")
    }
    void test_memcpy_wchar() {
      wchar_t buf[256];
      sdk::gepro::memcpy(buf, L"123", 4);
      TS_ASSERT_TEXT(buf, L"123")
    }
    void test_memcpy_int() {
      int buf[256];
      int src[]={1,2,3,0};
      sdk::gepro::memcpy(buf,src, 4);
      int r=memcmp(buf,src,sizeof(src));
      TS_ASSERT(r==0)
    }
    void test_append_char() {
      char buf[256]="ABC";
      sdk::gepro::append(buf,3, "123", 3);
      TS_ASSERT_TEXT(buf, "ABC123")
    }
    void test_prepend_char() {
      char buf[256] = "ABC";
      sdk::gepro::prepend(buf, 3, "123", 3);
      TS_ASSERT_TEXT(buf, "123ABC")
    }
    void test_insert_char0() {
      char buf[256] = "ABC";
      sdk::gepro::insert(buf, 3,0, "123", 3);
      TS_ASSERT_TEXT(buf, "123ABC")
    }
    void test_insert_char_1() {
      char buf[256] = "ABC";
      sdk::gepro::insert(buf, 3, 3, "123", 3);
      TS_ASSERT_TEXT(buf, "ABC123")
    }
    void test_insert_char1() {
      char buf[256] = "ABC";
      sdk::gepro::insert(buf, 3,1, "123", 3);
      TS_ASSERT_TEXT(buf, "A123BC")
    }
    void test_insert_char2() {
      char buf[256] = "ABCDEF";
      sdk::gepro::insert(buf, 6, 2, "1234", 4);
      TS_ASSERT_TEXT(buf, "AB1234CDEF")
    }
    void test_insert_wchar0() {
      wchar_t buf[256] = L"ABC";
      sdk::gepro::insert(buf, 3, 0, L"123", 3);
      TS_ASSERT_TEXT(buf, L"123ABC")
    }
    void test_insert_wchar_1() {
      wchar_t buf[256] = L"ABC";
      sdk::gepro::insert(buf, 3, 3, L"123", 3);
      TS_ASSERT_TEXT(buf, L"ABC123")
    }
    void test_insert_wchar1() {
      wchar_t buf[256] = L"ABC";
      sdk::gepro::insert(buf, 3, 1, L"123", 3);
      TS_ASSERT_TEXT(buf, L"A123BC")
    }
    void test_insert_wchar2() {
      wchar_t buf[256] = L"ABCDEF";
      sdk::gepro::insert(buf, 6, 2, L"1234", 4);
      TS_ASSERT_TEXT(buf, L"AB1234CDEF")
    }
    void test_append_wchar() {
      wchar_t buf[256] = L"ABC";
      sdk::gepro::append(buf, 3, L"123", 3);
      TS_ASSERT_TEXT(buf, L"ABC123")
    }
    void test_prepend_wchar() {
      wchar_t buf[256] = L"ABC";
      sdk::gepro::prepend(buf, 3, L"123", 3);
      TS_ASSERT_TEXT(buf, L"123ABC")
    }
    void test_wstrchr() {
      const wchar_t* q=L"ìšèøžýáíéúù";
      const wchar_t* f=strchr(q,L'ž');
      TS_ASSERT(f);
      size_t l=f-q;
      TS_ASSERT_EQUALS(l, (size_t)4)
      f=strrchr(q,L'ž');
      TS_ASSERT(f);
      l=f-q;
      TS_ASSERT_EQUALS(l, (size_t)4)
    }
    void test_wstrcmp() {
      const wchar_t* q=L"ìšèøžýáíéúù";
      const wchar_t* t=L"ìšèøž";
      int r=strcmp(q,t);
      TS_ASSERT_EQUALS(r,1)
      r=strcmp(t,q);
      TS_ASSERT_EQUALS(r,-1)
      r=strcmp(t,t);
      TS_ASSERT_EQUALS(r,0)
    }
    void test_wstricmp() {
      const wchar_t* q=L"ìšèøžýáíéúù";
      const wchar_t* t=L"ÌŠÈØŽ";
      int r=stricmp(q,t);
      TS_ASSERT_EQUALS(r,1)
      r=stricmp(t,q);
      TS_ASSERT_EQUALS(r,-1)
      r=stricmp(t,t);
      TS_ASSERT_EQUALS(r,0)
    }
    void test_wstrlen() {
      const wchar_t* t=L"ÌŠÈØŽ";
      const size_t l=strlen(t);
      TS_ASSERT_EQUALS(l, (size_t)5)
    }
    void test_wstrtod() {
      const wchar_t* t=L"1.23,";
      double l=strtod(t,(wchar_t** )&t);
      TS_ASSERT_EQUALS(l,1.23)
      TS_ASSERT_EQUALS(*t,',')
    }
    void test_wstrtol() {
      const wchar_t* t=L"-123,";
      int l=strtol(t, (wchar_t**)&t,10);
      TS_ASSERT_EQUALS(l,-123)
      TS_ASSERT_EQUALS(*t,',')
    }
    void test_wstrtoul() {
      const wchar_t* t=L"123,";
      unsigned l=strtoul(t, (wchar_t**)&t,10);
      TS_ASSERT_EQUALS(l,(unsigned)123)
      TS_ASSERT_EQUALS(*t,',')
    }
    void test_assign() {
      cz::gepro::constcharsi a1("abcde");
      cz::gepro::constcharsi a2("abcde",4);
      TS_ASSERT_EQUALS(a1.size(),(size_t)5)
      TS_ASSERT_EQUALS(a2.size(), (size_t)4)
      a1.assign("abcde");
      a2.assign("abcde",4);
      TS_ASSERT_EQUALS(a1.size(), (size_t)5)
      TS_ASSERT_EQUALS(a2.size(), (size_t)4)
    }
    void test_assign2() {
      cz::gepro::constcharsi a1("abcde");
      cz::gepro::constcharsi a2("abcde", 4);
      TS_ASSERT_EQUALS(a1.size(), (size_t)5)
      TS_ASSERT_EQUALS(a2.size(), (size_t)4)
      const char* x = "abcde";
      a1.assign(x);
      a2.assign(x, x+4);
      TS_ASSERT_EQUALS(a1.size(), (size_t)5)
      TS_ASSERT_EQUALS(a2.size(), (size_t)4)
      TS_ASSERT(a1.begin()==x)
      TS_ASSERT(a1.end() == x+5)
      TS_ASSERT(a2.begin() == x)
      TS_ASSERT(a2.end() == x + 4)
    }
    void test_comparer() {
      const char* a="abc";
      const char* b="abx";
      int res=cz::gepro::string_compare::compare(a,a,3);
      TS_ASSERT_EQUALS(res,0)
      res=cz::gepro::string_compare::compare(a,b,3);
      TS_ASSERT_EQUALS(res,-1)
      res=cz::gepro::string_compare::compare(b,a,3);
      TS_ASSERT_EQUALS(res,1)
    }
    void test_icomparer() {
      const char* a="abc";
      const char* a2="AbC";
      const char* b="Abx";
      int res=cz::gepro::string_icompare::compare(a,a2,3);
      TS_ASSERT_EQUALS(res,0)
      res=cz::gepro::string_icompare::compare(a,b,3);
      TS_ASSERT_EQUALS(res,-1)
      res=cz::gepro::string_icompare::compare(b,a,3);
      TS_ASSERT_EQUALS(res,1)
    }
    void test_wcomparer() {
      const wchar_t* a=L"abc";
      const wchar_t* b=L"abx";
      int res=cz::gepro::wstring_compare::compare(a,a,3);
      TS_ASSERT_EQUALS(res,0)
      res=cz::gepro::wstring_compare::compare(a,b,3);
      TS_ASSERT_EQUALS(res,-1)
      res=cz::gepro::wstring_compare::compare(b,a,3);
      TS_ASSERT_EQUALS(res,1)
    }
    void test_iwcomparer() {
      const wchar_t* a=L"abc";
      const wchar_t* a2=L"AbC";
      const wchar_t* b=L"Abx";
      int res=cz::gepro::wstring_icompare::compare(a,a2,3);
      TS_ASSERT_EQUALS(res,0)
      res=cz::gepro::wstring_icompare::compare(a,b,3);
      TS_ASSERT_EQUALS(res,-1)
      res=cz::gepro::wstring_icompare::compare(b,a,3);
      TS_ASSERT_EQUALS(res,1)
    }
    void test_constchars() {
      const char* _a="abc";
      const char* _b="abx";
      cz::gepro::constchars a(_a);
      cz::gepro::constchars b(_b);
      TS_ASSERT_EQUALS(a==a,true)
      TS_ASSERT_EQUALS(a==b,false)
      TS_ASSERT_EQUALS(a<b,true)
      TS_ASSERT_EQUALS(a<=b,true)
      TS_ASSERT_EQUALS(a!=b,true)
      TS_ASSERT_EQUALS(a>b,false)
      TS_ASSERT_EQUALS(a>=b,false)

      TS_ASSERT_EQUALS(b==a,false)
      TS_ASSERT_EQUALS(b<a,false)
      TS_ASSERT_EQUALS(b<=a,false)
      TS_ASSERT_EQUALS(b!=a,true)
      TS_ASSERT_EQUALS(b>a,true)
      TS_ASSERT_EQUALS(b>=a,true)
    }
    void test_constchars2() {
      const char* _a="";
      const char* _b="";
      cz::gepro::constchars a(_a);
      cz::gepro::constchars b(_b);
      TS_ASSERT_EQUALS(a==b,true)
      TS_ASSERT_EQUALS(a<b,false)
      TS_ASSERT_EQUALS(a<=b,true)
      TS_ASSERT_EQUALS(a!=b,false)
      TS_ASSERT_EQUALS(a>b,false)
      TS_ASSERT_EQUALS(a>=b,true)
    }
    void test_constchars3() {
      const char* _a="";
      const char* _b="a";
      cz::gepro::constchars a(_a);
      cz::gepro::constchars b(_b);
      TS_ASSERT_EQUALS(a==b,false)
      TS_ASSERT_EQUALS(a<b,true)
      TS_ASSERT_EQUALS(a<=b,true)
      TS_ASSERT_EQUALS(a!=b,true)
      TS_ASSERT_EQUALS(a>b,false)
      TS_ASSERT_EQUALS(a>=b,false)
    }
    void test_constchars4() {
      cz::gepro::constchars a("a");
      cz::gepro::constchars a1("b");
      cz::gepro::constchars a2("c");
      cz::gepro::constchars b("a@b");
      TS_ASSERT_EQUALS(b.starts_with(a), true)
      TS_ASSERT_EQUALS(b.ends_with(a1), true)
      TS_ASSERT_EQUALS(b.ends_with(a2), false)
    }
    void test_constchars_substr() {
      cz::gepro::constchars a("abc@def@xyz");
      cz::gepro::constchars b1=a.substr(0,3);
      cz::gepro::constchars b2 = a.substr(3, 3);
      cz::gepro::constchars b3 = a.substr(8, 3);
      TS_ASSERT_TEXT_CSTR("abc",b1)
      TS_ASSERT_TEXT_CSTR("@de", b2)
      TS_ASSERT_TEXT_CSTR("xyz", b3)
    }
    void test_constwchars() {
      const wchar_t* _a=L"abc";
      const wchar_t* _b=L"abx";
      cz::gepro::constwchars a(_a);
      cz::gepro::constwchars b(_b);
      TS_ASSERT_EQUALS(a==a,true)
      TS_ASSERT_EQUALS(a==b,false)
      TS_ASSERT_EQUALS(a<b,true)
      TS_ASSERT_EQUALS(a<=b,true)
      TS_ASSERT_EQUALS(a!=b,true)
      TS_ASSERT_EQUALS(a>b,false)
      TS_ASSERT_EQUALS(a>=b,false)

      TS_ASSERT_EQUALS(b==a,false)
      TS_ASSERT_EQUALS(b<a,false)
      TS_ASSERT_EQUALS(b<=a,false)
      TS_ASSERT_EQUALS(b!=a,true)
      TS_ASSERT_EQUALS(b>a,true)
      TS_ASSERT_EQUALS(b>=a,true)
    }
    void test_constwchars2() {
      const wchar_t* _a=L"";
      const wchar_t* _b=L"";
      cz::gepro::constwchars a(_a);
      cz::gepro::constwchars b(_b);
      TS_ASSERT_EQUALS(a==b,true)
      TS_ASSERT_EQUALS(a<b,false)
      TS_ASSERT_EQUALS(a<=b,true)
      TS_ASSERT_EQUALS(a!=b,false)
      TS_ASSERT_EQUALS(a>b,false)
      TS_ASSERT_EQUALS(a>=b,true)
    }
    void test_constwchars3() {
      const wchar_t* _a=L"";
      const wchar_t* _b=L"a";
      cz::gepro::constwchars a(_a);
      cz::gepro::constwchars b(_b);
      TS_ASSERT_EQUALS(a==b,false)
      TS_ASSERT_EQUALS(a<b,true)
      TS_ASSERT_EQUALS(a<=b,true)
      TS_ASSERT_EQUALS(a!=b,true)
      TS_ASSERT_EQUALS(a>b,false)
      TS_ASSERT_EQUALS(a>=b,false)
    }
    void test_map() {
      typedef std::map<cz::gepro::constchars,int> str2int;
      str2int m;
      m.insert(str2int::value_type(cz::gepro::constchars("alfa"),1));
      m.insert(str2int::value_type(cz::gepro::constchars("beta"),2));
      m.insert(str2int::value_type(cz::gepro::constchars("gama"),3));
      str2int::const_iterator i=m.find(cz::gepro::constchars("alfa"));
      TS_ASSERT_EQUALS(i->second,1)
      i=m.find(cz::gepro::constchars("gama"));
      TS_ASSERT_EQUALS(i->second,3)
      i=m.find(cz::gepro::constchars("beta"));
      TS_ASSERT_EQUALS(i->second,2)
      i=m.find(cz::gepro::constchars("delta"));
      TS_ASSERT_EQUALS(i,m.end())
    }
    void test_mapi() {
      typedef std::map<cz::gepro::constcharsi,int> str2int;
      str2int m;
      m.insert(str2int::value_type(cz::gepro::constcharsi("alfa"),1));
      m.insert(str2int::value_type(cz::gepro::constcharsi("beta"),2));
      m.insert(str2int::value_type(cz::gepro::constcharsi("gama"),3));
      str2int::const_iterator i=m.find(cz::gepro::constcharsi("ALFA"));
      TS_ASSERT_EQUALS(i->second,1)
      i=m.find(cz::gepro::constcharsi("Gama"));
      TS_ASSERT_EQUALS(i->second,3)
      i=m.find(cz::gepro::constcharsi("Beta"));
      TS_ASSERT_EQUALS(i->second,2)
      i=m.find(cz::gepro::constcharsi("Delta"));
      TS_ASSERT_EQUALS(i,m.end())
    }

};


#endif // __TEST_H

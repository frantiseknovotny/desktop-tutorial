#ifndef __TEST_SMARTBUFS_H
#define __TEST_SMARTBUFS_H

/* vzor pro odvozeni dalsich testu - nemodifikovat 
   http://build2.gepro:8088/sdk/docs/cxxtext/modules.html
*/
using namespace cz::gepro::vtoa::simple;
#define PAGELEN 0xffffff00
#define __(x) (const char*)x
#define IMG_ERASE "<img />"
#define IMG_MAPA "<img mapa/>"
#define ERASE 1
#define MAP_VOKAL 1
class HrefPage_gms {
    cz::gepro::tstatbuf<1024> buf;
  public:
    HrefPage_gms(int _flags,int _methode,int _action,int _id) {
        buf << "href='Page?gms,0,";
        buf << (_flags&(~PAGELEN));
        buf << "," << _methode << "," << _action << "," << _id << "'";
    }
    operator const char*() const {return buf.begin();}
    size_t len() const {return buf.size();}
};
template <class S>
class HrefPage_gms2 {
  public:
    typedef S ostream;
    HrefPage_gms2(ostream& o,int _flags,int _methode,int _action,int _id) {
        o << "href='Page?gms,0," << (_flags&(~PAGELEN)) << "," << _methode << "," << _action << "," << _id << "'";
    }
};
class ActionDelete {
    cz::gepro::tstatbuf<1024> buf;
  public:
    ActionDelete(int _flags,int _methode,int _id) {
      buf << "&nbsp;<a " << (const char*)HrefPage_gms(_flags,_methode,ERASE,_id);
      buf << " onClick=' confirm(\"" << __("Naozaj chcete?") << "\\n" << __("Tato nevratna!") <<"\")'";
      buf << " title='" << __("vyradit") << "'>";
      buf << IMG_ERASE << "</a>";
    }
    operator const char*() const {return buf.begin();}
    size_t len() const {return buf.size();}
};
// generovani URL pro zobrazeni do MAPY
template <class S>
class _UrlGen_Mapa {
  public:
    typedef S ostream;
    _UrlGen_Mapa(ostream& o,int _flags,const char* _desc,int _id,int _action=1) {
        //"href='Mapa?show,%d,%s,%d,%ld'",flags&(~PAGELEN),desc,SHOW_MAP_OBJEKT,ptr->ID);
        o << "Mapa?show" << (_flags&(~PAGELEN)) << "," << _desc << "," << _action << "," << _id;
    }
};
template <class S>
class _UrlGen_Mapa_JS {
  public:
    typedef S ostream;
    _UrlGen_Mapa_JS(ostream& o,const char* _psp,int _id) {
        //"OnClick=\"opener.top.App.Query(4,'','','M','','GR\\nICNR\\nAND\\nGR\\nILAY\\tPspHrbit\\nAND\\nGR\\nIINF\\tY=%ld\\nAND',6);opener.top.GRF.focus();return false;\""
        o << "OnClick=\"opener.top.App.Query(4,'','','M','','GR\\nICNR\\nAND\\nGR\\nILAY\\t" << _psp << "\\nAND\\nGR\\nIINF\\tY=" << _id << "\\nAND',6);opener.top.GRF.focus();return false;\"";
    }
};
template <class S>
class _href_Mapa {
  public:
    typedef S ostream;
    _href_Mapa(ostream& o,const char* _psp,int _flags,const char* _desc,int _id,int _action=1) {
      if(_flags&MAP_VOKAL) {
         //"href='#' OnClick=\"opener.top.App.Query(4,'','','M','','GR\\nICNR\\nAND\\nGR\\nILAY\\tPspHrbit\\nAND\\nGR\\nIINF\\tY=%ld\\nAND',6);opener.top.GRF.focus();return false;\"",ptr->ID);
         o << "href='#'";
         _UrlGen_Mapa_JS<ostream>(o,_psp,_id);
      } else {
         //"href='Mapa?show,%d,%s,1,%ld'",flags&(~PAGELEN),desc,ptr->ID);
         o << "href='";
         _UrlGen_Mapa<ostream>(o,_flags,_desc,_id,_action);
         o << "'";
      }    
    }
};
template <class S>
class _a_Mapa {
  public:
    typedef S ostream;
    _a_Mapa(ostream& o,const char* _psp,const char* _title,int _flags,const char* _desc,int _id,int _action=1) {
      o << "&nbsp;&nbsp;<a ";
      _href_Mapa<ostream>(o,_psp,_flags,_desc,_id,_action);
      o << " title='" << _title << "'>";
      o << IMG_MAPA;
      o << "</a>"; 
    }
};
/*
          char desc[1024];
          sprintf(desc,"hrobové místo: %s",(const char*)ptr->hrob_c);
          char* cptr=desc;
          while (cptr=strchr(cptr,',')) *cptr++=';';
          char tmpbuf[1024];
          if (flags&MAP_VOKAL) {
             sprintf(tmpbuf,"href='#' OnClick=\"opener.top.App.Query(4,'','','M','','GR\\nICNR\\nAND\\nGR\\nILAY\\tPspHrbit\\nAND\\nGR\\nIINF\\tY=%ld\\nAND',6);opener.top.GRF.focus();return false;\"",ptr->ID);
          } else {
             sprintf(tmpbuf,"href='Mapa?show,%d,%s,1,%ld'",flags&(~PAGELEN),desc,ptr->ID);
          }
          len+=sprintf(databuf+len,"&nbsp;&nbsp;<a %s TITLE='ukázat v mapì'>%s</a>",tmpbuf,IMG_MAPA);
*/          
template <class D>
class Operators {
  public:
    typedef D Derived;
    Derived& This() {return (Derived&)*this;}
    Derived& operator<<(int i) {
      This().put(i);
      return *this;
    }
};

namespace cz {
  namespace gepro {
    // adapter pro std::string
    template <>
    struct string_iface<std::string> {
      typedef std::string string_type;
      typedef string_type::value_type char_type;
      typedef cz::gepro::STLifacestring<string_type, char_type> iface;
    };
#if _MSC_VER>1200
    template <>
    struct string_iface2<std::string> {
      typedef std::string string_type;
      typedef string_type::value_type char_type;
      typedef cz::gepro::STLifacestring2<string_type, char_type> iface;
    };
    template <>
    struct string_iface2<std::wstring> {
      typedef std::wstring string_type;
      typedef wchar_t char_type;
      typedef cz::gepro::STLifacestring2<string_type, char_type> iface;
    };
#endif
  };//ns gepro
};//ns cz

/** Testy pro smart buffer
*/
class smartbufsTest : public CxxTest::TestSuite
{
public:
    /** Test omezení bufferu pro delší string.
    */
    void test_examples_0() {
      typedef cz::gepro::tstatbuf<256> pathbuf;
      pathbuf buf;
      std::string s("pocet=");
      buf << s << 10;
      TS_ASSERT_TEXT(buf.begin(),"pocet=10")  // buffer je dost velkı
      cz::gepro::tstatbuf<4> buf2;
      buf2 << "pocet=" << 10;
      TS_ASSERT_TEXT(buf2.begin(),"poc")  // buffer je krátkı na celı poadovanı vıstup
    }
    void test_setcapacity_0() {
      typedef cz::gepro::tstatbuf<256> pathbuf;
      pathbuf buf;
      buf << "pocet=" << 10;
      TS_ASSERT_TEXT(buf.begin(),"pocet=10")  // buffer je dost velkı
      buf.setcapacity(4);
      TS_ASSERT_TEXT(buf.begin(),"poc")  // buffer je krátkı na celı poadovanı vıstup
    }
    void test_setcapacity_1() {
      typedef cz::gepro::tstatbuf<256> pathbuf;
      pathbuf buf;
      buf.setcapacity(4);
      buf << "pocet=" << 10;
      TS_ASSERT_TEXT(buf.begin(),"poc")  // buffer je krátkı na celı poadovanı vıstup
    }
    void test_1() {
      typedef cz::gepro::tstatbuf<256> pathbuf;
      pathbuf buf;
      buf << "pocet" << (char)'=' << 10;
      TS_ASSERT_TEXT(buf.begin(),"pocet=10")  // buffer je dost velkı
    }
    void test_2() {
      typedef cz::gepro::tstatbufe<256> pathbuf;
      pathbuf buf;
      buf << "pocet" << (char)'=' << 10;
      TS_ASSERT_TEXT(buf.begin(),"pocet=10")  // buffer je dost velkı
    }
    void test_void_NULL() {
      cz::gepro::tstatbuf<32> b;
      int id=1024;
      int action=1;
      b << "Page?gms," << id << "," << action;
      TS_ASSERT_EQUALS(b.size(),(size_t)15)
      TS_ASSERT_SAME_DATA(b.begin(),"Page?gms,1024,1",16) 
    }
    void test_HrefPage_gms2() {
      cz::gepro::tstatbuf<1024> b;
      HrefPage_gms2<cz::gepro::tstatbuf<1024> > _b(b,1,2,3,4);
      TS_ASSERT_EQUALS(b.size(), (size_t)25)
      TS_ASSERT_SAME_DATA(b.begin(),"href='Page?gms,0,1,2,3,4'",26) 
    }
    void test_HrefPage_gms() {
      HrefPage_gms b(1,2,3,4);
      TS_ASSERT_EQUALS(b.len(),(size_t)25)
      TS_ASSERT_SAME_DATA((const char*)b,"href='Page?gms,0,1,2,3,4'",26) 
    }
    void test_ActionDelete() {
      ActionDelete b(1,2,3);
      char result[]="&nbsp;<a href='Page?gms,0,1,2,1,3' onClick=' confirm(\"Naozaj chcete?\\nTato nevratna!\")' title='vyradit'><img /></a>";
      _DUMP((const char*)b)
      TS_ASSERT_EQUALS(b.len(),strlen(result))
      TS_ASSERT_SAME_DATA((const char*)b,result,b.len()+1) 
    }
    void test_a_Mapa() {
      cz::gepro::tstatbuf<1024> b;
      _a_Mapa<cz::gepro::tstatbuf<1024> >(b,"PspHrbit","title",0,"desc",1,1);
      _DUMP((const char*)b.begin())
      char result[]="&nbsp;&nbsp;<a href='Mapa?show0,desc,1,1' title='title'><img mapa/></a>";
      TS_ASSERT_EQUALS(b.size(),strlen(result))
      TS_ASSERT_SAME_DATA(b.begin(),result,b.size()+1) 
    }
    void test_a_Mapa_Vokal() {
      cz::gepro::tstatbuf<1024> b;
      _a_Mapa<cz::gepro::tstatbuf<1024> >(b,"PspHrbit","title",MAP_VOKAL,"desc",1,1);
      _DUMP((const char*)b.begin())
      char result[]="&nbsp;&nbsp;<a href='#'OnClick=\"opener.top.App.Query(4,'','','M','','GR\\nICNR\\nAND\\nGR\\nILAY\\tPspHrbit\\nAND\\nGR\\nIINF\\tY=1\\nAND',6);opener.top.GRF.focus();return false;\" title='title'><img mapa/></a>";
      TS_ASSERT_EQUALS(b.size(),strlen(result))
      TS_ASSERT_SAME_DATA(b.begin(),result,b.size()+1) 
    }
    void test_capitalize() {
      cz::gepro::tstatbuf<1024> b;
      b << "velka pismena";
      b.capitalize();
      char result[]="Velka Pismena";
      TS_ASSERT_EQUALS(b.size(),strlen(result))
      TS_ASSERT_SAME_DATA(b.begin(),result,b.size()+1) 
    }
    void test_capitalize2() {
      cz::gepro::tstatbuf<1024> b;
      b.capitalize();
      char result[]="";
      TS_ASSERT_EQUALS(b.size(),strlen(result))
      TS_ASSERT_SAME_DATA(b.begin(),result,b.size()+1) 
    }
    void test_capitalize3() {
      cz::gepro::tstatbuf<1024> b;
      b << "1 koruna";
      b.capitalize();
      char result[]="1 Koruna";
      TS_ASSERT_EQUALS(b.size(),strlen(result))
      TS_ASSERT_SAME_DATA(b.begin(),result,b.size()+1) 
    }

    void test_stringbuf() {
      typedef cz::gepro::tstringbuf<std::string,4,char> strbuf;
      strbuf buf;
      buf+="12";
      TS_ASSERT_EQUALS(buf.size(),(size_t)2)
      buf+="34";
      TS_ASSERT_EQUALS(buf.size(), (size_t)4)
      buf+="567";
      TS_ASSERT_EQUALS(buf.size(), (size_t)7)
      buf+="890";
      TS_ASSERT_EQUALS(buf.size(), (size_t)10)
      TS_ASSERT_TEXT(buf.begin(),"1234567890")
    }
    void test_stringbuf2() {
      typedef cz::gepro::tstringbuf<std::string,4> strbuf;
      strbuf buf;
      buf+="1234";
      TS_ASSERT_EQUALS(buf.size(), (size_t)4)
      std::string s("567890");
      buf << s;
      TS_ASSERT_EQUALS(buf.size(), (size_t)10)
      TS_ASSERT_TEXT(buf.begin(),"1234567890")
      buf << 256;
      _DUMP(buf.begin())
      TS_ASSERT_TEXT(buf.begin(),"1234567890256")
      buf << 2.56;
      TS_ASSERT_TEXT(buf.begin(),"12345678902562.56")
      buf << (char)' ';
      buf << (unsigned)0x100;
      TS_ASSERT_TEXT(buf.begin(),"12345678902562.56 256")

    }
    void test_stringbuf3() {
      typedef cz::gepro::tstringbuf<std::string,4> strbuf;
      strbuf buf;
      buf+="1234";
      TS_ASSERT_EQUALS(buf.size(), (size_t)4)
      buf << (const char*)NULL;
      TS_ASSERT_EQUALS(buf.size(), (size_t)4)
    }
    void test_stringbuf_strcpy() {
      typedef cz::gepro::tstringbuf<std::string,4> strbuf;
      strbuf buf;
      strcpy(buf,"12345678");
      TS_ASSERT_EQUALS(buf.size(), (size_t)8)
      strcat(buf,"90");
      TS_ASSERT_EQUALS(buf.size(), (size_t)10)
      TS_ASSERT_TEXT(buf.begin(),"1234567890")
    }
    void test_statbuf_strcpy() {
      cz::gepro::tstatbuf<4> buf;
      strcpy(buf,"abcd");
      TS_ASSERT_TEXT(buf.begin(),"abcd")
      strcpy(buf,"123456");
      TS_ASSERT_TEXT(buf.begin(),"1234")
    }
    /** Test generování vıjimky pøi textu delším ne je velikost bufferu
    */
    void test_statbuf_exception() {
      cz::gepro::tstatbufe<4> buf;
      strcpy(buf,"abcd");
      TS_ASSERT_TEXT(buf.begin(),"abcd")
      try {
        strcpy(buf,"123456");
      } catch(cz::gepro::small_buffer& e) {
        TS_ASSERT_TEXT(e.what(),"small buffer")
        TS_ASSERT_TEXT(buf.begin(),"1234")
      }
    }
    void test_stringbuf_double() {
      typedef cz::gepro::tstringbuf<std::string,256> strbuf;
      strbuf buf;
      buf << 11.1;
      TS_ASSERT_TEXT(buf.begin(),"11.1")
    }
    void test_tstatbufe_double_big() {
      typedef cz::gepro::tstatbufe<256> strbuf;
      strbuf buf;
      buf <<  1068110.11;
      TS_ASSERT_TEXT(buf.begin(),"1068110.11")
    }
    void test_kokpoint() {
      cz::gepro::tstatbufe<256> buf;
      cz::gepro::point v(1212345.678,12345678.1);
      buf << v.X << "," << v.Y;
      const char* val=buf.begin();  
      TS_ASSERT_TEXT(val,"1212345.678,12345678.1")
    }
    void test_stringbuf_DWORD() {
      typedef cz::gepro::tstringbuf<std::string,256> strbuf;
      strbuf buf;
      DWORD v=1111;
      buf << (unsigned long)v;
      TS_ASSERT_TEXT(buf.begin(),"1111")
    }
    void test_stringbuf_bigdata() {
      typedef cz::gepro::tstringbuf<std::string,4096> strbuf;
      strbuf o;
      FILE* in=fopen(cxxAdjustToExeDir("\\testdata\\ostream.dat"),"rt");
      while(!feof(in)) {
        char buf[1024];
        fgets(buf,sizeof(buf),in);
        char* q=strchr(buf,'\n');
        if(q) *q='\0';
//        _DUMP(buf)
        o+=buf;
      }
      FILE* out=fopen(cxxAdjustToExeDir("\\testdata\\out1_ostream.dat"),"wt");
      fputs(o.begin(),out);
      fclose(out);
      std::string f1=cxxAdjustToExeDir("\\testdata\\out1_ostream.dat");
      std::string f2=cxxAdjustToExeDir("\\testdata\\out_ostream.dat");
      TS_ASSERT_EQUALS(cmpfile(f1.c_str()),cmpfile(f2.c_str()))
    }
    void test_stringbuf_bigdata2() {
      typedef cz::gepro::tstringbuf<std::string,4096> strbuf;
      strbuf o;
      FILE* in=fopen(cxxAdjustToExeDir("\\testdata\\ostream.dat"),"rt");
      while(!feof(in)) {
        char buf[1024];
        fgets(buf,sizeof(buf),in);
        char* q=strchr(buf,'\n');
        if(q) *q='\0';
//        _DUMP(buf)
        o << buf;
      }
      FILE* out=fopen(cxxAdjustToExeDir("\\testdata\\out2_ostream.dat"),"wt");
      fputs(o.begin(),out);
      fclose(out);
      std::string f1=cxxAdjustToExeDir("\\testdata\\out2_ostream.dat");
      std::string f2=cxxAdjustToExeDir("\\testdata\\out_ostream.dat");
      TS_ASSERT_EQUALS(cmpfile(f1.c_str()),cmpfile(f2.c_str()))
    }
    void test_Hex() {
      cz::gepro::tstatbuf<64> l,i,s,c;
      l << cz::gepro::Hex((__int64)10);
      i << cz::gepro::Hex(10);
      s << cz::gepro::Hex((short)10);
      c << cz::gepro::Hex((char)10);
      TS_ASSERT_TEXT(l.begin(),"000000000000000a")
      TS_ASSERT_TEXT(i.begin(),        "0000000a")
      TS_ASSERT_TEXT(s.begin(),            "000a")
      TS_ASSERT_TEXT(c.begin(),              "0a")
    }
    void test_lower() {
      cz::gepro::tstatbuf<10> buf;
      buf << "AbCDeF";
      buf.lower();
      TS_ASSERT_TEXT(buf.begin(),"abcdef")
    }
    void test_upper() {
      cz::gepro::tstatbuf<10> buf;
      buf << "AbCDeF";
      buf.upper();
      TS_ASSERT_TEXT(buf.begin(),"ABCDEF")
    }
    void test_fill() {
      cz::gepro::tstatbuf<10> buf("1");
      buf.assign(5,'A');
      TS_ASSERT_TEXT(buf.begin(),"AAAAA")
    }
    void test_assign() {
      cz::gepro::tstatbuf<10> buf("1");
      buf.assign("AAAAA",5);
      TS_ASSERT_TEXT(buf.begin(),"AAAAA")
    }
    void test_assign_s() {
      cz::gepro::tstatbuf<10> buf("1");
      buf.assign(std::string("AAAAA"));
      TS_ASSERT_TEXT(buf.begin(),"AAAAA")
    }
    void test_append() {
      cz::gepro::tstatbuf<10> buf("1");
      buf.append("AAAAA",5);
      TS_ASSERT_TEXT(buf.begin(),"1AAAAA")
    }
    void test_append_s() {
      cz::gepro::tstatbuf<10> buf("1");
      buf.append(std::string("AAAAA"));
      TS_ASSERT_TEXT(buf.begin(),"1AAAAA")
    }
    void test_fillw() {
      cz::gepro::tstatbuf<10,wchar_t> buf;
      buf.assign(5,'A');
      TS_ASSERT_TEXT(buf.begin(),L"AAAAA")
    }
    void test_assignw() {
      cz::gepro::tstatbuf<10,wchar_t> buf;
      buf.assign(L"AAAAA",5);
      TS_ASSERT_TEXT(buf.begin(),L"AAAAA")
    }
    void test_assignw_s() {
      cz::gepro::tstatbuf<10,wchar_t> buf;
      buf.assign(std::wstring(L"AAAAA"));
      TS_ASSERT_TEXT(buf.begin(),L"AAAAA")
    }
    void test_trim_0() {
      cz::gepro::tstatbuf<16> buf;
      buf << "0123456789ABCDE";
      const char* q=buf.c_str();
      buf.trimr(12,"..");
      q=buf.c_str();
      TS_ASSERT_TEXT(q,"0123456789..")
    }
    void test_trimtstringbuf0() {
      cz::gepro::tstringbuf<std::string,8> buf;
      buf << "0123456789ABCDE";
      const char* q;
      buf.trimr(12,"..");
      q=buf.c_str();
      TS_ASSERT_TEXT(q,"0123456789..")
    }
    void test_trimtstringbuf1() {
      cz::gepro::tstringbuf<std::string,8> buf;
      buf << "0123456789";
      const char* q;
      buf.trimr(9,"..");
      q=buf.c_str();
      TS_ASSERT_TEXT(q,"0123456..")
    }
    void test_trimtstringbuf2() {
      cz::gepro::tstringbuf<std::string,8> buf;
      buf << "0123456789ABC";
      const char* q;
      buf.trimr(12,"..");
      q=buf.c_str();
      TS_ASSERT_TEXT(q,"0123456789..")
    }
    void test_AddTokens0() {
      cz::gepro::tstringbuf2<std::string,8> buf;
      buf.AddTokens("AB,CD",5,',');
      const char* q=buf.c_str();
      TS_ASSERT_TEXT(q,"AB")
      q+=3;
      TS_ASSERT_TEXT(q,"CD")
      q+=3;
      TS_ASSERT_TEXT(q,"")
    }
    void test_AddTokens1() {
      cz::gepro::tstringbuf2<std::string,8> buf;
      buf.AddTokens("AB,CD,EF,GH,IJ,KL,MN",20,',');
      const char* q=buf.c_str();
      TS_ASSERT_TEXT(q,"AB")
      q+=3;
      TS_ASSERT_TEXT(q,"CD")
      q+=3;
      TS_ASSERT_TEXT(q,"EF")
      q+=3;
      TS_ASSERT_TEXT(q,"GH")
      q+=3;
      TS_ASSERT_TEXT(q,"IJ")
      q+=3;
      TS_ASSERT_TEXT(q,"KL")
      q+=3;
      TS_ASSERT_TEXT(q,"MN")
      q+=3;
      TS_ASSERT_TEXT(q,"")
    }
    void test_AddTokens2() {
      cz::gepro::tstringbuf2<std::string,8> buf;
      buf.AddTokens("AB,CD,EF,GH,IJ,KL,MN",20,',','|');
      const char* q=buf.c_str();
      TS_ASSERT_TEXT(q,"AB|CD|EF|GH|IJ|KL|MN||");
    }
    void test_AddTokens3() {
      cz::gepro::tstringbuf2<std::string, 4> buf;
      buf.AddTokens("AB,CD,EF,GH,IJ,KL,MN", 20, ',', '|');
      const char* q = buf.c_str();
      TS_ASSERT_TEXT(q, "AB|CD|EF|GH|IJ|KL|MN||");
    }
    void test_append_if_not() {
      cz::gepro::tstringbuf<std::string, 4> a, b;
      a << "abc";
      b << "abc/";
      a.append_if_not('/');
      b.append_if_not('/');
      TS_ASSERT_EQUALS(a.size(), b.size())
        TS_ASSERT_SAME_DATA(a.c_str(), b.c_str(), a.size())
    }
    void test_append_if_not2() {
      cz::gepro::tstringbuf2<std::string, 4> a,b;
      a << "abc";
      b << "abc/";
      a.append_if_not('/');
      b.append_if_not('/');
      TS_ASSERT_EQUALS(a.size(), b.size())
      TS_ASSERT_SAME_DATA(a.c_str(),b.c_str(),a.size())
    }
    void test_append_if_not3() {
      cz::gepro::tstatbuf<6> a, b;
      a << "abc";
      b << "abc/";
      a.append_if_not('/');
      b.append_if_not('/');
      TS_ASSERT_EQUALS(a.size(), b.size())
      TS_ASSERT_SAME_DATA(a.c_str(), b.c_str(), a.size())
    }
    void test_append_if_not4() {
      std::tstringbuf<4, std::string, cz::gepro::STLifacestring<std::string, char>> a, b;
      a << "abc";
      b << "abc/";
      a.append_if_not('/');
      b.append_if_not('/');
      TS_ASSERT_EQUALS(a.size(), b.size())
        TS_ASSERT_SAME_DATA(a.c_str(), b.c_str(), a.size())
    }
    void test_append_if_not5() {
      std::tstatbuf<6> a, b;
      a << "abc";
      b << "abc/";
      a.append_if_not('/');
      b.append_if_not('/');
      TS_ASSERT_EQUALS(a.size(), b.size())
        TS_ASSERT_SAME_DATA(a.c_str(), b.c_str(), a.size())
    }
    void test_cesky() {
      cz::gepro::tstatbuf<256> a;
      a << "ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ";
      a.cesky();
      TS_ASSERT_TEXT(a.c_str(), "escrzyaieuudtnESCRZYAIEUUDTN")
    }
    void test_cesky_str() {
      cz::gepro::tstringbuf2<std::string, 24> a;
      a << "ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ";
      a.cesky();
      TS_ASSERT_TEXT(a.c_str(), "escrzyaieuudtnESCRZYAIEUUDTN")
    }
    void test_constchars0() {
      cz::gepro::tstatbuf<256> o;
      cz::gepro::constchars a("ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ");
      cz::gepro::constcharsi b("ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ");
      o << a << "|" << b;
      TS_ASSERT_TEXT(o.c_str(), "ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ|ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ")
    }
    void test_constwchars0() {
      cz::gepro::tstatbuf<256,wchar_t> o;
      cz::gepro::constwchars a(L"ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ");
      cz::gepro::constwcharsi b(L"ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ");
      o << a << L"|" << b;
      TS_ASSERT_TEXT(o.c_str(), L"ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ|ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ")
    }
    void test_constchars1() {
      cz::gepro::tstringbuf2<std::string, 24> o;
      cz::gepro::constchars a("ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ");
      cz::gepro::constcharsi b("ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ");
      o << a << "|" << b;
      TS_ASSERT_TEXT(o.c_str(), "ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ|ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ")
    }
    void test_constwchars1() {
      cz::gepro::tstringbuf2<std::wstring, 24, wchar_t> o;
      cz::gepro::constwchars a(L"ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ");
      cz::gepro::constwcharsi b(L"ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ");
      o << a << L"|" << b;
      TS_ASSERT_TEXT(o.c_str(), L"ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ|ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ")
    }

    void test_constchars2() {
      cz::gepro::tstringbuf<std::string, 24> o;
      cz::gepro::constchars a("ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ");
      cz::gepro::constcharsi b("ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ");
      o << a << "|" << b;
      TS_ASSERT_TEXT(o.c_str(), "ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ|ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ")
    }
    void test_constwchars2() {
      cz::gepro::tstringbuf<std::wstring, 24, wchar_t> o;
      cz::gepro::constwchars a(L"ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ");
      cz::gepro::constwcharsi b(L"ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ");
      o << a << L"|" << b;
      TS_ASSERT_TEXT(o.c_str(), L"ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ|ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ")
    }
    void test_constchars3() {
      cz::gepro::xstringbuf2<24, std::string> o;
      cz::gepro::constchars a("ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ");
      cz::gepro::constcharsi b("ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ");
      o << a << "|" << b;
      TS_ASSERT_TEXT(o.c_str(), "ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ|ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ")
    }
    void test_constwchars3() {
      cz::gepro::xstringbuf2<24,std::wstring> o;
      cz::gepro::constwchars a(L"ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ");
      cz::gepro::constwcharsi b(L"ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ");
      o << a << L"|" << b;
      TS_ASSERT_TEXT(o.c_str(), L"ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ|ìšèøıáíéúùïòÌŠÈØİÁÍÉÚÙÏÒ")
    }
};


#endif // __TEST_H

#ifndef __TEST_STDFORMAT_H
#define __TEST_STDFORMAT_H

/* vzor pro odvozeni dalsich testu - nemodifikovat */

class Test_STDFORMAT : public CxxTest::TestSuite
{
public:
    typedef std::tstringbuf<256,std::string,cz::gepro::STLifacestring<std::string,char> > ostream;
    
    void test_variant_format_formater() {
      _DUMP("test_variant_format_formater\n")
      ostream buf;
      cz::gepro::variant_format_formater<ostream> ff(buf);

      cz::gepro::variant_format f;
      f=cz::gepro::baseformat(std::ios::hex);
      buf << 100 << std::endl;
      boost::apply_visitor(ff,f);
      buf << 100 << std::endl;
      ff.reset();
      buf << 100 << std::endl;
      _DUMP(buf.begin());
      TS_ASSERT_TEXT(buf.begin(),"100\n64\n100\n")
    }
    void test_export_variant() {
      _DUMP("test_export_variant\n")
      cz::gepro::variant v((int)19);
      cz::gepro::variant_format f;
      ostream buf;
      typedef cz::gepro::export_variant<ostream> e;
      e::value(buf,v,f);
      buf << std::endl;
      e::pair(buf,"dec",v,f);
      buf << std::endl;
      f=cz::gepro::baseformat(std::ios::hex);
      e::attribute(buf,"hexa",v,f);
      buf << std::endl;
      _DUMP(buf.begin());
      static char ok[]="19\ndec=19\n hexa=\"13\"\n";
      TS_ASSERT_TEXT(buf.begin(),ok)
    }
    void test_export_variant2() {
      _DUMP("test_export_variant2\n")
      int a=11;
      cz::gepro::variant2 v(&a);
      cz::gepro::variant_format f;
      ostream buf;
      typedef cz::gepro::export_variant<ostream,cz::gepro::variant2> e;
      e::value(buf,v,f);
      buf << std::endl;
      e::pair(buf,"dec",v,f);
      buf << std::endl;
      f=cz::gepro::baseformat(std::ios::hex);
      a=255;
      e::attribute(buf,"hexa",v,f);
      buf << std::endl;
      _DUMP(buf.begin());
      static char ok[]="11\ndec=11\n hexa=\"ff\"\n";
      TS_ASSERT_TEXT(buf.begin(),ok)
    }
    class MyDataSet:public cz::gepro::TIDataImplMap<const char*,cz::gepro::IData::value_type> {
      public:
        MyDataSet() {
          insert("index_0",1);
          insert("index_1",3.14);
          insert("index_2","txt");
          insert("index_3",100);
        }
    };
    class MyDataRows:public cz::gepro::IDataRows {
      public:
        typedef data_row::value_type value_type;
        typedef std::vector<value_type> values_type;
        class MyRow:public cz::gepro::IDataRows::data_row {
          public:
            values_type values;
            value_type dummy;
            virtual const value_type& GetValue(size_t i) {
              if(i>=values.size()) return dummy; // throw !
              return values[i];
            }
        };
        typedef std::vector<MyRow> vector_rows;
        vector_rows rows;
        virtual size_t GetCntRows() {return rows.size();}
        virtual data_row* GetDataRow(size_t i) {
          if(i>=rows.size()) return NULL; // throw !
          return &rows[i];
        }
        virtual const char_type* GetName() {return "mydata";}
        virtual size_t GetCount() {
          if(!rows.size()) return 0;
          return rows[0].values.size();
        }
        virtual const char_type* GetId(size_t i) {
          static cz::gepro::tstatbuf<64> buf;
          buf.clear();
          buf << "index_" << i;
          return buf.begin();
        }
        virtual size_t GetIndex(const char_type* id) {
          if(!strcmp("index_0",id)) return 0;
          if(!strcmp("index_1",id)) return 1;
          if(!strcmp("index_2",id)) return 2;
          if(!strcmp("index_3",id)) return 3;
          return 0;
        }
        MyDataRows() {
          {
            MyRow r;
            r.values.push_back(1);
            r.values.push_back(3.14);
            r.values.push_back("txt");
            r.values.push_back(100);
            rows.push_back(r);
          }
          {
            MyRow r;
            r.values.push_back(10);
            r.values.push_back(30.14);
            r.values.push_back("txt2");
            r.values.push_back(1000);
            rows.push_back(r);
          }
        }
    };
    class MyDataSet2:public cz::gepro::TIDataImplMap<const char*,cz::gepro::IData2::value_type> {
      public:
        MyDataSet2() {
          insert("index_0",1);
          insert("index_1",3.14);
          insert("index_2","txt");
          insert("index_3",100);
        }
    };


    #ifdef SDK_ON_FRANTA_PC
    class MyDataFormat1:public cz::gepro::TIDataImplMap<const char*,cz::gepro::variant_format> {
      public:
        MyDataFormat1() {
          insert("index_0",cz::gepro::noneformat());
          insert("index_1",cz::gepro::noneformat());
          insert("index_2",cz::gepro::noneformat());
          insert("index_3",cz::gepro::baseformat(std::ios::hex));
        }
    };
    #endif
   class MyDataFormat:public cz::gepro::IDataFormat {
      public:
        typedef std::vector<cz::gepro::IDataFormat::value_type> values_type;
        values_type values;
        cz::gepro::IDataFormat::value_type dummy;
        virtual const value_type& GetValue(size_t i) {
          if(i>=values.size()) return dummy; // throw !
          return values[i];
        }
        MyDataFormat() {
          values.push_back(cz::gepro::noneformat());
          values.push_back(cz::gepro::noneformat());
          values.push_back(cz::gepro::noneformat());
          values.push_back(cz::gepro::baseformat(std::ios::hex));
        }

    };
    void test_MyDataSet_attribute() {
      _DUMP("test_MyDataSet_attribute\n")
      ostream buf;
      cz::gepro::variant_format f;
      typedef cz::gepro::export_variant<ostream,cz::gepro::variant2> e;
      MyDataSet data;
      for(size_t i=0;i<data.GetCount();i++) {
        e::attribute(buf,data.GetId(i),data.GetValue(i),f);
        buf << std::endl;
      }
      _DUMP(buf.begin());
      static char ok[]=" index_0=\"1\"\n index_1=\"3.14\"\n index_2=\"txt\"\n index_3=\"100\"\n";
      TS_ASSERT_TEXT(buf.begin(),ok)
    }
    void test_MyDataSet_xml_export_attribute() {
      _DUMP("test_MyDataSet_xml_export_attribute\n")
      ostream buf;
      cz::gepro::variant_format f;
      typedef cz::gepro::export_rows<ostream,cz::gepro::xml_export_attribute<ostream> > a; 
      MyDataSet data;
      a::write(buf,&data);
      buf << std::endl;
      _DUMP(buf.begin());
      static char ok[]="<attribute name=\"index_0\" value=\"1\" />\n<attribute name=\"index_1\" value=\"3.14\" />\n<attribute name=\"index_2\" value=\"txt\" />\n<attribute name=\"index_3\" value=\"100\" />\n";
      TS_ASSERT_TEXT(buf.begin(),ok)
    }
    void test_MyDataSet_xml_export_attribute_format() {
      _DUMP("test_MyDataSet_xml_export_attribute_format\n")
      ostream buf;
      cz::gepro::variant_format f;
      typedef cz::gepro::export_rows<ostream,cz::gepro::xml_export_attribute<ostream> > a; 
      MyDataSet data;
      MyDataFormat fmt;
      a::write(buf,&data,&fmt);
      buf << std::endl;
      _DUMP(buf.begin());
      static char ok[]="<attribute name=\"index_0\" value=\"1\" />\n<attribute name=\"index_1\" value=\"3.14\" />\n<attribute name=\"index_2\" value=\"txt\" />\n<attribute name=\"index_3\" value=\"64\" />\n";
      TS_ASSERT_TEXT(buf.begin(),ok)
    }
    void test_export_variant_ini() {
      _DUMP("test_export_variant_ini\n")
      ostream buf;
      cz::gepro::variant_format f;
      typedef cz::gepro::export_rows<ostream,cz::gepro::export_variant_ini<ostream> > a; 
      MyDataSet data;
      MyDataFormat fmt;
      a::write(buf,&data,&fmt);
      buf << std::endl;
      _DUMP(buf.begin());
      static char ok[]="index_0=1\nindex_1=3.14\nindex_2=txt\nindex_3=64\n";
      TS_ASSERT_TEXT(buf.begin(),ok)
    }
    void test_export_variant_form() {
      _DUMP("test_export_variant_form\n")
      ostream buf;
      typedef cz::gepro::export_rows<ostream,cz::gepro::export_variant_form<ostream>,'&' > a; 
      MyDataSet data;
      MyDataFormat fmt;
      a::write(buf,&data,&fmt);
      _DUMP(buf.begin());
      static char ok[]="index_0=1&index_1=3.14&index_2=txt&index_3=64";
      TS_ASSERT_TEXT(buf.begin(),ok)
    }
    void test_export_variant_json() {
      _DUMP("test_export_variant_json\n")
      ostream buf;
      typedef cz::gepro::export_rows<ostream,cz::gepro::export_variant_json<ostream>,',' > a; 
      MyDataSet data;
      MyDataFormat fmt;
      a::write(buf,&data,&fmt);
      _DUMP(buf.begin());
      static char ok[]="\"index_0\":1,\"index_1\":3.14,\"index_2\":\"txt\",\"index_3\":64";
      TS_ASSERT_TEXT(buf.begin(),ok)
    }
    void test_export_variant_csv() {
      _DUMP("test_export_variant_csv\n")
      ostream buf;
      typedef cz::gepro::export_rows<ostream,cz::gepro::export_variant_csv<ostream>,',' > a; 
      MyDataSet data;
      MyDataFormat fmt;
      a::write(buf,&data,&fmt);
      _DUMP(buf.begin());
      static char ok[]="1,3.14,\"txt\",64";
      TS_ASSERT_TEXT(buf.begin(),ok)
    }
    void test_export_variant_csv2() {
      _DUMP("test_export_variant_csv2\n")
      ostream buf;
      typedef cz::gepro::export_rows2<ostream,cz::gepro::export_variant_csv<ostream,cz::gepro::IData2::value_type>,cz::gepro::IData2,cz::gepro::IDataFormat,',' > a; 
      MyDataSet2 data;
      MyDataFormat fmt;
      a::write(buf,&data,&fmt);
      _DUMP(buf.begin());
      static char ok[]="1,3.14,\"txt\",64";
      TS_ASSERT_TEXT(buf.begin(),ok)
    }
    class mygetter : public boost::static_visitor<> {
      public:
        typedef char char_type;
        const char_type* type;
        mygetter() {type=NULL;}
        void operator()(const int ) {
        }
        void operator()(const double ) {
        }
        void operator()(const char* ) {
          type="string";
        }
        void operator()(const int* ) {
        }
        void operator()(const double* ) {
        }
        const char_type* gettype() const {return type;}
    };
    void test_MyDataSet_xml_export_attribute_format2() {
      _DUMP("test_MyDataSet_xml_export_attribute_format\n")
      ostream buf;
      cz::gepro::variant_format f;
      typedef cz::gepro::export_rows<ostream,cz::gepro::xml_export_attribute<ostream,cz::gepro::IData::value_type,cz::gepro::outputer<ostream>,mygetter> > a; 
      MyDataSet data;
      MyDataFormat fmt;
      a::write(buf,&data,&fmt);
      buf << std::endl;
      _DUMP(buf.begin());
      static char ok[]="<attribute name=\"index_0\" value=\"1\" />\n<attribute name=\"index_1\" value=\"3.14\" />\n<attribute name=\"index_2\" value=\"txt\" type=\"string\" />\n<attribute name=\"index_3\" value=\"64\" />\n";
      TS_ASSERT_TEXT(buf.begin(),ok)
    }
    template<class O,class I=cz::gepro::IDataRows,class F=cz::gepro::variant_format>
    class td {
      public:
        typedef O ostream;
        typedef typename ostream::traits_type::char_type char_type;
        typedef I data_type;
        typedef F format_type;
        const char_type* classname;

        td(const char_type* _classname=NULL) {classname=_classname;}
        void open_table(ostream& o,data_type& ) const {
          o << "<table>" << std::endl;
        }
        void close_table(ostream& o,data_type& ) const {
          o << "</table>" << std::endl; 
        }
        void open_row(ostream& o,data_type& ,size_t i) const {
          if(i%2) o << "<tr class=\"sudy\">";
          else o << "<tr>";
        }
        void close_row(ostream& o,data_type& ,size_t ) const {
          o << "</tr>" << std::endl; 
        }
        void open(ostream& o,size_t ,const char_type* ,const format_type& ) const {
          o << "<td";
          //if(classname) o << " class=\"" << classname << "\"";
          //o << " col=\"" << i << "\" name=\"" << name << "\"";
          o << ">";
        }
        void close(ostream& o,size_t ,const char_type* ,const format_type& ) const {
          o << "</td>";
        }
    };
    template<class O,class I=cz::gepro::IDataRows,class F=cz::gepro::IDataFormat>
    class attr {
      public:
        typedef O ostream;
        typedef typename ostream::traits_type::char_type char_type;
        typedef I data_type;
        typedef typename F::value_type format_type;

        void open_table(ostream& o,data_type& ) const {
          o << "<objects>" << std::endl;
        }
        void close_table(ostream& o,data_type& ) const {
          o << "</objects>" << std::endl;
        }
        void open_row(ostream& o,data_type& ,size_t ) const {
          o << "<object>" << std::endl; 
        }
        void close_row(ostream& o,data_type& ,size_t ) const {
          o << "</object>" << std::endl; 
        }
        void open(ostream& o,size_t ,const char_type* name,const format_type& ) const {
          o << "<attribute name=\"" << name << "\" value=\"";
        }
        void close(ostream& o,size_t ,const char_type* ,const format_type& ) const {
          o << "\" />" << std::endl;
        }
    };
    void test_MyDataRows() {
      ostream buf;
      cz::gepro::variant_format f;
      typedef cz::gepro::export_variant<ostream,cz::gepro::variant2> e;
      MyDataRows data;
      for(size_t j=0;j<data.GetCntRows();j++) {
        MyDataRows::data_row* r=data.GetDataRow(j);
        buf << "row:" << j << std::endl;
        td<ostream> tdr("data");
        for(size_t i=0;i<data.GetCount();i++) {
          e::quotedex(buf,i,data.GetId(i),r->GetValue(i),f,tdr);
        }
        buf << std::endl;
      }
      _DUMP(buf.begin());
    }
    void test_MyDataRows2() {
      ostream buf;
      cz::gepro::variant_format f;
      typedef cz::gepro::export_variant<ostream,cz::gepro::variant2> e;
      MyDataRows data;
      for(size_t j=0;j<data.GetCntRows();j++) {
        MyDataRows::data_row* r=data.GetDataRow(j);
        buf << "row:" << j << std::endl;
        td<ostream> tdr("data");
        for(size_t i=0;i<data.GetCount();i++) {
          e::quotedex(buf,i,data.GetId(i),r->GetValue(i),f,tdr);
        }
        buf << std::endl;
      }
      _DUMP(buf.begin());
    }
    
    void test_MyDataRows3() {
      ostream buf;
      typedef cz::gepro::export_table<ostream,cz::gepro::IDataRows,cz::gepro::IDataFormat> e;
      MyDataRows data;
      for(size_t j=0;j<data.GetCntRows();j++) {
        MyDataRows::data_row* r=data.GetDataRow(j);
        buf << "row:" << j << std::endl;
        td<ostream> tdr("data");
        e::write_row(buf,data,j,*r,tdr);
        buf << std::endl;
      }
      _DUMP(buf.begin());
    }
    void test_MyDataRows4() {
      ostream buf;
      typedef cz::gepro::export_table<ostream,cz::gepro::IDataRows,cz::gepro::IDataFormat> e;
      MyDataRows data;
      td<ostream> tdr("data");
      e::write(buf,data,tdr);
      _DUMP(buf.begin());
    }
    void test_MyDataRows5() {
      ostream buf;
      typedef cz::gepro::export_table<ostream,cz::gepro::IDataRows,cz::gepro::IDataFormat> e;
      MyDataRows data;
      MyDataFormat fmt;
      td<ostream> tdr("data");
      e::write(buf,data,fmt,tdr);
      _DUMP(buf.begin());
    }
    void test_MyDataRows6() {
      ostream buf;
      typedef cz::gepro::export_table<ostream,cz::gepro::IDataRows,cz::gepro::IDataFormat> e;
      MyDataRows data;
      #ifdef SDK_ON_FRANTA_PC
        MyDataFormat1 fmt;
      #else 
        MyDataFormat fmt;
      #endif
      attr<ostream> tdr;
      e::write(buf,data,fmt,tdr);
      _DUMP(buf.begin());
    }
   
};


#endif // __TEST_H

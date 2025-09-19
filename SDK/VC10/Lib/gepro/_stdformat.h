#ifndef __SDK_GEPRO__STDFORMAT
#define __SDK_GEPRO__STDFORMAT

/* formatovac streamu */

#ifndef BOOST_VARIANT_HPP
  #include <boost/variant.hpp>
#endif
namespace cz {
namespace gepro {
/** Formátovací tøídy - umožní nastavit parametry pro výstup na stream pro jednotlivé datové typy.
    Tvorbou nového formátovacího typu lze rozšiøovat formátováci možnosti.
*/
class noneformat {
  public:
    noneformat() {}
    ~noneformat() {}
};
class baseformat {
  public:
    std::ios_base::fmtflags basefield;
    std::ios_base::fmtflags adjustfield;
    std::ios_base::fmtflags floatfield;
    int fill;
    int width;
    bool showbase;
    baseformat() {
      showbase=false;
      width=fill=0;
      basefield=adjustfield=floatfield=NULL;
    }
    baseformat(std::ios_base::fmtflags _basefield) {
      showbase=false;
      width=fill=0;
      adjustfield=floatfield=NULL;
      basefield=_basefield;
    }
    ~baseformat() {}
    
};
class coordsformat {
  public:
    std::streamsize precision;
    coordsformat() {
      precision=15;
    }
};
class base_format_time {
    cz::gepro::tstatbuf<64> f_;
  public:
    void put(const char* _f) {
      f_.clear();
      f_<<_f;
    }
    const char* get() const {return f_.begin();}
};
/** Variant jednotlivých formátovacích tøíd
*/
typedef boost::variant< noneformat,baseformat,coordsformat> variant_format;
/** Visitor pro uplatnìní jednotlivých tøíd. Pokud se pøidá nová formátovací tøída
    je nutné doplnit operator () pro nový typ.

    Tøída O musí podporovat interface std::ostream.
*/
template<class O,class FT=base_format_time>
class variant_format_formater:public boost::static_visitor<> {
  public:
    typedef O ostream;
    typedef FT format_datetime;
    variant_format_formater(ostream& _o,format_datetime* _fdt=NULL):o_(_o) {f_=false;fdt_=_fdt;}
    void reset() {
      if(!f_) return;
      o_.unsetf(std::ios::showbase|std::ios::basefield);
      f_=false;
    }
    void operator()(const noneformat&) {
      reset();
    }
    void operator()(const baseformat& v) {
      reset();
      if(v.basefield) o_.setf(v.basefield,std::ios::basefield);
      if(v.showbase) o_.setf(std::ios::showbase);
      f_=true;
    }
    void operator()(const coordsformat& v) {
      reset();
      o_.precision(v.precision);
      o_.setf(std::ios::scientific,std::ios::floatfield);
      f_=true;
    }
    ostream& o_;
    format_datetime* fdt_;
  protected:
    bool f_;
};
/** Outputer realizuje výstup datového variantu s pomocí formátovací tøídy.
    Musí obsahovat operátor () pro všechny typy v použitém variantu (nebo pro typy konvertovatelné)

    Tøída O musí podporovat interface std::ostream.
*/
template<class O,class F=variant_format,class VF=variant_format_formater<O> >
class outputer : public boost::static_visitor<> {
  public:
    typedef O ostream;
    typedef F format_type;
    typedef VF formater;
    typedef typename formater::format_datetime format_datetime;
    outputer(ostream& _o,const format_type& _f):fmt_(_o,&fdt_),f_(_f) {quote_='\0';}
    void setquote(char _quote) {quote_=_quote;}
    ostream& getstream() const {return fmt_.o_;}
    void operator()(const int v) {
      boost::apply_visitor(fmt_,f_);
      fmt_.o_ << v;
    }
    void operator()(const double v) {
      boost::apply_visitor(fmt_,f_);
      fmt_.o_ << v;
    }
    void operator()(const char* v) {
      boost::apply_visitor(fmt_,f_);
      if(quote_) fmt_.o_ << quote_;
      fmt_.o_ << v;
      if(quote_) fmt_.o_ << quote_;
    }
    void operator()(const int* v) {
      boost::apply_visitor(fmt_,f_);
      fmt_.o_ << *v;
    }
    void operator()(const double* v) {
      boost::apply_visitor(fmt_,f_);
      fmt_.o_ << *v;
    }
    void operator()(const SYSTEMTIME& v) {
      boost::apply_visitor(fmt_,f_);
    }
  private:
    formater fmt_;
    format_datetime fdt_;
    const format_type& f_;
    char quote_;
};
/** Statická exportní tøída pro zadaný variant a outputer, realizuje základní výstupní tvary
    - èístý text value - jen pøevod hodnoty za pomocí formátovaèe
    - qutoed text - hodnota v uvozovkách
    - pair - dvojice kliè=hodnota
    - atribut - dvojice klíè="hodnota"

*/
template< class O,class V=variant,class G=outputer<O> >
class export_variant {
  public:
    typedef O ostream;
    typedef typename ostream::traits_type::char_type char_type;
    typedef G outputer_type;
    typedef V value_type;
    typedef typename outputer_type::format_type format_type;
    static void value(ostream& o,const value_type& v,const format_type& f) {
      outputer_type out(o,f);
      boost::apply_visitor(out,v);
    }
    /** Výstup hodnoty, stringová hodnota se vloží do zadaných úvozovek q
    */
    static void value_q(ostream& o,const value_type& v,const format_type& f,char q) {
      outputer_type out(o,f);
      out.setquote(q);
      boost::apply_visitor(out,v);
    }
    static void quoted(ostream& o,const value_type& v,const format_type& f,const char_type* q) {
      o << q;
      value(o,v,f);
      o << q;
    }
    template <class Q>
    static void quotedex(ostream& o,size_t i,const char_type* name,const value_type& v,const format_type& f,const Q& br) {
      br.open(o,i,name,f);
      value(o,v,f);
      br.close(o,i,name,f);
    }
    static void pair(ostream& o,const char_type* name,const value_type& v,const format_type& f) {
      o << name << "=";
      value(o,v,f);
    }
    static void json(ostream& o,const char_type* name,const value_type& v,const format_type& f) {
      o << "\"" << name << "\":";
      value_q(o,v,f,'\"');
    }
    static void attribute(ostream& o,const char_type* name,const value_type& v,const format_type& f) {
      o << " " << name << "=";
      quoted(o,v,f,"\"");
    }
    static void attribute(ostream& o,const char_type* name,const char_type* val) {
      o << " " << name << "=\"" << val << "\"";
    }
};
typedef TIDataRow<variant_format> IDataFormat;
template<class E=char>
class type_getter_dummy : public boost::static_visitor<> {
  public:
    typedef E char_type;
    void operator()(const int ) {
    }
    void operator()(const double ) {
    }
    void operator()(const char* ) {
    }
    void operator()(const int* ) {
    }
    void operator()(const double* ) {
    }
    void operator()(const SYSTEMTIME& v) {
    }
    const char_type* gettype() const {return NULL;}
};
/** Export IData do XML ve tvaru
    <attribute name="GetId()" value="GetValue()" /> std::endl
*/
template<class O,
         class V=variant,
         class G=outputer<O>,
         class T=type_getter_dummy<O::traits_type::char_type> >
class xml_export_attribute {
  public:
    typedef O ostream;
    typedef typename ostream::traits_type::char_type char_type;
    typedef G outputer_type;
    typedef V value_type;
    typedef typename outputer_type::format_type format_type;
    typedef export_variant<ostream,value_type,outputer_type> e;
    typedef T type_getter;

    static void write(ostream& o,const char_type* id,const value_type& v,const format_type& f) {
      o << "<attribute";
      e::attribute(o,"name",id);
      e::attribute(o,"value",v,f);
      type_getter t;
      boost::apply_visitor(t,v);
      if(t.gettype()) {
        e::attribute(o,"type",t.gettype());
      }
      o << " />";
    }
};
/** Export IData do INI sekce ve tvaru
    GetId=GetValue() std::endl
*/
template<class O,class V=variant,class G=outputer<O> >
class export_variant_ini {
  public:
    typedef O ostream;
    typedef typename ostream::traits_type::char_type char_type;
    typedef G outputer_type;
    typedef V value_type;
    typedef typename outputer_type::format_type format_type;
    typedef export_variant<ostream,value_type,outputer_type> e;

    static void write(ostream& o,const char_type* id,const value_type& v,const format_type& f) {
      e::pair(o,id,v,f);
    }
};
/** Export IData do JSON sekce ve tvaru
    GetId=GetValue() std::endl
*/
template<class O,class V=variant,class G=outputer<O> >
class export_variant_json {
  public:
    typedef O ostream;
    typedef typename ostream::traits_type::char_type char_type;
    typedef G outputer_type;
    typedef V value_type;
    typedef typename outputer_type::format_type format_type;
    typedef export_variant<ostream,value_type,outputer_type> e;

    static void write(ostream& o,const char_type* id,const value_type& v,const format_type& f) {
      e::json(o,id,v,f);
    }
};
template<class O,class V=variant,class G=outputer<O> >
class export_variant_form {
  public:
    typedef O ostream;
    typedef typename ostream::traits_type::char_type char_type;
    typedef G outputer_type;
    typedef V value_type;
    typedef typename outputer_type::format_type format_type;
    typedef export_variant<ostream,value_type,outputer_type> e;

    static void write(ostream& o,const char_type* id,const value_type& v,const format_type& f) {
      e::pair(o,id,v,f);
    }
};
template<class O,class V=variant,class G=outputer<O> >
class export_variant_csv {
  public:
    typedef O ostream;
    typedef typename ostream::traits_type::char_type char_type;
    typedef G outputer_type;
    typedef V value_type;
    typedef typename outputer_type::format_type format_type;
    typedef export_variant<ostream,value_type,outputer_type> e;

    static void write(ostream& o,const char_type*,const value_type& v,const format_type& f) {
      e::value_q(o,v,f,'\"');
    }
};
template<class O,class EV,const char endl='\n'>
class export_rows {
  public:
    typedef O ostream;
    typedef EV export_type;
    typedef typename export_type::format_type format_type;
    typedef IData data_type;
    typedef IDataFormat data_format;
    static void write(ostream& o,data_type* r) {
      format_type f;
      size_t cnt=r->GetCount();
      bool first=true;
      for(size_t i=0;i<cnt;i++) {
        if(!first) {
          if(endl=='\n') o << std::endl; else o << endl;
        } else first=false;
        export_type::write(o,r->GetId(i),r->GetValue(i),f);
      }
    }
    static void write(ostream& o,data_type* r,data_format* f) {
      size_t cnt=r->GetCount();
      bool first=true;
      for(size_t i=0;i<cnt;i++) {
        if(!first) {
          if(endl=='\n') o << std::endl; else o << endl;
        } else first=false;
        export_type::write(o,r->GetId(i),r->GetValue(i),f->GetValue(i));
      }
    }
};
template<class O,class EV,class I,class IF,const char endl>
class export_rows2 {
  public:
    typedef O ostream;
    typedef EV export_type;
    typedef typename export_type::format_type format_type;
    typedef I data_type;
    typedef IF data_format;
    static void write(ostream& o,data_type* r) {
      format_type f;
      size_t cnt=r->GetCount();
      bool first=true;
      for(size_t i=0;i<cnt;i++) {
        if(!first) {
          if(endl=='\n') o << std::endl; else o << endl;
        } else first=false;
        export_type::write(o,r->GetId(i),r->GetValue(i),f);
      }
    }
    static void write(ostream& o,data_type* r,data_format* f) {
      size_t cnt=r->GetCount();
      bool first=true;
      for(size_t i=0;i<cnt;i++) {
        if(!first) {
          if(endl=='\n') o << std::endl; else o << endl;
        } else first=false;
        export_type::write(o,r->GetId(i),r->GetValue(i),f->GetValue(i));
      }
    }
};

template<class O,class I,class IF>
class export_table {
  public:
    typedef O ostream;
    typedef typename ostream::traits_type::char_type char_type;
    typedef I data_type;
    typedef typename data_type::value_type value_type;
    typedef typename data_type::data_row data_row;
    typedef cz::gepro::export_variant<ostream,value_type> export_type;
    typedef typename export_type::format_type format_type;
    typedef IF data_format;
    template<class Q>
    static void write_row(ostream& o,data_type& h,size_t i,data_row& r,const Q& q) {
      format_type f;
      size_t cnt=h.GetCount();
      if(!cnt) return;
      q.open_row(o,h,i);
      for(size_t j=0;j<cnt;j++) {
        export_type::quotedex(o,j,h.GetId(j),r.GetValue(j),f,q);
      }
      q.close_row(o,h,i);
    }
    template<class Q>
    static void write_row(ostream& o,data_type& h,size_t i,data_row& r,data_format& f,const Q& q) {
      size_t cnt=h.GetCount();
      if(!cnt) return;
      q.open_row(o,h,i);
      for(size_t j=0;j<cnt;j++) {
        export_type::quotedex(o,j,h.GetId(j),r.GetValue(j),f.GetValue(j),q);
      }
      q.close_row(o,h,i);
    }
    template<class Q>
    static void write(ostream& o,data_type& h,const Q& q) {
      size_t cnt=h.GetCntRows();
      if(!cnt) return;
      q.open_table(o,h);
      for(size_t i=0;i<cnt;i++) {
        data_row* r=h.GetDataRow(i);
        if(r) write_row(o,h,i,*r,q);
      }
      q.close_table(o,h);
    }
    template<class Q>
    static void write(ostream& o,data_type& h,data_format& f,const Q& q) {
      size_t cnt=h.GetCntRows();
      if(!cnt) return;
      q.open_table(o,h);
      for(size_t i=0;i<cnt;i++) {
        data_row* r=h.GetDataRow(i);
        if(r) write_row(o,h,i,*r,f,q);
      }
      q.close_table(o,h);
    }
};
};//gepro
};//cz

#endif 

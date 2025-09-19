#ifndef __TYPES_H
#define __TYPES_H
#if defined(DEBUG_PREPROC)
  #pragma message(__FILE__ "(1) : debug included")
#endif

namespace gepro
{
  class TIMESTAMP : public TIMESTAMP_STRUCT
  {
  public:
    TIMESTAMP()
    {
      memset(this, 0, sizeof(*this));
    }
    TIMESTAMP(const TIMESTAMP_STRUCT& _pTs)
    {
      TIMESTAMP();
      year = _pTs.year;
      month = _pTs.month;
      day = _pTs.day;
      hour = _pTs.hour;
      minute = _pTs.minute;
      second = _pTs.second;
      fraction = _pTs.fraction;
    }
    TIMESTAMP& operator =(const TIMESTAMP_STRUCT& _pTs)
    {
      TIMESTAMP();
      year = _pTs.year;
      month = _pTs.month;
      day = _pTs.day;
      hour = _pTs.hour;
      minute = _pTs.minute;
      second = _pTs.second;
      fraction = _pTs.fraction;
      return *this;
    }

    TIMESTAMP(const SYSTEMTIME& _pSt)
    {
      TIMESTAMP();
      year = _pSt.wYear;
      month = _pSt.wMonth;
      day = _pSt.wDay;
      hour = _pSt.wHour;
      minute = _pSt.wMinute;
      second = _pSt.wSecond;
      fraction = _pSt.wMilliseconds;
    }
    TIMESTAMP& operator =(const SYSTEMTIME& _pSt)
    {
      TIMESTAMP();
      year = _pSt.wYear;
      month = _pSt.wMonth;
      day = _pSt.wDay;
      hour = _pSt.wHour;
      minute = _pSt.wMinute;
      second = _pSt.wSecond;
      fraction = _pSt.wMilliseconds;
      return *this;
    }

    TIMESTAMP(SWORD _year, UWORD _month, UWORD _day, UWORD _hour = 0, UWORD _minute = 0, UWORD _second = 0, UDWORD _fraction = 0)
    {
      TIMESTAMP();
      year = _year;
      month = _month;
      day = _day;
      hour = _hour;
      minute = _minute;
      second = _second;
      fraction = _fraction;
    }
    /** Now 
        Naplni strukturu aktualnim systemovym casenm s ohledem na nastevenou casovou zonu
    
      @return void
    */
    void Now()
    {
      SYSTEMTIME st, loc;
      ::GetSystemTime(&st);
      SystemTimeToTzSpecificLocalTime(NULL, &st, &loc);
      year = loc.wYear;
      month = loc.wMonth;
      day = loc.wDay;
      hour = loc.wHour;
      minute = loc.wMinute;
      second = loc.wSecond;
      fraction = loc.wMilliseconds;
    }
    /** TimeToLocalTime 
        prevede from na lokalni cas a ulozi do to
   
      @param to   - vysledny cas podle nastavene timezone v locales
      @param from - zdrojovy cas
    
      @return TIMESTAMP*
    */
    TIMESTAMP* TimeToLocalTime(TIMESTAMP& to, TIMESTAMP& from)
    {
      SYSTEMTIME st;
      memset(&st, 0, sizeof(st));
      st.wYear = from.year;
      st.wMonth = from.month;
      st.wDay = from.day;
      st.wHour = from.hour;
      st.wMinute = from.minute;
      st.wSecond = from.second;
      st.wMilliseconds = (WORD)from.fraction;

      SYSTEMTIME loc;
      SystemTimeToTzSpecificLocalTime(NULL, &st, &loc);
      to.year = loc.wYear;
      to.month = loc.wMonth;
      to.day = loc.wDay;
      to.hour = loc.wHour;
      to.minute = loc.wMinute;
      to.second = loc.wSecond;
      to.fraction = loc.wMilliseconds;
      return &to;
    }
    /** ToLocalTime 
        prevede _ts na miste na lokalni cas
   
      @param _ts - vysledny lokalni cas s podle nastavene timezone v locales
    
      @return TIMESTAMP*
    */
    TIMESTAMP* ToLocalTime(TIMESTAMP& _ts)
    {
      SYSTEMTIME st;
      memset(&st, 0, sizeof(st));
      st.wYear = _ts.year;
      st.wMonth = _ts.month;
      st.wDay = _ts.day;
      st.wHour = _ts.hour;
      st.wMinute = _ts.minute;
      st.wSecond = _ts.second;
      st.wMilliseconds = (WORD)_ts.fraction;

      SYSTEMTIME loc;
      SystemTimeToTzSpecificLocalTime(NULL, &st, &loc);
      _ts.year = loc.wYear;
      _ts.month = loc.wMonth;
      _ts.day = loc.wDay;
      _ts.hour = loc.wHour;
      _ts.minute = loc.wMinute;
      _ts.second = loc.wSecond;
      _ts.fraction = loc.wMilliseconds;
      return &_ts;
    }
    __int64 GetFileTime()
    {
      __int64 lTime;
      SYSTEMTIME st;
      st.wYear = year;
      st.wMonth = month;
      st.wDay = day;
      st.wHour = hour;
      st.wMinute = minute;
      st.wSecond = second;
      st.wMilliseconds = (WORD)fraction;
      FILETIME localtime;
      SystemTimeToFileTime(&st, &localtime);
      LocalFileTimeToFileTime(&localtime, (FILETIME*)&lTime);
      return lTime;
    }
    SYSTEMTIME* GetSystemTime(SYSTEMTIME& _st)
    {
      _st.wYear = year;
      _st.wMonth = month;
      _st.wDay = day;
      _st.wHour = hour;
      _st.wMinute = minute;
      _st.wSecond = second;
      _st.wMilliseconds = (WORD)fraction;
      return &_st;
    }
    friend bool operator >(const TIMESTAMP& t1, const TIMESTAMP& t2)
    {
      if (t1.year > t2.year)
      {
        return( true) ;
      }
      else if (t1.year < t2.year)
      {
        return( false) ;
      }
      if (t1.month > t2.month)
      {
        return( true) ;
      }
      else if (t1.month < t2.month)
      {
        return( false) ;
      }
      if (t1.day > t2.day)
      {
        return( true) ;
      }
      else if (t1.day < t2.day)
      {
        return( false) ;
      }
      if (t1.hour > t2.hour)
      {
        return( true) ;
      }
      else if (t1.hour < t2.hour)
      {
        return( false) ;
      }
      if (t1.minute > t2.minute)
      {
        return( true) ;
      }
      else if (t1.minute < t2.minute)
      {
        return( false) ;
      }
      if (t1.second > t2.second)
      {
        return( true) ;
      }
      else if (t1.second < t2.second)
      {
        return( false) ;
      }
      if (t1.fraction > t2.fraction)
      {
        return( true) ;
      }
      return( false) ;
    }
    friend bool operator >=(const TIMESTAMP& t1, const TIMESTAMP& t2)
    {
      if (t1.year > t2.year)
      {
        return( true) ;
      }
      else if (t1.year < t2.year)
      {
        return( false) ;
      }
      if (t1.month > t2.month)
      {
        return( true) ;
      }
      else if (t1.month < t2.month)
      {
        return( false) ;
      }
      if (t1.day > t2.day)
      {
        return( true) ;
      }
      else if (t1.day < t2.day)
      {
        return( false) ;
      }
      if (t1.hour > t2.hour)
      {
        return( true) ;
      }
      else if (t1.hour < t2.hour)
      {
        return( false) ;
      }
      if (t1.minute > t2.minute)
      {
        return( true) ;
      }
      else if (t1.minute < t2.minute)
      {
        return( false) ;
      }
      if (t1.second > t2.second)
      {
        return( true) ;
      }
      else if (t1.second < t2.second)
      {
        return( false) ;
      }
      if (t1.fraction > t2.fraction)
      {
        return( true) ;
      }
      if (t1.fraction < t2.fraction)
      {
        return( false) ;
      }
      return( true) ;
    }
    friend bool operator <(const TIMESTAMP& t1, const TIMESTAMP& t2)
    {
      if (t1.year < t2.year)
      {
        return( true) ;
      }
      else if (t1.year > t2.year)
      {
        return( false) ;
      }
      if (t1.month < t2.month)
      {
        return( true) ;
      }
      else if (t1.month > t2.month)
      {
        return( false) ;
      }
      if (t1.day < t2.day)
      {
        return( true) ;
      }
      else if (t1.day > t2.day)
      {
        return( false) ;
      }
      if (t1.hour < t2.hour)
      {
        return( true) ;
      }
      else if (t1.hour > t2.hour)
      {
        return( false) ;
      }
      if (t1.minute < t2.minute)
      {
        return( true) ;
      }
      else if (t1.minute > t2.minute)
      {
        return( false) ;
      }
      if (t1.second < t2.second)
      {
        return( true) ;
      }
      else if (t1.second > t2.second)
      {
        return( false) ;
      }
      if (t1.fraction < t2.fraction)
      {
        return( true) ;
      }
      return( false) ;
    }
    friend bool operator <=(const TIMESTAMP& t1, const TIMESTAMP& t2)
    {
      if (t1.year < t2.year)
      {
        return( true) ;
      }
      else if (t1.year > t2.year)
      {
        return( false) ;
      }
      if (t1.month < t2.month)
      {
        return( true) ;
      }
      else if (t1.month > t2.month)
      {
        return( false) ;
      }
      if (t1.day < t2.day)
      {
        return( true) ;
      }
      else if (t1.day > t2.day)
      {
        return( false) ;
      }
      if (t1.hour < t2.hour)
      {
        return( true) ;
      }
      else if (t1.hour > t2.hour)
      {
        return( false) ;
      }
      if (t1.minute < t2.minute)
      {
        return( true) ;
      }
      else if (t1.minute > t2.minute)
      {
        return( false) ;
      }
      if (t1.second < t2.second)
      {
        return( true) ;
      }
      else if (t1.second > t2.second)
      {
        return( false) ;
      }
      if (t1.fraction < t2.fraction)
      {
        return( true) ;
      }
      if (t1.fraction > t2.fraction)
      {
        return( false) ;
      }
      return( true) ;
    }
    friend bool operator ==(const TIMESTAMP& t1, const TIMESTAMP& t2)
    {
      if (t1.year != t2.year)
      {
        return( false) ;
      }
      if (t1.month != t2.month)
      {
        return( false) ;
      }
      if (t1.day != t2.day)
      {
        return( false) ;
      }
      if (t1.hour != t2.hour)
      {
        return( false) ;
      }
      if (t1.minute != t2.minute)
      {
        return( false) ;
      }
      if (t1.second != t2.second)
      {
        return( false) ;
      }
      if (t1.fraction != t2.fraction)
      {
        return( false) ;
      }
      return( true) ;
    }
    friend bool operator !=(const TIMESTAMP& t1, const TIMESTAMP& t2)
    {
       return !(t1 == t2);
    }
    /** CheckTimestamp
        kontrola platnosti jednotlivych polozek TIMESTRUCT, vcetne prechodnych roku 
   
      @param t - 
    
      @return bool
    */
    bool CheckTimestamp()
    {
      if (second > 59)
      {
        return( false);
      }
      if (minute > 59)
      {
        return( false);
      }
      if (hour > 23)
      {
        return( false);
      }
      if (day < 1 || day > 31)
      {
        return( false);
      }
      if (month < 1 || month > 12)
      {
        return( false);
      }
      if (year < 1000)
      {
        return( false);
      }
      if (day > 30)
      {
        if (month == 4 || month == 6 || month == 9 || month == 11)
        {
          return( false);
        }
      }
      if (month == 2)
      {
        if (day > 29)
        {
          return( false);
        }
        if ((year%4) != 0 || ((year%100) == 0 && (year%400) != 0))
        {
          if (day > 28)
          {
            return( false);
          }
        }
      }
      return( true) ;
    }
  };
}

inline bool CheckTimestamp(const TIMESTAMP_STRUCT& _t)
{
  return ((gepro::TIMESTAMP)_t).CheckTimestamp();
}
inline bool CheckTimestamp(const SYSTEMTIME& _t)
{
  gepro::TIMESTAMP t = _t;
  return t.CheckTimestamp();
}

inline bool operator ==(const TIMESTAMP_STRUCT& t1, const TIMESTAMP_STRUCT& t2)
{
  return (gepro::TIMESTAMP)t1 == (gepro::TIMESTAMP)t2;
}
inline bool operator <(const TIMESTAMP_STRUCT& t1, const TIMESTAMP_STRUCT& t2)
{
  return (gepro::TIMESTAMP)t1 < (gepro::TIMESTAMP)t2;
}
inline bool operator <=(const TIMESTAMP_STRUCT& t1, const TIMESTAMP_STRUCT& t2)
{
  return (gepro::TIMESTAMP)t1 <= (gepro::TIMESTAMP)t2;
}
inline bool operator >(const TIMESTAMP_STRUCT& t1, const TIMESTAMP_STRUCT& t2)
{
  return (gepro::TIMESTAMP)t1 > (gepro::TIMESTAMP)t2;
}
inline bool operator >=(const TIMESTAMP_STRUCT& t1, const TIMESTAMP_STRUCT& t2)
{
  return (gepro::TIMESTAMP)t1 >= (gepro::TIMESTAMP)t2;
}
inline bool operator !=(const TIMESTAMP_STRUCT& t1, const TIMESTAMP_STRUCT& t2)
{
  return !((gepro::TIMESTAMP)t1 == (gepro::TIMESTAMP)t2);
}

#endif

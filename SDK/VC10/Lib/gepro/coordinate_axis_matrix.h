#ifndef __SDK_GEPRO_COORDINATE_AXIS_MATRIX_H
#define __SDK_GEPRO_COORDINATE_AXIS_MATRIX_H
#if defined(DEBUG_PREPROC)
  #pragma message(__FILE__ "(1) : debug included")
#endif

#include <map>
#include <string>

#include <gepro/point.h>
#include <gepro/rectangle.h>

namespace cz {
namespace gepro {
/** Tøída pro prohazování otáèení a další kouzla se souøadnicovými osami
*/
#pragma pack(push, 1) 
class coordinate_axis_matrix
{
public:
  enum type {
    UNDEFINED,
    IDENTITY,
    SWAP,
    SWAP_NEG,
    NEG,
    EN2SW = SWAP_NEG,
    EN2NE = SWAP,

    SW2NE = NEG,
    SW2EN = SWAP_NEG,
    SW2ES,
    SW2SE,
    SW2NW,
    SW2WN,
    SW2WS = SWAP,

    WS2NE = SW2ES,
    WS2EN = NEG,
    WS2ES = SW2NW,
    WS2SE,
    WS2NW = SW2ES,
    WS2WN = SW2SE,
    WS2SW = SWAP,

    EN2ES = SW2SE,
    //EN2SW = SWAP_NEG,
    EN2NW = WS2SE,
    EN2WN = SW2NW,
    EN2WS = NEG,

    NE2EN = SWAP,
    NE2ES = SW2SE,
    NE2SE = SW2NW,
    NE2WN = SW2ES,
    NE2NW = SW2SE,
    NE2SW = NEG,
    NE2WS = SWAP_NEG,

  };
  coordinate_axis_matrix() : xx_(1), xy_(0), yx_(0), yy_(1) {} //identity
  coordinate_axis_matrix(int xx, int xy, int yx, int yy) : xx_(xx), xy_(xy), yx_(yx), yy_(yy) {}
  coordinate_axis_matrix(type t) : xx_(1), xy_(0), yx_(0), yy_(1)
  {
    Set(t);
  }

  void Set(type t)
  {
    if (t == SWAP)
    {
      xx_ = 0; xy_ = 1;
      yx_ = 1; yy_ = 0;
    }
    else if (t == SWAP_NEG)
    {
      xx_ =  0; xy_ = -1;
      yx_ = -1; yy_ = 0;
    }
    else if (t == NEG)
    {
      xx_ = -1; xy_ =  0;
      yx_ =  0; yy_ = -1;
    }
    else if (t == SW2ES)     // a zaroven i WS2NE
    {
      xx_ =  0; xy_ = -1;
      yx_ =  1; yy_ =  0;
    }
    else if (t == SW2SE)    // a zaroven i WS2WN
    {
      xx_ =  1; xy_ =  0;
      yx_ =  0; yy_ = -1;
    }
    else if (t == SW2NW)    // a zaroven i  WS2ES
    {
      xx_ = -1; xy_ =  0;
      yx_ =  0; yy_ =  1;
    }

    else if (t == WS2SE)
    {
      xx_ =  0; xy_ =  1;
      yx_ = -1; yy_ =  0;
    }

    /*
    else if (t == NE2WN)    //
    {
      xx_ =  0; xy_ = -1;
      xx_ =  1; xy_ =  0;
    }
    */
  }
  point p(double val_x, double val_y) const
  {
    return point(val_x * xx_ + val_y * xy_, val_x * yx_ + val_y * yy_);
  }
  double x(double val_x, double val_y) const { return val_x * xx_ + val_y * xy_; }
  double y(double val_x, double val_y) const { return val_x * yx_ + val_y * yy_; }
  int xx() const { return xx_; }
  int xy() const { return xy_; }
  int yx() const { return yx_; }
  int yy() const { return yy_; }

  void Identity()
  {
      xx_ = 1; xy_ = 0;
      yx_ = 0; yy_ = 1;
  }

  void Transform( double& x, double& y) const
  {
    double _x(x);
    double _y(y);
    x = _x * xx_ + _y * xy_;
    y = _x * xy_ + _y * yy_;
  }


  static void identity(coordinate_axis_matrix& cm)
  {
    cm.Identity();
  }
  static void set(coordinate_axis_matrix& cm, const char* from2to)
  {
    type t = get_type(from2to);
    if (t == UNDEFINED)
      throw(std::exception("undefined coordinate_axis_matrix"));
    cm.Set(t);
  }

  static void transform(const coordinate_axis_matrix& cm, double& x, double& y)
  {
    cm.Transform(x, y);   
  }

  static point transform_point(const coordinate_axis_matrix& cm, const point& p)
  {
    point _p(p);
    cm.Transform(_p.X, _p.Y);
    return _p;
  }

  static rectangle transform_rect(const coordinate_axis_matrix& cm, const rectangle& rc)
  {
    point pt[4];
    pt[0] = point(rc.X1, rc.Y1);
    pt[1] = point(rc.X1, rc.Y2);
    pt[2] = point(rc.X2, rc.Y2);
    pt[3] = point(rc.X2, rc.Y1);

    point px = transform_point(cm, pt[0]);
    rectangle rct(px.X, px.Y, px.X, px.Y);
    for (int i = 1; i < 4; i++)
    {
      px = transform_point(cm, pt[i]);
      if (rct.X1 > px.X) rct.X1 = px.X;
      if (rct.Y1 > px.Y) rct.Y1 = px.Y;
      if (rct.X2 < px.X) rct.X2 = px.X;
      if (rct.Y2 < px.Y) rct.Y2 = px.Y;
    }
    return rct;
  }

private:
  static std::map<std::string, type> get_type_map() //v C++ 11 uz nebude potreba, tam se udela  static std::map<std::string, type> type_map = {{"sw2ne", SW2NE}, {"sw2ne", SW2NE}, ...};
  {
     std::map<std::string, type> type_map;
     type_map.insert(std::pair<std::string, type>("sw2ne", SW2NE));
     type_map.insert(std::pair<std::string, type>("sw2en", SW2EN));
     type_map.insert(std::pair<std::string, type>("sw2es", SW2ES));
     type_map.insert(std::pair<std::string, type>("sw2se", SW2SE));
     type_map.insert(std::pair<std::string, type>("sw2nw", SW2NW));
     type_map.insert(std::pair<std::string, type>("sw2wn", SW2WN));
     type_map.insert(std::pair<std::string, type>("sw2ws", SW2WS));

     type_map.insert(std::pair<std::string, type>("ws2ne", WS2NE));
     type_map.insert(std::pair<std::string, type>("ws2en", WS2EN));
     type_map.insert(std::pair<std::string, type>("ws2es", WS2ES));
     type_map.insert(std::pair<std::string, type>("ws2se", WS2SE));
     type_map.insert(std::pair<std::string, type>("ws2nw", WS2NW));
     type_map.insert(std::pair<std::string, type>("ws2wn", WS2WN));
     type_map.insert(std::pair<std::string, type>("ws2sw", WS2SW));

     type_map.insert(std::pair<std::string, type>("en2ne", EN2NE));
     type_map.insert(std::pair<std::string, type>("en2es", EN2ES));
     type_map.insert(std::pair<std::string, type>("en2se", EN2SW));
     type_map.insert(std::pair<std::string, type>("en2nw", EN2NW));
     type_map.insert(std::pair<std::string, type>("en2wn", EN2WN));
     type_map.insert(std::pair<std::string, type>("en2sw", EN2SW));
     type_map.insert(std::pair<std::string, type>("en2ws", EN2WS));

     type_map.insert(std::pair<std::string, type>("ne2en", NE2EN));
     type_map.insert(std::pair<std::string, type>("ne2es", NE2ES));
     type_map.insert(std::pair<std::string, type>("ne2se", NE2SE));
     type_map.insert(std::pair<std::string, type>("ne2nw", NE2NW));
     type_map.insert(std::pair<std::string, type>("ne2wn", NE2WN));
     type_map.insert(std::pair<std::string, type>("ne2sw", NE2SW));
     type_map.insert(std::pair<std::string, type>("ne2ws", NE2WS));

     return type_map;
  }
  static type get_type(const std::string& from2to)
  {
    static std::map<std::string, type> type_map = get_type_map();
    auto a = type_map.find(from2to);
    if (a != type_map.end())
      return a->second;
    return UNDEFINED;
  }
  int xx_, xy_;
  int yx_, yy_;
};
#pragma pack(pop)
}; //gepro
}; //cz
#endif
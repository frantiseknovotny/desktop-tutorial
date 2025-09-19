#ifndef __SDK_GEPRO_G2D_H
#define __SDK_GEPRO_G2D_H
#if defined(DEBUG_PREPROC)
  #pragma message(__FILE__ "(1) : debug included")
#endif
#ifndef __SDK_GEPRO_MATH_H
  #include   <gepro/math.h>
#endif
namespace cz {
namespace gepro {
/**	@addtogroup geometry Geometrické typy a funkce
    @{
    \brief g2d Namespace: obsahuje základní geometrické funkce ve 2D.
    V šablonách kde je typ T jako bod, musí mít public èleny double X a double Y.

*/
namespace g2d {
#ifdef PI
#undef PI
#endif
static double PI = M_PI;
static double PIx2 = 2*M_PI;
static double EPS = DBL_EPSILON;
static double EPS2 = 1e-6;


/**	\brief	The Direction function: výpoèet smìrniku z bodu p1 na bod p2 a vzdalenosti p1,p2

	\param	p1	a parameter of type const T&,  bod z nìjž se poèitá (stanovisko)
	\param	p2	a parameter of type const T&,  bod k nìmuž se poèitá
	\param	dist	a parameter of type double&,  vypoètená vzdálenost

	\return	template <class T> double - smìrník z bodu p1 na na bod p2 v radianech v rozmezí 0 - 2PI

	
*/
template <class T> double Direction(const T& p1, const T& p2, double& dist)
{  double dy=p2.Y-p1.Y;
   double dx=p2.X-p1.X;
   dist = hypot( dx, dy);
   if (dist < EPS2) { dist = 0.; return 0.; }
   double dir = atan2( dy, dx);
   if (dir < 0.) dir += PIx2;
   return dir;
}

/**	\brief	The Direction function: výpoèet smìrniku z bodu p1 na bod p2

	\param	p1	a parameter of type const T&,  bod z nìjž se poèitá (stanovisko)
	\param	p2	a parameter of type const T&,  bod k nìmuž se poèitá

	\return	template <class T> double - smìrník z bodu p1 na na bod p2 v radianech v rozmezí 0 - 2PI


*/
template <class T> double Direction(const T& p1, const T& p2)
{  double dy=p2.Y-p1.Y;
   double dx=p2.X-p1.X;
   double dir = atan2( dy, dx);
   if (dir < 0.) dir += PIx2;
   return dir;
}


/**	\brief	The AnglePos function: výpoèet úhlu na bodì p1 od p0 k p2 po smìru rotace (v pravotoèivé soustavì je to levostranný úhel)

	\param	p0	a parameter of type const T&,  koncový bod prvního ramene poèítaného úhlu
	\param	p1	a parameter of type const T&,  bod vrchol poèítaného úhlu
	\param	p2	a parameter of type const T&,  koncový bod druhého ramene poèítaného úhlu

	\return	template <class T> double - úhel  v radianech v rozmezí < 0 - 2PI)

    X
    |      p0 x
    |         |__
    |         |   \
    |         | u  |
    |      p1 x--------x p2 
    |
    |_______________________________ Y
*/
template <typename T> double AnglePos(const T& p0, const T& p1, const T& p2)
{
   double dir1=Direction(p1, p0);
   double dir2=Direction(p1, p2);
   double angle=dir2-dir1;
   if (angle < 0) {
    angle+=PIx2;
   } 
   return angle;
}


/**	\brief	The AngleNeg function: výpoèet úhlu na bodì p1 od p0 k p2 proti smìru rotace (v pravotoèivé soustavì je to pravostranný úhel)

	\param	p0	a parameter of type const T&,  koncový bod prvního ramene poèítaného úhlu
	\param	p1	a parameter of type const T&,  bod vrchol poèítaného úhlu
	\param	p2	a parameter of type const T&,  koncový bod druhého ramene poèítaného úhlu

	\return	template <class T> double - úhel  v  v radianech v rozmezí < 0 - 2PI )

    X
    |      p0 x
    |         |
    |       __|
    |      /  | p1
    |     | u x--------x p2  
    |      \____/     
    |_______________________________ Y

*/
template <typename T> double AngleNeg(const T& p0, const T& p1, const T& p2)
{
   double dir1=Direction(p1, p0);
   double dir2=Direction(p1, p2);
   double angle=dir1-dir2;
   if (angle < 0) {
    angle+=PIx2;
   } 
   return angle;
}


/**	\brief	The AngleConvex function: výpoèet konvexního úhlu na bodì p1 od p0 k p2

	\param	p0	a parameter of type const T&,  koncový bod prvního ramene poèítaného úhlu
	\param	p1	a parameter of type const T&,  bod vrchol poèítaného úhlu
	\param	p2	a parameter of type const T&,  koncový bod druhého ramene poèítaného úhlu

	\return	template <class T> double - konvexní úhel  v radianech v rozmezí < 0 - PI >

    X
    |      p0 x                p1 x--------x p2
    |         |__                 | u |
    |         |   \               |__ /
    |         | u  |              |
    |      p1 x--------x p2    p0 x  
    |
    |___________________________________________________ Y

*/
template <typename T> double AngleConvex(const T& p0, const T& p1, const T& p2)
{
  double angle = AnglePos(p0, p1, p2);
  if (angle > PI) {
    angle = PIx2-angle;
  }  
  return angle;
}


/**	\brief	The DirectRay function: výpoèet rajónu

	\param	orig	a parameter of type const T&,  bod z nìjž se poèitá (stanovisko)
	\param	l	a parameter of type double,  délka na urèovaný bod
	\param	alfa	a parameter of type double,  smìrník na urèovaný bod v rad
	\param	p	a parameter of type T&,  vypoètený bod

	\return	template <class T> void

	
*/
template <class T> void DirectRay(const T& orig, double l, double alfa, T& p)
{
  p.X = orig.X + l*cos(alfa);
  p.Y = orig.Y + l*sin(alfa);
}

/**	\brief	The PointPointDist function: výpoèet vzdálenosti dvou bodù

	\param	p1	a parameter of type const T&,  první bod
	\param	p2	a parameter of type const T&,  druhý bod

	\return	template <class T> double,  vzdálenost bodù

	
*/
template <class T> double PointPointDist(const T& p1,const T& p2)
{
  return hypot( p1.X - p2.X, p1.Y - p2.Y);
}


/**	\brief	The PointLineFoot function: výpoèet orientované vzdálenosti bodu od orientované pøímky a paty kolmice z bodu na pøímku

	\param	p	a parameter of type const T&,   bod k nìmuž se poèítá vzdálenost a pata kolmice
	\param	pl	a parameter of type const T&,   poèáteèní bod orientované pøímky
	\param	smer	a parameter of type double, smìr pøímky v rad.
	\param	pp	a parameter of type T&,  spoètená pata kolmice na pøímku

	\return	template <class T> double, orientovaná vzdálenost bodu od pøímky kladná hodnota, bod je vpravo, záporná vlevo

	
*/
template <class T> double PointLineFoot(const T& p,const T& pl,double smer,T& pp)
{  
   double t, s, c;
   c = cos(smer);
   s = sin(smer);
   t = c * (p.X-pl.X) + s * (p.Y-pl.Y);
   pp.X = pl.X + c * t;
   pp.Y = pl.Y + s * t;
   return c * (p.Y-pl.Y) + s * (pl.X-p.X);
}

/**	\brief	The PointLineFoot function: výpoèet orientované vzdálenosti bodu od orientované pøímky a paty kolmice z bodu na pøímku

	\param	p	a parameter of type const T&,   bod k nìmuž se poèítá vzdálenost a pata kolmice
	\param	a	a parameter of type const T&,   poèáteèní bod orientované pøímky
	\param	b	a parameter of type const T&,   druhý bod orientované pøímky
	\param	pp	a parameter of type T&,  spoètená pata kolmice na pøímku

	\return	template <class T> double, orientovaná vzdálenost bodu od pøímky kladná hodnota, bod je vpravo, záporná vlevo

	
*/
template <class T> double PointLineFoot(const T& p,const T& a,const T& b,T& pp)
{
  double px=b.X-a.X;
  double py=b.Y-a.Y;
  if ((px==0) && (py==0)) {    //pokud jsou body shodne, pata je taky shodna a vzdalenost je +
    pp=a;
    return PointPointDist(p,a);
  }
  double u = ((p.X-a.X)*px + (p.Y-a.Y)*py)/(px*px + py*py);

  pp.X = a.X + u * px;
  pp.Y = a.Y + u * py;
  double dx = pp.X - p.X;
  double dy = pp.Y - p.Y;

  if (px*(p.Y - a.Y) < py*(p.X - a.X)) {
    return -sqrt(dx*dx + dy*dy);
  }
  return sqrt(dx*dx + dy*dy);
}


/**	\brief	The PointLineDist function: výpoèet vzdálenosti bodu od pøímky

	\param	a	a parameter of type const T&,   bod první bod pøímky
	\param	b	a parameter of type const T&,   druhý bod pøímky
	\param	p 	a parameter of type const T&,   bod jehož vzdálenost se poèítá


	\return	template <class T> double, vzdálenost bodu p pøímky ab

	
*/
template <class T> double PointLineDist(const T& a,const T& b,const T& p)
{  
  double px=b.X-a.X;
  double py=b.Y-a.Y;
  if ((px==0) && (py==0)) {    //pokud jsou body shodne
    return PointPointDist(p,a);
  }
  return abs(px*(a.Y-p.Y)-(a.X-p.X)*py)/sqrt(px*px+py*py);
}
/**	\brief	The PointLineRelation function: výpoèet polohy bodu vùèi pøímce
	\param	p 	a parameter of type const T&,   bod jehož poloha vùèi pøímce se poèítá
	\param	a	a parameter of type const T&,   bod první bod pøímky
	\param	b	a parameter of type const T&,   druhý bod pøímky
	\param	pp	a parameter of type T&,   pata kolmice z bodu na pøímku
	\param	lp	a parameter of type T&,   x stanièení, y kolmice + right, - left v pravotoèivé soustavì
	\return	 double poloha bodu na úseèce a,b < 0 pøed prvním bodem > 1, za druhým bodem, 0.5 uprostøed 
*/
template <class T> double PointLineRelation(const T& p,const T& a,const T& b,T& pp,T& lp)
{
   if ((a.X==b.X) && (a.Y==b.Y)) {
     pp=a;
     lp.X=0;
     lp.Y=PointPointDist(p,a);
     return 0;
   }

   double dist = PointLineFoot(p, a, b, pp);
   lp.Y=dist;

   double segmen_length,pp_dist;
   double line_direction=Direction(a,b,segmen_length);
   double pp_direction=Direction(a,pp,pp_dist);

   if (abs(line_direction-pp_direction)< 0.01) { //stejny smer
     lp.X=pp_dist;
   } else {                                      //opacny smer
     lp.X=-pp_dist;
   }

   double res=lp.X/segmen_length;
   return res;
}



/**	\brief	The PointSegmentDist function: výpoèet vzdálenosti bodu od úseèky

	\param	a	a parameter of type const T&,   bod první bod úseèky
	\param	b	a parameter of type const T&,   druhý bod úseèky
	\param	p 	a parameter of type const T&,   bod jehož vzdálenost se poèítá


	\return	template <class T> double, vzdálenost bodu p úseèky ab

	
*/
template <class T> double PointSegmentDist(const T& a,const T& b,const T& p)
{ 
  double px=b.X-a.X;
  double py=b.Y-a.Y;
  double pxy=px*px + py*py;
  double u = ((p.X-a.X)*px + (p.Y-a.Y)*py)/pxy;

  if (u > 1) {          //za druhym bodem
    u = 1;  
  } else if (u < 0) {   //pred prvnim bodem
    u = 0;
  }

  double x = a.X + u * px;
  double y = a.Y + u * py;
  double dx = x - p.X;
  double dy = y - p.Y;

  return sqrt(dx*dx + dy*dy);
}

/**	\brief	The Area function: výpoèet plochy ohranièené body

	\param	p	a parameter of type const T&,  pole bodù
	\param	cnt	a parameter of type int,       poèet bodù

	\return	double, plocha ohranièená body +pokud jsou uspoøádány souhlasnì se soustavou,
                    - pokud jsou protismìrnì

	
*/
template <typename T> double Area(const T& p, int cnt) {
  double area=0;
  int i;
  for (i=0;i<cnt-1;i++) {
    area+=p[i].X*p[i+1].Y;
  }
  area+=p[cnt-1].X*p[0].Y;

  for (i=0;i<cnt-1;i++) {
    area-=p[i+1].X*p[i].Y;
  }
  area-=p[0].X*p[cnt-1].Y;

  return area/2;
}

/**	\brief	The CircleCentre function: výpoèet støedu a polomìru kružnice dané tøemi body

	\param	p1	a parameter of type const T&, první bod
	\param	p2	a parameter of type const T&, druhý bod
	\param	p3	a parameter of type const T&, tøetí bod
	\param	ps	a parameter of type T&, vypoètený støed

	\return	template <typename T> double, polomìr kružnice, -1 pokud jsou body na pøímce

	
*/
template <typename T> double CircleCentre( const T& p1, const T& p2, const T& p3, T& ps)
{  double c2, c3, d;
   double p2_X = p2.X - p1.X;
   double p2_Y = p2.Y - p1.Y;
   double p3_X = p3.X - p1.X;
   double p3_Y = p3.Y - p1.Y;
   d = p2_X*p3_Y - p2_Y*p3_X;
   if (fabs(d) < FLT_EPSILON) return -1;
   d *= 2;
   c2 = - p3_X*p3_X - p3_Y*p3_Y;
   c3 = + p2_X*p2_X + p2_Y*p2_Y;
   ps.X = (p2_Y*c2 + p3_Y*c3)/d;
   ps.Y = -(p2_X*c2 + p3_X*c3)/d;
   double res = hypot (ps.X, ps.Y);
   ps.X += p1.X ; ps.Y += p1.Y;
   return res;
}


}; //g2d
}; //gepro
}; //cz
/**
 @}
 */
#endif
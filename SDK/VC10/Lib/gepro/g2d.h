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
/**	@addtogroup geometry Geometrick� typy a funkce
    @{
    \brief g2d Namespace: obsahuje z�kladn� geometrick� funkce ve 2D.
    V �ablon�ch kde je typ T jako bod, mus� m�t public �leny double X a double Y.

*/
namespace g2d {
#ifdef PI
#undef PI
#endif
static double PI = M_PI;
static double PIx2 = 2*M_PI;
static double EPS = DBL_EPSILON;
static double EPS2 = 1e-6;


/**	\brief	The Direction function: v�po�et sm�rniku z bodu p1 na bod p2 a vzdalenosti p1,p2

	\param	p1	a parameter of type const T&,  bod z n�j� se po�it� (stanovisko)
	\param	p2	a parameter of type const T&,  bod k n�mu� se po�it�
	\param	dist	a parameter of type double&,  vypo�ten� vzd�lenost

	\return	template <class T> double - sm�rn�k z bodu p1 na na bod p2 v radianech v rozmez� 0 - 2PI

	
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

/**	\brief	The Direction function: v�po�et sm�rniku z bodu p1 na bod p2

	\param	p1	a parameter of type const T&,  bod z n�j� se po�it� (stanovisko)
	\param	p2	a parameter of type const T&,  bod k n�mu� se po�it�

	\return	template <class T> double - sm�rn�k z bodu p1 na na bod p2 v radianech v rozmez� 0 - 2PI


*/
template <class T> double Direction(const T& p1, const T& p2)
{  double dy=p2.Y-p1.Y;
   double dx=p2.X-p1.X;
   double dir = atan2( dy, dx);
   if (dir < 0.) dir += PIx2;
   return dir;
}


/**	\brief	The AnglePos function: v�po�et �hlu na bod� p1 od p0 k p2 po sm�ru rotace (v pravoto�iv� soustav� je to levostrann� �hel)

	\param	p0	a parameter of type const T&,  koncov� bod prvn�ho ramene po��tan�ho �hlu
	\param	p1	a parameter of type const T&,  bod vrchol po��tan�ho �hlu
	\param	p2	a parameter of type const T&,  koncov� bod druh�ho ramene po��tan�ho �hlu

	\return	template <class T> double - �hel  v radianech v rozmez� < 0 - 2PI)

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


/**	\brief	The AngleNeg function: v�po�et �hlu na bod� p1 od p0 k p2 proti sm�ru rotace (v pravoto�iv� soustav� je to pravostrann� �hel)

	\param	p0	a parameter of type const T&,  koncov� bod prvn�ho ramene po��tan�ho �hlu
	\param	p1	a parameter of type const T&,  bod vrchol po��tan�ho �hlu
	\param	p2	a parameter of type const T&,  koncov� bod druh�ho ramene po��tan�ho �hlu

	\return	template <class T> double - �hel  v  v radianech v rozmez� < 0 - 2PI )

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


/**	\brief	The AngleConvex function: v�po�et konvexn�ho �hlu na bod� p1 od p0 k p2

	\param	p0	a parameter of type const T&,  koncov� bod prvn�ho ramene po��tan�ho �hlu
	\param	p1	a parameter of type const T&,  bod vrchol po��tan�ho �hlu
	\param	p2	a parameter of type const T&,  koncov� bod druh�ho ramene po��tan�ho �hlu

	\return	template <class T> double - konvexn� �hel  v radianech v rozmez� < 0 - PI >

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


/**	\brief	The DirectRay function: v�po�et raj�nu

	\param	orig	a parameter of type const T&,  bod z n�j� se po�it� (stanovisko)
	\param	l	a parameter of type double,  d�lka na ur�ovan� bod
	\param	alfa	a parameter of type double,  sm�rn�k na ur�ovan� bod v rad
	\param	p	a parameter of type T&,  vypo�ten� bod

	\return	template <class T> void

	
*/
template <class T> void DirectRay(const T& orig, double l, double alfa, T& p)
{
  p.X = orig.X + l*cos(alfa);
  p.Y = orig.Y + l*sin(alfa);
}

/**	\brief	The PointPointDist function: v�po�et vzd�lenosti dvou bod�

	\param	p1	a parameter of type const T&,  prvn� bod
	\param	p2	a parameter of type const T&,  druh� bod

	\return	template <class T> double,  vzd�lenost bod�

	
*/
template <class T> double PointPointDist(const T& p1,const T& p2)
{
  return hypot( p1.X - p2.X, p1.Y - p2.Y);
}


/**	\brief	The PointLineFoot function: v�po�et orientovan� vzd�lenosti bodu od orientovan� p��mky a paty kolmice z bodu na p��mku

	\param	p	a parameter of type const T&,   bod k n�mu� se po��t� vzd�lenost a pata kolmice
	\param	pl	a parameter of type const T&,   po��te�n� bod orientovan� p��mky
	\param	smer	a parameter of type double, sm�r p��mky v rad.
	\param	pp	a parameter of type T&,  spo�ten� pata kolmice na p��mku

	\return	template <class T> double, orientovan� vzd�lenost bodu od p��mky kladn� hodnota, bod je vpravo, z�porn� vlevo

	
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

/**	\brief	The PointLineFoot function: v�po�et orientovan� vzd�lenosti bodu od orientovan� p��mky a paty kolmice z bodu na p��mku

	\param	p	a parameter of type const T&,   bod k n�mu� se po��t� vzd�lenost a pata kolmice
	\param	a	a parameter of type const T&,   po��te�n� bod orientovan� p��mky
	\param	b	a parameter of type const T&,   druh� bod orientovan� p��mky
	\param	pp	a parameter of type T&,  spo�ten� pata kolmice na p��mku

	\return	template <class T> double, orientovan� vzd�lenost bodu od p��mky kladn� hodnota, bod je vpravo, z�porn� vlevo

	
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


/**	\brief	The PointLineDist function: v�po�et vzd�lenosti bodu od p��mky

	\param	a	a parameter of type const T&,   bod prvn� bod p��mky
	\param	b	a parameter of type const T&,   druh� bod p��mky
	\param	p 	a parameter of type const T&,   bod jeho� vzd�lenost se po��t�


	\return	template <class T> double, vzd�lenost bodu p p��mky ab

	
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
/**	\brief	The PointLineRelation function: v�po�et polohy bodu v��i p��mce
	\param	p 	a parameter of type const T&,   bod jeho� poloha v��i p��mce se po��t�
	\param	a	a parameter of type const T&,   bod prvn� bod p��mky
	\param	b	a parameter of type const T&,   druh� bod p��mky
	\param	pp	a parameter of type T&,   pata kolmice z bodu na p��mku
	\param	lp	a parameter of type T&,   x stani�en�, y kolmice + right, - left v pravoto�iv� soustav�
	\return	 double poloha bodu na �se�ce a,b < 0 p�ed prvn�m bodem > 1, za druh�m bodem, 0.5 uprost�ed 
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



/**	\brief	The PointSegmentDist function: v�po�et vzd�lenosti bodu od �se�ky

	\param	a	a parameter of type const T&,   bod prvn� bod �se�ky
	\param	b	a parameter of type const T&,   druh� bod �se�ky
	\param	p 	a parameter of type const T&,   bod jeho� vzd�lenost se po��t�


	\return	template <class T> double, vzd�lenost bodu p �se�ky ab

	
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

/**	\brief	The Area function: v�po�et plochy ohrani�en� body

	\param	p	a parameter of type const T&,  pole bod�
	\param	cnt	a parameter of type int,       po�et bod�

	\return	double, plocha ohrani�en� body +pokud jsou uspo��d�ny souhlasn� se soustavou,
                    - pokud jsou protism�rn�

	
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

/**	\brief	The CircleCentre function: v�po�et st�edu a polom�ru kru�nice dan� t�emi body

	\param	p1	a parameter of type const T&, prvn� bod
	\param	p2	a parameter of type const T&, druh� bod
	\param	p3	a parameter of type const T&, t�et� bod
	\param	ps	a parameter of type T&, vypo�ten� st�ed

	\return	template <typename T> double, polom�r kru�nice, -1 pokud jsou body na p��mce

	
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
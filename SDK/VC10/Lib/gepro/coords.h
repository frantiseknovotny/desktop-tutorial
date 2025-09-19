#ifndef __SDK_GEPRO_COORDS_H
#define __SDK_GEPRO_COORDS_H

namespace cz {
namespace gepro {
 /**	Hodnoty pouzivane v Kokesovi a v knihovnach proj32(64).dll pro rozliseni souradnicovych
        systemu. Hodnoty se ukladaji primo do vykresu, nesmi se tedy v zadnem pripade
        zmenit. Je mozne pouze pridavat.
*/

	enum {
		  COORDS_KROVAK     =0x1,           // soustava krovak Krovakovo zobr. Elipsoid Bessel
		  COORDS_GAUSS      =0x2,           // Gauss-Kruegerovo zobr. syst. S42 3. pas 
		  COORDS_JTSK       =COORDS_KROVAK,
		  COORDS_GK         =COORDS_GAUSS,
		  COORDS_USER       =16,            // uzivatelska soustava zobrazuje se vzdy bez prepoctu
		  COORDS_MARIN      =17,            // Marinovo zobrazeni
		  COORDS_AITOV      =18,            // Aitovovo zobrazeni
		  COORDS_GAUSS3     =COORDS_GAUSS,  // Gauss-Kruegerovo zobr. syst. S42 3. pas
		  COORDS_GAUSS4     =19,            // Gauss-Kruegerovo zobr. syst. S42 4. pas
		  COORDS_GAUSS2     =20,            // Gauss-Kruegerovo zobr. syst. S42 2. pas
		  COORDS_MERCATOR   =21,            // Mercatorovo zobr. v norm poloze
		  COORDS_AUSTRIA_M28=22,            // rakousky lokalni system, neni implementovan pro zobrazovani!
		  COORDS_AUSTRIA_M31=23,            // rakousky lokalni system, neni implementovan pro zobrazovani!
		  COORDS_AUSTRIA_M34=24,            // rakousky lokalni system, neni implementovan pro zobrazovani!
          COORDS_JTSKN      =25,       // JTSK s modifikaci severni poloviny aby se kuzel uzavrel,
                                       // pro X>=0 je to stejne jako JTSK

          COORDS_PSAD65_CH_S_18 =26,   // UTM 18.pas - Provisional South American 1956 - Chile (Southern)
          COORDS_PSAD65_CH_S_19 =27,   // UTM 19.pas - Provisional South American 1956 - Chile (Southern)
          COORDS_PSAD65_CH_N_18 =28,   // UTM 18.pas - Provisional South American 1956 - Chile (Northern)
          COORDS_PSAD65_CH_N_19 =29,   // UTM 19.pas - Provisional South American 1956 - Chile (Northern)

		  COORDS_GAUSS5  =35,          // Gauss-Kruegerovo zobr. syst. S42  5. pas
		  COORDS_GAUSS6  =36,          // Gauss-Kruegerovo zobr. syst. S42  6. pas
		  COORDS_GAUSS7  =37,          // Gauss-Kruegerovo zobr. syst. S42  7. pas
		  COORDS_GAUSS8  =38,          // Gauss-Kruegerovo zobr. syst. S42  8. pas
		  COORDS_GAUSS9  =39,          // Gauss-Kruegerovo zobr. syst. S42  9. pas
		  COORDS_GAUSS10 =40,          // Gauss-Kruegerovo zobr. syst. S42 10. pas
		  COORDS_GAUSS11 =41,          // Gauss-Kruegerovo zobr. syst. S42 11. pas
		  COORDS_GAUSS12 =42,          // Gauss-Kruegerovo zobr. syst. S42 12. pas
		  COORDS_GAUSS13 =43,          // Gauss-Kruegerovo zobr. syst. S42 13. pas
		  COORDS_GAUSS14 =44,          // Gauss-Kruegerovo zobr. syst. S42 14. pas
		  COORDS_GAUSS15 =45,          // Gauss-Kruegerovo zobr. syst. S42 15. pas
		  COORDS_GAUSS16 =46,          // Gauss-Kruegerovo zobr. syst. S42 16. pas
		  COORDS_GAUSS17 =47,          // Gauss-Kruegerovo zobr. syst. S42 17. pas
		  COORDS_GAUSS18 =48,          // Gauss-Kruegerovo zobr. syst. S42 18. pas
		  COORDS_GAUSS19 =49,          // Gauss-Kruegerovo zobr. syst. S42 19. pas
		  COORDS_GAUSS20 =50,          // Gauss-Kruegerovo zobr. syst. S42 20. pas
		  COORDS_GAUSS21 =51,          // Gauss-Kruegerovo zobr. syst. S42 21. pas
		  COORDS_GAUSS22 =52,          // Gauss-Kruegerovo zobr. syst. S42 22. pas
		  COORDS_GAUSS23 =53,          // Gauss-Kruegerovo zobr. syst. S42 23. pas
		  COORDS_GAUSS24 =54,          // Gauss-Kruegerovo zobr. syst. S42 24. pas
		  COORDS_GAUSS25 =55,          // Gauss-Kruegerovo zobr. syst. S42 25. pas
		  COORDS_GAUSS26 =56,          // Gauss-Kruegerovo zobr. syst. S42 26. pas
		  COORDS_GAUSS27 =57,          // Gauss-Kruegerovo zobr. syst. S42 27. pas
		  COORDS_GAUSS28 =58,          // Gauss-Kruegerovo zobr. syst. S42 28. pas
		  COORDS_GAUSS29 =59,          // Gauss-Kruegerovo zobr. syst. S42 29. pas
		  COORDS_GAUSS30 =60,          // Gauss-Kruegerovo zobr. syst. S42 30. pas
		  COORDS_GAUSS31 =61,          // Gauss-Kruegerovo zobr. syst. S42 31. pas
		  COORDS_GAUSS32 =62,          // Gauss-Kruegerovo zobr. syst. S42 32. pas
		  COORDS_GAUSS33 =63,          // Gauss-Kruegerovo zobr. syst. S42 33. pas
		  COORDS_GAUSS34 =64,          // Gauss-Kruegerovo zobr. syst. S42 34. pas
		  COORDS_GAUSS35 =65,          // Gauss-Kruegerovo zobr. syst. S42 35. pas
		  COORDS_GAUSS36 =66,          // Gauss-Kruegerovo zobr. syst. S42 36. pas
		  COORDS_GAUSS37 =67,          // Gauss-Kruegerovo zobr. syst. S42 37. pas
		  COORDS_GAUSS38 =68,          // Gauss-Kruegerovo zobr. syst. S42 38. pas
		  COORDS_GAUSS39 =69,          // Gauss-Kruegerovo zobr. syst. S42 39. pas
		  COORDS_GAUSS40 =70,          // Gauss-Kruegerovo zobr. syst. S42 40. pas
    //tady by mohly byt pasy az do 60. COORDS_GAUSS41 =71 ; COORDS_GAUSS60 =90
    //ale nepredpokladam, ze by byly potreba. Tohle staci pres Sibir az na Aljasku.
                                                
		  COORDS_UTM01CM  =101,         // UTM WGS84  1.pas C-M (jizni)
		  COORDS_UTM01NX  =102,         // UTM WGS84  1.pas N-X (severni)
		  COORDS_UTM02CM  =103,         // UTM WGS84  2.pas C-M (jizni)
		  COORDS_UTM02NX  =104,         // UTM WGS84  2.pas N-X (severni)
		  COORDS_UTM03CM  =105,         // UTM WGS84  3.pas C-M (jizni)
		  COORDS_UTM03NX  =106,         // UTM WGS84  3.pas N-X (severni)
		  COORDS_UTM04CM  =107,         // UTM WGS84  4.pas C-M (jizni)
		  COORDS_UTM04NX  =108,         // UTM WGS84  4.pas N-X (severni)
		  COORDS_UTM05CM  =109,         // UTM WGS84  5.pas C-M (jizni)
		  COORDS_UTM05NX  =110,         // UTM WGS84  5.pas N-X (severni)
		  COORDS_UTM06CM  =111,         // UTM WGS84  6.pas C-M (jizni)
		  COORDS_UTM06NX  =112,         // UTM WGS84  6.pas N-X (severni)
		  COORDS_UTM07CM  =113,         // UTM WGS84  7.pas C-M (jizni)
		  COORDS_UTM07NX  =114,         // UTM WGS84  7.pas N-X (severni)
		  COORDS_UTM08CM  =115,         // UTM WGS84  8.pas C-M (jizni)
		  COORDS_UTM08NX  =116,         // UTM WGS84  8.pas N-X (severni)
		  COORDS_UTM09CM  =117,         // UTM WGS84  9.pas C-M (jizni)
		  COORDS_UTM09NX  =118,         // UTM WGS84  9.pas N-X (severni)
		  COORDS_UTM10CM  =119,         // UTM WGS84 10.pas C-M (jizni)
		  COORDS_UTM10NX  =120,         // UTM WGS84 10.pas N-X (severni)
		  COORDS_UTM11CM  =121,         // UTM WGS84 11.pas C-M (jizni)
		  COORDS_UTM11NX  =122,         // UTM WGS84 11.pas N-X (severni)
		  COORDS_UTM12CM  =123,         // UTM WGS84 12.pas C-M (jizni)
		  COORDS_UTM12NX  =124,         // UTM WGS84 12.pas N-X (severni)
		  COORDS_UTM13CM  =125,         // UTM WGS84 13.pas C-M (jizni)
		  COORDS_UTM13NX  =126,         // UTM WGS84 13.pas N-X (severni)
		  COORDS_UTM14CM  =127,         // UTM WGS84 14.pas C-M (jizni)
		  COORDS_UTM14NX  =128,         // UTM WGS84 14.pas N-X (severni)
		  COORDS_UTM15CM  =129,         // UTM WGS84 15.pas C-M (jizni)
		  COORDS_UTM15NX  =130,         // UTM WGS84 15.pas N-X (severni)
		  COORDS_UTM16CM  =131,         // UTM WGS84 16.pas C-M (jizni)
		  COORDS_UTM16NX  =132,         // UTM WGS84 16.pas N-X (severni)
		  COORDS_UTM17CM  =133,         // UTM WGS84 17.pas C-M (jizni)
		  COORDS_UTM17NX  =134,         // UTM WGS84 17.pas N-X (severni)
		  COORDS_UTM18CM  =135,         // UTM WGS84 18.pas C-M (jizni)
		  COORDS_UTM18NX  =136,         // UTM WGS84 18.pas N-X (severni)
		  COORDS_UTM19CM  =137,         // UTM WGS84 19.pas C-M (jizni)
		  COORDS_UTM19NX  =138,         // UTM WGS84 19.pas N-X (severni)

		  COORDS_UTM20CM  =139,         // UTM WGS84 20.pas C-M (jizni)
		  COORDS_UTM20NX  =140,         // UTM WGS84 20.pas N-X (severni)
		  COORDS_UTM21CM  =141,         // UTM WGS84 21.pas C-M (jizni)
		  COORDS_UTM21NX  =142,         // UTM WGS84 21.pas N-X (severni)
		  COORDS_UTM22CM  =143,         // UTM WGS84 22.pas C-M (jizni)
		  COORDS_UTM22NX  =144,         // UTM WGS84 22.pas N-X (severni)
		  COORDS_UTM23CM  =145,         // UTM WGS84 23.pas C-M (jizni)
		  COORDS_UTM23NX  =146,         // UTM WGS84 23.pas N-X (severni)
		  COORDS_UTM24CM  =147,         // UTM WGS84 24.pas C-M (jizni)
		  COORDS_UTM24NX  =148,         // UTM WGS84 24.pas N-X (severni)
		  COORDS_UTM25CM  =149,         // UTM WGS84 25.pas C-M (jizni)
		  COORDS_UTM25NX  =150,         // UTM WGS84 25.pas N-X (severni)
		  COORDS_UTM26CM  =151,         // UTM WGS84 26.pas C-M (jizni)
		  COORDS_UTM26NX  =152,         // UTM WGS84 26.pas N-X (severni)
		  COORDS_UTM27CM  =153,         // UTM WGS84 27.pas C-M (jizni)
		  COORDS_UTM27NX  =154,         // UTM WGS84 27.pas N-X (severni)
		  COORDS_UTM28CM  =155,         // UTM WGS84 28.pas C-M (jizni)
		  COORDS_UTM28NX  =156,         // UTM WGS84 28.pas N-X (severni)
		  COORDS_UTM29CM  =157,         // UTM WGS84 29.pas C-M (jizni)
		  COORDS_UTM29NX  =158,         // UTM WGS84 29.pas N-X (severni)

		  COORDS_UTM30CM  =159,         // UTM WGS84 30.pas C-M (jizni)
		  COORDS_UTM30NX  =160,         // UTM WGS84 30.pas N-X (severni)
		  COORDS_UTM31CM  =161,         // UTM WGS84 31.pas C-M (jizni)
		  COORDS_UTM31NX  =162,         // UTM WGS84 31.pas N-X (severni)
		  COORDS_UTM32CM  =163,         // UTM WGS84 32.pas C-M (jizni)
		  COORDS_UTM32NX  =164,         // UTM WGS84 32.pas N-X (severni)
		  COORDS_UTM33CM  =165,         // UTM WGS84 33.pas C-M (jizni)
		  COORDS_UTM33NX  =166,         // UTM WGS84 33.pas N-X (severni)
		  COORDS_UTM34CM  =167,         // UTM WGS84 34.pas C-M (jizni)
		  COORDS_UTM34NX  =168,         // UTM WGS84 34.pas N-X (severni)
		  COORDS_UTM35CM  =169,         // UTM WGS84 35.pas C-M (jizni)
		  COORDS_UTM35NX  =170,         // UTM WGS84 35.pas N-X (severni)
		  COORDS_UTM36CM  =171,         // UTM WGS84 36.pas C-M (jizni)
		  COORDS_UTM36NX  =172,         // UTM WGS84 36.pas N-X (severni)
		  COORDS_UTM37CM  =173,         // UTM WGS84 37.pas C-M (jizni)
		  COORDS_UTM37NX  =174,         // UTM WGS84 37.pas N-X (severni)
		  COORDS_UTM38CM  =175,         // UTM WGS84 38.pas C-M (jizni)
		  COORDS_UTM38NX  =176,         // UTM WGS84 38.pas N-X (severni)
		  COORDS_UTM39CM  =177,         // UTM WGS84 39.pas C-M (jizni)
		  COORDS_UTM39NX  =178,         // UTM WGS84 39.pas N-X (severni)

		  COORDS_UTM40CM  =179,         // UTM WGS84 40.pas C-M (jizni)
		  COORDS_UTM40NX  =180,         // UTM WGS84 40.pas N-X (severni)
		  COORDS_UTM41CM  =181,         // UTM WGS84 41.pas C-M (jizni)
		  COORDS_UTM41NX  =182,         // UTM WGS84 41.pas N-X (severni)
		  COORDS_UTM42CM  =183,         // UTM WGS84 42.pas C-M (jizni)
		  COORDS_UTM42NX  =184,         // UTM WGS84 42.pas N-X (severni)
		  COORDS_UTM43CM  =185,         // UTM WGS84 43.pas C-M (jizni)
		  COORDS_UTM43NX  =186,         // UTM WGS84 43.pas N-X (severni)
		  COORDS_UTM44CM  =187,         // UTM WGS84 44.pas C-M (jizni)
		  COORDS_UTM44NX  =188,         // UTM WGS84 44.pas N-X (severni)
		  COORDS_UTM45CM  =189,         // UTM WGS84 45.pas C-M (jizni)
		  COORDS_UTM45NX  =190,         // UTM WGS84 45.pas N-X (severni)
		  COORDS_UTM46CM  =191,         // UTM WGS84 46.pas C-M (jizni)
		  COORDS_UTM46NX  =192,         // UTM WGS84 46.pas N-X (severni)
		  COORDS_UTM47CM  =193,         // UTM WGS84 47.pas C-M (jizni)
		  COORDS_UTM47NX  =194,         // UTM WGS84 47.pas N-X (severni)
		  COORDS_UTM48CM  =195,         // UTM WGS84 48.pas C-M (jizni)
		  COORDS_UTM48NX  =196,         // UTM WGS84 48.pas N-X (severni)
		  COORDS_UTM49CM  =197,         // UTM WGS84 49.pas C-M (jizni)
		  COORDS_UTM49NX  =198,         // UTM WGS84 49.pas N-X (severni)

		  COORDS_UTM50CM  =199,         // UTM WGS84 50.pas C-M (jizni)
		  COORDS_UTM50NX  =200,         // UTM WGS84 50.pas N-X (severni)
		  COORDS_UTM51CM  =201,         // UTM WGS84 51.pas C-M (jizni)
		  COORDS_UTM51NX  =202,         // UTM WGS84 51.pas N-X (severni)
		  COORDS_UTM52CM  =203,         // UTM WGS84 52.pas C-M (jizni)
		  COORDS_UTM52NX  =204,         // UTM WGS84 52.pas N-X (severni)
		  COORDS_UTM53CM  =205,         // UTM WGS84 53.pas C-M (jizni)
		  COORDS_UTM53NX  =206,         // UTM WGS84 53.pas N-X (severni)
		  COORDS_UTM54CM  =207,         // UTM WGS84 54.pas C-M (jizni)
		  COORDS_UTM54NX  =208,         // UTM WGS84 54.pas N-X (severni)
		  COORDS_UTM55CM  =209,         // UTM WGS84 55.pas C-M (jizni)
		  COORDS_UTM55NX  =210,         // UTM WGS84 55.pas N-X (severni)
		  COORDS_UTM56CM  =211,         // UTM WGS84 56.pas C-M (jizni)
		  COORDS_UTM56NX  =212,         // UTM WGS84 56.pas N-X (severni)
		  COORDS_UTM57CM  =213,         // UTM WGS84 57.pas C-M (jizni)
		  COORDS_UTM57NX  =214,         // UTM WGS84 57.pas N-X (severni)
		  COORDS_UTM58CM  =215,         // UTM WGS84 58.pas C-M (jizni)
		  COORDS_UTM58NX  =216,         // UTM WGS84 58.pas N-X (severni)
		  COORDS_UTM59CM  =217,         // UTM WGS84 59.pas C-M (jizni)
		  COORDS_UTM59NX  =218,         // UTM WGS84 59.pas N-X (severni)
		  COORDS_UTM60CM  =219,         // UTM WGS84 60.pas C-M (jizni)
		  COORDS_UTM60NX  =220,         // UTM WGS84 60.pas N-X (severni)

	      COORDS_LKS94    =250,         // Litevsky souradnicovy system na bazi WGS84
	      COORDS_LG4      =251,         // Souradny system pouzity pro rastrovou mapu Lotyska (S42-L0=24)

          COORDS_LCC_3244_100W = 300,   // Lambert conformal conic, Nort America
                                        // 1st Standard Latitude = 32
                                        // 2nd Standard Latitude = 44
                                        // Center Latitude  =  38
                                        // Center Longitude =-100
	      COORDS_WGS84=18001,           // Zemepisne souradnice WGS84
          COORDS_JTSK_EL_F=18002,       // Zemepisne souradnice JTSK (Ferro)
          COORDS_JTSK_EL_G=18003        // Zemepisne souradnice JTSK (Greenwich)
};

}; //gepro
}; //cz


#endif
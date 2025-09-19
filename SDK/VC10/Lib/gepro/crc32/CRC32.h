#ifndef __CRC32_H
#define __CRC32_H
#if defined(DEBUG_PREPROC)
#pragma message(__FILE__ "(1) : debug included")
#endif
///Trida pro vypocet CRC32
///Pocita standardni CRC-32, krety pouziva
/// (napr. PKZip, WinZip)

class CRC32 {
    static const unsigned int CRC32Table[];
    unsigned int crc;
  public:
    ///konstruktor provadi zaroven to co Init()
    CRC32(void):crc(0xFFFFFFFF){;}
    ///Init nastavi pocatecni stav.
    ///Je potreba zavolat pred kazdym vypoctem vyjma prvniho vypoctu
    ///po vytvoreni objektu.
    void Init(void){
      crc = 0xFFFFFFFF;
    }
    ///Pocita pripadne pokracuje ve vypoctu CRC, Buffer jsou data
    ///pro nez se to pocita, BufferLength je jejich delka.
    void Update(const char* Buffer, unsigned int BufferLength) {
      unsigned int index, i;
      for(i=0;i<BufferLength;i++) {
          index = (crc ^ *(Buffer+i)) & 0x000000FF;
          crc = ((crc >> 8) & 0x00FFFFFF) ^ CRC32Table[index];
      }
    }
    /**	\brief	The Update function, zahrne do výpoètu obsah pamìti pro
      uložení pøíslušného typu. CRC32.Update(int) nepøipoète hodnotu int,
      ale celý kus pamìti v nìmž je int.

	    \param	p	a parameter of type const T&

	    \return	template <class T>

	    
    */
    template <class T> void Update(const T& p) {
       const char* Buffer=reinterpret_cast<const char*>(&p);
       Update(Buffer, sizeof(p));
    }
    ///Vrati vysledny CRC.
    ///Nez se zacne pocitat dalsi je treba zavolat Init();
    unsigned int Final(void) {
      return (crc ^ 0xFFFFFFFF);
    }
};
#endif


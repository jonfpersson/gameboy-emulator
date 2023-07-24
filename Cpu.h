#include <stdio.h>
#include <iostream>
#include <fstream>
#ifndef CPU
#define CPU

typedef unsigned char BYTE;
typedef char SIGNED_BYTE;
typedef unsigned short WORD;
typedef signed short SIGNED_WORD;

class Cpu {
    public:
    private:
        BYTE m_Cartridge[0x200000] ;

    void CPUReset()
    {
        FILE *in;
        in = fopen("game", "rb");
        fread(&m_Cartridge[0], 0x200000, 1, in);
        fclose(in);
    }

};

#endif
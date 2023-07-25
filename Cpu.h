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
    private:
        BYTE m_Cartridge[0x200000] ;
        BYTE m_Rom[0x10000] ;


    void CPUReset()
    {
        FILE *in;
        in = fopen("game", "rb");
        fread(&m_Cartridge[0], 0x200000, 1, in);
        fclose(in);
    }

    public:
        void run( )
        {
            const int MAXCYCLES = 4194304/60;
            int cyclesThisUpdate = 0;

            while (cyclesThisUpdate < MAXCYCLES)
            {
                int cycles = ExecuteNextOpcode();
                cyclesThisUpdate+=cycles;
                UpdateTimers(cycles);
                UpdateGraphics(cycles);
                DoInterupts();
            }
            RenderScreen();
        }


};

#endif
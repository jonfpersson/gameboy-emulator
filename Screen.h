#include <stdio.h>
#include <iostream>
#include <fstream>
#ifndef SCREEN
#define SCREEN

typedef unsigned char BYTE;
typedef char SIGNED_BYTE;
typedef unsigned short WORD;
typedef signed short SIGNED_WORD;

class Cpu {
    public:

    private:
        BYTE m_ScreenData[160][144][3];


};

#endif
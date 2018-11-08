#include "exibir.hpp"
#include <windows.h>

int  mgotoxy(int C, int L)
{
    COORD p = {C,L};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
    return 0;
}

int comparar(PL **abb, string plN)
{
    if((*abb)->pl < plN)
        return 0;
    if((*abb)->pl > plN)
        return 1;
    if((*abb)->pl == plN)
        return -1;
}


#include "exibir.hpp"
#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

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

int add(PL **abb, string plN, ofstream &arq)
{
    if (*abb==NULL)
    {

        PL *tmp = (PL*)malloc(sizeof(PL));
        tmp->pl = plN;
        arq << plN << endl;
        tmp->cont = 0;
        tmp->maior = NULL;
        tmp->menor = NULL;
        *abb = tmp;
        return 0;
    }
    int t = comparar(&(*abb),plN);
    if (t == 0)
        add(&(*abb)->menor,plN,arq);
    else if (t == 1)
        add(&(*abb)->maior,plN,arq);
    else
        (*abb)->cont++;
}

int  vPL(PL **abb, string op2, int x)
{
    if(*abb == NULL)
    {
        return 0;
    }
    string pl3 = (*abb)->pl;
    pl3.resize(x+1);
        if(op2 == pl3)
        {
            cout << (*abb)->pl << "\n";
            vPL(&(*abb)->maior, op2, x);
        }
        else
            vPL(&(*abb)->menor, op2, x);

}



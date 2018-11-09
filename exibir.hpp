#ifndef _EXIBIR_H
#define _EXIBIR_H
#include "struct.hpp"
#include <fstream>

using namespace std;

string toString(string pl);
int  mgotoxy(int C, int L);
int comparar(PL **abb, string plN);
int add(PL **abb, string plN, ofstream &);
int  vPL(PL **abb, string op2, int x);

#endif

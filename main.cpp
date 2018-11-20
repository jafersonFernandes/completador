#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <windows.h>
#include "exibir.hpp"
#include "struct.hpp"

using namespace std;

int main()
{
    PL *abb = NULL;
    //PLF *raiz = NULL;
    FRASE *Frase = InicializaFrase();
    string pl = "";
    char ch;
    capturar(pl, ch, &abb, Frase);
    //pl = upF(&raiz, pl);
    //cout << pl << "\n";
    exibirF(Frase);
    return 0;

}


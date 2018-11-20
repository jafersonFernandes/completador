#ifndef _EXIBIR_H
#define _EXIBIR_H
#include "struct.hpp"

using namespace std;

void mgotoxy(int C, int L);
int comparar(PL **abb, string plN);
void add(PL **abb, string plN);
void vPL(PL **abb, string pl);
//void addPLF(PLF **raiz, string pl);
//void capturar(string pl, char ch, PL **abb, PLF **raiz);
void capturar(string pl, char ch, PL **abb, FRASE *Frase);
void exibir(PL **abb);
//void exibirF(PLF **raiz);
int tf(PLF **raiz);
string upF(FRASE *Frase, string pl);
void addPLF(FRASE *Frase, string pl);
FRASE *InicializaFrase();
void exibirF(FRASE *Frase);

#endif

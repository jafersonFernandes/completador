#ifndef _STRUCT_H
#define _STRUCT_H
#include <string>

using namespace std;


struct Palavra // arvore
{
    string  *pl;
    int cont;
    struct Palavra *maior;
    struct Palavra *menor;
};
typedef struct Palavra PL;


struct palavraF // palavra da frase
{
    string *palavra;
    struct palavraF *prox;
};
typedef struct palavraF PLF;

#endif // _STRUCT_H

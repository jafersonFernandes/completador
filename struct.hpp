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
    struct palavraF *ant;
};
typedef struct palavraF PLF;

struct listaPalavras
{
    int n;
    PLF *head;
};
typedef struct listaPalavras FRASE;

#endif // _STRUCT_H

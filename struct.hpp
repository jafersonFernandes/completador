#ifndef _STRUCT_H
#define _STRUCT_H
#include <string>

using namespace std;


struct Palavra
{
    string  pl;
    int cont;
    struct Palavra *maior;
    struct Palavra *menor;
};
typedef struct Palavra PL;

struct palavraF
{
    PL *palavra;
    struct palavraF *proxima;
    struct palavraF *anterior;
};
typedef struct palavraF PLF;


#endif // _STRUCT_H

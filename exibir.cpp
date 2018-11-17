#include "exibir.hpp"
#include <windows.h>
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

void mgotoxy(int C, int L)
{
    COORD p = {C,L};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
    return;
}

int comparar(PL **abb, string plN)
{
    if(*((*abb)->pl) < plN)
        return 0;
    if(*((*abb)->pl) > plN)
        return 1;
    if(*((*abb)->pl) == plN)
        return -1;
}

void add(PL **abb, string plN)
{
    if (*abb==NULL)
    {

        PL *tmp = (PL*)malloc(sizeof(PL));
        tmp->pl = new string;
        *(tmp->pl) += plN;
        tmp->cont = 0;
        tmp->maior = NULL;
        tmp->menor = NULL;

        *abb = tmp;
        return;
    }
    int t = comparar(&(*abb),plN);
    if (t == 0)
        add(&(*abb)->menor,plN);
    else if (t == 1)
        add(&(*abb)->maior,plN);
    else
        (*abb)->cont++;
}

void vPL(PL **abb, string pl)
{
    if(*abb == NULL)
    {
        return;
    }
    if(pl == "")
        return;
    string pl2 = *((*abb)->pl);
    pl2.resize(pl.size());
    if(pl == pl2)
    {
        vPL(&(*abb)->maior, pl);
        cout << *((*abb)->pl) << "\n";
        vPL(&(*abb)->menor, pl);
    }
    else
    {
        vPL(&(*abb)->menor, pl);
        vPL(&(*abb)->maior, pl);
    }
}

void  addPLF(PLF **raiz, PL **abb, string pl)
{
    if (*raiz == NULL)
    {
        PLF *tmp = (PLF*)malloc(sizeof(PLF));
        tmp->palavra = new string;
        *(tmp->palavra) += pl;
        tmp->prox = NULL;
        *raiz = tmp;
        return;
    }
    else
        addPLF(&(*raiz)->prox, &(*abb), pl);
}

void capturar(string pl, char ch, PL **abb, PLF **raiz)
{
    while(true)
    {
        if(kbhit())
        {
            ch = getch();
            if(ch == 27)
            break;
            if(ch != 8)
            {
                if(ch != ' ')
                {
                    ch = toupper(ch);
                    pl.push_back(ch);
                }
                else
                {
                    add(abb, pl);
                    addPLF(raiz, abb, pl);
                    pl = "";
                }
                system("cls");
                exibirF(raiz);
                cout << pl << "\n";
                vPL(abb, pl);
            }
            else
                {
                    if(pl != "") pl.resize(pl.size()-1);
                    else pl = upF(raiz, pl);
                    system("cls");
                    exibirF(raiz);
                    cout << pl << "\n";
                    vPL(abb, pl);
                }
        }
    }
    add(abb, pl);
    addPLF(raiz, abb, pl);
    pl = "";
    return;
}

void exibir(PL **abb)
{

    if(*abb != NULL)
    {
        exibir(&(*abb)->maior);
        cout << "Palavras: " << *((*abb)->pl) << "\n";
        exibir(&(*abb)->menor);
    }
    if(*abb == NULL)
    {
        return;
    }
}

void exibirF(PLF **raiz)
{

    if(*raiz != NULL)
    {
        cout << *((*raiz)->palavra) << " ";
        exibirF(&(*raiz)->prox);
    }
    if(*raiz == NULL)
    {
        return ;
    }
}

string upF(PLF **raiz, string pl)
{
    int tf = 0;
    PLF *tmp = (PLF*)malloc(sizeof(PLF));
    PLF *ant = (PLF*)malloc(sizeof(PLF));
    tmp = *raiz;
    while(tmp != NULL)
    {
        pl = *(tmp->palavra);
        if(tmp->prox != NULL) ant = tmp;
        tmp = tmp->prox;
        tf++;
    }
    ant->prox = NULL;
    if (tf == 1)
    {
        system("cls");
        pl = "";
        tmp = NULL;
        *raiz = tmp;
    }
    return pl;
}





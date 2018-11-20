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

/*void  addPLF(PLF **raiz, string pl)
{
    if (*raiz == NULL)
    {
        PLF *tmp = (PLF*)malloc(sizeof(PLF));
        tmp->palavra = new string;
        *(tmp->palavra) += pl;
        tmp->prox = NULL;
        tmp->ant = NULL;
        *raiz = tmp;
        return;
    }
    else
        addPLF(&(*raiz)->prox, pl);
}*/

void addPLF(FRASE *Frase, string pl)
{
    PLF *tmp = Frase->head;
    PLF *aux = (PLF *)malloc(sizeof(PLF));
    aux->palavra = new string;
    *(aux->palavra) += pl;
    aux-> prox = NULL;
    if (tmp == NULL)
    {
        Frase->head = aux;
        aux->ant = NULL;
    }
    else
    {
        while (tmp->prox)
        {
            tmp = tmp->prox ;
        }
        aux->ant = tmp;
        tmp->prox = aux;
    }
    Frase->n++;
    return;
}

void capturar(string pl, char ch, PL **abb, FRASE *Frase)
{
    int C = 0;
    int L = 0;
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
                    addPLF(Frase, pl);
                    pl = "";
                }
                system("cls");
                exibirF(Frase);
                cout << pl << "\n";
                vPL(abb, pl);
            }
            else
            {
                if(pl != "")
                {
                    pl.resize(pl.size()-1);
                    system("cls");
                    exibirF(Frase);
                    cout << pl << "\n";
                    vPL(abb, pl);
                }
                else
                {
                    if(Frase->n == 1)
                    {
                        system("cls");
                        pl = upF(Frase, pl);
                        cout << pl;
                    }
                    else
                    {
                        pl = upF(Frase, pl);
                        system("cls");
                        exibirF(Frase);
                        cout << pl << "\n";
                        vPL(abb, pl);
                    }
                }
            }
        }
    }
    add(abb, pl);
    addPLF(Frase, pl);
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

/*void exibirF(PLF **raiz)
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
}*/

string upF(FRASE *Frase, string pl)
{
    PLF *tmp = Frase->head;
    while (tmp->prox)
    {
        tmp = tmp->prox;
    }
    if(tmp->ant == NULL)
    {
       pl = *(tmp->palavra);
       tmp->prox = NULL;
       *(tmp->palavra) = "";
     }
     else
     {
         pl = *(tmp->palavra);
         tmp = tmp->ant;
         tmp->prox = NULL;
     }
Frase->n--;
    return pl;
}

FRASE *InicializaFrase()
{
    FRASE *Frase = (FRASE *)malloc(sizeof(FRASE));
    Frase->n = 0;
    Frase->head = NULL;
    return Frase;
}

void exibirF(FRASE *Frase)
{
    PLF *tmp = Frase->head;
    if(tmp == NULL)
        return;
    while (tmp)
    {
        if(*(tmp->palavra) != "") cout << *(tmp->palavra) << " ";
        tmp = tmp->prox;
    }
    return;
}






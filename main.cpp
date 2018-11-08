#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string>

using namespace std;

int  mgotoxy(int C, int L)
{
    COORD p = {C,L};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
    return 0;
}

struct Palavra
{
    string  pl;
    int cont;
    struct Palavra *maior;
    struct Palavra *menor;
};
typedef struct Palavra PL;

int comparar(PL **abb, string plN)
{
    if((*abb)->pl < plN)
        return 0;
    if((*abb)->pl > plN)
        return 1;
    if((*abb)->pl == plN)
        return -1;
}

int add(PL **abb, string plN)
{
    if (*abb==NULL)
    {

        PL *tmp = (PL*)malloc(sizeof(PL));
        tmp->pl = plN;
        tmp->cont = 0;
        tmp->maior = NULL;
        tmp->menor = NULL;

        *abb = tmp;
        return 0;
    }
    int t = comparar(&(*abb),plN);
    if (t == 0)
        add(&(*abb)->menor,plN);
    else if (t == 1)
        add(&(*abb)->maior,plN);
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

int main()
{
    PL *abb = NULL;
    string pl = "abcdefgh";
    add(&abb,pl);
    pl = "abcdefg";
    add(&abb,pl);
    pl = "abcdef";
    add(&abb,pl);
    pl = "abcde";
    add(&abb,pl);
    pl = "abcd";
    add(&abb,pl);
    pl = "abd";
    add(&abb,pl);
    int x = 0;
    int y = 0;
    int t = 0;
    char op;
    string op2;
    string  frase;
    frase.clear();
    while(true)
    {
        if(kbhit())
        {
            p2:
            op = getch();
            if(op == 27)
                break;
            if(op != 8 && op != ' ')
            {
                op2.push_back(op);
                p3:
                system("cls");
                cout << frase + op2 << "\n";
                p1:
                vPL(&abb, op2, x);
                x++;
                y++;
                mgotoxy(y, 0);
                mgotoxy(10,10);
                cout << x;
                 mgotoxy(10,11);
                cout << y;
            }
            else if(op == ' ')
            {
                frase = frase + op2 + ' ';
                op2.clear();
                x = 0;
                y++;
                goto p2;
            }
            else if(op == 8 && x !=0)
            {
                x--;
                y= y -2;
                op2.resize(x);
                system("cls");
                cout << frase + op2 << "\n";
                x--;
                goto p1;
            }
            else if(op == 8 && x == 0)
            {
                t = frase.length()-1;
                y = t;
                while(frase[t-1] != ' ')
                {
                    t--;
                }
                while(t < frase.length())
                {
                    op2 = op2+frase[t];
                    t++;
                }
                x = op2.length()-1;
                frase.resize(frase.length()-x-1);
                goto p3;
            }
            else
                system("cls");
        }
    }
    system("cls");
    cout << "Fim";
    return 0;
}

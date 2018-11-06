#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <cstring>
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
        cout << "Palavra ja inserida" << endl;
}

int  vPL(PL **abb, string op2, int x)
{
    if(*abb == NULL)
    {
        return 0;
    }
        if(op2 [x]== (*abb)->pl[x])
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
    char op;
    string op2;
    while(true)
    {
        if(kbhit())
        {
            op = getch();
            if(op != 8)
            {
                op2.push_back(op);
                mgotoxy(0, 0);
                system("cls");
                cout << op2 << "\n";
                p1:
                vPL(&abb, op2, x);
                x++;
                mgotoxy(x, 0);
            }
            else if(op == 8 && x > 0)
            {
                x--;
                op2.resize(x);
                mgotoxy(0,0);
                system("cls");
                cout << op2 << "\n";
                x--;
                goto p1;
            }
            else
                system("cls");
        }
    }
    system("cls");
    cout << "Fim";
    return 0;
}

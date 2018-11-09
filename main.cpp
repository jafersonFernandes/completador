#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include "exibir.hpp"
#include "struct.hpp"
#include <fstream>
#include <sstream>

using namespace std;

int main()
{

    ofstream Arquivo("persistencia.txt", ios::out);
    PL *abb = NULL;
    string pl;
    add(&abb,pl,Arquivo);
    pl = "abcdefg";
    add(&abb,pl,Arquivo);
    pl = "abcdef";
    add(&abb,pl,Arquivo);
    pl = "abcde";
    add(&abb,pl,Arquivo);
    pl = "abcd";
    add(&abb,pl,Arquivo);
    pl = "abd";
    add(&abb,pl,Arquivo);
    int x = 0;
    int y = 0;
    int t = 0;
    char op;
    string op2;
    string  frase;
    frase.clear();
    ifstream Arquivo2("persistencia.txt");
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
                add(&abb,op2,Arquivo);
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
                while(frase[t-1] != ' ' && abs(t) < frase.length())
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
    Arquivo.close();
    return 0;
}

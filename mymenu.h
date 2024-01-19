#ifndef MYMENU_H_INCLUDED
#define MYMENU_H_INCLUDED

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
void arrowplace (int realposition, int arrowposition){
    if (realposition == arrowposition)
    {
        printf("\x1b[32m----->> - ");
        printf("\x1b[0m");
    }
    else
    {
        printf("          ");
    }
    }

int menu (){
    system("cls");
    int position = 1;
    int keyboard = 0;

#define MAX 4
#define MIN 1
int t = 1;
while (keyboard !=13)
{
    system("cls");
    arrowplace(1, position);
    if (position==1)
    {
    printf("\x1b[34mprevious game\n");
    printf("\x1b[0m");
    t =1;
    }
    else
    {
    printf("previous game\n");
    }

    arrowplace(2, position);
    if (position==2)
    {
    printf("\x1b[34mresume the game\n");
    printf("\x1b[0m");
    t =2;
    }
    else
    {
    printf("resume the game\n");
    }
    arrowplace(3, position);
    if (position==3)
    {
    printf("\x1b[34mtimer mode\n");
    printf("\x1b[0m");
    t = 3;
    }
    else
    {
    printf("timer mode\n");
    }
    arrowplace(4, position);
    if (position==4)
    {
    printf("\x1b[34mexit\n");
    printf("\x1b[0m");
    t = 4;
    }
    else
    {
    printf("exit\n");
    }


    keyboard= _getch();
    // printf("%c",keyboard);
    if (keyboard == 80 && position != MAX)
    {
        position++;
    }
    if (keyboard == 72 && position != MIN)
    {
        position --;
    }
    
}
return t;
}


#endif // MYMENU_H_INCLUDED

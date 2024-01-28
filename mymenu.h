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

    if (position==1)
    {
    arrowplace(1, position);
    printf("\x1b[34mResume previuos games\n");
    printf("\x1b[0m");
    t =1;
    }
    else
    {
    printf("Resume previuos games\n");
    }


    if (position==2)
    {
    arrowplace(2, position);
    printf("\x1b[34mStart a new game in normal mode\n");
    printf("\x1b[0m");
    t =2;
    }
    else
    {
    printf("Start a new game in normal mode\n");
    }

    if (position==3)
    {
    arrowplace(3, position);
    printf("\x1b[34mStart a new game in time mode\n");
    printf("\x1b[0m");
    t = 3;
    }
    else
    {
    printf("Start a new game in time mode\n");
    }
    
    if (position==4)
    {
    arrowplace(4, position);
    printf("\x1b[34mExit\n");
    printf("\x1b[0m");
    t = 4;
    }
    else
    {
    printf("Exit\n");
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

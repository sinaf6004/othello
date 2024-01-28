#include <stdio.h>
#include <time.h>
#include "mymenu.h"
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "read previous files.h"
struct part
{
    char character;
    int x;
    int y;
};
typedef struct part partition;
struct Members
{
    char name[10];
    int points;
};
typedef struct Members members;
struct saveFile
{
    char member1[10];
    char member2[10];
    char array[64];
    int turn;
    int time1;
    int time2;
    int point1;
    int point2;

    char arraySupport1[64];
    char arraySupport2[64];
    int pointSupporta1;
    int pointSupporta2;
    int pointSupportb1;
    int pointSupportb2;

    int turnBackCountera;
    int turnBackCounterb;
    int index1;
    int index2;
    int counter;
    int x23;
    int extraCounter;
    int extraTime1a;
    int extraTime1b;
    int extraTime1Counter;
    int extraTime1Countersu;
    int extraTime2a;
    int extraTime2b;
    int extraTime2Counter;
    int extraTime2Countersu;
};
typedef struct saveFile saveFile;
struct saveFileNormal
{
    char member1[10];
    char member2[10];
    char array[64];
    int turn;
    int point1;
    int point2;
    char arraySupport1[64];
    char arraySupport2[64];
    int pointSupporta1;
    int pointSupporta2;
    int pointSupportb1;
    int pointSupportb2;

    int turnBackCountera;
    int turnBackCounterb;
    int index1;
    int index2;
    int counter;
    int x23;
    int extraCounter;
};
typedef struct saveFileNormal normalSave;
members member1;
members member2;
struct globalPoint
{
    int point;
    char name[10];
};
typedef struct globalPoint globalPoint;
globalPoint globalPointMember1;
globalPoint globalPointMember2;
void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
}
void firstvaluesSave(partition array[])
{
    // for (int i = 0; i < 64; i++)
    // {
    //     (array[i]).character = ' ';
    // }
    // array[27].character = 'O';
    // array[36].character = 'O';
    // array[35].character = '#';
    // array[28].character = '#';
    int a = 0;
    for (int i = 1; i < 9; i++)
    {
        for (int j = 1; j < 9; j++)
        {
            array[a].x = i;
            array[a].y = j;
            a++;
        }
    }
}
void firstvaluesNotSave(partition array[])
{
    for (int i = 0; i < 64; i++)
    {
        (array[i]).character = ' ';
    }
    array[27].character = 'O';
    array[36].character = 'O';
    array[35].character = '#';
    array[28].character = '#';
    int a = 0;
    for (int i = 1; i < 9; i++)
    {
        for (int j = 1; j < 9; j++)
        {
            array[a].x = i;
            array[a].y = j;
            a++;
        }
    }
}
int time1 = 600;
int time2 = 600;
int t;
void printTime1()
{
    printf("\x1b[32m%s \x1b[0mremaining time is \x1b[33m%d \x1b[0mseconds", member1.name, time1);
    printf("\x1b[0m");
}
void printTime2()
{
    printf("\x1b[32m%s \x1b[0mremaining time is \x1b[33m%d \x1b[0mseconds", member2.name, time2);
    printf("\x1b[0m");
}
void printPointsa()
{
    printf("\x1b[32m%s \x1b[0mpoint is :\x1b[36m%d", member1.name, member1.points);
    printf("\x1b[0m");
}
void printPointsb()
{
    printf("\x1b[32m%s \x1b[0mpoint is :\x1b[36m%d", member2.name, member2.points);
    printf("\x1b[0m");
}

void printarray(partition array[])
{
    int a = 0;
    printf("\n\n");
    printf("   ");

    for (int i = 0; i < 8; i++)
    {
        printf(" \x1b[32m%d  ", i + 1);
        printf("\x1b[0m");
    }
    printf("\n");

    for (int j = 0; j < 8; j++)
    {
        printf("  ");
        for (int i = 0; i < 33; i++)
        {
            if ((i % 4) == 0)
            {
                printf(" ");
            }
            else
            {
                printf("-");
            }
        }
        for (int i = 0; i < 12; i++)
        {
            printf(" ");
        }

        if (j == 4)
        {
            printPointsb();
        }
        if ((j == 2) && (t != 2) && (t != 4))
        {
            printTime1();
        }

        printf("\n");
        printf("  ");
        for (int i = 0; i < 9; i++)
        {
            printf("|   ");
        }
        printf("\n");

        printf("\x1b[32m%d ", j + 1);
        printf("\x1b[0m");
        for (int i = 0; i < 8; i++)
        {
            if (array[a].character == '#')
            {
                printf("| \x1b[36m%c ", array[a].character);
            }
            else
            {
                printf("| \x1b[31m%c ", array[a].character);
            }

            // printf("| \x1b[36m%c ", array[a].character);
            printf("\x1b[0m");
            a++;
        }
        printf("|\n");

        printf("  ");
        for (int i = 0; i < 9; i++)
        {
            printf("|   ");
        }

        if (j == 3)
        {
            for (int i = 0; i < 9; i++)
            {
                printf(" ");
            }
            printPointsa();
        }

        if ((j == 2) && (t != 2) && (t != 4))
        {
            for (int i = 0; i < 9; i++)
            {
                printf(" ");
            }
            printTime2();
        }

        printf("\n");
    }

    printf("  ");
    for (int i = 0; i < 33; i++)
    {
        if ((i % 4) == 0)
        {
            printf(" ");
        }
        else
        {
            printf("-");
        }
    }
    printf("\n\n\n");
}
int insider1(partition array[], int x, int y)
{

    x++;
    if (x > 8)
    {
        return 0;
    }

    int n = ((x - 1) * 8) + y - 1;
    if (array[n].character == '#')
    {
        return 1;
    }
    if (array[n].character == ' ')
    {
        return 0;
    }
    if (insider1(array, x, y) == 1)
    {
        member1.points++;
        array[n].character = '#';
        return 1;
    }
}
// amodi be bala
int insider2(partition array[], int x, int y)
{
    x--;
    if (x < 1)
    {
        return 0;
    }

    int n = ((x - 1) * 8) + y - 1;
    if (array[n].character == '#')
    {
        return 1;
    }
    if (array[n].character == ' ')
    {
        return 0;
    }

    if (insider2(array, x, y) == 1)
    {
        member1.points++;
        array[n].character = '#';
        return 1;
    }
}
// amodi be paeen
int insider3(partition array[], int x, int y)
{
    x++;
    y++;
    if (x > 8)
    {
        return 0;
    }
    if (y > 8)
    {
        return 0;
    }

    int n = ((x - 1) * 8) + y - 1;
    if (array[n].character == '#')
    {
        return 1;
    }
    if (array[n].character == ' ')
    {
        return 0;
    }

    if (insider3(array, x, y) == 1)
    {
        member1.points++;
        array[n].character = '#';
        return 1;
    }
}

int insider4(partition array[], int x, int y)
{
    x--;
    y--;
    if (x < 1)
    {
        return 0;
    }
    if (y < 1)
    {
        return 0;
    }

    int n = ((x - 1) * 8) + y - 1;
    if (array[n].character == '#')
    {
        return 1;
    }
    if (array[n].character == ' ')
    {
        return 0;
    }

    if (insider4(array, x, y) == 1)
    {
        member1.points++;
        array[n].character = '#';
        return 1;
    }
}

int insider5(partition array[], int x, int y)
{
    x--;
    y++;
    if (x < 1)
    {
        return 0;
    }
    if (y > 8)
    {
        return 0;
    }

    int n = ((x - 1) * 8) + y - 1;
    if (array[n].character == '#')
    {
        return 1;
    }
    if (array[n].character == ' ')
    {
        return 0;
    }

    if (insider5(array, x, y) == 1)
    {
        member1.points++;
        array[n].character = '#';
        return 1;
    }
}

int insider6(partition array[], int x, int y)
{
    y--;
    if (y < 1)
    {
        return 0;
    }

    int n = ((x - 1) * 8) + y - 1;
    if (array[n].character == '#')
    {
        return 1;
    }
    if (array[n].character == ' ')
    {
        return 0;
    }

    if (insider6(array, x, y) == 1)
    {
        member1.points++;
        array[n].character = '#';
        return 1;
    }
}

int insider7(partition array[], int x, int y)
{
    y++;
    if (y > 8)
    {
        return 0;
    }

    int n = ((x - 1) * 8) + y - 1;
    if (array[n].character == '#')
    {
        return 1;
    }
    if (array[n].character == ' ')
    {
        return 0;
    }

    if (insider7(array, x, y) == 1)
    {
        member1.points++;
        array[n].character = '#';
        return 1;
    }
}

int insider8(partition array[], int x, int y)
{
    x++;
    y--;
    if (x > 8)
    {
        return 0;
    }
    if (y < 1)
    {
        return 0;
    }

    int n = ((x - 1) * 8) + y - 1;
    if (array[n].character == '#')
    {
        return 1;
    }
    if (array[n].character == ' ')
    {
        return 0;
    }

    if (insider8(array, x, y) == 1)
    {
        member1.points++;
        array[n].character = '#';
        return 1;
    }
}

/////////////////////////////////

int insiderb1(partition array[], int x, int y)
{

    x++;
    if (x > 8)
    {
        return 0;
    }

    int n = ((x - 1) * 8) + y - 1;
    if (array[n].character == 'O')
    {
        return 1;
    }
    if (array[n].character == ' ')
    {
        return 0;
    }
    if (insiderb1(array, x, y) == 1)
    {
        member2.points++;
        array[n].character = 'O';
        return 1;
    }
}
// amodi be bala
int insiderb2(partition array[], int x, int y)
{
    x--;
    if (x < 1)
    {
        return 0;
    }

    int n = ((x - 1) * 8) + y - 1;
    if (array[n].character == 'O')
    {
        return 1;
    }
    if (array[n].character == ' ')
    {
        return 0;
    }

    if (insiderb2(array, x, y) == 1)
    {
        member2.points++;
        array[n].character = 'O';
        return 1;
    }
}
// amodi be paeen
int insiderb3(partition array[], int x, int y)
{
    x++;
    y++;
    if (x > 8)
    {
        return 0;
    }
    if (y > 8)
    {
        return 0;
    }

    int n = ((x - 1) * 8) + y - 1;
    if (array[n].character == 'O')
    {
        return 1;
    }
    if (array[n].character == ' ')
    {
        return 0;
    }

    if (insiderb3(array, x, y) == 1)
    {
        member2.points++;
        array[n].character = 'O';
        return 1;
    }
}

int insiderb4(partition array[], int x, int y)
{
    x--;
    y--;
    if (x < 1)
    {
        return 0;
    }
    if (y < 1)
    {
        return 0;
    }

    int n = ((x - 1) * 8) + y - 1;
    if (array[n].character == 'O')
    {
        return 1;
    }
    if (array[n].character == ' ')
    {
        return 0;
    }

    if (insiderb4(array, x, y) == 1)
    {
        member2.points++;
        array[n].character = 'O';
        return 1;
    }
}

int insiderb5(partition array[], int x, int y)
{
    x--;
    y++;
    if (x < 1)
    {
        return 0;
    }
    if (y > 8)
    {
        return 0;
    }

    int n = ((x - 1) * 8) + y - 1;
    if (array[n].character == 'O')
    {
        return 1;
    }
    if (array[n].character == ' ')
    {
        return 0;
    }

    if (insiderb5(array, x, y) == 1)
    {
        member2.points++;
        array[n].character = 'O';
        return 1;
    }
}

int insiderb6(partition array[], int x, int y)
{
    y--;
    if (y < 1)
    {
        return 0;
    }

    int n = ((x - 1) * 8) + y - 1;
    if (array[n].character == 'O')
    {
        return 1;
    }
    if (array[n].character == ' ')
    {
        return 0;
    }

    if (insiderb6(array, x, y) == 1)
    {
        member2.points++;
        array[n].character = 'O';
        return 1;
    }
}

int insiderb7(partition array[], int x, int y)
{
    y++;
    if (y > 8)
    {
        return 0;
    }

    int n = ((x - 1) * 8) + y - 1;
    if (array[n].character == 'O')
    {
        return 1;
    }
    if (array[n].character == ' ')
    {
        return 0;
    }

    if (insiderb7(array, x, y) == 1)
    {
        member2.points++;
        array[n].character = 'O';
        return 1;
    }
}

int insiderb8(partition array[], int x, int y)
{
    x++;
    y--;
    if (x > 8)
    {
        return 0;
    }
    if (y < 1)
    {
        return 0;
    }

    int n = ((x - 1) * 8) + y - 1;
    if (array[n].character == 'O')
    {
        return 1;
    }
    if (array[n].character == ' ')
    {
        return 0;
    }

    if (insiderb8(array, x, y) == 1)
    {
        member2.points++;
        array[n].character = 'O';
        return 1;
    }
}

int outsider1(partition array[], int x, int y, int a)
{
    a++;
    x++;
    y++;
    int n = ((x - 1) * 8) + y - 1;

    if (x > 8)
    {
        return 0;
    }
    if (y > 8)
    {
        return 0;
    }

    if ((array[n].character == '#') && (a != 1))
    {
        return 1;
    }
    else if ((array[n].character == '#') && (a == 1))
    {
        return 0;
    }

    if (array[n].character == ' ')
    {
        return 0;
    }
    if (outsider1(array, x, y, a) == 1)
    {
        return 1;
    }
    if (outsider1(array, x, y, a) == 0)
    {
        return 0;
    }
}

int outsider2(partition array[], int x, int y, int a)
{
    a++;
    x++;
    int n = ((x - 1) * 8) + y - 1;

    if (x > 8)
    {
        return 0;
    }

    if ((array[n].character == '#') && (a != 1))
    {
        return 1;
    }
    else if ((array[n].character == '#') && (a == 1))
    {
        return 0;
    }
    if (array[n].character == ' ')
    {
        return 0;
    }
    if (outsider2(array, x, y, a) == 1)
    {
        return 1;
    }
    if (outsider2(array, x, y, a) == 0)
    {
        return 0;
    }
}

int outsider3(partition array[], int x, int y, int a)
{
    a++;
    x++;
    y--;
    int n = ((x - 1) * 8) + y - 1;

    if (x > 8)
    {
        return 0;
    }
    if (y < 1)
    {
        return 0;
    }

    if ((array[n].character == '#') && (a != 1))
    {
        return 1;
    }
    else if ((array[n].character == '#') && (a == 1))
    {
        return 0;
    }
    if (array[n].character == ' ')
    {
        return 0;
    }
    if (outsider3(array, x, y, a) == 1)
    {
        return 1;
    }
    if (outsider3(array, x, y, a) == 0)
    {
        return 0;
    }
}

int outsider4(partition array[], int x, int y, int a)
{
    a++;
    y++;
    int n = ((x - 1) * 8) + y - 1;

    if (y > 8)
    {
        return 0;
    }
    if ((array[n].character == '#') && (a != 1))
    {
        return 1;
    }
    else if ((array[n].character == '#') && (a == 1))
    {
        return 0;
    }
    if (array[n].character == ' ')
    {
        return 0;
    }
    if (outsider4(array, x, y, a) == 1)
    {
        return 1;
    }
    if (outsider4(array, x, y, a) == 0)
    {
        return 0;
    }
}

int outsider5(partition array[], int x, int y, int a)
{
    a++;
    y--;
    int n = ((x - 1) * 8) + y - 1;

    if (y < 1)
    {
        return 0;
    }

    if ((array[n].character == '#') && (a != 1))
    {
        return 1;
    }
    else if ((array[n].character == '#') && (a == 1))
    {
        return 0;
    }
    if (array[n].character == ' ')
    {
        return 0;
    }
    if (outsider5(array, x, y, a) == 1)
    {
        return 1;
    }
    if (outsider5(array, x, y, a) == 0)
    {
        return 0;
    }
}

int outsider6(partition array[], int x, int y, int a)
{
    a++;
    x--;
    y++;
    int n = ((x - 1) * 8) + y - 1;

    if (x < 1)
    {
        return 0;
    }
    if (y > 8)
    {
        return 0;
    }

    if ((array[n].character == '#') && (a != 1))
    {
        return 1;
    }
    else if ((array[n].character == '#') && (a == 1))
    {
        return 0;
    }
    if (array[n].character == ' ')
    {
        return 0;
    }
    if (outsider6(array, x, y, a) == 1)
    {
        return 1;
    }
    if (outsider6(array, x, y, a) == 0)
    {
        return 0;
    }
}

int outsider7(partition array[], int x, int y, int a)
{
    a++;
    x--;
    int n = ((x - 1) * 8) + y - 1;

    if (x < 1)
    {
        return 0;
    }

    if ((array[n].character == '#') && (a != 1))
    {
        return 1;
    }
    else if ((array[n].character == '#') && (a == 1))
    {
        return 0;
    }

    if (array[n].character == ' ')
    {
        return 0;
    }
    if (outsider7(array, x, y, a) == 1)
    {
        return 1;
    }
    if (outsider7(array, x, y, a) == 0)
    {
        return 0;
    }
}

int outsider8(partition array[], int x, int y, int a)
{
    a++;
    x--;
    y--;
    int n = ((x - 1) * 8) + y - 1;

    if (x < 1)
    {
        return 0;
    }
    if (y < 1)
    {
        return 0;
    }

    if ((array[n].character == '#') && (a != 1))
    {
        return 1;
    }
    else if ((array[n].character == '#') && (a == 1))
    {
        return 0;
    }

    if (array[n].character == ' ')
    {
        return 0;
    }
    if (outsider8(array, x, y, a) == 1)
    {
        return 1;
    }
    if (outsider8(array, x, y, a) == 0)
    {
        return 0;
    }
}
////////////////////////
int outsiderb1(partition array[], int x, int y, int a)
{
    a++;
    x++;
    y++;
    int n = ((x - 1) * 8) + y - 1;

    if (x > 8)
    {
        return 0;
    }
    if (y > 8)
    {
        return 0;
    }

    if ((array[n].character == 'O') && (a != 1))
    {
        return 1;
    }
    else if ((array[n].character == 'O') && (a == 1))
    {
        return 0;
    }

    if (array[n].character == ' ')
    {
        return 0;
    }
    if (outsiderb1(array, x, y, a) == 1)
    {
        return 1;
    }
    if (outsiderb1(array, x, y, a) == 0)
    {
        return 0;
    }
}

int outsiderb2(partition array[], int x, int y, int a)
{
    a++;
    x++;
    int n = ((x - 1) * 8) + y - 1;

    if (x > 8)
    {
        return 0;
    }

    if ((array[n].character == 'O') && (a != 1))
    {
        return 1;
    }
    else if ((array[n].character == 'O') && (a == 1))
    {
        return 0;
    }
    if (array[n].character == ' ')
    {
        return 0;
    }
    if (outsiderb2(array, x, y, a) == 1)
    {
        return 1;
    }
    if (outsiderb2(array, x, y, a) == 0)
    {
        return 0;
    }
}

int outsiderb3(partition array[], int x, int y, int a)
{
    a++;
    x++;
    y--;
    int n = ((x - 1) * 8) + y - 1;

    if (x > 8)
    {
        return 0;
    }
    if (y < 1)
    {
        return 0;
    }

    if ((array[n].character == 'O') && (a != 1))
    {
        return 1;
    }
    else if ((array[n].character == 'O') && (a == 1))
    {
        return 0;
    }
    if (array[n].character == ' ')
    {
        return 0;
    }
    if (outsiderb3(array, x, y, a) == 1)
    {
        return 1;
    }
    if (outsiderb3(array, x, y, a) == 0)
    {
        return 0;
    }
}

int outsiderb4(partition array[], int x, int y, int a)
{
    a++;
    y++;
    int n = ((x - 1) * 8) + y - 1;

    if (y > 8)
    {
        return 0;
    }
    if ((array[n].character == 'O') && (a != 1))
    {
        return 1;
    }
    else if ((array[n].character == 'O') && (a == 1))
    {
        return 0;
    }
    if (array[n].character == ' ')
    {
        return 0;
    }
    if (outsiderb4(array, x, y, a) == 1)
    {
        return 1;
    }
    if (outsiderb4(array, x, y, a) == 0)
    {
        return 0;
    }
}

int outsiderb5(partition array[], int x, int y, int a)
{
    a++;
    y--;
    int n = ((x - 1) * 8) + y - 1;

    if (y < 1)
    {
        return 0;
    }

    if ((array[n].character == 'O') && (a != 1))
    {
        return 1;
    }
    else if ((array[n].character == 'O') && (a == 1))
    {
        return 0;
    }
    if (array[n].character == ' ')
    {
        return 0;
    }
    if (outsiderb5(array, x, y, a) == 1)
    {
        return 1;
    }
    if (outsiderb5(array, x, y, a) == 0)
    {
        return 0;
    }
}

int outsiderb6(partition array[], int x, int y, int a)
{
    a++;
    x--;
    y++;
    int n = ((x - 1) * 8) + y - 1;

    if (x < 1)
    {
        return 0;
    }
    if (y > 8)
    {
        return 0;
    }

    if ((array[n].character == 'O') && (a != 1))
    {
        return 1;
    }
    else if ((array[n].character == 'O') && (a == 1))
    {
        return 0;
    }
    if (array[n].character == ' ')
    {
        return 0;
    }
    if (outsiderb6(array, x, y, a) == 1)
    {
        return 1;
    }
    if (outsiderb6(array, x, y, a) == 0)
    {
        return 0;
    }
}

int outsiderb7(partition array[], int x, int y, int a)
{
    a++;
    x--;
    int n = ((x - 1) * 8) + y - 1;

    if (x < 1)
    {
        return 0;
    }

    if ((array[n].character == 'O') && (a != 1))
    {
        return 1;
    }
    else if ((array[n].character == 'O') && (a == 1))
    {
        return 0;
    }

    if (array[n].character == ' ')
    {
        return 0;
    }
    if (outsiderb7(array, x, y, a) == 1)
    {
        return 1;
    }
    if (outsiderb7(array, x, y, a) == 0)
    {
        return 0;
    }
}

int outsiderb8(partition array[], int x, int y, int a)
{
    a++;
    x--;
    y--;
    int n = ((x - 1) * 8) + y - 1;

    if (x < 1)
    {
        return 0;
    }
    if (y < 1)
    {
        return 0;
    }

    if ((array[n].character == 'O') && (a != 1))
    {
        return 1;
    }
    else if ((array[n].character == 'O') && (a == 1))
    {
        return 0;
    }

    if (array[n].character == ' ')
    {
        return 0;
    }
    if (outsiderb8(array, x, y, a) == 1)
    {
        return 1;
    }
    if (outsiderb8(array, x, y, a) == 0)
    {
        return 0;
    }
}

int check(partition array[], int x, int y)
{
    if (array[((x - 1) * 8) + y - 1].character == '#')
    {
        return 0;
    }
    if (array[((x - 1) * 8) + y - 1].character == 'O')
    {
        return 0;
    }
    if (outsider1(array, x, y, 0) == 1)
    {
        return 1;
    };
    if (outsider2(array, x, y, 0) == 1)
    {
        return 1;
    };
    if (outsider3(array, x, y, 0) == 1)
    {
        return 1;
    };
    if (outsider4(array, x, y, 0) == 1)
    {
        return 1;
    };
    if (outsider5(array, x, y, 0) == 1)
    {
        return 1;
    };
    if (outsider6(array, x, y, 0) == 1)
    {
        return 1;
    };
    if (outsider7(array, x, y, 0) == 1)
    {
        return 1;
    };
    if (outsider8(array, x, y, 0) == 1)
    {
        return 1;
    };
    return 0;
}
int checkb(partition array[], int x, int y)
{
    if (array[((x - 1) * 8) + y - 1].character == '#')
    {
        return 0;
    }
    if (array[((x - 1) * 8) + y - 1].character == 'O')
    {
        return 0;
    }

    if (outsiderb1(array, x, y, 0) == 1)
    {
        return 1;
    };
    if (outsiderb2(array, x, y, 0) == 1)
    {
        return 1;
    };
    if (outsiderb3(array, x, y, 0) == 1)
    {
        return 1;
    };
    if (outsiderb4(array, x, y, 0) == 1)
    {
        return 1;
    };
    if (outsiderb5(array, x, y, 0) == 1)
    {
        return 1;
    };
    if (outsiderb6(array, x, y, 0) == 1)
    {
        return 1;
    };
    if (outsiderb7(array, x, y, 0) == 1)
    {
        return 1;
    };
    if (outsiderb8(array, x, y, 0) == 1)
    {
        return 1;
    };
    return 0;
}

int getnum1(partition array[])
{
    printf("%s! it's your turn please choose a block\n", member1.name);
    int x;
    int y;
    int n;
    int t = member1.points;
    // scanf("%d%d",&x,&y);

    do
    {
        scanf("%d%d", &x, &y);
        if ((x > 0) && (x <= 8) && (y <= 8) && (y > 0))
        {
            break;
        }
        else
        {
            printf("invalid number !!!\n");
            continue;
        }

    } while (1);

    // printf("x =%d--y =%d\n",x,y);
    n = ((x - 1) * 8) + y - 1;
    // printf("2\n");
    if (check(array, x, y) == 0)
    {
        printf("%s you can't move!!\n please choose another block\n", member1.name);
        return 0;
    }

    // check();
    array[n].character = '#';
    insider1(array, x, y);
    insider2(array, x, y);
    insider3(array, x, y);
    insider4(array, x, y);
    insider5(array, x, y);
    insider6(array, x, y);
    insider7(array, x, y);
    insider8(array, x, y);
    // printf("xx\n");
    return 1;
}

int getnum2(partition array[])
{
    printf("%s! it's your turn please choose a block\n", member2.name);
    int x;
    int y;
    int n;
    int t = member2.points;
    do
    {
        scanf("%d%d", &x, &y);
        if ((x <= 8) && (y <= 8))
        {
            break;
        }
        else
        {
            printf("invalid number !!!\n");
        }

    } while ((x > 8) && (y > 8));
    // printf("x =%d--y =%d\n",x,y);
    n = ((x - 1) * 8) + y - 1;
    printf("2\n");
    if (checkb(array, x, y) == 0)
    {
        printf("%s you can't move!!\n please choose another block\n", member2.name);
        return 0;
    }

    // check();
    array[n].character = 'O';
    insiderb1(array, x, y);
    insiderb2(array, x, y);
    insiderb3(array, x, y);
    insiderb4(array, x, y);
    insiderb5(array, x, y);
    insiderb6(array, x, y);
    insiderb7(array, x, y);
    insiderb8(array, x, y);
    // printf("xx\n");
    return 1;
}
int chooseWinner(partition array[])
{
    int tagCounter = 0;
    int ocounter = 0;
    for (int i = 0; i < 64; i++)
    {
        if (array[i].character == '#')
        {
            tagCounter++;
        }
        if (array[i].character == 'O')
        {
            ocounter++;
        }
    }
    if (tagCounter > ocounter)
    {
        return 1;
    }
    if (tagCounter < ocounter)
    {
        return 2;
    }
}
void codingChar(char array1[], char array2[])
{
    int i;
    for (i = 0; i < 64; i++)
    {
        array2[i] = (array1[i] * 3 + 5) % 128;
    }
}
void decodingChar(char array1[], char array2[])
{
    int i;
    for (i = 0; i < 64; i++)
    {
        array1[i] -= 5;
        int hold = array1[i];
        while (hold % 3 != 0)
        {
            hold += 128;
        }

        array2[i] = hold / 3;
    }
}
int codingNumber(int x)
{
    int y;
    y = (x * 3 + 5) % 128;
    return y;
}
int decodingNumber(int x)
{
    int y;
    int i;
    x -= 5;
    int hold = x;
    while (hold % 3 != 0)
    {
        hold += 128;
    }

    y = hold / 3;
    return y;
}

/// *********************************************************************
/// *********************************************************************
int main()
{
    while (1)
    {

        partition array[64];
        t = menu();
        // delay(10);
        // system("cls");
        if (t == 1)
        {
            scanf("%s", &member1.name);
            scanf("%s", &member2.name);
            prointPreviousGames(member1.name, member2.name);
            char holdFileName[50];
            char holdIsIt1[50] = {'\0'};
            char holdIsIt2[50] = {'\0'};
            printf("which game do you want to continue?\n");
            scanf("%s", holdFileName);
            char globalPointName1[20];
            FILE *filePointer;
            globalPoint readFile1;
            globalPoint readFile2;
            globalPointName1[0] = '\0';
            strcpy(globalPointName1, member1.name);
            strcat(globalPointName1, "points.txt");
            filePointer = fopen(globalPointName1, "r");
            fread(&readFile1, sizeof(readFile1), 1, filePointer);
            fclose(filePointer);

            globalPointName1[0] = '\0';
            strcpy(globalPointName1, member2.name);
            strcat(globalPointName1, "points.txt");
            filePointer = fopen(globalPointName1, "r");
            fread(&readFile2, sizeof(readFile2), 1, filePointer);
            fclose(filePointer);
            saveFile save;
            filePointer = fopen(holdFileName, "r");
            fread(&save, sizeof(save), 1, filePointer);
            fclose(filePointer);
            char arraySupport1[64];
            char arraySupport2[64];
            int pointSupporta1;
            int pointSupporta2;
            int pointSupportb1;
            int pointSupportb2;
            int turnBackCountera = 2;
            int turnBackCounterb = 2;
            int index1 = 0;
            int index2 = 0;
            int counter = 0;
            int x23;
            int extraCounter = 0;
            int extraTime1a;
            int extraTime1b;
            int extraTime1Counter = 0;
            int extraTime1Countersu = 0;
            int extraTime2a;
            int extraTime2b;
            int extraTime2Counter = 0;
            int extraTime2Countersu = 0;
            strcpy(holdIsIt1, member1.name);
            strcat(holdIsIt1, member2.name);
            strcpy(holdIsIt2, save.member1);
            strcat(holdIsIt2, save.member2);
            int startI;
            char mainArrayCoding[64];
            char arraySupport1Coding[64];
            char arraySupport2Coding[64];
            char mainArrayDecoding[64];
            char arraySupport1Decoding[64];
            char arraySupport2Decoding[64];
            if (strcmp(holdIsIt1, holdIsIt2) == 0)
            {
                startI = decodingNumber(save.turn) + 1;
                member1.points = readFile1.point;
                member2.points = readFile2.point;
                decodingChar(save.array, mainArrayDecoding);
                decodingChar(save.arraySupport1, arraySupport1Decoding);
                decodingChar(save.arraySupport2, arraySupport2Decoding);
                for (int i = 0; i < 64; i++)
                {
                    array[i].character = mainArrayDecoding[i];
                }
                time1 = (save.time1);
                time2 = (save.time2);
                firstvaluesSave(array);
                for (int i = 0; i < 64; i++)
                {
                    arraySupport1[i] = arraySupport1Decoding[i];
                }
                printf("\n");
                for (int i = 0; i < 64; i++)
                {
                    arraySupport2[i] = arraySupport2Decoding[i];
                }
                printf("\n");

                pointSupporta1 = readFile1.point + decodingNumber(save.pointSupporta1) - member1.points;
                pointSupporta2 = readFile2.point + decodingNumber(save.pointSupporta2) - member2.points;
                pointSupportb1 = readFile1.point + decodingNumber(save.pointSupportb1) - member1.points;
                pointSupportb2 = readFile2.point + decodingNumber(save.pointSupportb2) - member2.points;
                turnBackCountera = decodingNumber(save.turnBackCountera);
                turnBackCounterb = decodingNumber(save.turnBackCounterb);
                index1 = decodingNumber(save.index1);
                index2 = decodingNumber(save.index2);
                counter = decodingNumber(save.counter);
                x23 = decodingNumber(save.x23);
                extraCounter = decodingNumber(save.extraCounter);
                extraTime1a = decodingNumber(save.extraTime1a);
                extraTime1b = decodingNumber(save.extraTime1b);
                extraTime1Counter = decodingNumber(save.extraTime1Counter);
                extraTime1Countersu = decodingNumber(save.extraTime1Countersu);
                extraTime2a = decodingNumber(save.extraTime2a);
                extraTime2b = decodingNumber(save.extraTime2b);
                extraTime2Counter = decodingNumber(save.extraTime2Counter);
                extraTime2Countersu = decodingNumber(save.extraTime2Countersu);
                clock_t start, end;
                for (int i = startI; i < (60 + extraCounter); i++)
                {
                    if ((turnBackCountera == 0) && (i == index1))
                    {
                        extraTime1Counter++;
                        extraTime1Countersu = 1;
                        turnBackCountera = -1; /*for avoiding to enter again in this if*/
                    }
                    if ((i == index1 + 1) && (extraTime1Counter == 1))
                    {
                        extraTime1Counter++;
                        extraTime1Countersu = 1;
                        extraTime1Counter = 0;
                    }

                    if ((turnBackCounterb == 0) && (i == index2))
                    {
                        extraTime2Counter++;
                        extraTime2Countersu = 1;
                        turnBackCounterb = -1; /*for avoiding to enter again in this if*/
                    }
                    if ((i == index2 + 1) && (extraTime2Counter == 1))
                    {
                        extraTime2Counter++;
                        extraTime2Countersu = 1;
                        extraTime2Counter = 0;
                    }

                    printarray(array);
                    printf("turn = %d\n", i + 1);
                    start = clock();
                    int t = 0;
                    if ((i % 2) == 0)
                    {
                        for (int j = 0; j < 64; j++)
                        {
                            if (check(array, array[j].x, array[j].y) == 1)
                            {
                                t++;
                            };
                        }

                        if (t == 0)
                        {
                            int sentinel1 = 0;
                            printf("%syou can't move \n", member1.name);
                            extraCounter++;
                            for (int j = 0; j < 64; j++)
                            {
                                if (checkb(array, array[j].x, array[j].y) == 1)
                                {
                                    sentinel1++;
                                }
                            }
                            if (sentinel1 == 0)
                            {
                                break;
                            }

                            continue;
                        }
                        if (i >= 2)
                        {
                            if (counter == 1)
                            {
                                if (i > index1)
                                {
                                    int x = 0;
                                    if (turnBackCountera > 0)
                                    {

                                        printf("%s do you want to go back?", member1.name);
                                        scanf("%d", &x);
                                        if (x == 1)
                                        {
                                            if (turnBackCountera == 2)
                                            {
                                                time1 -= 30;
                                            }
                                            if (turnBackCountera)
                                            {
                                                time1 -= 60;
                                            }
                                            for (int i = 0; i < 64; i++)
                                            {
                                                array[i].character = arraySupport1[i];
                                            }
                                            member1.points = pointSupporta1;
                                            member2.points = pointSupporta2;
                                            i = index1 - 1;
                                            turnBackCountera--;
                                            counter = 0;
                                            continue;
                                        }
                                    }
                                }
                            }
                        }
                        if (i >= 2)
                        {
                            if (counter == 1)
                            {
                                if (i > index2)
                                {
                                    int x = 0;
                                    if (turnBackCounterb > 0)
                                    {
                                        printf("%s do you want to go back?", member2.name);
                                        scanf("%d", &x);
                                        if (x == 1)
                                        {
                                            if (turnBackCounterb == 2)
                                            {
                                                time2 -= 30;
                                            }
                                            if (turnBackCounterb == 1)
                                            {
                                                time2 -= 60;
                                            }

                                            for (int i = 0; i < 64; i++)
                                            {
                                                array[i].character = arraySupport2[i];
                                            }
                                            member1.points = pointSupportb1;
                                            member2.points = pointSupportb2;
                                            i = index2 - 1;
                                            turnBackCounterb--;
                                            counter = 0;
                                            continue;
                                        }
                                    }
                                }
                            }
                        }
                        int index1getnum0 = index1;
                        char arraySupport1getnum0[64];
                        for (int i = 0; i < 64; i++)
                        {
                            arraySupport1getnum0[i] = arraySupport1[i];
                        }
                        int pointSupporta1getnum0 = pointSupporta1;
                        int pointSupporta2getnum0 = pointSupporta2;

                        for (int i = 0; i < 64; i++)
                        {
                            arraySupport1[i] = array[i].character;
                        }
                        if (counter == 0)
                        {
                            counter = 1;
                        }

                        pointSupporta1 = member1.points;
                        pointSupporta2 = member2.points;
                        index1 = i;

                        if (getnum1(array) == 0)
                        {
                            end = clock();
                            int reduce = (end - start) / CLOCKS_PER_SEC;
                            time1 -= reduce;
                            i--;
                            index1 = index1getnum0;
                            pointSupporta1 = pointSupporta1getnum0;
                            pointSupporta2 = pointSupporta2getnum0;
                            for (int i = 0; i < 64; i++)
                            {
                                arraySupport1[i] = arraySupport1getnum0[i];
                            }
                            continue;
                        };
                        end = clock();
                        int reduce = (end - start) / CLOCKS_PER_SEC;
                        time1 -= reduce;
                        if (extraTime1Countersu == 1)
                        {
                            // printf("%d added to time2", reduce);
                            time2 += reduce;
                            extraTime1Countersu = 0;
                        }
                        if (extraTime2Countersu == 1)
                        {
                            // printf("%d added to time1\n", reduce);
                            time1 += reduce;
                            extraTime2Countersu = 0;
                        }

                        if (time1 < 0)
                        {
                            printf("%s you lost the time\n%s won the game\n", member1.name, member2.name);
                            break;
                        }
                    }
                    if ((i % 2) == 1)
                    {

                        for (int j = 0; j < 64; j++)
                        {
                            if (checkb(array, array[j].x, array[j].y) == 1)
                            {
                                t++;
                            };
                        }
                        if (t == 0)
                        {
                            int sentinel2 = 0;
                            printf("you can't move \n");
                            extraCounter++;
                            for (int j = 0; j < 64; j++)
                            {
                                if (check(array, array[j].x, array[j].y) == 1)
                                {
                                    sentinel2++;
                                }
                            }
                            if (sentinel2 == 0)
                            {
                                break;
                            }

                            continue;
                        }
                        if (i >= 2)
                        {
                            if (counter == 1)
                            {
                                if (i > index2)
                                {

                                    int x = 0;
                                    if (turnBackCounterb > 0)
                                    {
                                        printf("%s do you want to go back?", member2.name);
                                        scanf("%d", &x);

                                        if (x == 1)
                                        {
                                            if (turnBackCounterb == 2)
                                            {
                                                time2 -= 30;
                                            }
                                            if (turnBackCounterb == 1)
                                            {
                                                time2 -= 60;
                                            }

                                            for (int i = 0; i < 64; i++)
                                            {
                                                array[i].character = arraySupport2[i];
                                            }
                                            member1.points = pointSupportb1;
                                            member2.points = pointSupportb2;
                                            i = index2 - 1;
                                            turnBackCounterb--;
                                            counter = 0;
                                            continue;
                                        }
                                    }
                                }
                            }
                        }
                        if (i >= 3)
                        {
                            if (counter == 1)
                            {
                                if (i > index1)
                                {

                                    int x = 0;
                                    if (turnBackCountera > 0)
                                    {
                                        printf("%s do you want to go back?", member1.name);
                                        scanf("%d", &x);

                                        if (x == 1)
                                        {
                                            if (turnBackCountera == 2)
                                            {
                                                time1 -= 30;
                                            }
                                            if (turnBackCountera == 1)
                                            {
                                                time1 -= 60;
                                            }

                                            for (int i = 0; i < 64; i++)
                                            {
                                                array[i].character = arraySupport1[i];
                                            }
                                            member1.points = pointSupporta1;
                                            member2.points = pointSupporta2;
                                            i = index1 - 1;
                                            turnBackCountera--;
                                            counter = 0;
                                            continue;
                                        }
                                    }
                                }
                            }
                        }
                        int index2getnum0 = index2;
                        char arraySupport2getnum0[64];
                        for (int i = 0; i < 64; i++)
                        {
                            arraySupport2getnum0[i] = arraySupport2[i];
                        }
                        int pointSupportb1getnum0 = pointSupportb1;
                        int pointSupportb2getnum0 = pointSupportb2;
                        for (int i = 0; i < 64; i++)
                        {
                            arraySupport2[i] = array[i].character;
                        }
                        pointSupportb1 = member1.points;
                        pointSupportb2 = member2.points;
                        index2 = i;
                        if (counter == 0)
                        {
                            counter = 1;
                        }

                        if (getnum2(array) == 0)
                        {
                            i--;
                            index2 = index2getnum0;
                            pointSupportb1 = pointSupportb1getnum0;
                            pointSupportb2 = pointSupportb2getnum0;
                            for (int i = 0; i < 64; i++)
                            {
                                arraySupport2[i] = arraySupport2getnum0[i];
                            }

                            continue;
                        };
                        end = clock();
                        int reduce = (end - start) / CLOCKS_PER_SEC;
                        time2 -= reduce;
                        if (extraTime1Countersu == 1)
                        {
                            time2 += reduce;
                            extraTime1Countersu = 0;
                        }
                        if (extraTime2Countersu == 1)
                        {
                            time1 += reduce;
                            extraTime2Countersu = 0;
                        }

                        if (time2 < 0)
                        {
                            printf("%s you lost the time\n%s won the game", member2.name, member1.name);
                            member1.points = 0;
                            break;
                        }

                        // printarray(array);
                        // printf("%s point is :%d\n", member1.name, member1.points);
                        // printf("%s point is :%d\n", member2.name, member2.points);
                    }
                    printf("do you want to save the game and quit?(yes = 1/no = 0)\n");
                    int saveCheck;
                    scanf("%d", &saveCheck);
                    if (saveCheck == 1)
                    {
                        // for (int i = 0; i < 64; i++)
                        // {
                        //     printf("%c", arraySupport2[i]);
                        // }
                        // printf("\n");
                        // printf("%s\n", holdFileName);
                        char mainArrayCharacter[64];
                        for (int i = 0; i < 64; i++)
                        {
                            mainArrayCharacter[i] = array[i].character;
                        }
                        codingChar(mainArrayCharacter, mainArrayCoding);
                        codingChar(arraySupport1, arraySupport1Coding);
                        codingChar(arraySupport2, arraySupport2Coding);

                        for (int i = 0; i < 64; i++)
                        {
                            save.array[i] = mainArrayCoding[i];
                        }
                        strcpy(save.member1, (member1.name));
                        strcpy(save.member2, (member2.name));
                        save.time1 = (time1);
                        save.time2 = (time2);
                        save.turn = codingNumber(i);
                        save.point1 = codingNumber(member1.points);
                        save.point2 = codingNumber(member2.points);
                        for (int i = 0; i < 64; i++)
                        {
                            save.arraySupport1[i] = arraySupport1Coding[i];
                        }
                        for (int i = 0; i < 64; i++)
                        {
                            save.arraySupport2[i] = arraySupport2Coding[i];
                        }
                        save.pointSupporta1 = codingNumber(pointSupporta1);
                        save.pointSupporta2 = codingNumber(pointSupporta2);
                        save.pointSupportb1 = codingNumber(pointSupportb1);
                        save.pointSupportb2 = codingNumber(pointSupportb2);
                        save.turnBackCountera = codingNumber(turnBackCountera);
                        save.turnBackCounterb = codingNumber(turnBackCounterb);
                        save.index1 = codingNumber(index1);
                        save.index2 = codingNumber(index2);
                        save.counter = codingNumber(counter);
                        save.x23 = codingNumber(x23);
                        save.extraCounter = codingNumber(extraCounter);
                        save.extraTime1a = codingNumber(extraTime1a);
                        save.extraTime1b = codingNumber(extraTime1b);
                        save.extraTime1Counter = codingNumber(extraTime1Counter);
                        save.extraTime1Countersu = codingNumber(extraTime1Countersu);
                        save.extraTime2a = codingNumber(extraTime2a);
                        save.extraTime2b = codingNumber(extraTime2b);
                        save.extraTime2Counter = codingNumber(extraTime2Counter);
                        save.extraTime2Countersu = codingNumber(extraTime2Countersu);
                        // saving global points
                        globalPointMember1.point = member1.points;
                        strcpy(globalPointMember1.name, member1.name);
                        globalPointMember2.point = member2.points;
                        strcpy(globalPointMember2.name, member2.name);
                        char globalPointName1[20];
                        globalPointName1[0] = '\0';
                        strcpy(globalPointName1, member1.name);
                        strcat(globalPointName1, "points.txt");

                        filePointer = fopen(globalPointName1, "w");
                        fwrite(&globalPointMember1, sizeof(globalPointMember1), 1, filePointer);
                        fclose(filePointer);
                        globalPointName1[0] = '\0';
                        strcpy(globalPointName1, member2.name);
                        strcat(globalPointName1, "points.txt");

                        filePointer = fopen(globalPointName1, "w");
                        fwrite(&globalPointMember2, sizeof(globalPointMember2), 1, filePointer);
                        fclose(filePointer);

                        filePointer = fopen(holdFileName, "w");
                        fwrite(&save, sizeof(save), 1, filePointer);
                        fclose(filePointer);
                    }
                }
                globalPoint readFile;

                // saving global points
                globalPointMember1.point = member1.points;
                strcpy(globalPointMember1.name, member1.name);
                globalPointMember2.point = member2.points;
                strcpy(globalPointMember2.name, member2.name);
                char globalPointName1[20];

                globalPointName1[0] = '\0';
                strcpy(globalPointName1, member1.name);
                strcat(globalPointName1, "points.txt");

                filePointer = fopen(globalPointName1, "w");
                fwrite(&globalPointMember1, sizeof(globalPointMember1), 1, filePointer);
                fclose(filePointer);

                globalPointName1[0] = '\0';
                strcpy(globalPointName1, member2.name);
                strcat(globalPointName1, "points.txt");

                filePointer = fopen(globalPointName1, "w");
                fwrite(&globalPointMember2, sizeof(globalPointMember2), 1, filePointer);
                fclose(filePointer);
                if (chooseWinner(array) == 1)
                {
                    printf("%s won the game", member1.name);
                }
                if (chooseWinner(array) == 2)
                {
                    printf("%s won the game", member2.name);
                }
            }
            delay(30);
        }
        if (t == 2)
        {
            scanf("%s", &member1.name);
            scanf("%s", &member2.name);
            int lastFileNUmber;
            lastFileNUmber = prointPreviousGamesNormal(member1.name, member2.name);
            FILE *filePointer;
            char globalPointName1[20];
            globalPoint readFile1;
            globalPoint readFile2;
            globalPointName1[0] = '\0';
            strcpy(globalPointName1, member1.name);
            strcat(globalPointName1, "points.txt");
            filePointer = fopen(globalPointName1, "r");
            fread(&readFile1, sizeof(readFile1), 1, filePointer);
            fclose(filePointer);

            globalPointName1[0] = '\0';
            strcpy(globalPointName1, member2.name);
            strcat(globalPointName1, "points.txt");
            filePointer = fopen(globalPointName1, "r");
            fread(&readFile2, sizeof(readFile2), 1, filePointer);
            fclose(filePointer);
            if (strcmp(readFile1.name, member1.name) == 0)
            {
                member1.points = readFile1.point;
            }
            else
            {
                member1.points = 0;
            }
            if (strcmp(readFile2.name, member2.name) == 0)
            {
                member2.points = readFile2.point;
            }
            else
            {
                member2.points = 0;
            }
            // values for coding and decoding
            char mainArrayCoding[64];
            char arraySupport1Coding[64];
            char arraySupport2Coding[64];
            char mainArrayDecoding[64];
            char arraySupport1Decoding[64];
            char arraySupport2Decoding[64];

            char arraySupport1[64];
            char arraySupport2[64];
            int pointSupporta1;
            int pointSupporta2;
            int pointSupportb1;
            int pointSupportb2;
            firstvaluesNotSave(array);
            int turnBackCountera = 2;
            int turnBackCounterb = 2;
            int index1 = 0;
            int index2 = 0;
            int counter = 0;
            int x23;
            int extraCounter = 0;
            for (int i = 0; i < (60 + extraCounter); i++)
            {
                printarray(array);
                printf("turn = %d\n", i + 1);
                int t = 0;

                if ((i % 2) == 0)
                {
                    for (int j = 0; j < 64; j++)
                    {
                        if (check(array, array[j].x, array[j].y) == 1)
                        {
                            t++;
                        };
                    }
                    if (t == 0)
                    {
                        int sentinel1 = 0;
                        printf("you can't move\n");
                        extraCounter++;
                        for (int j = 0; j < 64; j++)
                        {
                            if (checkb(array, array[j].x, array[j].y) == 1)
                            {
                                sentinel1++;
                            }
                        }
                        if (sentinel1 == 0)
                        {
                            break;
                        }

                        continue;
                    }

                    if (i >= 2)
                    {
                        if (counter == 1)
                        {
                            if (i > index1)
                            {
                                int x = 0;
                                if (turnBackCountera > 0)
                                {
                                    printf("%s do you want to go back?", member1.name);
                                    scanf("%d", &x);
                                    if (x == 1)
                                    {
                                        for (int i = 0; i < 64; i++)
                                        {
                                            array[i].character = arraySupport1[i];
                                        }
                                        member1.points = pointSupporta1;
                                        member2.points = pointSupporta2;
                                        i = index1 - 1;
                                        turnBackCountera--;
                                        counter = 0;
                                        continue;
                                    }
                                }
                            }
                        }
                    }
                    if (i >= 2)
                    {
                        if (counter == 1)
                        {
                            if (i > index2)
                            {
                                int x = 0;
                                if (turnBackCounterb > 0)
                                {
                                    printf("%s do you want to go back?", member2.name);
                                    scanf("%d", &x);
                                    if (x == 1)
                                    {
                                        for (int i = 0; i < 64; i++)
                                        {
                                            array[i].character = arraySupport2[i];
                                        }
                                        member1.points = pointSupportb1;
                                        member2.points = pointSupportb2;
                                        i = index2 - 1;
                                        turnBackCounterb--;
                                        counter = 0;
                                        continue;
                                    }
                                }
                            }
                        }
                    }
                    int index1getnum0 = index1;
                    char arraySupport1getnum0[64];
                    for (int i = 0; i < 64; i++)
                    {
                        arraySupport1getnum0[i] = arraySupport1[i];
                    }
                    int pointSupporta1getnum0 = pointSupporta1;
                    int pointSupporta2getnum0 = pointSupporta2;

                    for (int i = 0; i < 64; i++)
                    {
                        arraySupport1[i] = array[i].character;
                    }
                    if (counter == 0)
                    {
                        counter = 1;
                    }

                    pointSupporta1 = member1.points;
                    pointSupporta2 = member2.points;
                    index1 = i;
                    if (getnum1(array) == 0)
                    {
                        i--;
                        index1 = index1getnum0;
                        pointSupporta1 = pointSupporta1getnum0;
                        pointSupporta2 = pointSupporta2getnum0;
                        for (int i = 0; i < 64; i++)
                        {
                            arraySupport1[i] = arraySupport1getnum0[i];
                        }
                        continue;
                    };

                    // printarray(array);
                    // printf("%s point is :%d\n", member1.name, member1.points);
                    // printf("%s point is :%d\n", member2.name, member2.points);
                }

                /*o turn*/

                if ((i % 2) == 1)
                {
                    for (int j = 0; j < 64; j++)
                    {
                        if (checkb(array, array[j].x, array[j].y) == 1)
                        {
                            //         printf("%s you can choose x = %d y = %d block\n",member2.name,array[j].x, array[j].y);
                            t++;
                        };
                    }
                    if (t == 0)
                    {
                        int sentinel2 = 0;
                        printf("you can't move\n");
                        extraCounter++;
                        for (int j = 0; j < 64; j++)
                        {
                            if (check(array, array[j].x, array[j].y) == 1)
                            {
                                sentinel2++;
                            }
                        }
                        if (sentinel2 == 0)
                        {
                            break;
                        }

                        continue;
                    }
                    if (i >= 2)
                    {
                        if (counter == 1)
                        {
                            if (i > index2)
                            {

                                int x = 0;
                                if (turnBackCounterb > 0)
                                {
                                    printf("%s do you want to go back?", member2.name);
                                    scanf("%d", &x);

                                    if (x == 1)
                                    {
                                        for (int i = 0; i < 64; i++)
                                        {
                                            array[i].character = arraySupport2[i];
                                        }
                                        member1.points = pointSupportb1;
                                        member2.points = pointSupportb2;
                                        // oISupport = i - 2;
                                        i = index2 - 1;
                                        turnBackCounterb--;
                                        counter = 0;
                                        continue;
                                    }
                                }
                            }
                        }
                    }
                    if (i >= 3)
                    {
                        if (counter == 1)
                        {
                            if (i > index1)
                            {

                                int x = 0;
                                if (turnBackCountera > 0)
                                {
                                    printf("%s do you want to go back?", member1.name);
                                    scanf("%d", &x);

                                    if (x == 1)
                                    {
                                        for (int i = 0; i < 64; i++)
                                        {
                                            array[i].character = arraySupport1[i];
                                        }
                                        member1.points = pointSupporta1;
                                        member2.points = pointSupporta2;
                                        i = index1 - 1;
                                        turnBackCountera--;
                                        counter = 0;
                                        continue;
                                    }
                                }
                            }
                        }
                    }
                    int index2getnum0 = index2;
                    char arraySupport2getnum0[64];
                    for (int i = 0; i < 64; i++)
                    {
                        arraySupport2getnum0[i] = arraySupport2[i];
                    }
                    int pointSupportb1getnum0 = pointSupportb1;
                    int pointSupportb2getnum0 = pointSupportb2;

                    index2 = i;
                    for (int i = 0; i < 64; i++)
                    {
                        arraySupport2[i] = array[i].character;
                    }
                    pointSupportb1 = member1.points;
                    pointSupportb2 = member2.points;

                    if (counter == 0)
                    {
                        counter = 1;
                    }

                    if (getnum2(array) == 0)
                    {
                        i--;
                        index2 = index2getnum0;
                        pointSupportb1 = pointSupportb1getnum0;
                        pointSupportb2 = pointSupportb2getnum0;
                        for (int i = 0; i < 64; i++)
                        {
                            arraySupport2[i] = arraySupport2getnum0[i];
                        }

                        continue;
                    }
                }
                printf("do you want to save and quit?(yes = 1, no = 0)\n");
                int quit;
                scanf("%d", &quit);
                if (quit == 1)
                {
                    char holdFileName[50];
                    char holdFIleNameNumber[2];
                    holdFIleNameNumber[0] = '0' + lastFileNUmber + 1;
                    holdFIleNameNumber[1] = '\0';
                    strcpy(holdFileName, member1.name);
                    strcat(holdFileName, member2.name);
                    strcat(holdFileName, "normal");
                    if (lastFileNUmber != -1)
                    {
                        strcat(holdFileName, holdFIleNameNumber);
                    }
                    strcat(holdFileName, ".txt");
                    printf("%s\n", holdFileName);

                    normalSave save;
                    char mainArrayCharacter[64];
                    for (int i = 0; i < 64; i++)
                    {
                        mainArrayCharacter[i] = array[i].character;
                    }
                    codingChar(mainArrayCharacter, mainArrayCoding);
                    codingChar(arraySupport1, arraySupport1Coding);
                    codingChar(arraySupport2, arraySupport2Coding);

                    for (int i = 0; i < 64; i++)
                    {
                        save.array[i] = mainArrayCoding[i];
                    }
                    strcpy(save.member1, (member1.name));
                    strcpy(save.member2, (member2.name));
                    save.turn = codingNumber(i);
                    save.point1 = codingNumber(member1.points);
                    save.point2 = codingNumber(member2.points);
                    for (int i = 0; i < 64; i++)
                    {
                        save.arraySupport1[i] = arraySupport1Coding[i];
                    }
                    for (int i = 0; i < 64; i++)
                    {
                        save.arraySupport2[i] = arraySupport2Coding[i];
                    }
                    save.pointSupporta1 = codingNumber(pointSupporta1);
                    save.pointSupporta2 = codingNumber(pointSupporta2);
                    save.pointSupportb1 = codingNumber(pointSupportb1);
                    save.pointSupportb2 = codingNumber(pointSupportb2);
                    save.turnBackCountera = codingNumber(turnBackCountera);
                    save.turnBackCounterb = codingNumber(turnBackCounterb);
                    save.index1 = codingNumber(index1);
                    save.index2 = codingNumber(index2);
                    save.counter = codingNumber(counter);
                    save.x23 = codingNumber(x23);
                    save.extraCounter = codingNumber(extraCounter);
                    globalPoint readFile;

                    // saving global points
                    globalPointMember1.point = member1.points;
                    strcpy(globalPointMember1.name, member1.name);
                    globalPointMember2.point = member2.points;
                    strcpy(globalPointMember2.name, member2.name);

                    globalPointName1[0] = '\0';
                    strcpy(globalPointName1, member1.name);
                    strcat(globalPointName1, "points.txt");

                    filePointer = fopen(globalPointName1, "w");
                    fwrite(&globalPointMember1, sizeof(globalPointMember1), 1, filePointer);
                    fclose(filePointer);

                    globalPointName1[0] = '\0';
                    strcpy(globalPointName1, member2.name);
                    strcat(globalPointName1, "points.txt");

                    filePointer = fopen(globalPointName1, "w");
                    fwrite(&globalPointMember2, sizeof(globalPointMember2), 1, filePointer);
                    fclose(filePointer);

                    filePointer = fopen(holdFileName, "w");
                    fwrite(&save, sizeof(save), 1, filePointer);
                    fclose(filePointer);
                }
            }
            globalPoint readFile;

            // saving global points
            globalPointMember1.point = member1.points;
            strcpy(globalPointMember1.name, member1.name);
            globalPointMember2.point = member2.points;
            strcpy(globalPointMember2.name, member2.name);
            globalPointName1[0] = '\0';
            strcpy(globalPointName1, member1.name);
            strcat(globalPointName1, "points.txt");

            filePointer = fopen(globalPointName1, "w");
            fwrite(&globalPointMember1, sizeof(globalPointMember1), 1, filePointer);
            fclose(filePointer);

            globalPointName1[0] = '\0';
            strcpy(globalPointName1, member2.name);
            strcat(globalPointName1, "points.txt");

            filePointer = fopen(globalPointName1, "w");
            fwrite(&globalPointMember2, sizeof(globalPointMember2), 1, filePointer);
            fclose(filePointer);
            if (chooseWinner(array) == 1)
            {
                printf("%s won the game", member1.name);
            }
            if (chooseWinner(array) == 2)
            {
                printf("%s won the game", member2.name);
            }
            delay(30);
        }

        //*****************************************************************************************************************************************************************
        //*****************************************************************************************************************************************************************
        if (t == 3)
        {
            printf("\x1b[35mStart a new game in time mode selected\n");
            printf("player 1 please enter your name\n");
            printf("\x1b[0m");
            scanf("%s", &member1.name);
            printf("\x1b[35mplayer 2 please enter your name\n");
            printf("\x1b[0m");
            scanf("%s", &member2.name);
            int lastFileNUmber;
            lastFileNUmber = prointPreviousGames(member1.name, member2.name);
            char holdFileName[50];
            // forchecking the past games
            char holdIsIt1[50];
            char holdIsIt2[50];
            /////////////////////
            strcpy(holdFileName, member1.name);
            strcat(holdFileName, member2.name);
            strcat(holdFileName, ".txt");
            FILE *filePointer;
            saveFile save;
            filePointer = fopen(holdFileName, "r");
            fread(&save, sizeof(save), 1, filePointer);
            fclose(filePointer);

            // global points
            char globalPointName1[20];
            globalPoint readFile1;
            globalPoint readFile2;
            globalPointName1[0] = '\0';
            strcpy(globalPointName1, member1.name);
            strcat(globalPointName1, "points.txt");
            filePointer = fopen(globalPointName1, "r");
            fread(&readFile1, sizeof(readFile1), 1, filePointer);
            fclose(filePointer);

            globalPointName1[0] = '\0';
            strcpy(globalPointName1, member2.name);
            strcat(globalPointName1, "points.txt");
            filePointer = fopen(globalPointName1, "r");
            fread(&readFile2, sizeof(readFile2), 1, filePointer);
            fclose(filePointer);
            char arraySupport1[64];
            char arraySupport2[64];
            int pointSupporta1;
            int pointSupporta2;
            int pointSupportb1;
            int pointSupportb2;
            int turnBackCountera = 2;
            int turnBackCounterb = 2;
            int index1 = 0;
            int index2 = 0;
            int counter = 0;
            int x23;
            int extraCounter = 0;
            int extraTime1a;
            int extraTime1b;
            int extraTime1Counter = 0;
            int extraTime1Countersu = 0;
            int extraTime2a;
            int extraTime2b;
            int extraTime2Counter = 0;
            int extraTime2Countersu = 0;
            strcpy(holdIsIt1, member1.name);
            strcat(holdIsIt1, member2.name);
            strcpy(holdIsIt2, save.member1);
            strcat(holdIsIt2, save.member2);
            int startI;
            // values for coding and decoding
            char mainArrayCoding[64];
            char arraySupport1Coding[64];
            char arraySupport2Coding[64];
            char mainArrayDecoding[64];
            char arraySupport1Decoding[64];
            char arraySupport2Decoding[64];
            if (strcmp(readFile1.name, member1.name) == 0)
            {
                member1.points = readFile1.point;
            }
            else
            {
                member1.points = 0;
            }
            if (strcmp(readFile2.name, member2.name) == 0)
            {
                member2.points = readFile2.point;
            }
            else
            {
                member2.points = 0;
            }

            firstvaluesNotSave(array);
            startI = 0;
            // for turning back

            clock_t start, end;
            for (int i = startI; i < (60 + extraCounter); i++)
            {
                if ((turnBackCountera == 0) && (i == index1))
                {
                    extraTime1Counter++;
                    extraTime1Countersu = 1;
                    turnBackCountera = -1; /*for avoiding to enter again in this if*/
                }
                if ((i == index1 + 1) && (extraTime1Counter == 1))
                {
                    extraTime1Counter++;
                    extraTime1Countersu = 1;
                    extraTime1Counter = 0;
                }

                if ((turnBackCounterb == 0) && (i == index2))
                {
                    extraTime2Counter++;
                    extraTime2Countersu = 1;
                    turnBackCounterb = -1; /*for avoiding to enter again in this if*/
                }
                if ((i == index2 + 1) && (extraTime2Counter == 1))
                {
                    extraTime2Counter++;
                    extraTime2Countersu = 1;
                    extraTime2Counter = 0;
                }

                printarray(array);
                printf("turn = %d\n", i + 1);
                start = clock();
                int t = 0;
                if ((i % 2) == 0)
                {
                    for (int j = 0; j < 64; j++)
                    {
                        if (check(array, array[j].x, array[j].y) == 1)
                        {
                            t++;
                        };
                    }

                    if (t == 0)
                    {
                        int sentinel1 = 0;
                        printf("you can't move \n");
                        extraCounter++;
                        for (int j = 0; j < 64; j++)
                        {
                            if (checkb(array, array[j].x, array[j].y) == 1)
                            {
                                sentinel1++;
                            }
                        }
                        if (sentinel1 == 0)
                        {
                            break;
                        }

                        continue;
                    }
                    if (i >= 2)
                    {
                        if (counter == 1)
                        {
                            if (i > index1)
                            {
                                int x = 0;
                                if (turnBackCountera > 0)
                                {

                                    printf("%s do you want to go back?", member1.name);
                                    scanf("%d", &x);
                                    if (x == 1)
                                    {
                                        if (turnBackCountera == 2)
                                        {
                                            time1 -= 30;
                                        }
                                        if (turnBackCountera)
                                        {
                                            time1 -= 60;
                                        }
                                        for (int i = 0; i < 64; i++)
                                        {
                                            array[i].character = arraySupport1[i];
                                        }
                                        member1.points = pointSupporta1;
                                        member2.points = pointSupporta2;
                                        i = index1 - 1;
                                        turnBackCountera--;
                                        counter = 0;
                                        continue;
                                    }
                                }
                            }
                        }
                    }
                    if (i >= 2)
                    {
                        if (counter == 1)
                        {
                            if (i > index2)
                            {
                                int x = 0;
                                if (turnBackCounterb > 0)
                                {
                                    printf("%s do you want to go back?", member2.name);
                                    scanf("%d", &x);
                                    if (x == 1)
                                    {
                                        if (turnBackCounterb == 2)
                                        {
                                            time2 -= 30;
                                        }
                                        if (turnBackCounterb == 1)
                                        {
                                            time2 -= 60;
                                        }

                                        for (int i = 0; i < 64; i++)
                                        {
                                            array[i].character = arraySupport2[i];
                                        }
                                        member1.points = pointSupportb1;
                                        member2.points = pointSupportb2;
                                        i = index2 - 1;
                                        turnBackCounterb--;
                                        counter = 0;
                                        continue;
                                    }
                                }
                            }
                        }
                    }
                    int index1getnum0 = index1;
                    char arraySupport1getnum0[64];
                    for (int i = 0; i < 64; i++)
                    {
                        arraySupport1getnum0[i] = arraySupport1[i];
                    }
                    int pointSupporta1getnum0 = pointSupporta1;
                    int pointSupporta2getnum0 = pointSupporta2;

                    for (int i = 0; i < 64; i++)
                    {
                        arraySupport1[i] = array[i].character;
                    }
                    if (counter == 0)
                    {
                        counter = 1;
                    }

                    pointSupporta1 = member1.points;
                    pointSupporta2 = member2.points;
                    index1 = i;

                    if (getnum1(array) == 0)
                    {
                        end = clock();
                        int reduce = (end - start) / CLOCKS_PER_SEC;
                        time1 -= reduce;
                        i--;
                        index1 = index1getnum0;
                        pointSupporta1 = pointSupporta1getnum0;
                        pointSupporta2 = pointSupporta2getnum0;
                        for (int i = 0; i < 64; i++)
                        {
                            arraySupport1[i] = arraySupport1getnum0[i];
                        }

                        continue;
                    };
                    end = clock();
                    int reduce = (end - start) / CLOCKS_PER_SEC;
                    time1 -= reduce;
                    // printf("player one reduce = %d\n");
                    if (extraTime1Countersu == 1)
                    {
                        // printf("%d added to time2", reduce);
                        time2 += reduce;
                        extraTime1Countersu = 0;
                    }
                    if (extraTime2Countersu == 1)
                    {
                        // printf("%d added to time1\n", reduce);
                        time1 += reduce;
                        extraTime2Countersu = 0;
                    }

                    if (time1 < 0)
                    {
                        printf("%s you lost the time\n%s won the game", member1.name, member2.name);
                        break;
                    }
                }
                if ((i % 2) == 1)
                {

                    for (int j = 0; j < 64; j++)
                    {
                        if (checkb(array, array[j].x, array[j].y) == 1)
                        {
                            t++;
                        };
                    }
                    if (t == 0)
                    {
                        int sentinel2 = 0;
                        printf("you can't move \n");
                        extraCounter++;
                        for (int j = 0; j < 64; j++)
                        {
                            if (check(array, array[j].x, array[j].y) == 1)
                            {
                                sentinel2++;
                            }
                        }
                        if (sentinel2 == 0)
                        {
                            break;
                        }

                        continue;
                    }
                    if (i >= 2)
                    {
                        if (counter == 1)
                        {
                            if (i > index2)
                            {

                                int x = 0;
                                if (turnBackCounterb > 0)
                                {
                                    printf("%s do you want to go back?", member2.name);
                                    scanf("%d", &x);

                                    if (x == 1)
                                    {
                                        if (turnBackCounterb == 2)
                                        {
                                            time2 -= 30;
                                        }
                                        if (turnBackCounterb == 1)
                                        {
                                            time2 -= 60;
                                        }

                                        for (int i = 0; i < 64; i++)
                                        {
                                            array[i].character = arraySupport2[i];
                                        }
                                        member1.points = pointSupportb1;
                                        member2.points = pointSupportb2;
                                        i = index2 - 1;
                                        turnBackCounterb--;
                                        counter = 0;
                                        continue;
                                    }
                                }
                            }
                        }
                    }
                    if (i >= 3)
                    {
                        if (counter == 1)
                        {
                            if (i > index1)
                            {

                                int x = 0;
                                if (turnBackCountera > 0)
                                {
                                    printf("%s do you want to go back?", member1.name);
                                    scanf("%d", &x);

                                    if (x == 1)
                                    {
                                        if (turnBackCountera == 2)
                                        {
                                            time1 -= 30;
                                        }
                                        if (turnBackCountera == 1)
                                        {
                                            time1 -= 60;
                                        }

                                        for (int i = 0; i < 64; i++)
                                        {
                                            array[i].character = arraySupport1[i];
                                        }
                                        member1.points = pointSupporta1;
                                        member2.points = pointSupporta2;
                                        i = index1 - 1;
                                        turnBackCountera--;
                                        counter = 0;
                                        continue;
                                    }
                                }
                            }
                        }
                    }
                    int index2getnum0 = index2;
                    char arraySupport2getnum0[64];
                    for (int i = 0; i < 64; i++)
                    {
                        arraySupport2getnum0[i] = arraySupport2[i];
                    }
                    int pointSupportb1getnum0 = pointSupportb1;
                    int pointSupportb2getnum0 = pointSupportb2;

                    for (int i = 0; i < 64; i++)
                    {
                        arraySupport2[i] = array[i].character;
                    }
                    pointSupportb1 = member1.points;
                    pointSupportb2 = member2.points;
                    index2 = i;
                    if (counter == 0)
                    {
                        counter = 1;
                    }

                    if (getnum2(array) == 0)
                    {
                        i--;
                        index2 = index2getnum0;
                        pointSupportb1 = pointSupportb1getnum0;
                        pointSupportb2 = pointSupportb2getnum0;
                        for (int i = 0; i < 64; i++)
                        {
                            arraySupport2[i] = arraySupport2getnum0[i];
                        }

                        continue;
                    };
                    end = clock();
                    int reduce = (end - start) / CLOCKS_PER_SEC;
                    time2 -= reduce;
                    if (extraTime1Countersu == 1)
                    {
                        time2 += reduce;
                        extraTime1Countersu = 0;
                    }
                    if (extraTime2Countersu == 1)
                    {
                        time1 += reduce;
                        extraTime2Countersu = 0;
                    }

                    if (time2 < 0)
                    {
                        printf("%s you lost the time\n%s won the game", member2.name, member1.name);
                        break;
                    }
                }
                printf("do you want to save the game and quit?(yes = 1/no = 0)\n");
                int saveCheck;
                scanf("%d", &saveCheck);
                if (saveCheck == 1)
                {

                    char holdFileName[50];
                    char holdFIleNameNumber[2];

                    holdFIleNameNumber[0] = '0' + lastFileNUmber + 1;
                    holdFIleNameNumber[1] = '\0';
                    strcpy(holdFileName, member1.name);
                    strcat(holdFileName, member2.name);
                    if (lastFileNUmber != -1)
                    {
                        strcat(holdFileName, holdFIleNameNumber);
                    }
                    strcat(holdFileName, ".txt");
                    char mainArrayCharacter[64];
                    for (int i = 0; i < 64; i++)
                    {
                        mainArrayCharacter[i] = array[i].character;
                    }
                    codingChar(mainArrayCharacter, mainArrayCoding);
                    codingChar(arraySupport1, arraySupport1Coding);
                    codingChar(arraySupport2, arraySupport2Coding);

                    for (int i = 0; i < 64; i++)
                    {
                        save.array[i] = mainArrayCoding[i];
                    }
                    strcpy(save.member1, (member1.name));
                    strcpy(save.member2, (member2.name));
                    save.time1 = (time1);
                    save.time2 = (time2);
                    save.turn = codingNumber(i);
                    save.point1 = codingNumber(member1.points);
                    save.point2 = codingNumber(member2.points);
                    for (int i = 0; i < 64; i++)
                    {
                        save.arraySupport1[i] = arraySupport1Coding[i];
                    }
                    for (int i = 0; i < 64; i++)
                    {
                        save.arraySupport2[i] = arraySupport2Coding[i];
                    }
                    save.pointSupporta1 = codingNumber(pointSupporta1);
                    save.pointSupporta2 = codingNumber(pointSupporta2);
                    save.pointSupportb1 = codingNumber(pointSupportb1);
                    save.pointSupportb2 = codingNumber(pointSupportb2);
                    save.turnBackCountera = codingNumber(turnBackCountera);
                    save.turnBackCounterb = codingNumber(turnBackCounterb);
                    save.index1 = codingNumber(index1);
                    save.index2 = codingNumber(index2);
                    save.counter = codingNumber(counter);
                    save.x23 = codingNumber(x23);
                    save.extraCounter = codingNumber(extraCounter);
                    save.extraTime1a = codingNumber(extraTime1a);
                    save.extraTime1b = codingNumber(extraTime1b);
                    save.extraTime1Counter = codingNumber(extraTime1Counter);
                    save.extraTime1Countersu = codingNumber(extraTime1Countersu);
                    save.extraTime2a = codingNumber(extraTime2a);
                    save.extraTime2b = codingNumber(extraTime2b);
                    save.extraTime2Counter = codingNumber(extraTime2Counter);
                    save.extraTime2Countersu = codingNumber(extraTime2Countersu);

                    globalPoint readFile;

                    // saving global points
                    globalPointMember1.point = member1.points;
                    strcpy(globalPointMember1.name, member1.name);
                    globalPointMember2.point = member2.points;
                    strcpy(globalPointMember2.name, member2.name);
                    char globalPointName1[20];

                    globalPointName1[0] = '\0';
                    strcpy(globalPointName1, member1.name);
                    strcat(globalPointName1, "points.txt");

                    filePointer = fopen(globalPointName1, "w");
                    fwrite(&globalPointMember1, sizeof(globalPointMember1), 1, filePointer);
                    fclose(filePointer);

                    globalPointName1[0] = '\0';
                    strcpy(globalPointName1, member2.name);
                    strcat(globalPointName1, "points.txt");

                    filePointer = fopen(globalPointName1, "w");
                    fwrite(&globalPointMember2, sizeof(globalPointMember2), 1, filePointer);
                    fclose(filePointer);
                    filePointer = fopen(holdFileName, "w");
                    fwrite(&save, sizeof(save), 1, filePointer);
                    fclose(filePointer);
                }
            }
            globalPoint readFile;

            // saving global points
            globalPointMember1.point = member1.points;
            strcpy(globalPointMember1.name, member1.name);
            globalPointMember2.point = member2.points;
            strcpy(globalPointMember2.name, member2.name);
            globalPointName1[0] = '\0';
            strcpy(globalPointName1, member1.name);
            strcat(globalPointName1, "points.txt");

            filePointer = fopen(globalPointName1, "w");
            fwrite(&globalPointMember1, sizeof(globalPointMember1), 1, filePointer);
            fclose(filePointer);

            globalPointName1[0] = '\0';
            strcpy(globalPointName1, member2.name);
            strcat(globalPointName1, "points.txt");

            filePointer = fopen(globalPointName1, "w");
            fwrite(&globalPointMember2, sizeof(globalPointMember2), 1, filePointer);
            fclose(filePointer);
            if (chooseWinner(array) == 1)
            {
                printf("%s won the game", member1.name);
            }
            if (chooseWinner(array) == 2)
            {
                printf("%s won the game", member2.name);
            }
            delay(30);
        }

        /*resume normal mode*/
        if (t == 4)
        {
            scanf("%s", &member1.name);
            scanf("%s", &member2.name);
            int lastFileNUmber;
            lastFileNUmber = prointPreviousGamesNormal(member1.name, member2.name);
            char holdFileName[50];
            // forchecking the past games
            char holdIsIt1[50] = {'\0'};
            char holdIsIt2[50] = {'\0'};
            printf("which game do you want to continue?\n");
            // Enter which game do you want to resume...
            scanf("%s", holdFileName);
            FILE *filePointer;
            char globalPointName1[20];
            globalPoint readFile1;
            globalPoint readFile2;
            globalPointName1[0] = '\0';
            strcpy(globalPointName1, member1.name);
            strcat(globalPointName1, "points.txt");
            filePointer = fopen(globalPointName1, "r");
            fread(&readFile1, sizeof(readFile1), 1, filePointer);
            fclose(filePointer);

            globalPointName1[0] = '\0';
            strcpy(globalPointName1, member2.name);
            strcat(globalPointName1, "points.txt");
            filePointer = fopen(globalPointName1, "r");
            fread(&readFile2, sizeof(readFile2), 1, filePointer);
            fclose(filePointer);
            // opening the save file
            normalSave save;
            filePointer = fopen(holdFileName, "r");
            fread(&save, sizeof(save), 1, filePointer);
            fclose(filePointer);
            //////////////////
            member1.points = readFile1.point;
            member2.points = readFile2.point;
            strcpy(holdIsIt1, member1.name);
            strcat(holdIsIt1, member2.name);
            strcpy(holdIsIt2, save.member1);
            strcat(holdIsIt2, save.member2);
            int startI;
            // values for coding and decoding
            char mainArrayCoding[64];
            char arraySupport1Coding[64];
            char arraySupport2Coding[64];
            char mainArrayDecoding[64];
            char arraySupport1Decoding[64];
            char arraySupport2Decoding[64];

            char arraySupport1[64];
            char arraySupport2[64];
            int pointSupporta1;
            int pointSupporta2;
            int pointSupportb1;
            int pointSupportb2;
            // firstvaluesSave(array);
            int turnBackCountera = 2;
            int turnBackCounterb = 2;
            int index1 = 0;
            int index2 = 0;
            int counter = 0;
            int x23;
            int extraCounter = 0;
            if (strcmp(holdIsIt1, holdIsIt2) == 0)
            {

                // decoding
                startI = decodingNumber(save.turn) + 1;
                member1.points = readFile1.point;
                member2.points = readFile2.point;
                decodingChar(save.array, mainArrayDecoding);
                decodingChar(save.arraySupport1, arraySupport1Decoding);
                decodingChar(save.arraySupport2, arraySupport2Decoding);
                for (int i = 0; i < 64; i++)
                {
                    array[i].character = mainArrayDecoding[i];
                }
                firstvaluesSave(array);
                for (int i = 0; i < 64; i++)
                {
                    arraySupport1[i] = arraySupport1Decoding[i];
                }
                printf("\n");
                for (int i = 0; i < 64; i++)
                {
                    arraySupport2[i] = arraySupport2Decoding[i];
                }
                printf("\n");

                pointSupporta1 = readFile1.point + decodingNumber(save.pointSupporta1) - member1.points;
                pointSupporta2 = readFile2.point + decodingNumber(save.pointSupporta2) - member2.points;
                pointSupportb1 = readFile1.point + decodingNumber(save.pointSupportb1) - member1.points;
                pointSupportb2 = readFile2.point + decodingNumber(save.pointSupportb2) - member2.points;
                turnBackCountera = decodingNumber(save.turnBackCountera);
                turnBackCounterb = decodingNumber(save.turnBackCounterb);
                index1 = decodingNumber(save.index1);
                index2 = decodingNumber(save.index2);
                counter = decodingNumber(save.counter);
                x23 = decodingNumber(save.x23);
                extraCounter = decodingNumber(save.extraCounter);
                for (int i = startI; i < 60 + extraCounter; i++)
                {
                    printarray(array);
                    printf("turn = %d\n", i + 1);
                    int t = 0;

                    if ((i % 2) == 0)
                    {
                        for (int j = 0; j < 64; j++)
                        {
                            if (check(array, array[j].x, array[j].y) == 1)
                            {
                                t++;
                            };
                        }
                        if (t == 0)
                        {
                            int sentinel1 = 0;
                            printf("you can't move\n");
                            extraCounter++;
                            for (int j = 0; j < 64; j++)
                            {
                                if (checkb(array, array[j].x, array[j].y) == 1)
                                {
                                    sentinel1++;
                                }
                            }
                            if (sentinel1 == 0)
                            {
                                break;
                            }

                            continue;
                        }

                        if (i >= 2)
                        {
                            if (counter == 1)
                            {
                                if (i > index1)
                                {
                                    int x = 0;
                                    if (turnBackCountera > 0)
                                    {
                                        printf("%s do you want to go back?", member1.name);
                                        scanf("%d", &x);
                                        if (x == 1)
                                        {
                                            for (int i = 0; i < 64; i++)
                                            {
                                                array[i].character = arraySupport1[i];
                                            }
                                            member1.points = pointSupporta1;
                                            member2.points = pointSupporta2;
                                            i = index1 - 1;
                                            turnBackCountera--;
                                            counter = 0;
                                            continue;
                                        }
                                    }
                                }
                            }
                        }
                        if (i >= 2)
                        {
                            if (counter == 1)
                            {
                                if (i > index2)
                                {
                                    int x = 0;
                                    if (turnBackCounterb > 0)
                                    {
                                        printf("%s do you want to go back?", member2.name);
                                        scanf("%d", &x);
                                        if (x == 1)
                                        {
                                            for (int i = 0; i < 64; i++)
                                            {
                                                array[i].character = arraySupport2[i];
                                            }
                                            member1.points = pointSupportb1;
                                            member2.points = pointSupportb2;
                                            i = index2 - 1;
                                            turnBackCounterb--;
                                            counter = 0;
                                            continue;
                                        }
                                    }
                                }
                            }
                        }
                        int index1getnum0 = index1;
                        char arraySupport1getnum0[64];
                        for (int i = 0; i < 64; i++)
                        {
                            arraySupport1getnum0[i] = arraySupport1[i];
                        }
                        int pointSupporta1getnum0 = pointSupporta1;
                        int pointSupporta2getnum0 = pointSupporta2;

                        for (int i = 0; i < 64; i++)
                        {
                            arraySupport1[i] = array[i].character;
                        }
                        if (counter == 0)
                        {
                            counter = 1;
                        }

                        pointSupporta1 = member1.points;
                        pointSupporta2 = member2.points;
                        index1 = i;
                        if (getnum1(array) == 0)
                        {
                            i--;
                            index1 = index1getnum0;
                            pointSupporta1 = pointSupporta1getnum0;
                            pointSupporta2 = pointSupporta2getnum0;
                            for (int i = 0; i < 64; i++)
                            {
                                arraySupport1[i] = arraySupport1getnum0[i];
                            }

                            continue;
                        };

                        // printarray(array);
                        // printf("%s point is :%d\n", member1.name, member1.points);
                        // printf("%s point is :%d\n", member2.name, member2.points);
                    }

                    /*o turn*/

                    if ((i % 2) == 1)
                    {
                        for (int j = 0; j < 64; j++)
                        {
                            if (checkb(array, array[j].x, array[j].y) == 1)
                            {
                                //         printf("%s you can choose x = %d y = %d block\n",member2.name,array[j].x, array[j].y);
                                t++;
                            };
                        }
                        if (t == 0)
                        {
                            int sentinel2 = 0;
                            printf("you can't move\n");
                            extraCounter++;
                            for (int j = 0; j < 64; j++)
                            {
                                if (check(array, array[j].x, array[j].y) == 1)
                                {
                                    sentinel2++;
                                }
                            }
                            if (sentinel2 == 0)
                            {
                                break;
                            }

                            continue;
                        }
                        if (i >= 2)
                        {
                            if (counter == 1)
                            {
                                if (i > index2)
                                {

                                    int x = 0;
                                    if (turnBackCounterb > 0)
                                    {
                                        printf("%s do you want to go back?", member2.name);
                                        scanf("%d", &x);

                                        if (x == 1)
                                        {
                                            for (int i = 0; i < 64; i++)
                                            {
                                                array[i].character = arraySupport2[i];
                                            }
                                            member1.points = pointSupportb1;
                                            member2.points = pointSupportb2;
                                            // oISupport = i - 2;
                                            i = index2 - 1;
                                            turnBackCounterb--;
                                            counter = 0;
                                            continue;
                                        }
                                    }
                                }
                            }
                        }
                        if (i >= 3)
                        {
                            if (counter == 1)
                            {
                                if (i > index1)
                                {

                                    int x = 0;
                                    if (turnBackCountera > 0)
                                    {
                                        printf("%s do you want to go back?", member1.name);
                                        scanf("%d", &x);

                                        if (x == 1)
                                        {
                                            for (int i = 0; i < 64; i++)
                                            {
                                                array[i].character = arraySupport1[i];
                                            }
                                            member1.points = pointSupporta1;
                                            member2.points = pointSupporta2;
                                            i = index1 - 1;
                                            turnBackCountera--;
                                            counter = 0;
                                            continue;
                                        }
                                    }
                                }
                            }
                        }
                        int index2getnum0 = index2;
                        char arraySupport2getnum0[64];
                        for (int i = 0; i < 64; i++)
                        {
                            arraySupport2getnum0[i] = arraySupport2[i];
                        }
                        int pointSupportb1getnum0 = pointSupportb1;
                        int pointSupportb2getnum0 = pointSupportb2;

                        for (int i = 0; i < 64; i++)
                        {
                            arraySupport2[i] = array[i].character;
                        }
                        pointSupportb1 = member1.points;
                        pointSupportb2 = member2.points;
                        index2 = i;
                        if (counter == 0)
                        {
                            counter = 1;
                        }

                        if (getnum2(array) == 0)
                        {
                            i--;
                            index2 = index2getnum0;
                            pointSupportb1 = pointSupportb1getnum0;
                            pointSupportb2 = pointSupportb2getnum0;
                            for (int i = 0; i < 64; i++)
                            {
                                arraySupport2[i] = arraySupport2getnum0[i];
                            }

                            continue;
                        };
                    }
                    printf("do you want to save and quit?(yes = 1, no = 0)\n");
                    int quit;
                    scanf("%d", &quit);
                    if (quit == 1)
                    {

                        normalSave save;
                        char mainArrayCharacter[64];
                        for (int i = 0; i < 64; i++)
                        {
                            mainArrayCharacter[i] = array[i].character;
                        }
                        codingChar(mainArrayCharacter, mainArrayCoding);
                        codingChar(arraySupport1, arraySupport1Coding);
                        codingChar(arraySupport2, arraySupport2Coding);

                        for (int i = 0; i < 64; i++)
                        {
                            save.array[i] = mainArrayCoding[i];
                        }
                        strcpy(save.member1, (member1.name));
                        strcpy(save.member2, (member2.name));
                        save.turn = codingNumber(i);
                        save.point1 = codingNumber(member1.points);
                        save.point2 = codingNumber(member2.points);
                        for (int i = 0; i < 64; i++)
                        {
                            save.arraySupport1[i] = arraySupport1Coding[i];
                        }
                        for (int i = 0; i < 64; i++)
                        {
                            save.arraySupport2[i] = arraySupport2Coding[i];
                        }
                        save.pointSupporta1 = codingNumber(pointSupporta1);
                        save.pointSupporta2 = codingNumber(pointSupporta2);
                        save.pointSupportb1 = codingNumber(pointSupportb1);
                        save.pointSupportb2 = codingNumber(pointSupportb2);
                        save.turnBackCountera = codingNumber(turnBackCountera);
                        save.turnBackCounterb = codingNumber(turnBackCounterb);
                        save.index1 = codingNumber(index1);
                        save.index2 = codingNumber(index2);
                        save.counter = codingNumber(counter);
                        save.x23 = codingNumber(x23);
                        save.extraCounter = codingNumber(extraCounter);
                        globalPoint readFile;

                        // saving global points
                        globalPointMember1.point = member1.points;
                        strcpy(globalPointMember1.name, member1.name);
                        globalPointMember2.point = member2.points;
                        strcpy(globalPointMember2.name, member2.name);
                        char globalPointName1[20];

                        globalPointName1[0] = '\0';
                        strcpy(globalPointName1, member1.name);
                        strcat(globalPointName1, "points.txt");

                        filePointer = fopen(globalPointName1, "w");
                        fwrite(&globalPointMember1, sizeof(globalPointMember1), 1, filePointer);
                        fclose(filePointer);

                        globalPointName1[0] = '\0';
                        strcpy(globalPointName1, member2.name);
                        strcat(globalPointName1, "points.txt");

                        filePointer = fopen(globalPointName1, "w");
                        fwrite(&globalPointMember2, sizeof(globalPointMember2), 1, filePointer);
                        fclose(filePointer);

                        filePointer = fopen(holdFileName, "w");
                        fwrite(&save, sizeof(save), 1, filePointer);
                        fclose(filePointer);
                    }
                }
                globalPoint readFile;

                // saving global points
                globalPointMember1.point = member1.points;
                strcpy(globalPointMember1.name, member1.name);
                globalPointMember2.point = member2.points;
                strcpy(globalPointMember2.name, member2.name);
                char globalPointName1[20];

                globalPointName1[0] = '\0';
                strcpy(globalPointName1, member1.name);
                strcat(globalPointName1, "points.txt");

                filePointer = fopen(globalPointName1, "w");
                fwrite(&globalPointMember1, sizeof(globalPointMember1), 1, filePointer);
                fclose(filePointer);

                globalPointName1[0] = '\0';
                strcpy(globalPointName1, member2.name);
                strcat(globalPointName1, "points.txt");

                filePointer = fopen(globalPointName1, "w");
                fwrite(&globalPointMember2, sizeof(globalPointMember2), 1, filePointer);
                fclose(filePointer);

                if (chooseWinner(array) == 1)
                {
                    printf("%s won the game", member1.name);
                }
                if (chooseWinner(array) == 2)
                {
                    printf("%s won the game", member2.name);
                }
            }
            delay(30);
        }
        if (t == 5)
        {
            printf("Bye");
            break;
        }
    }
    return 0;
}

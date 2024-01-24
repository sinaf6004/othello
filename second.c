#include <stdio.h>
#include <time.h>
#include "mymenu.h"
#include <stdlib.h>
#include <string.h>

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
members member1;
members member2;
void firstvalues(partition array[])
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
void printPointsa()
{
    printf("%s point is :\x1b[36m%d", member1.name, member1.points);
    printf("\x1b[0m");
}
void printPointsb()
{
    printf("%s point is :\x1b[36m%d", member2.name, member2.points);
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
    scanf("%d%d", &x, &y);
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
    // scanf("%d%d",&x,&y);
    scanf("%d%d", &x, &y);
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

int time1 = 300;
int time2 = 300;

int main()
{
    partition array[64];
    int t = menu();
    // printf("%d\n", t);
    if (t == 3)
    {
        scanf("%s", &member1.name);
        scanf("%s", &member2.name);
        member1.points = 0;
        member2.points = 0;
        char arraySupport1[64];
        char arraySupport2[64];
        int pointSupporta1;
        int pointSupporta2;
        int pointSupportb1;
        int pointSupportb2;
        firstvalues(array);
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
        clock_t start, end;
        for (int i = 0; i < 64 + extraCounter; i++)
        {
            if ((turnBackCountera == 0) && (i == index1))
            {
                extraTime1Counter++;
                extraTime1Countersu = 1;
            }
            if ((i == index1 + 1) && (extraTime1Counter == 1))
            {
                extraTime1Counter++;
                extraTime1Countersu = 1;
                extraTime1Counter = 0;
            }

            if (i == index2)
            {
                // printf("mohammad has returned\n");
            }

            printarray(array);
            printf("i = %d\n", i);
            start = clock();
            int t = 0;
            if ((i % 2) == 0)
            {
                for (int j = 0; j < 64; j++)
                {
                    if (check(array, array[j].x, array[j].y) == 1)
                    {
                        // printf("%s you can choose x = %d y = %d block\n", member1.name, array[j].x, array[j].y);
                        t++;
                    };
                }
                // printf("t = %d\n");

                if (t == 0)
                {
                    int sentinel1 = 0;
                    printf("you can't move ff\n");
                    // end = clock();
                    // int reduce = (end - start) / CLOCKS_PER_SEC;
                    // time1 -= reduce;
                    // printf("time 1 = %d\n", time1);
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
                                    // tIsupport = i - 2;
                                    i -= 3;
                                    turnBackCountera--;
                                    counter = 0;
                                    continue;
                                }
                            }
                        }
                    }
                }
                if (i >= 4)
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
                                    i -= 2;
                                    turnBackCounterb--;
                                    counter = 0;
                                    continue;
                                }
                            }
                        }
                    }
                }
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
                    printf("time 1 = %d\n", time1);
                    i--;
                    continue;
                };
                end = clock();
                int reduce = (end - start) / CLOCKS_PER_SEC;
                time1 -= reduce;
                printf("player one reduce = %d\n");
                if (extraTime1Countersu == 1)
                {
                    time2 += reduce;
                    extraTime1Countersu = 0;
                }

                if (time1 < 0)
                {
                    printf("player one you lost the time\nplayer 2 won thegame");
                    break;
                }

                // printarray(array);
                // printf("%s point is :%d\n", member1.name, member1.points);
                // printf("%s point is :%d\n", member2.name, member2.points);
            }
            if ((i % 2) == 1)
            {

                for (int j = 0; j < 64; j++)
                {
                    if (checkb(array, array[j].x, array[j].y) == 1)
                    {
                        // printf("%s you can choose x = %d y = %d block\n", member2.name, array[j].x, array[j].y);
                        t++;
                    };
                }
                printf("t = %d\n");
                if (t == 0)
                {
                    int sentinel2 = 0;
                    printf("you can't move lll\n");
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
                if (i >= 3)
                {
                    if (counter == 1)
                    {
                        if (i > index2)
                        {

                            int x = 0;
                            // if (oISupport != i)
                            // {
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
                                    i -= 3;
                                    turnBackCounterb--;
                                    counter = 0;
                                    continue;
                                }
                            }
                            // }
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
                                    i -= 2;
                                    turnBackCountera--;
                                    counter = 0;
                                    continue;
                                }
                            }
                        }
                    }
                }
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
                    continue;
                };
                end = clock();
                int reduce = (end - start) / CLOCKS_PER_SEC;
                time2 -= reduce;
                printf("player two reduce = %d\n");
                if (extraTime1Countersu == 1)
                {
                    time2 += reduce;
                    extraTime1Countersu = 0;
                }

                if (time2 < 0)
                {
                    printf("player two you lost the time\nplayer 1 won thegame");
                    break;
                }
                // printarray(array);
                // printf("%s point is :%d\n", member1.name, member1.points);
                // printf("%s point is :%d\n", member2.name, member2.points);
            }
            // end = clock();
            // int reduce = (end-start)/CLOCKS_PER_SEC;
            if (i % 2 == 0)
            {
                //     time1 -= reduce;
                //     if (time1<0)
                //     {
                //         printf("player one you lost the time\nplayer 2 won thegame");
                //         break;
                //     }

                printf("time 1 = %d\n", time1);
            }
            if (i % 2 == 1)
            {
                //     time2 -= reduce;
                //     if (time2<0)
                //     {
                //         printf("player two you lost the time\nplayer 1 won thegame");
                //         break;
                //     }
                printf("time 2 = %d\n", time2);
            }
        }
    }

    /*normal mode*/

    //     if (t == 2)
    //     {
    //         scanf("%s", &member1.name);
    //         scanf("%s", &member2.name);
    //         FILE *fp;
    //         char hold1[50];
    //         char hold2[50];
    //         for (int i = 0; i < 50; i++)
    //         {
    //             hold1[i] = member1.name[i];
    //         }
    //         strcat(hold1, ".txt");
    //         fp = fopen(hold1, "r");
    //         fscanf(fp, "%d", &member1.points);
    //         fclose(fp);

    //         for (int i = 0; i < 50; i++)
    //         {
    //             hold2[i] = member2.name[i];
    //         }
    //         strcat(hold2, ".txt");
    //         fp = fopen(hold2, "r");
    //         fscanf(fp, "%d", &member2.points);
    //         fclose(fp);
    //         printf("%d----%d\n", member1.points, member2.points);

    //         member1.points = 0;
    //         member2.points = 0;
    //         char arraySupport1[64];
    //         char arraySupport2[64];
    //         int pointSupporta1;
    //         int pointSupporta2;
    //         int pointSupportb1;
    //         int pointSupportb2;
    //         firstvalues(array);
    //         int turnBackCountera = 2;
    //         int turnBackCounterb = 2;
    //         int index1 = 0;
    //         int index2 = 0;
    //         int counter = 0;
    //         int x23;
    //         int extraCounter = 0;
    //         for (int i = 0; i < 64 + extraCounter; i++)
    //         {
    //             printarray(array);
    //             printf("i = %d\n", i);
    //             int t = 0;
    //             /*#turn*/
    //             printf("do you wanna qiut and save?");

    //             scanf("%d", &x23);
    //             if (x23 == 1)
    //             {
    //                 fp = fopen(hold1, "w");
    //                 fprintf(fp, "%d", member1.points);
    //                 fclose(fp);
    //                 fp = fopen(hold2, "w");
    //                 fprintf(fp, "%d", member2.points);
    //                 fclose(fp);
    //                 printf("%s", "goodbye");
    //                 break;
    //             }

    //             if ((i % 2) == 0)
    //             {
    //                 for (int j = 0; j < 64; j++)
    //                 {
    //                     if (check(array, array[j].x, array[j].y) == 1)
    //                     {
    //                         //         printf("%s you can choose x = %d y = %d block\n",member1.name,array[j].x, array[j].y);
    //                         t++;
    //                     };
    //                 }
    //                 if (t == 0)
    //                 {
    //                     int sentinel1 = 0;
    //                     printf("you can't move\n");
    //                     extraCounter++;
    //                     for (int j = 0; j < 64; j++)
    //                     {
    //                         if (checkb(array, array[j].x, array[j].y) == 1)
    //                         {
    //                             sentinel1++;
    //                         }
    //                     }
    //                     if (sentinel1 == 0)
    //                     {
    //                         break;
    //                     }

    //                     continue;
    //                 }

    //                 if (i >= 2)
    //                 {
    //                     if (counter == 1)
    //                     {
    //                         if (i > index1)
    //                         {
    //                             int x = 0;
    //                             if (turnBackCountera > 0)
    //                             {
    //                                 printf("%s do you want to go back?", member1.name);
    //                                 scanf("%d", &x);
    //                                 if (x == 1)
    //                                 {
    //                                     for (int i = 0; i < 64; i++)
    //                                     {
    //                                         array[i].character = arraySupport1[i];
    //                                     }
    //                                     member1.points = pointSupporta1;
    //                                     member2.points = pointSupporta2;
    //                                     // tIsupport = i - 2;
    //                                     i -= 3;
    //                                     turnBackCountera--;
    //                                     counter = 0;
    //                                     continue;
    //                                 }
    //                             }
    //                         }
    //                     }
    //                 }
    //                 if (i >= 4)
    //                 {
    //                     if (counter == 1)
    //                     {
    //                         if (i > index2)
    //                         {
    //                             int x = 0;
    //                             if (turnBackCounterb > 0)
    //                             {
    //                                 printf("%s do you want to go back?", member2.name);
    //                                 scanf("%d", &x);
    //                                 if (x == 1)
    //                                 {
    //                                     for (int i = 0; i < 64; i++)
    //                                     {
    //                                         array[i].character = arraySupport2[i];
    //                                     }
    //                                     member1.points = pointSupportb1;
    //                                     member2.points = pointSupportb2;
    //                                     i -= 2;
    //                                     turnBackCounterb--;
    //                                     counter = 0;
    //                                     continue;
    //                                 }
    //                             }
    //                         }
    //                     }
    //                 }

    //                 for (int i = 0; i < 64; i++)
    //                 {
    //                     arraySupport1[i] = array[i].character;
    //                 }
    //                 if (counter == 0)
    //                 {
    //                     counter = 1;
    //                 }

    //                 pointSupporta1 = member1.points;
    //                 pointSupporta2 = member2.points;
    //                 index1 = i;
    //                 if (getnum1(array) == 0)
    //                 {
    //                     i--;
    //                     continue;
    //                 };

    //                 // printarray(array);
    //                 // printf("%s point is :%d\n", member1.name, member1.points);
    //                 // printf("%s point is :%d\n", member2.name, member2.points);
    //             }

    //             /*o turn*/

    //             if ((i % 2) == 1)
    //             {
    //                 for (int j = 0; j < 64; j++)
    //                 {
    //                     if (checkb(array, array[j].x, array[j].y) == 1)
    //                     {
    //                         //         printf("%s you can choose x = %d y = %d block\n",member2.name,array[j].x, array[j].y);
    //                         t++;
    //                     };
    //                 }
    //                 if (t == 0)
    //                 {
    //                     int sentinel2 = 0;
    //                     printf("you can't move\n");
    //                     extraCounter++;
    //                     for (int j = 0; j < 64; j++)
    //                     {
    //                         if (check(array, array[j].x, array[j].y) == 1)
    //                         {
    //                             sentinel2++;
    //                         }
    //                     }
    //                     if (sentinel2 == 0)
    //                     {
    //                         break;
    //                     }

    //                     continue;
    //                 }
    //                 if (i >= 3)
    //                 {
    //                     if (counter == 1)
    //                     {
    //                         if (i > index2)
    //                         {

    //                             int x = 0;
    //                             // if (oISupport != i)
    //                             // {
    //                             if (turnBackCounterb > 0)
    //                             {
    //                                 printf("%s do you want to go back?", member2.name);
    //                                 scanf("%d", &x);

    //                                 if (x == 1)
    //                                 {
    //                                     for (int i = 0; i < 64; i++)
    //                                     {
    //                                         array[i].character = arraySupport2[i];
    //                                     }
    //                                     member1.points = pointSupportb1;
    //                                     member2.points = pointSupportb2;
    //                                     // oISupport = i - 2;
    //                                     i -= 3;
    //                                     turnBackCounterb--;
    //                                     counter = 0;
    //                                     continue;
    //                                 }
    //                             }
    //                             // }
    //                         }
    //                     }
    //                 }
    //                 if (i >= 3)
    //                 {
    //                     if (counter == 1)
    //                     {
    //                         if (i > index1)
    //                         {

    //                             int x = 0;
    //                             if (turnBackCountera > 0)
    //                             {
    //                                 printf("%s do you want to go back?", member1.name);
    //                                 scanf("%d", &x);

    //                                 if (x == 1)
    //                                 {
    //                                     for (int i = 0; i < 64; i++)
    //                                     {
    //                                         array[i].character = arraySupport1[i];
    //                                     }
    //                                     member1.points = pointSupporta1;
    //                                     member2.points = pointSupporta2;
    //                                     i -= 2;
    //                                     turnBackCountera--;
    //                                     counter = 0;
    //                                     continue;
    //                                 }
    //                             }
    //                         }
    //                     }
    //                 }
    //                 for (int i = 0; i < 64; i++)
    //                 {
    //                     arraySupport2[i] = array[i].character;
    //                 }
    //                 pointSupportb1 = member1.points;
    //                 pointSupportb2 = member2.points;
    //                 index2 = i;
    //                 if (counter == 0)
    //                 {
    //                     counter = 1;
    //                 }

    //                 if (getnum2(array) == 0)
    //                 {
    //                     i--;
    //                     continue;
    //                 };

    //                 // printarray(array);
    //                 // printf("%s point is :%d\n", member1.name, member1.points);
    //                 // printf("%s point is :%d\n", member2.name, member2.points);
    //             }
    //         }
    //         if (chooseWinner(array) == 1)
    //         {
    //             printf("%s won the game", member1.name);
    //         }
    //         if (chooseWinner(array) == 2)
    //         {
    //             printf("%s won the game", member2.name);
    //         }
    //     }
    return 0;
}

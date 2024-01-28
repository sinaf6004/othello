#ifndef READ_PREVIOUS_FILES_H_INCLUDED
#define READ_PREVIOUS_FILES_H_INCLUDED
#include <stdio.h>
#include <string.h>
struct identity
{
    char name1[10];
    char name2[10];
};
typedef struct identity identities;
int prointPreviousGames(char member1[], char member2[])
{

    identities file1;
    strcpy(file1.name1, member1);
    strcpy(file1.name2, member2);
    FILE *fp;
    // for writing
    fp = fopen("sinamona4.txt", "w");
    fwrite(&file1, sizeof(file1), 1, fp);
    fclose(fp);
    identities filereader;
    char firstFile[20] = {'\0'};
    strcat(firstFile, file1.name1);
    strcat(firstFile, file1.name2);
    strcat(firstFile, ".txt");
    fp = fopen(firstFile, "r");
    fread(&filereader, sizeof(filereader), 1, fp);
    fclose(fp);
    char hold1[20] = {'\0'};
    char hold2[20] = {'\0'};
    strcat(hold1, filereader.name1);
    strcat(hold1, filereader.name2);
    strcat(hold2, file1.name1);
    strcat(hold2, file1.name2);
    int n = 0;
    char n2[2];
    n2[1] = '\0';
    int i = 5;
    if (strcmp(hold1, hold2) == 0)
    {
        n =1;
        printf("\e[1;37myour previous games:\n");
        printf("%s\n", firstFile);
        while (i > 0)
        {
            char openFileHolder[20] = {'\0'};
            char mainFileName[20] = {'\0'};
            for (int i = 0; i < 20; i++)
            {
                hold1[i] = '\0';
            }

            strcat(mainFileName, file1.name1);
            strcat(mainFileName, file1.name2);
            n2[0] = '0' + n;
            strcpy(openFileHolder, mainFileName);
            strcat(openFileHolder, n2);
            strcat(openFileHolder, ".txt");
            identities filereader2;
            filereader2.name1[0] = '\0';
            filereader2.name2[0] = '\0';
            FILE *fp2;
            fp2 = fopen(openFileHolder, "r");
            fread(&filereader2, sizeof(filereader2), 1, fp2);
            fclose(fp2);
            strcat(hold1, filereader2.name1);
            strcat(hold1, filereader2.name2);
            if (strcmp(hold1, hold2) == 0)
            {
                printf("%s\n", openFileHolder);
                n++;
            }
            if (strcmp(hold1, hold2) != 0)
            {
                break;
            }
        }
    }
    else
    {
        printf("There is no previous game to show");
    }
    printf("\x1b[0m");
    return n - 1;
}

int prointPreviousGamesNormal(char member1[], char member2[])
{

    identities file1;
    strcpy(file1.name1, member1);
    strcpy(file1.name2, member2);
    FILE *fp;
    // for writing
    fp = fopen("sinamona4.txt", "w");
    fwrite(&file1, sizeof(file1), 1, fp);
    fclose(fp);
    identities filereader;
    char firstFile[20] = {'\0'};
    strcat(firstFile, file1.name1);
    strcat(firstFile, file1.name2);
    strcat(firstFile, "normal");
    strcat(firstFile, ".txt");
    fp = fopen(firstFile, "r");
    fread(&filereader, sizeof(filereader), 1, fp);
    fclose(fp);
    char hold1[20] = {'\0'};
    char hold2[20] = {'\0'};
    strcat(hold1, filereader.name1);
    strcat(hold1, filereader.name2);
    strcat(hold2, file1.name1);
    strcat(hold2, file1.name2);
    int n = 0;
    char n2[2];
    n2[1] = '\0';
    int i = 5;
    if (strcmp(hold1, hold2) == 0)
    {
        n = 1;
        printf("\e[1;37myour previous games:\n");
        printf("%s\n", firstFile);
        while (i > 0)
        {
            char openFileHolder[20] = {'\0'};
            char mainFileName[20] = {'\0'};
            for (int i = 0; i < 20; i++)
            {
                hold1[i] = '\0';
            }

            strcat(mainFileName, file1.name1);
            strcat(mainFileName, file1.name2);
            n2[0] = '0' + n;
            strcpy(openFileHolder, mainFileName);
            strcat(openFileHolder, "normal");
            strcat(openFileHolder, n2);
            strcat(openFileHolder, ".txt");
            identities filereader2;
            filereader2.name1[0] = '\0';
            filereader2.name2[0] = '\0';
            FILE *fp2;
            fp2 = fopen(openFileHolder, "r");
            fread(&filereader2, sizeof(filereader2), 1, fp2);
            fclose(fp2);
            strcat(hold1, filereader2.name1);
            strcat(hold1, filereader2.name2);
            if (strcmp(hold1, hold2) == 0)
            {
                printf("%s\n", openFileHolder);
                n++;
            }
            if (strcmp(hold1, hold2) != 0)
            {
                break;
            }
        }
    }
    else
    {
        printf("There is no previous game to show");
    }
    printf("\x1b[0m");
    return n - 1;
}

#endif // READ_PREVIOUS_FILES_H_INCLUDED

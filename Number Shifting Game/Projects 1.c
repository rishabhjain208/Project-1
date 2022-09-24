#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<windows.h>
void gameRule()
{

    int i,j,n[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    printf("\t\t\tRule of this game\n");
    printf("1.You can move only step at a time by arrow key\n\n");
    printf("Move Up : by Up arrow key\n");
    printf("Move Down : by Down arrow key\n");
    printf("Move Right : by Right arrow key\n\n");
    printf("2.You can move number at empty position only\n\n");
    printf("3.For each valid move : you total number of moves will decrease by 1\n\n");
    printf("\n\n");
    printf("\t\tWinning Situation:\n\n");
    printf("\n1.Number in a 4*4 matrix should be in order from 1 to 15\n\n");
    printf("---------------------\n");

       for (i = 0; i < 4; i++)
    {
        printf("| ");
        for (j = 0; j < 4; j++)
        {
            if (n[i][j] != 0)
                printf("%2d | ", 4 * i + j + 1);
            else
                printf("   |" );
        }
        printf("\n");
    }

    printf("---------------------\n");
    getch();
    system("cls");
}
void createMatrix(int arr[][4])
{
    int n=15;
    int num[n],i,j;
    for(i=0; i<15; i++)
        num[i]=i+1;

    srand(time(NULL));

    int lastindex = n-1,index;

    for(i=0; i<4; i++)

        for(j=0; j<4; j++)
        {
            if (lastindex >= 0)
            {
                index = rand() % (lastindex + 1);
                arr[i][j] = num[index];
                num[index] = num[lastindex--];
            }
        }

    arr[i-1][j-1] = 0;
}
void DisplayMatrix(int arr[][4])
{
    int i,j;
    printf("--------------------\n");
    for(i=0; i<4; i++)
    {
        printf("|");
        for(j=0; j<4; j++)
        {
            if(arr[i][j]!=0)
                printf("%2d | ",arr[i][j]);
            else
                printf("   | ");
        }
        printf("\n");
    }
    printf("-------------------\n");
}
int winner(int arr[][4])
{
    int i,j,k=1;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++,k++)
            if(arr[i][j]!=k&& k!=16)
            break;
        if (j < 4)
            break;
    }
    if (j < 4)
        return 0;
    return 1;
}
void swap(int *a,int *b)
{
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
    printf("");
}
int shiftUp(int arr[][4])
{
    int i,j;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
            if(arr[i][j]==0)
            break;
        if(j<4)
            break;
    }
    if(i==3)
    return 0;

    swap(&arr[i][j],&arr[i+1][j]);
    return 1;
}
int shiftDown(int arr[][4])
{
    int i,j;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
            if(arr[i][j]==0)
            break;
        if(j<4)
            break;
    }
    if(i == 0)
    return 0;

    swap(&arr[i][j],&arr[i-1][j]);
    return 1;
}
int shiftRight(int arr[][4])
{
    int i,j;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
            if(arr[i][j]==0)
            break;
            if(j<4)
            break;
    }
    if(j == 0)
    return 0;

    swap(&arr[i][j],&arr[i][j-1]);
    return 1;
}
int shiftLeft(int arr[][4])
{

    int i,j;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
            if(arr[i][j]==0)
            break;
            if(j<4)
            break;
    }
    if(j == 3)
    return 0;

    swap(&arr[i][j],&arr[i][j+1]);
    return 1;
}
int readKey()
{
    char c;
    c = _getch();
    if (c == -32)
        c = _getch();

    return c;
}
int main()
{
    int arr[4][4];
    int maxTry = 1000;
    char name[20];;
    printf("Player Name: ");
    fgets(name,20,stdin);

    system("cls");

    while (1)
    {
        createMatrix(arr);
        gameRule();

        while (!winner(arr))
        {
            system("cls");
            if (!maxTry)
                break;

            printf("\n\n  Player Name:  %s  Move remaining : %d\n\n", name, maxTry);

            DisplayMatrix(arr);

            int key = readKey();
            switch (key)
            {
            case 101:
            case 69:
                printf("\a\a\a\a\a\a\n     Thanks for Playing ! \n\a");
                printf("\nHit 'Enter' to exit the game \n");
                key = readKey();
                return 0;

            case 72:
                if (shiftUp(arr))
                    maxTry--;
                break;
            case 80:
                if (shiftDown(arr))
                    maxTry--;
                break;
            case 77:
                if (shiftRight(arr))
                    maxTry--;
                break;
            case 75:
                if (shiftLeft(arr))
                    maxTry--;
                break;
            default:

                printf("\n\n      \a\a Not Allowed \a");
            }

        }

        if (!maxTry)
            printf("\n\a          YOU LOSE !          \a\a\n");
        else
            printf("\n\a!!!!!!!!!!!!!Congratulations  %s for winning this game !!!!!!!!!!!!!\n\a", name);

        fflush(stdin);
        char check;
        printf("\nWant to play again ? \n");
        printf("enter 'y' to play again:  ");
        scanf("%c", &check);


        if ((check != 'y') && (check != 'Y'))
            break;

        maxTry = 1000;
    }
    return 0;
}


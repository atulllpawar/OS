#include <stdio.h>
#include <stdlib.h>

int allocation[100][100], max[100][100], need[100][100];
int i, j, pr, rs;
int available[100];

void accept()
{
    printf("\nEnter No. of Processes: ");
    scanf("%d", &pr);

    printf("\nEnter No. of Resources: ");
    scanf("%d", &rs);

    printf("\nEnter Allocation Data:\n");
    for (i = 0; i < pr; i++)
    {
        for (j = 0; j < rs; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("\nEnter Max Data:\n");
    for (i = 0; i < pr; i++)
    {
        for (j = 0; j < rs; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }
}

void accept_available()
{
    printf("\nEnter Available Resources:\n");
    for (j = 0; j < rs; j++)
    {
        printf("%c: ", 65 + j);
        scanf("%d", &available[j]);
    }
}

void display()
{
    printf("\nAllocation Matrix:\n");
    for (i = 0; i < pr; i++)
    {
        for (j = 0; j < rs; j++)
            printf("%d ", allocation[i][j]);
        printf("\n");
    }

    printf("\nMax Matrix:\n");
    for (i = 0; i < pr; i++)
    {
        for (j = 0; j < rs; j++)
            printf("%d ", max[i][j]);
        printf("\n");
    }
}

void display_available()
{
    printf("\nAvailable Resources:\n");
    for (j = 0; j < rs; j++)
        printf("%c = %d\n", 65 + j, available[j]);
}

void calc_need()
{
    printf("\nNeed Matrix:\n");

    for (i = 0; i < pr; i++)
    {
        for (j = 0; j < rs; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    char ch;

    accept();

    while (1)
    {
        printf("\n\na. Accept Available");
        printf("\nb. Display Allocation, Max");
        printf("\nc. Display the contents of Need Matrix");
        printf("\nd. Display Available");
        printf("\nq. Exit");

        printf("\nEnter Choice: ");
        scanf(" %c", &ch);

        switch (ch)
        {
            case 'a':
                accept_available();
                break;

            case 'b':
                display();
                break;

            case 'c':
                calc_need();
                break;

            case 'd':
                display_available();
                break;

            case 'q':
                exit(0);

            default:
                printf("\nInvalid Choice");
        }
    }

    return 0;
}
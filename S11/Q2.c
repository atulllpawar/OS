#include <stdio.h>

int main()
{
    int n, f, i, j, k;
    int pages[100], frames[20];
    int pageFaults = 0, found, pos, farthest;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
    {
        frames[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        found = 0;

        for (j = 0; j < f; j++)
        {
            if (frames[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if (found == 0)
        {
            pageFaults++;

            pos = -1;
            farthest = -1;

            for (j = 0; j < f; j++)
            {
                if (frames[j] == -1)
                {
                    pos = j;
                    break;
                }

                for (k = i + 1; k < n; k++)
                {
                    if (frames[j] == pages[k])
                        break;
                }

                if (k > farthest)
                {
                    farthest = k;
                    pos = j;
                }
            }

            frames[pos] = pages[i];
        }

        printf("\nPage %d: ", pages[i]);

        for (j = 0; j < f; j++)
        {
            if (frames[j] == -1)
                printf("- ");
            else
                printf("%d ", frames[j]);
        }

        if (found == 0)
            printf("Page Fault");
        else
            printf("Page Hit");
    }

    printf("\n\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}
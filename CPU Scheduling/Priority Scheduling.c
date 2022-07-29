#include <stdio.h>
int main()
{
    int n, i, j, temp=0, temp1=0, temp2=0;
    int c[10], priority[10], process[10], w[10], t[10];
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nEnter the CPU Time of P%d: ", i+1);
        scanf("%d", &c[i]);

        process[i] = i+1;

        printf("Enter the Priority Value of P%d: ", i+1);
        scanf("%d", &priority[i]);
    }

    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(priority[j] < priority[i])
            {
                temp = priority[j];
                priority[j] = priority[i];
                priority[i] = temp;

                temp1 = c[j];
                c[j] = c[i];
                c[i] = temp1;

                temp2 = process[j];
                process[j] = process[i];
                process[i] = temp2;
            }
        }
    }

    w[0] = 0;
    for(i = 1; i < n; i++)
    {
        w[i] = w[i-1] + c[i-1];
    }

    for(i = 0; i < n; i++)
    {
        t[i] = w[i] + c[i];
    }

    printf("\n\nProcess\t   CPU Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d\t   %d\t\t%d\t\t%d\t\t%d\n", process[i], c[i], priority[i], w[i], t[i]);
    }

    printf("\n\nGrand Chart:\n\n|");
    for(i = 0; i < n; i++)
    {
        printf(" P%d\t |", i+1);
    }

    printf("\n0");
    for(i = 0; i < n; i++)
    {
        printf("\t  %d", t[i]);
    }
}



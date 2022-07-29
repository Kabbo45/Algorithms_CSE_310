#include <stdio.h>
int main()
{
    int i, j, n, cpu_time[10], waitting_time[10], arrival_time[10],
        turnaround_time[10], temp[10];
    int process[10], work_process[100], work_process_time[100],
        response_time[10] = {0};
    float avg_w=0,avg_t=0,avg_r=0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("\nEnter CPU time of P%d: ", i+1);
        scanf("%d", &cpu_time[i]);
        temp[i] = cpu_time[i];
        printf("Enter arrival time of P%d: ", i+1);
        scanf("%d", &arrival_time[i]);
        process[i] = i+1;
    }
    int counter=0, timer=0,smallest=9,complete=0;
    temp[smallest] = 10000;
    for(counter = 0, timer=0; counter !=n; timer++)
    {
        smallest = 9;
        for(i=0; i<n; i++)
        {
            if(arrival_time[i] <= timer && temp[i] < temp[smallest] &&
                    temp[i]>0)
            {
                smallest = i;
            }
        }
        temp[smallest]--;
        work_process[timer] = smallest+1;
        work_process_time[timer] = timer+1;
        if(response_time[smallest] == 0)
        {
            response_time[smallest] = timer+1;
        }
        if(temp[smallest] == 0)
        {
            counter++;
            complete = timer+1;
            turnaround_time[smallest] = complete -
                                        arrival_time[smallest];
            waitting_time[smallest] = turnaround_time[smallest] -
                                      cpu_time[smallest];
        }
    }
    printf("Process\t Arrival Time\tCPU Time\tWaiting Time\tTurnaround
           Time\t Response Time\n");
           for(i=0; i<n; i++)
{
    printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t%d\n", i+1,
           arrival_time[i], cpu_time[i], waitting_time[i], turnaround_time[i],
           response_time[i]);
        avg_r += response_time[i];
        avg_w += waitting_time[i];
        avg_t += turnaround_time[i];
    }
    avg_w /= n;
             avg_t /= n;
             avg_r /= n;
             printf("Average Waiting Time: %.2f\n", avg_w);
             printf("Average Turnaround Time: %.2f\n", avg_t);
             printf("Average Response Time: %.2f\n", avg_r);
             printf("\n\nGrand Chart\n\n");
             for(i=0; i<timer; i++)
{
    printf("| P%d |", work_process[i]);
    }
    printf("\n0");
    for(i=0; i<timer; i++)
{
    printf("\t%d", work_process_time[i]);
    }
}


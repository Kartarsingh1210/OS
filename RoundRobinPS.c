#include <stdio.h>

struct P
{
    int pos, AT, BT, RT, WT, TAT, FT;
};

int main()
{
    int n, i, j, tq;

    printf("Enter No. of Processes: ");
    scanf("%d", &n);

    printf("Enter TIme Quantum :");
    scanf("%d", &tq);

    struct P p[n];

    printf("Enter Process No. :");
    for (i = 0; i < n; i++)
    {
     scanf("%d", &p[i].pos);
    }
    printf("Enter AT :");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i].AT);
    }

    printf("Enter BT :");
    for (i = 0; i < n; i++)
    {
    scanf("%d", &p[i].BT);
    p[i].RT = p[i].BT;
    }

    struct P temp;
    int time = 0;
    int rem_process = n;
    int tot_wt = 0, tot_tat = 0;
    int flag = 0;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (p[j].AT > p[j + 1].AT)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    printf("\nProcess No.\tAT\tBT\tFT\tTAT\tWT\n");
    while (rem_process != 0)
    {
        if (p[i].RT <= tq && p[i].RT > 0)
        {
            time += p[i].RT;
            p[i].RT = 0;
            flag = 1;
        }
        else if (p[i].RT > 0)
        {
            p[i].RT -= tq;
            time += tq;
        }

        if (p[i].RT == 0 && flag == 1)
        {
            flag = 0;
            rem_process--;
            p[i].FT = time;
            p[i].TAT = p[i].FT - p[i].AT;
            p[i].WT = p[i].TAT - p[i].BT;

            tot_tat += p[i].TAT;
            tot_wt += p[i].WT;

            printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pos, p[i].AT, p[i].BT, p[i].FT, p[i].TAT, p[i].WT);
        }

        if (i != n - 1 && p[i + 1].AT <= time)
            i++;
        else
            i = 0;
    }
    double avg_wt = tot_wt / (float)n;
    double avg_tat = tot_tat / (float)n;
    printf("\n");
    printf("Avg Waiting time : %lf\n", avg_wt);
    printf("Avg TurnAround time  : %lf\n", avg_tat);
}
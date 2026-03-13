/*#include <stdio.h>

void nonPreemptiveSJF(int n, int bt[], int p[])
{
    int wt[20], tat[20], i, j, temp;
    float avg_wt=0, avg_tat=0;

    // Sort burst time with process numbers
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(bt[i] > bt[j])
            {
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;

                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }

    wt[0]=0;

    for(i=1;i<n;i++)
        wt[i]=wt[i-1]+bt[i-1];

    for(i=0;i<n;i++)
        tat[i]=wt[i]+bt[i];

    printf("\nProcess\tBT\tWT\tTAT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\n",p[i],bt[i],wt[i],tat[i]);
        avg_wt+=wt[i];
        avg_tat+=tat[i];
    }

    printf("Average WT = %.2f\n",avg_wt/n);
    printf("Average TAT = %.2f\n",avg_tat/n);
}

void preemptiveSJF(int n, int bt[])
{
    int rt[20], wt[20], tat[20];
    int time=0, completed=0, shortest=-1;
    int min, finish_time;
    float avg_wt=0, avg_tat=0;

    for(int i=0;i<n;i++)
        rt[i]=bt[i];

    while(completed != n)
    {
        min=9999;
        shortest=-1;

        for(int i=0;i<n;i++)
        {
            if(rt[i]>0 && rt[i]<min)
            {
                min=rt[i];
                shortest=i;
            }
        }

        rt[shortest]--;
        time++;

        if(rt[shortest]==0)
        {
            completed++;
            finish_time=time;

            wt[shortest]=finish_time-bt[shortest];
            tat[shortest]=finish_time;
        }
    }

    printf("\nProcess\tBT\tWT\tTAT\n");

    for(int i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\n",i+1,bt[i],wt[i],tat[i]);
        avg_wt+=wt[i];
        avg_tat+=tat[i];
    }

    printf("Average WT = %.2f\n",avg_wt/n);
    printf("Average TAT = %.2f\n",avg_tat/n);
}

int main()
{
    int n, bt[20], p[20], choice;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter burst times:\n");
    for(int i=0;i<n;i++)
    {
        printf("P%d: ",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;
    }

    printf("\n1. Non Preemptive SJF\n");
    printf("2. Preemptive SJF\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            nonPreemptiveSJF(n,bt,p);
            break;

        case 2:
            preemptiveSJF(n,bt);
            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}*/

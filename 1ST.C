#include <stdio.h>

int main() {
    int n, i, j;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int AT[n], BT[n], CT[n], TAT[n], WT[n], pid[n];
    float avgWT = 0, avgTAT = 0;
    int current_time = 0;

    // Input Arrival Time and Burst Time
    for(i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("\nProcess %d\n", pid[i]);
        printf("Arrival Time: ");
        scanf("%d", &AT[i]);
        printf("Burst Time: ");
        scanf("%d", &BT[i]);
    }

    // Sort processes by Arrival Time
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(AT[i] > AT[j]) {
                int temp;

                temp = AT[i];
                AT[i] = AT[j];
                AT[j] = temp;

                temp = BT[i];
                BT[i] = BT[j];
                BT[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    // Calculate CT, TAT, WT
    for(i = 0; i < n; i++) {

        if(current_time < AT[i]) {
            current_time = AT[i];
        }

        CT[i] = current_time + BT[i];
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];

        current_time = CT[i];

        avgWT += WT[i];
        avgTAT += TAT[i];
    }

    avgWT /= n;
    avgTAT /= n;

    // Display results
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], AT[i], BT[i], CT[i], TAT[i], WT[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avgWT);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT);

    return 0;
}
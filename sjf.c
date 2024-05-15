/*Write a C program to compute and print the average waiting time, 
average turnaround time and CPU burst times for the given list of 
processes. Display/print the Gantt chart for first come first serve, shortest 
job first, priority scheduling and round robin scheduling algorithm. 
*/

#include <stdio.h>

int main() {
    int n;
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    int process_id[n], arrival_time[n], burst_time[n], compilation_time[n], turn_around_time[n], waiting_time[n], response_time[n];
    
    for(int i = 0; i < n; i++) {
        printf("\nEnter the arrival time of Process %d: ", i + 1);
        scanf("%d", &arrival_time[i]);
        process_id[i] = i;
        printf("\nEnter the burst time of Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }
    
    
    // Sort processes by burst time (SJF)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (burst_time[j] > burst_time[j + 1]) {
                int temp = burst_time[j];
                burst_time[j] = burst_time[j + 1];
                burst_time[j + 1] = temp;

                temp = arrival_time[j];
                arrival_time[j] = arrival_time[j + 1];
                arrival_time[j + 1] = temp;

                temp = process_id[j];
                process_id[j] = process_id[j + 1];
                process_id[j + 1] = temp;
            }
        }
    }
    
    int current_time = 0;
    float total_idle_time = 0.0;
    float total_turnaround_time = 0.0;
    float total_waiting_time = 0.0;
    float total_response_time = 0.0;

    printf("\nPTD\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    
    // Print process details and calculate times
    for(int i = 0; i < n; i++) {
        // Check for idle time
        if(current_time < arrival_time[i]) {
            // printf("IDLE\t%d\t-\t%d\t-\t-\n", current_time, arrival_time[i]);
            total_idle_time += arrival_time[i] - current_time;
            current_time = arrival_time[i];
        }
        
        // Calculate response time
        response_time[i] = current_time - arrival_time[i];
        
        // Calculate compilation time
        compilation_time[i] = current_time + burst_time[i];
        
        // Calculate turnaround time
        turn_around_time[i] = compilation_time[i] - arrival_time[i];
        
        // Calculate waiting time
        waiting_time[i] = turn_around_time[i] - burst_time[i];
        
        // Output process details
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", process_id[i]+1, arrival_time[i], burst_time[i], compilation_time[i], turn_around_time[i], waiting_time[i], response_time[i]);
        
        // Update total times
        total_turnaround_time += turn_around_time[i];
        total_waiting_time += waiting_time[i];
        total_response_time += response_time[i];

        // Update current time
        current_time = compilation_time[i];
    }
    
    // Calculate averages
    float avg_turnaround_time = total_turnaround_time / n;
    float avg_waiting_time = total_waiting_time / n;
    float avg_response_time = total_response_time / n;

    // Print averages and total idle time
    printf("\nAverage Turnaround Time: %f\n", avg_turnaround_time);
    printf("Average Waiting Time: %f\n", avg_waiting_time);
    printf("Average Response Time: %f\n", avg_response_time);
    printf("Total Idle Time: %f\n", total_idle_time);

    // Print Gantt chart
    printf("\nGantt Chart:\n");
    printf(" ");
    for (int i = 0; i < n; i++) {
        printf("|  P%d\t", process_id[i]+1);
    }
    printf("|\n");

    printf("%d", arrival_time[0]);
    for (int i = 0; i < n; i++) {
        printf("\t%d", compilation_time[i]);
    }
    printf("\n\n");

    return 0;
}

/*Enter the number of processes: 4

Enter the arrival time of Process 1: 1

Enter the burst time of Process 1: 3

Enter the arrival time of Process 2: 2

Enter the burst time of Process 2: 4

Enter the arrival time of Process 3: 1

Enter the burst time of Process 3: 2

Enter the arrival time of Process 4: 4

Enter the burst time of Process 4: 4

PTD     AT      BT      CT      TAT     WT      RT
P2      1       2       3       2       0       0
P0      1       3       6       5       2       2
P1      2       4       10      8       4       4
P3      4       4       14      10      6       6

Average Turnaround Time: 6.250000
Average Waiting Time: 3.000000
Average Response Time: 3.000000
Total Idle Time: 1.000000

Gantt Chart:
 |  P2  |  P0   |  P1   |  P3   |
1       3       6       10      14
*/
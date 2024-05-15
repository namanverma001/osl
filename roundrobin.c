#include <stdio.h>

int main() {
    int n, time_quantum;
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    int process_id[n], arrival_time[n], burst_time[n], remaining_burst_time[n], completion_time[n], turn_around_time[n], waiting_time[n], response_time[n];
    
    // Input process details
    for(int i = 0; i < n; i++) {
        printf("\nEnter the arrival time of Process %d: ", i + 1);
        scanf("%d", &arrival_time[i]);
        printf("Enter the burst time of Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        remaining_burst_time[i] = burst_time[i];
        process_id[i] = i;
    }
    
    int current_time = 0;
    float total_turnaround_time = 0.0;
    float total_waiting_time = 0.0;
    float total_response_time = 0.0;

    printf("\nPTD\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    
    // Process execution using Round Robin
    while(1) {
        int all_processes_complete = 1;
        for(int i = 0; i < n; i++) {
            if(remaining_burst_time[i] > 0) {
                all_processes_complete = 0;
                if(remaining_burst_time[i] > time_quantum) {
                    // Process executes for time quantum
                    current_time += time_quantum;
                    remaining_burst_time[i] -= time_quantum;
                } else {
                    // Process finishes execution
                    current_time += remaining_burst_time[i];
                    remaining_burst_time[i] = 0;
                    // Calculate completion time
                    completion_time[i] = current_time;
                    // Calculate response time
                    response_time[i] = current_time - arrival_time[i] - burst_time[i] + time_quantum;
                    // Calculate turnaround time
                    turn_around_time[i] = completion_time[i] - arrival_time[i];
                    // Calculate waiting time
                    waiting_time[i] = turn_around_time[i] - burst_time[i];
                    // Update total times
                    total_turnaround_time += turn_around_time[i];
                    total_waiting_time += waiting_time[i];
                    total_response_time += response_time[i];
                }
            }
        }
        if(all_processes_complete) {
            break;
        }
    }

    // Print process details
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", process_id[i], arrival_time[i], burst_time[i], completion_time[i], turn_around_time[i], waiting_time[i], response_time[i]);
    }

    // Calculate averages
    float avg_turnaround_time = total_turnaround_time / n;
    float avg_waiting_time = total_waiting_time / n;
    float avg_response_time = total_response_time / n;

    // Print averages
    printf("\nAverage Turnaround Time: %f\n", avg_turnaround_time);
    printf("Average Waiting Time: %f\n", avg_waiting_time);
    printf("Average Response Time: %f\n", avg_response_time);

    return 0;
}

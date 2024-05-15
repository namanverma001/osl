#include <stdio.h>

int main() {
    int n;
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    int process_id[n], arrival_time[n], burst_time[n], priority[n], compilation_time[n], turn_around_time[n], waiting_time[n], response_time[n];
    
    // Input process details
    for(int i = 0; i < n; i++) {
        printf("\nEnter the arrival time of Process %d: ", i + 1);
        scanf("%d", &arrival_time[i]);
        printf("Enter the burst time of Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        printf("Enter the priority of Process %d: ", i + 1);
        scanf("%d", &priority[i]);
        process_id[i] = i;
    }
    
    int current_time = 0;
    float total_idle_time = 0.0;
    float total_turnaround_time = 0.0;
    float total_waiting_time = 0.0;
    float total_response_time = 0.0;

    printf("\nPTD\tAT\tBT\tPri\tCT\tTAT\tWT\tRT\n");
    
    // Print process details and calculate times
    for(int i = 0; i < n; i++) {
        // Check for idle time
        if(current_time < arrival_time[i]) {
           // printf("IDLE\t%d\t-\t-\t%d\t-\t-\t-\n", current_time, arrival_time[i]);
            total_idle_time += arrival_time[i] - current_time;
            current_time = arrival_time[i];
        }
        
        // Find process with highest priority that has arrived
        int highest_priority_process = -1;
        int highest_priority = 9999; // Assume maximum priority is 9999
        for(int j = 0; j < n; j++) {
            if(arrival_time[j] <= current_time && priority[j] < highest_priority) {
                highest_priority = priority[j];
                highest_priority_process = j;
            }
        }
        
        // Calculate response time
        response_time[highest_priority_process] = current_time - arrival_time[highest_priority_process];
        
        // Calculate compilation time
        compilation_time[highest_priority_process] = current_time + burst_time[highest_priority_process];
        
        // Calculate turnaround time
        turn_around_time[highest_priority_process] = compilation_time[highest_priority_process] - arrival_time[highest_priority_process];
        
        // Calculate waiting time
        waiting_time[highest_priority_process] = turn_around_time[highest_priority_process] - burst_time[highest_priority_process];
        
        // Output process details
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", process_id[highest_priority_process], arrival_time[highest_priority_process], burst_time[highest_priority_process], priority[highest_priority_process], compilation_time[highest_priority_process], turn_around_time[highest_priority_process], waiting_time[highest_priority_process], response_time[highest_priority_process]);
        
        // Update total times
        total_turnaround_time += turn_around_time[highest_priority_process];
        total_waiting_time += waiting_time[highest_priority_process];
        total_response_time += response_time[highest_priority_process];

        // Update current time
        current_time = compilation_time[highest_priority_process];
        
        // Mark the processed process to avoid re-processing
        priority[highest_priority_process] = 9999; // Set highest priority to a large value to exclude it from consideration in the next iteration
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
        printf("|  P%d\t", process_id[i]);
    }
    printf("|\n");

    printf("%d", arrival_time[0]);
    for (int i = 0; i < n; i++) {
        printf("\t%d", compilation_time[i]);
    }
    printf("\n\n");

    return 0;
}
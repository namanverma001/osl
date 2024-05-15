#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 3

// Function prototypes
void FIFO(int pages[], int n);
void OPR(int pages[], int n, int fn);
void LRU(int pages[], int n);

int main() {
    int n, ch;

    printf("Enter the number of page references: ");
    scanf("%d", &n);

    int pages[n]; // Page reference string

    printf("Enter the page reference string:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    do {
        printf("\nSelect the task that you have to perform: ");
        printf("\n1. FIFO\n2. OPR\n3. LRU\n4. Exit\n"); // Added option for LRU and Exit
        scanf("%d", &ch); // Added input for menu selection

        switch (ch) {
            case 1:
                FIFO(pages, n);
                break;
            case 2:
                OPR(pages, n, MAX_FRAMES); // Call OPR function with page reference string and number of frames
                break;
            case 3:
                LRU(pages, n); // Call LRU function with page reference string
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (ch != 4);

    return 0;
}

// FIFO function remains the same

void FIFO(int pages[], int n) {
    int frames[MAX_FRAMES];
    int frameCount = 0;
    int pageFaults = 0;
    int nextFrameIndex = 0;

    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        int currentPage = pages[i];
        int pageFound = 0;

        // Check if the current page is already in one of the frames
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == currentPage) {
                pageFound = 1;
                break;
            }
        }

        // If page not found in frames, it's a page fault
        if (!pageFound) {
            pageFaults++;

            // Replace the oldest page in the frames with the current page
            frames[nextFrameIndex] = currentPage;
            nextFrameIndex = (nextFrameIndex + 1) % MAX_FRAMES; // Move to the next frame circularly

            // Increment the frame count if it's less than MAX_FRAMES
            if (frameCount < MAX_FRAMES) {
                frameCount++;
            }
        }

        // Display the current frames
        printf("Page reference: %d, Frames: ", currentPage);
        for (int j = 0; j < frameCount; j++) {
            printf("%d ", frames[j]);
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
}

// OPR function implementation remains the same

// OPR function implementation remains the same

void OPR(int pages[], int n, int fn) {
    int frames[MAX_FRAMES];
    int frameCount = 0;
    int pageFaults = 0;

    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1; 
    }

    for (int i = 0; i < n; i++) {
        int currentPage = pages[i];
        int pageFound = 0;

        for (int j = 0; j < frameCount; j++) {
            if (frames[j] == currentPage) {
                pageFound = 1;
                break;
            }
        }

        if (!pageFound) {
            pageFaults++;

            if (frameCount < fn) {
                frames[frameCount++] = currentPage;
            } else {
                int j = 0;
                int farthest = -1;

                for (int k = 0; k < frameCount; k++) {
                    int l;
                    for ( l = i + 1; l < n; l++) {
                        if (frames[k] == pages[l]) {
                            if (l > farthest) {
                                farthest = l;
                                j = k;
                            }
                            break;
                        }
                    }
                    if (l == n) {
                        j = k;
                        break;
                    }
                }

                frames[j] = currentPage;
            }
        }

        printf("Page reference: %d, Frames: ", currentPage);
        for (int j = 0; j < frameCount; j++) {
            printf("%d ", frames[j]);
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
}


// LRU function implementation
void LRU(int pages[], int n) {
    int frames[MAX_FRAMES];
    int pageFaults = 0;
    int time[MAX_FRAMES];
    int currentTime = 0;

    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
        time[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int currentPage = pages[i];
        int pageFound = 0;

        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == currentPage) {
                pageFound = 1;
                time[j] = currentTime++;
                break;
            }
        }

        if (!pageFound) {
            pageFaults++;

            int minTimeIndex = 0;
            for (int j = 1; j < MAX_FRAMES; j++) {
                if (time[j] < time[minTimeIndex]) {
                    minTimeIndex = j;
                }
            }

            frames[minTimeIndex] = currentPage;
            time[minTimeIndex] = currentTime++;
        }

        // Display the current frames
        printf("Page reference: %d, Frames: ", currentPage);
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] != -1) {
                printf("%d ", frames[j]);
            }
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
}

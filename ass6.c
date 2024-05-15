#include<stdio.h>  
void Firstinfirstout()
{
    int pageFaults = 0;  
    int frames = 3;  
    int m, n, s, pages;   
  
    printf("Enter the number of pages in the incoming stream: ");
    scanf("%d", &pages);
    
    int incomingStream[pages];
    
    printf("Enter the page numbers:\n");
    for (m = 0; m < pages; m++) {
        scanf("%d", &incomingStream[m]);
    }

    printf("Incoming\tFrame 1\tFrame 2\tFrame 3\n");  

    int temp[frames];  
    for(m = 0; m < frames; m++) {  
        temp[m] = -1;  
    }  

    for(m = 0; m < pages; m++) {  
        s = 0;   
        for(n = 0; n < frames; n++) {  
            if(incomingStream[m] == temp[n]) {  
                s++;  
                pageFaults--;  
            }  
        }  
        pageFaults++;  
        if((pageFaults <= frames) && (s == 0)) {  
            temp[m] = incomingStream[m];  
        }  
        else if(s == 0) {  
            temp[(pageFaults - 1) % frames] = incomingStream[m];  
        }  

        printf("\n%d\t\t",incomingStream[m]);  
        for(n = 0; n < frames; n++) {  
            if(temp[n] != -1)  
                printf("%d\t\t", temp[n]);  
            else  
                printf("-\t\t");  
        }  
    }  
    printf("\nTotal Page Faults:\t%d\n", pageFaults);  

}




void optimalpagefault()
{
    int no_of_frames, no_of_pages, frames[10], pages[30], temp[10], flag1, flag2, flag3, i, j, k, pos, max, faults = 0;
    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);
    
    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);
    
    printf("Enter page reference string: ");
    
    for(i = 0; i < no_of_pages; ++i){
        scanf("%d", &pages[i]);
    }
    
    for(i = 0; i < no_of_frames; ++i){
        frames[i] = -1;
    }
    
    for(i = 0; i < no_of_pages; ++i){
        flag1 = flag2 = 0;
        
        for(j = 0; j < no_of_frames; ++j){
            if(frames[j] == pages[i]){
                   flag1 = flag2 = 1;
                   break;
               }
        }
        
        if(flag1 == 0){
            for(j = 0; j < no_of_frames; ++j){
                if(frames[j] == -1){
                    faults++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }    
        }
        
        if(flag2 == 0){
         flag3 =0;
        
            for(j = 0; j < no_of_frames; ++j){
             temp[j] = -1;
            
             for(k = i + 1; k < no_of_pages; ++k){
             if(frames[j] == pages[k]){
             temp[j] = k;
             break;
             }
             }
            }
            
            for(j = 0; j < no_of_frames; ++j){
             if(temp[j] == -1){
             pos = j;
             flag3 = 1;
             break;
             }
            }
            
            if(flag3 ==0){
             max = temp[0];
             pos = 0;
            
             for(j = 1; j < no_of_frames; ++j){
             if(temp[j] > max){
             max = temp[j];
             pos = j;
             }
             }            
            }
frames[pos] = pages[i];
faults++;
        }
        
        printf("\n");
        
        for(j = 0; j < no_of_frames; ++j){
            printf("%d\t", frames[j]);
        }
    }
    
    printf("\n\nTotal Page Faults = %d", faults);
}



int findLRU(int time[], int n){
int i, minimum = time[0], pos = 0;
 
for(i = 1; i < n; ++i){
if(time[i] < minimum){
minimum = time[i];
pos = i;
}
}
return pos;
}

void LeastRecentlyused()
{
int no_of_frames, no_of_pages, frames[10], pages[30], counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0;
printf("Enter number of frames: ");
scanf("%d", &no_of_frames);
printf("Enter number of pages: ");
scanf("%d", &no_of_pages);
printf("Enter reference string: ");
    for(i = 0; i < no_of_pages; ++i){
     scanf("%d", &pages[i]);
    }
    
for(i = 0; i < no_of_frames; ++i){
     frames[i] = -1;
    }
    
    for(i = 0; i < no_of_pages; ++i){
     flag1 = flag2 = 0;
    
     for(j = 0; j < no_of_frames; ++j){
     if(frames[j] == pages[i]){
     counter++;
     time[j] = counter;
   flag1 = flag2 = 1;
   break;
   }
     }
    
     if(flag1 == 0){
for(j = 0; j < no_of_frames; ++j){
     if(frames[j] == -1){
     counter++;
     faults++;
     frames[j] = pages[i];
     time[j] = counter;
     flag2 = 1;
     break;
     }
     }
     }
    
     if(flag2 == 0){
     pos = findLRU(time, no_of_frames);
     counter++;
     faults++;
     frames[pos] = pages[i];
     time[pos] = counter;
     }
    
     printf("\n");
    
     for(j = 0; j < no_of_frames; ++j){
     printf("%d\t", frames[j]);
     }
}
printf("\n\nTotal Page Faults = %d", faults);
}
int main()  
{  
    int num;
    printf("1.First in First Out\n2.Optimal Page Replacement \n3.least recently\n");
    printf("Enter Your Choice:");
    scanf("%d",&num);
    switch(num)
    {
        case 1:
        Firstinfirstout();
        break;

        case 2:
        optimalpagefault();
        break;
        case 3:
        LeastRecentlyused();
        break;
    
    }
    return 0;  
}  

#include<stdio.h>
int main(){
    int n,r;
    printf("\nEnter the number of process: ");
    scanf("%d",&n);
    printf("\nEnter the number of resource: ");
    scanf("%d",&r);
    
    int allocation_matrix[n][r];
    printf("\nEnter the allocation matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<r;j++){
            scanf("%d",&allocation_matrix[i][j]);
        }
    }
    
    int maximum_matrix[n][r];
    printf("\nEnter the maximum matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<r;j++){
            scanf("%d",&maximum_matrix[i][j]);
        }
    }
    
    int available[r];
    printf("\nEnter the available resource: ");
    for(int i=0;i<r;i++){
        scanf("%d",&available[i]);
    }
    
    int f[n],ans[n],ind=0;
    for(int k=0;k<n;k++){
        f[k]=0;    //mark all processes as not visited
    }
    
    int need[n][r];
    for(int i=0;i<n;i++){
        for(int j=0;j<r;j++){
            need[i][j]=maximum_matrix[i][j]-allocation_matrix[i][j];
        }
    }
    
    int y=0;
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            if(f[i]==0){   
                int flag=0;
                for(int j=0;j<r;j++){
                    if(need[i][j] > available[j]){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    ans[ind++]=i;
                    int av[y];
                    for(int y=0;y<r;y++){
                        av[y]=available[y];
                        available[y]=available[y]+allocation_matrix[i][y];
                        f[i]=1;
                    }
                }
            }
        }
    }
    
	printf("\nProcess\t\tAllocation\t\tMaximum\t\tNeed\n");
	for(int i=0;i<n;i++){
		printf("P%d",i);
		for(int j=0;j<r;j++){
			printf("\t%d",allocation_matrix[i][j]);
		}
		printf("|");
		for(int j=0;j<r;j++){
			printf("\t%d",maximum_matrix[i][j]);
		}
		printf("|");
		for(int j=0;j<r;j++){
			printf("\t%d",need[i][j]);
		}
		printf("\n");
	}

    
	
	 printf("\nThe SAFE sequence is as follows: \n");
        for(int i=0;i<n;i++){
            printf("P%d->",ans[i]+1);
        }
    return 0;
}

/*Enter the number of process: 5

Enter the number of resource: 3

Enter the allocation matrix:
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2

Enter the maximum matrix:
7 5 3
3 2 2
9 0 2
4 2 2
5 3 3

Enter the available resource: 3 3 2

Process         Allocation              Maximum         Available               Need
P0      0       1       0|      7       5       3|      7       4       3
P1      2       0       0|      3       2       2|      1       2       2
P2      3       0       2|      9       0       2|      6       0       0
P3      2       1       1|      4       2       2|      2       1       1
P4      0       0       2|      5       3       3|      5       3       1

The SAFE sequence is as follows:
P2->P4->P5->P1->P3->
*/
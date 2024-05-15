/*Write a C program to implement producer-consumer problem*/

#include <stdio.h>
#include <stdlib.h>


int mutex = 1;
int full = 0;
int empty = 10, x = 0;
void producer()
{
    --mutex;
    ++full;
    --empty;
    x++;
    printf("Producer produces item %d",x);
    ++mutex;
}
void consumer()
{
    --mutex;
    --full;
    ++empty;
    printf("\nConsumer consumes item %d",x);
    x--;
    ++mutex;
}

int main()
{
    int n, i,number;
    printf("\n1.For Producer""\n2.For Consumer""\n3.Exit");



    for (i = 1; i > 0; i++) {

        printf("\nEnter your choice:");
        scanf("%d", &n);


        switch (n) {
        case 1:

            if ((mutex == 1) && (empty != 0)) {
                producer();
            }

            else {
                printf("The Buffer is full!");
            }
            break;

        case 2:
	printf("Enter the no of process you want to consume:");
	scanf("%d",&number);
	if(number > full)
	{
		printf("can't Process your consumption number exceeds from %d ",full);
	}	
else
{
            if ((mutex == 1) && (full != 0)) {
                consumer();
            }

            else {
                printf("Buffer is empty!");
            }
}


            break;

        case 3:
            exit(0);
            break;
        }
    }
}
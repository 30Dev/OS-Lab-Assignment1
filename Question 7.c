#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 

static int s = 0;
  
void *printMessage(void)
{
	printf("The sum of the two numbers: ");
}

void *printSum(void *data)
{
	int a = *((int*)data);
	
	s = s + a;
}

int main() 
{  
    pthread_t thread1;
    pthread_t thread2;
    
    int a[2];
    int i;
    
    printf("Enter the numbers for addition: ");
    for(i=0; i<2; i++)
    {
    	scanf("%d", &a[i]);
	}
  
    pthread_create(&thread1, NULL, printMessage, NULL);
    for(i=0; i<2; i++)
    {
		pthread_create(&thread2, NULL, printSum, &a[i]); 
	}
	
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    printf("%d", s);
    return 0; 
}

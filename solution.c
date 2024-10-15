#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <inttypes.h>


#ifdef _SC_NPROCESSORS_ONLN
#define NUM_THREADS sysconf(_SC_NPROCESSORS_ONLN)
#else
#define NUM_THREADS 1
#endif

//time taskset -c 3 

typedef struct {
    int lower;
    int upper;
    int number;
    long result;
    long resultCount;
} worker_range;


int randomPivot=0;
int numOfRandomNumbers=0;




/*
int isPrime(int n)
{

    if(n<=1){
   	 return 0;}
    if (n<=3){
   	 return 1;}
    
    if(n%2 ==0 || n%3==0)
   	 return 0;
    
    for(int i=5; i*i<=n; i=i+6)
   	 if(n%i ==0 || n%(i+2)==0){
  	  return 0;}
   
    return 1;
}
*/

int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}


void* work(void* param) {
    worker_range* range = (worker_range*)param;
    int number;
    while (scanf("%d", &number) == 1) {
        if (isPrime(number)) {
        //printf("%d",number);
            range->resultCount++;
        }
    }
    return NULL;
}
	       	
			
		









int main(){

   

  int core = NUM_THREADS;
    
    srand(randomPivot);

    pthread_t thread[NUM_THREADS];
    worker_range ranges[NUM_THREADS];
  
    int start = 0;
     
     for (int i = 0; i < core; i++) {
        ranges[i].lower = start;
        ranges[i].upper = start+1;
        ranges[i].resultCount = 0;
        pthread_create(&thread[i], NULL, work, &ranges[i]);
        start = ranges[i].upper + 1;
    }

    for (int i = 0; i < core; i++) {
        pthread_join(thread[i], NULL);
    }

    long totalPrimes = 0;
    for (int i = 0; i < core; i++) {
        totalPrimes += ranges[i].resultCount;
    }
    printf("%ld total primes.\n", totalPrimes);



  return 0;
}







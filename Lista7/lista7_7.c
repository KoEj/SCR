/******************************************************************************
* FILE: hello_arg2.c
* DESCRIPTION:
*   A "hello world" Pthreads program which demonstrates another safe way
*   to pass arguments to threads during thread creation.  In this case,
*   a structure is used to pass multiple arguments.
* AUTHOR: Blaise Barney
* LAST REVISED: 01/29/09
******************************************************************************/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#define NUM_THREADS    5
#define LOOP           10000

struct thread_data
{
   int  thread_id; 
   int  wheel;     //  czy punkt w kole
};

struct thread_data thread_data_array[NUM_THREADS];

int wheel_MC() {
    double X, Y;
    X=2*drand48();
    Y=2*drand48();
    if(sqrt(((X-1)*(X-1))+((Y-1)*(Y-1)))<=1) return 1;
    else return 0;
}

void *PrintHello(void *threadarg) {
    int taskid;
    struct thread_data *my_data;

    my_data = (struct thread_data *) threadarg;
    taskid = my_data->thread_id;
    
    for (int i=0;i<LOOP;i++)
        thread_data_array[taskid].wheel+=wheel_MC();
    
    
    printf("Thread %d    | Pi value: %f\n",taskid,(float)thread_data_array[taskid].wheel*4/LOOP);
    
    sleep(1);
    
    //printf("Thread %d:   Sum=", taskid);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    double count=0.0;
    srand48(1);
    pthread_t threads[NUM_THREADS];
    //int *taskids[NUM_THREADS];
    int rc, t;


    for(t=0;t<NUM_THREADS;t++) {
        thread_data_array[t].thread_id = t;
        rc = pthread_create(&threads[t], NULL, PrintHello, (void *) &thread_data_array[t]);
        
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    
    sleep(3);
    
    for(int i=0;i<NUM_THREADS;i++)
        count+=thread_data_array[i].wheel;
    
    printf("ALL THREADS | Pi estimated value: %f\n",count*4/(NUM_THREADS*LOOP));
    pthread_exit(NULL);
}


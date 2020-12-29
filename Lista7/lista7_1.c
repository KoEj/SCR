#include <pthread.h>
#include <stdio.h>

#define ILOSC_WATKOW 10

void *thread_message(void *id) {
    long tid;
    tid=(long)id;
    printf("Hello SCR. Written by thread %ld\n", tid);
    
    pthread_exit(NULL);
}

int main(int argc, const char * argv[]) {
    pthread_t id[ILOSC_WATKOW];
    
    for(long i=0;i<ILOSC_WATKOW;++i) {
        if(pthread_create(&id[i], NULL, thread_message, (void*)i)) {
            fprintf(stderr, "Problem przy tworzeniu wątku!");
        }
    }
    
    for(int i=0;i<ILOSC_WATKOW;++i) {
        pthread_join(id[i], NULL);
    }
    
    pthread_exit(NULL);
    
    return 0;
}

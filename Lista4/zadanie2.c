//
// kill -l
// 14 - SIGALARM, 15 - SIGTERM, 30 - SIGUSR1, 31 - SIGUSR2
//
//
//
//
//


#include <time.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int i = 0;

// wyswietla komunikat i konczy prace programu
void sygnal_a(int sygnal) {
    printf("Sygnał przechwycony: %d, koniec pracy programu!\n Kliknij ENTER...",sygnal);
    exit(0);
}

// wyswietla komunikat i powraca do wykonywania programu
void sygnal_b(int sygnal) {
    printf("Sygnał przechwycony: %d, program kontynuuje swoją pracę.\n", sygnal);
}

//
void sygnal_c(int sygnal) {
    printf("Poczatek blokowania sygnałów\n");
    for (int j=0;j<10;j++) {
        ++i;
        sleep(1);
        printf("%d\n",i);
    }
    printf("Koniec blokowania sygnałów\n");
    
}

// calkowite ignorowanie sygnalu
void sygnal_d(int sygnal) {
}

int main() {
    signal(SIGALRM, sygnal_a);
    signal(SIGTERM, sygnal_b);
    signal(SIGUSR1, sygnal_c);
    signal(SIGUSR2, sygnal_d);


    while (1) {
       ++i;
        sleep(1);
        printf("%d\n",i);
    
    }
    
    return 0;
}

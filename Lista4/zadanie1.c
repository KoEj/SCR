//
// Na początku wywołano program bez sleepa - znajdował się on na pierwszej pozycji, potem dodano strukturę nanosleep - 5ns. Program na początku pojawił się na samej górze, potem w htop znikał i co 1 sekundę się pojawiał i znowu znikał.
// Program htop wywołano poleceniem: sudo htop -d 1
//

#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char * argv[]) {
    struct timespec tim, tim2;
    tim.tv_sec  = 0;
    tim.tv_nsec = 5e08;
    
    int i=1;
    while (1) {
        ++i;
        nanosleep(&tim, &tim2);
    }
    return 0;
}

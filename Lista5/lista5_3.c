#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFOR 256
//#define READ_FD 0
//#define WRITE_FD 1

#define FIFO "FIFO"

int main(int argc, const char * argv[]) {
    char buf[BUFFOR];
    int fd[BUFFOR];
    int pipe;
    int i;
    int n;
    int int_sleep=5;
    int blad=0;
    
    
    //Zamiennik mknod FIFO p
    //Na systemie MacOS nie wyszukuje opcji p - pipe fifo
    // " mknod: node type must be 'b' or 'c' or 'w'. "
    
    mkfifo(FIFO,0666);
    //default mode that allows read and write permission for the owner, group, and others (0666) as modified by the current file creation mask.
    pipe = open(FIFO, O_WRONLY);
    
    for(i=1;;i++) {
        if(argv[i]==NULL) {
            if(i==1)
                printf("\033[0;31mNie podano plików do otwarcia w argumentach! Koniec pracy programu.\033[0m\n");
                else
                    if (blad>0) printf("\033[0;31mNie otworzono wszystkich plików poprawnie!. Koniec pracy programu.\033[0m\n");
                        else
                printf("\033[0;32mWszystkie pliki - %d zostały poprawnie otwarte! Koniec pracy programu.\033[0m\n",i-1);
            close(pipe);
            return 0;
        }
        else {
            fd[i]=open(argv[i],O_RDONLY);
            
            if (fd[i]<0) {
                fprintf(stderr, "\033[0;31mBłąd przy otwarciu pliku!\033[0m\n");
                blad++;
            }
            else {
                printf("Zapisywanie do pipe %d. pliku \n",i);
                
                while ((n=read(fd[i],buf,BUFFOR)) > 0) {
                    write(pipe,buf,n);
                }

                printf("Przerwa w pracy programu (%ds)\n",int_sleep);
                sleep(int_sleep);
            }
        }
    }
}

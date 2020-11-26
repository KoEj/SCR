#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUFFOR 256
#define READ_FD 0
#define WRITE_FD 1

int main(int argc, const char * argv[]) {
    int fd[2];
    int plik;
    int n;
    char buf[BUFFOR];
    char nazwa[BUFFOR];
    pid_t pid;
    
    if (pipe(fd) < 0) {
        fprintf(stderr, "Błąd przy tworzeniu pipe");
        return 1;
    }
    pid=fork();

    //Dziecko
    if (pid==0) {
        close(fd[WRITE_FD]);
        close(READ_FD);
        dup(fd[READ_FD]);
        close(fd[READ_FD]);
        if (open(argv[1], O_RDONLY)>0) {
            execlp("display", "display",NULL,NULL);
        }
    }
    //Rodzic
    else {
        close(fd[READ_FD]);
        printf("Podaj sciezke do pliku: ");
        scanf("%s", nazwa);
        
        if ((plik=(open(nazwa, O_RDONLY))<0)) {
            fprintf(stderr, "Błąd przy otwarciu pliku!");
            return 2;
        }

        while ((n=(read(plik, buf, BUFFOR)) > 0)) {
            if (write(fd[WRITE_FD], buf, n)<0) {
                fprintf(stderr, "Błąd zapisu do pipe!");
                return 3;
            }
        }
    close(plik);

    }
    return 0;
}

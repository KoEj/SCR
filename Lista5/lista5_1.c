#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define BUFFOR 256
#define READ_FD 0
#define WRITE_FD 1

int main(int argc, const char * argv[]) {
    int fd[2];
    char buf[BUFFOR];
    pid_t pid;
    FILE *plik;
    
    if (pipe(fd) < 0) {
        fprintf(stderr, "Błąd przy tworzeniu pipe");
        return 1;
    }
    pid=fork();

    //Dziecko
    if (pid==0) {
        close(fd[WRITE_FD]);
        
        while(read(fd[READ_FD], buf, BUFFOR)) {
            if (buf[BUFFOR-1]!=0) {
                buf[BUFFOR-1]='\0';
                printf("# %s #\n",buf);
            }
            else break;
        }
    }
    //Rodzic
    else {
        close(fd[READ_FD]);
        
        if (!(plik=fopen(argv[1],"r"))) {
            fprintf(stderr, "Błąd przy otwarciu pliku!");
            return 2;
        }

        while (fgets(buf,BUFFOR,plik)){
            buf[BUFFOR-1]=1;
            write(fd[1],buf,BUFFOR);
        }
        
        fclose(plik);
    }

    return 0;
}


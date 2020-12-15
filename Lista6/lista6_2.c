#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    struct stat dane_pliku;
    int mapf_fd;
    int f_fd;
    //char buff[1];
    //long long odczyt;
    char plik[256];
    int pid;
    
    if((mapf_fd=open("./wynik_map.jpg",O_RDWR))<=0) {
   // if((mapf_fd=open(argv[1],O_RDWR))<=0) {
        fprintf(stderr,"Blad przy otwieraniu pliku do mapowania pamieci");
        exit(1);
    }
    
    while(1) {
        pid=fork();
        
        if(pid>0) {
            printf("Podaj nazwe pliku do odczytu \n");
            scanf("%s",plik);

            if((f_fd=open(plik,O_RDONLY))<0) {
                fprintf(stderr,"Blad przy odczytaniu pliku");
                exit(2);
            }
            
            if (fstat(f_fd, &dane_pliku)==-1) {
                fprintf(stderr,"Blad przy wyciaganiu statystyk");
                exit(3);
            }

            //Przycina plik do określonej długości)
            ftruncate(mapf_fd,dane_pliku.st_size);
            
            char* wsk=mmap(NULL,dane_pliku.st_size,PROT_WRITE | PROT_READ,MAP_SHARED,mapf_fd,0);
            
            if (wsk==MAP_FAILED) {
                fprintf(stderr,"Blad przy kolejnym mapowaniu");
                exit(4);
            }

            read(f_fd,wsk,dane_pliku.st_size);
            close(f_fd);
        }
        else if(pid==0) {
            //execlp("display", "", "-update", "1", "-delay", "2", "cat_arr.jpg", NULL);
            sleep(5);
            execlp("pqiv","","wynik_map.jpg", NULL);
        }
        else {
            fprintf(stderr,"Blad funkcji fork");
            close(mapf_fd);
            exit(5);
        }
    }
}

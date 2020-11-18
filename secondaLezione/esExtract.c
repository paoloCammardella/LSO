#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <inttypes.h>
#include <errno.h>

void extract(const char *file1, char *file2, int byteIniziale, int byteFinale);

int main(int argc, char *argv[]){

    int n = atoi(argv[3]), m = atoi(argv[4]);
    
    extract(argv[1], argv[2], n, m);

    return 0;
}

void extract(const char *file1, char *file2, int byteIniziale, int byteFinale){
    
    mode_t mode = S_IRUSR | S_IWUSR;
    int fd1, fd2, sommaByte;
    sommaByte = byteFinale - byteIniziale;
    
    //gestione file2
    int f2d = open(file2, O_RDWR | O_CREAT | O_APPEND, mode);
    if(f2d == -1)
        perror("c'e` un errore con file2");

    //inizio gestione primo file
    if((fd1 = open(file1, O_RDONLY, mode)) == -1)
        perror("c'e` un errore file1");

    if(lseek(fd1, byteIniziale, SEEK_SET) == -1)
        perror("error seeking");
    else
        perror("seeking");
    
    while(lseek(fd1, 0, SEEK_CUR) <= byteFinale){
        
        char buf;
        if(read(fd1, &buf, 1) != 1)
            printf("cannot read");

        if(write(f2d, &buf, 1) != 1)
            printf("cannot write");
    }
}
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "syscall.h"

int main(int argc, char *argv[]){
    int f1, f2, n;
    char buf[BUFSIZ];

    if(f1 = open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR) == -1)
        perror("Errore file1");
    
    if(f2 = open(argv[2], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR) == -1)
        perror("Errore file2");
    
    while((n = read(f1, buf, BUFSIZ)) > 0){
        if(write(f2, buf, n) != n)
            perror("Errore di scrittura");
    }
}
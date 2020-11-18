#include <sys/types.h>
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(){

    if(lseek(STDIN_FILENO, 0, SEEK_CUR) == -1){
        printf("cannot seek\n");
        perror("errore di seek ");
    }
    else
        printf("seek OK\n");
    
    return 0;
}
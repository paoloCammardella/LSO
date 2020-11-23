<<<<<<< HEAD
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
=======
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]){

    int fd;
    if((fd = open(argv[1], O_RDONLY | O_CREAT, S_IRWXU)) == -1)
        perror("file");
        
    return 0;
}
>>>>>>> c0a5129 (salvataggio portatile)

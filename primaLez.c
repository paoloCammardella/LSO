#include <stdio.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(){

     fd = open("~/lso/file.txt", 
        O_RDWR | 
        O_CREAT | 
        O_APPEND, 
        S_IRUSR | 
        S_IWUSR);

    //printf("%d\n", fileE);
    
    if(open(fd , O_RDONLY) == -1)
        perror("errore di open");
   
    return 0;
}
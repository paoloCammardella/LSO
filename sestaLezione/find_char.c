#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/stat.h>

void *thread();
int stringToLong(char *);

int main(int argc, char *argv[]){

    int n = stringToLong(argv[3]);

    int fd, nbyteread, nbyteperthread;
    char x = argv[2];
    pthread_t thread1;

    if((fd = open(argv[1], O_RDONLY | O_CREAT, S_IRWXU)) == -1)
        perror("file");

    if((nbyteread = read(fd, BUFSIZ, BUFSIZ)) == -1)
        perror("read");

    nbyteperthread = nbyteread / n;
    
    thread1 = pthread_create(&thread1, NULL, thread, NULL);

return 0;
}

void *thread(void){
    //lseek(fd, nbpt, SEEK_SET);
    printf("new thread");
}

int stringToLong(char *arg){
    if(arg == NULL)
        arg = 0;
    else
        arg = strtol(arg, &arg, 10);
    
    return arg;
}
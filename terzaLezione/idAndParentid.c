#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){

    printf("Parent process: \t%d; \tprocess: \t%d;\n", getppid(), getpid());
    
    pid_t pid;
    if((pid = fork()) < 0){
        perror("fork error\n");
        exit(EXIT_FAILURE);
    }
    printf("PID: \t%d; \tParent process: \t%d; \tprocess: \t%d;\n", pid, getppid(), getpid());
    return 0;
}

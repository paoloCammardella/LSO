#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{

    int n = atoi(argv[1]), i;
    int args_size = n;
    char *args[args_size];
    
    for(i = 0; i < args_size; i++){
        args[i] = argv[i + 2];
    }

    args[n - 1] = NULL;

    for (i = 0; i < n ; i++)
    {
        pid_t pid = fork();
        
        if (pid > 0)
            waitpid(pid, NULL, 0);
        else if (pid == 0){
            if(execvp(args[0], args) == -1);
            perror("execvp");
        }
        else
            perror("fork");
    }
}
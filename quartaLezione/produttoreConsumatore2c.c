#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <signal.h>


void produttore(int);
void consumatore(int);

int main()
{
    int pipefd[2];
    
    if(pipe(pipefd) < 0)
        perror("pipe error");

    printf("per terminare il processo inserire 0.\n\n");
    signal(SIGINT, SIG_IGN);

    pid_t pid = fork();

    if (pid > 0) {//padre
        produttore(pipefd[1]);
        close(pipefd[0]);
    }
    else {//figlio
        consumatore(pipefd[0]);
        close(pipefd[1]);
    }
    return 0;
}

void produttore(int fd)
{
    while (1)
    {
        int intero;

        if (scanf("%d%*c", &intero) != 1 || intero == 0)
        {
            printf("programma terminato\n");
            exit(1);
        }
        if (write(fd, &intero, sizeof(int)) != sizeof(int))
            exit(1);
    }
    
}

void consumatore(int fd)
{
    while (1)
    {
        int intero;
        
        if (read(fd, &intero, sizeof(int)) == 0)
        {
            perror("read");
            exit(1);
        }

        printf("%d\n", intero);
    }
}
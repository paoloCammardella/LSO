#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <signal.h>

#define FILENAME "mybuffer.temp"

void produttore(int);
void consumatore();

int main()
{
    int fd;

    if ((fd = open(FILENAME, O_WRONLY | O_CREAT, S_IRWXU)) == -1)
        perror("mybuffer.temp");

    printf("per terminare il processo inserire 0.\n\n");
    signal(SIGINT, SIG_IGN);

    pid_t pid = fork();

    if (pid) //padre
        produttore(fd);
    else //figlio
        consumatore();

    unlink(FILENAME);
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
    
    if(unlink(FILENAME) != 0)
        perror("close");
}

void consumatore()
{
    int fd;

    if ((fd = open(FILENAME, O_RDONLY)) == -1)
        perror("");

    while (1)
    {
        int intero, result;

        while ((result = read(fd, &intero, sizeof(int))) == 0)
            ;
        if (result == -1)
        {
            perror("read");
            exit(1);
        }

        printf("%d\n", intero);
        write(fd, &intero, sizeof(int));
    }
}
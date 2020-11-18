#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{

    int fd, fd2, sz;
    char buffer;
    off_t offset;

    printf("------------------FILE1-----------------\n");
    if ((fd = open(argv[1], O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR)) == -1)
        perror("Errore file1");
    else{
        perror("File1 open");
        printf("File descriptor file1: %d\n\n", fd);
    }

    printf("------------------FILE2-----------------\n");
    if ((fd2 = open(argv[2], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR)) == -1)
        perror("Errore file2");
    else{
        perror("File2 open");
        printf("file descriptor file2: %d\n\n", fd2);
    }

    if(lseek(fd, -0, SEEK_END) == -1)
        perror("Error seeking");
    else
        perror("Seeking");
    
    while (lseek(fd, -2, SEEK_CUR) >= 0)
    {
        char b;

        if(read(fd, &b, 1) != 1)
            perror("cannot read");

        if (write(fd2, &b, 1) != 1)
            perror("cannot write");
    }

    close(fd);
    close(fd2);
    return 0;
}
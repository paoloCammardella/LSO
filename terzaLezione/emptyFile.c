#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFSIZ 8192

int main(int argc, char *argv[]){

    int fd = open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    int fd2 = open(argv[2], O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR);
    char s[BUFSIZ];
    int n;

    int lim = scanf("%[^\n]s*c", s);
    for(int i = 0; i < lim; i++){
        printf("%s", &s[i]);
    }

    write(fd, s, n);

    while(n = read(fd, s, BUFSIZ) > 0){
        write(fd2, s, n);
    }

    printf("\n");
}
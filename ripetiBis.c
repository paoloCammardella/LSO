#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){

    exec("ls", "");

    return 0;
}
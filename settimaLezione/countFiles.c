#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/stat.h>

// typedef struct thread{
//     pthread_t tid;
// }thread;

void *myTurn(void *arg){
    for(int i = 0; i < 8; i++){
        sleep(1);
        printf("my turn now!\n");
    }

    return NULL;
}

void yourTurn(){
    for(int i = 0; i < 3; i++){
        sleep(2);
        printf("your turn now!\n");
    }

    //return NULL;
}

int main(void){
    pthread_t newthread, secondthread;
    pthread_create(&newthread, NULL, myTurn, NULL);
    //pthread_create(&secondthread, NULL, yourTurn, NULL);

    yourTurn();
}
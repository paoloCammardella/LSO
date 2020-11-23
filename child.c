#include <stdio.h>
#include <fcntl.h>

typedef struct client{
    pid_t pid;
    char *nickname;
}client;

client crea(client, char *);

 int main(){
//     int thread;
//     p_threads_create(thread);
    client c1 = crea(c1, "paolo");

    printf("\tnickname c1: %s\n", c1.nickname);
    printf("\tpid c1: %d\n", c1.pid);
    
    return 0;
}

client crea(client client, char *clientName){
    
    client.nickname = clientName;
    client.pid = fork();

    return client;
}
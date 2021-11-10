#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

using namespace std;

int main(int argc, char *argv[]){
char *path= argv[1];
int fd = open(path,O_RDWR);
if(lockf(fd,F_TEST,100) == 0){
    lockf(fd,F_LOCK,100);
    sleep(30);
    lockf(fd,F_ULOCK,100);
}

//si esta desbloqueado, fijaara un cerrojo y escribira la hora actual.


//si esta bloqueado terminara el programa

 return 1;   
}

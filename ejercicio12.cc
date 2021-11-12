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
int fd = open(path,O_CREAT,0777);//lo creo con todos los permisos
if(fd ==-1){
    printf("error");
}
int fd2 = dup2(fd,1);
printf("rediccionamiento");
dup2(fd2,fd);


 return 1;   
}

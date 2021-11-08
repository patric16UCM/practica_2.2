
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

using namespace std;

int main(int argc, char *argv[]){
char *path= argv[0];
mode_t modo;
 modo = umask(0645);
 int resultado = open(path,O_CREAT,modo);

 if(resultado == -1){
     perror("Se ha producido un error.");
 }
 return 1;   
}

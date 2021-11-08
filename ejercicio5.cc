
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

using namespace std;

int main(int argc, char *argv[]){
char *path= argv[1];
mode_t modo;

 int resultado = open(path,O_CREAT|O_TRUNC,0645);

 if(resultado == -1){
     perror("Se ha producido un error.");
 }
 return 1;   
}

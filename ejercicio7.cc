#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

using namespace std;

int main(int argc, char *argv[]){
char *path= argv[1];
 int resultado =umask(0727);
 if(resultado == -1){
     perror("Se ha producido un error fijando la mascara.");
 }
  resultado = open(path,O_CREAT|O_TRUNC,0777);

 if(resultado == -1){
     perror("Se ha producido un error creando el archivo.");
 }
 return 1;   
}

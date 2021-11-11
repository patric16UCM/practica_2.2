#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <time.h>

using namespace std;

int main(int argc, char *argv[]){
char *path= argv[1];
struct stat datos;
char *archivoT = "desconocido";
int resultado = stat(path, &datos);
//st_ino nodo = datos->st_ino;
mode_t tipo = datos.st_mode;
time_t tiempo = datos.st_atime;
tm *acc = localtime(&tiempo);
dev_t dispositivo = datos.st_dev;

if(S_ISLNK(datos.st_mode)){
    archivoT ="enlace simbolico";
}
else if(S_ISREG(datos.st_mode)){
    archivoT="fichero normal";
}
else if(S_ISDIR(datos.st_mode  )){
    archivoT="directorio";
}
printf("Tipo de archivo: %s\n",archivoT);
printf("Ultimo acceso:%d:%d:%d \n",acc->tm_hour, acc->tm_min,acc->tm_sec);
//printf("Tipo de archivo: %s\n", dispositivo);
printf("Numero inodo: %d \n",(long)datos.st_ino);
printf("Numero major:%d \n",major(dispositivo ));
printf("Numero minor:%d \n",minor(dispositivo ));
 return 1;   
}

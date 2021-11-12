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
char* duro;
char* blando;
strcpy(duro,argv[1]);
strcpy(blando,argv[1]);
struct stat *datos;
int res  = stat(path,datos);
if(S_ISREG(datos->st_mode)){
duro = strcat(duro,".hard");
blando = strcat(blando,".sym");
int resultado = link(path,duro);
int resultado2 = symlink(path,blando);
}
 return 1;   
}

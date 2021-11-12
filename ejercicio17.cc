#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>

using namespace std;

int main(int argc, char *argv[]){
char *path= argv[1];
struct stat *datos;
DIR *directorio = opendir(path);
struct dirent *sigD;
sigD = readdir(directorio);
while(sigD != NULL ){
    int resultado  = stat(path,datos);
    if(S_ISLNK(datos->st_mode)){
    printf("enlace simbolico[*] %s \n", sigD->d_name);
            }
    else if(S_ISREG(datos->st_mode)){
        printf("fichero normal-> %s \n", sigD->d_name);
    }
    else if(S_ISDIR(datos->st_mode  )){
        printf("directorio/ %s \n", sigD->d_name );
    }      
    sigD = readdir(directorio);
}

closedir(directorio);

 return 1;   
} 

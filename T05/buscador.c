#define _DEFAULT_SOURCE
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buscador(const char *path, const char *file) {
       struct dirent **namelist;
       int n;

       n = scandir(path, &namelist, NULL, alphasort);
       if (n == -1) {
              perror("scandir");
              exit(EXIT_FAILURE);
       }

       while (n--) {
              if(strstr(namelist[n]->d_name, file) != NULL) {
                     printf("%d . %s/%s\n", n,path,namelist[n]->d_name);
              }
              free(namelist[n]);
       }
       free(namelist);

       exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[])
{
        char *path = argv[1];
        char *file = argv[2];
        buscador(path, file);

}

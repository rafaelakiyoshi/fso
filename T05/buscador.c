#define _DEFAULT_SOURCE
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int loop = 0;
int it = 1;

void read_file(long byteAmount, char *file_name) {
   FILE * pFile;
  long lSize;
  char * buffer;
  size_t result;

  pFile = fopen (file_name , "rb" );
  if (pFile==NULL) {fputs ("File error",stderr); exit (1);}

  // obtain file size:
  fseek (pFile , 0 , SEEK_END);
  lSize = ftell (pFile);
  rewind (pFile);

  // allocate memory to contain the whole file:
  if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}

  // copy the file into the buffer:
  if(lSize>byteAmount){
    buffer = (char*) malloc (sizeof(char)*lSize);
    result = fread (buffer,1,lSize,pFile);
  } else {
    buffer = (char*) malloc (sizeof(char)*byteAmount);
    result = fread (buffer,1,byteAmount,pFile);
  }
  if (result != lSize) {fputs ("Reading error",stderr); exit (3);}

  /* the whole file is now loaded in the memory buffer. */
  printf("%s\n", buffer);
  // terminate
  fclose (pFile);
  free (buffer);
}

int isDirectory(char *path){
   struct stat buf;
   stat(path, &buf);
   if(S_ISDIR(buf.st_mode)) {
      return 1;
   }
   else {
      return 0;
   }
}

char* concatenate_string(char* str1, char* str2, char* str3) {
   char * str4 = (char *) malloc(1 + strlen(str1)+ strlen(str2) + strlen(str3) );
   strcpy(str4, str1);
   strcat(str4, str2);
   strcat(str4, str3);
   return str4;
}

int buscador(char *path, char *archive) {
   struct dirent **namelist;
   int n;

   n = scandir(path, &namelist, NULL, alphasort);
   if (n == -1) {
      perror("scandir");
      exit(EXIT_FAILURE);
   }
   while (n--) {
      char *fileToOpen = concatenate_string(path, namelist[n]->d_name, "");
      if(isDirectory(fileToOpen) == 1 && (strcmp(namelist[n]->d_name, "..")!=0 && strcmp(namelist[n]->d_name, ".")!=0)) {
         char *fileToOpen = concatenate_string(path, namelist[n]->d_name, "/");
         return buscador(fileToOpen, archive);
      } else {
         if(strstr(namelist[n]->d_name, archive) != NULL) {
            printf("%d. %s --\n", it,fileToOpen);
            read_file(30, fileToOpen);
            // int c;
            // int count = 0;
            // FILE *file;
            // file = fopen(fileToOpen, "r");
            // if (file) {
            //    int test = 20;
            //    while( ( c = fgetc(file) ) != EOF || count < 30) {
            //       Buffer[count++] = c; // make Buffer global variable
            //
            //       printf("%c",c);
            //    }
            //    printf("\n");
            //    fclose(file);
            // }

            it++;
         }
      }
      free(namelist[n]);
      if(loop == 1){
         return 0;
      } else {
         loop--;
      }
   }
   free(namelist);

   exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[])
{
   char *path = argv[1];
   char *archive = argv[2];
   loop = atoi(argv[3]);
   printf("Resultado de buscador -- \"%s\" na pasta %s\n",archive, path);
   buscador(path, archive);

}

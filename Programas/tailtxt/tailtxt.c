#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <dirent.h>

char*
dar_variable(char *var)
{
  char *value;
  value = getenv(var);
  return value;
}

static void
leerdirp(DIR *dirp){
  struct dirent *direntp;
  while ((direntp = readdir(dirp)) != NULL) {
    char *name;
    name = direntp->d_name;

    printf("%d,\t%s\n", direntp->d_reclen, name);
  }
  closedir(dirp);
}

int
main(int argc, char *argv[])
{
  char *env;
  DIR *dirp;
  char *bytes;
  int intbytes =0;

  env = dar_variable("PWD");
  dirp = opendir(env);
  if (dirp == NULL){
    printf("Error: No se puede abrir el directorio\n");
    exit(2);
  }

  switch(argc){
    case 1:
      leerdirp(dirp);
      break;
    default:
        bytes = argv[1];
        leerdirp(dirp);
        intbytes = atoi(bytes);
        if (intbytes == 0){
          printf("Error: argumento N Bytes inválido\n");
          exit(2);
        }
        printf("\nbytes: %d\n",intbytes);
  }

  exit(EXIT_SUCCESS);
}

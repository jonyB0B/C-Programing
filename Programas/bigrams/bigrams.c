#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>


static void
run(char *file){
  FILE *fp;
  struct t_reg r;

  fp=fopen (file,"r");
  if (fp == NULL){
    err(1,"fopen\n " );
  }
  fread (&r, sizeof(r), 1, fp);
  while (!feof(fp)) {
    printf ("%d: %s: %c\n" , r.num, r.cad, r.car);
    fread (&r, sizeof(r), 1, fp);
  }
  fclose (fp);
}


int
main(int argc, char* argv[] ){
  char *file;

  if (argc<2){
    fprintf(stderr,"Numero de argumentos incorrecto\n");
    exit(1);
  }
  file = argv[1];

  run(file);
  exit (EXIT_SUCCESS);
}

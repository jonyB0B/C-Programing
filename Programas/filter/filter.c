#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>


typedef struct Tcomando Tcomando;
struct Tcomando
{
	char *comando;
	char *argumentos[64];
};

char*
dar_variable(char *var)
{
  char *value;
  value = getenv(var);
  return value;
}

/*creatfile(char *name){
  int fd;
  int fdaux;
  int nr;
  int nw;
  int buffer[1024];
  char fout[128];

  sprintf(fout,"%s.out",name);

  fd = open (name,O_RDONLY);
  if(fd<0)
    err(1,"Error: open\n");

  fdaux = creat(fout,0644);
  if(fdaux<0)
    err(1,"Error: creat\n");


  for(;;){
    nr=read(fd,buffer,1024);
    if(nr<=0)
      break;

    nw = write(fdaux,buffer,nr);
    if(nw!=nr)
      err(1,"Error: erro al escribir\n");
  }
  close(fd);
  close(fdaux);
}

int
estxt(char **p){
  return (*p!=NULL)&&(strlen(*p)==strlen(".txt"));
}

void
waitchild(int files){
  int i;
  int status;
  int finalstatus=0;

  for(i=0;i<files;i++){
    wait(&status);
    if (status!=0)
      finalstatus = 1;
  }

  if (finalstatus)
    exit(EXIT_FAILURE);
}

void
forkfiles(char ficheros[][128],int files){
  int i;
  int pid;
  struct stat fichero;

  for(i=0;i<files;i++){
    pid = fork();
    switch(pid){
    case -1:
        err(1,"Error: fork \n");
        break;
    case 0:
      stat(ficheros[i],&fichero);
      creatfile(ficheros[i]);
      exit(EXIT_SUCCESS);
      break;
    }
  }
  waitchild(files);
}



static void
leerdirp(DIR *dirp,char *comando,char *rexp){
  struct dirent *direntp;
  struct stat info;
  char ficheros[MAX][128];
  char *p;
  int files = 0;

  while ((direntp = readdir(dirp)) != NULL) {
    char *name;
    name = direntp->d_name;
    stat(name,&info);
    if((info.st_mode & S_IFMT)!=S_IFREG)
      continue;

    strcpy(ficheros[files],name);
    files++;
    if(files==MAX){
      fprintf(stderr,"Error: demasiados ficheros\n");
      exit(1);
    }
  }
  closedir(dirp);
  forkfiles(ficheros,files);
}*/

/*execvp(comandos[i].comando,comandos[i].argumentos);*/
int
main(int argc, char *argv[])
{
  //char *env;
  //DIR *dirp;
  int i;
  int n;
  char *comando[64];
  char *rexp;
  Tcomando comandos[MAXCMD];
/*  env = dar_variable("PWD");
  dirp = opendir(env);

  if (dirp == NULL)
    err(1,"Error: No se puede abrir el directorio\n");*/
  rexp = argv[1];
  printf("Expresion : %s\n",rexp);
  for(i=2;i<argc;i++){
      comando[i] = argv[i];
      n = strtok(comando[i]," ");
      comandos[i].argumentos[n] =NULL;
			comandos[i].comando = comandos[i].argumentos[0];

  }

  //leerdirp(rexp,comando);
    //expresion regular + comando
  exit(EXIT_SUCCESS);
}

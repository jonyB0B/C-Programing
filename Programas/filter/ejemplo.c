#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

comando < fichero | grep reprex
void 
exec(char *filename, char *expresion , char *comando[]){
	int p[2];
	int fd;
	pipe (p);
	pid =fork();
	switch(pid){
	case -1:
        err(1,"Error: fork \n");
        break;
    case 0:
    	fd = open(filename,O_RDONLY);
		if(fd<0)
		  err(1,"Error: open\n");
		dup2(fd,0);      	
		close(fd);

		dup2(p[1],1);//comando al pipe
		close(p[0]);//solo tengo que tener abierto 0 1 2
		close(p[1]);

		execvp(comando[0],comando);
		exit(EXIT_FAILURE);
    }

    pid2 = fork();
    switch(pid2){
    case -1:
        err(1,"Error: fork \n");
        break;
    case 0:
		dup2(p[0],0); // salida del pipe
		close(p[0]);//solo tengo que tener abierto 0 1 2
		close(p[1]);
		execlp("grep","grep",rexp,NULL);
		exit(1);
      
    }
	close(p[0]);//solo tengo que tener abierto 0 1 2 por lo que tengo que cerrar antes de los wait 
	close(p[1]);
	wait(NULL);
	wait(NULL);
}

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
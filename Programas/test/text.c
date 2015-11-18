#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

/*void
reemplazar(char **s)
{

	*s="hola";

}

int 
main(int argc, char * argv[ ])
{

	char *z;
	z="adios";
	reemplazar(&z);
	printf("%s",z);
	exit(0);

}*/
int
main(int argc, char * argv[ ])

{

char buf[8192];

int n;

n=read(0,buf,sizeof buf);

write(1,buf, n);
exit(0);

}
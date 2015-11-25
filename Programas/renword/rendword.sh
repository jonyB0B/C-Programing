#if for y grep
#script un argumento solo
#$* argumentos de un script $# numero de argumentos
#exit 1 error , echo --> salida de error    2&>1>fich

#!/bin/bash
if [ $# -gt 1 ]
then
  echo "Usage: $0 numero de argumentos incorrecto "
  exit 1
fi

for i in $PWD/*.txt
do
    if [ $grep '^' $1 $i ]
    then
      echo mv $i $i.$1
    fi
done
exit 0

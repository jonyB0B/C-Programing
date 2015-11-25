#!/bin/bash
if [ $# -gt 1 ];then
  echo "Usage: $0 numero de argumentos incorrecto " 1>&2
  exit 1
fi

for i in `ls`
do
    if  grep "^"$1 $i > /dev/null 2>&1 
    then
      mv $i $i.$1
    fi
done
exit 0
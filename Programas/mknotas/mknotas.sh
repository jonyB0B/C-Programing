#uniq sort -u pipelines y filtros -E para usar +
#!/bin/bash
if [ $# -eq 4 ];then
  #for i in $*;do
  usuarios=`sort $* | awk '{print $1}' | uniq -c | awk '{print $2}'`
  echo $usuarios
  grep -e "si" $*
  #done
else
  echo "Usage: $0 numero de argumentos incorrecto " 1>&2
  exit 1
fi

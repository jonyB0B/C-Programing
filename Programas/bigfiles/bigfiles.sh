#!/bin/bash
#awk mirar
a=`du -a -b | sort -n -r`
for i in $a;do
 if [ -f $i ];then
   du -b -a $i
 fi
done | sed $1q

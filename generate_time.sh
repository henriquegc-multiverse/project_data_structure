#!/bin/bash

i=1
j=1

rm ./tempos.txt

while [ "$i" -le 10 ]; do
  echo "Lista $i" >> ./tempos.txt

  while [ "$j" -le 30 ]; do
    ./bin/estoque ./lists/lista-$i.txt ./saida.txt ./tempos.txt
    j=$(($j+1))
  done
  
  i=$(($i+1))
  j=1
done

rm ./saida.txt

#!/bin/bash

i=1
j=1

if [ -e "./tempos.txt" ] ; then
  rm ./tempos.txt
fi

while [ "$i" -le 30 ]; do
  while [ "$j" -le 10 ]; do
    ./bin/estoque ./lists/lista-$j.txt ./saida.txt ./tempos.txt
    j=$(($j+1))
  done
  
  i=$(($i+1))
  j=1
done

rm ./saida.txt

output=""
k=1

output+="Lista 1,Lista 2,Lista 3,Lista 4,Lista 5,Lista 6,Lista 7,Lista 8,Lista 9,Lista 10\n"

while IFS= read -r line; do
  output+="$line"

  if [ "$k" -lt 10 ]; then
    output+=","
  else
    output+="\n"
    k=0
  fi

  k=$(($k+1))
done < "./tempos.txt"

echo -e "$output" > "./tempos.csv"

rm ./tempos.txt

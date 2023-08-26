#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

extern FILE *file;

#define MIN_LENGTH 5000
#define MAX_LENGTH 50000
#define GAP 5000
#define REPETITIONS 30

// Insere o produto no arquivo x vezes, sendo x = tamanho
void insertProducts(int tamanho);

// Insere as ultimas linhas do arquivo, para ordenar e para indicar o fim de execução
void insertSortedList();

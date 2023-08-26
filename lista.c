#include "lista.h"

void insertProducts(int tamanho) {
  char instrucao[] = "PRODUTO";
  char produto_nome[] = "ALPISTE";
  int produto_id = 4;
  int data[3] = {27, 12, 1990};

  for (int preco = 0; preco < tamanho; preco++) {
    fprintf(file, "%s %s %d %d %d %d %d\n", instrucao, produto_nome, produto_id,
            preco, data[0], data[1], data[2]);
  }
}

void insertSortedList() { fprintf(file, "ORDENA_LISTA_VALOR\nFIM\n"); }

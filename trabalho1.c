#include "estoque.h"
#include <string.h>

int main() {
  char aa[20];
  FILE *f = fopen("./tests/entrada.txt", "r");

  if (f == NULL) {
    puts("File open error! exiting...");
    return 1;
  }

  char b[100];
  int c;
  float d;
  int e;
  int h;
  int g;
  int i;
  int j;
  float k;


  while(fscanf(f, "%s", aa) == 1) {
    printf("%s\n", aa);

    if (!strcmp(aa, "PRODUTO")) {
      fscanf(f, "%s", b); // PRODUTO
      fscanf(f, "%d", &c); // ID
      fscanf(f, "%f", &d); // PRECO
      fscanf(f, "%d", &e); // DIA
      fscanf(f, "%d", &g); // MES
      fscanf(f, "%d", &h); // ANO
    }

    else if (!strcmp(aa, "RETIRA")) {
      fscanf(f, "%s", i); // ID
    }

    else if (!strcmp(aa, "IMPRIME_LISTA")) {
      // Imprimir lista
    }  

    else if (!strcmp(aa, "ATUALIZA_PRECO")) {
      fscanf(f, "%s", j); // ID
      fscanf(f, "%s", k); // NOVO PRECO
    }

    else if (!strcmp(aa, "VERIFICA_VALIDADE")) {
      // Ver se algum produto ta fora de validade
      fscanf(f, "%d", &e); // DIA
      fscanf(f, "%d", &g); // MES
      fscanf(f, "%d", &h); // ANO
    }

    else if (!strcmp(aa, "VERIFICA_LISTA")) {
      // Ver se o produto ta na lista
      fscanf(f, "%s", j); // ID
    }

    else if (!strcmp(aa, "ORDENA_LISTA_VALIDADE")) {
      // Ordenar lista por validade
    }

    else if (!strcmp(aa, "ORDENA_LISTA_VALOR")) {
      // Ordenar lista por valor
    }

    else if (!strcmp(aa, "FIM")) {
      break;
    }

    else {
      printf("Comando não reconhecido: %s\n", aa);
    }
  }

  fclose(f); 

  return 0;
}
#include "estoque.h"
#include <string.h>
#include <time.h>
#include <string.h>

#define BUF_LEN 256

int main() {
  char aa[20];
  FILE *f = fopen("./tests/entrada.txt", "r");

  if (f == NULL) {
    puts("Erro ao abrir o arquivo!");
    return 1;
  }

  char nome[20];
  int id;
  float preco;
  int data[3];

  int i;
  int j;
  float k;


  Lista* l = CriaLista();

  while(fscanf(f, "%s", aa) == 1) {

    if (!strcmp(aa, "PRODUTO")) {
      fscanf(f, "%s", nome); // PRODUTO
      fscanf(f, "%d", &id); // ID
      fscanf(f, "%f", &preco); // PRECO
      fscanf(f, "%d", &data[0]); // DIA
      fscanf(f, "%d", &data[1]); // MES
      fscanf(f, "%d", &data[2]); // ANO
      printf("PRODUTO");

      Produto* p = CriaProduto(nome, id, preco, data);
      l = InsereListaProduto(l, p);
    }

    else if (!strcmp(aa, "RETIRA")) {
      fscanf(f, "%d", &i); // ID
      l = RetiraListaProduto(l, i);
    }

    else if (!strcmp(aa, "IMPRIME_LISTA")) {
      ImprimeListaProdutos(l);
    }  

    else if (!strcmp(aa, "ATUALIZA_PRECO")) {
      fscanf(f, "%d", &j); // ID
      fscanf(f, "%fs", &k); // NOVO PRECO
    }

    else if (!strcmp(aa, "VERIFICA_VALIDADE")) {
      // Ver se algum produto ta fora de validade
      fscanf(f, "%d", &data[0]); // DIA
      fscanf(f, "%d", &data[1]); // MES
      fscanf(f, "%d", &data[2]); // ANO
      l = VerificaListaValidade(l, data[0], data[1], data[2]);
    }

    else if (!strcmp(aa, "VERIFICA_LISTA")) {
      // Ver se o produto ta na lista
      fscanf(f, "%d", &j); // ID
      // int isProductInlist = VerificaListaProduto(l, j); - ERRO
    }

    else if (!strcmp(aa, "ORDENA_LISTA_VALIDADE")) {
      // Ordenar lista por validade
    }

    else if (!strcmp(aa, "ORDENA_LISTA_VALOR")) {
      // Ordenar lista por valor
      // l = OrdenaListaValor(l); - ERRO
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
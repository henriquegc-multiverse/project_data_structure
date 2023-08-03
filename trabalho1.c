#include "estoque.h"
#include <string.h>
#include <time.h>
#include <string.h>

#define BUF_LEN 256

FILE *f;
FILE *f_final;

int main() {
  char aa[20];
  f = fopen("./tests/entrada.txt", "r");
  f_final = fopen("./tests/saida-me.txt", "a");

  if (f_final == NULL) {
    puts("Erro ao abrir o arquivo de escrita!");
    perror(NULL);
  }

  if (f == NULL) {
    puts("Erro ao abrir o arquivo de leitura!");
    perror(NULL);
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
      fscanf(f, "%f", &k); // NOVO PRECO
      l = AtualizaPrecoProduto(l, j, k);
    }

    else if (!strcmp(aa, "VERIFICA_VALIDADE")) {
      fscanf(f, "%d", &data[0]); // DIA
      fscanf(f, "%d", &data[1]); // MES
      fscanf(f, "%d", &data[2]); // ANO
      l = VerificaListaValidade(l, data[0], data[1], data[2]);
    }

    else if (!strcmp(aa, "VERIFICA_LISTA")) {
      fscanf(f, "%d", &j); // ID
      int isProductInlist = VerificaListaProduto(l, j);
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
  fclose(f_final);

  return 0;
}
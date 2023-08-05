#include "estoque.h"
#include <string.h>
#include <time.h>

#define BUF_LEN 256

FILE *f;
FILE *f_final;

int main(int argc, char *argv[]) {
  char reader[20];

  if (argc != 3) {
    printf("\nUso: $ %s <carminho do arquivo de entrada>.txt <caminho do "
           "arquivo de saida>.txt\n",
           argv[0]);
    exit(1);
  }

  f = fopen(argv[1], "r");
  f_final = fopen(argv[2], "a");

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

  Lista *l = CriaLista();

  while (fscanf(f, "%s", reader) == 1) {

    if (!strcmp(reader, "PRODUTO")) {
      fscanf(f, "%s", nome);     // PRODUTO
      fscanf(f, "%d", &id);      // ID
      fscanf(f, "%f", &preco);   // PRECO
      fscanf(f, "%d", &data[0]); // DIA
      fscanf(f, "%d", &data[1]); // MES
      fscanf(f, "%d", &data[2]); // ANO

      Produto *p = CriaProduto(nome, id, preco, data);
      l = InsereListaProduto(l, p);
    }

    else if (!strcmp(reader, "RETIRA")) {
      fscanf(f, "%d", &id); // ID
      l = RetiraListaProduto(l, id);
    }

    else if (!strcmp(reader, "IMPRIME_LISTA")) {
      ImprimeListaProdutos(l);
    }

    else if (!strcmp(reader, "ATUALIZA_PRECO")) {
      fscanf(f, "%d", &id);    // ID
      fscanf(f, "%f", &preco); // NOVO PRECO
      l = AtualizaPrecoProduto(l, id, preco);
    }

    else if (!strcmp(reader, "VERIFICA_VALIDADE")) {
      fscanf(f, "%d", &data[0]); // DIA
      fscanf(f, "%d", &data[1]); // MES
      fscanf(f, "%d", &data[2]); // ANO
      l = VerificaListaValidade(l, data[0], data[1], data[2]);
    }

    else if (!strcmp(reader, "VERIFICA_LISTA")) {
      fscanf(f, "%d", &id); // ID
      int isProductInlist = VerificaListaProduto(l, id);
    }

    else if (!strcmp(reader, "ORDENA_LISTA_VALIDADE")) {
      l = OrdenaListaVencimento(l);
    }

    else if (!strcmp(reader, "ORDENA_LISTA_VALOR")) {
      l = OrdenaListaValor(l);
    }

    else if (!strcmp(reader, "FIM")) {
      break;
    }

    else {
      printf("Comando não reconhecido: %s\n", reader);
    }
  }

  fclose(f);
  fclose(f_final);

  return 0;
}
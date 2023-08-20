#include "estoque.h"
#include <time.h>

struct produto {
  char nome[20];
  int codigo;
  float valor;
  int data[3];
};

struct lista {
  Produto *p;
  Lista *prox;
};

/* Cria lista vazia */
Lista *CriaLista() { return NULL; }

/* Cria um novo produto */
Produto *CriaProduto(char *nome, int codigo, float valor,
                     int *data_de_validade) {
  Produto *p = (Produto *)malloc(sizeof(Produto));

  if (p == NULL) {
    puts("Produto não criado");
    perror(NULL);
  }

  p->codigo = codigo;
  p->valor = valor;

  for (int i = 0; i < sizeof(p->nome); i++) {
    if (i < 3) {
      p->data[i] = *(data_de_validade + i);
    }

    p->nome[i] = *(nome + i);
  }

  return p;
}

/* Insere um produto em uma lista */
Lista *InsereListaProduto(Lista *l, Produto *p) {
  Lista *new_l = (Lista *)malloc(sizeof(Lista));

  fseek(f_final, 0, SEEK_END);

  if (p == NULL) {
    puts("Lista não criada");
    perror(NULL);
  }

  new_l->p = p;
  new_l->prox = l;

  fprintf(f_final, "PRODUTO %s %d ADICIONADO\n", p->nome, p->codigo);

  return new_l;
}

/* Retira um produto de uma determinada lista */
Lista *RetiraListaProduto(Lista *l, int id_produto) {
  Lista *prev = CriaLista();
  Lista *new_l = l;

  fseek(f_final, 0, SEEK_END);

  while (new_l != NULL && new_l->p->codigo != id_produto) {
    prev = new_l;
    new_l = new_l->prox;
  }

  if (new_l == NULL) {
    return l; // Produto não existe
  }

  if (prev == NULL) {
    l = new_l->prox; // Econtrou na primeira
  } else {
    prev->prox = new_l->prox; // O elemento está no meio ou no final
  }

  fprintf(f_final, "PRODUTO %d %s RETIRADO\n", new_l->p->codigo,
          new_l->p->nome);

  free(new_l);
  return l;
}

/* Verifica se um produto está presente em uma determinada lista */
int VerificaListaProduto(Lista *l, int id_produto) {
  Lista *new_l = l;

  for (new_l = l; new_l != NULL; new_l = new_l->prox) {
    if (new_l->p->codigo == id_produto) {
      fprintf(f_final, "PRODUTO %d PRESENTE NA LISTA\n", new_l->p->codigo);
      return 1; // Está presente
    }
  }

  fprintf(f_final, "PRODUTO NAO ENCONTRADO NA LISTA\n");

  return 0;
}

Lista *AtualizaPrecoProduto(Lista *l, int id_produto, float novo_preco) {
  Lista *new_l = l;

  for (new_l = l; new_l != NULL; new_l = new_l->prox) {
    if (new_l->p->codigo == id_produto) {
      new_l->p->valor = novo_preco;
      fprintf(f_final, "PRECO ATUALIZADO %s %d %.1f\n", new_l->p->nome,
              new_l->p->codigo, new_l->p->valor);

      return l; // Está presente
    }
  }

  return l; // Não está presente
}

/* Verifica se existe um produto está vencido em uma determinada lista */
Lista *VerificaListaValidade(Lista *l, int dia, int mes, int ano) {
  Lista *new_l = l;
  int is_one_overdue = 0;

  fseek(f_final, 0, SEEK_END);

  for (new_l = l; new_l != NULL; new_l = new_l->prox) {
    if (ano > new_l->p->data[2]) {
      is_one_overdue = 1;
      fprintf(f_final, "PRODUTO %d %s VENCIDO\n", new_l->p->codigo,
              new_l->p->nome);
      continue;
    }

    // Se passar aqui, o ano já é menor ou igual
    if (new_l->p->data[2] == ano && mes > new_l->p->data[1]) {
      is_one_overdue = 1;
      fprintf(f_final, "PRODUTO %d %s VENCIDO\n", new_l->p->codigo,
              new_l->p->nome);
      continue;
    }

    // Se passar aqui, o ano é menor ou igual e o mês é menor ou igual
    if (new_l->p->data[2] == ano && new_l->p->data[1] == mes &&
        dia > new_l->p->data[0]) {
      is_one_overdue = 1;
      fprintf(f_final, "PRODUTO %s %d VENCIDO\n", new_l->p->nome,
              new_l->p->codigo);
      continue;
    }

    // Se passar aqui, o ano é menor ou igual, e o mês é menor ou igual e o dia
    // é menor ou igual Ou seja, o produto não está vencido OU ele vence hoje
    // Portanto, não está vencido
  }

  if (is_one_overdue != 1) {
    fprintf(f_final, "PRODUTO VENCIDO NAO ENCONTRADO NA LISTA\n");
  }

  return l;
}

/* Imprime todos os produtos de uma lista */
void ImprimeListaProdutos(Lista *l) {
  Lista *new_l = l;

  fseek(f_final, 0, SEEK_END);

  for (new_l = l; new_l != NULL; new_l = new_l->prox) {
    fprintf(f_final, "%s %d %.1f %d %d %d\n", new_l->p->nome, new_l->p->codigo,
            new_l->p->valor, new_l->p->data[0], new_l->p->data[1],
            new_l->p->data[2]);
  }
}

/* Orderna Lista pelo valor do produto */
Lista *OrdenaListaValor(Lista *l) {
  clock_t inicio, fim;
  double tempo_gasto;

  Lista *new_l;

  if (l == NULL) {
    return l;
  }

  inicio = clock();

  for (new_l = l; new_l->prox != NULL; new_l = new_l->prox) {
    Lista *min = new_l;

    for (Lista *j = new_l->prox; j != NULL; j = j->prox) {
      if (j->p->valor < min->p->valor) {
        min = j;
      }
    }

    Produto *aux = new_l->p;
    new_l->p = min->p;
    min->p = aux;
  }
  
  fim = clock();
  tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;

  fprintf(f_tempos, "%f\n", tempo_gasto);

  return l;
}

/* Orderna Lista pelo valor do produto */
Lista *OrdenaListaVencimento(Lista *l) {
  Lista *new_l;

  if (l == NULL) {
    return l;
  }

  for (new_l = l; new_l->prox != NULL; new_l = new_l->prox) {
    Lista *min = new_l;

    for (Lista *j = new_l->prox; j != NULL; j = j->prox) {
      if (j->p->data[2] < min->p->data[2]) {
        min = j;
      }

      if (j->p->data[2] == min->p->data[2] && j->p->data[1] < min->p->data[1]) {
        min = j;
      }

      if (j->p->data[2] == min->p->data[2] &&
          j->p->data[1] == min->p->data[1] && j->p->data[0] < min->p->data[0]) {
        min = j;
      }
    }

    Produto *aux = new_l->p;
    new_l->p = min->p;
    min->p = aux;
  }

  return l;
}

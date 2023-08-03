#include <stdio.h>
#include <stdlib.h>

extern FILE *f_final;

// Tipo que define o produto
typedef struct produto Produto;

// Tipo que define a lista
typedef struct lista Lista;

/* Cria lista vazia */
Lista *CriaLista();

/* Cria um novo produto */
Produto *CriaProduto(char *nome, int codigo, float valor,
                     int *data_de_validade);

/* Insere um produto em uma lista */
Lista *InsereListaProduto(Lista *l, Produto *p);

/* Retira um produto de uma determinada lista */
Lista *RetiraListaProduto(Lista *l, int id_produto);

/* Verifica se um produto está presente em uma determinada lista */
int VerificaListaProduto(Lista *p, int id_produto);

/* Verifica se existe um produto está vencido em uma determinada lista */
Lista *VerificaListaValidade(Lista *p, int d, int m, int y);

/* Atualiza o preço do produto numa determinada lista */
Lista *AtualizaPrecoProduto(Lista *p, int id_produto, float novo_preco);

/* Imprime todos os produtos de uma lista */
void ImprimeListaProdutos(Lista *p);

/* Orderna Lista pelo valor do produto */
Lista *OrdenaListaValor(Lista *p);

/* Orderna Lista pelo valor do produto */
Lista *OrdenaListaVencimento(Lista *p);

/*-------------------------------------------*/

// Função Quick Sort para ordenar a lista
void quickSort(Lista *inicio, Lista *fim);
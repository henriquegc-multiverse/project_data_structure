struct produto {
  char nome[20];
  int codigo;
  float valor;
  int data[3];
}

struct lista {
  Produto *p;
  Lista *prox;
}
#include "lista.h"

FILE *file;

void main(int argc, char *argv[]) {
  for (int i = MIN_LENGTH; i <= MAX_LENGTH; i = i + GAP) {
    char filename[15];
    sprintf(filename, "%s%d%s", "lista-", i / MIN_LENGTH, ".txt");

    file = fopen(filename, "w");

    if (!file) {
      printf("Erro ao abrir o arquivo\n");
      exit(1);
    }

    insertProducts(i);
    insertSortedList();

    fclose(file);
  }
}

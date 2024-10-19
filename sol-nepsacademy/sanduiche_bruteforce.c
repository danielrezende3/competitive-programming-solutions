#include <stdio.h>
int bruteforce(int *pedacos, int num_pedacos, int qnt_sanduiche) {
  int resposta = 0;
  for (int i = 0; i < num_pedacos; i++) {
    int sum = 0;
    for (int j = 0; j < num_pedacos; j++) {
      int indice = i + j;
      int indice2 = 0;
      if (indice > num_pedacos - 1) {
        sum = sum + pedacos[indice2++];
      } else
        sum = sum + pedacos[indice];

      if (sum == qnt_sanduiche) resposta++;
    }
  }
  return resposta;
}
int main() {
  int num_pedacos;
  int qnt_sanduiche;
  scanf("%d %d", &num_pedacos, &qnt_sanduiche);
  int pedacos[num_pedacos];
  for (int i = 0; i < num_pedacos; i++) {
    scanf("%d", &pedacos[i]);
  }

  printf("%d", bruteforce(pedacos,num_pedacos,qnt_sanduiche));
  return 0;
}
#include <stdio.h>
int main() {
  int count;
  int value;
  int total;
  int qnt_operacoes;
  int flag;
  char operat;
  flag = 0;
  qnt_operacoes = 0;
  while (scanf("%d", &count) && count != 0) {
    total = 0;

    // multiplico por causa do tipo de entrada
    for (int i = 0; i < (count * 2) - 1; i++) {
      if (flag == 0) {
        scanf("%d", &value);
        total += value;
        flag = 1;
        continue;
      }
      if (i % 2 == 0) {
        scanf("%d", &value);
        if (operat == '+') {
          total += value;
        } else {
          total -= value;
        }
      } else {
        scanf("%c", &operat);
      }
    }
    flag = 0;
    qnt_operacoes++;
    printf("Teste %d\n%d\n", qnt_operacoes, total);
  }
  return 0;
}
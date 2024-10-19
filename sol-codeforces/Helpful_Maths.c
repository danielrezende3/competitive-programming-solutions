#include <stdio.h>
int main() {
  char string[101];
  int len = 0, k = 0;
  int result[10] = {};
  scanf("%s", string);
  while (string[len] != '\0') {
    if (string[len] == '1') {
      result[1]++;
    }
    if (string[len] == '2') {
      result[2]++;
    }
    if (string[len] == '3') {
      result[3]++;
    }
    len++;
  }
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < result[i]; j++) {
      if (k == len/2) {
        printf("%i", i);
      } else {
        printf("%i+", i);
        k++;
      }
    }
  }

  return 0;
}
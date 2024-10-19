#include <stdlib.h>
#include <stdio.h>
int main() {
  int value, ans;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      scanf("%d", &value);
      if (value == 1) {
        ans = abs(3 - (i + 1)) + abs(3 - (j + 1));
      }
    }
  }
  printf("%d", ans)
  return 0;
}
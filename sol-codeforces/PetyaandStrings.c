#include <ctype.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[]) {
  int ans;
  char palavra1[100];
  char palavra2[100];
  scanf("%s %s", palavra1, palavra2);
  for (size_t i = 0; i < 100; i++) {
    palavra1[i] = tolower(palavra1[i]);
    palavra2[i] = tolower(palavra2[i]);
  }
  ans = strcmp(palavra1, palavra2);
  if (ans > 0) {
    ans = 1;
  } else if (ans < 0) {
    ans = -1;
  }

  printf("%d", ans);
  return 0;
}

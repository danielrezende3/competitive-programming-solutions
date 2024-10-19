#include <stdio.h>

int main() {
  int x, y, z;
  int questions, answer;
  answer = 0;
  scanf("%d", &questions);
  for (int i = 0; i < questions; i++) {
    scanf("%d %d %d", &x, &y, &z);
    if (x + y + z > 1) {
      answer++;
    }
  }
  printf("%d", answer);
}
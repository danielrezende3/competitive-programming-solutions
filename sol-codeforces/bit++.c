#include <stdio.h>
int main() {
  int count, answer;
  char line[3];
  answer = 0;
  scanf("%d", &count);
  for (int i = 0; i < count; i++) {
    scanf(" %c%c%c", &line[0],&line[1],&line[2]);
    if (line[1] == '+') {
      answer++;
    } else {
      answer--;
    }
  }
printf("%d", answer);
  return 0;
}
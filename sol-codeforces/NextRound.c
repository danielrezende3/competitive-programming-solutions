#include <stdio.h>

int main() {
  int n, k, value, answer, compare;
  answer = 0;
  scanf("%d %d", &n, &k);
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &value);
    arr[i] = value;
    if (i == k - 1) {
      compare = value;
    }
  }
  for (int i = 0; i < n; i++) {
    if (arr[i] >= compare && arr[i] > 0) {
      answer++;
    }
  }
  printf("%d", answer);
}
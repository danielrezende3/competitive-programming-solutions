#include <stdio.h>

int main() {
   unsigned long long int n, m, a;
   unsigned long long int answer;
  scanf("%lld %lld %lld", &n, &m, &a);
    answer = ((m+a-1)/a)*((n+a-1)/a);
  printf("%lld", answer);
}

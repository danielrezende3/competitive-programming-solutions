#include <iostream>

using namespace std;
int ans1;
int ans2;
int fibonacci(int n) {
  if (n <= 1) {
    ans2++;
    ans1 += n;
    return n;
  }
  ans2++;
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
  int n, number, temp;

  cin >> n;

  for (int i = 0; i < n; i++) {
    ans1 = 0;
    ans2 = 0;
    cin >> number;
    temp = fibonacci(number);
    cout << "fib(" << number << ") = " << ans2-1 << " calls = " << ans1 << endl;
  }
  return 0;
}

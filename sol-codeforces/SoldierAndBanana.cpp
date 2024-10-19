// link: https://codeforces.com/problemset/problem/546/A

#include <iostream>
using namespace std;

int main() {
  int cost_banana, initial_bananas, n_wants;
  cin >> cost_banana >> initial_bananas >> n_wants;
  int owing = 0;
  int total_price = 0;
  for (int i = 1; i <= n_wants; i++) {
    total_price += i * cost_banana;
  }
  owing = total_price - initial_bananas;
  if (owing < 0) {
    owing = 0;
  }
  cout << owing << endl;
  return 0;
}

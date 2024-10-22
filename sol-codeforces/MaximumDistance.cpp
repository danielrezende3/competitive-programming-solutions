// link: https://codeforces.com/gym/102951/problem/A

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for (auto &&i : x) {
    cin >> i;
  }
  for (auto &&i : y) {
    cin >> i;
  }
  int max_squared = 0;

  for (size_t i = 0; i < n; i++) {
    for (size_t j = i + 1; j < n; j++) {
      int dx = x[i] - x[j];
      int dy = y[i] - y[j];
      int squared = dx * dx + dy * dy;
      max_squared = max(max_squared, squared);
    }
  }
  cout << max_squared << "\n";
}
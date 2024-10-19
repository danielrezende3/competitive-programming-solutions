#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> entraram;
  vector<int> sairam;
  int N, M, value;
  cin >> N;
  for (size_t i = 0; i < N; i++) {
    cin >> value;
    entraram.push_back(value);
  }
  cin >> M;
  for (size_t i = 0; i < M; i++) {
    cin >> value;
    sairam.push_back(value);
  }

  sort(sairam.begin(), sairam.end());
  for (size_t i = 0; i < N; i++) {
    if (binary_search(sairam.begin(), sairam.end(), entraram[i]))
      continue;
    else
      cout << entraram[i] << " ";
  }
}
#include <algorithm>
#include <iostream>
#include <vector>
int compare(std::pair<int, int> a, std::pair<int, int> b) {
  return a.first < b.first;
}
int main() {
  int number;
  std::vector<std::pair<int, int>> vencedores;
  for (int i = 0; i < 3; i++) {
    std::cin >> number;
    vencedores.push_back(std::make_pair(number, i + 1));
  }
  std::sort(vencedores.begin(), vencedores.end(), compare);
  for (int i = 0; i < 3; i++) {
    std::cout << vencedores[i].second << std::endl;
  }

  return 0;
}
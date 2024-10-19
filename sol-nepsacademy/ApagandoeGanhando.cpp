#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
int main() {
  int N, D;
  std::string number;
  while (std::cin >> N >> D && N != 0 && D != 0) {
    int aux = 0;
    std::cin >> number;
    std::stack<int> pilha;
    std::vector<int> vetor;
    for (auto &&c : number) {
      while (!pilha.empty() && pilha.top() < (c - 48) && aux < D) {
        aux++;
        pilha.pop();
      }
      if (pilha.size() < N - D) {
      pilha.push(c - 48);
      }

    }
    while (!pilha.empty()) {
      vetor.push_back(pilha.top());
      pilha.pop();
    }

    for (int i = vetor.size() - 1; i >= 0; i--) {
      std::cout << vetor[i];
    }
    std::cout << "\n";
  }
}
// 6 2
// 103759
// 0 0
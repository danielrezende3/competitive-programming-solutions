#include <iostream>
#include <stack>

int main() {
  bool ok = true;
  int linhas;
  std::string expressao;
  std::stack<char> pilha;
  std::cin >> linhas;
  getchar();
  for (int i = 0; i < linhas; i++) {
    getline(std::cin, expressao);
    for (auto &&c : expressao) {
      if (c == '{')
        pilha.push(c);
      else if (c == '}') {
        if (pilha.empty()) {
          ok = false;
          break;
        } else
          pilha.pop();
      }
    }
  }
  if (!pilha.empty()) ok = false;

  if (ok)
    std::cout << "S";
  else
    std::cout << "N";

  return 0;
}
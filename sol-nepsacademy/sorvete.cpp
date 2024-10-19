#include <algorithm>
#include <iostream>
#include <vector>
int main() {
  int32_t comprimento, qnt_sorveteiros;
  std::pair<int32_t, int32_t> aux;
  std::vector<std::pair<int32_t, int32_t>> sorveteiro;
  std::vector<std::pair<int32_t, int32_t>> resposta;
  std::cin >> comprimento >> qnt_sorveteiros;
  for (int32_t i = 0; i < qnt_sorveteiros; i++) {
    std::cin >> aux.first >> aux.second;
    sorveteiro.push_back(aux);
  }
  sort(sorveteiro.begin(), sorveteiro.end());
  resposta.push_back(sorveteiro[0]);
  for (int i = 0; i < qnt_sorveteiros; i++) {
    aux = resposta.back();
    if (sorveteiro[i].first > aux.second) {
      resposta.push_back(sorveteiro[i]);
    } else if (sorveteiro[i].second > aux.second) {
      aux.second = sorveteiro[i].second;
      resposta.pop_back();
      resposta.push_back(aux);
    }
  }
  for (size_t i = 0; i < resposta.size(); i++) {
    std::cout << resposta[i].first << " " << resposta[i].second << std::endl;
  }

  return 0;
}
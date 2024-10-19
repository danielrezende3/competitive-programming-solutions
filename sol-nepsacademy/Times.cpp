#include <bits/stdc++.h>
bool sortbysec(const std::pair<std::string, int> a,
               std::pair<std::string, int> b) {
  return a.second < b.second;
}
int main() {
  int qnt_alunos, qnt_formacao_times;
  std::pair<std::string, int> tmp;
  std::cin >> qnt_alunos >> qnt_formacao_times;

  std::vector<std::pair<std::string, int>> alunos;
  for (size_t i = 0; i < qnt_alunos; i++) {
    std::cin >> tmp.first >> tmp.second;
    alunos.push_back(tmp);
  }
  sort(alunos.begin(), alunos.end(), sortbysec);
  std::vector<std::vector<std::string>> times;
  times.resize(qnt_formacao_times);
  for (size_t i = 0; i < qnt_alunos; i++) {
    times[i % qnt_formacao_times].push_back(alunos[alunos.size() - 1].first);
    alunos.pop_back();
  }
  for (int i = 0; i < qnt_formacao_times; i++) {
    sort(times[i].begin(), times[i].end());
    std::cout << "Time " << i + 1 << std::endl;
    for (int j = 0; j < times[i].size(); j++) {
      std::cout << times[i][j] << std::endl;
    }
  }

  return 0;
}
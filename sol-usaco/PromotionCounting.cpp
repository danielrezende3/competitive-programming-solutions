// https://usaco.org/index.php?page=viewproblem2&cpid=591

#include <fstream>
#include <iostream>
using namespace std;
int main() {
  std::string file_name = "promote";
  ifstream fin(file_name + ".in");
  ofstream fout(file_name + ".out");

  int bronze_before, bronze_after, silver_before, silver_after, gold_before,
      gold_after, platinum_before, platinum_after;
  fin >> bronze_before >> bronze_after >> silver_before >> silver_after >>
      gold_before >> gold_after >> platinum_before >> platinum_after;

  int bronze_to_silver = 0, silver_to_gold = 0, gold_to_plat = 0;
  int total_after = bronze_after + silver_after + gold_after + platinum_after;
  int total_before =
      bronze_before + silver_before + gold_before + platinum_before;
  int faltam = total_after - total_before;

  // primeira rodada
  faltam += bronze_before - bronze_after;
  bronze_to_silver = faltam;
  // segunda rodada
  faltam += silver_before - silver_after;
  silver_to_gold = faltam;

  // terceira rodada
  faltam += gold_before - gold_after;
  gold_to_plat = faltam;

  fout << bronze_to_silver << "\n" << silver_to_gold << "\n" << gold_to_plat;

  return 0;
}

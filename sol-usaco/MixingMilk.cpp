// link https://usaco.org/index.php?page=viewproblem2&cpid=891

#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string file_name = "mixmilk";
  ifstream fin(file_name + ".in");
  ofstream fout(file_name + ".out");

  int c_1, m_1, c_2, m_2, c_3, m_3;

  fin >> c_1 >> m_1 >> c_2 >> m_2 >> c_3 >> m_3;
  int text = (14 + 13) % c_3;
  array<int, 3> curr_milk_arr{m_1, m_2, m_3};
  array<int, 3> cap_milk_arr{c_1, c_2, c_3};

  for (int i = 0; i < 100; i++) {
    int pos = i % 3;
    int next_pos = (i + 1) % 3;
    int cap_milk = cap_milk_arr[next_pos];
    int total_milk = curr_milk_arr[pos] + curr_milk_arr[next_pos];
    if (total_milk > cap_milk) {
      int leftover = total_milk - cap_milk;
      curr_milk_arr[pos] = leftover;
      curr_milk_arr[next_pos] = cap_milk;
    } else {
      curr_milk_arr[pos] = 0;
      curr_milk_arr[next_pos] = total_milk;
    }
  }
  for (auto &&curr_milk_arr : curr_milk_arr) {
    fout << curr_milk_arr << "\n";
  }
  return 0;
}

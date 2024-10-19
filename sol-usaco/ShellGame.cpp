// link https://usaco.org/index.php?page=viewproblem2&cpid=891

#include <algorithm>
#include <array>
#include <fstream>
#include <vector>
using namespace std;

void change_pos(array<int, 3>& arr, int a, int b) {
  int tmp = arr[a - 1];
  arr[a - 1] = arr[b - 1];
  arr[b - 1] = tmp;
}
int main() {
  string file_name = "shell";
  ifstream fin(file_name + ".in");
  ofstream fout(file_name + ".out");

  int n_swaps, a, b, g;
  fin >> n_swaps;
  array<int, 3> corr_pos{};
  array<int, 3> x{1, 0, 0};
  array<int, 3> y{0, 1, 0};
  array<int, 3> z{0, 0, 1};
  for (int i = 0; i < n_swaps; i++) {
    fin >> a >> b >> g;
    change_pos(x, a, b);
    change_pos(y, a, b);
    change_pos(z, a, b);
    if (x[g - 1] == 1) {
      corr_pos[0] += 1;
    }
    if (y[g - 1] == 1) {
      corr_pos[1] += 1;
    }
    if (z[g - 1] == 1) {
      corr_pos[2] += 1;
    }
  }
  int max_number = *max_element(corr_pos.begin(), corr_pos.end());
  fout << max_number << "\n";
  return 0;
}

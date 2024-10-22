// link https://usaco.org/index.php?page=viewproblem2&cpid=568

#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
  string file_name = "speeding";
  ifstream fin(file_name + ".in");
  ofstream fout(file_name + ".out");

  int n, m;
  fin >> n >> m;

  vector<pair<int, int>> road_segment;
  vector<pair<int, int>> journey;
  for (int i = 0; i < n; i++) {
    int length, speed_limit;
    fin >> length >> speed_limit;

    road_segment.push_back(make_pair(length, speed_limit));
  }
  for (int i = 0; i < m; i++) {
    int length, speed_limit;
    fin >> length >> speed_limit;

    road_segment.push_back(make_pair(length, speed_limit));
  }
  return 0;
}

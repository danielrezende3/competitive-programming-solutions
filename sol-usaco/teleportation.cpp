// https://usaco.org/index.php?page=viewproblem2&cpid=807

#include <fstream>
void sort_x_y(int &x, int &y) {
  if (x > y) {
    int temp = x;
    x = y;
    y = temp;
  }
}

int give_solution(int a, int b, int x, int y) {
  int path_1 = abs(a - b);
  int path_2 = abs(a - x) + abs(b - y);
  int path_3 = abs(a - y) + abs(b - x);
  int path_teleport = (path_2 < path_3) ? path_2 : path_3;

  if (path_1 <= path_teleport) {
    return path_1;
  } else {
    return path_teleport;
  }
}

int main(int argc, char const *argv[]) {
  std::ifstream fin("teleport.in");
  std::ofstream fout("teleport.out");
  int a, b, x, y;
  fin >> a >> b >> x >> y;
  int solution = give_solution(a, b, x, y);
  fout << solution << std::endl;

  return 0;
}

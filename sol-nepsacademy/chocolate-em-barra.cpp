#include <iostream>
int which_quadrant(int x, int y, int n) {
  if ((x <= n / 2) && (y <= n / 2)) {
    return 1;
  } else if ((x > n / 2) && (y <= n / 2)) {
    return 2;
  } else if ((x <= n / 2) && (y > n / 2)) {
    return 3;
  } else if ((x > n / 2) && (y > n / 2)) {
    return 4;
  }
  return 0;
}

int main() {
  int x, y, n;
  int test_a, test_b;
  ;
  std::pair<int, int> a;
  std::pair<int, int> b;

  std::cin >> n;
  std::cin >> x >> y;
  a.first = x;
  a.second = y;
  std::cin >> x >> y;
  b.first = x;
  b.second = y;
  test_a = which_quadrant(a.first, a.second, n);
  test_b = which_quadrant(b.first, b.second, n);

  if (test_a == test_b) {
    std::cout << "N";
  } else {
    std::cout << "S";
  }

  return 0;
}
// test case
// 6
//
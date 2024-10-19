#include <iostream>
void print2darr(int **arr, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << arr[i][j];
    }
    std::cout << std::endl;
  }
}
int main() {
  int n, number;
  std::cin >> n;
  int arr[n][n];
  int sum_diagonal = 0;
  int sum_diagonal_inv = 0;
  int resp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> number;
      arr[i][j] = number;
      if (i == j) {
        sum_diagonal += number;
      }
      if (i == (n - 1 - j)) {
        sum_diagonal_inv += number;
      }
    }
  }
  if (sum_diagonal != sum_diagonal_inv) {
    resp = 0;
    std::cout << "-1";
    return 1;
  }

  for (int i = 0; i < n; i++) {
    int sum_horizontal = 0;
    int sum_vertical = 0;
    for (int j = 0; j < n; j++) {
      sum_horizontal += arr[i][j];
      sum_vertical += arr[j][i];
    }
    if (sum_horizontal != sum_diagonal || sum_vertical != sum_diagonal) {
      std::cout << "-1";
      return 2;
    }
  }
  std::cout << sum_diagonal;
  return 0;
}
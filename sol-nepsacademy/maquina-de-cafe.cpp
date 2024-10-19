#include <algorithm>
#include <iostream>

int comp(int a, int b) { return (a < b); }
int main() {
  int arr[3], resp[3];
  int n = sizeof(arr) / sizeof(arr[0]);
  for (int i = 0; i < 3; i++) {
    std::cin >> arr[i];
  }
  resp[0] = arr[1] * 2 + arr[2] * 4;
  resp[1] = arr[0] * 2 + arr[2] * 2;
  resp[2] = arr[0] * 4 + arr[1] * 2;
  std::sort(resp, resp + n);
  std::cout << resp[0];
}
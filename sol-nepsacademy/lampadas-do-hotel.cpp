#include <iostream>
int main() {
  int I_a, I_b, F_a, F_b;
  std::cin >> I_a >> I_b >> F_a >> F_b;
  if (I_a == F_a && I_b == F_b) {
    std::cout << "0";
  }
  if (I_a == F_a && I_b != F_b) {
    std::cout << "2";
  }
  if (I_a != F_a) {
    std::cout << "1";
  }
}
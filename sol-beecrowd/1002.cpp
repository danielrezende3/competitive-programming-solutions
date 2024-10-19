#include <iomanip>
#include <iostream>
int main() {
  double a, sum;
  double pi = 3.14159;
  std::cin >> a;
  sum = pi * a * a;
  std::cout << std::fixed;
  std::cout << "A=" << std::setprecision(4) << sum << std::endl;
  return 0;
}

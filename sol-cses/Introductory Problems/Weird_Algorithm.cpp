#include <iostream>
#include <cstdint>

int64_t getNumber() {
  int64_t number{};
  std::cin >> number;
  return number;
}
void algo(int64_t number) {
  while (number != 1 && number >= 1) {
    std::cout << number << ' ';
    if (number % 2 == 0) {
      number /= 2;
    } else {
      number = (number * 3) + 1;
    }
  }
  std::cout << 1;
}
int main() {
  int64_t number{getNumber()};
  algo(number);
}
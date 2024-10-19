#include <iostream>

int main() {
  int A, B, C;
  std::cin >> A >> B >> C;
  if (A == B && A == C) {
    std::cout << "*";
  } else if (A == B && A != C) {
    std::cout << "C";
  } else if (A == C && A != B) {
    std::cout << "B";
  } else {
    std::cout << "A";
  }
}
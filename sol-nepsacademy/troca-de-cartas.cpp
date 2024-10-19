#include <algorithm>
#include <iostream>
#include <set>

int comp_bigger(int a, int b) { return a < b ? 0 : 1; }
int main() {
  int A, B, number;
  int count;
  std::set<int> set_A;
  std::set<int> set_B;
  std::set<int> intersection;
  std::cin >> A >> B;
  for (int i = 0; i < A; i++) {
    std::cin >> number;
    set_A.insert(number);
  }
  for (int i = 0; i < B; i++) {
    std::cin >> number;
    set_B.insert(number);
  }
  std::set_intersection(set_A.begin(), set_A.end(), set_B.begin(), set_B.end(),
                        std::inserter(intersection, intersection.begin()));

  count = comp_bigger(set_A.size(), set_B.size());
  if (count == 0) {
    std::cout << set_A.size() - intersection.size();
  } else {
    std::cout << set_B.size() - intersection.size();
  }
}
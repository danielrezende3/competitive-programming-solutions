#include <iostream>
#include <set>
int main() {
  std::set<int> mySet;
  int count, number, fab_pieces = 0;
  std::cin >> count;

  for (auto i = 0; i < count; i++) {
    std::cin >> number;
    auto search = mySet.find(number);
    if (search != mySet.end()) {
      mySet.erase(number);
    } else {
      mySet.insert(number);
      fab_pieces += 2;
    }
  }
  std::cout << fab_pieces << std::endl;
  return 0;
}
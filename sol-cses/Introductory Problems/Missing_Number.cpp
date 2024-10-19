#include <iostream>
#include <vector>
using namespace std;

int main() {
  int count;
  cin >> count;
  vector<int> arr(count + 1, 0);

  int number;
  for (int i = 0; i < count - 1; i++) {
    cin >> number;
    arr[number]++;
  }
  for (int i = 1; i < count + 1; i++) {
    if (arr[i] == 0) {
      cout << i << endl;
    }
  }
  return 0;
}

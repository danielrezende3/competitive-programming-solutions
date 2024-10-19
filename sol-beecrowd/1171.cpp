#include <iostream>
using namespace std;
#define TAMANHO 2001
int main() {
  int count;
  int value;
  int arr[TAMANHO] = {0};
  cin >> count;
  for (int i = 0; i < count; i++) {
    cin >> value;
    arr[value]++;
  }
  for (int i = 0; i < TAMANHO; i++) {
    if (arr[i] > 0) {
      cout << i << " aparece " << arr[i] << " vez(es)" << endl;
    }
  }

  return 0;
}
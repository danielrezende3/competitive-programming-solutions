#include <bits/stdc++.h>
using namespace std;

int min(int a, int b) { return a < b ? a : b; }

int main() {
  int matriz[61][2] = {0};
  int resp;
  char orientation;
  int count;
  int size;

  while (cin >> count) {
    memset(matriz,0, sizeof(matriz));
    resp = 0;
    for (int i = 0; i < count; i++) {
      cin >> size;
      cin >> orientation;
      if (orientation == 'E') {
        matriz[size][0]++;
      } else if (orientation == 'D') {
        matriz[size][1]++;
      }
    }

    for (int i = 0; i < 61; i++) {
      resp += min(matriz[i][0], matriz[i][1]);
    }
    cout << resp << endl;
  }

  return 0;
}
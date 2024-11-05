#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> substances;

  for (int i = 0; i < n; i++) {
    int temp_1, temp_2;
    cin >> temp_1 >> temp_2;
    substances.push_back({temp_1, temp_2});
  }

  for (int T1 = -100; T1 <= 100; T1++) {
    for (int T2 = T1; T2 <= 100; T2++) {
      bool is_valid = true;

      for (auto& substance : substances) {
        int a = substance.first;
        int b = substance.second;

        if (!((a <= T1 && T1 <= b) || (a <= T2 && T2 <= b))) {
          is_valid = false;
          break;
        }
      }

      if (is_valid) {
        cout << T1 << " " << T2;
        return 0;
      }
    }
  }

  cout << -1;
  return 0;
}

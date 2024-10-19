#include <iostream>
using namespace std;

int main() {
  int n;
  int perDayCost;
  int revenue[1001];
  int profit;
  int ans;
  int temp;
  while (cin >> n && n != EOF) {
    ans = 0;
    cin >> perDayCost;
    for (int i = 0; i < n; i++) {
      cin >> revenue[i];
    }
    for (int i = 0; i < n; i++) {
      profit = 0;
      for (int j = i; j < n; j++) {
        profit += revenue[j];
        temp = profit - ((j-i+1) * perDayCost);
        if (temp > ans) {
          ans = temp;
        }
      }
    }

    cout << ans << endl;
  }

  return 0;
}

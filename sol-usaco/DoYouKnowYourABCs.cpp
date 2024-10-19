// https://usaco.org/index.php?page=viewproblem2&cpid=1059

#include <iostream>
#include <map>
using namespace std;
int main() {
  int x;
  map<int, int> a;
  for (int i = 0; i < 7; i++) {
    cin >> x;
    a[x]++;
  }
  // 3 iguais
  if (a.size() == 3) {
    x = a.begin()->first;
    cout << x << " " << x << " " << x << endl;
  }
  // 3 diferentes
  if (a.size() == 6) {
    cout << a.begin()->first << " " << (++a.begin())->first << " "
         << (++(++a.begin()))->first << endl;
  }
  // 2 iguais, 1 diferente
  
}

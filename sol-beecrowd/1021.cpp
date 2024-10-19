#include <bits/stdc++.h>
using namespace std;
int main() {
  double value;
  int monetary_value;
  int aux;
  cin >> value;
  aux = value;
  cout << "NOTAS:" << endl;
  // 576.73
  monetary_value = value / 100;
  aux = aux%100;
  value = value - monetary_value * 100;
  cout << monetary_value << " nota(s) de R$ 100.00" << endl;
  // 50
  monetary_value = value / 50;
  value = value - monetary_value * 50;
  cout << monetary_value << " nota(s) de R$ 50.00" << endl;
  // 20
  monetary_value = value / 20;
  value = value - monetary_value * 20;
  cout << monetary_value << " nota(s) de R$ 20.00" << endl;
  // 10
  monetary_value = value / 10;
  value = value - monetary_value * 10;
  cout << monetary_value << " nota(s) de R$ 10.00" << endl;
  // 5
  monetary_value = value / 5;
  value = value - monetary_value * 5;
  cout << monetary_value << " nota(s) de R$ 5.00" << endl;
  // 2
  monetary_value = value / 2;
  value = value - monetary_value * 2;
  cout << monetary_value << " nota(s) de R$ 2.00" << endl;

  cout << "MOEDAS:" << endl;
  // 1
  monetary_value = value / 1;
  value = value - monetary_value * 1;
  cout << monetary_value << " moeda(s) de R$ 1.00" << endl;
  // 0.50
  monetary_value = value / 0.50;
  value = value - monetary_value * 0.50;
  cout << monetary_value << " moeda(s) de R$ 0.50" << endl;
  // 0.25
  monetary_value = value / 0.25;
  value = value - monetary_value * 0.25;
  cout << monetary_value << " moeda(s) de R$ 0.25" << endl;
  // 0.10
  monetary_value = value / 0.10;
  value = value - monetary_value * 0.10;
  cout << monetary_value << " moeda(s) de R$ 0.10" << endl;
  // 0.05
  monetary_value = value / 0.05;
  value = value - monetary_value * 0.05;
  cout << monetary_value << " moeda(s) de R$ 0.05" << endl;
  // 0.01
  monetary_value = value / 0.01;
  value = value - monetary_value * 0.01;
  cout << monetary_value << " moeda(s) de R$ 0.01" << endl;

  return 0;
}
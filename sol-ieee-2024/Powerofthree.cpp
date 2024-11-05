// NOTE: Used the help of AI
// links:
// - https://www.youtube.com/watch?v=dJZR8_s7t_8
// - https://www.youtube.com/watch?v=hkneV9hW22o
// - https://www.cuemath.com/numbers/divisibility-rule-of-3/
#include <bits/stdc++.h>
using namespace std;

bool is_divisible_by_3(const string& number) {
  int sum = 0;
  for (char i : number) {
    sum += (i - '0');
  }
  return sum % 3 == 0;
}

string divide_by_3(const string& num) {
  string result;
  int carry = 0;
  for (char digit : num) {
    int current = carry * 10 + (digit - '0');
    result += (current / 3) + '0';
    carry = current % 3;
  }
  return result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));
}
int main() {
  string n;
  int resp = -1;
  int x = 0;

  cin >> n;  

  if (n == "0") {
    cout << -1;
    return 0;
  }

  while (is_divisible_by_3(n)) {
    n = divide_by_3(n); 
    x++;
  }

  if (n == "1") {
    resp = x;
  }

  cout << resp;
}

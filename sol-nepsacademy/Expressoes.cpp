#include <bits/stdc++.h>
using namespace std;

int main() {
  int count;
  cin >> count;

  for (int i = 0; i < count; i++) {
    string palavra;
    stack<char> pilha;
    bool flag = true;  // true
    cin >> palavra;
    for (char c : palavra) {
      if (c == '{' || c == '[' || c == '(') {
        pilha.push(c);
      } else if (!pilha.empty() && pilha.top() == '{' && c == '}') {
        pilha.pop();
      } else if (!pilha.empty() && pilha.top() == '[' && c == ']') {
        pilha.pop();
      } else if (!pilha.empty() && pilha.top() == '(' && c == ')') {
        pilha.pop();
      } else {
        flag = false;
        break;
      }
    }

    if (pilha.size() == 0 && flag == true) {
      cout << "S\n";
    } else {
      cout << "N\n";
    }
  }

  return 0;
}
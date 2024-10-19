#include <iostream>
using namespace std;

void resultado(int a, int b) {
  cout << "O JOGO DUROU " << a << " HORA(S) E " << b << " MINUTO(S)" << endl;
}

// NOTE: knowing that the game can begin in a day and finish in another day
// NOTE: horas podem ser ==, <, >, tratar cada um dos tres casos, totalizando 9
// casos possiveis.
int main() {
  int total_horas, total_min, init_total, final_total, hole_day;
  int init_hour, init_min, final_hour, final_min;
  hole_day = 24*60;
  cin >> init_hour >> init_min >> final_hour >> final_min;
  init_hour *= 60;
  final_hour *= 60;
  init_total = init_hour + init_min;
  final_total = final_hour + final_min;
  // check if are the same, it knows its during the hole day
  if (init_total == final_total) {
    resultado(24, 0);
    return 0;
  }
  if (final_total > init_total) {
    total_horas = (final_total - init_total) / 60;
    total_min = (final_total - init_total) % 60;
  } else {
    total_horas = ((final_total - init_total)+hole_day) / 60;
    total_min = ((final_total - init_total)+hole_day)  % 60;
  }
  resultado(total_horas, total_min);
  //checagens:
  // 7 7 7 7 OK!
  // 7 8 9 10 OK!
  // 7 10 8 9 OK!

  return 0;
}
#include <iostream>

using namespace std;

int main() {
    int hh, pp, ff, dd;
    cin >> hh >> pp >> ff >> dd;

    // Calcula a distância entre o fugitivo e o policial em cada direção
    int dist_horario = (hh - ff + 16) % 16;
    int dist_antihorario = (ff - hh + 16) % 16;

    // Verifica se o fugitivo consegue chegar no helicóptero sem passar pelo policial
    if ((dd == -1 && dist_horario > dist_antihorario) || (dd == 1 && dist_horario < dist_antihorario)) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }

    return 0;
}

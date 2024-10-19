#include <iostream>
using namespace std;

const int MAXN = 1010;  // A maior quantidade de elementos que esperamos ler

int parent[MAXN];  // parent[i] = pai do i-ésimo valor

int find(int value)  // Essa função irá retornar o representante de x
{
  if (parent[value] == value)  // Checa se x é um representante
    return value;
  return find(parent[value]);
}
// Essa função irá fazer a fusão dos conjuntos que contém i e j
void merge(int i, int j) {
  i = find(i);
  j = find(j);  // Acha o representante dos dois conjuntos

  if (i != j)       // Checa se eles não estão no mesmo conjunto já
    parent[i] = j;  // Junta os dois conjuntos criando uma nova ligação
}

int main() {
  int n, q;

  // Lê o número de conjuntos e o número de perguntas
  cin >> n >> q;
  
  // Inicializa cada valor como a raiz de seu próprio conjunto
  for (int i = 0; i < n; i++) parent[i] = i;

  for (int i = 0; i < q; i++) {
    int type, a, b;

    // Lê a descrição de uma pergunta
    cin >> type >> a >> b;

    if (type == 1)
      merge(a, b);
    else {
      if (find(a) == find(b))
        cout << "Mesmo conjunto" << endl;
      else
        cout << "Conjuntos diferentes" << endl;
    }
  }
}

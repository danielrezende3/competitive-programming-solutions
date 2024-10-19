#include <iostream>

int main() {
  int menor;
  int arr[10];
  int ocorrencias[10] = {0};
  menor = 100;
  int j = 0;
  for (int i = 0; i < 10; i++) {
    std::cin >> arr[i];
    if (arr[i] < menor) {
      menor = arr[i];
      j = 0;
    }
    if (arr[i] == menor) {
      ocorrencias[j++] = i;
    }
  }
  std::cout << "Menor: " << menor << std::endl;

  std::cout << "Ocorrencias: ";
  for (int i = 0; i < j; i++) {
    std::cout << ocorrencias[i] << " ";
  }

std::cout << std::endl;
for (int i = 0; i < 10; i++) {
  if (arr[i] == menor) {
    arr[i] = -1;
  }
  std::cout << arr[i] << " ";
}
return 0;
}

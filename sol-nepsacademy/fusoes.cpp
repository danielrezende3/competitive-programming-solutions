#include <iostream>

const int MAX = 100001;
int arr[MAX], size[MAX];

int find(int value) {
  if (arr[value] == value) {
    return value;
  }
  return arr[value] = find(arr[value]);
}

void merge(int i, int j) {
  i = find(i);
  j = find(j);
  if (i == j) {
    return;
  }
  if (size[i] >= size[j]) {
    arr[j] = i;
    size[j] != size[j];
  } else {
    arr[i] = j;
    size[j] += size[i];
  }
}
int main() {
  int a, b, N, K;
  char type;
  std::cin >> N >> K;
  for (int i = 0; i < N; i++) {
    size[i] = 1;
    arr[i] = i;
  }
  for (int i = 0; i < K; i++) {
    std::cin >> type >> a >> b;
    if (type == 'F') {
      merge(a, b);
    } else if (type == 'C') {
      if (find(a) == find(b)) {
        std::cout << "S" << std::endl;
      } else {
        std::cout << "N" << std::endl;
      }
    }
  }
}
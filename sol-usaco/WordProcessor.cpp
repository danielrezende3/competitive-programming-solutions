// link https://usaco.org/index.php?page=viewproblem2&cpid=987

#include <fstream>
#include <vector>
using namespace std;

int main() {
  string file_name = "word";
  ifstream fin(file_name + ".in");
  ofstream fout(file_name + ".out");

  int n_words, max_length;

  fin >> n_words >> max_length;

  vector<string> response;
  string buffer_content;
  int buffer_size = 0;
  string word;
  for (int i = 0; i < n_words; i++) {
    fin >> word;
    buffer_size += word.length();
    if (buffer_size <= max_length) {
      if (buffer_content.empty()) {
        buffer_content += word;
      } else {
        buffer_content += " " + word;
      }
    } else {
      buffer_size = word.length();
      response.push_back(buffer_content);
      buffer_content = word;
    }
  }
  if (!buffer_content.empty()) {
    response.push_back(buffer_content);
  }
  for (string str : response) {
    fout << str << "\n";
  }

  return 0;
}

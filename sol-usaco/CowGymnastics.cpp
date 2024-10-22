// link: https://usaco.org/index.php?page=viewproblem2&cpid=963

#include <bits/stdc++.h>
using namespace std;
int main() {
  string file_name = "gymnastics";
  ifstream fin(file_name + ".in");
  ofstream fout(file_name + ".out");

  int num_sessions, num_cows, cow_id;

  fin >> num_sessions >> num_cows;
  vector<int> rankings;

  // Read all the rankings from each practice session
  for (int session = 0; session < num_sessions; session++) {
    for (int cow = 0; cow < num_cows; cow++) {
      fin >> cow_id;
      rankings.push_back(cow_id);
    }
  }

  int consistent_pairs = 0;

  // Iterate over each cow to find consistent pairs
  for (int current_cow = 1; current_cow <= num_cows; current_cow++) {
    set<int> better_than_current;

    for (int session = 0; session < num_sessions; session++) {
      int cow_position_in_session = num_cows * (session + 1);

      for (int cow_in_session = session * num_cows;
           cow_in_session < num_cows * (session + 1); cow_in_session++) {
        if (rankings[cow_in_session] == current_cow) {
          cow_position_in_session = cow_in_session;
        }
        if (cow_in_session < cow_position_in_session) {
          better_than_current.insert(rankings[cow_in_session]);
        }
      }
    }

    consistent_pairs += num_cows - better_than_current.size() - 1;
  }

  fout << consistent_pairs << "\n";
}

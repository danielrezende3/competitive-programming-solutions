// link https://usaco.org/index.php?page=viewproblem2&cpid=568

#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <deque>
#include <cassert>
using namespace std;

int speeding_ticket(deque<pair<int, int>> road_segment, deque<pair<int, int>> journey)
{
  int speed_limit_exceeded = 0;

  auto curr_road = road_segment.front();
  auto curr_journey = journey.front();

  while (!road_segment.empty() && !journey.empty())
  {
    if (curr_journey.second > curr_road.second)
    {
      speed_limit_exceeded = max(speed_limit_exceeded, curr_journey.second - curr_road.second);
    }
    if (curr_journey.first == curr_road.first)
    {
      journey.pop_front();
      road_segment.pop_front();
      if (!road_segment.empty() && !journey.empty())
      {
        curr_road = road_segment.front();
        curr_journey = journey.front();
      }
    }
    else if (curr_journey.first > curr_road.first)
    {
      curr_journey.first -= curr_road.first;
      road_segment.pop_front();
      if (!road_segment.empty())
      {
        curr_road = road_segment.front();
      }
    }
    else if (curr_journey.first < curr_road.first)
    {
      curr_road.first -= curr_journey.first;
      journey.pop_front();
      if (!journey.empty())
      {
        curr_journey = journey.front();
      }
    }
  }
  return speed_limit_exceeded;
}

void test_speeding_ticket()
{
  deque<pair<int, int>> road_segment = {{40, 75}, {50, 35}, {10, 45}};
  deque<pair<int, int>> journey = {{40, 76}, {20, 30}, {40, 40}};

  int result = speeding_ticket(road_segment, journey);
  int expected = 5;
  assert(result == expected);

  cout << "Test passed!" << endl;
}

int main()
{
  // test_speeding_ticket();
  string file_name = "speeding";
  ifstream fin(file_name + ".in");
  ofstream fout(file_name + ".out");

  int n, m;
  fin >> n >> m;

  deque<pair<int, int>> road_segment;
  deque<pair<int, int>> journey;
  for (int i = 0; i < n; i++)
  {
    int length, speed_limit;
    fin >> length >> speed_limit;

    road_segment.push_back(make_pair(length, speed_limit));
  }
  for (int i = 0; i < m; i++)
  {
    int length, speed_limit;
    fin >> length >> speed_limit;

    journey.push_back(make_pair(length, speed_limit));
  }
  fout << speeding_ticket(road_segment, journey);

  return 0;
}

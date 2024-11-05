#include <bits/stdc++.h>
using namespace std;
// https://victorlecomte.com/cp-geo.pdf
//  pag 40 orient
//  pag 55 properinter
struct Point {
  int x;
  int y;
  Point operator-(Point p) { return {x - p.x, y - p.y}; }
  Point operator*(double d) { return {x * d, y * d}; }
  Point operator/(double d) { return {x / d, y / d}; }
};
struct Segment {
  Point start, end;
};

// Cross product of vectors ab and ac
long crossProduct(const Point& a, const Point& b, const Point& c) {
  return (1L * (b.x - a.x) * (c.y - a.y)) - (1L * (b.y - a.y) * (c.x - a.x));
}

// Check if point c and point d are on different sides of line ab
bool onDifferentSides(const Point& a, const Point& b, const Point& c,
                      const Point& d) {
  long cross1 = crossProduct(a, b, c);
  long cross2 = crossProduct(a, b, d);
  return (cross1 * cross2) < 0;
}

// Check if two segments intersect
bool segmentsIntersect(const Segment& seg1, const Segment& seg2) {
  return onDifferentSides(seg1.start, seg1.end, seg2.start, seg2.end) &&
         onDifferentSides(seg2.start, seg2.end, seg1.start, seg1.end);
}
// NEW WAY TO PROCESS
double cross(Point v, Point w) { return v.x * w.y - v.y * w.x; }
double orient(Point a, Point b, Point c) { return cross(b - a, c - a); }
bool properInter(Point a, Point b, Point c, Point d, Point& out) {
  double oa = orient(c, d, a), ob = orient(c, d, b), oc = orient(a, b, c),
         od = orient(a, b, d);
  // Proper intersection exists iff opposite signs
  if (oa * ob < 0 && oc * od < 0) {
    out = (a * ob - b * oa) / (ob - oa);
    return true;
  }
  return false;
}
int main() {
  int l, n, m;
  cin >> l >> n >> m;

  int value;
  char letter;
  vector<Segment> coordenates;
  for (int i = 0; i < n; i++) {
    cin >> letter >> value;
    if (letter == 'U') {
      coordenates.push_back({{0, 0}, {value, l}});
    } else if (letter == 'R') {
      coordenates.push_back({{0, 0}, {l, value}});
    }
  }
  for (int i = 0; i < m; i++) {
    cin >> letter >> value;
    if (letter == 'U') {
      coordenates.push_back({{30, 0}, {value, l}});
    } else if (letter == 'L') {
      coordenates.push_back({{30, 0}, {l, value}});
    }
  }
  int intersections = 0;
  for (auto&& i : coordenates) {
    for (auto&& j : coordenates) {
      intersections += segmentsIntersect(i, j);
    }
  }
  int size = coordenates.size();
  int response = coordenates.size() + 1 + intersections;
  cout << response;
  return 0;
}

{{0,0},{10,30}}
{{0,0},{25,30}}
{{0,0},{30,10}}
{{30,0},{30,15}}
{{30,0},{20,30}}
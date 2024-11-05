#include <iostream>
#include <optional>
#include <vector>

struct Point {
  double x, y;
};

std::optional<Point> segmentIntersection(Point A, Point B, Point C, Point D) {
  double a1 = B.y - A.y;
  double b1 = A.x - B.x;
  double c1 = a1 * A.x + b1 * A.y;

  double a2 = D.y - C.y;
  double b2 = C.x - D.x;
  double c2 = a2 * C.x + b2 * C.y;

  double determinant = a1 * b2 - a2 * b1;

  if (determinant == 0) {
    // Lines are parallel or coincident
    return std::nullopt;
  }

  double x = (b2 * c1 - b1 * c2) / determinant;
  double y = (a1 * c2 - a2 * c1) / determinant;

  auto isBetween = [](double a, double b, double c) {
    return (a <= b && b <= c) || (c <= b && b <= a);
  };

  if (isBetween(A.x, x, B.x) && isBetween(A.y, y, B.y) &&
      isBetween(C.x, x, D.x) && isBetween(C.y, y, D.y)) {
    return Point{x, y};
  }

  return std::nullopt;
}

int countIntersections(const std::vector<std::pair<Point, Point>>& segments) {
  int intersectionCount = 0;

  for (size_t i = 0; i < segments.size(); ++i) {
    for (size_t j = i + 1; j < segments.size(); ++j) {
      if (segmentIntersection(segments[i].first, segments[i].second,
                              segments[j].first, segments[j].second)) {
        ++intersectionCount;
      }
    }
  }

  return intersectionCount;
}

int main() {
  std::vector<std::pair<Point, Point>> segments = {{{0, 0}, {10, 30}},
                                                   {{0, 0}, {25, 30}},
                                                   {{0, 0}, {30, 10}},
                                                   {{30, 0}, {30, 15}},
                                                   {{30, 0}, {20, 30}}};

  int intersections = countIntersections(segments);
  std::cout << "Total number of intersections: " << intersections << "\n";

  return 0;
}

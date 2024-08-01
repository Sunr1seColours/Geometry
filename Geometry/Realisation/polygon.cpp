#include "../polygon.h"
#include "../ishape.h"
#include "../point.h"
#include "../ray.h"
#include "../segment.h"
#include "../vector.h"
#include <string>
#include <vector>

namespace geometry {
Polygon::Polygon(std::vector<Point> points) : points_(points) {
}

IShape &Polygon::Move(const Vector &v) {
  for (uint64_t i = 0; i < points_.size(); ++i) {
    points_.at(i).SetX(points_.at(i).GetX() + v.GetXDiff());
    points_.at(i).SetY(points_.at(i).GetY() + v.GetYDiff());
  }
  return *this;
}

bool Polygon::ContainsPoint(const Point &point) const {
  for (uint64_t i = 0; i < points_.size(); ++i) {
    uint64_t next = (i + 1) % points_.size();
    if (Segment{points_.at(i), points_.at(next)}.ContainsPoint(point)) {
      return true;
    }
  }
  Point new_point{point.GetX() + 100000, point.GetY() + 1};
  Ray ray{point, new_point};
  int64_t ray_crosses_count = 0;
  for (uint64_t i = 0; i < points_.size(); ++i) {
    uint64_t next = (i + 1) % points_.size();
    Segment segment{points_.at(i), points_.at(next)};
    if (ray.CrossesSegment(segment)) {
      ++ray_crosses_count;
    }
  }
  for (uint64_t i = 0; i < points_.size(); ++i) {
    if (ray.ContainsPoint(points_.at(i))) {
      --ray_crosses_count;
    }
  }
  return ray_crosses_count % 2 == 1;
}

bool Polygon::CrossesSegment(const Segment &segment) const {
  for (uint64_t i = 0; i < points_.size(); ++i) {
    uint64_t next = (i + 1) % points_.size();
    if (segment.CrossesSegment(Segment{points_.at(i), points_.at(next)})) {
      return true;
    }
  }
  return false;
}

std::unique_ptr<IShape> Polygon::Clone() const {
  return std::make_unique<Polygon>(std::move(points_));
}

std::string Polygon::ToString() const {
  std::string str{"Polygon("};
  for (uint64_t i = 0; i < points_.size(); ++i) {
    str += points_.at(i).ToString() + ", ";
  }
  str.erase(str.end() - 2, str.end());
  str += ")";
  return str;
}
}  // namespace geometry

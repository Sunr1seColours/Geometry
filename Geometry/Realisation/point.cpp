#include "../point.h"
#include "../vector.h"
#include "../segment.h"

namespace geometry {
Point::Point(int64_t x, int64_t y) : x_(x), y_(y) {
}

IShape &Point::Move(const Vector &v) {
  x_ += v.GetXDiff();
  y_ += v.GetYDiff();
  return *this;
}

bool Point::ContainsPoint(const Point &point) const {
  return (x_ == point.x_ && y_ == point.y_);
}

bool Point::CrossesSegment(const Segment &segment) const {
  return segment.ContainsPoint(*this);
}

std::unique_ptr<IShape> Point::Clone() const {
  return std::make_unique<Point>(x_, y_);
}

std::string Point::ToString() const {
  std::string str{"Point("};
  str += std::to_string(x_) + ", " + std::to_string(y_) + ")";
  return str;
}

Vector operator-(const Point &first, const Point &second) {
  return Vector(first.x_ - second.x_, first.y_ - second.y_);
}

int64_t Point::GetX() const {
  return x_;
}

int64_t Point::GetY() const {
  return y_;
}

void Point::SetX(int64_t new_x) {
  x_ = new_x;
}

void Point::SetY(int64_t new_y) {
  y_ = new_y;
}
}  // namespace geometry

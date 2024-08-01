#include "../line.h"
#include "../vector.h"
#include "../point.h"
#include "../segment.h"
#include <string>

namespace geometry {
template <class Number>
int GetSign(Number number) {
  if (number > 0) {
    return 1;
  } else if (number < 0) {
    return -1;
  }
  return 0;
}

Line::Line(const Point &first, const Point &second) {
  a_ = second.GetY() - first.GetY();
  b_ = first.GetX() - second.GetX();
  c_ = second.GetX() * first.GetY() - first.GetX() * second.GetY();
}

Line::Line(const int64_t x1, const int64_t y1, const int64_t x2, const int64_t y2)
    : Line(Point(x1, y1), Point(x2, y2)) {
}

Line::Line(const int64_t a, const int64_t b, const int64_t c) : a_(a), b_(b), c_(c) {
}

IShape &Line::Move(const Vector &v) {
  c_ -= a_ * v.GetXDiff() + b_ * v.GetYDiff();
  return *this;
}

bool Line::ContainsPoint(const Point &point) const {
  return a_ * point.GetX() + b_ * point.GetY() + c_ == 0;
}

bool Line::CrossesSegment(const Segment &segment) const {
  return GetSign(a_ * segment.GetFirstPoint().GetX() + b_ * segment.GetFirstPoint().GetY() + c_) *
             GetSign(a_ * segment.GetSecondPoint().GetX() + b_ * segment.GetSecondPoint().GetY() + c_) <=
         0;
}

std::unique_ptr<IShape> Line::Clone() const {
  return std::make_unique<Line>(a_, b_, c_);
}

std::string Line::ToString() const {
  std::string str{"Line("};
  str += std::to_string(static_cast<int>(a_)) + ", " + std::to_string(static_cast<int>(b_)) + ", " +
         std::to_string(static_cast<int>(c_)) + ")";
  return str;
}
}  // namespace geometry
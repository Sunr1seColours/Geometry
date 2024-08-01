#include "../segment.h"
#include "../point.h"
#include "../vector.h"
#include "../line.h"

namespace geometry {
Segment::Segment(const Point &first, const Point &second) : first_(new Point(first)), second_(new Point(second)) {
}

Segment::Segment(const int64_t x1, const int64_t y1, const int64_t x2, const int64_t y2)
    : Segment(Point{x1, y1}, Point{x2, y2}) {
}

IShape &Segment::Move(const Vector &v) {
  first_->SetX(first_->GetX() + v.GetXDiff());
  first_->SetY(first_->GetY() + v.GetYDiff());
  second_->SetX(second_->GetX() + v.GetXDiff());
  second_->SetY(second_->GetY() + v.GetYDiff());
  return *this;
}

bool Segment::ContainsPoint(const Point &point) const {
  Vector v1 = point - *first_;
  Vector v2 = *second_ - point;
  return v1.Cross(v2) == 0 && v1 * v2 >= 0;
}

bool Segment::CrossesSegment(const Segment &segment) const {
  if (segment.first_->ContainsPoint(*segment.second_)) {
    return ContainsPoint(*segment.first_);
  } else if (first_->ContainsPoint(*second_)) {
    return segment.ContainsPoint(*first_);
  }
  if ((*segment.second_ - *segment.first_).Cross(*second_ - *first_) == 0) {
    return ContainsPoint(*segment.first_) || ContainsPoint(*segment.second_);
  }
  return (Line{*first_, *second_}.CrossesSegment(segment) &&
          Line(*segment.first_, *segment.second_).CrossesSegment(*this));
}

std::unique_ptr<IShape> Segment::Clone() const {
  return std::make_unique<Segment>(*first_, *second_);
}

std::string Segment::ToString() const {
  std::string str{"Segment("};
  str += first_->ToString() + ", " + second_->ToString() + ")";
  return str;
}

Point &Segment::GetFirstPoint() const {
  return *first_;
}

Point &Segment::GetSecondPoint() const {
  return *second_;
}
}  // namespace geometry
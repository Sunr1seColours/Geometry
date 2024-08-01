#include "../ray.h"
#include "../point.h"
#include "../segment.h"
#include "../vector.h"
#include "../line.h"

namespace geometry {
Ray::Ray(const Point &first, const Point &second) : peak_(new Point(first)), direction_(new Vector(second - first)) {
}

Ray::Ray(const int64_t x1, const int64_t y1, const int64_t x2, const int64_t y2) : Ray(Point(x1, y1), Point(x2, y2)) {
}

IShape &Ray::Move(const Vector &v) {
  peak_->SetX(peak_->GetX() + v.GetXDiff());
  peak_->SetY(peak_->GetY() + v.GetYDiff());
  return *this;
}

Ray::Ray(const Point &point, const Vector &vector) : peak_(new Point(point)), direction_(new Vector(vector)) {
}

bool Ray::ContainsPoint(const Point &point) const {
  return (direction_->Cross(point - *peak_) == 0 && *direction_ * (point - *peak_) >= 0);
}

bool Ray::CrossesSegment(const Segment &segment) const {
  if (Line(*peak_, Point{peak_->GetX() + direction_->GetXDiff(), peak_->GetY() + direction_->GetYDiff()})
          .CrossesSegment(segment)) {
    return direction_->Cross(segment.GetSecondPoint() - segment.GetFirstPoint()) *
               (*peak_ - segment.GetFirstPoint()).Cross(segment.GetSecondPoint() - segment.GetFirstPoint()) <=
           0;
  }
  return ContainsPoint(segment.GetFirstPoint()) || ContainsPoint(segment.GetSecondPoint());
}

std::unique_ptr<IShape> Ray::Clone() const {
  return std::make_unique<Ray>(*peak_, *direction_);
}

std::string Ray::ToString() const {
  std::string str{"Ray("};
  str += peak_->ToString() + ", " + direction_->ToString() + ")";
  return str;
}
}  // namespace geometry
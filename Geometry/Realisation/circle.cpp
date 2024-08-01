#include "../circle.h"
#include "../ishape.h"
#include "../point.h"
#include "../segment.h"
#include "../vector.h"
#include <string>
#include <cmath>

namespace geometry {
Circle::Circle(const Point &center, const uint32_t radius) : center_(new Point(center)), radius_(radius) {
}

IShape &Circle::Move(const Vector &v) {
  center_->SetX(center_->GetX() + v.GetXDiff());
  center_->SetY(center_->GetY() + v.GetYDiff());
  return *this;
}

bool Circle::ContainsPoint(const Point &point) const {
  return std::sqrt(std::pow(center_->GetX() - point.GetX(), 2) + std::pow(center_->GetY() + point.GetY(), 2)) <=
         radius_;
}

bool Circle::CrossesSegment(const Segment &segment) const {
  if ((segment.GetFirstPoint() - *center_).Length() < radius_ &&
      (segment.GetSecondPoint() - *center_).Length() < radius_) {
    return false;
  }
  double distance = 0;
  Vector segment_vector = segment.GetSecondPoint() - segment.GetFirstPoint();
  Vector v1 = *center_ - segment.GetFirstPoint();
  Vector v2 = *center_ - segment.GetSecondPoint();
  if (v1 * segment_vector <= 0) {
    distance = v1.Length();
  } else if (v2 * (-segment_vector) <= 0) {
    distance = v2.Length();
  } else {
    distance = std::abs(segment_vector.Cross(v1)) / segment_vector.Length();
  }
  return distance <= radius_;
}

std::unique_ptr<IShape> Circle::Clone() const {
  return std::make_unique<Circle>(*center_, radius_);
}

std::string Circle::ToString() const {
  std::string str{"Circle("};
  str += center_->ToString() + ", " + std::to_string(radius_) + ")";
  return str;
}
}  // namespace geometry
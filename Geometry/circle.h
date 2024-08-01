#ifndef GEOMETRY_CIRCLE_H_
#define GEOMETRY_CIRCLE_H_
#include "ishape.h"
#include <string>
#include <memory>

namespace geometry {
class Point;
class Segment;

class Circle : public IShape {
 private:
  std::unique_ptr<Point> center_;
  uint32_t radius_;

 public:
  Circle(const Point &, const uint32_t);
  IShape &Move(const Vector &) override;
  bool ContainsPoint(const Point &) const override;
  bool CrossesSegment(const Segment &) const override;
  std::unique_ptr<IShape> Clone() const override;
  std::string ToString() const override;
};
}  // namespace geometry

#endif
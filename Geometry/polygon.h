#ifndef GEOMETRY_POLYGON_H_
#define GEOMETRY_POLYGON_H_
#include "ishape.h"
#include "point.h"
#include <vector>
#include <string>
#include <memory>

namespace geometry {
class Point;
class Segment;

class Polygon : public IShape {
 private:
  std::vector<Point> points_;

 public:
  explicit Polygon(std::vector<Point>);
  IShape &Move(const Vector &) override;
  bool ContainsPoint(const Point &) const override;
  bool CrossesSegment(const Segment &) const override;
  std::unique_ptr<IShape> Clone() const override;
  std::string ToString() const override;
};
}  // namespace geometry

#endif
#ifndef GEOMETRY_RAY_H_
#define GEOMETRY_RAY_H_
#include "ishape.h"
#include "vector.h"
#include <memory>

namespace geometry {
class Point;
class Segment;

class Ray : public IShape {
 private:
  std::unique_ptr<Point> peak_;
  std::unique_ptr<Vector> direction_;

 public:
  Ray(const Point &, const Point &);
  Ray(const int64_t, const int64_t, const int64_t, const int64_t);
  Ray(const Point &, const Vector &);
  IShape &Move(const Vector &) override;
  bool ContainsPoint(const Point &) const override;
  bool CrossesSegment(const Segment &) const override;
  std::unique_ptr<IShape> Clone() const override;
  std::string ToString() const override;
};
}  // namespace geometry

#endif
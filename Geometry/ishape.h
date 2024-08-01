#ifndef GEOMETRY_ISHAPE_H_
#define GEOMETRY_ISHAPE_H_
#include <string>
#include <memory>

namespace geometry {
class Point;
class Segment;
class Vector;
class IShape {
 public:
  virtual ~IShape() = default;
  virtual IShape &Move(const Vector &) = 0;
  virtual bool ContainsPoint(const Point &) const = 0;
  virtual bool CrossesSegment(const Segment &) const = 0;
  virtual std::unique_ptr<IShape> Clone() const = 0;
  virtual std::string ToString() const = 0;
};
}  // namespace geometry

#endif
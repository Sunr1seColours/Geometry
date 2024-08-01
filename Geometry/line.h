#ifndef GEOMETRY_LINE_H_
#define GEOMETRY_LINE_H_
#include "ishape.h"
#include <string>
#include <memory>

namespace geometry {
class Point;
class Segment;

class Line : public IShape {
 private:
  int64_t a_;
  int64_t b_;
  int64_t c_;

 public:
  Line(const Point &, const Point &);
  Line(const int64_t, const int64_t, const int64_t, const int64_t);
  Line(const int64_t, const int64_t, const int64_t);
  IShape &Move(const Vector &) override;
  bool ContainsPoint(const Point &) const override;
  bool CrossesSegment(const Segment &) const override;
  std::unique_ptr<IShape> Clone() const override;
  std::string ToString() const override;
};
}  // namespace geometry

#endif
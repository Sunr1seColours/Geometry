#ifndef GEOMETRY_SEGMENT_H_
#define GEOMETRY_SEGMENT_H_
#include "ishape.h"
#include <string>
#include <memory>

namespace geometry {
class Point;
class Segment : public IShape {
 private:
  std::unique_ptr<Point> first_;
  std::unique_ptr<Point> second_;

 public:
  Segment(const Point &, const Point &);
  Segment(const int64_t, const int64_t, const int64_t, const int64_t);
  IShape &Move(const Vector &) override;
  bool ContainsPoint(const Point &) const override;
  bool CrossesSegment(const Segment &) const override;
  std::unique_ptr<IShape> Clone() const override;
  std::string ToString() const override;
  Point &GetFirstPoint() const;
  Point &GetSecondPoint() const;
};
}  // namespace geometry

#endif
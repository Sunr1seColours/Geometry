#ifndef GEOMETRY_POINT_H_
#define GEOMETRY_POINT_H_
#include "ishape.h"
#include <memory>
#include <string>

namespace geometry {
class Segment;

class Point : public IShape {
 private:
  int64_t x_;
  int64_t y_;

 public:
  Point(const int64_t, const int64_t);
  IShape &Move(const Vector &) override;
  bool ContainsPoint(const Point &) const override;
  bool CrossesSegment(const Segment &) const override;
  std::unique_ptr<IShape> Clone() const override;
  std::string ToString() const override;
  friend Vector operator-(const Point &, const Point &);
  int64_t GetX() const;
  int64_t GetY() const;
  void SetX(int64_t);
  void SetY(int64_t);
};
}  // namespace geometry

#endif
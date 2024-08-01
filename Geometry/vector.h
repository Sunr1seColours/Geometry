#ifndef GEOMETRY_VECTOR_H_
#define GEOMETRY_VECTOR_H_
#include <string>
#include <memory>

namespace geometry {
class Vector {
 private:
  int64_t x_diff_;
  int64_t y_diff_;

 public:
  Vector(const int64_t, const int64_t);
  friend Vector operator+(const Vector &, const Vector &);
  friend Vector operator-(const Vector &, const Vector &);
  friend Vector operator*(const Vector &, const int64_t);
  friend Vector operator*(const int64_t, const Vector &);
  friend int64_t operator*(const Vector &, const Vector &);
  friend Vector operator/(const Vector &, const int64_t);
  friend Vector &operator+=(Vector &, const Vector &);
  friend Vector &operator-=(Vector &, const Vector &);
  friend Vector &operator*=(Vector &, const int64_t);
  friend Vector &operator/=(Vector &, const int64_t);
  friend bool operator==(const Vector &, const Vector &);
  Vector operator+() const;
  Vector operator-() const;
  int64_t GetXDiff() const;
  int64_t GetYDiff() const;
  std::string ToString() const;
  int64_t Cross(const Vector &) const;
  double Length() const;
};
}  // namespace geometry

#endif
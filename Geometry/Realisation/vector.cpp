#include "../vector.h"
#include <string>
#include <cmath>

namespace geometry {
Vector::Vector(const int64_t x, const int64_t y) : x_diff_(x), y_diff_(y) {
}

Vector operator+(const Vector &v1, const Vector &v2) {
  return Vector(v1.x_diff_ + v2.x_diff_, v1.y_diff_ + v2.y_diff_);
}

Vector operator-(const Vector &v1, const Vector &v2) {
  return Vector(v1.x_diff_ - v2.x_diff_, v1.y_diff_ - v2.y_diff_);
}

Vector operator*(const Vector &v, const int64_t k) {
  return Vector(v.x_diff_ * k, v.y_diff_ * k);
}

Vector operator*(const int64_t k, const Vector &v) {
  return Vector(v.x_diff_ * k, v.y_diff_ * k);
}

int64_t operator*(const Vector &v1, const Vector &v2) {
  return v1.x_diff_ * v2.x_diff_ + v1.y_diff_ * v2.y_diff_;
}

Vector operator/(const Vector &v, const int64_t del) {
  return Vector(v.x_diff_ / del, v.y_diff_ / del);
}

Vector &operator+=(Vector &v1, const Vector &v2) {
  v1 = v1 + v2;
  return v1;
}

Vector &operator-=(Vector &v1, const Vector &v2) {
  v1 = v1 - v2;
  return v1;
}

Vector &operator*=(Vector &v1, const int64_t k) {
  v1 = v1 * k;
  return v1;
}

Vector &operator/=(Vector &v1, const int64_t del) {
  v1 = v1 / del;
  return v1;
}

bool operator==(const Vector &v1, const Vector &v2) {
  return (v1.x_diff_ == v2.x_diff_ && v1.y_diff_ == v2.y_diff_);
}

Vector Vector::operator+() const {
  return Vector(this->x_diff_, this->y_diff_);
}

Vector Vector::operator-() const {
  return Vector(-this->x_diff_, -this->y_diff_);
}

int64_t Vector::GetXDiff() const {
  return x_diff_;
}

int64_t Vector::GetYDiff() const {
  return y_diff_;
}

std::string Vector::ToString() const {
  std::string str{"Vector("};
  str += std::to_string(x_diff_) + ", " + std::to_string(y_diff_) + ")";
  return str;
}

int64_t Vector::Cross(const Vector &v) const {
  return x_diff_ * v.y_diff_ - y_diff_ * v.x_diff_;
}

double Vector::Length() const {
  return std::sqrt(std::pow(x_diff_, 2) + std::pow(y_diff_, 2));
}

}  // namespace geometry

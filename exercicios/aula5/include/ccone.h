#pragma once
#include "cshape3d.h"
#include <cmath>
template <typename T> class CCone : public CShape3d<T> {
  T volume() override {
    float PI = std::atan(1) * 4;
    return (PI * this->a * this->a * this->b) / 3;
  }

public:
  CCone(T radius, T height) {
    this->a = radius;
    this->b = height;
  }
  ~CCone() = default;
};

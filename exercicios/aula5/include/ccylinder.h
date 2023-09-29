#pragma once
#include "cshape3d.h"
#include <cmath>
#include <vector>
template <typename T> class CCylinder : public CShape3d<T> {
  T volume() override {
    float PI = std::atan(1) * 4;
    return (PI * this->a * this->a * this->b);
  }

public:
  CCylinder(T radius, T height) {
    this->a = radius;
    this->b = height;
  }
  ~CCylinder() = default;
};

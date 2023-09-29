#pragma once
#include "cshape3d.h"

template <typename T> class CBox : public CShape3d<T> {
public:
  T volume() override { return this->a * this->b * this->c; }

public:
  CBox(T a, T b, T c) {
    this->a = a;
    this->b = b;
    this->c = c;
  }
  ~CBox() = default;
};

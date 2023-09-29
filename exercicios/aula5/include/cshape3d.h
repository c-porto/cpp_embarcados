#pragma once

template<typename T>
class CShape3d
{
  public:
    virtual ~CShape3d() = default;

  protected:
    T a;
    T b;
    T c;

  public:
    virtual T volume() = 0;
};


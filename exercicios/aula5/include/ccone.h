#pragma once
#include "cshape3d.h"
class CCone : public CShape3d
{
    float volume() override;

  public:
    CCone(float, float);
    ~CCone() = default;
};

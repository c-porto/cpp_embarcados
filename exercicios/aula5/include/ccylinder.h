#pragma once
#include "cshape3d.h"
class CCylinder : public CShape3d
{
    float volume() override;

  public:
    CCylinder(float, float);
    ~CCylinder()=default;
};

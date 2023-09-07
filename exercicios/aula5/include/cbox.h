#pragma once
#include "cshape3d.h"
class CBox : public CShape3d
{
    float volume() override;

  public:
    CBox(float, float, float);
    ~CBox()=default;
};

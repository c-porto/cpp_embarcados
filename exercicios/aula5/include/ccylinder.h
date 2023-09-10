#pragma once
#include "cshape3d.h"
#include <memory>
#include <ostream>
#include <vector>
class CCylinder : public CShape3d
{
  public:
    float volume() override;

  public:
    CCylinder(float, float);
    ~CCylinder() = default;
    std::unique_ptr<std::vector<float>> createVolumeDataset();
    void vPrintDimensions(std::ostream&);
    friend std::ostream &operator<<(std::ostream &s, CCylinder &cylinder)
    {
        s << cylinder.volume();
        return s;
    }

};

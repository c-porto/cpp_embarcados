#pragma once

class CShape3d
{
  public:
    virtual ~CShape3d() = default;

  protected:
    float a;
    float b;
    float c;

  public:
    virtual float volume() = 0;
};


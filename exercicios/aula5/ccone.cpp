#include "include/ccone.h"
#include <cmath>

CCone::CCone(float radius, float height)
{
    a = radius;
    b = height;
}

float CCone::volume()
{

    float PI = std::atan(1) * 4;
    return (PI * a * a * b) / 3;
}

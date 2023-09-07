#include "include/ccylinder.h"
#include <cmath>

CCylinder::CCylinder(float radius, float height) {
  a = radius;
  b = height;
}

float CCylinder::volume() {
  float PI = std::atan(1) * 4;
  return (PI * a * a * b);
}

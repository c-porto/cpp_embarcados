#include "include/ccylinder.h"
#include <algorithm>
#include <cmath>
#include <cstring>
#include <memory>
#include <ostream>

using DataP = std::unique_ptr<std::vector<float>>;

CCylinder::CCylinder(float radius, float height)
{
    a = radius;
    b = height;
}

float CCylinder::volume()
{
    float PI = std::atan(1) * 4;
    return (PI * a * a * b);
}
std::unique_ptr<std::vector<float>> CCylinder::createVolumeDataset()
{
    float tmp = this->volume();
    DataP dataset = std::make_unique<std::vector<float>>(10);
    std::fill(dataset.get()->begin(), dataset.get()->end(), tmp);
    return dataset;
}
void CCylinder::vPrintDimensions(std::ostream& ss)
{
    ss << "Radius: " << a << std::endl;
    ss << "Height: " << b << std::endl;
    ss << "Volume: " << *this << std::endl;
}

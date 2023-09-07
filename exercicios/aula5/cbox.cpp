#include "include/cbox.h"

CBox::CBox(float a, float b, float c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}

float CBox::volume()
{
    return a * b * c;
}

#include <cmath>
#include "rectangle.hpp"
#include "Vec2.hpp"
#include "color.hpp"

Rectangle::Rectangle():
    min_(0.0f, 0.0f),
    max_(0.0f, 0.0f),
    color_(0.0f, 0.0f, 0.0f){}

Rectangle::Rectangle(Vec2 const& min, Vec2 const& max):
    min_(min),
    max_(max),
    color_(0.0f, 0.0f, 0.0f){}

Rectangle::Rectangle(Vec2 const& min, Vec2 const& max, Color const& c):
    min_(min),
    max_(max),
    color_(c){}

Vec2 Rectangle::getMin_() const{
    return min_;
}

Vec2 Rectangle::getMax_() const{
    return max_;
}

Color Rectangle::getColor_() const{
    return color_;
}




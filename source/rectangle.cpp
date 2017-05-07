#include <cmath>
#include "rectangle.hpp"
#include "Vec2.hpp"
#include "color.hpp"
#include "window.hpp"

/*
Unterschied Methode und Funktion:
Circumference als const?: Ja, da Memberfunktion und verändert Rectangle- bzw Circleobjekte nicht
*/

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

float Rectangle::circumference() const{
    return (2*(getMax_().x_-getMin_().x_))+(2*(getMax_().y_-getMin_().y_));
}

void Rectangle::draw(Window const& win)const{
	win.draw_line(min_.x_, min_.y_, min_.x_, max_.y_, color_.r_, color_.g_, color_.b_);
    win.draw_line(min_.x_, min_.y_, max_.x_, min_.y_, color_.r_, color_.g_, color_.b_);
    win.draw_line(max_.x_, min_.y_, max_.x_, max_.y_, color_.r_, color_.g_, color_.b_);
	win.draw_line(min_.x_, max_.y_, max_.x_, max_.y_, color_.r_, color_.g_, color_.b_);
}

void Rectangle::draw(Window const& win, Color const& color)const{
	win.draw_line(min_.x_, min_.y_, min_.x_, max_.y_, color.r_, color.g_, color.b_);
    win.draw_line(min_.x_, min_.y_, max_.x_, min_.y_, color.r_, color.g_, color.b_);
    win.draw_line(max_.x_, min_.y_, max_.x_, max_.y_, color.r_, color.g_, color.b_);
	win.draw_line(min_.x_, max_.y_, max_.x_, max_.y_, color.r_, color.g_, color.b_);
}
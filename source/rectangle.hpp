#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "Vec2.hpp"
#include "color.hpp"
#include "window.hpp"


class Rectangle{

public:
    Rectangle();
    Rectangle(Vec2 const& min, Vec2 const& max);
    Rectangle(Vec2 const& min, Vec2 const& max, Color const& c);

	Vec2 getMin_() const;
	Vec2 getMax_() const;
	Color getColor_() const;
    float circumference() const;

    void draw(Window const& win) const;


private:
    Vec2 min_;
    Vec2 max_;
	Color color_;

};

#endif

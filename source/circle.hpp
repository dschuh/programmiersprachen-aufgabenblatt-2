#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "Vec2.hpp"
#include "color.hpp"


class Circle{

public:
    Circle();
    Circle(Vec2 const& c, float r);
    Circle(Vec2 const& a, float r, Color const& c);

    Vec2 getCenter() const;
    float getRadius() const;
    Color getColor() const;
    float circumference() const;

private:
    Vec2 center_;
    float radius_;
    Color color_;
};

#endif


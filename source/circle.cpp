#include <cmath>
#include "circle.hpp"
#include "Vec2.hpp"
#include "color.hpp"
#include "window.hpp"

Circle::Circle():
    center_(0.0f, 0.0f),
    radius_(1.0f),
    color_(0.0f, 0.0f, 0.0f){}


Circle::Circle(Vec2 const& c, float r):
    center_(c),
    radius_(r),
    color_(0.0f, 0.0f, 0.0f){}

Circle::Circle(Vec2 const& a, float r, Color const& c):
    center_(a),
    radius_(r),
    color_(c){}

Vec2 Circle::getCenter() const {
	return center_;
}

float Circle::getRadius() const {
	return radius_;
}

Color Circle::getColor() const {
	return color_;
}

float Circle::circumference() const {
	return M_PI*radius_*2;
}
/*
void Circle::draw(Window& w){
//	for(float i = 0.0; i<= 2* M_PI; i += 0.01){
//		w.draw_point(r/100*cos(i)+0.5, r/100*sin(i)+0.5, col.r_, col.g_, col.b_);
//	}
    for (int i = 1; i<= 360; ++i)
	    {
       		Vec2 v1{ (make_rotation_mat2(2*M_PI*i/360)) * Vec2(getRadius(), 0) + getCenter() };
        	Vec2 v2{ (make_rotation_mat2((2*M_PI*(i+1))/360)) * Vec2(get_radius(), 0) + get_ctr() };
        	win.draw_line(v1.x_, v1.y_, v2.x_, v2.y_, color_.r_, color_.g_, color_.b_);
		}	
}


void Circle::draw(Window& w, Color col){
	for(float i = 0.0; i<= 2* M_PI; i += 0.01){
		w.draw_point(r/100*cos(i)+ctr.x, r/100*sin(i)+ctr.y, col.r_, col.g_, col.b_);
	}
}
*/
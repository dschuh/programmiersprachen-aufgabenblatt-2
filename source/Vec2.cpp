#include "Vec2.hpp"
#include <cmath>

Vec2::Vec2():
  x_(0.0f), y_(0.0f){}

Vec2::Vec2(float x, float y):
  x_(x), y_(y){}

Vec2& Vec2::operator += ( Vec2 const & v ){
  this->x_ += v.x_;
	this->y_ += v.y_;
	return *this; 
}

Vec2& Vec2::operator -= (Vec2 const & v){
	this->x_ -= v.x_;
	this->y_ -= v.y_;
	return *this;
}

Vec2& Vec2::operator *= (float s){
	this->x_ *= s;
	this->y_ *= s;
	return *this;
}

Vec2& Vec2::operator /= (float s){
	this->x_ /= s;
	this->y_ /= s;
	return *this;
}

Vec2 operator +( Vec2 const & u , Vec2 const & v ){
    Vec2 test{};
    test.x_ = u.x_ + v.x_;
    test.y_ = u.y_ + v.y_;
    return test;
}

Vec2 operator -( Vec2 const & u , Vec2 const & v ){
    Vec2 test{};
    test.x_ = u.x_ - v.x_;
    test.y_ = u.y_ - v.y_;
    return test;
}

Vec2 operator *( Vec2 const & v , float s ){
    Vec2 test{};
    test.x_ = v.x_ * s;
    test.y_ = v.y_ * s;
    return test;
}

Vec2 operator /( Vec2 const & v , float s ){
    Vec2 test{};
    test.x_ = v.x_ / s;
    test.y_ = v.y_ / s;
    return test;
}

Vec2 operator *( float s , Vec2 const & v ){
    Vec2 test{};
    test.x_ = v.x_ * s;
    test.y_ = v.y_ * s;
    return test;
}
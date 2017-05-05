#ifndef MAT2_HPP
#define MAT2_HPP

struct Mat2{
//Constructors
Mat2();
Mat2(float a1, float a2, float a3, float a4);

float a11_;
float a12_;
float a21_;
float a22_;

Mat2& operator *=(Mat2 const& m);
};
Mat2 operator *(Mat2 const& m1, Mat2 const& m2);

#endif
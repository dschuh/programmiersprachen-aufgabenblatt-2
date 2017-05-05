#include "mat2.hpp"

Mat2::Mat2():
  a11_{1.0f}, 
  a12_{0.0f},
  a21_{0.0f}, 
  a22_{1.0f}{}

Mat2::Mat2(float a1, float a2, float a3, float a4):
  a11_{a1},
  a12_{a2},
  a21_{a3},
  a22_{a4}{}

Mat2& Mat2::operator *= (Mat2 const& m){
  float a11=a11_; 
  float a12=a12_; 
  float a21=a21_; 
  float a22=a22_; 
  a11_ = (a11 * m.a11_)+(a12 * m.a21_);
  a12_ = (a11 * m.a12_)+(a12 * m.a22_);
  a21_ = (a21 * m.a11_)+(a22 * m.a21_);
  a22_ = (a21 * m.a12_)+(a22 * m.a22_);
	return *this;
}

Mat2 operator *(Mat2 const& m1, Mat2 const& m2){
    Mat2 result{};
    result.a11_ = (m1.a11_ * m2.a11_)+(m1.a12_ * m2.a21_);
    result.a12_ = (m1.a11_ * m2.a12_)+(m1.a12_ * m2.a22_);
    result.a21_ = (m1.a21_ * m2.a11_)+(m1.a22_ * m2.a21_);
    result.a22_ = (m1.a21_ * m2.a12_)+(m1.a22_ * m2.a22_);
    return result;
}
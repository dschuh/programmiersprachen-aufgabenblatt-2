#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "Vec2.hpp"
#include "mat2.hpp"

TEST_CASE("default konstruktor initialisiert x und y mit 0.0f","[constructor]")
{
  Vec2 u{};
  REQUIRE(u.x_ == 0.0f);
  REQUIRE(u.y_ == 0.0f);
}

TEST_CASE("userconstructor der x und y als argumente bekommt")
{
  Vec2 v{2.0f, -3.0f};
  REQUIRE(v.x_ == 2.0f);
  REQUIRE(v.y_ == -3.0f);
}

TEST_CASE("testing -= operator", "[operator -=]")
{
  Vec2 v1{2.0f, -3.0f};
  Vec2 v2{1.0f, 3.0f};
  Vec2 v3{5.0f, 7.0f};
  v1 -= v2;
  v2 -= v3;
  REQUIRE(v1.x_==1.0f);
  REQUIRE(v1.y_==-6.0f);
  REQUIRE(v2.x_==-4.0f);
  REQUIRE(v2.y_==-4.0f);
}

TEST_CASE("testing *= operator", "[operator *=]")
{
  Vec2 v1{2.0f, -3.0f};
  float a=3.0f;
  float b=0.0f;
  v1 *= a;
  REQUIRE(v1.x_==6.0f);
  REQUIRE(v1.y_==-9.0f);
  v1 *= b;
  REQUIRE(v1.x_==0.0f);
  REQUIRE(v1.y_==0.0f);
}

TEST_CASE("testing /= operator", "[operator /=]")
{
  Vec2 v1{2.0f, -3.0f};
  float a=3.0f;
  float b=0.0f;
  v1 /= a;
  REQUIRE(Approx(v1.x_)==0.66666666f);
  REQUIRE(v1.y_==-1.0f);
  v1 /= b;
  REQUIRE(Approx(v1.x_)==0.666666f);
  REQUIRE(v1.y_==-1.0f);
}

TEST_CASE("testing + operator", "[operator +]")
{
  Vec2 v1{2.0f, -3.0f};
  Vec2 v2{1.0f, 3.0f};
  Vec2 v3{5.0f, 7.0f};
  Vec2 v4{};
  Vec2 v5{};
  v4 = v1 + v2;
  v5 = v2 + v3;
  REQUIRE(v1.x_==2.0f);
  REQUIRE(v4.x_==3.0f);
  REQUIRE(v4.y_==0.0f);
  REQUIRE(v5.x_==6.0f);
  REQUIRE(v5.y_==10.0f);
}

TEST_CASE("testing - operator", "[operator -]")
{
  Vec2 v1{2.0f, -3.0f};
  Vec2 v2{1.0f, 3.0f};
  Vec2 v3{5.0f, 7.0f};
  Vec2 v4{};
  Vec2 v5{};
  v4 = v1 - v2;
  v5 = v2 - v3;
  REQUIRE(v4.x_==1.0f);
  REQUIRE(v4.y_==-6.0f);
  REQUIRE(v5.x_==-4.0f);
  REQUIRE(v5.y_==-4.0f);
  REQUIRE(v1.x_==2.0f);
}

TEST_CASE("testing * operator", "[operator *]")
{
  Vec2 v1{1.0f, 3.0f};
  Vec2 v2{5.0f, 7.0f};
  float a=5.0f;
  float b=3.0f;
  Vec2 v3{};
  Vec2 v4{};
  Vec2 v5{};
  v3=v1*a;
  v4=b*v2;
  REQUIRE(v3.x_==5.0f);
  REQUIRE(v3.y_==15.0f);
  REQUIRE(v4.x_==15.0f);
  REQUIRE(v4.y_==21.0f);
  v5=v1*0.0f;
  REQUIRE(v5.x_==0.0f);
  REQUIRE(v5.y_==0.0f);
}

TEST_CASE("testing / operator", "[operator /]")
{
  Vec2 v1{1.0f, 3.0f};
  Vec2 v2{5.0f, 7.0f};
  Vec2 v3{};
  Vec2 v4{};
  Vec2 v5{};
  float a=5.0f;
  float b=3.0f;
  v3=v1/a;
  v4=v2/b;
  REQUIRE(v3.x_==0.2f);
  REQUIRE(v3.y_==0.6f);
  REQUIRE(Approx(v4.x_)==1.666666f);
  REQUIRE(Approx(v4.y_)==2.333333f);
  v5=v1/0.0f;
  REQUIRE(v5.x_==v5.x_);
  REQUIRE(v5.y_==v5.y_);
}

TEST_CASE("testing matrix constructors")
{
  Mat2 m{};
  REQUIRE(m.a11_==1.0f);
  REQUIRE(m.a12_==0.0f);
  REQUIRE(m.a21_==0.0f);
  REQUIRE(m.a22_==1.0f);
}

TEST_CASE("testing matrix constructors with user input")
{
  Mat2 m{1.0f, 2.0f, 3.0f, 4.0f};
  REQUIRE(m.a11_==1.0f);
  REQUIRE(m.a12_==2.0f);
  REQUIRE(m.a21_==3.0f);
  REQUIRE(m.a22_==4.0f);
}

TEST_CASE("testing operator *=", "[operator *=]")
{
  Mat2 m1{1.0f, 2.0f, 
          3.0f, 4.0f};
  Mat2 m2{5.0f, 6.0f,
          7.0f, 8.0f};
  m1 *= m2;
  REQUIRE(m1.a11_==19.0f);
  REQUIRE(m1.a12_==22.0f);
  REQUIRE(m1.a21_==43.0f);
  REQUIRE(m1.a22_==50.0f);
  Mat2 m3{};
  m1 *= m3;
  REQUIRE(m1.a11_==19.0f);
  REQUIRE(m1.a12_==22.0f);
  REQUIRE(m1.a21_==43.0f);
  REQUIRE(m1.a22_==50.0f);
}

TEST_CASE("testing operator *", "[operator *]")
{
  Mat2 m1{1.0f, 2.0f, 
          3.0f, 4.0f};
  Mat2 m2{5.0f, 6.0f,
          7.0f, 8.0f};
  Mat2 m3{};
  m3 = m1 * m2;
  REQUIRE(m3.a11_==19.0f);
  REQUIRE(m3.a12_==22.0f);
  REQUIRE(m3.a21_==43.0f);
  REQUIRE(m3.a22_==50.0f);
}








//  REQUIRE(==);




















int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "Vec2.hpp"

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




int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "Vec2.hpp"
#include "mat2.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "color.hpp"
#include "window.hpp"

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

TEST_CASE("testing operator * for matrix*vector", "[operator *]")
{
  Mat2 m1{1.0f, 2.0f, 
          3.0f, 4.0f};
  Mat2 m2{5.0f, 6.0f,
          7.0f, 8.0f};
  Vec2 v1{3.0f, 5.0f};
  Vec2 v2{7.0f, 9.0f};
  Vec2 v3{};
  v3 = m1 * v1;
  REQUIRE(v3.x_==13.0f);
  REQUIRE(v3.y_==29.0f);
  v3 = m2 * v2;
  REQUIRE(v3.x_==89.0f);
  REQUIRE(v3.y_==121.0f);
}

TEST_CASE("testing operator * for vector*matrix", "[operator *]")
{
  Mat2 m1{1.0f, 2.0f, 
          3.0f, 4.0f};
  Mat2 m2{5.0f, 6.0f,
          7.0f, 8.0f};
  Vec2 v1{3.0f, 5.0f};
  Vec2 v2{7.0f, 9.0f};
  Vec2 v3{};
  v3 = v1*m1;
  REQUIRE(v3.x_==12.0f);
  REQUIRE(v3.y_==30.0f);
  v3 = v2*m2;
  REQUIRE(v3.x_==84.0f);
  REQUIRE(v3.y_==126.0f);
}

TEST_CASE("testing inverse matrix", "[inverse]")
{
  Mat2 m1{1.0f, 2.0f, 
          3.0f, 4.0f};
  Mat2 m2{5.0f, 6.0f,
          7.0f, 8.0f};
  Mat2 inv=inverse(m1);
  Mat2 inv2=inverse(m2);
  REQUIRE(inv.a11_==-2.0f);
  REQUIRE(inv.a12_==1.0f);
  REQUIRE(inv.a21_==1.5f);
  REQUIRE(inv.a22_==-0.5f);
  REQUIRE(inv2.a11_==-4.0f);
  REQUIRE(inv2.a12_==3.0f);
  REQUIRE(inv2.a21_==3.5f);
  REQUIRE(inv2.a22_==-2.5f);
}

TEST_CASE("testing transpose matrix", "[transpose]")
{
  Mat2 m1{1.0f, 2.0f, 
          3.0f, 4.0f};
  Mat2 m2{5.0f, 6.0f,
          7.0f, 8.0f};
  Mat2 trn=transpose(m1);
  Mat2 trn2=transpose(m2);
  REQUIRE(trn.a11_==1.0f);
  REQUIRE(trn.a12_==3.0f);
  REQUIRE(trn.a21_==2.0f);
  REQUIRE(trn.a22_==4.0f);
  REQUIRE(trn2.a11_==5.0f);
  REQUIRE(trn2.a12_==7.0f);
  REQUIRE(trn2.a21_==6.0f);
  REQUIRE(trn2.a22_==8.0f);
}

TEST_CASE ("testing rotation matrix", "[make_rotation_mat2]")
{
  Mat2 rot = make_rotation_mat2(30);
  REQUIRE (rot.a11_ == Approx(0.15425f));
  REQUIRE (rot.a12_ == Approx(0.98803f));
  REQUIRE (rot.a21_ == Approx(-0.98803f));
  REQUIRE (rot.a22_ == Approx(0.15425f));
}

TEST_CASE ("testing default circle constructor", "[circle constructor]")
{
  Circle c{};
  REQUIRE (c.getCenter().x_ == 0.0f);
  REQUIRE (c.getCenter().y_ == 0.0f);
  REQUIRE (c.getRadius() == 1.0f);
  REQUIRE (c.getColor().r_ == 0.0f);
  REQUIRE (c.getColor().g_ == 0.0f);
  REQUIRE (c.getColor().b_ == 0.0f);
}

TEST_CASE ("testing circle constructor with user input", "[circle constructor]")
{
  Circle c{{2.0f, 5.0f}, 10.0f};
  REQUIRE (c.getCenter().x_ == 2.0f);
  REQUIRE (c.getCenter().y_ == 5.0f);
  REQUIRE (c.getRadius() == 10.0f);
  REQUIRE (c.getColor().r_ == 0.0f);
  REQUIRE (c.getColor().g_ == 0.0f);
  REQUIRE (c.getColor().b_ == 0.0f);}

TEST_CASE ("testing circle constructor with user input including color", "[circle constructor]")
{
  Circle c{{2.0f, 5.0f}, 10.0f, 0.7f};
  REQUIRE (c.getCenter().x_ == 2.0f);
  REQUIRE (c.getCenter().y_ == 5.0f);
  REQUIRE (c.getRadius() == 10.0f);
  REQUIRE (c.getColor().r_ == 0.7f);
  REQUIRE (c.getColor().g_ == 0.7f);
  REQUIRE (c.getColor().b_ == 0.7f);}

TEST_CASE ("testing center getter", "[getCenter]")
{
  Circle c{{2.0f, 5.0f}, 10.0f};
  REQUIRE (c.getCenter().x_ == 2.0f);
  REQUIRE (c.getCenter().y_ == 5.0f );
}

TEST_CASE ("testing radius getter", "[getRadius]")
{
  Circle c{{2.0f, 5.0f}, 10.0f};
  REQUIRE (c.getRadius() == 10.0f);
}

TEST_CASE ("testing circumference function", "[circumference]")
{
  Circle c{{2.0f, 5.0f}, 10.0f};
  Circle c2{{2.0f, 5.0f}, 0.0f};
  REQUIRE (Approx(c.circumference()) == 62.8318f);
  REQUIRE (c2.circumference() == 0.0f);
}

TEST_CASE ("testing default rectangle constructors", "[default rectangle constructor]")
{
  Rectangle r{};
  REQUIRE (r.getMin_().x_ ==0.0f);
  REQUIRE (r.getMin_().y_ ==0.0f);
  REQUIRE (r.getMax_().x_ ==0.0f);
  REQUIRE (r.getMax_().y_ ==0.0f);
  REQUIRE (r.getColor_().r_ ==0.0f);
  REQUIRE (r.getColor_().g_ ==0.0f);
  REQUIRE (r.getColor_().b_ ==0.0f);
}

TEST_CASE ("testing rectangle user input constructors", "[rectangle user input constructor]")
{
  Rectangle r{{2.0f, 5.0f}, {3.0f, 6.0f}};
  REQUIRE (r.getMin_().x_ ==2.0f);
  REQUIRE (r.getMin_().y_ ==5.0f);
  REQUIRE (r.getMax_().x_ ==3.0f);
  REQUIRE (r.getMax_().y_ ==6.0f);
  REQUIRE (r.getColor_().r_ ==0.0f);
  REQUIRE (r.getColor_().g_ ==0.0f);
  REQUIRE (r.getColor_().b_ ==0.0f);
}

TEST_CASE ("testing user defined rectangle constructors", "[rectangle constructor /w user input]")
{
  Rectangle r{{2.0f, 5.0f},{3.0f, 6.0f},{0.5f, 0.7f, 0.9f}};
  REQUIRE (r.getMin_().x_ ==2.0f);
  REQUIRE (r.getMin_().y_ ==5.0f);
  REQUIRE (r.getMax_().x_ ==3.0f);
  REQUIRE (r.getMax_().y_ ==6.0f);
  REQUIRE (r.getColor_().r_ ==0.5f);
  REQUIRE (r.getColor_().g_ ==0.7f);
  REQUIRE (r.getColor_().b_ ==0.9f);
}

TEST_CASE ("testing min getter", "[getMin_]")
{
  Rectangle r{{2.0f, 5.0f}, {3.0f, 7.0f}};
  REQUIRE (r.getMin_().x_ == 2.0f);
  REQUIRE (r.getMin_().y_ == 5.0f );
}

TEST_CASE ("testing max getter", "[getMax_]")
{
  Rectangle r{{2.0f, 5.0f}, {3.0f, 7.0f}};
  REQUIRE (r.getMax_().x_ == 3.0f);
  REQUIRE (r.getMax_().y_ == 7.0f);
}

TEST_CASE ("testing color getter", "[getColor_]")
{
  Rectangle r{{2.0f, 5.0f}, {3.0f, 7.0f}};
  Rectangle r2{{2.0f, 5.0f},{3.0f, 6.0f},{0.5f, 0.7f, 0.9f}};
  REQUIRE (r.getColor_().r_== 0.0f);
  REQUIRE (r.getColor_().g_== 0.0f);
  REQUIRE (r.getColor_().b_== 0.0f);
  REQUIRE (r2.getColor_().r_== 0.5f);
  REQUIRE (r2.getColor_().g_== 0.7f);
  REQUIRE (r2.getColor_().b_== 0.9f);
}


TEST_CASE ("testing circumference method", "[circumference]")
{
  Rectangle r{{2.0f, 5.0f}, {3.0f, 7.0f}};
  REQUIRE (r.circumference()== 6.0f);
  Rectangle r2{{0.0f, 0.0f}, {0.0f, 0.0f}};
  REQUIRE (r2.circumference()==0.0f);
}

TEST_CASE ("testing is inside rect function", "[isInsideRect]")
{
  Rectangle r{{5.0f, 5.0f}, {10.0f, 10.0f}};
  Vec2 p{7.0f, 7.0f};
  Rectangle r2{{5.0f, 5.0f}, {10.0f, 10.0f}};
  Vec2 p2{2.0f, 2.0f};
  REQUIRE (r.isInsideRect(p) == true);
  REQUIRE (r2.isInsideRect(p2) == false);
}

TEST_CASE ("testing is inside circ function", "[isInsideCirc]")
{
  Circle c{{5.0f, 5.0f}, 10.0f};
  Vec2 p{7.0f, 7.0f};
  Circle c2{{5.0f, 5.0f}, 10.0f};
  Vec2 p2{2.0f, 2.0f};
  REQUIRE (c.isInsideCirc(p) == true);
  REQUIRE (c2.isInsideCirc(p2) == false);
}


/*

TEST_CASE ("", "[]")
{
  
  REQUIRE ( == );
  REQUIRE ( == );
  REQUIRE ( == );
  REQUIRE ( == );
}
*/

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

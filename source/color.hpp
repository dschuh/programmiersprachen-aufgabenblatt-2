#ifndef COLOR_HPP
#define COLOR_HPP

//Im unterschied zur Klasse sind beim struct alle 
//Membervariablen und -funktionen per default public
//DTO:

struct Color{

Color();
Color(float c);
Color(float r, float g, float b);

float r_;
float g_;
float b_;

};

#endif
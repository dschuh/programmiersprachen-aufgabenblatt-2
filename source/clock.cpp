#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include "circle.hpp"

int main(int argc, char* argv[])
{
  Window win{std::make_pair(600,600)};

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }
    Vec2 ctr{300,300};
    Circle clock{ctr, 250, Color{0.0f,0.0f,0.0f}};
    clock.draw(win); 
    float passedTime = win.get_time(); 
    Vec2 s{sin((passedTime*6*M_PI)/180)*245,-cos((passedTime*6*M_PI)/180)*245};
    Vec2 m{sin((0.1*passedTime*M_PI)/180)*210,-cos((0.1*passedTime*M_PI)/180)*210};
    Vec2 h{sin((0.0075*passedTime*M_PI)/180)*130,-cos((0.0075*passedTime*M_PI)/180)*130};
    s += ctr;
    m += ctr;
    h += ctr;
    //Uhrzeiger
    win.draw_line(ctr.x_,ctr.y_,s.x_,s.y_,1.0f,0.0f,0.0f);
    win.draw_line(ctr.x_,ctr.y_,m.x_,m.y_,0.8f,0.8f,0.8f);
    win.draw_line(ctr.x_,ctr.y_,h.x_,h.y_,0.0f,0.0f,0.0f);
    //Zeitstriche
    win.draw_line(300.0f, 50.0f, 300.0f, 70.0f, 1.0f, 0.0f, 0.0f);
    win.draw_line(300.0f, 550.0f, 300.0f, 530.0f, 1.0f, 0.0f, 0.0f);
    win.draw_line(550.0f, 300.0f, 530.0f, 300.0f, 1.0f, 0.0f, 0.0f);
    win.draw_line(50.0f, 300.0f, 70.0f, 300.0f, 1.0f, 0.0f, 0.0f);
    //Zeitanzeige
    std::string zeit = "Verstrichene Zeit: " + std::to_string((int)passedTime/3600 %24) + ":" 
    + std::to_string((int)passedTime/60 %60) + ":" + std::to_string((int)passedTime%60);
    win.draw_text(10, 5, 35.0f, zeit);
  
    win.update();
  }

  return 0;
}
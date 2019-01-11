/**
 * @file main-triangle.cc
 * @brief
 *
 * @author Cody Barnson
 * @bug no known bugs
 */

#include <cstdlib>
#include <ctime>
#include <list>
#include <memory>

#include "Display.h"
#include "Triangle.h"
#include "mySimulator.h"

int main() {
  srand(time(0));

  Display disp;
  mySimulator rain(disp, 30);
  int dropsOnScreen = 40;

  for (int i = 0; i < dropsOnScreen; i++) {
    std::shared_ptr<Triangle> tp;
    tp = std::make_shared<Triangle>(disp.getW(), disp.getH());

    rain.addDrawable(tp);
    rain.addUpdateable(tp);
  }
  rain.run();
}

/**
 * @file main-triangle.cc
 * @author C. Barnson (cbarnson@outlook.com)
 * @brief Program entry point for the "rain" program.
 * @version 0.1
 * @date 2019-01-11
 *
 * @copyright Copyright (c) 2019
 *
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

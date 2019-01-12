/**
 * @file main-line.cc
 * @author C. Barnson (cbarnson@outlook.com)
 * @brief Program entry for the "tree" program.
 * @version 0.1
 * @date 2019-01-11
 *
 * @copyright Copyright (c) 2019
 *
 */
#include <ctime>
#include <memory>

#include "Display.h"
#include "Point.h"
#include "Trunk.h"
#include "mySimulator.h"

int main() {
  srand(time(NULL));

  Display disp;
  mySimulator tree(disp, 30);
  int uniform_angle = rand() % 30 + 10;
  std::shared_ptr<Trunk> root = std::make_shared<Trunk>(
      Point(400, 500), Point(400, 25), 4.0, 0.5, uniform_angle, 4);
  tree.addDrawable(root);
  tree.addUpdateable(root);
  tree.run();

  return 0;
}

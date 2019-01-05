/**
 * @file main-line.cc
 * @brief
 *
 * @author Cody Barnson
 * @bug No known bugs
 */

#include <ctime>
#include <memory>

#include "Display.h"
#include "mySimulator.h"
#include "Trunk.h"
#include "Point.h"

int main() {

   srand(time(NULL));
   
   Display disp;
   mySimulator tree(disp, 30);
   int uniform_angle = rand() % 30 + 10;   
   std::shared_ptr<Trunk> root = std::make_shared<Trunk> (Point(400,500),
							  Point(400,25),
							  4.0,
							  0.5,
							  uniform_angle,
							  4);   
   tree.addDrawable(root);
   tree.addUpdateable(root);
   tree.run();

   return 0;
}

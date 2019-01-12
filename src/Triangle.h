/**
 * @file Triangle.h
 * @author C. Barnson (cbarnson@outlook.com)
 * @brief Triangle represents a single triangle that moves from the top of the
 * display to the bottom over time.
 * @version 0.1
 * @date 2019-01-11
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <allegro5/allegro_primitives.h>
#include <cstdlib>
#include <ctime>
#include "Drawable.h"
#include "Point.h"
#include "Updateable.h"
#include "Vector.h"

/**
 * @class Triangle
 * @brief represents a triangle that falls from the top of the display to the
 * bottom
 */
class Triangle : public Drawable, public Updateable {
 private:
  /**
   * @var pt
   * represents one vertex of the triangle object
   */
  Point pt;

  /**
   * @var max_x
   * represents the maximum x coordinate that the triangle can be drawn from
   * @var max_y
   * represents the bottom of the display window beyond which the triangle is no
   * longer visable
   * @var size
   * represents the side length of the triangle in pixels
   */
  int max_x, max_y, size;

  Vector crtSpeed;

 public:
  /**
   * @brief Construct a new Triangle object
   *
   * @param x Initial x-coordinate for the Triangle object.
   * @param y Initial y-coordinate for the Triangle object.
   */
  Triangle(int x, int y) : max_x(x), max_y(y), size(30), crtSpeed(0, 100) {
    pt = Point(rand() % x, rand() % y);
  }

  /**
   * @brief draws the triangle object to the display, if out of bounds returns
   * to the top
   */
  void draw() {
    if (pt.y > max_y) {
      pt.y = -size;
      pt.x = rand() % max_x;
    }
    al_draw_filled_triangle(pt.x, pt.y, pt.x + size, pt.y, pt.x + (size / 2),
                            pt.y + size, al_map_rgb(0, 0, 255));
  }

  /**
   * @brief Updates the triangle's position over time, i.e.  \f$pt = pt +
   * crtSpeed * dt\f$.
   *
   * @param dt Change in time, in seconds, since last update.
   */
  void update(double dt) { pt = pt + crtSpeed * dt; }
};

#endif

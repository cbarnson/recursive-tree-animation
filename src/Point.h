/**
 * @file Point.h
 * @author C. Barnson (cbarnson@outlook.com)
 * @brief Describes a position on a 2D grid.
 * @version 0.1
 * @date 2019-01-11
 *
 * @copyright Copyright (c) 2019
 *
 */
#ifndef _POINT_H
#define _POINT_H

#include "Vector.h"

/**
 * @struct Point
 * @brief represents a position on the display (grid)
 */
struct Point {
  double x;
  double y;
  /**
   * @brief Constructor
   * @param
   */
  Point(double a = 0.0, double b = 0.0) : x(a), y(b){};

  /**
   * @brief adds the value of member x of v to this objects member x, and
   * adds the value of member y of v to this objects member y
   * @param v represents the change in position for this Point object
   * @return Point
   */
  Point operator+(Vector v) { return Point(x + v.x, y + v.y); }
};

#endif

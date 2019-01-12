/**
 * @file Line.h
 * @author C. Barnson (cbarnson@outlook.com)
 * @brief Represents a straight line in 2D.
 * @version 0.1
 * @date 2019-01-11
 *
 * @copyright Copyright (c) 2019
 *
 */
#ifndef _LINE
#define _LINE

#include <cmath>

#include "Point.h"

const float PI = 3.14159265;

/**
 * @struct _line
 * @brief represents a straight line from the Point object _start to the Point
 * object _end with a certain slope
 */

struct _line {
  /**
   * @var Point _start
   * represents the start point
   * @var Point _end
   * represents the end point
   */
  Point _start, _end;

  _line();
  _line(Point a, Point b) : _start(a), _end(b){};

  /**

   * @brief finds the scalar distance between the two points
   * @param none
   * @return value of type double
   */
  double length() {
    return sqrt(pow(_end.y - _start.y, 2) + pow(_end.x - _start.x, 2));
  }

  /**

   * @brief calculates the new angle (in radians)
   * @param change_in_angle the change in angle (added; counter-clockwise
   * change)
   * @return double value representing radians in the range [-PI, PI]
   */
  double get_angle_ccw(double change_in_angle) {
    return -(atan2(_start.y - _end.y, _end.x - _start.x) + change_in_angle);
  }

  /**

   * @brief calculates the new angle (in radians)
   * @param change_in_angle the change in angle (subtracted; clockwise change)
   * @return double value representing radians in the range [-PI, PI]
   */
  double get_angle_cw(double change_in_angle) {
    return -(atan2(_start.y - _end.y, _end.x - _start.x) - change_in_angle);
  }

  /**

   * @brief calculates the position of the endpoint for the new line with some
   * change in angle
   * @param change_in_angle the change in angle (radians)
   * @param new_length the straight line distance from start to end for the new
   * line
   * @return Point object
   */
  Point get_endpoint_ccw(double change_in_angle, double new_length) {
    return Point(_end.x - new_length * cos(get_angle_ccw(change_in_angle)),
                 _end.y - new_length * sin(get_angle_ccw(change_in_angle)));
  }

  /**

   * @brief calculates the position of the endpoint for the new line with some
   * change in angle
   * @param change_in_angle the change in angle (radians)
   * @param new_length the straight line distance from start to end for the new
   * line
   * @return Point object
   */
  Point get_endpoint_cw(double change_in_angle, double new_length) {
    return Point(_end.x - new_length * cos(get_angle_cw(change_in_angle)),
                 _end.y - new_length * sin(get_angle_cw(change_in_angle)));
  }
};

#endif

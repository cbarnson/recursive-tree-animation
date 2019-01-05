/**
 * @file Point.h
 * @brief Definition of the Point struct
 *  
 * This contains the public member variables of the Point struct
 * describes a position on a grid
 *
 * @author Cody Barnson
 * @bug No known bugs
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
    * @fn Point(double a, double b)
    * @brief Constructor
    * @param 
    */
Point(double a=0.0, double b=0.0): x(a), y(b) {};
   
   /**
    * @fn Point operator + (Vector v)
    * @brief adds the value of member x of v to this objects member x, and
    * adds the value of member y of v to this objects member y
    * @param v represents the change in position for this Point object
    * @return Point
    */
   Point operator+(Vector v) {
      return Point(x + v.x, y + v.y);
   }
};

#endif
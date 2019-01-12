#ifndef DRAWABLE_H
#define DRAWABLE_H

/**
 * @class Drawable
 * @brief interface for drawable objects
 *
 * provides the declaration of the draw function
 */
class Drawable {
 public:
  /**


   * @brief virtual function to draw derived objects
   */
  virtual void draw() = 0;
};

#endif

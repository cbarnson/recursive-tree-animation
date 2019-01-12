/**
 * @file Display.cc
 * @author C. Barnson (cbarnson@outlook.com)
 * @brief Display window.
 * @version 0.1
 * @date 2019-01-11
 *
 * @copyright Copyright (c) 2019
 *
 */
#include <allegro5/allegro_primitives.h>
#include <cstdlib>
#include <iostream>

#include "Display.h"

/**
 * @brief Construct a new Display:: Display object
 *
 * @param w width of the display window
 * @param h height of the display window
 */
Display::Display(int w, int h) {
  width = w;
  height = h;

  al_init();

  // if the display cannot be initialized, we should throw an
  // exception. We will deal with exceptons later in the course, so
  // for now, we simply exit
  if ((display = al_create_display(width, height)) == NULL) {
    std::cerr << "Cannot initialize the display" << std::endl;
    exit(1);  // non-zero argument means "trouble"
  }

  al_init_primitives_addon();
}

/**
 * @brief Destroy the Display:: Display object
 *
 */
Display::~Display() {
  al_destroy_display(display);
}

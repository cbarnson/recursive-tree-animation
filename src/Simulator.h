/**
 * @file Simulator.h
 * @author C. Barnson (cbarnson@outlook.com)
 * @version 0.1
 * @date 2019-01-11
 *
 * @copyright Copyright (c) 2019
 *
 */
#ifndef __SIMULATOR_H
#define __SIMULATOR_H

#include <allegro5/allegro.h>
#include "Display.h"

/**
 * @brief Simulator object.  Sets up Allegro library, and runs the main
 * simulation loop.
 *
 */
class Simulator {
 private:
  int framesPerSec;  /// the rendering frequency

  ALLEGRO_TIMER *timer;             /// generates events for the simulation
  ALLEGRO_EVENT_QUEUE *eventQueue;  /// event storage

 public:
  /**
   * @brief Construct a new Simulator object, and initialize the Allegro
   * library.
   *
   * @param d Display object.
   * @param fps Frames per second.
   */
  Simulator(const Display &d, int fps);

  /**
   * @brief Destroy the Simulator object, free all Allegro resources allocated
   * by constructor.
   *
   */
  ~Simulator();

  /**
   * @brief Invoke to begin the simulation.  Main rendering loop.
   *
   */
  void run();

  /**
   * @brief Updates the state of the objects in the model.
   *
   * @param dt Change in time, in seconds, since last update.
   */
  virtual void updateModel(double dt) = 0;

  /**
   * @brief Draws the model to the display.
   *
   */
  virtual void drawModel() = 0;
};

#endif

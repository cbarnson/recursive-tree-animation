/**
 * @file Trunk.h
 * @author C. Barnson (cbarnson@outlook.com)
 * @brief Trunk of the tree object.
 * @version 0.1
 * @date 2019-01-11
 *
 * @copyright Copyright (c) 2019
 *
 */
#ifndef TRUNK_H
#define TRUNK_H

#include <cmath>
#include <ctime>
#include <list>
#include <memory>
#include <vector>

#include <allegro5/allegro_primitives.h>

#include "Drawable.h"
#include "Line.h"
#include "Point.h"
#include "Updateable.h"
#include "Vector.h"

/**
 * @class Trunk
 * @brief represents an elogating line from Point start to Point end in
 * total_time
 */
class Trunk : public Drawable, public Updateable {
 private:
  /**
   * @var start
   * represents the originating point of the growing line
   * @var end
   * represents the point at which the line stops growing
   * @var current
   * represents the point, somewhere along the straight line path from start to
   * end, that shows the growing line's progress from start to end
   */
  Point start, end, current;

  /**
   * @var growth
   * represents the change in position of the Point current in pixels per second
   */
  Vector growth;

  /**
   * @var L
   * scalar value that represents the maximum length of the Trunk object from
   * start to end
   * @var total_time
   * represents the time, in seconds, for the Point current to travel from start
   * to end
   * @var branch_factor
   * value between 0 and 1 such branch_factor multiplied by the maximum length
   * of its parent equals the maximum length of the child Trunk
   * @var angle
   * represents the angle (in degrees; chosen at random between 10-30 in
   * main-line file) between a parent Trunk object and its child Trunk objects
   */
  double L, total_time, branch_factor, angle;

  /**
   * @var rec_depth
   * represents the recursive depth limit, beyond which the recursive
   * 'branching' stops
   */
  int rec_depth;

  /**
   * @var expanded
   * each Trunk object will only branch off a maximum of 1 time
   * expanded = true, indicates the Trunk has undergone expansion
   * expanded = false, indicates it has not yet expanded
   */
  bool expanded;

  /**
   * @var branch
   * represents the child Trunk objects belonging to this Trunk object
   */
  std::list<std::shared_ptr<Trunk> > branch;

 public:
  /**


   * @brief Constructor
   *
   * Point current is initalized to Point start
   * growth is initalized to the distance between start and end divided by the
   * total time expanded is initalized to false
   */
  Trunk(Point p1, Point p2, double time, double bf, double a, int rd)
      : start(p1),
        end(p2),
        total_time(time),
        branch_factor(bf),
        angle(a),
        rec_depth(rd) {
    current = start;
    L = sqrt(pow(end.y - start.y, 2) + pow(end.x - start.x, 2));
    growth =
        Vector((end.x - start.x) / total_time, (end.y - start.y) / total_time);
    expanded = false;
  }

  /**
   * @brief called when Point current has reached one third of the distance from
   * start to end randomly chooses to add between 1-4 child Trunk objects to the
   * branch list
   *
   * child Trunk objects have the possibility to appear in 4 positions as
   * follows: 1/3 of the max length, angled to the left 1/3 of the max length,
   * angled to the right 1/6 of the max length, angled to the left 1/6 of the
   * max length, angled to the right
   */
  void addBranch() {
    Point current_2 = start + growth * (total_time / 6);

    Point end_extended = end + growth * (total_time / 3);
    Point end_extended_2 = end + growth * (total_time / 6);

    _line end_ext(current, end_extended);
    _line end_ext_2(current_2, end_extended_2);
    double radians = angle * PI / 180.0;

    Point p;
    std::vector<Point> pts;

    /**< position 1 : @1/3 L, angled to left of trunk */
    p = Point(current.x, current.y);
    pts.push_back(p);
    p = end_ext.get_endpoint_ccw(radians, branch_factor * L);
    pts.push_back(p);

    /**< position 2 : @1/6 L, angled to the right of the trunk */
    p = Point((current.x + start.x) / 2, (current.y + start.y) / 2);
    pts.push_back(p);
    p = end_ext_2.get_endpoint_cw(radians, branch_factor * L);
    pts.push_back(p);

    /**< position 3 : @1/6 L, angled to the left of the trunk */
    p = Point((current.x + start.x) / 2, (current.y + start.y) / 2);
    pts.push_back(p);
    p = end_ext_2.get_endpoint_ccw(radians, branch_factor * L);
    pts.push_back(p);

    /**< position 4 : @1/3 L, angled to right of trunk */
    p = Point(current.x, current.y);
    pts.push_back(p);
    p = end_ext.get_endpoint_cw(radians, branch_factor * L);
    pts.push_back(p);

    int branch_config = rand() % 4 + 1;
    std::vector<Point>::iterator it1 = pts.begin();
    std::vector<Point>::iterator it2 = pts.begin() + 1;

    for (int i = 0; i < branch_config; i++) {
      branch.push_back(std::make_shared<Trunk>(
          (*it1), (*it2), total_time, branch_factor, angle, rec_depth - 1));
      ++it1;
      ++it1;
      ++it2;
      ++it2;
    }
  }

  /**


   * @brief draws a straight line from start to current, then iteratively calls
   * draw on each of the child Trunk objects in the branch container
   */
  void draw() {
    al_draw_line(start.x, start.y, current.x, current.y,
                 al_map_rgb(34, 128, 34), 3);
    if (!branch.empty()) {
      for (auto it = branch.begin(); it != branch.end(); ++it) {
        (*it)->draw();
      }
    }
  }

  /**


   * @brief updates the position of current according to the Trunk objects
   * growth rate and time passed dt; updates the position of all the child Trunk
   * objects in the branch container;
   *
   */
  void update(double dt) {
    double start_to_end =
        sqrt(pow(start.x - end.x, 2) + pow(start.y - end.y, 2));
    double start_to_current =
        sqrt(pow(start.x - current.x, 2) + pow(start.y - current.y, 2));

    if (start_to_current < start_to_end) {
      current = current + growth * dt;
    } else {
      current = end;
    }

    if (!branch.empty()) {
      for (auto it = branch.begin(); it != branch.end(); ++it) {
        (*it)->update(dt);
      }
    }

    if (!expanded && rec_depth > 0) {
      start_to_current =
          sqrt(pow(start.x - current.x, 2) + pow(start.y - current.y, 2));
      if (start_to_current > (L / 3)) {
        addBranch();
        expanded = true;
      }
    }
  }
};

#endif

/*
 * Copyright (c) 2019: Gustav Björdal, gustav.bjordal@it.uu.se.
 *
 * This file is part of course 1DL481 at Uppsala University, Sweden.
 *
 * Permission is hereby granted only to the registered students of that course to use this file, for
 * a homework assignment.
 *
 * The copyright notice and permission notice above shall be included in all copies and extensions
 * of this file, and those are not allowed to appear publicly on the internet, both during a course
 * instance and forever after.
 *
 */


/**
 * Some representation of a move.
 * 
 * It will most likely be useful to also have a cost field associated with the move so that, after
 * performing a probe, the cost associated with the move can be checked without requiring
 * re-probing.
 *
 */
public class Move {

  /* ... */
  private Cost cost;

  public Move(/* ... */) {
  }

  public Cost getCost() {
    return cost;
  }

  public void setCost(Cost cost) {
    this.cost = cost;
  }
}

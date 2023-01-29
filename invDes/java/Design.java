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
 * Most of this codes assumes that the investment design is represented using a 2D grid, but it can
 * easily be changed to also support a set representation. Feel free to change anything in this file
 * if necessary.
 *
 * Don't forget to add your own helper methods in addition to the ones here.
 */
class Design {

  /* ... */
  private DotProduct dotProduct;
  private final int v, b, r;

  // Don't forget to use incremental data structures to efficiently determine, given a move, which
  // rows in dotProduct that change.

  Design(int v, int b, int r) {
    this.v = v;
    this.b = b;
    this.r = r;
    /* ... */
    this.init();
  }

  /**
   * Create a random initial assignment, setup incremental data structures for detminening which row
   * changes given a move, and setup the dotProduct object.
   */
  void init() {
    /* ... */
  }

  /**
   * Probe a move. This does not update change any internal data structures (or: any changes are
   * undone before returning the cost)
   *
   * @param m
   */
  Cost probeMove(Move m) {
    /* ... */

    // Allocating an new object each probe is unnecessarily expensive.
    // This can be worked around by instead updating some static object.
    // However, for this assignment allocating here should be fine...
    return new Cost(/* ... */);
  }

  /**
   * Commits a move. This updates internal data structures and performs any necessary computations
   * that may speed up future probes.
   *
   * @param m
   */
  void commitMove(Move m) {
    /* ... */
  }

  /**
   * Helper method.
   * 
   * Given a move, make the necessary calls to dotProduct.increment() and dotProduct.decrement()
   * such that dotProduct is up to date.
   *
   * @param m
   */
  private void updateDotProductFromMove(Move m) {
    /* ... */
  }

  /**
   * Saves the current assignment such that it can be restored later. Call this when finding a new
   * overall best assignment.
   */
  void saveDesign() {
    /* ... */
  }

  /**
   * Restores the saved assignment such that search can continue from it. Call this when doing an
   * intensification step or for printing the best found solution at the end of the search.
   */
  void restoreSavedDesign() {
    /* ... */
  }

  /**
   *
   * @return the current design in the format required by the assignment.
   */
  @Override
  public String toString() {
    return "/*...*/";
  }

}

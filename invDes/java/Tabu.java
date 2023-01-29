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
 * This class assumes that the investment design is represented using a 2D grid. It can easily be
 * adapted to deal with a set representation of the investment design.
 *
 * Feel free to change anything in this file if necessary.
 */
class Tabu {
  private final int tenure;
  private final int v, b, r;

  public Tabu(int tenure, int v, int b, int r) {
    this.tenure = tenure;
    this.v = v;
    this.b = b;
    this.r = r;
    /* ... */
  }

  /**
   * Check if the cell at position (row, column) is tabu at iteration it.
   *
   * @param row
   * @param column
   * @param it     The current iteration.
   * @return
   */
  boolean isTabu(int row, int column, int it) {
    /* ... */
    return false;
  }

  /**
   * Make the cell at position (row, column) tabu for the next tenure iterations after it.
   * 
   * @param row
   * @param column
   * @param it     The current iteration.
   */
  void makeTabu(int row, int column, int it) {
    /* .. */
  }

}

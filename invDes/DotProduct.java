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
 * Incremental data structure for maintaining the maximum dot product of a design.
 *
 * By incrementally updating the maximum dot product of a design, there is no need to recompute it
 * from scratch each iteration, taking something that would have a high computational complexity and
 * making it much lower. Make sure functions of this class are as efficient as possible!
 *
 * Feel free to change anything in this file if necessary.
 */
class DotProduct {
  private final int v, b, r;

  /* ... */

  DotProduct(int v, int b, int r) {
    this.v = v;
    this.b = b;
    this.r = r;
    /* ... */
  }

  /**
   * Given a design (which has a current assignment), initialise the incremental data structures.
   * Basically this will compute all dot products and store them somehow.
   *
   * Note that this method should ideally only be called once. But can be called multiple times in
   * case of restarts.
   * 
   * @param design
   */
  void initialise(Design design) {
    /* ... */
  }

  /**
   * Notify that the dot product between row row1 and row2 has increased by 1.
   * 
   * Updates the internal data structures and possibly the maximum dot product to reflect this.
   *
   * This can be done in constant time.
   * 
   * @param row1
   * @param row2
   */
  void increment(int row1, int row2) {
    /* ... */
  }

  /**
   * Notify that the dot product between row row1 and row2 has decreased by 1.
   * 
   * Updates the internal data structures and possibly the maximum dot product to reflect this.
   *
   * This can be done in constant time.
   * 
   * @param row1
   * @param row2
   */
  void decrement(int row1, int row2) {
    /* ... */
  }

  /**
   * Note that you probably want to use the getCost() method in case the cost function is something
   * more complex than just the current maximum dot product.
   *
   * This should take constant time.
   * 
   * @return The current maximum dot product
   */
  int getMaximumDotProduct() {
    /* ... */
    return -1;
  }

  /**
   * This should take constant time.
   * 
   * @return The current cost.
   */
  Cost getCost() {
    return new Cost(/* ... */);
  }
}

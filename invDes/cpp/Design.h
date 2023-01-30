#pragma once

#include <iostream>
#include <string>

#ifndef DOTP
#include "DotProduct.h"
#endif

class Design {
private:
int v;
int b;
int r;

Design(int v, int b, int r);
void init();
Cost probeMove(Move m);


};

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
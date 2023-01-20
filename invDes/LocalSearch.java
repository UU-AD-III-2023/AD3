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
 * We here assume that tabu search is used. While it is highly recommended that you use tabu search
 * for this assignment, you are allowed to implement simulated annealing instead.
 *
 */
class LocalSearch {
  private final Design design;
  private final int v, b, r, lb;
  private final Tabu tabu;
  private int it, bestLambda;
  private int alpha, beta;

  public LocalSearch(int v, int b, int r, int alpha, int beta) {
    this.v = v;
    this.b = b;
    this.r = r;
    this.lb = calculateLb();
    this.design = new Design(v, b, r);
    this.tabu = new Tabu(0/* ... */, v, b, r);
    this.it = 1;
    this.alpha = alpha;
    this.beta = beta;
  }

  /**
   * @return the lower bound lambda according to the formula in the assignment.
   */
  private int calculateLb() {
    /* ... */
    return 0;
  }

  /**
   * Do local search.
   */
  void run() {

    /* ... */

    System.out.println(v + " " + b + " " + r + " " + lb + " " + bestLambda);
    design.restoreSavedDesign();
    System.out.println(design);
  }

  /**
   * Optional helper method.
   *
   * Returns the best (non-tabu) neighbour in the neighbourhood. This requires a complete
   * exploration (probing) of the neighbourhood.
   * 
   * Note that the neighbourhood is usually not explicitly represented but is rather defined as the
   * set of moves that can be performed on the current assignment.
   *
   * @return the best (non-tabu) neighbour
   */
  private Move getBestNeighbour(/* ... */) {
    /* ... */
    return new Move();
  }

  /**
   * Optional helper method.
   *
   * Returns the first (non-tabu) improving neighbour in the neighbourhood. Think about how
   * exploration order affects the search. What does this return when no neighbour is improving?
   * 
   *
   * @return the first (non-tabu) improving neighbour
   */
  private Move getFirstImprovingNeighbour(/* ... */) {
    /* ... */
    return new Move();
  }

  /**
   * Optional helper method.
   *
   * Returns a random neighbour in the neighbourhood. This is mainly used for simulated annealing
   * (not recommented for this assignment).
   *
   * Make sure that this method never returns the same move twice unless a commit has been made
   * inbetween!
   *
   * @return a random neighbour.
   */
  private Move getRandomNeighbour(/* ... */) {
    /* ... */
    return new Move();
  }

  /**
   *
   * @return the current design in the format required by the assignment.
   */
  public String getOutput() {
    design.restoreSavedDesign();
    return v + " " + b + " " + r + " " + lb + " " + bestLambda + "\n" +design.toString();
  }
}

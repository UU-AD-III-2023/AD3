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
 * Main entry point
 *
 * This skeleton code is just a starting point and a suggestion on how to structure a local search
 * algorithm. There are better ways to do it.
 *
 * Feel free to completely ignore the skeleton code and implement something better. The only thing
 * we impose is the input and output format of your program.
 *
 */
public class InvDes {

  private static final int[][] instances = new int[][] {{10, 30, 9}, {12, 44, 11}, {15, 21, 7},
      {16, 16, 6}, {9, 36, 12}, {11, 22, 10}, {19, 19, 9}, {10, 37, 14}, {8, 28, 14}, {10, 100, 30},
      {6, 50, 25}, {6, 60, 30}, {11, 150, 50}, {9, 70, 35}, {10, 350, 100}, {13, 250, 80},
      {10, 325, 100}, {15, 350, 100}, {9, 300, 100}, {12, 200, 75}, {10, 360, 120}};



  public static void main(String[] args) {
    // Paramters for tuning local search algorithm, does not have to be int.
    int alpha = 0;
    int beta = 0;

    if (args.length == 3) {
      int v = Integer.parseInt(args[0]);
      int b = Integer.parseInt(args[1]);
      int r = Integer.parseInt(args[2]);
      runSolver(v, b, r, alpha, beta);
    } else {
      // This is just an example of how to run all instances, you probably want to do
      // something more interesting in order to gather the required statistics.
      /* ... */
      for (int[] instance : instances) {
        runSolver(instance[0], instance[1], instance[2], alpha, beta);
      }
    }
  }

  private static void runSolver(int v, int b, int r, int alpha, int beta) {
    // Todo: Add asserts
    System.out.println("Solving instance v: " + v + " b: " + b + " r: " + r
        + ". With parameters alpha: " + alpha + " beta: " + beta);
    LocalSearch s = new LocalSearch(v, b, r, alpha, beta);
    s.run();
  }
}

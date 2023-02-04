#pragma once

#include <iostream>
#include <string>
#include <cmath>

#ifndef DOTP
#include "DotProduct.h"
#endif
#ifndef MOVE
#include "Move.h"
#endif
#ifndef DESIGN
#include "Design.h"
#endif
#ifndef TABU
#include "Tabu.h"
#endif

using std::string;

class LocalSearch {
private:
  Design design;
  int v,b,r,lb;
  Tabu tabu;
  int it, bestLambda;
  int alpha, beta;

  vector<Move> possibleMoves;

public:
  LocalSearch();
  LocalSearch(int v, int b, int r, int alpha, int beta);
  int calculateLb();
  void run();
  Move getBestNeighbour();
  Move getFirstImprovingNeighbour();
  Move getRandomNeighbour();
  string getOutput();
};

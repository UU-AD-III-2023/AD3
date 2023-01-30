#pragma once

#include <iostream>
#include <string>

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

public:
  LocalSearch(int v, int b, int r, int alpha, int beta);
  int calculateLb();
  void run();
  Move getBestNeighbour();
  Move getFirstImprovingNeighbour();
  Move getRandomNeighbour();
  string getOutput();
};

// // Class SLS
// class LocalSearch {
//   public: 
//   int v;
//   int b;
//   int r;
//   int alpha;
//   int beta;

//   int bestlambda;
//   int lb;

//   LocalSearch(int v, int b, int r, int alpha, int beta) {
//     v = v;
//     b = b;
//     r = r;
//     lb = calculateLb();
//     // design = new Design(v, b, r);
//     // tabu = new Tabu(0/* ... */, v, b, r);
//     // it = 1;
//     alpha = alpha;
//     beta = beta;
//   }

//   int calculateLb(){
//     return 0;
//   }
//   void run() {

//     /* ... */

//     printf("", v, " ", b, " ", r, " ", lb, " ", bestLambda, "");
//     design.restoreSavedDesign();
//     printf(design);
//   }
// };
// Initialise Input Values
// Calculate lb

// Initialise Matrix

// Tabu
// Finding Cost of neighbours 
  //Move
    // for each row, get all neighbours and dotproduct -> store lowest cost
  // Cannot reach optimal after full neighbourhood search, remember best case, randomise board
  // redo until timeout or proven optimal reached

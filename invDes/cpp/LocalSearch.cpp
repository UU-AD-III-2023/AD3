#include "LocalSearch.h"
#include <sstream>

using std::stringstream;

LocalSearch::LocalSearch(int v, int b, int r, int alpha, int beta) {
  this->v = v;
  this->b = b;
  this->r = r;
  this->lb = calculateLb();
  this->design = Design(v, b, r);
  this->tabu = Tabu(0/* ... */, v, b, r);
  this->it = 1;
  this->alpha = alpha;
  this->beta = beta;
}

LocalSearch::LocalSearch(){}

// def lb(r, v, b):
//     a2 = (r*v) % b
//     if a2 != 0:
//         a1 = ((r*v) // b + 1)**2
//     else:
//         a1 = ((r*v) // b)**2
//     a3 = ((r*v) // b)**2
//     a4 = b - (r*v) % b
//     up = a1*a2 + a3 *a4 - r*v
//     down = v*(v-1)
//     if up % down == 0:
//         return up // down
//     else:
//         return up // down + 1

int LocalSearch::calculateLb(){
  int rv = r*v;

  int top = std::pow(ceil((rv)/b),2)*(rv%b)+pow(floor(rv/b),2)*(b-(rv%b))-rv;
  int bot = (v*(v-1));
  return ceil(top/bot);
};

void LocalSearch::run(){
  design.init();

  string output = getOutput();
  std::cout << "\nlb: " << lb;
  std::cout << output;

};
Move LocalSearch::getBestNeighbour(){
  return Move();
};
Move LocalSearch::getFirstImprovingNeighbour(){
  return Move();
};
Move LocalSearch::getRandomNeighbour(){
  return Move();
};
string LocalSearch::getOutput(){
  return design.toString();
};

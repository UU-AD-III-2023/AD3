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

int LocalSearch::calculateLb(){
  int rv = r*v;

  int top = std::pow(ceil((rv)/b),2)*(rv%b)+pow(floor(rv/b),2)*(b-(rv%b))-rv;
  int bot = (v*(v-1));
  return ceil(top/bot);
};

void LocalSearch::run(){
  std::cout << "\ninitialising...\n";
  design.init();
  // std::cout << "nice";
  this->possibleMoves = design.makeMoves();
  this->bestLambda=design.getCurrentLambda();


  while (bestLambda > lb) {
    Move itMove = getFirstImprovingNeighbour();
    if (itMove.row==-1){
      std::cout<<"NO MORE FIRST IMPROVING, breaking loop...\n" 
      << "====================================================================\n";
      break;
    }
    design.commitMove(itMove);
    this->bestLambda=design.getBestLb();

    std::cout << bestLambda << "\n";
  }
  string output = getOutput();
  std::cout << "\nlb: " << lb << "\n";
  std::cout << bestLambda;
  std::cout << output;

};
Move LocalSearch::getBestNeighbour(){
  // vector<int> expensive = design.getExpensiveRows();
  Cost cost;
  int bestReduction = 0;
  int bestMoveIdx = -1;
  for (int i=0; i< int(possibleMoves.size());i++){
    cost = design.probeMove(possibleMoves[i]);
    possibleMoves[i].setCost(cost);
    if (cost.improvement > bestReduction) {
      bestMoveIdx=i;
      bestReduction = cost.improvement;
    }
  }
  return possibleMoves[bestMoveIdx];
};
Move LocalSearch::getFirstImprovingNeighbour(){
  // vector<int> expensive = design.getExpensiveRows();
  int bestReduction = 0;
  for (int i=0; i< int(possibleMoves.size());i++){
    Cost cost = design.probeMove(possibleMoves[i]);
    possibleMoves[i].setCost(cost);
    if (cost.improvement > bestReduction) {
      return possibleMoves[i];
    }
  }
  return Move(-1,-1,-1);
};
Move LocalSearch::getRandomNeighbour(){
  //Random algo
  //return possibleMoves[i];
  return Move();
};
string LocalSearch::getOutput(){
  return design.toString();
};

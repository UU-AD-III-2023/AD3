#include "LocalSearch.h"
#include <sstream>
#include <random>
#include <algorithm>

using std::stringstream;

LocalSearch::LocalSearch(int v, int b, int r, int alpha, int beta) {
  this->v = v;
  this->b = b;
  this->r = r;
  this->lb = calculateLb();
  this->design = Design(v, b, r);
  this->tabu = Tabu(0/* ... */, v, b, r);
  this->it = 0;
  this->alpha = alpha;
  this->beta = beta;
  this->tabu = Tabu(0,v,b,r);
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
  this->possibleMoves = design.makeMoves();
  this->bestLambda=design.getCurrentLambda();

  int repeat = v/2;
  while (bestLambda > lb) {
    this->it++;
    Move itMove = getFirstImprovingNeighbour();
    if (itMove.row==-1){
      if (repeat) {
        repeat--;
        int randn=0;
        for (int i=0;i<rand()%(10/3);i++){
          randn = rand()%int(possibleMoves.size());
        }
        design.commitMove(possibleMoves[randn]);
        std::cout<<"Tabu: "<<it;
        tabu.makeTabu(possibleMoves[randn],it);
        itMove = possibleMoves[randn];
      } else {
        std::cout<<"NO MORE FIRST IMPROVING, breaking loop...\n" 
        << "====================================================================\n";
        break;
      }
    }
    design.commitMove(itMove);
    this->bestLambda=design.getBestLb();
    std::cout << bestLambda << "\n";
  }
  string output = getOutput();
  std::cout << "\nlb: " << lb << "\n";
  std::cout << bestLambda << "\x1b[32m";
  std::cout << output << "\x1b[0m";

};
Move LocalSearch::getBestNeighbour(){
  // vector<int> expensive = design.getExpensiveRows();
  Cost cost;
  Cost bestCost = Cost();
  int bestMoveIdx;
  for (int i=0; i< int(possibleMoves.size());i++){
    cost = design.probeMove(possibleMoves[i]);
    possibleMoves[i].setCost(cost);
    if (cost.isBetterThan(bestCost) && !tabu.isTabu(possibleMoves[i],it)) {
      bestMoveIdx=i;
      bestCost = cost;
      std::cout<<" improved: " << bestCost.improvement<< "\n";
    }
  }
  if (bestCost.improvement==0) {
    return Move(-1,-1,-1);
  }
  return possibleMoves[bestMoveIdx];
};
Move LocalSearch::getFirstImprovingNeighbour(){
  // vector<int> expensive = design.getExpensiveRows();
  Cost bestCost = Cost();
  for (int i=0; i< int(possibleMoves.size());i++){
    Cost cost = design.probeMove(possibleMoves[i]);
    possibleMoves[i].setCost(cost);
    if (cost.isBetterThan(bestCost)) {
      if (!tabu.isTabu(possibleMoves[i],it)){
        return possibleMoves[i];
      } else {
        return possibleMoves[i+1?i-1:i==0];
      }
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

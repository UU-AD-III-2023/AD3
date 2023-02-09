#include "LocalSearch.h"
#include <sstream>
#include <random>
#include <algorithm>
#include <ctime>

using std::stringstream;
using std::clock_t;

auto rd = std::random_device {}; 
auto rng = std::default_random_engine { rd() };

LocalSearch::LocalSearch(int v, int b, int r, int alpha, int beta, bool printMode) {
  this->v = v;
  this->b = b;
  this->r = r;
  this->lb = calculateLb();
  this->design = Design(v, b, r);
  this->it = 0;
  this->alpha = alpha;
  this->beta = beta;
  this->tabu = Tabu(alpha);
  this->printMode = printMode;
}

LocalSearch::LocalSearch(){}

int LocalSearch::calculateLb(){
  int rv = r*v;

  int top = std::pow(ceil((rv)/b),2)*(rv%b)+pow(floor(rv/b),2)*(b-(rv%b))-rv;
  int bot = (v*(v-1));

  std::cout  << "\x1b[33m" << " ideal-lb: " << ceil(top/bot) << "\x1b[0m";
  return ceil(top/bot);
};

void LocalSearch::randInit(){
  design.init();
  this->possibleMoves = design.makeMoves();
  this->bestLambda=design.getCurrentLambda();
}

int LocalSearch::run(){
  std::cout << "\ninitialising...";
  randInit();
  // int alph = v/2;
  clock_t start = std::clock();
  int thisIter = alpha;

  while (bestLambda > lb && ((clock() - start) < CLOCKS_PER_SEC*300)) {
    this->it++;
    Move itMove = getFirstImprovingNeighbour();
    if (itMove.row==-1){
      if (thisIter) {
        thisIter--;
        design.saveDesign();
        randInit();

        // std::cout<<"Tabu: "<<it;
        // tabu.makeTabu(possibleMoves[randn],it);
        // itMove = possibleMoves[randn];
      } else {
        // std::cout<<"NO MORE FIRST IMPROVING, breaking loop...\n" 
        // << "====================================================================\n";
        break;
      }
    }
    if (itMove.row!=-1){
      design.commitMove(itMove);
    }
    this->bestLambda=design.getCurrentLambda();
    // std::cout << bestLambda << "\n";
  }
  design.restoreSavedDesign();
  string output = getOutput();
  // std::cout << "currentBest: " << bestLambda ;
  // long totalsecs = (clock() - start)/CLOCKS_PER_SEC;
  std::cout << "\x1b[32m" << output << " TIMING: " << ((clock() - start)*1.0/CLOCKS_PER_SEC) << " seconds\x1b[0m";
  return bestLambda;
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
      // std::cout<<" improved: " << bestCost.improvement<< "\n";
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
  Move out;
  std::uniform_int_distribution<int> rgen(1,int(possibleMoves.size()));
  out = possibleMoves[rgen(rng)];
  return out;
};
string LocalSearch::getOutput(){
  return design.toString(printMode);
};

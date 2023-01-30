#include "LocalSearch.h"

LocalSearch::LocalSearch(int v, int b, int r, int alpha, int beta){
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

int LocalSearch::calculateLb(){
  return 0;
};
void LocalSearch::run(){

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
  return ("",v," ",b," ",r," ",lb," ",bestLambda,"\n ",design.toString());
};

#include "Tabu.h"
Tabu::Tabu(){};

Tabu::Tabu(int tenure, int v, int b, int r){
    this->tenure = tenure;
    // this->Tmove = move;
    this->numMoves = (v*r*(b-r))*v*b;    
}

bool Tabu::isTabu(Move move, int it){
    if ( (Tmove.row == move.row || Tmove.oldIdx==move.oldIdx) && tenure >= it) {
        return true;
    }
    return false;
}

void Tabu::makeTabu(Move move, int it){
    this->Tmove = move;
    int total = it + numMoves;
    this->tenure = total;
}
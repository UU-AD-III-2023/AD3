#include "Move.h"

/**
 * Some representation of a move.
 * 
 * It will most likely be useful to also have a cost field associated with the move so that, after
 * performing a probe, the cost associated with the move can be checked without requiring
 * re-probing.
 *
 */
Move::Move(){
};

Move::Move(int row, int oldIdx, int newIdx){
    this->row=row;
    this->oldIdx=oldIdx;
    this->newIdx=newIdx;
};

Cost Move::getCost(){
    return cost;
};

void Move::setCost(Cost cost){
    this->cost = cost;
};
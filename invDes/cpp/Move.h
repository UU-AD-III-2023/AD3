#pragma once

#include <iostream>

#ifndef COST
#include "Cost.h"
#endif

/**
 * Some representation of a move.
 * 
 * It will most likely be useful to also have a cost field associated with the move so that, after
 * performing a probe, the cost associated with the move can be checked without requiring
 * re-probing.
 *
 */
class Move {
public:
    int row;
    int oldIdx;
    int newIdx;

    Cost cost;
    Move();
    Cost getCost();
    void setCost(Cost cost);
};

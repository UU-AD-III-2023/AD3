#pragma once

#include <vector>
#include <iostream>
#ifndef MOVE
#include "Move.h"
#endif

using std::vector;

class Tabu {
    private:
    int tenure;
    vector<Move> tabooMoves;
    vector<int> tenures;

    public:
    Tabu();
    Tabu(int tenure);
    bool isTabu(Move move, int it);
    void makeTabu(Move move, int it);
    // Tabu(int tenure, int v, int b, int r);
    // bool isTabu(int row, int column, int it);
    // void makeTabu(int row, int column, int it);
};

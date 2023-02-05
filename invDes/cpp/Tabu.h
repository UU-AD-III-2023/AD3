#pragma once

#include <iostream>
#ifndef MOVE
#include "Move.h"
#endif

class Tabu {
    private:
    int tenure;
    int numMoves;
    Move Tmove;
    // int v;
    // int b;
    // int r;

    public:
    Tabu();
    Tabu(int tenure,int v, int b, int r);
    bool isTabu(Move move, int it);
    void makeTabu(Move move, int it);
    // Tabu(int tenure, int v, int b, int r);
    // bool isTabu(int row, int column, int it);
    // void makeTabu(int row, int column, int it);
};

#pragma once

#include <iostream>
#ifndef MOVE
#include "Move.h"
#endif

#include <vector>

using std::vector;

class Tabu {
    private:
    int tenure;
    vector<Move> Tmove;
    vector<int> TabooTens;
    // int v;
    // int b;
    // int r;

    public:
    Tabu();
    Tabu(int tenure);
    bool isTabu(Move move, int it);
    void makeTabu(Move move, int it);
    // Tabu(int tenure, int v, int b, int r);
    // bool isTabu(int row, int column, int it);
    // void makeTabu(int row, int column, int it);
};

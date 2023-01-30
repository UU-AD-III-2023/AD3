#pragma once

#include <iostream>

class Tabu {
    private:
    int tenure;
    int v;
    int b;
    int r;

    public:
    Tabu(int tenure, int v, int b, int r);
    bool isTabu(int row, int column, int it);
    void makeTabu(int row, int column, int it);

};

#include "Tabu.h"
Tabu::Tabu(){};

Tabu::Tabu(int tenure, int v, int b, int r){
    this->tenure = tenure;
    this->v = v;
    this->b = b;
    this->r = r;
}

bool Tabu::isTabu(int row, int column, int it){
    if (row == column && column == it) {
        return true;
    }
    return false;
}

void Tabu::makeTabu(int row, int column, int it){
    this->r = row;
    this->b = column;
    this->v = it;
}
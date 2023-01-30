#include "Tabu.h"

Tabu::Tabu(int tenure, int v, int b, int r){
    this->tenure = tenure;
    this->v = v;
    this->b = b;
    this->r = r;
}

bool Tabu::isTabu(int row, int column, int it){
    return false;
}

void Tabu::makeTabu(int row, int column, int it){
    
}
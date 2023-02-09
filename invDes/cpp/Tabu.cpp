#include "Tabu.h"
Tabu::Tabu(){};

Tabu::Tabu(int tenure){
    this->tenure = tenure;
    this->tabooMoves={};
    this->tenures={};
}

bool Tabu::isTabu(Move move, int it){
    // for (int i=(int(tabooMoves.size())); i>=0; i--) {
    //     Move checkMove = tabooMoves[i];
    //     if (tenures[i] < it) {
    //         for (int j=0; j<=i;j++){
    //             tenures.erase(tenures.begin());
    //         }
    //         i = -1;
    //     }
    //     else if (checkMove.row==move.row && checkMove.newIdx==move.newIdx && checkMove.oldIdx==move.oldIdx){
    //         return true;
    //     }
    // }

    this->tabooMoves.push_back(move);
    return (it > 0);
}

void Tabu::makeTabu(Move move, int it){
    int total = it + tenure;
    this->tabooMoves.push_back(move);
    this->tenures.push_back(total);
}
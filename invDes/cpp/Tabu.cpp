#include "Tabu.h"
Tabu::Tabu(){};

Tabu::Tabu(int tenure){
    this->tenure = tenure;
    this->Tmove={};
    this->TabooTens={};
}

bool Tabu::isTabu(Move move, int it){
    int curSize = int(Tmove.size());
    if (curSize>=1){
        for (int i=curSize-1; i>=0; i--) {
            Move checkMove = Tmove[i];
            if (TabooTens[i] < it) {
                for (int j=0; j<=i;j++){
                    TabooTens.erase(TabooTens.begin());
                    Tmove.erase(Tmove.begin());
                }
                i = -1;
            }
            else if (checkMove.row==move.row && checkMove.newIdx==move.newIdx && checkMove.oldIdx==move.oldIdx){
                return true;
            }
        }
    }

    return (it < 0);
}

void Tabu::makeTabu(Move move, int it){
    int total = it + tenure;
    this->Tmove.push_back(move);
    this->TabooTens.push_back(total);
}
#pragma once

#include <iostream>
#include <string>

#ifndef DOTP
#include "DotProduct.h"
#endif
#ifndef MOVE
#include "Move.h"
#endif

using std::string;

class Design {
private:
int v;
int b;
int r;

public:
Design(int v, int b, int r);
void init();
Cost probeMove(Move m);
void commitMove(Move m);
void updateDotProductFromMove(Move m);
void saveDesign();
void restoreSavedDesign();
string toString();
};

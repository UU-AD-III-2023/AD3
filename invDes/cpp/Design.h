#pragma once

#include <iostream>
#include <string>
#include <vector>

#ifndef DOTP
#include "DotProduct.h"
// #endif
// #ifndef MOVE
#include "Move.h"
#endif

using std::string;
using std::vector;

class Design {
private:
int v;
int b;
int r;
vector<vector<int>> chkpt;

vector<vector<int>> invNorm;
vector<vector<int>> possibleNorm;

vector<vector<int>> selections;
vector<vector<int>> blank;

Matrix matrix;

public:
// baskets add investment
vector<vector<int>> portfolio;

Design();
Design(int v, int b, int r);
void init();
vector<Move> getNeighbours();
Cost probeMove(Move m);
void commitMove(Move m);
void updateDotProductFromMove(Move m);
void saveDesign();
void restoreSavedDesign();
string toString();
int dotCost(int row);
};

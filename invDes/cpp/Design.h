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
int bestLambda;

// vector<vector<int>> oriSel;
// vector<vector<int>> oriBlank;

Matrix matrix;

public:
// baskets add investment
vector<vector<int>> portfolio;
vector<vector<int>> chkpt;
vector<vector<int>> selections;
vector<vector<int>> blank;

int getCurrentLambda();
int getBestLb();
Design();
Design(int v, int b, int r);
void init();
vector<Move> makeMoves();
Cost probeMove(Move m);

vector<int> getExpensiveRows();

void commitMove(Move m);
void updateDotProductFromMove(Move m);
void saveDesign();
void restoreSavedDesign();
string toString(bool printMode);
int dotCost(int row);
int moveCost(vector<int> temp, int row);
};

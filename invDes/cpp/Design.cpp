#include "Design.h"
#include <sstream>
#include <random>
#include <algorithm>

using std::stringstream;

Design::Design(){}

Design::Design(int v, int b, int r) {
    this->v = v;
    this->b = b;
    this->r = r;
    /* ... */
}

int Design::getBestLb(){
    // int worst=0;
    // for (int i=0; i<v;i++){
    //     int tmp = dotCost(i);
    //     if (tmp>worst){
    //         worst=tmp;
    //     }
    // }
    // int lb = worst;
    // this->bestLambda=worst;
    return bestLambda;
}

/**
 * get the Cost of the board
 * 
 * @param row: Ignores this row for dot calculations
 */
int Design::dotCost(int row){
    int worst=0;
    for (int j =0; j<v;j++){
        int val=0;
        if (j!=row){
            matrix.dot_prod(portfolio[row], portfolio[j],val);
        }
        if (val>worst){
            worst = val;
        }
    }
    return worst;
}

int Design::getCurrentLambda(){
    int worst = 0;
    for (int i=0; i < v; i++){
        int tmp = dotCost(i);

        if (tmp>worst){
            worst=tmp;
        }
    }
    // this->bestLambda = worst;
    return worst;
}

/**
 * Create a random initial assignment, setup incremental data structures for detminening which row
 * changes given a move, and setup the dotProduct object.
 */
void Design::init() {
    /* ... */
    selections={};
    blank={};
    portfolio={};

    for (int i=0; i<v;i++){
        vector<int> row(b,0);

        for (int j=0; j<r; j++){
            row[j]=1;
        }

        auto rd = std::random_device {}; 
        auto rng = std::default_random_engine { rd() };
        std::shuffle(std::begin(row), std::end(row), rng);

        // Remember indexes for easy reference
        vector<int> tsIdx;//(r,0);     //tmp selected indexes
        vector<int> teIdx;//(b-r,0);   //tmp empty indexes
        vector<int> originSIdx;//(r,0);     //tmp selected indexes
        vector<int> originEIdx;//(b-r,0);   //tmp empty indexes
        for (int j=0; j<b;j++){
            if (row[j]==1){
                tsIdx.push_back(j);
                originSIdx.push_back(j);
            }
            else {
                teIdx.push_back(j);
                originEIdx.push_back(j);
            }
        }

        selections.push_back(tsIdx);
        blank.push_back(teIdx);
        portfolio.push_back(row);
    }
}

/**
 * get the Cost of the board
 * 
 * @param row: Ignores this row for dot calculations
 * @param temp: Modified Uncommited Move
 */
int Design::moveCost(vector<int> temp, int row){
    int worst=0;
    for (int j =0; j<v;j++){
        int val=0;
        if (j!=row){
            matrix.dot_prod(temp, portfolio[j],val);
        }
        if (val>worst){
            worst = val;
        }
    }
    return worst;
}

/**
 * Create all possible Moves and place them in a list. 
 * i row, j index in selected baskets list, k index in empty baskets list
*/
vector<Move> Design::makeMoves(){
    vector<Move> possibleMoves;
    for (int i=0; i<v; i++){
        for (int j=0; j<r; j++) {
            for (int k=0; k<(b-r); k++){
                //PERMUTE ALL Moves
                possibleMoves.push_back(Move(i,j,k));
            }
        }
    }
    // std::cout<<int(possibleMoves.size()) << " POSSIBLE MOVES CREATED\n" ;
    return possibleMoves;
}

/**
 * Probe a move. This does not update change any internal data structures (or: any changes are
 * undone before returning the cost)
 *
 * @param m
 */
Cost Design::probeMove(Move m) {
    /* ... */
    int row = m.row;
    int oldIdx = selections[row][m.oldIdx];
    int newIdx = blank[row][m.newIdx];
    
    vector<int> tmp = portfolio[row];

    // Allocating an new object each probe is unnecessarily expensive.
    // This can be worked around by instead updating some static object.
    // However, for this assignment allocating here should be fine...
    int before = moveCost(tmp,row);
    Cost cost = m.getCost();
    if (cost.value <= before){
        int before = moveCost(tmp,row);
        std::swap(tmp[oldIdx],tmp[newIdx]);
        int after=moveCost(tmp,row);
        cost.value = after;
        cost.improvement = before-after;
        m.setCost(cost);
    }

    return cost;
}

/**
 * Probe a move. This does not update change any internal data structures (or: any changes are
 * undone before returning the cost)
 *
 * @param m
 */
vector<int> Design::getExpensiveRows() {
    vector<int> expensive;

    for (int i = 0; i<v;i++){
        int cost = dotCost(i);
        if (cost == this->bestLambda){
            expensive.push_back(i);
        }
    }
    return expensive;
}

/**
 * Commits a move. This updates internal data structures and performs any necessary computations
 * that may speed up future probes.
 *
 * @param m
 */
void Design::commitMove(Move m) {
    /* ... */
    int row = m.row;
    int oldIdx = selections[row][m.oldIdx];
    int newIdx = blank[row][m.newIdx];

    Cost cost = m.getCost();
    // int costV = cost.value;

    std::swap(portfolio[row][oldIdx],portfolio[row][newIdx]);
    std::swap(selections[row][m.oldIdx],blank[row][m.newIdx]);

    getCurrentLambda();

    cost.value = -1;
}

/**
 * Helper method.
 * 
 * Given a move, make the necessary calls to dotProduct.increment() and dotProduct.decrement()
 * such that dotProduct is up to date.
 *
 * @param m
 */
void Design::updateDotProductFromMove(Move m) {
/* ... */
    m.getCost();
}

/**
 * Saves the current assignment such that it can be restored later. Call this when finding a new
 * overall best assignment.
 */
void Design::saveDesign() {
/* ... */
    int currLb = getCurrentLambda();
    if (currLb < getBestLb()){
        for (int i=0; i<int(portfolio.size()); i++){
            for (int j=0; j<b;j++){
                // std::cout<<"YES";
                chkpt[i][j]=portfolio[i][j];
            }
        }
        // this->chkpt = portfolio;
        this->bestLambda=currLb;
    }
    // chkpt = portfolio;
}

/**
 * Restores the saved assignment such that search can continue from it. Call this when doing an
 * intensification step or for printing the best found solution at the end of the search.
 */
void Design::restoreSavedDesign() {
/* ... */
    int currLb = getCurrentLambda();
    if (!(currLb <= getBestLb())){
        for (int i=0; i<int(chkpt.size()); i++){
            for (int j=0; j<b;j++){
                portfolio[i][j]=chkpt[i][j];
            }
        }
    }
}

/**
 *
 * @return the current design in the format required by the assignment.
 */
string Design::toString(bool printMode) {
    int worst = 0;
    
    for (int i=0; i < v; i++){
        int tmp = dotCost(i);

        if (tmp>worst){
            worst=tmp;
        }
    }
    stringstream output;
    output << "\nCost of Portfolio: " << worst << "";
        
    if (printMode){
        for (int i=0;i<v;i++){
            vector<int> vec = portfolio[i];
            for(auto it =vec.begin();it!=vec.end();it++){ 
                if(it != vec.begin()){
                    output <<" ";
                }
                output << *it;
            }
            output << "";
        }
    }
    
    string out = output.str();
    return out;
}
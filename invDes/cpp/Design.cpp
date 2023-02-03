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

/**
 * Create a random initial assignment, setup incremental data structures for detminening which row
 * changes given a move, and setup the dotProduct object.
 */
void Design::init() {
    /* ... */
    for (int i=0; i<v;i++){
        vector<int> row(b,0);

        for (int j=0; j<r; j++){
            row[j]=1;
        }

        auto rd = std::random_device {}; 
        auto rng = std::default_random_engine { rd() };
        std::shuffle(std::begin(row), std::end(row), rng);

        // Remember indexes for easy reference
        vector<int> tsIdx(r,0);     //tmp selected indexes
        vector<int> teIdx(b-r,0);   //tmp empty indexes
        for (int j=0; j<b;j++){
            if (row[j]==1){
                tsIdx.push_back(j);
            }
            else {
                teIdx.push_back(j);
            }
        }

        selections.push_back(tsIdx);
        blank.push_back(teIdx);
        portfolio.push_back(row);
    }
}

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

// vector<Move> Design::getNeighbours(){
//     for (int i=0; i<v; i++){
//         for (int j=0; j<r; j++) {
//             for (int k=0; k<(b-r); k++){
//                 //PERMUTE ALL NEIGHBOURS

//             }
//         }
//     }
// }

/**
 * Probe a move. This does not update change any internal data structures (or: any changes are
 * undone before returning the cost)
 *
 * @param m
 */
Cost Design::probeMove(Move m) {
    /* ... */
    int row = m.row;
    int old = m.oldIdx;
    int newI = m.newIdx;
    

    // Allocating an new object each probe is unnecessarily expensive.
    // This can be worked around by instead updating some static object.
    // However, for this assignment allocating here should be fine...
    Cost cost = m.getCost();
    if (cost.value < 0){
        std::swap(portfolio[row][old],portfolio[row][newI]);
        int worst=dotCost(row);

        cost.value = worst;
        m.setCost(cost);
    }

    return cost;
}

/**
 * Commits a move. This updates internal data structures and performs any necessary computations
 * that may speed up future probes.
 *
 * @param m
 */
void Design::commitMove(Move m) {
    /* ... */
    m.getCost();
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
    chkpt = portfolio;
}

/**
 * Restores the saved assignment such that search can continue from it. Call this when doing an
 * intensification step or for printing the best found solution at the end of the search.
 */
void Design::restoreSavedDesign() {
/* ... */
}

/**
 *
 * @return the current design in the format required by the assignment.
 */
string Design::toString() {
    int worst = 0;
    for (int i=0; i < v; i++){
        int tmp = dotCost(i);

        if (tmp>worst){
            worst=tmp;
        }
    }
    stringstream output;
    output << "\nCost of Portfolio: " << worst << "\n";
    
    for (int i=0;i<v;i++){
        vector<int> vec = portfolio[i];
        for(auto it =vec.begin();it!=vec.end();it++){ 
            if(it != vec.begin()){
                output <<" ";
            }
            output << *it;
        }
        output << "\n";
    }
    
    string out = output.str();
    return out;
}
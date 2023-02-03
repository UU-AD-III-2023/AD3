#include "Design.h"
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
        vector<int> tmpIdxs{};
        while (tmpIdxs.size()<b) {
            int idx = rand()%b;
            if (count(tmpIdxs.begin(), tmpIdxs.end(),idx)) {
                tmpIdxs.push_back(idx);
            }
        }
        for (int it=0; it < tmpIdxs.size(); it++){
            row[tmpIdxs[it]] = 1;
        }
        selections.push_back(tmpIdxs);
        portfolio.push_back(row);
    }
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
    int old = m.oldIdx;
    int newI = m.newIdx;

    // Allocating an new object each probe is unnecessarily expensive.
    // This can be worked around by instead updating some static object.
    // However, for this assignment allocating here should be fine...
    Cost cost = m.getCost();
    if (cost.value < 0){
        std::swap(portfolio[row][old],portfolio[row][newI]);
        int worst=0;

        //(vector<T> a, vector<vector<T>> b, int j, T &out)
        for (int j = 0; j<v; j++) {
            int val;
            if (j!=row){
                matrix.dot_prod(portfolio[row], portfolio[j], val);
            }
            if (val > worst){
                worst=val;
            }
        }
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
    return "/*...*/";
}
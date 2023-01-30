#include "Design.h"

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
}

/**
 * Probe a move. This does not update change any internal data structures (or: any changes are
 * undone before returning the cost)
 *
 * @param m
 */
Cost Design::probeMove(Move m) {
    /* ... */

    // Allocating an new object each probe is unnecessarily expensive.
    // This can be worked around by instead updating some static object.
    // However, for this assignment allocating here should be fine...
    return Cost(/* ... */);
}

/**
 * Commits a move. This updates internal data structures and performs any necessary computations
 * that may speed up future probes.
 *
 * @param m
 */
void Design::commitMove(Move m) {
    /* ... */
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
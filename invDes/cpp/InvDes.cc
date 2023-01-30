#include <iostream>
#include <vector>

#include "LocalSearch.h"

using std::vector;

class InvDes {

    private: 
        vector<vector<int>> instances = {{10, 30, 9}, {12, 44, 11}, {15, 21, 7},
            {16, 16, 6}, {9, 36, 12}, {11, 22, 10}, {19, 19, 9}, {10, 37, 14}, {8, 28, 14}, {10, 100, 30},
            {6, 50, 25}, {6, 60, 30}, {11, 150, 50}, {9, 70, 35}, {10, 350, 100}, {13, 250, 80},
            {10, 325, 100}, {15, 350, 100}, {9, 300, 100}, {12, 200, 75}, {10, 360, 120}};

    public:
        void main(int argc, char * argv[]) {
            // Paramters for tuning local search algorithm, does not have to be int.
            int alpha = 0;
            int beta = 0;

            if (argc == 4) {
                int v = atoi(argv[1]);
                int b = atoi(argv[2]);
                int r = atoi(argv[3]);
                runSolver(v, b, r, alpha, beta);
            } else {
                // This is just an example of how to run all instances, you probably want to do
                // something more interesting in order to gather the required statistics.
                /* ... */
                for (auto & instance : instances) {
                    runSolver(instance[0], instance[1], instance[2], alpha, beta);
                }
            }
        }

        void runSolver(int v, int b, int r, int alpha, int beta) {
            // Todo: Add asserts
            printf("Solving instance v: ", v, " b: ", b,  " r: ", r, 
            ". With parameters alpha: ", alpha, " beta: ", beta);
            LocalSearch s = LocalSearch(v, b, r, alpha, beta);
            s.run();
        }
};


int main (int argc, char * argv[]) {
    // Initialise v,b,r (argv)
    
    return 0;
};

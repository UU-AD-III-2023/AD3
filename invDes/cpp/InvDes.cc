#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>

#include "LocalSearch.h"

using std::vector;
using std::string;
using std::stringstream;
using std::clock_t;

class InvDes {

    private: 
        vector<vector<int>> instances = {{10, 30, 9}, {12, 44, 11}, {15, 21, 7},
            {16, 16, 6}, {9, 36, 12}, {11, 22, 10}, {19, 19, 9}, {10, 37, 14}, {8, 28, 14}, {10, 100, 30},
            {6, 50, 25}, {6, 60, 30}, {11, 150, 50}, {9, 70, 35}, {10, 350, 100}, {13, 250, 80},
            {10, 325, 100}, {15, 350, 100}, {9, 300, 100}, {12, 200, 75}, {10, 360, 120}};

    public:
        InvDes(){};
        void main(int argc, char * argv[]) {
            // Paramters for tuning local search algorithm, does not have to be int.
            int alpha = 600;
            int beta = 20;
            bool printMode = false;

            int v=0;
            int b=0;
            int r=0;

            if (argc >= 4) {
                if (argc == 5 && *argv[1]=='p') {
                    v = atoi(argv[2]);
                    b = atoi(argv[3]);
                    r = atoi(argv[4]);
                    printMode = true;
                }
                else if (argc == 5) {
                    alpha = atoi(argv[1]);
                    v = atoi(argv[2]);
                    b = atoi(argv[3]);
                    r = atoi(argv[4]);
                    printMode = true;
                }
                else if (argc == 4){
                    v = atoi(argv[1]);
                    b = atoi(argv[2]);
                    r = atoi(argv[3]);
                    printMode = false;
                }
                clock_t start = clock();
                runSolver(v, b, r, alpha, beta, printMode);
                std::cout << "\x1b[33m" << "TOTAL TIME TAKEN: " << ((clock() - start)*1.0/CLOCKS_PER_SEC) << "seconds\n\x1b[0m";

            } else {
                // This is just an example of how to run all instances, you probably want to do
                // something more interesting in order to gather the required statistics.
                /* ... */
                if (argc == 2){
                    printMode = ((*argv[1]=='p') || (*argv[1]=='P'));
                }
                for (auto & instance : instances) {
                    clock_t start = clock();
                    runSolver(instance[0], instance[1], instance[2], alpha, beta, printMode);
                    std::cout << "\x1b[33m" << "TOTAL TIME TAKEN: " << ((clock() - start)*1.0/CLOCKS_PER_SEC) << "seconds\x1b[0m";
                }
            }
        }

        void runSolver(int v, int b, int r, int alpha, int beta, bool printMode) {
            // Todo: Add asserts
            stringstream output;
            output << "\nSolving instance v: " << v << " b: " << b <<  " r: " << r << 
            ". With parameters alpha: " << alpha << " beta: " << beta << "";
            string out = output.str();
            std::cout << out;
            LocalSearch s = LocalSearch(v, b, r, alpha, beta, printMode);
            vector<int> storage = {};

            for (int i=0; i<5; i++){
                int store = s.run();
                storage.push_back(store);
            }

            stringstream medianss;
            medianss << "Median Result: " << findMedian(storage, 5);
            std::cout << "\n\x1b[33m" << medianss.str() <<"\x1b[0m\n\nNEXT!\n";
        }

        // Function for calculating
        // the median from geeks for geeks
        double findMedian(vector<int> a, int n){
            // If size of the arr[] is even
            if (n % 2 == 0) {
                // Applying nth_element
                // on n/2th index
                nth_element(a.begin(), a.begin() + n / 2, a.end());
        
                // Applying nth_element
                // on (n-1)/2 th index
                nth_element(a.begin(), a.begin() + (n - 1) / 2, a.end());
        
                // Find the average of value at
                // index N/2 and (N-1)/2
                return (double)(a[(n - 1) / 2] + a[n / 2]) / 2.0;
            }
        
            // If size of the arr[] is odd
            else {
        
                // Applying nth_element
                // on n/2
                nth_element(a.begin(), a.begin() + n / 2, a.end());
        
                // Value at index (N/2)th
                // is the median
                return (double)a[n / 2];
            }
        }
        
};


int main (int argc, char * argv[]) {
    // Initialise v,b,r (argv)
    InvDes solver = InvDes();
    solver.main(argc, argv);
    return 0;
};

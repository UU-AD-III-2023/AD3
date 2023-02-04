#pragma once

#include <iostream>
#include <string>

using std::string;

class Cost {
// *...*/

public:
    // int it; // Which iteration, if different, ignore cost
    int value;
    int improvement;
    Cost();
    // Cost(int it, int value);
    string toString();
    bool isEqualTo(Cost c);
    bool isBetterThan(Cost c);
};

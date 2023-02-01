#pragma once

#include <iostream>
#include <string>

using std::string;

class Cost {
// *...*/

public:
    int value;
    Cost();
    string toString();
    bool isEqualTo(Cost c);
    bool isBetterThan(Cost c);
};

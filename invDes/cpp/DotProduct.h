#pragma once

#include <iostream>

// #ifndef _FUNCTS_
// #define _FUNCTS_

#include <vector>
using std::vector;

// b[n][size]
class Matrix {
public:
	vector<int> a_int; 
	vector<int> b_int;
    // void initialise() {}
	Matrix();
	void dot_prod(vector<int> a, vector<int> b, int &out);
};

// #endif

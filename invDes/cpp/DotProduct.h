#pragma once

#include <iostream>

// #ifndef _FUNCTS_
// #define _FUNCTS_

#include <vector>
using std::vector;

// b[n][size]
template<class T> class Matrix {
public:
	vector<T> a_int; 
	vector<T> b_int;
    // void initialise() {}
	Matrix();
	void dot_prod(vector<T> a, vector<T> b, T &out);
};

// #endif

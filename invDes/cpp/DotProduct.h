#pragma once

#include <iostream>

// #ifndef _FUNCTS_
// #define _FUNCTS_

#include <vector>
using std::vector;

// b[n][size]
template<class T> class Matrix {
public:
	T a_int, b_int;
    // void initialise() {}
	Matrix();
	void dot_prod(T a, T b, int j, int n, T &out);
};

// #endif

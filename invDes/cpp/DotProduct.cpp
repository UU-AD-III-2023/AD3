# include "DotProduct.h"
#include <vector>

using std::vector;

template<class T> Matrix<T>::Matrix(){};

// j Column, on vector on nth Row
template<class T> void Matrix<T>::dot_prod(vector<T> a, vector<T> b, T &out) {
	T dotp = 0;
	int n = a.size();

	this->a_int=a;
	// ATTENTION!
	// Vector<int> bint push element i,j
	this->b_int=b;

	for(int i=0; i<n; i++) {
		dotp += a_int[i] * b_int[i];
	}
	out = dotp;
};
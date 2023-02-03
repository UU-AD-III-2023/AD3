# include "DotProduct.h"

Matrix::Matrix(){};

// j Column, on vector on nth Row
void Matrix::dot_prod(vector<int> a, vector<int> b, int &out) {
	int dotp = 0;
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
# include "DotProduct.h"
#include <vector>

using std::vector;

template<class T> Matrix<T>::Matrix(){};

template<class T> void Matrix<T>::dot_prod(T a, T b, int j, int n, T &out) {
	T dotp = 0;

	for(int i=0; i<n;i++){
		this->a_int[i]=a[i];
	}
	// ATTENTION!
	for(int i=0; i<n;i++){
		this->b_int[i][j]=b[i][j];
	}

	for(int i=0; i<n; i++) {
		dotp += a_int[i] * b_int[i][j];
	}
	out = dotp;
}
#ifndef _FUNCTS_
#define _FUNCTS_

template<class T, int size, int n> class Matrix {
public:
	T a_int[n], b_int[n][size];
    // void initialise() {}
	Matrix() {}
	void dot_prod(T a[n], T b[n][size], int j, T &out) {
		T dotp = 0;

		for(int i=0; i<n;i++){
			a_int[i]=a[i];
		}
		for(int i=0; i<n;i++){
			b_int[i][j]=b[i][j];
		}

		for(int i=0; i<n; i++) {
			dotp += a_int[i] * b_int[i][j];
		}
		out = dotp;
	}
};

#endif
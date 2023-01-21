#include <iostream>
using namespace std;

class Row {
protected:
  int length;
  int row[]; // Array sawing which numbers in a row are colored.

public:
  Row(int length, int coloured_fields) {
    row = int[length];
    for (int i = 0; i < coloured_fields;) {
      int x = rand();
      x = x % length;
      if (!(x in row)) {
        row[i] = x;
        i++;
      }
    }
  }
  int DotProduct(Row row) {
    int count = 0;
    for (int i = 0; i < length; i++) {
      if ((row.row[i]) && (row[i])) {
        count++
      }
    }
    return count;
  }
};

class Matrix {
protected:
  int row;
  int columns;

public:
  Matrix(int aRow, int aColumn) {
    row = aRow;
    columns = aColumn;
    int matrix[row][columns];
  }
  int getLargestDotProduct() {
    int val = INT_MIN;
    for (int i = 0; i < row; i++) {
      for (int j = i + 1; i < row; j++) {
        if (row[i].Dotproduct(row[j]) > val) {
          val = row[i].Dotproduct(row[j]);
        }
      }
    }
    return val;
  }
};

int main() { return 0; }

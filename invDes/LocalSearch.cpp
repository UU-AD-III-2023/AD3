#include <iostream>
#include <set>
using namespace std;

class Row {
protected:
  int length;
  set<int> row; // soled using sets

public:
  Row(int length, int coloured_fields) {
    while (row.size() > coloured_fields) {
      int x = rand();
      row.insert(x);
    }
  }
  // Calculating the dot product between 2 rows.
  int DotProduct(Row row) {
    set<int> commun;
    set_intersection(row.begin(), row.end(), row.row.begin(), row.row.end(),
                     inserter(commun, commun.begin()));
    return commun.size();
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
    Row[columns];
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

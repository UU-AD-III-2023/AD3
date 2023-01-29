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
  set<Row> rows;
  int max_dotprod;

public:
  Matrix(int aRow, int aColumn, int aColoured) {
    row = aRow;
    columns = aColumn;
    for (int i = 0; i < columns; i++) {
      rows.add(Row(row, aColoured));
    }
  }
  int getLargestDotProduct() {

    int val = 0;
    for () {
    }
  }
} return val;
}
}
;

int main() { return 0; }

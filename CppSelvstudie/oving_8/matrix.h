#include <cassert>
#include <iostream>
#include <fstream>

class Matrix{
    private:
    int mRows;
    int mColumns;

    double **matrix;

    public:
    Matrix(int rows, int columns);

    explicit Matrix(int nRows);

    double get(int row, int column) const;

    void set(int row, int column, double val);

    int getRows() const;

    int getColumns() const;

    friend std::ostream& operator<<(std::ostream &stream, Matrix &matrix);

    double *operator[](int i);

    Matrix(const Matrix &rhs);

    Matrix operator=(Matrix rhs);

    ~Matrix();
};
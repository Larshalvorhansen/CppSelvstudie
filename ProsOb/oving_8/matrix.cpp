#include "matrix.h"
#include <iostream>
#include <fstream>
#include <iomanip>

Matrix::Matrix(int rows, int columns) : mRows{rows}, mColumns{columns}{
    assert(rows > 0 && columns > 0);
    matrix = new double* [columns];
    for (int row = 0; row < columns; row++){
        matrix[row] = new double[rows];
        for (int column = 0; column < rows; column++){
            matrix[row][column] = 0;
        }
    }
}

Matrix::Matrix(int rows) : Matrix(rows, rows){
    for (int i = 0; i < rows; i++){
        matrix[i][i] = 1;
    }
}

double Matrix::get(int row, int column) const{
    assert(row > 0 && row < mRows && column > 0 && column < mColumns);
    return matrix[row][column];
}

void Matrix::set(int row, int column, double val){
    assert(row >= 0 && row < mRows && column >= 0 && column < mColumns);
    matrix[row][column] = val;
}

int Matrix::getRows()const{
    return mRows;
}

int Matrix::getColumns() const{
    return mColumns;
}
double *Matrix::operator[](int i){
    return matrix[i];
}

std::ostream& operator<<(std::ostream& stream, Matrix &matrix){
    for (int row = 0; row < matrix.mRows; row++){
        for (int col = 0; col < matrix.mColumns; col++){
            stream << std::setw(4) << matrix[row][col] << " ";
        } 
        stream << "\n";
    }
    return stream;
}

Matrix::Matrix(const Matrix &rhs){
    this->mRows = rhs.getRows();
    this->mColumns = rhs.getColumns();
    this->matrix = new double *[this->mRows];

    for (int rows = 0; rows < this->mRows; rows++){
        matrix[rows] = new double[this->mColumns];
        for (int columns = 0; columns < this->mColumns; columns++){
            this->matrix[mRows][mColumns] = rhs.matrix[mRows][mColumns];
        }
    }
}

Matrix Matrix::operator=(Matrix rhs) {
    std::swap(mRows, rhs.mRows);
    std::swap(mColumns, rhs.mColumns);
    std::swap(matrix, rhs.matrix);

    return *this;
}

Matrix::~Matrix(){
    delete[] matrix[mRows];
    matrix = nullptr;
}


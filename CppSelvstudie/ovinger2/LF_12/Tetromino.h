#pragma once
#include "Graph.h"

enum class TetrominoType{J, L, T, S, Z, O, I, NONE}; 

class Tetromino {
public:
    static constexpr int blockSize {30};

    Tetromino(Point startingPoint, TetrominoType tetType);
    Tetromino() : matrixSize{0}, topLeftCorner{0,0} {} 
    
    void rotateClockwise();
    void rotateCounterClockwise();
    void moveDown();
    void moveLeft();
    void moveRight();

    bool blockExist(int row, int column) const {
        return blockMatrix[row][column] != TetrominoType::NONE;
    }

    TetrominoType getBlock(int row, int column) const {
        return blockMatrix[row][column];
    }

    int getMatrixSize() const {
        return matrixSize;
    }

    Point getPosition() const {
        return topLeftCorner;
    }
    
    ~Tetromino() {}

private: 

    int matrixSize;
    Point topLeftCorner;
    vector<vector<TetrominoType>> blockMatrix;
};


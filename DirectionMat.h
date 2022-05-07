#ifndef CELL_H
#define CELL_H

#include <iostream> // size_t
#include <stdint.h>

typedef struct {
    uint8_t c0 : 2;
    uint8_t c1 : 2;
    uint8_t c2 : 2;
    uint8_t c3 : 2;
}Cell;

class DirectionMat
{
private:
    Cell* data;
    size_t compactCols;

public:
    DirectionMat(size_t rows, size_t cols);
    ~DirectionMat();

    uint8_t at(size_t row, size_t col);
    void set(uint8_t val, size_t row, size_t col);
};

#endif
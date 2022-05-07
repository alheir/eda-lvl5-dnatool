#include "DirectionMat.h"

DirectionMat::DirectionMat(size_t rows, size_t cols)
{
    compactCols = (cols / 4) + (cols % 4 != 0);
    data = new Cell[compactCols * rows];
}

DirectionMat::~DirectionMat()
{
    delete[] data;
}

uint8_t DirectionMat::at(size_t row, size_t col)
{
    Cell cell = data[(compactCols * row) + (col / 4)];

    switch (col % 4)
    {
    case 0:
        return cell.c0;
        break;
    case 1:
        return cell.c1;
        break;
    case 2:
        return cell.c2;
        break;
    case 3:
        return cell.c3;
        break;
    }
    return 0;
}

void DirectionMat::set(uint8_t val, size_t row, size_t col)
{
    size_t index = (compactCols * row) + (col / 4);

    switch (col % 4)
    {
    case 0:
        data[index].c0 = val;
        break;
    case 1:
        data[index].c1 = val;
        break;
    case 2:
        data[index].c2 = val;
        break;
    case 3:
        data[index].c3 = val;
        break;
    }
}
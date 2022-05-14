/**
 * @file DirectionMat.cpp
 * @authors DALZOTTO, Rafael; HEIR, Alejandro - Grupo 7
 * @brief Implements 2 bit-size matrix cells.
 * @version 0.1
 * @date 2022-05-08
 *
 * @copyright Copyright (c) 2022 - 22.08 EDA - ITBA
 *
 */

#include "DirectionMat.h"

/**
 * @brief Constructs a new Direction Mat object
 *
 * @param rows Total rows
 * @param cols Total cols
 */
DirectionMat::DirectionMat(const size_t rows, const size_t cols) : rows(rows), cols(cols)
{
    compactCols = (cols / 4) + (cols % 4 != 0);
    data = new DirCell[compactCols * rows];
}

/**
 * @brief Destroys the Direction Mat object
 *
 */
DirectionMat::~DirectionMat()
{
    delete[] data;
}

/**
 * @brief Prints the given DirectionMat, used for debugging
 *
 * @param mat initialized DirectionMat
 */
void DirectionMat::print()
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            std::cout << this->at(i, j) << '\t';
        }
        std::cout << std::endl;
    }
}

/**
 * @brief Reads a given DirectionMap cell.
 *
 * @param row
 * @param col
 * @return uint8_t
 */
uint8_t DirectionMat::at(size_t row, size_t col)
{
    switch (col % 4)
    {
    case 0:
        return data[(compactCols * row) + (col / 4)].d0;
        break;
    case 1:
        return data[(compactCols * row) + (col / 4)].d1;
        break;
    case 2:
        return data[(compactCols * row) + (col / 4)].d2;
        break;
    case 3:
        return data[(compactCols * row) + (col / 4)].d3;
        break;
    }
    return 0;
}

/**
 * @brief Writes a given DirecitonMat cell.
 *
 * @param val Data to store
 * @param row
 * @param col
 */
void DirectionMat::set(uint8_t val, size_t row, size_t col)
{
    switch (col % 4)
    {
    case 0:
        data[(compactCols * row) + (col / 4)].d0 = val;
        break;
    case 1:
        data[(compactCols * row) + (col / 4)].d1 = val;
        break;
    case 2:
        data[(compactCols * row) + (col / 4)].d2 = val;
        break;
    case 3:
        data[(compactCols * row) + (col / 4)].d3 = val;
        break;
    }
}

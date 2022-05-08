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

DirectionMat::DirectionMat(size_t rows, size_t cols)
{
    this->rows = rows;
    this->cols = cols;

    compactCols = (cols / 4) + (cols % 4 != 0);

    data = new Cell[compactCols * rows];
}

DirectionMat::~DirectionMat()
{
    delete[] data;
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

/**
 * @brief Writes a given DirecitonMat cell.
 *
 * @param val Data to store
 * @param row
 * @param col
 */
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

/**
 * @brief Returns the DirectionMat row size
 *
 * @return size_t
 */
size_t DirectionMat::getRows()
{
    return rows;
}

/**
 * @brief Returns the DirectionMat column size
 *
 * @return size_t
 */
size_t DirectionMat::getCols()
{
    return cols;
}
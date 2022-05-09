/**
 * @file DirectionMat.h
 * @authors DALZOTTO, Rafael; HEIR, Alejandro - Grupo 7
 * @brief Implements 2 bit-size matrix cells.
 * @version 0.1
 * @date 2022-05-08
 *
 * @copyright Copyright (c) 2022 - 22.08 EDA - ITBA
 *
 */
#ifndef DIRECTIONMAT_H
#define DIRECTIONMAT_H

#include <iostream> // size_t
#include <stdint.h>

#include <vector>
#include <chrono>
#include <iostream>
#include <random>
#include <algorithm>

/**
 * @brief DirCell contains 4 directions in a single byte
 */
typedef struct
{
    uint8_t d0 : 2;
    uint8_t d1 : 2;
    uint8_t d2 : 2;
    uint8_t d3 : 2;
} DirCell;

class DirectionMat
{
public:
    DirectionMat(size_t rows, size_t cols);
    ~DirectionMat();

    uint8_t at(size_t row, size_t col);
    void set(uint8_t val, size_t row, size_t col);

    size_t getRows();
    size_t getCols();

private:
    DirCell *data;

    size_t compactCols;
    size_t rows;
    size_t cols;
};

#endif
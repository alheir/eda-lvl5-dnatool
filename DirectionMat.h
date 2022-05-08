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

#ifndef CELL_H
#define CELL_H

#include <iostream> // size_t
#include <stdint.h>

#include <vector>
#include <chrono>
#include <iostream>
#include <random>
#include <algorithm>

typedef struct
{
    uint8_t c0 : 2;
    uint8_t c1 : 2;
    uint8_t c2 : 2;
    uint8_t c3 : 2;
} Cell;

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
    Cell *data;

    size_t compactCols;
    size_t rows;
    size_t cols;
};

#endif
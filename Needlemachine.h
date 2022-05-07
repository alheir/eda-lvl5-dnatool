#ifndef NEEDLEMACHINE_H
#define NEEDLEMACHINE_H

#include <string>
#include <vector>
#include <array>

#include "DirectionMat.h"

DirectionMat* initMat(size_t &rows, size_t &cols, const std::string &seq1,
             const std::string &seq2);
int32_t fillMat(DirectionMat &mat, size_t rows, size_t cols, const std::string &seq1,
                const std::string &seq2);
void alignMat(DirectionMat &mat, size_t rows, size_t cols, const std::string &seq1,
              const std::string &seq2, std::array<std::string, 3> &output);

int32_t getGlobalAlignment(const std::string &seq1, const std::string &seq2,
                           std::array<std::string, 3> &alignment);

#endif
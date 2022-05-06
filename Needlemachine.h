#ifndef NEEDLEMACHINE_H
#define NEEDLEMACHINE_H

#include <string>
#include <vector>
#include <array>

typedef uint8_t Cell;

void initMat(Cell **&mat, size_t &rows, size_t &cols, const std::string &seq1,
             const std::string &seq2);
long fillMat(Cell **mat, size_t rows, size_t cols, const std::string &seq1,
             const std::string &seq2);
void alignMat(Cell **mat, size_t rows, size_t cols, const std::string &seq1,
              const std::string &seq2, std::array<std::string, 3> &output);

long getGlobalAlignment(const std::string &seq1, const std::string &seq2,
                        std::array<std::string, 3> &alignment);

#endif
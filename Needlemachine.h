#ifndef NEEDLEMACHINE_H
#define NEEDLEMACHINE_H

#include <string>
#include <vector>
#include <array>

typedef union
{
    int32_t word;
    struct
    {
        int32_t score : 29;
        int32_t bestDir : 3;
    };
} Cell;

void initMat(Cell**& mat, size_t &rows, size_t &cols, const std::string &seq1,
             const std::string &seq2);
void fillMat(Cell **mat, size_t rows, size_t cols, const std::string &seq1,
             const std::string &seq2);
int32_t alignMat(Cell **mat, size_t rows, size_t cols, const std::string &seq1,
              const std::string &seq2, std::array<std::string, 3> &output);

int32_t getGlobalAlignment(const std::string &seq1, const std::string &seq2,
                        std::array<std::string, 3> &alignment);

#endif
/**
 * @file Aligner.h
 * @authors DALZOTTO, Rafael; HEIR, Alejandro - Grupo 7
 * @brief Genetic sequence aligner, based on Needleman-Wunsch algorithm
 * @version 0.1
 * @date 2022-05-08
 *
 * @copyright Copyright (c) 2022 - 22.08 EDA - ITBA
 *
 */
#ifndef ALIGNER_H
#define ALIGNER_H

#include <string>
#include <array>

#include "DirectionMat.h"

void initMat(DirectionMat &mat);

int32_t fillMat(DirectionMat &mat, const std::string &seq1, const std::string &seq2);

void buildAligment(DirectionMat &mat, const std::string &seq1, const std::string &seq2,
              std::array<std::string, 3> &output);

int32_t getGlobalAlignment(const std::string &seq1, const std::string &seq2,
                           std::array<std::string, 3> &alignment);

#endif
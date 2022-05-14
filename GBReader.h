/**
 * @file GBReader.h
 * @authors DALZOTTO, Rafael; HEIR, Alejandro - Grupo 7
 * @brief Sequence extractor for GenBank-like files
 * @version 0.1
 * @date 2022-05-08
 *
 * @copyright Copyright (c) 2022 - 22.08 EDA - ITBA
 *
 */

#ifndef GBREADER_H
#define GBREADER_H

#include <iostream>

bool getSequence(std::string &output, std::istream &file);

#endif
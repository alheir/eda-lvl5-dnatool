/**
 * @file GBReader.cpp
 * @authors DALZOTTO, Rafael; HEIR, Alejandro - Grupo 7
 * @brief Sequence extractor for GenBank-like files
 * @version 0.1
 * @date 2022-05-08
 *
 * @copyright Copyright (c) 2022 - 22.08 EDA - ITBA
 *
 */

#include "GBReader.h"

#include <algorithm>

using namespace std;

/**
 * @brief Checks if a given character is not 'a', 'c', 'g' or 't'.
 *
 * @param c
 * @return true It's not
 * @return false It is
 */
bool isNotACGT(char c)
{
    return !(c == 'a' || c == 'c' || c == 'g' || c == 't');
}

/**
 * @brief Extracts an acgt-like string from a GenBank file
 *
 * @param output String to store the acgt sequence
 * @param file istream file handler.
 * @return true Success
 * @return false Failure
 */
bool getSequence(string &output, istream &file)
{
    output.clear();
    string tempStr;

    bool checker = false;

    while (getline(file, tempStr))
    {
        if (checker = (tempStr.substr(0, 6) == "ORIGIN"))
            break;
    }

    if (!checker)
        return false;

    while (getline(file, tempStr))
    {
        if (checker = (tempStr.substr(0, 2) == "//"))
            break;

        tempStr.erase(remove_if(tempStr.begin(), tempStr.end(), isNotACGT), tempStr.end());

        output.append(tempStr);
    }

    if (!checker)
        return false;

    for (auto &ch : output)
        ch = toupper(ch);

    return true;
}
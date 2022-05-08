/**
 * @file Aligner.cpp
 * @authors DALZOTTO, Rafael; HEIR, Alejandro - Grupo 7
 * @brief Genetic sequence aligner, based on Needleman-Wunsch algorithm.
 * @version 0.1
 * @date 2022-05-08
 *
 * @copyright Copyright (c) 2022 - 22.08 EDA - ITBA
 *
 */

#include "Aligner.h"

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

typedef enum
{
    VERTICAL,
    DIAGONAL,
    HORIZONTAL
} Direction;

static const char matchScore = 1;
static const char substScore = -1;
static const char indelScore = -1;

using namespace std;

/**
 * @brief Prints the given DirectionMat
 *
 * @param mat
 */
void printMat(DirectionMat *mat)
{
    for (size_t i = 0; i < mat->getRows(); i++)
    {
        for (size_t j = 0; j < mat->getCols(); j++)
        {
            printf("%d\t", mat->at(i, j));
        }
        cout << endl;
    }
}

/**
 * @brief Initializes a DirectionMat for storing Needleman-Wunsch directions.
 *
 * @param rows
 * @param cols
 * @return DirectionMat*
 */
DirectionMat *initMat(const size_t rows, const size_t cols)
{
    DirectionMat *mat = new DirectionMat(rows, cols);

    // Inicializar matriz
    for (int i = 0; i < cols; i++)
        mat->set(HORIZONTAL, 0, i);

    for (int i = 1; i < rows; i++)
        mat->set(VERTICAL, i, 0);

    return mat;
}

/**
 * @brief Completes a DirectionMat based on two given genetic sequences.
 *
 * @param mat
 * @param seq1 String with one acgt-like genetic sequence.
 * @param seq2 String with one acgt-like genetic sequence.
 * @return int32_t Optimal score
 */
int32_t fillMat(DirectionMat *mat, const string &seq1, const string &seq2)
{
    auto rows = mat->getRows();
    auto cols = mat->getCols();

    vector<int32_t> previousColumn(rows);
    vector<int32_t> currentColumn(rows);

    array<int32_t, 3> scores;

    // First column
    for (size_t u = 0; u < rows; u++)
        previousColumn[u] = -u;

    for (size_t i = 1; i < cols; i++)
    {
        currentColumn[0] = -i;

        for (size_t j = 1; j < rows; j++)
        {

            scores[VERTICAL] = currentColumn[j - 1] + indelScore;
            scores[HORIZONTAL] = previousColumn[j] + indelScore;

            if (seq1[j - 1] == seq2[i - 1])
                scores[DIAGONAL] = previousColumn[j - 1] + matchScore;
            else
                scores[DIAGONAL] = previousColumn[j - 1] + substScore;

            /*
            int32_t max = scores[0];
            mat->set(0, j, i);

            // Buscamos alguna direccion optima
            for (uint8_t u = 1; u < 3; u++)
            {
                if (scores[u] >= max)
                {
                    max = scores[u];
                    mat->set(u, j, i); // Guarda dirección optimizadora (solo una)
                }
            }
            currentColumn[j] = max; // Guarda puntaje de la celda
            */

            // Iterador al primer máximo
            auto maxIterator = max_element(scores.begin(), scores.end());

            currentColumn[j] = *maxIterator;              // Guarda el puntaje
            mat->set(maxIterator - scores.begin(), j, i); // Guarda la dirección
        }

        previousColumn = currentColumn;
    }

    return currentColumn.back();
}

/**
 * @brief Builds the optimal alignment for two genetic sequences
 * and an already filled DirectionMat.
 *
 * @param mat
 * @param seq1 String with one acgt-like genetic sequence.
 * @param seq2 String with one acgt-like genetic sequence.
 * @param output 3-string array to store the optimal alignment.
 */
void buildAligment(DirectionMat *mat, const string &seq1, const string &seq2, array<string, 3> &output)
{
    size_t i = mat->getRows() - 1;
    size_t j = mat->getCols() - 1;

    while (i >= 1 || j >= 1)
    {
        uint8_t val = mat->at(i, j);

        switch (val)
        {
        case VERTICAL:
            output[0].push_back(seq1.at(i - 1));
            output[1].push_back(' ');
            output[2].push_back('-');
            i--;
            break;

        case DIAGONAL:
            output[0].push_back(seq1.at(i - 1));
            output[1].push_back((seq1.at(i - 1) == seq2.at(j - 1)) ? '|' : '*');
            output[2].push_back(seq2.at(j - 1));
            i--;
            j--;
            break;

        case HORIZONTAL:
            output[0].push_back('-');
            output[1].push_back(' ');
            output[2].push_back(seq2.at(j - 1));
            j--;
            break;

        default:
            break;
        }
    }

    reverse(output[0].begin(), output[0].end());
    reverse(output[1].begin(), output[1].end());
    reverse(output[2].begin(), output[2].end());
}

/**
 * @brief Runs aligner for two acgt-like strings.
 *
 * @param seq1 String with one acgt-like genetic sequence.
 * @param seq2 String with one acgt-like genetic sequence.
 * @param alignment 3-string array to store the optimal alignment.
 * @return int32_t Optimal score
 */
int32_t getGlobalAlignment(const string &seq1, const string &seq2, array<string, 3> &alignment)
{
    // (1) Inicializar la Matriz
    DirectionMat *mat = initMat(seq1.length() + 1, seq2.length() + 1);

    // (2) Llenar la matriz
    int32_t bestScore = fillMat(mat, seq1, seq2);

    // (3) Alinear
    buildAligment(mat, seq1, seq2, alignment);

    // Liberar memoria
    delete mat;

    return bestScore;
}

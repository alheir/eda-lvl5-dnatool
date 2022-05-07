#include "Needlemachine.h"
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

void printMat(DirectionMat &mat, size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            printf("%d\t", mat.at(i, j));
        }
        cout << endl;
    }
}

DirectionMat* initMat(size_t &rows, size_t &cols, const string &seq1, const string &seq2)
{
    rows = seq1.length() + 1; // cant filas
    cols = seq2.length() + 1; // cant columnas

    DirectionMat* mat = new DirectionMat(rows, cols);

    // Inicializar matriz
    for (int i = 1; i < cols; i++)
        mat->set(HORIZONTAL, 0, i);

    for (int i = 1; i < rows; i++)
        mat->set(VERTICAL, i, 0);

    return mat;
}

int32_t fillMat(DirectionMat &mat, size_t rows, size_t cols, const string &seq1, const string &seq2)
{
    vector<int32_t> prevColumn(rows);
    vector<int32_t> currentColumn(rows);
    int32_t scores[3];

    // First column
    for (size_t u = 0; u < rows; u++)
        prevColumn[u] = -u;

    for (size_t i = 1; i < cols; i++)
    {
        currentColumn[0] = -i;

        for (size_t j = 1; j < rows; j++)
        {

            scores[VERTICAL] = currentColumn[j - 1] + indelScore;
            scores[HORIZONTAL] = prevColumn[j] + indelScore;

            if (seq1[j - 1] == seq2[i - 1])
                scores[DIAGONAL] = prevColumn[j - 1] + matchScore;
            else
                scores[DIAGONAL] = prevColumn[j - 1] + substScore;

            int32_t max = scores[0];
            mat.set(0, j, i);

            // Buscamos alguna direccion optima
            for (uint8_t u = 1; u < 3; u++)
            {
                if (scores[u] >= max)
                {
                    max = scores[u];
                    mat.set(u, j, i); // Guarda dirección optimizadora (solo una)
                }
            }
            currentColumn[j] = max; // Guarda puntaje de la celda
        }

        prevColumn = currentColumn;
    }

    return currentColumn.back();
}

void alignMat(DirectionMat &mat, size_t rows, size_t cols, const string &seq1,
              const string &seq2, array<string, 3> &output)
{
    array<char, 3> terna;

    size_t i = rows - 1;
    size_t j = cols - 1;
    while (i >= 1 || j >= 1)
    {
        uint8_t val = mat.at(i,j); 
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

int32_t getGlobalAlignment(const string &seq1, const string &seq2, array<string, 3> &alignment)
{
    // DirectionMat* mat = NULL;
    size_t rows = 0;
    size_t cols = 0;

    // (1) Inicializar la Matriz
    DirectionMat* mat = initMat(rows, cols, seq1, seq2);

    // (2) Llenar la matriz
    int32_t bestScore = fillMat(*mat, rows, cols, seq1, seq2);

    // printMat(*mat, rows, cols);

    // (3) Alinear
    alignMat(*mat, rows, cols, seq1, seq2, alignment);

    // Liberar memoria
    delete mat;

    return bestScore;
}

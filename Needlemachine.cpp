#include "Needlemachine.h"
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

typedef enum {VERTICAL, DIAGONAL, HORIZONTAL} Direction;

static const char matchScore = 1;
static const char substScore = -1;
static const char indelScore = -1;

using namespace std;

void printMat(Cell** mat, size_t rows, size_t cols)
{
    for(size_t i=0; i < rows; i++)
    {
        for(size_t j=0; j < cols; j++)
        {
            printf("% -d\t", mat[i][j].score);
        }
        cout << endl;
    }
}

void initMat(Cell**& mat, size_t& rows, size_t& cols, const string &seq1, const string &seq2)
{
    rows = seq1.length()+1; // cant filas
    cols = seq2.length()+1; // cant columnas

    mat = new Cell * [rows];
    
    for(size_t i=0; i < rows; i++)
        mat[i] = new Cell[cols];

    // Inicializar matriz
    mat[0][0].score = 0;

    for(int i = 1; i < cols; i++)
    {
        mat[0][i].score = mat[0][i-1].score + indelScore;
        mat[0][i].bestDir = HORIZONTAL;
    }

    for(int i = 1; i < rows; i++)
    {
        mat[i][0].score = mat[i-1][0].score + indelScore;
        mat[i][0].bestDir = VERTICAL;
    }
}

void fillMat(Cell** mat, size_t rows, size_t cols, const string &seq1, const string &seq2)
{
    for(size_t i = 1; i < rows; i++)
    {
        for(size_t j = 1; j < cols; j++)
        {
            int32_t scores[3];
            
            scores[VERTICAL] = mat[i-1][j].score + indelScore;
            scores[HORIZONTAL] = mat[i][j-1].score + indelScore;

            if(seq1.at(i-1) == seq2.at(j-1))
                scores[DIAGONAL] = mat[i-1][j-1].score + matchScore;
            else
                scores[DIAGONAL] = mat[i-1][j-1].score + substScore;

            int32_t max = INT32_MIN;
            mat[i][j].bestDir = -1;
            
            //TODO: se está guardando una sola dirección
            for (uint8_t u = 0; u < 3; u++)
            {
                if(scores[u] >= max)
                {
                    max = scores[u];
                    mat[i][j].bestDir = u;
                }
            }             
            mat[i][j].score = max;

        }
    }
}


//TODO poner este prototipo con menos de 100 caracteres
int32_t alignMat(Cell** mat, size_t rows, size_t cols, const string &seq1, const string &seq2, array<string,3>& output)
{
    long alignScore = 0;
    array<char,3> terna;

    size_t i = rows-1;
    size_t j = cols-1;
    while(i >= 1 || j >= 1)
    {
        int8_t dir = mat[i][j].bestDir;
        switch (dir)
        {
        case VERTICAL:
            output[0].push_back(seq1.at(i-1));
            output[1].push_back(' ');
            output[2].push_back('-');
            i--;
            break;
            
        case DIAGONAL:
            output[0].push_back(seq1.at(i-1));
            output[1].push_back((seq1.at(i-1) == seq2.at(j-1))? '|' : '*'); 
            output[2].push_back(seq2.at(j-1));
            i--;
            j--;
            break;

        case HORIZONTAL:
            output[0].push_back('-');
            output[1].push_back(' ');
            output[2].push_back(seq2.at(j-1));
            j--;
            break;        
        default:
            break;
        }
    }

    // Voltear las cadenas
    reverse(output[0].begin(), output[0].end());
    reverse(output[1].begin(), output[1].end());
    reverse(output[2].begin(), output[2].end());

    return alignScore;
}

int32_t getGlobalAlignment(const string &seq1, const string &seq2, array<string,3>  &alignment)
{
    Cell** mat = NULL;
    size_t rows = 0;
    size_t cols = 0;

    // (1) Inicializar la Matriz
    initMat(mat, rows, cols, seq1, seq2);

    // (2) Llenar la matriz
    fillMat(mat, rows, cols, seq1, seq2);

    // (3) Alinear
    alignMat(mat, rows, cols, seq1, seq2, alignment);

    // cout << "len: " << alignment.size() << endl;
    // cout << alignment[0].data() << endl;
    // cout << alignment[1].data() << endl;
    // cout << alignment[2].data() << endl;

    int32_t bestAlignment = mat[rows - 1][cols - 1].score;

    // Liberar memoria
    for(size_t i=0; i < rows; i++)
        delete[] mat[i];

    delete[] mat;

    return bestAlignment;
}

#include <iostream>

using namespace std;

#include "Needlemachine.h"
#include <string>
#include <array>

bool testMatInit(Cell **&mat, size_t &cols, size_t &rows, string &s1, string &s2,
                 size_t expectedCols, size_t expectedRows, int32_t (*expectedScoreMat)[8])
{
    bool output = true;

    initMat(mat, rows, cols, s1, s2);

    if (rows != expectedRows || cols != expectedCols)
    {
        cout << "Mat size init error!\n";
        output = false;
    }

    for (size_t i = 0; i < rows; i++)
    {
        if (mat[i][0].score != expectedScoreMat[i][0])
        {
            cout << "initial score mismatch at element [" << i << "][0]\n";
            cout << "score: " << mat[i][0].score << endl;
            output = false;
        }
    }

    for (size_t i = 0; i < cols; i++)
    {
        if (mat[0][i].score != expectedScoreMat[0][i])
        {
            cout << "initial score mismatch at element [0][" << i << "]\n";
            cout << "score: " << mat[0][i].score << endl;
            output = false;
        }
    }

    return output;
}

bool testFillMat(Cell **mat, size_t cols, size_t rows, string &s1, string &s2,
                 int32_t (*expectedScoreMat)[8])
{
    fillMat(mat, rows, cols, s1, s2);

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            if (mat[i][j].score != expectedScoreMat[i][j])
            {
                cout << "fill score mismatch at element [" << i << "][" << j << "]\n";
                cout << mat[i][j].score << " != " << expectedScoreMat[i][j] << endl;
                return false;
            }
        }
    }
    return true;
}

bool testAlignment(Cell **mat, size_t cols, size_t rows, string &s1, string &s2,
                   int32_t expectedScore, array<string, 3>& expectedAlignment)
{
    array<string, 3> alignment;
    int32_t score = alignMat(mat, rows, cols, s1, s2, alignment);

    for (uint8_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < alignment.at(0).size(); j++)
        {
            char c1 = expectedAlignment.at(i).at(j);
            char c2 = alignment.at(i).at(j);
            if(c1 != c2)
            {
                cout << "alignment mismatch at char [" << j << "], string: " << i << endl;
                cout << c1 << " != " << c2 << endl;
                return false;
            }
        }
    }
    return true;
}

int main(int nargs, char **argv)
{
    Cell **mat = NULL;
    size_t cols = 0, rows = 0;

    // Test data
    string seq1 = "GATTACA";
    string seq2 = "CGATACG";

    // Expected output
    size_t expectedCols = 8;
    size_t expectedRows = 8;
    int32_t expectedScoreMat[8][8] = {
        {0, -1, -2, -3, -4, -5, -6, -7},
        {-1, -1, 0, -1, -2, -3, -4, -5},
        {-2, -2, -1, 1, 0, -1, -2, -3},
        {-3, -3, -2, 0, 2, 1, 0, -1},
        {-4, -4, -3, -1, 1, 1, 0, -1},
        {-5, -5, -4, -2, 0, 2, 1, 0},
        {-6, -4, -5, -3, -1, 1, 3, 2},
        {-7, -5, -5, -4, -2, 0, 2, 2},
    };
    
    int32_t expectedScore = 2;
    array<string, 3> expectedAlignment = {
        "-GATTACA",
        " || |||*",
        "CGA-TACG",
    };

    // Test 1
    if (!testMatInit(mat, cols, rows, seq1, seq2, expectedCols, expectedRows, expectedScoreMat))
        return -1;
    cout << "Mat Init success!!\n";

    // Test 2
    if (!testFillMat(mat, cols, rows, seq1, seq2, expectedScoreMat))
        return -1;
    cout << "Fill Mat test success!!\n";

    // Test 3
    if(!testAlignment(mat, cols, rows, seq1, seq2, expectedScore, expectedAlignment))
        return -1;
    cout << "Alignment test success\n";

    // Liberar memoria
    for (size_t i = 0; i < rows; i++)
        delete[] mat[i];
    delete[] mat;

    return 0;
}
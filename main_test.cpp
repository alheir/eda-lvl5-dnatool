#include <iostream>

using namespace std;

#include "Needlemachine.h"
#include <string>

using namespace std;

bool testMatInit(string& s1, string& s2, size_t cols, size_t rows, int32_t** expectedScore)
{
    Cell** mat = NULL;
    
    if((s1.size() + 1) != rows || (s2.size() + 1) != cols)
    {
        cout << "Mat size init error!\n";
        return false;
    }
    size_t cols=0, rows=0;
    initMat(mat, rows, cols, s1, s2);

    for(size_t i=0; i < rows; i++)
    {
        if(mat[i][0].score != expectedScore[i][0])
        {
            cout << "score mismatch at element [" << i << "][0]\n";
            return false;
        }
    }

    for(size_t i=0; i < cols; i++)
    {
        if(mat[0][i].score != expectedScore[0][i|])
        {
            cout << "score mismatch at element [0][" << i << "]\n";
            return false;
        }
    }
}

int main(int nargs, char** argv)
{
    size_t cols = 8;
    size_t rows = 8;
    int32_t matFinalScore[8][8] = {
        { 0, -1, -2, -3, -4, -5, -6, -7},
        {-1, -1,  0, -1, -2, -3, -4, -5},
        {-2, -2, -1,  1,  0, -1, -2, -3},
        {-3, -3, -2,  0,  2,  1,  0,  1},
        {-4, -4, -3, -1,  1,  1,  0, -1},
        {-5, -5, -4, -2,  0,  2,  1,  0},
        {-6, -4, -5, -3, -1,  1,  3,  2},
        {-7, -5, -5, -4, -2,  0,  2,  2},
    };

    string seq1 = "GATTACA";
    string seq2 = "CGATACG";



    return 0;
}
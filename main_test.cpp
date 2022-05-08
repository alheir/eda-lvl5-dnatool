/**
 * @file main_test.cpp
 * @authors DALZOTTO, Rafael; HEIR, Alejandro - Grupo 7
 * @brief Tests for the genetic sequence aligner
 * @version 0.1
 * @date 2022-05-08
 *
 * @copyright Copyright (c) 2022 - 22.08 EDA - ITBA
 *
 */

#include <iostream>
#include <string>
#include <array>
#include <fstream>
#include <sstream>

#include "GBReader.h"
#include "Aligner.h"

using namespace std;

bool testMatInit(DirectionMat *&mat, const string &s1, const string &s2, DirectionMat &expectedMat)
{
    bool output = true;

    mat = initMat(s1.length() + 1, s2.length() + 1);

    if (mat->getRows() != expectedMat.getRows() || mat->getCols() != expectedMat.getCols())
    {
        cout << "Mat size init error!\n";
        output = false;
    }

    for (size_t i = 0; i < mat->getRows(); i++)
    {
        if (mat->at(i, 0) != expectedMat.at(i, 0))
        {
            cout << "initial direction mismatch at element [" << i << "][0]\n";
            cout << "direction: " << mat->at(i, 0) << endl;
            output = false;
        }
    }

    for (size_t i = 0; i < mat->getCols(); i++)
    {
        if (mat->at(0, i) != expectedMat.at(0, i))
        {
            cout << "initial score mismatch at element [0][" << i << "]\n";
            cout << "score: " << mat->at(0, i) << endl;
            output = false;
        }
    }

    return output;
}

bool testFillMat(DirectionMat *mat, const string &s1, const string &s2,
                 int32_t expectedScore, DirectionMat &expectedMat)
{
    int32_t calcScore = fillMat(mat, s1, s2);
    if (expectedScore != calcScore)
    {
        cout << "optimal score calculation failure\n";
        cout << "Expected: " << expectedScore << endl;
        cout << "Calculated: " << calcScore << endl;

        return false;
    }

    for (size_t i = 0; i < mat->getRows(); i++)
    {
        for (size_t j = 0; j < mat->getCols(); j++)
        {
            if (mat->at(i, j) != expectedMat.at(i, j))
            {
                cout << "fill direction mismatch at element [" << i << "][" << j << "]\n";
                cout << mat->at(i, j) << " != " << expectedMat.at(i, j) << endl;
                return false;
            }
        }
    }
    return true;
}

bool testAlignment(DirectionMat *mat, const string &s1, const string &s2,
                   array<string, 3> &expectedAlignment)
{
    array<string, 3> alignment;
    buildAligment(mat, s1, s2, alignment);

    for (uint8_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < alignment.at(0).size(); j++)
        {
            char c1 = expectedAlignment.at(i).at(j);
            char c2 = alignment.at(i).at(j);
            if (c1 != c2)
            {
                cout << "alignment mismatch at char [" << j << "], string: " << i << endl;
                cout << c1 << " != " << c2 << endl;
                return false;
            }
        }
    }
    return true;
}

int main()
{
    // Test data
    string sampleString1 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vestibulum sagittis et ex eget convallis. Nam sed leo eget libero laoreet semper eget at lacus.\n"
                           "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vestibulum sagittis et ex eget convallis. Nam sed leo eget libero laoreet semper eget at lacus.\n"
                           "ORIGIN\n"
                           "1 gattaca\n"
                           "//";
    string sampleString2 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vestibulum sagittis et ex eget convallis. Nam sed leo eget libero laoreet semper eget at lacus.\n"
                           "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vestibulum sagittis et ex eget convallis. Nam sed leo eget libero laoreet semper eget at lacus.\n"
                           "ORIGIN\n"
                           "1 cgatacg\n"
                           "//";

    istringstream sampleFile1(sampleString1), sampleFile2(sampleString2);

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

    // Expected output
    string expectedSeq1 = "GATTACA";
    string expectedSeq2 = "CGATACG";
    size_t expectedRows = 8;
    size_t expectedCols = 8;

    DirectionMat expectedMat(expectedRows, expectedCols);
    uint8_t hardcodedMat[8][8] = {
        {2, 2, 2, 2, 2, 2, 2, 2},
        {0, 1, 1, 2, 2, 2, 2, 1},
        {0, 0, 0, 1, 2, 1, 2, 2},
        {0, 0, 0, 0, 1, 2, 2, 2},
        {0, 0, 0, 0, 0, 1, 1, 1},
        {0, 0, 0, 0, 0, 1, 2, 2},
        {0, 1, 0, 0, 0, 0, 1, 2},
        {0, 0, 1, 0, 0, 0, 0, 1},
    };

    for (int i = 0; i < expectedRows; i++)
    {
        for (int j = 0; j < expectedCols; j++)
        {
            expectedMat.set(hardcodedMat[i][j], i, j);
        }
    }

    int32_t expectedScore = 2;
    array<string, 3> expectedAlignment = {
        "-GATTACA",
        " ||| ||*",
        "CGAT-ACG"};

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

    // Test 1
    string extractedSeq1, extractedSeq2;
    if (!getSequence(extractedSeq1, sampleFile1))
    {
        cout << "Failure in sequence 1 extraction\n";
        return -1;
    }
    if (extractedSeq1.compare(expectedSeq1))
    {
        cout << "Sequence 1 mismatch\n";
        return -1;
    }
    cout << "Sequence 1 extraction success!\n";

    if (!getSequence(extractedSeq2, sampleFile2))
    {
        cout << "Failure in sequence 2 extraction\n";
        return -1;
    }
    if (extractedSeq2.compare(expectedSeq2))
    {
        cout << "Sequence 1 mismatch\n";
        return -1;
    }
    cout << "Sequence 2 extraction success!\n";

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

    // Test 2
    DirectionMat *mat;
    if (!testMatInit(mat, extractedSeq1, extractedSeq2, expectedMat))
        return -1;
    cout << "Mat Init success!\n";

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

    // Test 3
    if (!testFillMat(mat, extractedSeq1, extractedSeq2, expectedScore, expectedMat))
        return -1;
    cout << "Fill Mat test success!\n";

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

    // Test 4
    if (!testAlignment(mat, extractedSeq1, extractedSeq2, expectedAlignment))
        return -1;
    cout << "Alignment test success!\n";

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

    // Liberar memoria
    delete mat;

    return 0;
}
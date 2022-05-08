/**
 * @file main.cpp
 * @authors DALZOTTO, Rafael; HEIR, Alejandro - Grupo 7
 * @brief Runs the genetic sequence aligner
 * @version 0.1
 * @date 2022-05-08
 *
 * @copyright Copyright (c) 2022 - 22.08 EDA - ITBA
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>

#include "GBReader.h"
#include "Aligner.h"

using namespace std;

static const int splitter = 60;

int main(int argc, char **argv)
{
    auto startTime = chrono::steady_clock::now();

    ifstream sample1(argv[1]);
    if (!sample1.is_open())
    {
        cout << "Error opening " << argv[1] << endl;
        return 1;
    }

    ifstream sample2(argv[2]);
    if (!sample2.is_open())
    {
        cout << "Error opening " << argv[2] << endl;
        return 1;
    }

    string seq1;
    if (!getSequence(seq1, sample1))
    {
        cout << "Error extracting first sequence..." << endl;
        return 1;
    }
    sample1.close();

    string seq2;
    if (!getSequence(seq2, sample2))
    {
        cout << "Error extracting second sequence..." << endl;
        return 1;
    }
    sample2.close();

    array<string, 3> optimalAlignment;
    int32_t optimalScore;

    optimalScore = getGlobalAlignment(seq1, seq2, optimalAlignment);

    cout << "Secuencias comparadas: " << endl;
    cout << '\t' << argv[1] << endl;
    cout << '\t' << argv[2] << endl
         << endl;

    cout << "Puntaje óptimo: " << optimalScore << endl
         << endl;
    cout << "Alineamiento óptimo: " << endl
         << endl;

    for (int i = 0; i < optimalAlignment[0].length(); i += splitter)
    {
        cout << optimalAlignment[0].substr(i, splitter).data() << endl;
        cout << optimalAlignment[1].substr(i, splitter).data() << endl;
        cout << optimalAlignment[2].substr(i, splitter).data() << endl
             << endl;
    }

    cout << endl;

    auto endTime = chrono::steady_clock::now();

    cout << "Elapsed time in milliseconds: "
         << chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count()
         << " ms" << endl;
    cout << "Elapsed time in seconds: "
         << chrono::duration_cast<chrono::seconds>(endTime - startTime).count()
         << " s" << endl;

    return 0;
}

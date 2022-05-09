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
using namespace chrono;

static const int splitInterval = 60;

void printElapsedFrom(time_point<steady_clock>& timestamp);

int main(int argc, char **argv)
{
    auto startTime = steady_clock::now();

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
        cout << "Error extracting first sequence...\n";
        return 1;
    }
    sample1.close();

    string seq2;
    if (!getSequence(seq2, sample2))
    {
        cout << "Error extracting second sequence...\n";
        return 1;
    }
    sample2.close();

    array<string, 3> optimalAlignment;
    int32_t optimalScore;

    optimalScore = getGlobalAlignment(seq1, seq2, optimalAlignment);

    cout << "Secuencias comparadas: \n";
    cout << '\t' << argv[1] << endl;
    cout << '\t' << argv[2] << endl;

    cout << "\nPuntaje óptimo: " << optimalScore;
    cout << "\n\nAlineamiento óptimo: \n\n";

    for (int i = 0; i < optimalAlignment[0].length(); i += splitInterval)
    {
        cout << optimalAlignment[0].substr(i, splitInterval).data() << endl;
        cout << optimalAlignment[1].substr(i, splitInterval).data() << endl;
        cout << optimalAlignment[2].substr(i, splitInterval).data() << "\n\n";
    }

    cout << endl;

    printElapsedFrom(startTime);

    return 0;
}

void printElapsedFrom(time_point<steady_clock>& timestamp)
{
    auto now = steady_clock::now();

    cout << "Elapsed time in milliseconds: "
         << duration_cast<milliseconds>(now - timestamp).count()
         << " ms" << endl;
    cout << "Elapsed time in seconds: "
         << duration_cast<seconds>(now - timestamp).count()
         << " s" << endl;
}
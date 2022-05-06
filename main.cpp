#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "Needlemachine.h"

using namespace std;

static const int splitter = 60;

void getSequence(string &output, ifstream &file);

bool isACGT(char c);

int main(int argc, char **argv)
{
    string seq1 = "GATTACA";
    string seq2 = "CGATACG";
    array<string, 3> optimalAlignment;
    int32_t optimalScore;

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

    getSequence(seq1, sample1);
    getSequence(seq2, sample2);

    optimalScore = getGlobalAlignment(seq1, seq2, optimalAlignment);

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

    return 0;
}

void getSequence(string &output, ifstream &file)
{
    output.clear();
    string tempStr;

    while (getline(file, tempStr))
    {
        if (tempStr.substr(0, 6) == "ORIGIN")
            break;
    }

    while (getline(file, tempStr))
    {
        if (tempStr.substr(0, 2) == "//")
            break;

        tempStr.erase(remove_if(tempStr.begin(), tempStr.end(), isACGT), tempStr.end());

        output.append(tempStr);
    }
}

bool isACGT(char c)
{
    return !(c == 'a' || c == 'c' || c == 'g' || c == 't');
}
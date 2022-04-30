#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "Needlemachine.h"

using namespace std;

void getSequence(string &output, ifstream &file);

bool isACGT(char c);

int main(int argc, char **argv)
{
    string str1 = "GATTACA";
    string str2 = "CGATACG";
    array<string,3> alignedSequence;

    getGlobalAlignment(str1, str2, alignedSequence);

    //ifstream sample1(argv[1]);
    //ifstream sample2(argv[2]);

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
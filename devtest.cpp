#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

#include "GenData.h"

int main(int argc, char **argv)
{
    string str = "tgcaacgtaaaaccccggggtttt";

    GenData sequence(str);

    cout << "len: " << sequence.length() << endl;
    cout << "bsize: " << sequence.data.size() << endl;
    cout << "block0: ";

    for(uint8_t b : sequence.data)
    {
        cout << (int)b << " ";
    }
    cout << endl;

    uint8_t block0 = sequence.data.at(0);
    printf("\n%0X\n", block0);

    /* ifstream sample1(argv[1]);

    int i=0;
    if (sample1.is_open())
    {
        while (getline(sample1, str1))
        {
            i++;
            if(i == 500)
            {
                cout << str1 << endl; // aacatgagcatgaaattgcttggtacacggaacgttctgaaaagagctatgaattgcaga
                cout << "line len: " << str1.length() << endl;

                for(auto c : str1)
                {
                    cout << "'" << c << "', ";
                }

                cout << endl << endl;
            }
        }

        sample1.close();
    } */

    return 0;
}
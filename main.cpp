#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    string str1, str2;

    ifstream sample1(argv[1]);
    ifstream sample2(argv[2]);

    if (sample1.is_open())
    {
        while (getline(sample1, str1))
        {
            cout << str1 << endl;
        }

        sample1.close();
    }

    if (sample2.is_open())
    {
        while (getline(sample2, str2))
        {
            cout << str2 << endl;
        }

        sample2.close();
    }


    return 0;
}
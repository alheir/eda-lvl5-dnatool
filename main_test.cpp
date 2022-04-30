#include <iostream>

using namespace std;

int main(int nargs, char** argv)
{
    cout << "args:" << endl;
    for(int i=0; i<nargs; i++)
    {
        cout << argv[i] << endl;
    }
    return 0;
}
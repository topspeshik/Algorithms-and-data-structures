#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

int main()
{
    cout<< "Write number of sets" << endl;
    int n;
    cin >> n;
    ofstream out;
    out.open("out.txt");
    for (int i = 0; i < n; i++)
    {
       
        for (int j = 0; j < 3; j++)
        {
            out << M_PI * (double(rand()) / RAND_MAX) - M_PI / 2 << " ";
        }
        out << endl;
    }

    out.close();

}

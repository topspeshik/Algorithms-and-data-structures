#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

int main() 
{

    ifstream in;
    in.open("out.txt");
    double x, y, z;
    while(in >> x)
    {

        in  >> y >> z;
        double angle = 2 * sin(x) * sin(y) + cos(z);
        cout << angle * (180 / M_PI) << endl;
    }
    in.close();

}

#include <iostream>
#include "NDArray.h"
using namespace std;


int main()
{
    int shape[2] = { 3,2 };
    int shape1[2] = { 2,3 };
    int fill[6] = { 1,2,3,4,5,6 };
    NDArray a(shape, fill);
    NDArray b(shape1, fill);
    NDArray c(shape);
    c.random();
    cout << "Array c - random" << endl;
    cout << c << endl;
    cout << "Array a" << endl;
    cout << a << endl;
    cout << "Array b" << endl;
    cout << b << endl;
    cout << "Transposition a" << endl;
    cout << a.T() << endl;
    cout << "Matrix multiplication - a * b" << endl;
    NDArray d = a.matMul(b);
    cout << d << endl;
}
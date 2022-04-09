#pragma once

#include <iostream>
#include <ostream>

using namespace std;

class NDArray
{
public:
    NDArray(int* shapeArr, int fill = 0);

    NDArray(int* shapeArr, int* fill);

    void random();

    int* getRow(int index);

    NDArray T();

    NDArray matMul(NDArray& other);

    NDArray operator+(const NDArray& other);

    NDArray operator-(const NDArray& other);

    NDArray operator*(const NDArray& other);
 
    NDArray operator/(const NDArray& other);

    NDArray element_with_operator(const NDArray& other, int oper);

    friend ostream& operator<<(ostream& os, const NDArray& arr);

private:
    int* shape = new int[2];
    int* array;
    int size;

};
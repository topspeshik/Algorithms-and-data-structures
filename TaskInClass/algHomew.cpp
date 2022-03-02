// algHomew.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    ofstream out;
    out.open("out.txt");
    for (int i = 0; i < n; i++)
    {
        int arr[3] = { rand() % 6 + (-3), rand() % 6 + (-3), rand() % 6 + (-3) };
        cout << arr[1] << endl;
        for (int j = 0; j < 3; j++)
        {
            out << arr[j] << " ";
        }
        out << endl;
    }


    //cout << rand() % 6 + (-3) << endl;
}


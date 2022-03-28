#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	vector<float>* vec = new vector<float>;
	int s;
	for (int i = 0; i <= 7; i++)
	{
		s = pow(10, i);
		for (int j = 0; j < s; j++)
		{
			vec->push_back(j);
		}


		cout << s << " " << sizeof(vector<float>) + sizeof(float) * vec->capacity() << " ";

	}

}


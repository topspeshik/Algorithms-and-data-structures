#include "NDArray.h"

NDArray::NDArray(int* shapeArr, int fill)
{
	for (int i = 0; i < 2; i++)
	{
		shape[i] = shapeArr[i];
	}

	this->size = shape[0] * shape[1];
	array = new int[this->size];

	for (int i = 0; i < this->size; i++)
	{
		array[i] = fill;
	}
}

NDArray::NDArray(int* shapeArr, int* fill)
{
	for (int i = 0; i < 2; i++)
	{
		shape[i] = shapeArr[i];
	}

	this->size = shape[0] * shape[1];
	array = new int[this->size];

	for (int i = 0; i < this->size; i++)
	{
		array[i] = fill[i];
	}
}

void NDArray::random()
{
	for (int i = 0; i < this->size; i++)
	{
		array[i] = rand();
	}
}

int* NDArray::getRow(int index)
{
	int* result = new int[shape[1]];
	int rowIndex = index * shape[1];

	for (int i = 0; i < shape[1]; i++)
	{
		result[i] = array[rowIndex];
		rowIndex++;
	}

	return result;
}

NDArray NDArray::T()
{
	int* res = new int[this->size];
	int index = 0;

	for (int i = 0; i < shape[0]; i++)
	{
		int* row = new int[shape[1]];
		row = this->getRow(i);
		index = i;
		for (int j = 0; j < shape[1]; j++)
		{
			res[index] = row[j];
			index += shape[0];
		}
		delete[]row;

	}

	int resShape[2] = { shape[1] , shape[0] };
	NDArray result(resShape, res);
	return result;
}

NDArray NDArray::matMul(NDArray& other)
{
	int* res = new int[shape[0] * other.shape[1]];
	int sum = 0;
	int count = 0;
	for (int i = 0; i < shape[0]; i++)
	{
		int* row = new int[shape[1]];
		row = this->getRow(i);

		for (int j = 0; j < other.shape[1]; j++)
		{
			int* otherMat = new int[other.T().shape[1]];
			otherMat = other.T().getRow(j);
			for (int c = 0; c < other.T().shape[1]; c++)
			{
				sum += row[c] * otherMat[c];
			}
			res[count] = sum;
			sum = 0;
			count++;
			delete[] otherMat;
		}
		delete[] row;

	}

	int shapeRes[2] = { shape[0], other.shape[1] };
	NDArray result(shapeRes, res);

	return result;
}

NDArray NDArray::element_with_operator(const NDArray& other, int oper)
{
	int* result = new int[this->size];

	for (int i = 0; i < this->size; i++)
	{
		if (oper == 1) {
			result[i] = array[i] + other.array[i];
		}
		if (oper == 2) {
			result[i] = array[i] - other.array[i];
		}
		if (oper == 3) {
			result[i] = array[i] * other.array[i];
		}
		if (oper == 4) {
			result[i] = array[i] / other.array[i];
		}
	}

	NDArray res(shape, result);
	return res;
}

NDArray NDArray::operator+(const NDArray& other)
{
	return this->element_with_operator(other, 1);
}

NDArray NDArray::operator-(const NDArray& other)
{
	return this->element_with_operator(other, 2);
}

NDArray NDArray::operator*(const NDArray& other)
{
	return this->element_with_operator(other, 3);
}

NDArray NDArray::operator/(const NDArray& other)
{
	return this->element_with_operator(other, 4);
}

ostream& operator<<(ostream& os, const NDArray& arr)
{
	int count = 0;
	for (int i = 0; i < arr.shape[0]; i++)
	{
		for (int j = 0; j < arr.shape[1]; j++)
		{
			os << arr.array[count] << " ";
			count++;
		}
		os << endl;
	}
	return os;
}

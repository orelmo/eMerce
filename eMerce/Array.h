#ifndef _ARRAY_H_
#define _ARRAY_H_
#include<iostream>

//T is pointer.
//*T must have << operator.

template<class T>
class Array
{
private:
	int physicalSize, logicalSize;
	char delimiter;
	T* arr;

public:
	Array(int maxSize = 10, char delimiter = ' ')
	{
		physicalSize = maxSize;
		logicalSize = 0;
		this->delimiter = delimiter;
		arr = new T[physicalSize];
	}

	Array(const Array& other):arr(nullptr)
	{
		*this = other;
	}

	~Array()
	{
		for (int i = 0; i < logicalSize; i++)
			delete arr[i];
		//delete[] arr;
	}

	const Array& operator=(const Array& other)
	{//the function don't delete the content of the array.
		if (this != &other)
		{
			delete[]arr;
			this->logicalSize = other.logicalSize;
			this->physicalSize = other.physicalSize;
			this->delimiter = other.delimiter;
			this->arr = new T[physicalSize];
			for (int i = 0; i < logicalSize; i++)
				this->arr[i] = other.arr[i];
		}
		return *this;
	}

	const Array& operator+=(const T other)
	{
		if (logicalSize >= physicalSize)
		{
			physicalSize *= 2;
			T* temp = new T[physicalSize];
			for (int i = 0; i < logicalSize; i++)
				temp[i] = this->arr[i];
			delete[]arr;
			arr = temp;
		}
		arr[logicalSize++] = other;
		return *this;
	}

	const int size()
	{
		return logicalSize;
	}

	friend std::ostream& operator<<(std::ostream& os, const Array& arr)
	{
		for (int i = 0; i < arr.logicalSize; i++)
			os << *arr[i] << arr.delimiter;
		return os;
	}
};
#endif // !_ARRAY_H_
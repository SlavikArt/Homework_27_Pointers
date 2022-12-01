#include <iostream>
using namespace std;

void ArrReverseCopy(int* arr1, int* arr2, const int SIZE);
void MoveArr(int* arr, const int SIZE);
int ArrMax(int* arr, const int SIZE);
int ArrMin(int* arr, const int SIZE);
void PrintArr(int* arr, const int SIZE);

int main()
{
	srand(time(0));

	int SIZE = 10;

	cout << "Enter a size of array: ";
	cin >> SIZE;

	int *arr1 = new int[SIZE];
	int *arr2 = new int[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		*(arr1 + i) = rand() % 100;
		*(arr2 + i) = rand() % 100;
	}

	PrintArr(arr1, SIZE);
	PrintArr(arr2, SIZE);

	cout << "\n";
	ArrReverseCopy(arr1, arr2, SIZE);

	PrintArr(arr1, SIZE);
	PrintArr(arr2, SIZE);

	cout << "\n";
	cout << "Max: " << ArrMax(arr1, SIZE) << "\nMin: " << ArrMin(arr1, SIZE) << "\n";

	MoveArr(arr1, SIZE);
	cout << "\n";
	PrintArr(arr1, SIZE);

	delete[] arr1;
	delete[] arr2;
}

void ArrReverseCopy(int* arr1, int* arr2, const int SIZE)
{
	for (int i = 0, j = SIZE - 1; i < SIZE / 2 && j >= SIZE / 2; i++, j--)
	{
		int tmp = *(arr1 + i);
		*(arr1 + i) = *(arr1 + j);
		*(arr1 + j) = tmp;
	}

	for (int i = 0; i < SIZE; i++)
	{
		*(arr2 + i) = *(arr1 + i);
	}
}

void MoveArr(int* arr, const int SIZE)
{
	int tmp = *(arr + SIZE - 1);
	for (int i = SIZE - 1; i >= 0; i--)
	{
		*(arr + i) = *(arr + i - 1);
	}
	*arr = tmp;
}

int ArrMax(int* arr, const int SIZE)
{
	int max = *arr;
	for (int i = 1; i < SIZE; i++)
	{
		if (max < *(arr + i))
		{
			max = *(arr + i);
		}
	}
	return max;
}

int ArrMin(int* arr, const int SIZE)
{
	int min = *arr;
	for (int i = 1; i < SIZE; i++)
	{
		if (min > *(arr + i))
		{
			min = *(arr + i);
		}
	}
	return min;
}

void PrintArr(int* arr, const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << "\n";
}
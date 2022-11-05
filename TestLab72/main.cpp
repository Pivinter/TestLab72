// Lab_7_2_2.cpp
#include "pch.h"
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void CreateRow(int** a, const int rowNo, const int K, const int Low,
	const int High, int colNo)
{
	a[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < K - 1)
		CreateRow(a, rowNo, K, Low, High, colNo + 1);
}
void CreateRows(int** a, const int N, const int K, const int Low, const int High, int rowNo)
{
	CreateRow(a, rowNo, K, Low, High, 0);
	if (rowNo < N - 1)
		CreateRows(a, N, K, Low, High, rowNo + 1);
}
void PrintRow(int** a, const int rowNo, const int K, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < K - 1)
		PrintRow(a, rowNo, K, colNo + 1);
	else
		cout << endl;
}
void PrintRows(int** a, const int N, const int K, int rowNo)
{
	PrintRow(a, rowNo, K, 0);
	if (rowNo < N - 1)
		PrintRows(a, N, K, rowNo + 1);
	else
		cout << endl;
}
void SearchFirstEven(int** a, const int K, int i, int& minEven, int& k)
{
	if (a[i][k - 1 - i] % 2 != 0)
	{
		k = i;
		minEven = a[i][K - 1 - i];
	}
	else
		if (i < K - 1)
			SearchFirstEven(a, K, i + 1, minEven, k);
}
void SearchMinEven(int** a, const int N, int i, int& minEven)
{
	if (a[i][N - 1 - i] % 2 != 0 && a[i][N - 1 - i] < minEven)
		minEven = a[i][N - 1 - i];
	if (i < N - 1)
		SearchMinEven(a, N, i + 1, minEven);
}
int main()
{
	srand((unsigned)time(NULL));
	int N, K;
	cout << "N = "; cin >> N;
	cout << "K = "; cin >> K;
	cout << endl;
	int** a = new int* [N];
	for (int i = 0; i < N; i++)
		a[i] = new int[K];
	int Low = -9, High = 9;

	CreateRows(a, N, K, Low, High, 0);
	PrintRows(a, N, K, 0);

	int k = -1;
	int minEven;
	SearchFirstEven(a, K, 0, minEven, k);
	if (k >= -1)
	{
		SearchMinEven(a, N, k + 1, minEven);
		cout << "minEven = " << minEven << endl;
	}
	else
		cout << "there are no even elements" << endl;
	for (int i = 0; i < N; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
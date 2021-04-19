#include <iostream>
#include<chrono>
#include<fstream>
#include<iomanip>
#include "String.h"
#include <cmath>
using namespace std;

const int QUINTET = 5;

void iMeasure(void foo(double*, int), double* arr, int n)
{
	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);
	foo(arr, n);// Here you put the name of the function you wish to measure
	auto end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program.
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	ofstream myfile("Measure.txt", ios::app); // The name of the file
	myfile << "Time taken by function <insertionSort> is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();
}


double sMeasure(double foo(double*, int, int, int), double* arr,int left ,int right, int i)
{
	double val;
	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);
	val = foo(arr, left, right, i);// Here you put the name of the function you wish to measure
	auto end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program.
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	ofstream myfile("Measure.txt", ios::app); // The name of the file
	myfile << "Time taken by function <select> is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();

	return val;
}

double &qMeasure(double &foo(double*, int, int), double *arr, int n, int i)
{
	double val;
	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);
	val = foo(arr, n, i);// Here you put the name of the function you wish to measure
	auto end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program.
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	ofstream myfile("Measure.txt", ios::app); // The name of the file
	myfile << "Time taken by function <quintetsSort> is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();

	return val;
}

void bubbleSort(double* arr, int size)
{
	int i, j;

	for (i = 0; i < size - 1; i++)
		for (j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
}

void errorMsg()
{
	cout << "wrong input" << endl;
	exit(1);
}
void swap(double& i, double& j)
{
	double temp = i;
	i = j;
	j = temp;
}

void insertionSort(double* arr, int size)
{
	int i = 0;
	int j = 0;
	for (i; i < size; i++)
	for (i; i < size; i++)
	{
		j = i;
		while (j > 0 && arr[j - 1] > arr[j])
		{
			swap(arr[j], arr[j - 1]);
			j--;
		}

	}
}



int partition(double* arr, int start, int size)
{
	int pivot, i, temp;
	pivot = start;
	i = size - 1;

	while (i != pivot)
	{
		if (i < pivot)
		{
			if (arr[i] < arr[pivot])
				i++;
			else
			{
				swap(arr[i], arr[pivot]);
				swap(i, pivot);
				i--;
			}
		}
		else
		{
			if (arr[pivot] < arr[i])
				i--;
			else
			{
				swap(arr[i], arr[pivot]);
				swap(i, pivot);
				i++;

			}
		}
	}
	return pivot;
}

int partition2(double* arr, int left, int right, double& pivot)
{
	int i;

	for (i = 0; i <= right; i++)
		if (arr[i] == pivot)
			break;

	swap(arr[i], arr[0]);

	while (left <= right)
	{
		if (arr[left] > pivot && arr[right] < pivot)
			swap(arr[left], arr[right]);
		else
		{

			while (arr[right] > pivot)
				right--;
			while (arr[left] < pivot)
				left++;
		}
	}

	swap(arr[right], arr[0]);

	return right;
}

double select(double* arr, int left, int right, int i)
{
	int pivot, leftPart;

	pivot = partition(arr, left, right);
	//pivot = partition2(arr, left+1, right-1, arr[0]);
	leftPart = pivot - left + 1;
	if (i == leftPart)
		return arr[pivot];
	if (i < leftPart)
		return select(arr, left, pivot, i);
	else
		return select(arr, pivot + 1, right, i - leftPart);
}

double& quintetsSort(double* arr, int size, int idx)
{
	int i, j, mediansIdx = 0, lastQuintetSize = size % 5;
	int quintetSize = 5;
	int numOfQuintets = ceil((double)size / 5);
	bool isLastQuintet = false;
	bool isDividedByFive = size % 5 == 0;
	int k;

	if (size <= 5)
	{
		bubbleSort(arr, size);
		return arr[idx - 1];
	}
	double tempArr[QUINTET]{ 0 };
	double* B = new double[numOfQuintets];

	for (i = 0; i < numOfQuintets; i++)
	{
		if (i == numOfQuintets - 1)
		{
			isLastQuintet = true;
			if (lastQuintetSize != 0)
				quintetSize = lastQuintetSize;
		}
		for (j = 0; j < quintetSize; j++)
		{
			tempArr[j] = arr[j + (i * QUINTET)];
		}
		bubbleSort(tempArr, quintetSize);
		if (isLastQuintet == true && !isDividedByFive)
			B[mediansIdx] = tempArr[lastQuintetSize / 2];
		else if (isLastQuintet == true)
			B[mediansIdx] = tempArr[quintetSize / 2];
		else
		{
			B[mediansIdx] = tempArr[quintetSize / 2];
			mediansIdx++;
		}
	}
	//double pivot = select(B, 0, mediansSize, (mediansSize / 2)+1);// the median is the the member which the n/2+1 in size

	double pivot = quintetsSort(B, numOfQuintets, numOfQuintets / 2 + 1);

	k = partition2(arr, 1, size - 1, pivot);

	if (idx < k + 1)
	{
		return quintetsSort(arr, k, idx);
	}
	if (idx > k + 1)
	{
		return quintetsSort(arr + k + 1, size - k - 1, idx - k - 1);
	}
	return arr[k];
}






int main()
{
	int n, i, j, counter, idx;
	double temp, qVal, sVal;
	char ch;

	cout << "Please enter the number of numbers you would like to enter and after that," <<
		" enter the index you would like to find" << endl;
	cin >> n >> i;

	if (i > n || i <= 0)
		errorMsg();

	cout << "Please enter the numbers from which you would like to find the index" << endl;


	double* arr = new double[n];

	counter = idx = 0;
	for (idx = 0; idx < n; idx++)
	{
		String str;
		str.getNum();
		arr[idx] = atof(str);
	}
	cout << endl;

	double* CopyArr = new double[n];
	for (idx = 0; idx < n; idx++)
	{
		CopyArr[idx] = arr[idx];
	}

	double* CopyArr2 = new double[n];
	for (idx = 0; idx < n; idx++)
	{
		CopyArr2[idx] = arr[idx];
	}

	iMeasure(insertionSort, arr, n);

	cout << "Insertion sort i'th element: " << fixed << setprecision(4) << arr[i - 1] << endl;

	//	cout << selection(arr,n, i) << endl;

	sVal = sMeasure(select, CopyArr, 0, n, i);

	cout << "Selection i'th element: " << fixed << setprecision(4) << sVal << endl;

	qVal = qMeasure(quintetsSort, CopyArr2, n, i);
	cout << "Quintuplet algorithm i'th element: " << fixed << setprecision(4) << qVal << endl;

	return 0;
}

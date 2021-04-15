#include <iostream>
#include<chrono>
#include<fstream>
#include<iomanip>
#include "String.h"
using namespace std;

const int QUINTET = 5;

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

void insertionSort(double *arr, int size)
{
	int i = 0;
	int j = 0;
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

///////////////////////////////////////////////////

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
				temp = i;
				i = pivot;
				pivot = temp;
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
				temp = i;
				i = pivot;
				pivot = temp;
				i++;
			}
		}
	}
	return pivot;
}

double select(double* arr, int left, int right, int i)
{
	int pivot, leftPart;

	pivot = partition(arr, left, right);
	leftPart = pivot - left + 1;
	if (i == leftPart)
		return arr[pivot];
	if (i < leftPart)
		return select(arr, left, pivot - 1, i);
	else
		return select(arr, pivot + 1, right, i - leftPart);
}

int recQuintets(double* arr, int size)
{
	int i, j, mediansSize = size / QUINTET, mediansIdx = 0, lastQuintetSize = size % 5;
	int quintetSize = 5;
	int pivot;
	bool isLastQuintet = false;
	
	if (size <= 5)
	{
		bubbleSort(arr, size);
		return size / 2;
	}
	double tempArr[QUINTET]{ 0 };
	double* B= new double[mediansSize];

	for (i = 0; i < size; i+=5)
	{
		if (i == size - lastQuintetSize && lastQuintetSize!=0)
		{
			quintetSize = lastQuintetSize;
			isLastQuintet = true;
		}
		for (j = 0; j < quintetSize; j++)
		{
			tempArr[j] = arr[j+(i)];
		}
		bubbleSort(tempArr, QUINTET);
		if(isLastQuintet == true)
			B[mediansIdx] = tempArr[lastQuintetSize / 2];
		else
		{
			B[mediansIdx] = tempArr[QUINTET / 2];
			mediansIdx++;
		}
	}
	pivot = recQuintets(B, mediansSize);
}



double quintetsSort(double* arr, int size, int idx)
{
	int pivot, k;
	pivot = recQuintets(arr, size);
	cout << pivot << " " << arr[pivot] << endl;
	k = partition(arr, pivot, size);

	if (idx < k)
	{
		return quintetsSort(arr, size - k, idx);
	}
	if (idx > k)
	{
		return quintetsSort(arr+k, size, idx-k);
	}
	return arr[k];
}




int main()
{
	int n, i, j, counter, idx;
	double temp;
	char ch;

	cout << "Please enter the number of numbers you would like to enter and after that," <<
		" enter the index you would like to find" << endl;
	cin >> n >> i;

	cout << "Please enter the numbers from which you would like to find the index" << endl;
	

	double *arr = new double[n];
	
	counter = idx = 0;
	for(idx = 0; idx < n; idx++)
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

	/*for (idx = 0; idx < n; idx++)
	{
		cout << arr[idx] << endl;
	}*/
	cout << endl;
	
	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);
	insertionSort(arr, n);// Here you put the name of the function you wish to measure
	auto end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program.
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	ofstream myfile("Measure.txt", ios::app); // The name of the file
	myfile << "Time taken by function <name-of-fun> is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();

	/*for (idx = 0; idx < n; idx++)
	{
		cout << arr[idx] << endl;
	}*/
	cout << endl;

	cout<<fixed<< setprecision(4) << arr[i-1] << endl;

//	cout << selection(arr,n, i) << endl;

	cout << fixed << setprecision(4)<< select(CopyArr, 0, n, i) << endl;

	auto start2 = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);
// Here you put the name of the function you wish to measure
	select(arr, 0, n, i);
	auto end2 = chrono::high_resolution_clock::now();
	
		// Calculating total time taken by the program.
		double time_taken2 =
		chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count();
	time_taken2 *= 1e-9;
	ofstream myfile2("Measure.txt",ios::app); // The name of the file
	myfile2 << "Time taken by function <name-of-fun> is : " << fixed
		<< time_taken2 << setprecision(9);
	myfile2 << " sec" << endl;
	myfile2.close();

	double test = quintetsSort(CopyArr2, n, i);
	cout << "---------------" << endl;
	cout << test << endl;

	return 0;
}




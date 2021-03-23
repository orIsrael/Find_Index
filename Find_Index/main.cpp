#include <iostream>
#include "String.h"
using namespace std;

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

	for (idx = 0; idx < n; idx++)
	{
		cout << arr[idx] << endl;
	}
	cout << endl;
	insertionSort(arr, n);

	for (idx = 0; idx < n; idx++)
	{
		cout << arr[idx] << endl;
	}
	cout << endl;

	cout << arr[i-1];

	return 0;
}
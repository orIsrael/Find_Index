#include <iostream>
#include "String.h"
using namespace std;

//bjhghjghjg

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

double selection(double* arr, int size, int i)
{
	return select(arr, 0, size, i);
	
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



	//cout <<setprecision(4)<< arr[i-1];

	cout << arr[i-1] << endl;

	
//	cout << selection(arr,n, i) << endl;

	cout << select(arr, 0, n, i) << endl;

	///זמני ריצה
	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);
	fun();// Here you put the name of the function you wish to measure
	auto end = chrono::high_resolution_clock::now();
	3
		// Calculating total time taken by the program.
		double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	ofstream myfile("Measure.txt"); // The name of the file
	myfile << "Time taken by function <name-of-fun> is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();


>>>>>>> c9dc596b9bb08c90539e2ecd48c3d5234930cb38

	return 0;
}




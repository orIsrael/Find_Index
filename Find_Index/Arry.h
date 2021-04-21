#ifndef Arry

template <class T>
class Arry {
	T* arr;
	int logSize;
	int phisicalSize;

public:
	Arry(int size)
	{
		double* arr = new double[n];
		logSize = phisicalSize = size;
	}

	void bubbleSort(T* arr, int size)
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



};


#endif // !Arry



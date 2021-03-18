#include <iostream>
using namespace std;



int main()
{
	int n, i, j, counter, index;
	cout << "Please enter the number of numbers you would like to enter and after that," <<
		" enter the index you would like to find" << endl;
	cin >> n >> i;

	cout << "Please enter the number" << endl;


	char ch = 0;

	counter = index = 0;
	while (ch != 'e')
	{
		
		counter++;
		cout << "Press 'e' to stop" << endl;
	}

	if (counter < n)
	{
		cout << "wrong input" << endl;
		exit(1);
	}



	return 0;
}
#ifndef STR_H_
#define STR_H_
#include <iostream> 
#include <fstream>
using namespace std;

const int MIN_SIZE = 2;
const int MAX_SIZE = 7;
extern void errorMsg();

class String
{
	char* str;
	int logSize;
	int phisicalSize;

public:
	String() :str(new char[MIN_SIZE]), phisicalSize(MIN_SIZE), logSize(0) {}

	~String()
	{
		delete str;
	}

	void resize()
	{
		char *newStr = new char[phisicalSize *= 2];
		copy(newStr);
		delete str;
		str = newStr;
	}

	void compress()
	{
		char *newStr = new char[logSize + 1];
		copy(newStr);
		delete str;
		str = newStr;
		phisicalSize = logSize;
	}

	operator char*() { return str; }

	friend ostream& operator<<(ostream& os, const String& str)
	{
		int i = 0;
		while (i < str.logSize)
		{
			os << str.str[i];
			i++;
		}
		return os;
	}
	void copy(char* s)
	{
		int i;
		for (i = 0; i < logSize + 1; i++)
			s[i] = str[i];
	}

	void getNum()
	{
		int count = 0;
		char ch = '0';
		bool isNum = ch >= '0' || ch <= '9';
		bool isSecIter = count == 1;
		bool isAfterPoint = false;
		bool isFirstIter = count == 0;
		bool isNegative = isFirstIter && ch == '-';
		bool testMode = true;
		
		
		/*if (testMode)
		{
			ifstream& TestFile();
			TestFile.open("testIndex.text");
			TestFile.get(ch);
		}*/
	/*	else*/
		cin >> ch;

		while (ch != '\n' && ch != ' ')
		{
			if (logSize >= phisicalSize-1)
				resize();
			//vlidation chack
			if (!isNum && ch != '\n' && !isNegative)
				errorMsg();
			
			str[logSize] = ch;
			logSize++;
			if (isAfterPoint)
				count++;
				count++;
		
				cin.get(ch);
			isAfterPoint = ch == '.';
			count++;
		}
		//vlidation chack
		if (isAfterPoint && (count > 3 || count < 1)|| ch == '\n' && count == 0)
			errorMsg();
		compress();
		str[logSize] = '\0';
	}

	const int& getSize() { return logSize;}

};

#endif // !STR

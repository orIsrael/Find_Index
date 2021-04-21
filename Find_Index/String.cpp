#include"String.h"

void String::resize()
{
	char* newStr = new char[phisicalSize *= 2];
	copy(newStr);
	delete str;
	str = newStr;
}

void String::compress()
{
	char* newStr = new char[logSize + 1];
	copy(newStr);
	delete str;
	str = newStr;
	phisicalSize = logSize;
}

ostream& operator<<(ostream& os, const String& str)
{
	int i = 0;
	while (i < str.logSize)
	{
		os << str.str[i];
		i++;
	}
	return os;
}

void String::copy(char* s)
{
	int i;
	for (i = 0; i < logSize + 1; i++)
		s[i] = str[i];
}

void String::getNum()
{
	int count = 0;
	char ch = '0';
	bool isNum = ch >= '0' || ch <= '9';
	bool isSecIter = count == 1;
	bool isAfterPoint = false;
	bool isFirstIter = count == 0;
	bool isNegative = isFirstIter && ch == '-';
	bool testMode = true;

	cin >> ch;

	while (ch != '\n' && ch != ' ')
	{
		if (logSize >= phisicalSize - 1)
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
	if (isAfterPoint && (count > 3 || count < 1) || ch == '\n' && count == 0)
		errorMsg();
	compress();
	str[logSize] = '\0';
}
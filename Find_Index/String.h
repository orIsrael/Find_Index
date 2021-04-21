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
	~String(){delete str;}
	void resize();
	void compress();
	operator char* () { return str; }
	friend ostream& operator<<(ostream& os, const String& str);
	void copy(char* s);
	void getNum();
	const int& getSize() { return logSize; }
};

#endif // !STR
#pragma once
#include <iostream>

using namespace std;

class StringBad
{
private:
	char* str;					// 문자열을 지시하는 포인터
	int len;					// 문자열의 길이
	static int num_strings;		// 객체의 수


public:
	// constructor
	StringBad();
	StringBad(const char* s);
	StringBad(const StringBad& copy);
	~StringBad();


	static void printString();



	// operator overloading
	friend ostream& operator<< (ostream& os, const StringBad& st);
	StringBad& operator= (const StringBad& st);
	char& operator[] (int i);
};


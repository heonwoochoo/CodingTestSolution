#pragma once
#include <iostream>

using namespace std;

class StringBad
{
private:
	char* str;					// ���ڿ��� �����ϴ� ������
	int len;					// ���ڿ��� ����
	static int num_strings;		// ��ü�� ��


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


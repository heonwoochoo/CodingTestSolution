#include "StringBad.h"
#include <cstring>

int StringBad::num_strings = 0;

StringBad::StringBad()
{
	len = 4;
	str = new char[4];
	strcpy_s(str, len, "C++");
	num_strings++;
	cout << num_strings << ":" << str << " ����Ʈ ��ü ����\n";
	
}

StringBad::StringBad(const char* s)
{
	len = strlen(s);
	str = new char[len + 1];
	strcpy_s(str, len + 1, s);
	num_strings++;
	cout << num_strings << ":" << str << " ��ü ����\n";
}

StringBad::StringBad(const StringBad& copy)
{
	len = strlen(copy.str);
	if (str != nullptr) str = nullptr;
	str = new char[len + 1];
	strcpy_s(str, len + 1, copy.str);
	num_strings++;
	cout << num_strings << ":" << str << " ���� ������ ��ü ����\n";
}

StringBad::~StringBad()
{
	cout << str << " ��ü �ı�, ";
	--num_strings;
	cout << "���� ��ü ��: " << num_strings << "\n";
	delete[] str;
}

void StringBad::printString()
{
	// static���� ����� �Լ��̹Ƿ� static member �������� ���� �����ϴ�.
	// cout << str << endl;  (�Ұ���)
	cout << num_strings << endl;
}

StringBad& StringBad::operator=(const StringBad& st)
{
	if (this == &st) return *this;
	len = st.len;
	delete[] str;
	this->str = new char[len + 1];
	strcpy_s(str, len + 1, st.str);
	return *this;
}

char& StringBad::operator[](int i)
{
	return *(str + i);
	// TODO: insert return statement here
}

ostream& operator<<(ostream& os, const StringBad& st)
{
	os << st.str;
	return os;
	// TODO: insert return statement here
}

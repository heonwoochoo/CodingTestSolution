#include "StringBad.h"
#include <cstring>

int StringBad::num_strings = 0;

StringBad::StringBad()
{
	len = 4;
	str = new char[4];
	strcpy_s(str, len, "C++");
	num_strings++;
	cout << num_strings << ":" << str << " 디폴트 객체 생성\n";
	
}

StringBad::StringBad(const char* s)
{
	len = strlen(s);
	str = new char[len + 1];
	strcpy_s(str, len + 1, s);
	num_strings++;
	cout << num_strings << ":" << str << " 객체 생성\n";
}

StringBad::StringBad(const StringBad& copy)
{
	len = strlen(copy.str);
	if (str != nullptr) str = nullptr;
	str = new char[len + 1];
	strcpy_s(str, len + 1, copy.str);
	num_strings++;
	cout << num_strings << ":" << str << " 복사 생성자 객체 생성\n";
}

StringBad::~StringBad()
{
	cout << str << " 객체 파괴, ";
	--num_strings;
	cout << "남은 객체 수: " << num_strings << "\n";
	delete[] str;
}

void StringBad::printString()
{
	// static으로 선언된 함수이므로 static member 변수에만 접근 가능하다.
	// cout << str << endl;  (불가능)
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

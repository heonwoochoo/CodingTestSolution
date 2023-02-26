#include "TableTennisPlayer.h"
#include <iostream>

A::A()
	: m_num(0)
{
	cout << "A default 생성자 호출\n";
}

A::A(int num)
	:m_num(num)
{
	cout << "A(num) 생성자 호출\n";
}

A::~A()
{
	cout << "A 소멸자 호출\n";
}

void A::printHello()
{
	cout << "A : Hello\n";
}

B::B()
{
	cout << "B default 생성자 호출\n";
}

B::B(int num)
	:A(num)
{
}

B::~B()
{
	cout << "B 소멸자 호출\n";
}

void B::printHello()
{
	cout << "B : Hello\n";
}

C::C()
{
	cout << "C default 생성자 호출\n";
}

C::C(int num)
	:A(num)
{
}

C::~C()
{
	cout << "C 소멸자 호출\n";
}

void C::printHello()
{
	cout << "C : Hello\n";
}

D::D()
{
	cout << "D default 생성자 호출\n";
}

D::D(int num)
	: B(num), C(num), A(num)
{
}

D::~D()
{
	cout << "D 소멸자 호출\n";
}

void D::printHello()
{
	B::printHello();
	C::printHello();
}

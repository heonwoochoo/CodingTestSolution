#include "TableTennisPlayer.h"
#include <iostream>

A::A()
	: m_num(0)
{
	cout << "A default ������ ȣ��\n";
}

A::A(int num)
	:m_num(num)
{
	cout << "A(num) ������ ȣ��\n";
}

A::~A()
{
	cout << "A �Ҹ��� ȣ��\n";
}

void A::printHello()
{
	cout << "A : Hello\n";
}

B::B()
{
	cout << "B default ������ ȣ��\n";
}

B::B(int num)
	:A(num)
{
}

B::~B()
{
	cout << "B �Ҹ��� ȣ��\n";
}

void B::printHello()
{
	cout << "B : Hello\n";
}

C::C()
{
	cout << "C default ������ ȣ��\n";
}

C::C(int num)
	:A(num)
{
}

C::~C()
{
	cout << "C �Ҹ��� ȣ��\n";
}

void C::printHello()
{
	cout << "C : Hello\n";
}

D::D()
{
	cout << "D default ������ ȣ��\n";
}

D::D(int num)
	: B(num), C(num), A(num)
{
}

D::~D()
{
	cout << "D �Ҹ��� ȣ��\n";
}

void D::printHello()
{
	B::printHello();
	C::printHello();
}

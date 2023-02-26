#pragma once
#include <string>

using namespace std;

class A
{
public:
	A();
	A(int num);
	virtual ~A();
	virtual void printHello();

private:
	int m_num;
};

class B : virtual public A
{
public:
	B();
	B(int num);
	~B();
	virtual void printHello() override;
};

class C : virtual public A
{
public:
	C();
	C(int num);
	~C();
	virtual void printHello() override;
};

class D : public B, public C
{
public:
	D();
	D(int num);
	~D();
	virtual void printHello() override;
};
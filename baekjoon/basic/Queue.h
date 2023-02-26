#pragma once


class Customer
{
private:
	long arrive;			// ���� ť�� ������ �ð�
	int processtime;		// ���� �ŷ��� ó���ϴ� �ð�

public:
	Customer() { arrive = processtime = 0; }
	void set(long when);
	long when() const { return arrive; }
	int ptime() const { return processtime; }
};

typedef Customer Item;

class Queue
{
private:
	struct Node
	{
		Item item;
		Node* next;
	};

	enum { Q_SIZE = 10 };

	Node* front;			// Queue�� �Ӹ��� �����ϴ� ������
	Node* rear;				// Queue�� ������ �����ϴ� ������
	int items;				// Queue�� �ִ� ���� �׸��
	const int qsize;		// Queue�� ���� �� �ִ� �ִ� �׸� ��

	// ���� ������
	Queue(const Queue& q) : qsize(0) {}
	Queue& operator=(const Queue& q) { return *this; }

public:
	Queue(int qs = Q_SIZE);	// qs �Ѱ踦 ���� ť�� ����
	~Queue();

	bool isEmpty() const;
	bool isFull() const;
	int queueCount() const;
	bool enQueue(const Item& item);		// �׸��� ������ �߰�
	bool deQueue(Item& item);			// �Ӹ����� �׸��� ����

};
#include "Queue.h"
#include <cstdlib>



Queue::Queue(int qs)
	: qsize(qs)
{
	front = rear = nullptr;
	items = 0;
}

Queue::~Queue()
{
	Node* temp;
	while (front != nullptr)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

bool Queue::isEmpty() const
{
	return items == 0;
}

bool Queue::isFull() const
{
	return items == qsize;
}

int Queue::queueCount() const
{
	return items;
}

bool Queue::enQueue(const Item& item)
{
	if (isFull()) return false;

	Node* add = new Node;						// ��带 �����Ѵ�
	add->item = item;							// ��� �����͸� �����Ѵ�
	add->next = nullptr;						
	items++;
	if (front == nullptr) front = add;			// ť�� ��������� ��ó���� ����Ű�� ������ ������ �ִ´�
	else rear->next = add;						// ť�� ��������� �ǳ��� ����Ű�� ������ ������ �ִ´�
	rear = add;									// rear�� ����带 �����Ѵ� -> enQueue�� ȣ��� ������ rear���� ���ε��� Node�� �ٲ�
	return true;
}

bool Queue::deQueue(Item& item)
{
	if (front == nullptr) return false;

	item = front->item;
	items--;
	Node* temp = front;
	front = front->next;
	delete temp;
	if (items == 0) rear = nullptr;

	return true;
}

void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
}
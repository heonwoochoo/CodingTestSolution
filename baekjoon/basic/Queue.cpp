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

	Node* add = new Node;						// 노드를 생성한다
	add->item = item;							// 노드 포인터를 설정한다
	add->next = nullptr;						
	items++;
	if (front == nullptr) front = add;			// 큐가 비어있으면 맨처음을 가리키는 포인터 변수에 넣는다
	else rear->next = add;						// 큐에 들어있으면 맨끝을 가리키는 포인터 변수에 넣는다
	rear = add;									// rear는 새노드를 지시한다 -> enQueue가 호출될 때마다 rear값이 새로들어온 Node로 바뀜
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
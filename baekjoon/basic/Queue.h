#pragma once


class Customer
{
private:
	long arrive;			// 고객이 큐에 도착한 시간
	int processtime;		// 고객의 거래를 처리하는 시간

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

	Node* front;			// Queue의 머리를 지시하는 포인터
	Node* rear;				// Queue의 꼬리를 지시하는 포인터
	int items;				// Queue에 있는 현재 항목수
	const int qsize;		// Queue에 넣을 수 있는 최대 항목 수

	// 복사 방지용
	Queue(const Queue& q) : qsize(0) {}
	Queue& operator=(const Queue& q) { return *this; }

public:
	Queue(int qs = Q_SIZE);	// qs 한계를 가진 큐를 생성
	~Queue();

	bool isEmpty() const;
	bool isFull() const;
	int queueCount() const;
	bool enQueue(const Item& item);		// 항목을 꼬리에 추가
	bool deQueue(Item& item);			// 머리에서 항목을 삭제

};
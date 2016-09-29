#include "stdafx.h"
#include <iostream>
using namespace std;

struct Node
{
	int x, y;
};

typedef Node* pNode;

class Queue
{
public:
	Queue(int QueueCapacity)
	{
		m_QueueCapacity = QueueCapacity;
		p_Queue = new Node[m_QueueCapacity];
		clearQueue();
	}
	~Queue()
	{
		delete[] p_Queue;
	}

	void clearQueue()
	{
		m_ElemCount = 0;
		head = 0;
		tail = 0;
	}

	bool QueueEmpty()
	{
		if (m_ElemCount == 0)
		{
			return true;
		}
		return false;
	}

	bool QueueFull()
	{
		if (m_ElemCount == m_QueueCapacity)
		{
			return true;
		}
		return false;
	}

	bool EnQueue(int Element_x, int Element_y)
	{
		if (QueueFull())
		{
			cout << "queue is full" << endl;
			return false;
		}
		p_Queue[tail].x = Element_x;
		p_Queue[tail].y = Element_y;

		tail++;
		tail = tail%m_QueueCapacity;
		m_ElemCount++;
		cout << "insert Done" << endl;
		return true;
	}

	bool DeQueue(pNode Element)
	{
		if (QueueEmpty())
		{
			cout << "queue is empty" << endl;
			return false;
		}
		Element = &p_Queue[head];
		head++;
		head = head%m_QueueCapacity;
		m_ElemCount--;
		cout << "DeQueue" << endl;
		return true;
	}

	void QueueTravel()
	{
		cout << endl;
		for (int i = head; i < m_QueueCapacity + tail; i++)
		{
			cout << "Element:" << p_Queue[i%m_QueueCapacity].x << "," << p_Queue[i%m_QueueCapacity].y << endl;
		}


		cout << endl << "head:" << head << endl;
		cout << "tail:" << tail << endl;
		cout << "elememt count:" << m_ElemCount << endl;
	}


private:
	pNode p_Queue;
	int head;
	int tail;
	int m_QueueCapacity;
	int m_ElemCount;
};



int main()
{
	pNode a = nullptr;
	int x = 0, y = 0;
	Queue p(5);
	p.EnQueue(1, 1);
	p.EnQueue(2, 2);
	p.EnQueue(3, 3);
	p.EnQueue(4, 4);
	p.EnQueue(5, 5);

	x = 5;
	y = 5;

	while (true)
	{
		system("pause");
		p.QueueTravel();
		p.DeQueue(a);
		x++;
		y++;
		p.EnQueue(x, y);
	}

	return 0;
}
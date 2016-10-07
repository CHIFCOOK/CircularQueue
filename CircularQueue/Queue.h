#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Queue
{
public:
	Queue(int QueueCapacity);
	~Queue();
	void clearQueue();
	bool QueueEmpty();
	bool QueueFull();
	bool EnQueue(T Element);
	bool DeQueue(T * Element);
	void QueueTravel();

private:
	T* p_Queue;
	int head;
	int tail;
	int m_QueueCapacity;
	int m_ElemCount;
};


//º¯Êý¶¨Òå
template<typename T>
inline Queue<T>::Queue(int QueueCapacity)
{
	m_QueueCapacity = QueueCapacity;
	p_Queue = new T[m_QueueCapacity];
	clearQueue();
}

template<typename T>
inline Queue<T>::~Queue()
{
	delete[] p_Queue;
}

template<typename T>
inline void Queue<T>::clearQueue()
{
	m_ElemCount = 0;
	head = 0;
	tail = 0;
}

template<typename T>
inline bool Queue<T>::QueueEmpty()
{
	return (m_ElemCount == 0) ? true : false;
}

template<typename T>
inline bool Queue<T>::QueueFull()
{
	return (m_ElemCount == m_QueueCapacity) ? true : false;
}

template<typename T>
inline bool Queue<T>::EnQueue(T Element)
{
	if (QueueFull())
	{
		cout << "queue is full" << endl;
		return false;
	}
	p_Queue[tail] = Element;

	tail++;
	tail = tail%m_QueueCapacity;
	m_ElemCount++;
	cout << "insert Done" << endl;
	return true;
}

template<typename T>
inline bool Queue<T>::DeQueue(T * Element)
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

template<typename T>
inline void Queue<T>::QueueTravel()
{
	cout << endl;
	for (int i = head; i < m_QueueCapacity + tail; i++)
	{
		cout << p_Queue[i] << endl;
	}


	cout << endl << "head:" << head << endl;
	cout << "tail:" << tail << endl;
	cout << "elememt count:" << m_ElemCount << endl;
}

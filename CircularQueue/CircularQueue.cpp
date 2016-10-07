#include "stdafx.h"
#include "queue.h"

int main()
{
	int a;
	Queue<int> s(5);
	s.EnQueue(1);
	s.EnQueue(2);
	s.EnQueue(3);
	s.EnQueue(4);
	s.EnQueue(5);
	s.DeQueue(&a);

	s.QueueTravel();
	system("pause");
	return 0;
}
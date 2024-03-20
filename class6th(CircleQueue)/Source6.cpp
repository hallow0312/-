#include<iostream>

using namespace std;
template <typename T>
#define SIZE 4
#pragma region 원형 큐
//물리적으로는 선형 구조를 가지고 있으며,
// 큐의 시작점과 끝점을 연결한 Queue
class CircleQueue
{
private:
	int front;
	int rear;
	T buffer[SIZE];


public:
	CircleQueue()
	{
		front = SIZE - 1;
		rear = SIZE - 1;
		for (int i = 0; i < SIZE; i++)
		{
			buffer[i] = NULL;
		}


	}
	~CircleQueue()
	{

	}


	void Push(T data)
	{

		if (IsFull())
		{
			cout << "Queue is full" << endl;
		}
		else
		{

			rear = (rear + 1) % SIZE;
			buffer[rear] = data;

		}


	}
	void Pop()
	{

		if (Empty())
		{
			cout << endl << "Release Arr" << endl;

		}
		else
		{
			front = (front + 1) % SIZE;
			buffer[front] = NULL;


		}
	}



	bool IsFull()
	{
		if (front == (rear + 1) % SIZE)
		{
			return true;

		}
		else
		{
			return false;
		}
	}
	bool Empty()
	{
		if (front == rear)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	T& Front()
	{

		return buffer[(front + 1) % SIZE];



	}




};















#pragma endregion



int main()
{
	CircleQueue <char> circlequeue;

	circlequeue.Push('a');
	circlequeue.Push('b');
	circlequeue.Push('c');
	circlequeue.Push('d');
	while (circlequeue.Empty() == false)
	{
		cout << circlequeue.Front() << endl;
		circlequeue.Pop();

	}
	circlequeue.Push('a');
	circlequeue.Push('b');
	circlequeue.Push('c');

	while (circlequeue.Empty() == false)
	{
		cout << circlequeue.Front() << endl;
		circlequeue.Pop();

	}



















	return 0;
}


















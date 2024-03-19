#include<iostream>

using namespace std;
template <typename T>
#define SIZE 5
class Queue
{
private:

	T front;
	T rear;
	int size;
	T QueueArr[5] = { 0 };

public:
	Queue()
	{
		for (int i = 0; i < SIZE; i++)
		{
			QueueArr[i] = NULL;
		}
		front = 0;
		rear = 0;
		size = 0;

	}
	~Queue()
	{

		cout << endl << "Release Queue" << endl;
	}
	void Push(T data)
	{

		if (IsFull())
		{
			cout << "Queue is Full" << endl;


		}
		else
		{
			QueueArr[rear] = data;
			rear++;
			size++;
		}


	}







	void Pop()
	{
		cout << "Remaining Arr : " << size << endl;
		if (Empty())
		{
			cout << "Release Arr" << endl;

		}
		else
		{
			QueueArr[front] = NULL;
			front++;
			size--;
		}
	}
	bool IsFull()
	{
		if (SIZE <= rear)
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
		if (Empty())
		{
			exit(1);
		}
		else
		{

			return QueueArr[front];
		}
	}
	int& Size()				// '&' 사용해주면서 복사되는 비용을 안쓰게됌. 반환되는 값 size가 같이 들어가게됌 
	{						// 기존의 int Size는 return 하면서 size 값을 복사하여 반환하기 때문에 복사비용이 생김.
		return size;
	}



};


int main()
{
#pragma region 선형구조 Queue
	// 배열의 공간에 들어간 데이터가 고정되어 
	// 데이터를 빼내더라도 초기화하지 않으며,
	// 원래 데이터가 있던 배열의 자리에 더이상 다른 값이 
	// 들어올 수 없는 Queue.

	Queue <int>queue;
	queue.Push(10);
	queue.Push(20);
	queue.Push(30);
	queue.Push(40);
	queue.Push(50);



	cout << "Queue.Size : " << queue.Size() << endl;
	while (queue.Empty() == false)
	{
		cout << queue.Front() << endl;
		queue.Pop();
	}



#pragma endregion


	return 0;
}


















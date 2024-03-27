#include <iostream>
using namespace std;

#define Max_Size 8
template <typename T>
class Heap
{
private:
	int index;
	T buffer[Max_Size];


public:
	Heap()
	{
		index = 0;

		for (int i = 0; i < Max_Size; i++)
		{
			buffer[i] = NULL;
		}
	}
	void Insert(int data)
	{
		if (index >= Max_Size - 1)
		{
			cout << "Heap is Full" << endl;
			return;
		}
		buffer[++index] = data;


		int child = index;
		int parent = index / 2;
		while (child > 1 && buffer[child] > buffer[parent])
		{
			/*
			자식 노드와 부모 노드의 데이터를 비교 (&& 연산자를 안쓸거면)
			if(buffer[parent]<buffer[child])
			{
				swap(buffer[parent,buffer[child])
			}

			*/
			swap(buffer[child], buffer[parent]);

			child = child / 2;

			parent = child / 2;
		}

	}
	T& Delete()
	{
		//1. Heap 이 비어 있더만 프로그램 종료 
		if (index <= 0)
		{
			cout << "Heap is empty" << endl;
			exit(1);
		}

		// 임시 변수에 buffer[1] 보관
		T result = buffer[1];

		buffer[1] = buffer[index];

		buffer[index--] = NULL;

		int parent = 1;

		int child = parent * 2;

		while (parent * 2 <= index)
		{
			if (buffer[child] < buffer[child + 1])
			{
				++child;
			}


			if (buffer[parent] < buffer[child])
			{
				swap(buffer[parent], buffer[child]);
			}
			else
			{
				break;
			}
			parent = child;
			child = parent * 2;


		}
		return result;


		//2.index 로 가리키는 배열의 값을 첫번 째로 원소에 넣어줌
		//index로 가리키는 배열의 값 초기화
		// index  감소 
	}


	void Show()
	{
		for (T element : buffer)
		{


			cout << element << " ";


		}

	}








};

int main()
{

#pragma region heap
	//가장 큰값이 꼭대기에 
	// 부모노드의 key 값이 자식노드의 key값보다 커야함
	// 완전 이진 트리 
	// 데이터 삽입이나 삭제가능 하나 완전이진트리가 유지가 되어야함 .
	// 데이터를 뽑을 때 상수값이 들기에 시간 효율 좋음 

	//왼쪽 자식의 인덱스 = 부모노드의 인덱스 *2;
	//오른쪽 자식의 인덱스 = 부모노드의 인덱스 *2+1;
	//부모의 인덱스 = 자식의 인덱스 /2;
	Heap <int> heap;
	heap.Insert(10);
	heap.Insert(20);
	heap.Insert(30);
	heap.Insert(40);
	heap.Insert(50);



	for (int i = 0; i < 5; i++)
	{
		heap.Show();

		cout << heap.Delete() << endl;

	}



#pragma endregion


	return 0;
}
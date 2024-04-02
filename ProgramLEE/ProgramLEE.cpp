#include<iostream>
using namespace std;
#define SIZE 10

template <typename T>
class AdjacencyList
{
private:
	struct Node
	{
		Node* next;
		T data;
		Node(T data, Node* link = NULL)
		{
			this->data = data;
			next = link;
		}
	};
	int size; // 정점의 개수 
	T vertex[SIZE]; // 정점의 집합
	Node* graphList[SIZE]; //인접 리스트

public:
	AdjacencyList()
	{
		size = 0;
		for (int i = 0; i < SIZE; i++)
		{
			vertex[i] = NULL;
			graphList = NULL;
		}
	}
	void Insert(T data)
	{	
		if (size > SIZE)
		{
			cout << "Adjacency List if Full" << endl;
			return;
		}
		vertex[size++] = data;
	}
	

	void Insert(int u, int v)
	{
		if (size <= 0)
		{
			cout << "Adjacency List is empty" << endl;
			return;
		}
		if (u > size || v > size)
		{
			cout << "Out of range" << endl;
			return;
		}
		graphList[u] = new Node(data,graphlist[u]);
		graphList[v] = new Node(data,graphList[v]);
	}
	

};

int main()
{
	
#pragma region 인접 리스트 (Adjacency List)

	// 그래프의 각 정점에 인접한 정점들을 연결 리스트 
	// 로 표현하는 방법.

	//장점 
	// 그래프의 모든 간선의 수를 o(V+E) 로 표현 가능

	//단점
	// 두 정점을 연결하는 간선을 조회하거나 정점의 차수를 알기 
	// 위해서 정점의 인접 리스트를 모두 탐색 해야 하므로 ,
	// 정점의 차수만큼의 시간이 필요함.
#pragma endregion


	return 0;
}
#include<iostream>
using namespace std;

#define SIZE 10

template <typename T>
class AdjacencyMatrix
{
private:

	int Matrix[SIZE][SIZE]; //인접 행렬
	int size; //정점의 개수
	T buffer[SIZE]; //정점의 집합
public:
	AdjacencyMatrix()
	{
		size = 0;
		for (int i = 0; i < SIZE; i++)
		{
			buffer[i] = NULL;
			for (int j = 0; j < SIZE; j++)
			{
				Matrix[j][i] = NULL;
			}
		}


	}
	void Insert(T data)
	{
		if (size >= SIZE)
		{
			cout << "Ajcacency Matrix is Full" << endl;
			return;
		}
		buffer[size++] = data;
	}
	void Insert(int i, int j, int value = 1)
	{
		if (size <= 0)
		{
			cout << "Empty Vertix" << endl;
			return;
		}
		if (i >= size || j >= size)
		{
			cout << "Out of Range" << endl;
			return;

		}
		Matrix[i][j] = value;
		Matrix[j][i] = value;
	}
	void Show()
	{
		cout << "   ";
		for (int i = 0; i < size; i++)
		{
			cout << buffer[i] << "  ";
		}

		cout << endl;
		for (int i = 0; i < size; i++)
		{
			cout << buffer[i] << "  ";
			for (int j = 0; j < size; j++)
			{
				cout << Matrix[i][j] << "  ";
			}
			cout << endl;
		}



	}
};
int main()
{
#pragma region 그래프

	// 요소들이 서로 복잡하게 연결되어 있는 관계를 
	// 표현하는 자료구조이며, 정점과 간선들의 집합으로 구성되어 있다 .

	// 정점(Vertex) : 노드(Node) 데이터가 저장되는 그래프의 기본 원소 .

	// 간선 (Edge) : 노드를 연결하는 선

	// 연결 정점(Adjacent Vertex) : 간선으로 직접 연결된 정점.

	// 차수 (Degree)
	// 정점에 연결된 간선의 수를 의미 ;

	//경로(Path)
	// 정점들을 연결하는 간선들의 순서 

	//1. 무방향 그래프 (Undirected Graph)
	// 간선에 방향이 없는 그래프 

	//2. 방향 그래프 (Directed Graph)
	// 간선에 방향이 있는 그래프 

	//3. 가중치 그래프 (Weighted Graph)
	// 간선에 가중치가 있는 그래프 


#pragma endregion

#pragma region 인접행렬(Adjacency Materix)

	// 인접 행렬 (Adjacency Materix)
	// 정점들 간의 연결 관계를 이차원 배열로 표현하는 방식.
	// 정점의 개수가 v일 때 , V x V 크기의 이차원 배열 사용

	//장점
	//1. 두 정점이 연결되어 있는지 확인하기 쉬움
	//2. 두 정점 사이의 간선의 가중치를 쉽게 확인가능 

	//단점
	//1. 정점의 개수가 많을 떄 메모리 낭비가 심함.
	//2. 특정 정점과 연결된 정점을 찾을 때 시간이 오래 걸림 .

	AdjacencyMatrix <char> matrix;

	matrix.Insert('A');
	matrix.Insert('B');
	matrix.Insert('C');
	matrix.Insert('D');
	matrix.Insert(1, 3);
	matrix.Show();


#pragma endregion


	return 0;
}
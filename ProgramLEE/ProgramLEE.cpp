#include<iostream>


using namespace std;
#define SIZE 6
template<typename KEY,typename VALUE>
class HashTable
{
private:
	struct Node
	{
		KEY key;
		VALUE value;
		Node* next;
		
	};

	struct Bucket
	{ 
		int count;
		//버킷 구조체 배열 생성 
		Node* head;

	};
	
Bucket bucket[SIZE];   

public:

	HashTable()
	{
		for (int i = 0; i < SIZE; i++)
		{
			bucket[i].count = 0; 
			bucket[i].head = nullptr; 
		}

	}

	template<typename T>
	int HashFunction(T key)
	{
		int HashIndex = (int)key % SIZE; 

		return HashIndex; 

	}
	
	template<>
	int HashFunction(string key)  //bucket 의 index를 결정하는 함수 ;
	{
		int result = 0;

		for (const char &element :key)
		{
			result += (int)element;
		}

		int HashIndex = (int)result % SIZE;
		return HashIndex;

	}

	Node* CreateNode(KEY key,VALUE value)     //노드를 반환해줄 함수 
	{
		Node* newNode = new Node;
		newNode->key = key;
		newNode->value = value;
		newNode->next = nullptr;

		return newNode; 
	}

	void Insert(KEY key, VALUE value) //bucket에 input 해줄 함수 
		
	{	//Hash 함수를 통해서 hash index 구하기 
		int index = HashFunction(key);  

		//2. 새로운 노드 
		Node* newNode = CreateNode(key, value);

		// 기존에 노드가 1개라도 존재하지 않으면;
		if (bucket[index].count == 0)
		{	
			//bucket[index]의 head 포인터에 새로운 노드 저장 
			bucket[index].head = newNode;
			//4. bucket[Index]의 count 값 ++
			bucket[index].count++;
		}
		else // 기존에 노드 1개 이상 존재한다면 
		{
			//1. newNode 의 next에 bucket[index]의 head 값(가장 최근의 노드 주소) 가리키게함.
			newNode->next = bucket[index].head; 
			//2. bucket[index].head에 새로 생성한 노드 주소 
			bucket[index].head = newNode;
			//3. bucket[index] 값 증가
			bucket[index].count++;
		}
	}

	void Show()
	{	
		
		for (int i = 0; i < SIZE; i++) 
		{	
			Node* currentNode = bucket[i].head;  
			while (currentNode != nullptr) 
			{	
				cout << "[" << currentNode->key <<"," << currentNode->value << "] "; 
				currentNode = currentNode->next; 

			}
			cout << endl;
		}
	}

	void Release(KEY key)
	{
		
		int index = HashFunction(key);
		
		Node* traceNode= bucket[index].head;;
		Node* currentNode=bucket[index].head;
		
		for (int i = 0; i < bucket[index].count; i++)
		{
			if (currentNode->key == key)
			{
				if (currentNode->next)
				{
					traceNode->next = currentNode->next;
					delete(currentNode);
					break;
				}
				else
				{
					traceNode->next = nullptr;
					delete(currentNode);
					break;
				}
			}
			else
			{
				traceNode = currentNode;
				currentNode = currentNode->next;
			}
		}

	}
};


int main()
{

#pragma region 해시 테이블 
	// (key , Value) 로 데이터를 저장하는 자료 구조 중 하나로 
	// 빠르게 데이터를 검색 할 수 있는 자료구조 ;

	// 해시 충돌을 해결 하는 방법
	// 
	// <체이닝 기법>
	// 각 해시 버킷을 연결리스트로 구성하는 방식
	
	// 해시 충돌 발생 시 동일한 해시 값에 해당하는 데이터들을 
	// 연결리스트로 연결하여 저장 .

	// <개방 주소법>
	// 충돌 발생 시 빈 버켓에 데이터를 저장하는 방식.

	// 빈 버킷을 어떻게 결정할 지에 따라 구현 방식이 달라짐.

	// 선형 탐사 : 충돌 발생 시 앞에서 부터 차례대로 빈 버킷을
	// 찾아 저장하는 방식 .
	
	// 이차 탐사 : 충돌 발생시 2^, 2^3 만큼 떨어진 빈 버킷을 찾아 
	// 값을 저장하는 방식 .

	// 이중 해싱 : 해시 값을 한번 더 해시 함수에서 다른함수를 
	// 도출하는 방식임.

	HashTable <int ,string> hashtable;
	
	hashtable.Insert(0, "soccer");
	hashtable.Insert(1, "Basketball");
	hashtable.Insert(2, "Tennis");
	hashtable.Insert(3, "Swimming");
	hashtable.Insert(4, "Baseball");
	hashtable.Insert(5, "Skate");
	hashtable.Insert(6, "Skeleton");


	hashtable.Release(3);
	hashtable.Show();
	

#pragma endregion


	return 0; 
}
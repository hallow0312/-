#include<iostream>


using namespace std;
#define SIZE 6
template<typename KEY, typename VALUE>
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
	~HashTable()
	{

		for (int i = 0; i < SIZE; i++)
		{
			Node* deleteNode = bucket[i].head;
			Node* nextNode = bucket[i].head;

			if (bucket[i].head == nullptr)
			{
				continue;
			}
			else
			{
				while (nextNode != nullptr)
				{
					if (nextNode != nullptr)
					{
						break;
					}

					nextNode = deleteNode->next;
					delete deleteNode;
					deleteNode = nextNode;
				}
			}
			cout << "Release bucket[" << i << "]" << endl;
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

		for (const char& element : key)
		{
			result += (int)element;
		}

		int HashIndex = (int)result % SIZE;
		return HashIndex;

	}

	Node* CreateNode(KEY key, VALUE value)     //노드를 반환해줄 함수 
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
				cout << "[" << currentNode->key << "," << currentNode->value << "] ";
				currentNode = currentNode->next;

			}
			cout << endl;
		}
	}

	void Release(KEY key)
	{
		//Hash 함수를 통해서 값을 받는 임시변수 필요
		int index = HashFunction(key);

		//2. 노드를 탐색할 수 있는 순회형 포인터 변수 선언 ;

		Node* currentNode = bucket[index].head;
		Node* traceNode = nullptr;
		//currentNode 가 nullptr이라고 한다면 함수 종료 
		if (currentNode == nullptr)
		{
			cout << "Not Key Found" << endl;
			return;
		}
		//5. currentNode를 이용해서 내가 찾고자 하는 key 값 찾기 
		while (currentNode != nullptr)
		{
			// currentNode-> key 값과 내가 삭제하고 싶은 key 값이 같다면 
			if (currentNode->key == key)
			{
				// 내가 삭제하고자 하는 key 가 head애 있는 노드라면 
				if (currentNode == bucket[index].head)
				{
					bucket[index].head = currentNode->next;

				}
				else
				{
					traceNode->next = currentNode->next;
				}



				//bucket count 감소 
				bucket[index].count--;
				//해당 메모리 삭제 
				delete currentNode;
				return;
			}

			traceNode = currentNode;
			currentNode = currentNode->next;

		}
		cout << "Not Key Found" << endl;

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

	HashTable <int, string> hashtable;

	hashtable.Insert(0, "soccer");
	hashtable.Insert(12, "Basketball");
	hashtable.Insert(21, "Tennis");
	hashtable.Insert(374, "Swimming");
	hashtable.Insert(45, "Baseball");
	hashtable.Insert(56, "Skate");
	hashtable.Insert(67, "Skeleton");

	hashtable.Show();
	hashtable.Release(374);
	hashtable.Show();


#pragma endregion


	return 0;
}
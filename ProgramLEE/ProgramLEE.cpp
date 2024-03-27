#include<iostream>

using namespace std;
#define SIZE 6
template<typename KEY,typename Value>
class HashTable
{
private:
	struct Node
	{
		KEY key;
		Value value;
		Node* next;
		
	};
	struct Bucket
	{
		int count;
		//버킷 구조체 배열 생성 
		Bucket* head;

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
	
	int HashFunction(string key) 
	{
		int HashIndex = 0;

		for (int i = 0; i < key.length(); i++)
		{
			HashIndex += (int)key[i];
		}

		HashIndex = (int)HashIndex % SIZE;
		return HashIndex;

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




#pragma endregion


	return 0; 
}
#include<iostream>

using namespace std;
template <typename T>
class DoubleLinkedList
{
private:
	struct Node
	{
		T data;
		Node* next;
		Node* prev;
	};
	Node* head;
	Node* tail;
	int size;
public:
	DoubleLinkedList()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	void PushBack(T data)
	{
		Node* newNode = new Node; 
		newNode->data = data; 
		newNode->prev = nullptr; 
		newNode->next = nullptr;

		if (head == nullptr && tail == nullptr) 
		{
			head = newNode;  
			tail = newNode;  
		}  
		else
		{	
			newNode->prev = tail;
			tail->next = newNode;  
			tail = newNode; 
			
			
		} ;
		size++;
	}
	void PushFront(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;
		newNode->prev = nullptr;
		if (head == nullptr && tail == nullptr)
		{
			head = newNode; 
			tail = newNode; 
		}
		else
		{
			newNode->next = head;
			head->prev = newNode; 
			head = newNode; 
		}
		size++;
	}
	void PopFront()
	{
		cout << "Remaining Node : " << size << endl;
		if (head == nullptr && tail == nullptr)
		{
			cout << "List is empty";
			return;
		}
		
		Node* deleteNode = nullptr;
		
		
		if (size == 0)
		{
		
			deleteNode = head;
			head = nullptr;
			tail = nullptr;
			delete deleteNode;
		
		}
		else
		{
			deleteNode = head;  
			head = deleteNode->next;  
			
			delete deleteNode; 

		}
		
		
	}
};

int main()
{
	


	return 0;
}






	
	


	


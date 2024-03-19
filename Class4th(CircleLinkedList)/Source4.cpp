#include<iostream>

using namespace std;
template <typename T>
class CircleLinkedList
{
private:
	struct Node
	{
		T data;
		Node* next;
	};
	int size;
	Node* head;
public:
	CircleLinkedList()
	{
		cout << endl << "*****Create Node*****" << endl;
		size = 0;
		head = nullptr;
	}
	~CircleLinkedList()
	{
		while (size != 0)
		{
			PopFront();

		}
		cout << endl << "*****Release Node*****" << endl;

	}
	void PushFront(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;
		if (head == nullptr)
		{
			head = newNode;
			newNode->next = head;
			head->next = newNode;
		}
		else
		{
			newNode->next = head->next;
			head->next = newNode;

		}
		size++;

	}
	void PushBack(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;
		if (head == nullptr)
		{
			head = newNode;
			newNode->next = head;
			head->next = newNode;
		}
		else
		{
			newNode->next = head->next;
			head->next = newNode;
			head = newNode;
		}
		size++;
	}
	void PopFront()
	{
		cout << "Remaining Node : " << size << endl;
		Node* deleteNode;
		if (size == 0)
		{

			cout << "List is empty" << endl;

		}
		else if (size == 1)
		{
			deleteNode = head;
			delete deleteNode;
			head = nullptr;
		}
		else
		{
			deleteNode = head->next;
			head->next = deleteNode->next;
			delete deleteNode;
		}
		size--;

	}
	void PopBack()
	{
		cout << "Remaining Node : " << size << endl;
		Node* deleteNode;
		Node* currentNode;
		if (size == 0)
		{
			cout << "List is empty" << endl;
		}
		else if (size == 1)
		{

			deleteNode = head;
			delete deleteNode;
			head = nullptr;
		}
		else
		{
			currentNode = head, deleteNode = head;
			while (size - 1)
			{
				currentNode = currentNode->next;

			}
			currentNode->next = head->next;
			head = currentNode;
			delete deleteNode;

		}

		size--;


	}

	void ShowNode()
	{
		Node* currentNode;
		currentNode = head;
		int num = size + 4;
		cout << endl << "List : ";
		while (num)
		{
			if (num > 1)
			{
				cout << currentNode->data << "-";
				currentNode = currentNode->next;
			}
			if (num == 1)
			{
				cout << currentNode->data;
				currentNode = currentNode->next;
			}
			--num;
		}
		cout << endl << endl;

	}
	int Size()
	{
		return size;
	}
};


int main()
{
	CircleLinkedList<int>circleLinkedList;
	circleLinkedList.PushFront(10);
	circleLinkedList.PushFront(20);
	circleLinkedList.PushFront(30);
	circleLinkedList.PushBack(40);
	circleLinkedList.PushBack(50);
	circleLinkedList.PushBack(60);
	cout << endl << "CircleLinkedList의 크기 : " << circleLinkedList.Size() << endl;
	circleLinkedList.ShowNode();


	return 0;
}













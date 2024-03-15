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
	~DoubleLinkedList()
	{
		while (size != 0)
		{
			PopFront();
			PopBack();

		}

		cout << "Release List";
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


		};
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


		Node* deleteNode = head;


		if (size == 0)
		{

			cout << endl << "List empty" << endl;
		}
		else if (size == 1)
		{
			tail = nullptr;
			head = nullptr;
			delete deleteNode;
		}
		else
		{

			head = head->next;
			head->prev = nullptr;


			delete deleteNode;

		}
		size--;

	}
	void PopBack()
	{
		cout << "Remaining Node : " << size << endl;





		Node* deleteNode = tail;

		if (size == 0)
		{

			cout << endl << "List empty" << endl;
			return;

		}
		else if (size == 1)
		{

			head = nullptr;
			tail = nullptr;
			delete deleteNode;
		}
		else
		{

			tail = tail->prev;
			tail->next = nullptr;

			delete deleteNode;
		}
		size--;
	}

	void Show()
	{
		Node* currentNode = nullptr;
		currentNode = head;
		while (currentNode != NULL)
		{
			cout << currentNode->data << "-";
			currentNode = currentNode->next;
		}
		cout << endl;
	}
	int Size()
	{
		return size;
	}

	void Insert(int position, T data)
	{

		if (position <= 1)
		{
			PushFront(data);
			return;
		}
		else if (position == size + 1)
		{
			PushBack(data);
			return;
		}
		else if (position > size + 1)
		{
			cout << "position 값이 잘못되었습니다." << endl;
			return;
		}
		Node* currentNode = head;
		for (int i = 1; i < position; i++)
		{
			currentNode = currentNode->next;

		}
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = currentNode;
		currentNode->prev->next = newNode;

		newNode->prev = currentNode->prev;

		currentNode->prev = newNode;
		size++;








	}








};





int main()
{
	DoubleLinkedList<int> doublelinkedlist;

	doublelinkedlist.PushFront(100);
	doublelinkedlist.Insert(2, 20);
	doublelinkedlist.PushFront(99);
	doublelinkedlist.PushFront(98);
	doublelinkedlist.PushBack(32);
	doublelinkedlist.PushBack(31);


	cout << "DoubleLinkedList의 크기 : " << doublelinkedlist.Size() << endl;

	doublelinkedlist.Show();



	return 0;
}













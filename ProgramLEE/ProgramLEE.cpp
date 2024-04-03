#include<iostream>
using namespace std;

template <typename T>

class BinarySearchTree
{
private:
	struct Node
	{
		T data;
		Node* left;
		Node* right;
		
	};
	Node* root;
public:
	BinarySearchTree()
	{
		root = nullptr;
	}
	Node* CreateNode(T key)
	{
		Node* newNode = new Node;
		newNode->data = key;
		newNode->left = nullptr;
		newNode->right = nullptr;
		return newNode;
	}
	void Insert(T key)
	{	
		
		if (root == nullptr)
		{	
			root = CreateNode(key); 
			
			return;
		}
		else
		{
			Node* currentNode = root;

			while (currentNode)
			{
				//내가 삽입하고자 하는 값이 current 값 보다 작은 경우 
				if (currentNode->data > key)
				{	
					//left 에 값이 있다면
					if (currentNode->left)
					{
						currentNode = currentNode->left;
					}
					else //없으면 추가 
					{
						currentNode->left = CreateNode(key);
						break;
					}
				}
				//내가 삽입하고자 하는 값이 current 값 보다 큰 경우 
				else if (currentNode->data < key)
				{
					if (currentNode->right) //값이 있으면 
					{
						currentNode = currentNode->right;
					}
					else //없으면 추가 
					{
						currentNode->right = CreateNode(key);
						break;
					}
				}
				else //중복 불가 
				{
					cout << "중복 값은 허용 X" << endl;
					return;
				}
			}

		}
	}
	
	void Find(T data)
	{	
		Node* currentNode = root;

		while (currentNode)
		{
			if (data < currentNode->data)
			{
				
				currentNode = currentNode->left;
				
			}
			else if (data > currentNode->data)
			{
				
				currentNode = currentNode->right;
			}
			else
			{
				cout << "Find data" << endl;
				return;
			}

		}
		if (currentNode == nullptr)
		{
			cout << "Can't Find" << endl;
			break;
		}
	}
	void Min()
	{
		Node* currentNode = root;
		while (currentNode)
		{
			if (currentNode->left)
			{
				curretNode = currentNode->left;
			}
			else
			{
				cout << currentNode->data << endl;
			}
		}
	}
	void Max()
	{
		Node* currentNode = root;
	}
};
int main()
{
#pragma region 이진탐색트리 

	// 한 노드에 대해 왼쪽 / 오른쪽의 (최대) 두개의 자식을 가질 수 있는 트리이며
	// 왼쪽 자식은 부모 노드보다 작은 값을 , 오른쪽 자식은 부모 노드보다 큰 값을 
	// 가지는 탐색 트리.
	
	

	
	
#pragma endregion
	
	
	
	
	
	
	
	
	
	
	
	
	
		




	return 0;
}
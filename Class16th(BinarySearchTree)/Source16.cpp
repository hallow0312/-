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

	bool Find(T data)
	{
		Node* currentNode = root;

		while (currentNode)
		{
			if (currentNode != nullptr)
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
					return true;
				}
			}
			else
			{
				break;
			}
		}
		if (currentNode == nullptr)
		{
			return false;
		}
	}
	void Min()
	{
		Node* currentNode = root;
		while (currentNode)
		{
			if (currentNode->left)
			{
				currentNode = currentNode->left;
			}
			else
			{
				cout << currentNode->data << endl;
				return;
			}
		}
	}
	void Max()
	{
		Node* currentNode = root;
		while (currentNode)
		{
			if (currentNode->right)
			{
				currentNode = currentNode->right;
			}
			else
			{
				cout << currentNode->data << endl;
				return;
			}

		}
	}
	void Delete(T data)
	{
		if (Find(data) == false)
		{
			cout << "Wrong data" << endl;
			return;
		}
		else
		{
			//1.자식 노드가 없는 노드를 삭제하는 경우 
			Node* currentNode = root;
			Node* Parent = root;
			if (currentNode == nullptr)
			{
				cout << "BinarySearchTree is Empty" << endl;
				return;
			}
			while (currentNode->data != data)
			{
				if (currentNode->data < data)
				{
					Parent = currentNode;
					currentNode = currentNode->right;
				}
				else if (currentNode->data > data)
				{
					Parent = currentNode;
					currentNode = currentNode->left;
				}

			}
			if (currentNode->right == nullptr && currentNode->left == nullptr)
			{
				if (Parent->left == currentNode)
				{
					delete currentNode;
					Parent->left = nullptr;

				}
				else if (Parent->right == currentNode)
				{
					delete currentNode;
					Parent->right = nullptr;


				}
				else if (currentNode == root)
				{
					delete root;
					root = nullptr;
				}
			}

			else
			{

				if (currentNode->left != nullptr && currentNode->right == nullptr)
				{
					if (currentNode == root)
					{
						Node* p = Parent->left;

						delete currentNode;
						root = p;
					}
					else
					{
						Parent->left = currentNode->left;
						delete currentNode;

					}

				}
				else if (currentNode->left == nullptr && currentNode->right != nullptr)
				{
					if (currentNode == root)
					{
						Node* p = Parent->right;

						delete currentNode;
						root = p;
					}
					else
					{
						Parent->right = currentNode->right;
						delete currentNode;

					}

				}
				else if (currentNode->left != nullptr && currentNode->right != nullptr)
				{

					Node* child = currentNode->right;
					while (child == nullptr)
					{
						child = child->left;
					}
					if (currentNode->data > Parent->data)
					{
						Parent->right = child;
						child->left = currentNode->left;
						child->right = currentNode->right;
						delete currentNode;
						
					}
					else if (currentNode->data < Parent->data)
					{
						Parent->left = child;
						child->left = currentNode->left;
						child->right = currentNode->right;
						delete currentNode;

					}
					else if (currentNode == root)
					{
						child->left = currentNode->left;
						child->right = currentNode->right;
						delete currentNode;
						root = child;
					}

					
				}

			}

		}

	}
	Node* returnROOT()
	{
		return root;
	}
	void Inorder(Node* root)
	{
		if (root != nullptr)
		{
			Inorder(root->left);
			cout << root->data << " ";
			Inorder(root->right);
		}
		else
		{
			return;
		}

	}
	~BinarySearchTree()
	{
		Destroy(root);
		
	}
	void Destroy(Node* root)
	{
		if (root != nullptr)
		{
			Destroy(root->left);
			Destroy(root->right);
			delete root;
		}
	}
		
};








int main()
{
#pragma region 이진탐색트리 

	// 한 노드에 대해 왼쪽 / 오른쪽의 (최대) 두개의 자식을 가질 수 있는 트리이며
	// 왼쪽 자식은 부모 노드보다 작은 값을 , 오른쪽 자식은 부모 노드보다 큰 값을 
	// 가지는 탐색 트리.


	BinarySearchTree <int> tree;
	tree.Insert(5);
	tree.Insert(7);
	tree.Insert(8);
	tree.Insert(9);
	tree.Insert(10);



	tree.Inorder(tree.returnROOT());
	tree.Delete(5);
	cout << endl;

	tree.Inorder(tree.returnROOT());
	tree.Delete(7);
	cout << endl;

	tree.Inorder(tree.returnROOT());
	tree.Delete(9);
	cout << endl;
	tree.Inorder(tree.returnROOT());
	tree.Delete(8);
	cout << endl;

	tree.Inorder(tree.returnROOT());
	tree.Delete(10);
	cout << endl;

	tree.Inorder(tree.returnROOT());







#pragma endregion


















	return 0;
}

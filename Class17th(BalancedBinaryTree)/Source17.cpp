#include<iostream>

using namespace std;
template <typename T>
class BalancedBinaryTree
{
private:
	struct Node
	{
		int height;
		T data;
		Node* left;
		Node* right;
	};
	Node* root;
public:
	BalancedBinaryTree()
	{
		root = nullptr;
	}
	Node* CreateNode(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->height = 1;
		newNode->left = nullptr;
		newNode->right = nullptr;
		return newNode;
	}
	int Height(Node* node)
	{
		if (node == nullptr)
		{
			return 0;
		}
		else
		{
			int left = Height(node->left);
			int right = Height(node->right);

			int height = max(left, right) + 1;
			return height;
		}




	}
	int BalanceFactor(Node* node)
	{

		return Height(node->left) - Height(node->right);


	}
	Node* Insert(Node* root, T data)
	{
		if (root == nullptr)
		{
			Node* newNode = CreateNode(data);

			return newNode;

		}
		else if (root->data < data)
		{
			root->right = Insert(root->right, data);


		}
		else if (root->data > data)
		{
			root->left = Insert(root->left, data);

		}
		root = Rebalance(root, data);
		return root;


	}
	Node* Rebalance(Node* root)
	{
		int factor = BalanceFactor(root);

		if (factor > 1) // 왼쪽으로 치우침 
		{
			if (root->data > root->left->data) //LL 회전 
			{
				root = LLRotate(root);
			}
			else if (root->data < root->right->data) //LR 회전
			{
				root->left = RRRotate(root->left);
				root - LLRotate(root);
			}
		}
		else if (factor < -1)  // 오른쪽으로 치우침
		{
			if (root->data < root->right->data) //RR 회전 
			{
				root = RRRotate(root);

			}
			else if (root->data > root->left->data) //RL  회전
			{
				root->right = LLRotate(root->right);
				root = RRRotate(root);
			}
		}
		return root;
	}


	Node* LLRotate(Node* root)
	{
		Node* temp = root->left;

		root->left = temp->right;

		temp->right = root;

		return temp;

	}
	Node* RRRotate(Node* root)
	{
		Node* temp = root->right;
		root->right = temp->left;

		temp->left = root;
		return temp;
	}

	void Print()
	{
		Show(root);
	}
	void Show(Node* root)
	{
		Show(root->left);
		cout << root->data << " ";
		Show(root->right);
	}

};
int main()
{

#pragma region 균형 이진 탐색 트리 

	// 삽입과 삭제가 일어나는 경우 자동으로 그높이를 
	// 작게 유지하는 노드 기반 이진 탐색 트리 .

	//Balance Factor(BF)
	// 왼쪽 서브 트리의 높이에서 오른쪽 서브 트리의 
	// 높이를 뺸 값 ;

	//BF = 1 (왼쪽 서브트리의 높이가 오른쪽 서브트리의 높이보다 한 단계 높음.)

	//BF = 0 (왼쪽 서브 트리의 높이와 오른쪽 서브 트리의 높이가 같다 )

	//BF = -1 (왼쪽 서브트리의 높이가 오른쪽 서브트리의 높이보다 한 단계 낮다 )

	// LL 유형 : 불균형 발생 노드의 왼쪽 자식 노드와 자식의 왼쪽 자식 노드에 
	// 의해 왼쪽으로 기울어져 있음 . 

	// RR 유형 : 불균형 발생 노드의 오른쪽 자식 노드와 자식의 오른쪽 자식 노드에 의해 
	// 오른쪽으로 기울어져 있음

	//LR 유형 : 불균형 발생노드의 왼쪽 자식 노드와 자식의 오른쪽 자식 노드에 의해 
	// 왼쪽 서브트리가 기울어져 있음.

	//RL 유형 : 불균형 발생노드의 오른쪽 자식노드와 자식의 왼쪽 자식 노드에 의해 
	// 오른쪽 서브트리가 기울어져 있음

#pragma endregion


	return 0;
}

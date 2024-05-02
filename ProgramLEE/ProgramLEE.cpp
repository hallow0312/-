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
		return node->height;
	}
	int BalanceFactor(Node* node)
	{
		
		return Height(node->left) - Height(node->right);
		
		
	}
	void Insert(T data)
	{

		if (root == nullptr)
		{
			root = CreateNode(data);

			return;
		}
		else
		{
			Node* currentNode = root;

			while (currentNode)
			{
				//내가 삽입하고자 하는 값이 current 값 보다 작은 경우 
				if (currentNode->data > data)
				{
					//left 에 값이 있다면
					if (currentNode->left)
					{
						currentNode = currentNode->left;
					}
					else //없으면 추가 
					{
						currentNode->left = CreateNode(data);
						break;
					}
				}
				//내가 삽입하고자 하는 값이 current 값 보다 큰 경우 
				else if (currentNode->data < data)
				{
					if (currentNode->right) //값이 있으면 
					{
						currentNode = currentNode->right;
					}
					else //없으면 추가 
					{
						currentNode->right = CreateNode(data);
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
	void Balancing(Node* root,T data)
	{
		int BF = BalanceFactor(root); 
		// LL 회전 LR 회전 RR 회전 RL 회전 
		if (BF > 1 && data > root->left->data)
		{

		}
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

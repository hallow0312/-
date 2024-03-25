#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};


Node* CreateNode(int data, Node*left, Node*right)
{	//1. 새로운 노드 작성
	Node* newNode = new Node;

	//2. 새로운 노드의 데이터 값 저장 
	newNode->data = data; 

	//3. 새로운 노드의 left 값 저장 
	newNode->left = left; 

	//4. 새로운 노드의 right 값 저장 
	newNode->right = right; 

	//5. 새로운 노드의 주소값 반환
	return newNode;
}

void Preivous(Node* node)
{
	if (node != nullptr)
	{	
		cout<<node->data<<" ";
		Preivous(node->left);
		Preivous(node->right);
	}
	else
	{
		return;
	}
	
}
void Inorder(Node* node)
{
	if (node != nullptr)
	{
		Inorder(node->left);
		cout << node->data<<" ";
		Inorder(node->right);
	}
	else
	{
		return;
	}
}
void Postorder(Node* node)
{
	if (node != nullptr)
	{
		Postorder(node->left);
		Postorder(node->right);
		cout << node->data<<" ";
	}
	else
	{
		return;
	}
}

int main()
{
	
#pragma region Tree 구조
	//root : 최상위 노드															
	//edge : 노드와 노드를 연결하는 간선											
	//parent : 부모 노드 A B C (자신보다 하위 노드를 가지고 있는 노드 )			   
	//leaf: 자식 노드를 가지고 있지 않는 노드 D E F G								
	//level : root 로 부터 하위 단계를 측정하는 것.
	//height: level 의 역순 
	// path: 노드 와 노드 사이간에 나타나는 노드와 간선의 순서 
	// degree: 해당노드가 포함하는 자식 노드의 수 
	// 트리구조 사용 이유 : 반복문보다 시간복잡도에 의해 시간 감소 

	Node* node7 = CreateNode(7, nullptr, nullptr); 
	Node* node6 = CreateNode(6, nullptr, nullptr); 
	Node* node5 = CreateNode(5, nullptr, nullptr); 
	Node* node4 = CreateNode(4, nullptr, nullptr); 
	Node* node3 = CreateNode(3, node6, node7); 
	Node* node2 = CreateNode(2, node4, node5); 
	Node* node1 = CreateNode(1, node2, node3); 
	
	Preivous(node1);
	cout << endl;
	
	Inorder(node1);
	cout << endl;
	
	Postorder(node1);
	cout << endl;
	//전위 순회
	//  1.Root Node 방문 
	//	2.왼쪽 서브 트리 전위 순회 
	//	3. 오른쪽 서브 트리 전위 순회 
	// 1->2->4->5->3->6->7

	//중위 순회 
	//1. 왼쪽 서브 트리 중위 순회
	//2. Root Node 방문
	//3. 오른쪽 서브 트리 중위 순회 
	
	// 후위 순회 
	// 1. 왼쪽 서브트리  후위 순회
	//	2. 오른쪽 서브트리 후위 순회
	//	3. Root Node 방문 
#pragma endregion

	

	return 0;
}
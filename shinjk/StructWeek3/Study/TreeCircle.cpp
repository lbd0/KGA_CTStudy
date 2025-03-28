#include<iostream>

using namespace std;

class Tree
{
public:
	struct Node
	{
		char data;
		Node* parent;
		Node* left;
		Node* right;

		Node(char data) :data(data), parent(nullptr), left(nullptr), right(nullptr) {}//노드에 data값 넣은데로 data 저장. 부모,왼쪽,오른쪽 포인트변수 기본적으로 nullptr
	};

	Node* root;//root 포인트변수 생성

public:
	Tree() { root = nullptr; }//root 포인트변수 값 nullptr으로 초기화

	void Insert(Node*& root, char a, char b, char c)
	{
		if (root == nullptr)//root가 없다면
		{
			Node* node1 = new Node(a);
			root = node1;//a의 데이터를 가진 node1이 root
			Node* node2 = new Node(b);
			root->left = node2;//b의 데이터를 가진 node2가 root의 왼쪽 자식
			root->left->parent = node1;//부모로 연결
			Node* node3 = new Node(c);
			root->right = node3;//c의 데이터를 가진 node3이 root의 오른쪽 자식
			root->right->parent = node1;//부모로 연결
		}
		else if (root->data == a)//비교 root의 data가 a라면
		{
			if (b != '.')//그리고 b가 .이 아니라면
			{
				Node* node1 = new Node(b);
				root->left = node1;//b의 데이터를 가진 node1이 비교root의 왼쪽자식
				root->left->parent = root;//부모로 연결
			}
			if (c != '.')
			{
				Node* node2 = new Node(c);//c의 데이터를 가진 node2가 비교root의 오른쪽 자식
				root->right = node2;//c의 데이터를 가진 node2가 비교root의 오른쪽 자식
				root->right->parent = root;//부모로 연결
			}
			return;
		}
		else
		{
			if (root->left != nullptr)//비교 root의 왼쪽이 있다면
			{
				Insert(root->left, a, b, c);//재귀함수
			}
			if (root->right != nullptr)//비교 root의 오른쪽이 있다면
			{
				Insert(root->right, a, b, c);//재귀함수
			}
		}
	}

	void preorder(Node* root)//전위순회
	{
		cout << root->data;//root의 data 출력
		if (root->left != nullptr)//root의 왼쪽자식이 있다면
		{
			preorder(root->left);//왼쪽 재귀함수
		}
		if (root->right != nullptr)//root의 오른쪽 자식이 있다면
		{
			preorder(root->right);//오른쪽 재귀함수
		}
	}

	void inorder(Node* root)//중위순회
	{
		if (root->left != nullptr)//root의 왼쪽자식이 있다면
		{
			inorder(root->left);//왼쪽 재귀함수
		}
		cout << root->data;//root의 data 출력
		if (root->right != nullptr)//root의 오른쪽 자식이 있다면
		{
			inorder(root->right);//오른쪽 재귀함수
		}
	}

	void postorder(Node* root)
	{
		if (root->left != nullptr)//root의 왼쪽자식이 있다면
		{
			postorder(root->left);//왼쪽 재귀함수
		}
		if (root->right != nullptr)//root의 오른쪽 자식이 있다면
		{
			postorder(root->right);//오른쪽 재귀함수
		}
		cout << root->data;//root의 data 출력
	}
};

//int main()
//{
//
//	int count;
//	cin >> count;//원소 갯수
//	char a;
//	char b;
//	char c;
//	Tree* t = new Tree();
//
//	for (int i=0; i < count; ++i)//원소 갯수만큼 입력받아서 삽입
//	{
//		cin >> a>>b>>c;
//		t->Insert(t->root, a, b, c);
//	}
//
//	t->preorder(t->root);
//	cout << endl;
//	t->inorder(t->root);
//	cout << endl;
//	t->postorder(t->root);
//
//
//}
#include<iostream>
#include<queue>

using namespace std;

class Tree
{
public:
	struct Node
	{
		int data;
		Node* parent;
		Node* left;
		Node* right;

		Node(int data) :data(data),parent(nullptr),left(nullptr),right(nullptr) {}
		//노드에 data값 넣은데로 data 저장. 부모,왼쪽,오른쪽 포인트변수 기본적으로 nullptr
	};

	Node* root;//root 포인트변수 생성

public:
	Tree() { root = nullptr; }//root 포인트변수 값 nullptr으로 초기화

	void Insert(Node*& root, Node* n) 
	{
		if (!root)//root가 없다면
		{
			root = n;//root는 n
		}
		else if (root->data >= n->data)//비교root의 data가 n의 data보다 크거나 같고
		{
			if (root->left == nullptr)//비교root의 왼쪽자식이 nullptr이라면,
			{
				root->left = n;//왼쪽 자식은 n
				n->parent = root;//n의 부모는 비교루트
				return;
			}
			else//왼쪽자식이 있다면,
			{
				this->Insert(root->left, n);//재귀함수
			}
			
		}
		else//비교root의 data가 n의 data보다 작고
		{
			if (root->right == nullptr)//비교root의 오른쪽자식이 nullptr이라면,
			{
				root->right = n;//오른쪽 자식은 n
				n->parent = root;//n의 부모는 비교루트
				return;
			}
			else//오른쪽 자식이 있다면
			{
				this->Insert(root->right, n);//재귀함수
			}
		}
	}

	void preorder(Node* n)
	{
		if (n == nullptr)return;
		cout << n->data << endl;//n의 data 출력
		if (n->left != nullptr)//n의 왼쪽 자식이 있다면
		{
			preorder(n->left);//재귀함수
		}
		if (n->right != nullptr)//n의 오른쪽 자식이 있다면
		{
			preorder(n->right);//재귀함수
		}
		else
		{
			return;
		}

	}

	void inorder(Node* n)
	{
		if (n == nullptr)return;
		if (n->left != nullptr)//n의 왼쪽 자식이 있다면
		{
			inorder(n->left);//재귀함수
		}
		cout << n->data << endl;//n의 data 출력
		if (n->right != nullptr)//n의 오른쪽 자식이 있다면
		{
			inorder(n->right);//재귀함수
		}
		else
		{
			return;
		}

	}

	void postorder(Node* n)
	{
		if (n == nullptr)return;
		if (n->left != nullptr)//n의 왼쪽 자식이 있다면
		{
			postorder(n->left);//재귀함수
		}
		if (n->right != nullptr)//n의 오른쪽 자식이 있다면
		{
			postorder(n->right);//재귀함수
		}
		cout << n->data << endl;//n의 data 출력
	}

	void pop(int data,Node*root)
	{
		if (data == root->data)//data가 비교대상의 data와 같다면
		{
			cout << root->data;
			delete(root);//비교대상 삭제(연결은 못하겠습니다....)
		}
		pop(data, root->left);//그게 아니라면 왼쪽 재귀
		pop(data, root->right);//오른쪽도 재귀
	}

};

//int main()
//{
//	Tree* t = new Tree();
//
//	Tree::Node* node = new Tree::Node(5);
//	t->Insert(t->root, node);
//	Tree::Node* node1 = new Tree::Node(10);
//	Tree::Node* node2 = new Tree::Node(6);
//	Tree::Node* node3 = new Tree::Node(4);
//	Tree::Node* node4 = new Tree::Node(8);
//	Tree::Node* node5 = new Tree::Node(7);
//	t->Insert(t->root, node1);
//	t->Insert(t->root, node2);
//	t->Insert(t->root, node3);
//	t->Insert(t->root, node4);
//	t->Insert(t->root, node5);
//
//
//	t->preorder(t->root);
//	cout << endl;
//	t->inorder(t->root);
//	cout << endl;
//	t->postorder(t->root);
//}

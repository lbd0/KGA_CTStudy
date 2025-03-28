#include <iostream>

using namespace std;

struct Node
{
	int data = 0;
	Node* parent = nullptr;
	Node* right = nullptr;
	Node* left = nullptr;

	Node(int data)
		:data(data)
	{

	}
};


void Insert(Node*& root, Node* n)
{
	if (!root)
	{
		root = n;
		return;
	}

	//해당 루트에서 값을 비교해가면서 삽입
	if (root->data >= n->data)
	{
		if (!root->left)
		{
			root->left = n;
			n->parent = root;
		}
		else
		{
			Insert(root->left, n);
		}
	}
	else if (root->data <= n->data)
	{
		if (!root->right)
		{
			root->right = n;
			n->parent = root;
		}
		else
		{
			Insert(root->left, n);
		}
	}
}

void Create(Node*& root)
{
	// 초기화. 간단하게 생성

	int keys[] = { 50, 30, 20, 40, 70, 60, 80 };

	for (int key : keys)
	{
		Node* node = new Node(key);
		Insert(root, node);
	}
}
Node* Delete(Node* root, int data)
{
	if (!root)
	{
		return nullptr;
	}

	if (root->data > data)
	{
		Delete(root->left, data);
	}
	else if (root->data < data)
	{
		Delete(root->right, data);
	}
	else if (root->data == data)
	{
		if (!root->left && !root->right)
		{
			//삭제하려는 노드가 리프일 때
			delete root;
			return nullptr;
		}
		//자식이 하나만 있을 때
		else if (!root->left)
		{
			//자식이 오른쪽에 하나만 있을 때
			Node* temp = root->right;
			temp->parent = root->parent;
			delete root;
			return temp;
		}
		else if (!root->right)
		{
			//자식이 왼쪽에 하나만 있을 때
			Node* temp = root->left;
			temp->parent = root->parent;
			delete root;
			return temp;
		}
		else
		{
			//자식 노드가 2개 일 때
			
		}


	}
}

void PreOrder(Node* n)
{
	if (!n)
	{
		return;
	}
	cout << n->data << endl;
	if (n->left != nullptr)
	{
		PreOrder(n->left);
	}
	if (n->right != nullptr)
	{
		PreOrder(n->right);
	}

}

void InOrder(Node* n)
{
	if (!n)
		return;

	if (n->left != nullptr)
	{
		InOrder(n->left);
	}
	cout << n->data << endl;
	if (n->right != nullptr)
	{
		InOrder(n->right);
	}
}

void PostOrder(Node* n)
{
	if (!n)
		return;

	if (n->left != nullptr)
	{
		PostOrder(n->left);
	}
	if (n->right != nullptr)
	{
		PostOrder(n->right);
	}
	cout << n->data << endl;
}
int main()
{
	Node* root = nullptr;
	Create(root);
	PreOrder(root);

	Node* node = new Node(1);
	Insert(root, node);
	cout << "--------" << endl;
	PreOrder(root);
}

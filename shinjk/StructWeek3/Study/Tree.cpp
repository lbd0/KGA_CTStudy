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

	};

	Node* root;

public:
	Tree() { root = nullptr; }

	void Insert(Node*& root, Node* n) 
	{
		if (!root)
		{
			root = n;
		}
		else if (root->data >= n->data)
		{
			if (root->left == nullptr)
			{
				root->left = n;
				n->parent = root->left;
				return;
			}
			else
			{
				this->Insert(root->left, n);
			}
			
		}
		else
		{
			if (root->right == nullptr)
			{
				root->right = n;
				n->parent = root->right;
				return;
			}
			else
			{
				this->Insert(root->right, n);
			}
		}
	}

	void preorder(Node* n)
	{
		if (n == nullptr)return;
		cout << n->data << endl;
		if (n->left != nullptr)
		{
			preorder(n->left);
		}
		if (n->right != nullptr)
		{
			preorder(n->right);
		}
		else
		{
			return;
		}

	}

	void inorder(Node* n)
	{
		if (n == nullptr)return;
		if (n->left != nullptr)
		{
			inorder(n->left);
		}
		cout << n->data << endl;
		if (n->right != nullptr)
		{
			inorder(n->right);
		}
		else
		{
			return;
		}

	}

	void postorder(Node* n)
	{
		if (n == nullptr)return;
		if (n->left != nullptr)
		{
			postorder(n->left);
		}
		if (n->right != nullptr)
		{
			postorder(n->right);
		}
		cout << n->data << endl;
	}

	void pop(int data,Node*root)
	{
		if (data == root->data)
		{
			cout << root->data;
			delete(root);
		}
		pop(data, root->left);
		pop(data, root->right);
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

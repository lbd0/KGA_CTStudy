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

		Node(char data) :data(data), parent(nullptr), left(nullptr), right(nullptr) {}
	};

	Node* root;

public:
	Tree() { root = nullptr; }

	void Insert(Node*& root, char a, char b, char c)
	{
		if (root == nullptr)
		{
			Node* node1 = new Node(a);
			root = node1;
			Node* node2 = new Node(b);
			root->left = node2;
			root->left->parent = node1;
			Node* node3 = new Node(c);
			root->right = node3;
			root->right->parent = node1;
		}
		else if (root->data == a)
		{
			if (b != '.')
			{
				Node* node1 = new Node(b);
				root->left = node1;
				root->left->parent = root;
			}
			if (c != '.')
			{
				Node* node2 = new Node(c);
				root->right = node2;
				root->right->parent = root;
			}
			return;
		}
		else
		{
			if (root->left != nullptr)
			{
				Insert(root->left, a, b, c);
			}
			if (root->right != nullptr)
			{
				Insert(root->right, a, b, c);
			}
		}
	}

	void preorder(Node* root)
	{
		cout << root->data;
		if (root->left != nullptr)
		{
			preorder(root->left);
		}
		if (root->right != nullptr)
		{
			preorder(root->right);
		}
	}

	void inorder(Node* root)
	{
		if (root->left != nullptr)
		{
			inorder(root->left);
		}
		cout << root->data;
		if (root->right != nullptr)
		{
			inorder(root->right);
		}
	}

	void postorder(Node* root)
	{
		if (root->left != nullptr)
		{
			postorder(root->left);
		}
		if (root->right != nullptr)
		{
			postorder(root->right);
		}
		cout << root->data;
	}
};

int main()
{

	int count;
	cin >> count;
	char a;
	char b;
	char c;
	Tree* t = new Tree();

	for (int i=0; i < count; ++i)
	{
		cin >> a>>b>>c;
		t->Insert(t->root, a, b, c);
	}

	t->preorder(t->root);
	cout << endl;
	t->inorder(t->root);
	cout << endl;
	t->postorder(t->root);


}
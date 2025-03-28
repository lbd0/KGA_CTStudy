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

		Node(char data) :data(data), parent(nullptr), left(nullptr), right(nullptr) {}//��忡 data�� �������� data ����. �θ�,����,������ ����Ʈ���� �⺻������ nullptr
	};

	Node* root;//root ����Ʈ���� ����

public:
	Tree() { root = nullptr; }//root ����Ʈ���� �� nullptr���� �ʱ�ȭ

	void Insert(Node*& root, char a, char b, char c)
	{
		if (root == nullptr)//root�� ���ٸ�
		{
			Node* node1 = new Node(a);
			root = node1;//a�� �����͸� ���� node1�� root
			Node* node2 = new Node(b);
			root->left = node2;//b�� �����͸� ���� node2�� root�� ���� �ڽ�
			root->left->parent = node1;//�θ�� ����
			Node* node3 = new Node(c);
			root->right = node3;//c�� �����͸� ���� node3�� root�� ������ �ڽ�
			root->right->parent = node1;//�θ�� ����
		}
		else if (root->data == a)//�� root�� data�� a���
		{
			if (b != '.')//�׸��� b�� .�� �ƴ϶��
			{
				Node* node1 = new Node(b);
				root->left = node1;//b�� �����͸� ���� node1�� ��root�� �����ڽ�
				root->left->parent = root;//�θ�� ����
			}
			if (c != '.')
			{
				Node* node2 = new Node(c);//c�� �����͸� ���� node2�� ��root�� ������ �ڽ�
				root->right = node2;//c�� �����͸� ���� node2�� ��root�� ������ �ڽ�
				root->right->parent = root;//�θ�� ����
			}
			return;
		}
		else
		{
			if (root->left != nullptr)//�� root�� ������ �ִٸ�
			{
				Insert(root->left, a, b, c);//����Լ�
			}
			if (root->right != nullptr)//�� root�� �������� �ִٸ�
			{
				Insert(root->right, a, b, c);//����Լ�
			}
		}
	}

	void preorder(Node* root)//������ȸ
	{
		cout << root->data;//root�� data ���
		if (root->left != nullptr)//root�� �����ڽ��� �ִٸ�
		{
			preorder(root->left);//���� ����Լ�
		}
		if (root->right != nullptr)//root�� ������ �ڽ��� �ִٸ�
		{
			preorder(root->right);//������ ����Լ�
		}
	}

	void inorder(Node* root)//������ȸ
	{
		if (root->left != nullptr)//root�� �����ڽ��� �ִٸ�
		{
			inorder(root->left);//���� ����Լ�
		}
		cout << root->data;//root�� data ���
		if (root->right != nullptr)//root�� ������ �ڽ��� �ִٸ�
		{
			inorder(root->right);//������ ����Լ�
		}
	}

	void postorder(Node* root)
	{
		if (root->left != nullptr)//root�� �����ڽ��� �ִٸ�
		{
			postorder(root->left);//���� ����Լ�
		}
		if (root->right != nullptr)//root�� ������ �ڽ��� �ִٸ�
		{
			postorder(root->right);//������ ����Լ�
		}
		cout << root->data;//root�� data ���
	}
};

//int main()
//{
//
//	int count;
//	cin >> count;//���� ����
//	char a;
//	char b;
//	char c;
//	Tree* t = new Tree();
//
//	for (int i=0; i < count; ++i)//���� ������ŭ �Է¹޾Ƽ� ����
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
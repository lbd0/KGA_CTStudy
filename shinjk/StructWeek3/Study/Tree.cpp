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
		//��忡 data�� �������� data ����. �θ�,����,������ ����Ʈ���� �⺻������ nullptr
	};

	Node* root;//root ����Ʈ���� ����

public:
	Tree() { root = nullptr; }//root ����Ʈ���� �� nullptr���� �ʱ�ȭ

	void Insert(Node*& root, Node* n) 
	{
		if (!root)//root�� ���ٸ�
		{
			root = n;//root�� n
		}
		else if (root->data >= n->data)//��root�� data�� n�� data���� ũ�ų� ����
		{
			if (root->left == nullptr)//��root�� �����ڽ��� nullptr�̶��,
			{
				root->left = n;//���� �ڽ��� n
				n->parent = root;//n�� �θ�� �񱳷�Ʈ
				return;
			}
			else//�����ڽ��� �ִٸ�,
			{
				this->Insert(root->left, n);//����Լ�
			}
			
		}
		else//��root�� data�� n�� data���� �۰�
		{
			if (root->right == nullptr)//��root�� �������ڽ��� nullptr�̶��,
			{
				root->right = n;//������ �ڽ��� n
				n->parent = root;//n�� �θ�� �񱳷�Ʈ
				return;
			}
			else//������ �ڽ��� �ִٸ�
			{
				this->Insert(root->right, n);//����Լ�
			}
		}
	}

	void preorder(Node* n)
	{
		if (n == nullptr)return;
		cout << n->data << endl;//n�� data ���
		if (n->left != nullptr)//n�� ���� �ڽ��� �ִٸ�
		{
			preorder(n->left);//����Լ�
		}
		if (n->right != nullptr)//n�� ������ �ڽ��� �ִٸ�
		{
			preorder(n->right);//����Լ�
		}
		else
		{
			return;
		}

	}

	void inorder(Node* n)
	{
		if (n == nullptr)return;
		if (n->left != nullptr)//n�� ���� �ڽ��� �ִٸ�
		{
			inorder(n->left);//����Լ�
		}
		cout << n->data << endl;//n�� data ���
		if (n->right != nullptr)//n�� ������ �ڽ��� �ִٸ�
		{
			inorder(n->right);//����Լ�
		}
		else
		{
			return;
		}

	}

	void postorder(Node* n)
	{
		if (n == nullptr)return;
		if (n->left != nullptr)//n�� ���� �ڽ��� �ִٸ�
		{
			postorder(n->left);//����Լ�
		}
		if (n->right != nullptr)//n�� ������ �ڽ��� �ִٸ�
		{
			postorder(n->right);//����Լ�
		}
		cout << n->data << endl;//n�� data ���
	}

	void pop(int data,Node*&root)
	{
		if (data == root->data)//data�� �񱳴���� data�� ���ٸ�
		{
			cout << root->data;//�񱳴�� data ���

			if (root->parent == nullptr)//�񱳴���� �θ� ���ٸ�(��Ʈ)
			{
				if (root->left != nullptr&&root->right!=nullptr)//�񱳴���� ������ �ְ�, �����ʵ� �ְ�
				{
					leftInsert(root->right, root->left);//��Ʈ�� �񱳴����������� �ٲٰ�, �񱳴����ʿ� ������Ʈ ���� ���̱�
					root = root->right;
					root->parent = nullptr;
					return;
				}
				else if (root->left != nullptr && root->right == nullptr)//�񱳴���� ������ �ְ�, �������� ����
				{
					root = root->left;//��Ʈ�� �񱳴����������� �ٲٱ�
					root->parent = nullptr;
					return;
					
				}
				else if (root->left == nullptr && root->right != nullptr)
				{
					root = root->right;//��Ʈ�� �񱳴��������� �ٲٱ�
					root->parent = nullptr;
					return;
					
				}
			}
			else if(root->parent!=nullptr)
			{
				if (root == root->parent->left)//�񱳴���� �񱳴��θ��� �����ڽ��̶��
				{
					if (root->right != nullptr)//�񱳴���� �������ڽ��� �ִٸ�
					{
						root->right->parent = root->parent;//�񱳴���� �������ڽ��� �θ�� �񱳴���� �θ�
						root->parent->left = root->right;//�񱳴���� �θ��� �����ڽ��� �񱳴���� ������
						if (root->left != nullptr)//�񱳴���� �����ڽ��� �ִٸ�
						{
							leftInsert(root->right, root->left);//�񱳴���� �������ڽ��� �����ʿ� �񱳴�� �����ڽ� ���̱�
						}
						return;
					}
					else if(root->right==nullptr)//�񱳴���� �������ڽ��� ���ٸ�
					{
						if (root->left != nullptr)//�񱳴���� �����ڽ��� �ִٸ�
						{
							root->left->parent = root->parent;//�񱳴���� �����ڽ��� �θ�� �񱳴���� �θ�
							root->parent->left = root->left;//�񱳴���� �θ��� �����ڽ��� �񱳴���� �����ڽ�
							
						}
						return;
					}

				}
				else if(root==root->parent->right)//�񱳴���� �񱳴��θ��� ������ �ڽ��̶��
				{
					if (root->right != nullptr)//�񱳴���� ������ �ڽ��� �ִٸ�
					{
						root->right->parent = root->parent;//�񱳴���� �������ڽ��� �θ�� �񱳴���� �θ�
						root->parent->right = root->right;//�񱳴���� �θ��� �������ڽ��� �񱳴���� ������ �ڽ�
						if (root->left != nullptr)//�񱳴���� �����ڽ��� �ִٸ�
						{
							leftInsert(root->right, root->left);//�񱳴���� ������ �ڽ��� �� ���ʿ� �񱳴�� �����ڽ� ���̱�
							
						}
						return;
					}
					else if(root->right==nullptr)//�񱳴���� ������ �ڽ��� ���ٸ�
					{
						if (root->left != nullptr)//�񱳴���� ���� �ڽ��� �ִٸ�
						{
							root->left->parent = root->parent;//�񱳴���� �����ڽ��� �θ�� �񱳴���� �θ�
							root->parent->right = root->left;//�񱳴���� �θ��� �������ڽ��� �񱳴���� �����ڽ�
							return;
						
						}
					}
				}
			}
			delete(root);//�񱳴�� ����(������ ���ϰڽ��ϴ�....)
		}
		pop(data, root->left);//�װ� �ƴ϶�� ���� ���
		pop(data, root->right);//�����ʵ� ���
	}

	void leftInsert(Node*& root,Node*&n)
	{
		if (root->left != nullptr)
		{
			leftInsert(root->left,n);
		}
		else
		{
			root->left = n;
			n->parent = root;
		}
	}
};

int main()
{
	Tree* t = new Tree();

	Tree::Node* node = new Tree::Node(5);
	t->Insert(t->root, node);
	Tree::Node* node1 = new Tree::Node(10);
	Tree::Node* node2 = new Tree::Node(6);
	Tree::Node* node3 = new Tree::Node(4);
	Tree::Node* node4 = new Tree::Node(8);
	Tree::Node* node5 = new Tree::Node(7);
	t->Insert(t->root, node1);
	t->Insert(t->root, node2);
	t->Insert(t->root, node3);
	t->Insert(t->root, node4);
	t->Insert(t->root, node5);

	t->pop(5, t->root);
	//t->pop(7, t->root);//��Ʈ�� ���ŵǴµ�, �׳��� ���Ű� �ȵ˴ϴ�...�Ф�

	cout << endl;
	t->preorder(t->root);
	cout << endl;
	t->inorder(t->root);
	cout << endl;
	t->postorder(t->root);
}

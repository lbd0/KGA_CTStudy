#include <iostream>

using namespace std;

template <typename T>
class BST 
{
public:
	struct Node
	{
		T data;					// ������ ������
		Node* parent;		// �θ� ���
		Node* left;			// ���� �ڽ� ���
		Node* right;			// ������ �ڽ� ���

		Node(T data) : data(data), parent(nullptr), left(nullptr), right(nullptr) {}		// ��� ���� �� �ʱ�ȭ

	};

	Node* root;		// ��Ʈ ���

	BST() : root(nullptr) {}			// Ʈ�� ���� �� �ʱ�ȭ

	Node* Root()			// Ʈ���� ��Ʈ ��� ��ȯ�ϴ� �Լ�
	{
		if (root == nullptr)
		{
			cout << "Ʈ���� ����ֽ��ϴ�." << endl;
			return nullptr;
		}

		return root;
	}

	void Insert(Node* parent, T data)			// ���� �Լ�
	{
		Node* newNode = new Node(data);			// ������ ��� ����

		if (parent == nullptr)			// root ��尡 ������
		{	
			root = newNode;			// ���� ������ ��带 root ���� ����
			return;
		}

		if (parent->data >= data)			// ������ �����Ͱ� �θ� ����� �����ͺ��� �۰ų� ������, �θ� ����� ���ʿ� ����
		{
			if (parent->left == nullptr)				// �θ� ����� ���� ��尡 ���������
			{
				parent->left = newNode;				// �θ� ����� ���� ��带 ���� ������ ���� ����
				parent->left->parent = parent;		// ���� ������ ����� �θ� ��� ����
				return;
			}
			else
			{
				Insert(parent->left, data);			// �θ� ��尡 ������� ������, ���� �ڽ� ���� �������� ���� �Լ� �ݺ� (���)
			}
		}
		else
		{														// ������ �����Ͱ� �θ� ����� �����ͺ��� ũ��, �θ� ����� �����ʿ� ���� (�Ʒ��� ���� ����� ����. '����' ��� '������' �����ϸ� �˴ϴ�.)
			if (parent->right == nullptr)				
			{
				parent->right = newNode;
				parent->right->parent = parent;
				return;
			}
			else
			{
				Insert(parent->right, data);
			}
		}
	}

	Node* FindNode(Node* parent, T data)				// ��� ã�� �Լ� (���� �Լ��� ����ϱ� ���� ����)
	{
		if (parent == nullptr || parent->data == data)						// �θ� ��尡 null�̰ų�, ã�� �����Ͱ� �θ� ����� �����Ͷ��, �θ� ��� ��ȯ
		{
			return parent;
		}

		if (parent->data >= data)							// ã�� �����Ͱ� �θ� ����� �����ͺ��� �۰ų� ������, ���� �ڽ� ���� �������� ��� ã�� �Լ� �ݺ� (���)
		{
			FindNode(parent->left, data);
		}
		else
			FindNode(parent->right, data);						// ã�� �����Ͱ� �θ� ����� �����ͺ��� ũ��, ������ �ڽ� ���� �������� �ݺ�
	}

	void Delete(Node* parent, T data)									// ���� �Լ�
	{
		Node* delNode = FindNode(parent, data);							// ������ ��带 ã��

		if (delNode->left == nullptr && delNode->right == nullptr)				// ������ ��尡 �ڽ� ��带 ������ ���� ���� �� : ������ ��常 �����ָ� ��
		{
			if (delNode->parent->data >= data)				// ������ ��尡 �θ� ����� ���� �ڽ�����, ������ �ڽ����� ã��
			{
				delNode->parent->left = nullptr;			//  �θ� ����� �����ͺ��� �۰ų� ������, ���� �ڽ��� null�� ����
			}
			else
			{
				delNode->parent->right = nullptr;			// �θ� ����� �����ͺ��� ũ��, ������ �ڽ��� null�� ����
			}	
		}
		else if (delNode->left != nullptr && delNode->right != nullptr)				// ������ ��尡 ������, ���� ��� �ڽ��� ���� �� : ���� / ������ ����
		{																											//���� ����Ʈ���� �����ϸ�, ���� ����Ʈ������ �ִ밪�� ã�Ƽ� ������ ��� �ڸ��� �־��ְ� ���� / ������ ����Ʈ���� �����ϸ�, ������ ����Ʈ������ �ּҰ��� ã�Ƽ� ������ ��� �ڸ��� �־��ְ� ����
			Node* head = delNode;											// ������ ��带 �θ� ���� �ΰ�
			Node* max = delNode->left;										// ���� ����Ʈ���� �����Ͽ�, �ִ밪 ã�� ��.

			do
			{
				if (max->right == nullptr)				// ���� ����Ʈ������ �ִ밪�� ã�� (������ �ڽ��� ���� ��尡 �ִ밪)
					break;

				head = max;									// Ʈ���� �������鼭 �ִ밪 ã��
				max = max->right;						// ������ �ڽ� ��尡 ū ���̴ϱ�, ������ �ڽ� ���� ������
			} while (true);

			if (max->left != nullptr)									// �ִ밪 ����� ���� �ڽ��� �ִٸ�
			{
				head->right = max->left;							// �ִ밪 ����� �θ� ����� ������ �ڽ����� �ִ밪 ����� ���� �ڽ��� ����
			}
			else
			{																// ���� �ڽ��� ���ٸ�
				if (head->left == max)							// �ִ밪 ��尡 �θ� ����� ���� �ڽ��̶��
				{
					head->left = nullptr;							// �θ� ����� ���� �ڽ��� null�� ����
				}
				else
					head->right = nullptr;				// �θ� ����� ���� �ڽ��� �ƴ϶��, ������ �ڽ��� null�� ����
			}
			delNode->data = max->data;			// ������ ����� �����Ϳ� �ִ밪 �־��ְ�
			delNode = max;								// ������ ���� �ִ밪 ���� ����
		}
		else
		{														// ���� �ڽ� / ������ �ڽ� �� �� �ϳ��� �ִٸ�
			Node* childNode = (delNode->left != nullptr) ? delNode->left : delNode->right;					// �ڽ� ��尡 �������� ���������� ã��

			if (delNode->parent->data >= data)								// ������ ��尡 �θ��� �����ͺ��� �۰ų� ���ٸ�, �θ� ����� ���ʿ� ������ ����� �ڽ��� �־���
			{
				delNode->parent->left = childNode;
			}
			else
			{																				// ������ ��尡 �θ��� �����ͺ��� ũ��, �θ� ����� �������� ������ ����� �ڽ��� �־���
				delNode->parent->right = childNode;
			}
			childNode->parent = delNode->parent;				// ������ ����� �ڽ� ����� �θ� ������ ����� �θ�� ����
		}

		cout << "\nDelete : " << data;
		delNode->parent = nullptr;							// ������ ����� �θ�  null ����
		delete delNode;										// ��� ����
		delNode = nullptr;

	}

	// ���� ��ȸ
	void PreOrder(Node* root)
	{
		if (root == nullptr) return;

		cout << root->data << "->";

		if (root->left != nullptr)
		{
			PreOrder(root->left);
		}

		if (root->right != nullptr)
		{
			PreOrder(root->right);
		}
	}

	// ���� ��ȸ
	void InOrder(Node* root)
	{
		if (root == nullptr) return;

		if (root->left != nullptr)
		{
			InOrder(root->left);
		}

		cout << root->data << "->";

		if (root->right != nullptr)
		{
			InOrder(root->right);
		}
	}

	// ���� ��ȸ
	void PostOrder(Node* root)
	{
		if (root == nullptr) return;

		if (root->left != nullptr)
		{
			PostOrder(root->left);
		}

		if (root->right != nullptr)
		{
			PostOrder(root->right);
		}

		cout << root->data << "->";
	}
};


int main()
{
	BST<int> bst;
	bst.Insert(bst.Root(), 10);
	bst.Insert(bst.Root(), 6);
	bst.Insert(bst.Root(), 3);
	bst.Insert(bst.Root(), 5);
	bst.Insert(bst.Root(), 8);
	bst.Insert(bst.Root(), 4);

	bst.PreOrder(bst.Root());
	cout << endl;
	bst.InOrder(bst.Root());
	cout << endl;
	bst.PostOrder(bst.Root());

	bst.Delete(bst.Root(), 6);
	cout << endl;
	bst.InOrder(bst.Root());
}
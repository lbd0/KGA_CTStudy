#include <iostream>
#include <vector>

using namespace std;

template<typename T>
struct Node
{
	T data;
	Node* parent;
	Node* leftNode;
	Node* rightNode;

	Node() : parent(nullptr), leftNode(nullptr), rightNode(nullptr) { }
	Node(T data) : data(data), parent(nullptr), leftNode(nullptr), rightNode(nullptr) {}
	Node(T data, Node<T>* parentNode) : data(data), parent(parentNode), leftNode(nullptr), rightNode(nullptr) {}
};

template <class T>
class BinaryTree
{
public:
	BinaryTree() : root(nullptr) {}
	BinaryTree(T data) {
		Node<T>* newNode = new Node<T>(data);
		root = newNode;
	}

	/// <summary>
	/// Ʈ���� �� ����
	/// </summary>
	/// <param name="insertData">������ ��</param>
	void insert(T insertData) {
		if (root == nullptr) {
			Node<T>* newNode = new Node<T>(insertData);
			root = newNode;
		}
		else {
			Node<T>* checkNode = root;
			while (true) {
				if (checkNode->data >= insertData) {
					if (checkNode->leftNode == nullptr) {
						Node<T>* newNode = new Node<T>(insertData, checkNode);
						checkNode->leftNode = newNode;
						break;
					}
					else {
						checkNode = checkNode->leftNode;
					}
				}
				else {
					if (checkNode->rightNode == nullptr) {
						Node<T>* newNode = new Node<T>(insertData, checkNode);
						checkNode->rightNode = newNode;
						break;
					}
					else {
						checkNode = checkNode->rightNode;
					}
				}
			}
		}
	}

	/// <summary>
	/// ���� ��ȸ
	/// </summary>
	void preorder() {

		cout << "���� ��ȸ : ";

		if (root == nullptr) {
			return;
		}

		preorder(root);

		cout << endl;
	}

	/// <summary>
	/// ���� ��ȸ
	/// </summary>
	void inorder() {
		cout << "���� ��ȸ : ";

		if (root == nullptr) {
			return;
		}

		inorder(root);

		cout << endl;
	}

	/// <summary>
	/// ���� ��ȸ
	/// </summary>
	void postorder() {

		cout << "���� ��ȸ : ";

		if (root == nullptr) {
			return;
		}

		postorder(root);

		cout << endl;
	}

	/// <summary>
	/// Ʈ���� �ش� ���� �ִ��� Ȯ���ϴ� �Լ�
	/// </summary>
	/// <param name="findData">Ȯ���� ��</param>
	/// <returns>������ �� ����� �ּҸ� ������ nullptr�� ��ȯ��</returns>
	Node<T>* findNode(T findData)
	{
		Node<T>* resultNode;
		resultNode = findNode(root, findData);

		return resultNode;
	}

	void erase(T eraseData) {
		Node<T>* eraseNode = findNode(eraseData);
		if (eraseNode == nullptr) {
			cout << "�����ҷ��� ���� ����" << endl;
		}
		else {
			if (eraseNode->leftNode == nullptr && eraseNode->rightNode == nullptr) {
				// �� ��� �� ���
				if (eraseNode->parent == nullptr) {
					// �θ� ����ִ� ���� ��Ʈ ���ۿ� ����
					root == nullptr;
					delete eraseNode;
				}
				else {
					Node<T>* parentNode = eraseNode->parent;
					if (parentNode->leftNode == eraseNode) {
						// �����ҷ��� ��尡 �θ��� ���� ����� ���
						parentNode->leftNode == nullptr;
						delete eraseNode;
					}
					else {
						// �����ҷ��� ��尡 �θ��� ������ ����� ��� 
						parentNode->rightNode == nullptr;
						delete eraseNode;
					}
				}
			}
			else if (eraseNode->leftNode != nullptr && eraseNode->rightNode == nullptr) {
				// ������ ��常 ��� �ִ� �����
				if (eraseNode->parent == nullptr) {
					// �θ� ����ִ� ���� ��Ʈ ���ۿ� ����
					root == eraseNode->leftNode;
					delete eraseNode;
				}
				else {
					Node<T>* parentNode = eraseNode->parent;
					if (parentNode->leftNode == eraseNode) {
						// �����ҷ��� ��尡 �θ��� ���� ����� ���
						parentNode->leftNode = eraseNode->leftNode;
						eraseNode->leftNode->parent = parentNode;
						delete eraseNode;
					}
					else {
						// �����ҷ��� ��尡 �θ��� ������ ����� ��� 
						parentNode->rightNode = eraseNode->leftNode;
						eraseNode->leftNode->parent = parentNode;
						delete eraseNode;
					}
				}
			}
			else if (eraseNode->leftNode == nullptr && eraseNode->rightNode != nullptr) {
				// ���� ��常 ��� �ִ� �����
				if (eraseNode->parent == nullptr) {
					// �θ� ����ִ� ���� ��Ʈ ���ۿ� ����
					root == eraseNode->rightNode;
					delete eraseNode;
				}
				else {
					Node<T>* parentNode = eraseNode->parent;
					if (parentNode->leftNode == eraseNode) {
						// �����ҷ��� ��尡 �θ��� ���� ����� ���
						parentNode->leftNode = eraseNode->rightNode;
						eraseNode->rightNode->parent = parentNode;
						delete eraseNode;
					}
					else {
						// �����ҷ��� ��尡 �θ��� ������ ����� ��� 
						parentNode->rightNode = eraseNode->rightNode;
						eraseNode->rightNode->parent = parentNode;
						delete eraseNode;
					}
				}
			}
			else if (eraseNode->leftNode != nullptr && eraseNode->rightNode != nullptr) {
				// �Ѵ� ����ִ� ��尡 �ƴ϶��
				Node<T>* replaceNode = findMinNode(eraseNode->rightNode);
				if (eraseNode == root) {
					replaceNode->leftNode == root->leftNode;
					replaceNode->rightNode == root->rightNode;
					if (replaceNode->parent->leftNode == replaceNode) {
						replaceNode->parent->leftNode = nullptr;
					}
					else {
						replaceNode->parent->rightNode = nullptr;
					}
					root = replaceNode;
					replaceNode->parent = nullptr;
				}
				else {
					if (replaceNode->parent->leftNode == replaceNode) {
						replaceNode->parent->leftNode == nullptr;
					}
					else {
						replaceNode->parent->rightNode == nullptr;
					}

					replaceNode->parent = eraseNode->parent;
					replaceNode->leftNode = eraseNode->leftNode;
					replaceNode->rightNode = eraseNode->rightNode;
				}
				
				delete eraseNode;
			}
		}

		

	}

private:
	Node<T>* root;

	void preorder(Node<T>* checkNode) {
		if (checkNode == nullptr) {
			return;
		}

		cout << checkNode->data << " ";

		if (checkNode->leftNode != nullptr) {
			preorder(checkNode->leftNode);
		}

		if (checkNode->rightNode != nullptr) {
			preorder(checkNode->rightNode);
		}
	}

	void inorder(Node<T>* checkNode) {
		if (checkNode->leftNode != nullptr) {
			inorder(checkNode->leftNode);
		}

		cout << checkNode->data << " ";

		if (checkNode->rightNode != nullptr) {
			inorder(checkNode->rightNode);
		}
	}

	void postorder(Node<T>* checkNode) {
		if (checkNode->leftNode != nullptr) {
			postorder(checkNode->leftNode);
		}

		if (checkNode->rightNode != nullptr) {
			postorder(checkNode->rightNode);
		}

		cout << checkNode->data << " ";
	}

	Node<T>* findNode(Node<T>* checkNode, T findData) {
		if (checkNode->data == findData) {
			return checkNode;
		}
		else {
			Node<T>* resultNode;
			if (checkNode->leftNode != nullptr) {
				resultNode = findNode(checkNode->leftNode, findData);
				if (resultNode != nullptr) {
					return resultNode;
				}
			}
			if (checkNode->rightNode != nullptr) {
				resultNode = findNode(checkNode->rightNode, findData);

				if (resultNode != nullptr) {
					return resultNode;
				}
			}
		}

		return nullptr;
	}

	/// <summary>
	/// ����Ʈ������ ���� ���� ���� ������ �ִ� ��带 ��ȯ�ϴ� �Լ�
	/// </summary>
	/// <param name="subTreeRootNode">����Ʈ���� root ��尡 �� ���</param>
	/// <returns>���� ���� ���� ���</returns>
	Node<T>* findMinNode(Node<T>* subTreeRootNode) {
		if (subTreeRootNode->leftNode == nullptr)
		{
			return subTreeRootNode;
		}
		else {
			return findMinNode(subTreeRootNode->leftNode);
		}
	}
};

int main() {
	BinaryTree<int> testTree = BinaryTree<int>(50);

	testTree.insert(25);
	testTree.insert(12);
	testTree.insert(40);
	testTree.insert(75);
	testTree.insert(60);
	testTree.insert(80);
	testTree.insert(100);
	testTree.insert(3);

	testTree.preorder();
	testTree.inorder();
	testTree.postorder();

	if (testTree.findNode(80) != nullptr) {
		cout << "�� ����" << endl;
	}
	else {
		cout << "�� ����" << endl;
	}

	if (testTree.findNode(33) != nullptr) {
		cout << testTree.findNode(30)->data << endl;
	}
	else {
		cout << "�� ����" << endl;
	}

	testTree.erase(33);

	testTree.erase(3);
	testTree.preorder();


	testTree.erase(50);
	testTree.preorder();
}


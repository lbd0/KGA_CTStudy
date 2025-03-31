#include <iostream>
#include <vector>

using namespace std;

template<typename T>
struct Node
{
	T data;				// ��忡 �� ������
	Node* parent;		// ����� �θ�
	Node* leftNode;		// ����� ����
	Node* rightNode;	// ����� ������

	Node() : parent(nullptr), leftNode(nullptr), rightNode(nullptr) { }												// �ܼ� ��� ����
	Node(T data) : data(data), parent(nullptr), leftNode(nullptr), rightNode(nullptr) {}							// ��忡 �����͸� �� ��� ���� (�θ� ��� �� �����͸� �� ��� ������)
	Node(T data, Node<T>* parentNode) : data(data), parent(parentNode), leftNode(nullptr), rightNode(nullptr) {}	// ��忡 �����Ϳ� �θ� �� ��� ����(�� ��� ������)
};

template <class T>
class BinaryTree
{
public:
	BinaryTree() : root(nullptr) {}						// �ƹ� �͵� �� ������ root�� nullptr�� ��
	BinaryTree(T data) {		
		Node<T>* newNode = new Node<T>(data);			// ��忡 �����͸� �����鼭 �����ϸ� root�� ��尡 ����
		root = newNode;
	}

	/// <summary>
	/// Ʈ���� �� ����
	/// </summary>
	/// <param name="insertData">������ ��</param>
	void insert(T insertData) {
		if (root == nullptr) {
			// ��Ʈ�� nullptr�̸� ���� ����
			Node<T>* newNode = new Node<T>(insertData);
			root = newNode;
		}
		else {
			// ��Ʈ���� ���ǿ� ���� ���� �������� �̵��ϸ鼭 �� ���� ��� ����
			Node<T>* checkNode = root;
			while (true) {
				if (checkNode->data >= insertData) {
					// üũ�� ��忡 �ִ� �����ͺ��� �۰ų� ���� �����Ͷ��
					if (checkNode->leftNode == nullptr) {
						// ���� ��尡 ��������� ���� ��忡 �� ��带 �����ϰ� ���� �� �ݺ� ����
						Node<T>* newNode = new Node<T>(insertData, checkNode);
						checkNode->leftNode = newNode;
						break;
					}
					else {
						// ���� ��尡 �� �ִٸ� üũ ��带 �������� ���� �ٲٰ� �ݺ���
						checkNode = checkNode->leftNode;
					}
				}
				else {
					if (checkNode->rightNode == nullptr) {
						// ������ ��尡 ��������� ���� ��忡 �� ��带 �����ϰ� ���� �� �ݺ� ����
						Node<T>* newNode = new Node<T>(insertData, checkNode);
						checkNode->rightNode = newNode;
						break;
					}
					else {
						// ������ ��尡 �� �ִٸ� üũ ��带 �������� ���� �ٲٰ� �ݺ���
						checkNode = checkNode->rightNode;
					}
				}
			}
		}
	}

	/// <summary>
	/// ���� ��ȸ
	/// ��¥ ���� ��ȸ�� �ƴϰ� �׳� ��Ÿ���ֱ� ���� ���� ��ȸ��
	/// </summary>
	void preorder() {

		cout << "���� ��ȸ : ";

		if (root == nullptr) {
			cout << "��Ʈ�� ����" << endl;
			return;
		}

		preorder(root);

		cout << endl;
	}

	/// <summary>
	/// ���� ��ȸ
	/// ��¥ ���� ��ȸ�� �ƴϰ� �׳� ��Ÿ���ֱ� ���� ���� ��ȸ��
	/// </summary>
	void inorder() {
		cout << "���� ��ȸ : ";

		if (root == nullptr) {
			cout << "��Ʈ�� ����" << endl;
			return;
		}

		inorder(root);

		cout << endl;
	}

	/// <summary>
	/// ���� ��ȸ
	/// ��¥ ���� ��ȸ�� �ƴϰ� �׳� ��Ÿ���ֱ� ���� ���� ��ȸ��
	/// </summary>
	void postorder() {

		cout << "���� ��ȸ : ";

		if (root == nullptr) {
			cout << "��Ʈ�� ����" << endl;
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

	/// <summary>
	/// �����͸� �����ϴ� �Լ��̴�
	/// �����͸� �����ϴ� ���� 3���� ��찡 �ִ�
	/// 1. �� ��带 �����ϴ� ���
	/// 2. �����Ϸ��� ��尡 �����̳� ������ ���� Ʈ�� �� �ϳ��� ������ �ִ� ���
	/// 3. �����Ϸ��� ��尡 ���ʰ� ������ ���� Ʈ���� ��� ������ �ִ� ���
	/// </summary>
	/// <param name="eraseData">������ ��</param>
	void erase(T eraseData) {
		Node<T>* eraseNode = findNode(eraseData);
		if (eraseNode == nullptr) {
			// �����ҷ��� ���� Ʈ���� ����
			cout << "�����ҷ��� ���� ����" << endl;
		}
		else {
			if (eraseNode->leftNode == nullptr && eraseNode->rightNode == nullptr) {
				// 1. �� ��带 �����ϴ� ��� (���� ���� Ʈ��, ������ ���� Ʈ���� ���� �����̴�)
				if (eraseNode->parent == nullptr) {
					// �θ� ����ִ� ���� ��Ʈ ���ۿ� ����
					root = nullptr;
					delete eraseNode;
				}
				else {
					Node<T>* parentNode = eraseNode->parent;
					if (parentNode->leftNode == eraseNode) {
						// �����ҷ��� ��尡 �θ��� ���� ����� ���
						parentNode->leftNode = nullptr;
						delete eraseNode;
					}
					else {
						// �����ҷ��� ��尡 �θ��� ������ ����� ��� 
						parentNode->rightNode = nullptr;
						delete eraseNode;
					}
				}
			}
			else if (eraseNode->leftNode != nullptr && eraseNode->rightNode == nullptr) {
				// ������ ����Ʈ���� ��� �ִ� �����
				if (eraseNode->parent == nullptr) {
					// �θ� ����ִ� ���� ��Ʈ ���ۿ� ����
					root = eraseNode->leftNode;
					delete eraseNode;
				}
				else {
					Node<T>* parentNode = eraseNode->parent;			// �����ҷ��� ����� �θ� ���
					if (parentNode->leftNode == eraseNode) {
						// �����ҷ��� ��尡 �θ��� ���� ����� ���
						parentNode->leftNode = eraseNode->leftNode;		// �θ��� ���� ��带 ������ ����� ���� ���� ����
						eraseNode->leftNode->parent = parentNode;		// ������ ����� ���� ����� �θ� ������ ����� �θ� ���� ����
						delete eraseNode;
					}
					else {
						// �����ҷ��� ��尡 �θ��� ������ ����� ��� 
						parentNode->rightNode = eraseNode->leftNode;	// �θ��� ������ ��带 ������ ����� ���� ���� ����
						eraseNode->leftNode->parent = parentNode;		// ������ ����� ���� ����� �θ� ������ ����� �θ� ���� ����
						delete eraseNode;
					}
				}
			}
			else if (eraseNode->leftNode == nullptr && eraseNode->rightNode != nullptr) {
				// ���� ��常 ��� �ִ� �����
				if (eraseNode->parent == nullptr) {
					// �θ� ����ִ� ���� ��Ʈ ���ۿ� ����
					root = eraseNode->rightNode;
					delete eraseNode;
				}
				else {
					Node<T>* parentNode = eraseNode->parent;			// �����ҷ��� ����� �θ� ���
					if (parentNode->leftNode == eraseNode) {
						// �����ҷ��� ��尡 �θ��� ���� ����� ���
						parentNode->leftNode = eraseNode->rightNode;	// �θ��� ���� ��带 ������ ����� ������ ���� ����
						eraseNode->rightNode->parent = parentNode;		// ������ ����� ������ ����� �θ� ������ ����� �θ� ���� ����
						delete eraseNode;
					}
					else {
						// �����ҷ��� ��尡 �θ��� ������ ����� ��� 
						parentNode->rightNode = eraseNode->rightNode;	// �θ��� ������ ��带 ������ ����� ������ ���� ����
						eraseNode->rightNode->parent = parentNode;		// ������ ����� ������ ����� �θ� ������ ����� �θ� ���� ����
						delete eraseNode;
					}
				}
			}
			else if (eraseNode->leftNode != nullptr && eraseNode->rightNode != nullptr) {
				// �Ѵ� ����ִ� ��尡 �ƴ϶��
				// �ΰ��� ����� �ֽ��ϴ�
				// 1. ���� ����Ʈ������ ���� ū ���� ���� ���� ��ü�Ѵ�
				// 2. ������ ���� Ʈ������ ���� ���� ���� ���� ���� ��ü�Ѵ� �Դϴ�
				// 1���̵� 2���̵� �ݵ�� �� ��� �Դϴ�
				// ���� ���⼭ 2���� ����Ͽ����ϴ�
				Node<T>* replaceNode = findMinNode(eraseNode);			// ������ ���� Ʈ������ ���� ���� ���� ������ �ִ� ����� �ּҸ� ��ü ��� ������ ����
				if (eraseNode == root) {
					// ���� ���� ��尡 ��Ʈ���
					replaceNode->leftNode == root->leftNode;				// ��ü�� ����� ���� ��带 ��Ʈ�� ���� ����
					replaceNode->rightNode == root->rightNode;				// ��ü�� ����� ������ ��带 ��Ʈ�� ������ ����
					if (replaceNode->parent->leftNode == replaceNode) {		
						// ��ü�� ��尡 ���� �θ��� ���� ���� �θ��� ���� ��带 nullptr�� �ٲ�
						replaceNode->parent->leftNode = nullptr;
					}
					else {
						// ��ü�� ��尡 ���� �θ��� ������ ���� �θ��� ������ ��带 nullptr�� �ٲ�
						replaceNode->parent->rightNode = nullptr;
					}
					root = replaceNode;				// ��Ʈ ����
					replaceNode->parent = nullptr;	// �θ� ����(���ر���)
				}
				else {
					// ���� ��尡 ��Ʈ�� �ƴϸ�
					if (replaceNode->parent->leftNode == replaceNode) {
						// ��ü�� ��尡 ���� �θ��� ���� ���� �θ��� ���� ��带 nullptr�� �ٲ�
						replaceNode->parent->leftNode = nullptr;
					}
					else {
						// ��ü�� ��尡 ���� �θ��� ������ ���� �θ��� ������ ��带 nullptr�� �ٲ�
						replaceNode->parent->rightNode = nullptr;
					}

					if (eraseNode->parent->rightNode == eraseNode) {
						//������ ��尡 ������ �θ� ����� ������ ����
						eraseNode->parent->rightNode = replaceNode;		// �ڽ� �ٲ�
					}
					else {
						//������ ��尡 ������ �θ� ����� ���� ����
						eraseNode->parent->leftNode = replaceNode;		// �ڽ� �ٲ�
					}


					replaceNode->parent = eraseNode->parent;			// ��ü�� ����� �θ� ���� ����� �θ��
					replaceNode->leftNode = eraseNode->leftNode;		// ��ü�� ����� ���� ��带 ���� ����� ���� ����
					replaceNode->rightNode = eraseNode->rightNode;		// ��ü�� ����� ������ ��带 ���� ����� ������ ����
				}
				
				delete eraseNode;		// ��� ����
			}
		}

		

	}

private:
	Node<T>* root;

	void preorder(Node<T>* checkNode) {
		if (checkNode == nullptr) {
			// üũ ��尡 nullptr�̸� ����
			return;
		}
	
		cout << checkNode->data << " ";		// ������ ���

		if (checkNode->leftNode != nullptr) {
			// ���� ��尡 nullptr�� �ƴϸ� ��� ����
			preorder(checkNode->leftNode);
		}

		if (checkNode->rightNode != nullptr) {
			// ������ ��尡 nullptr�� �ƴϸ� ��� ����
			preorder(checkNode->rightNode);
		}
	}

	void inorder(Node<T>* checkNode) {
		if (checkNode->leftNode != nullptr) {
			// ���� ��尡 nullptr�� �ƴϸ� ��� ����
			inorder(checkNode->leftNode);
		}

		cout << checkNode->data << " ";		// ������ ���

		if (checkNode->rightNode != nullptr) {
			// ������ ��尡 nullptr�� �ƴϸ� ��� ����
			inorder(checkNode->rightNode);
		}
	}

	void postorder(Node<T>* checkNode) {
		if (checkNode->leftNode != nullptr) {
			// ���� ��尡 nullptr�� �ƴϸ� ��� ����
			postorder(checkNode->leftNode);
		}

		if (checkNode->rightNode != nullptr) {
			// ������ ��尡 nullptr�� �ƴϸ� ��� ����
			postorder(checkNode->rightNode);
		}

		cout << checkNode->data << " ";		// ������ ���
	}

	Node<T>* findNode(Node<T>* checkNode, T findData) {
		if (checkNode->data == findData) {
			// üũ ����� �����Ͱ� ã�� �����Ͷ� ������ üũ ����� �ּҸ� ��ȯ�Ѵ�
			return checkNode;
		}
		else {
			// üũ ����� �����Ͱ� ã�� �����Ͷ� �ٸ��� ���� ���� ������ ���캻�� ���� ��忡 ������ ������ ��带 ���캻��
			// ��� �� ����� ���� �ʴ� checkNode�� �����Ϳ� findData�� ���ϸ� ��� ��带 ã�ƾ� �ϴ��� �� �� �ֱ� �����̴�
			// ������ �����Ͱ� �׻� int�� float���� ���ϱ� ���� �������� �ƴ� �� �� �ֱ⿡ �ش� ����� ���� �ʾҴ�
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

		return nullptr;	// ���� ã�� �����Ͱ� ������ nullptr�� ��ȯ�Ѵ�
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

	//testTree.insert(25);
	//testTree.preorder();
	//testTree.erase(25);
	//testTree.preorder();
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
	testTree.preorder();
	testTree.erase(3);
	cout << "3�� ���� ���� ";
	testTree.preorder();

	testTree.erase(12);
	cout << "12�� ���� ���� ";
	testTree.preorder();

	testTree.erase(75);
	cout << "75�� ���� ���� ";
	testTree.preorder();


	//testTree.erase(50);
	//testTree.preorder();
}


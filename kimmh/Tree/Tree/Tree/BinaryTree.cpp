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
	/// 트리에 값 삽입
	/// </summary>
	/// <param name="insertData">삽입할 값</param>
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
	/// 전위 순회
	/// </summary>
	void preorder() {

		cout << "전위 순회 : ";

		if (root == nullptr) {
			return;
		}

		preorder(root);

		cout << endl;
	}

	/// <summary>
	/// 중위 순회
	/// </summary>
	void inorder() {
		cout << "중위 순회 : ";

		if (root == nullptr) {
			return;
		}

		inorder(root);

		cout << endl;
	}

	/// <summary>
	/// 후위 순회
	/// </summary>
	void postorder() {

		cout << "후위 순회 : ";

		if (root == nullptr) {
			return;
		}

		postorder(root);

		cout << endl;
	}

	/// <summary>
	/// 트리에 해당 값이 있는지 확인하는 함수
	/// </summary>
	/// <param name="findData">확인할 값</param>
	/// <returns>있으면 그 노드의 주소를 없으면 nullptr을 반환함</returns>
	Node<T>* findNode(T findData)
	{
		Node<T>* resultNode;
		resultNode = findNode(root, findData);

		return resultNode;
	}

	void erase(T eraseData) {
		Node<T>* eraseNode = findNode(eraseData);
		if (eraseNode == nullptr) {
			cout << "삭제할려는 값이 없음" << endl;
		}
		else {
			if (eraseNode->leftNode == nullptr && eraseNode->rightNode == nullptr) {
				// 잎 노드 일 경우
				if (eraseNode->parent == nullptr) {
					// 부모가 비어있는 경우는 루트 노드밖에 없음
					root == nullptr;
					delete eraseNode;
				}
				else {
					Node<T>* parentNode = eraseNode->parent;
					if (parentNode->leftNode == eraseNode) {
						// 삭제할려는 노드가 부모의 왼쪽 노드일 경우
						parentNode->leftNode == nullptr;
						delete eraseNode;
					}
					else {
						// 삭제할려는 노드가 부모의 오른쪽 노드일 경우 
						parentNode->rightNode == nullptr;
						delete eraseNode;
					}
				}
			}
			else if (eraseNode->leftNode != nullptr && eraseNode->rightNode == nullptr) {
				// 오른쪽 노드만 비어 있는 노드라면
				if (eraseNode->parent == nullptr) {
					// 부모가 비어있는 경우는 루트 노드밖에 없음
					root == eraseNode->leftNode;
					delete eraseNode;
				}
				else {
					Node<T>* parentNode = eraseNode->parent;
					if (parentNode->leftNode == eraseNode) {
						// 삭제할려는 노드가 부모의 왼쪽 노드일 경우
						parentNode->leftNode = eraseNode->leftNode;
						eraseNode->leftNode->parent = parentNode;
						delete eraseNode;
					}
					else {
						// 삭제할려는 노드가 부모의 오른쪽 노드일 경우 
						parentNode->rightNode = eraseNode->leftNode;
						eraseNode->leftNode->parent = parentNode;
						delete eraseNode;
					}
				}
			}
			else if (eraseNode->leftNode == nullptr && eraseNode->rightNode != nullptr) {
				// 왼쪽 노드만 비어 있는 노드라면
				if (eraseNode->parent == nullptr) {
					// 부모가 비어있는 경우는 루트 노드밖에 없음
					root == eraseNode->rightNode;
					delete eraseNode;
				}
				else {
					Node<T>* parentNode = eraseNode->parent;
					if (parentNode->leftNode == eraseNode) {
						// 삭제할려는 노드가 부모의 왼쪽 노드일 경우
						parentNode->leftNode = eraseNode->rightNode;
						eraseNode->rightNode->parent = parentNode;
						delete eraseNode;
					}
					else {
						// 삭제할려는 노드가 부모의 오른쪽 노드일 경우 
						parentNode->rightNode = eraseNode->rightNode;
						eraseNode->rightNode->parent = parentNode;
						delete eraseNode;
					}
				}
			}
			else if (eraseNode->leftNode != nullptr && eraseNode->rightNode != nullptr) {
				// 둘다 비어있는 노드가 아니라면
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
	/// 서브트리에서 가장 작은 값을 가지고 있는 노드를 반환하는 함수
	/// </summary>
	/// <param name="subTreeRootNode">서브트리의 root 노드가 될 노드</param>
	/// <returns>가장 작은 값인 노드</returns>
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
		cout << "값 있음" << endl;
	}
	else {
		cout << "값 없음" << endl;
	}

	if (testTree.findNode(33) != nullptr) {
		cout << testTree.findNode(30)->data << endl;
	}
	else {
		cout << "값 없음" << endl;
	}

	testTree.erase(33);

	testTree.erase(3);
	testTree.preorder();


	testTree.erase(50);
	testTree.preorder();
}


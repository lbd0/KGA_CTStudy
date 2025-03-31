#include <iostream>
#include <vector>

using namespace std;

template<typename T>
struct Node
{
	T data;				// 노드에 들어갈 데이터
	Node* parent;		// 노드의 부모
	Node* leftNode;		// 노드의 왼쪽
	Node* rightNode;	// 노드의 오른쪽

	Node() : parent(nullptr), leftNode(nullptr), rightNode(nullptr) { }												// 단순 노드 생성
	Node(T data) : data(data), parent(nullptr), leftNode(nullptr), rightNode(nullptr) {}							// 노드에 데이터만 들어간 노드 생성 (부모 노드 및 데이터만 들어간 노드 생성용)
	Node(T data, Node<T>* parentNode) : data(data), parent(parentNode), leftNode(nullptr), rightNode(nullptr) {}	// 노드에 데이터와 부모가 들어간 노드 생성(잎 노드 생성용)
};

template <class T>
class BinaryTree
{
public:
	BinaryTree() : root(nullptr) {}						// 아무 것도 안 넣으면 root에 nullptr이 들어감
	BinaryTree(T data) {		
		Node<T>* newNode = new Node<T>(data);			// 노드에 데이터를 넣으면서 생성하면 root에 노드가 생성
		root = newNode;
	}

	/// <summary>
	/// 트리에 값 삽입
	/// </summary>
	/// <param name="insertData">삽입할 값</param>
	void insert(T insertData) {
		if (root == nullptr) {
			// 루트가 nullptr이면 새로 생성
			Node<T>* newNode = new Node<T>(insertData);
			root = newNode;
		}
		else {
			// 루트부터 조건에 따라 좌측 우측으로 이동하면서 빈 곳에 노드 생성
			Node<T>* checkNode = root;
			while (true) {
				if (checkNode->data >= insertData) {
					// 체크할 노드에 있는 데이터보다 작거나 같은 데이터라면
					if (checkNode->leftNode == nullptr) {
						// 왼쪽 노드가 비어있으면 왼쪽 노드에 새 노드를 생성하고 넣은 뒤 반복 종료
						Node<T>* newNode = new Node<T>(insertData, checkNode);
						checkNode->leftNode = newNode;
						break;
					}
					else {
						// 왼쪽 노드가 차 있다면 체크 노드를 왼쪽으로 노드로 바꾸고 반복함
						checkNode = checkNode->leftNode;
					}
				}
				else {
					if (checkNode->rightNode == nullptr) {
						// 오른쪽 노드가 비어있으면 왼쪽 노드에 새 노드를 생성하고 넣은 뒤 반복 종료
						Node<T>* newNode = new Node<T>(insertData, checkNode);
						checkNode->rightNode = newNode;
						break;
					}
					else {
						// 오른쪽 노드가 차 있다면 체크 노드를 왼쪽으로 노드로 바꾸고 반복함
						checkNode = checkNode->rightNode;
					}
				}
			}
		}
	}

	/// <summary>
	/// 전위 순회
	/// 진짜 전위 순회는 아니고 그냥 나타내주기 위한 전위 순회임
	/// </summary>
	void preorder() {

		cout << "전위 순회 : ";

		if (root == nullptr) {
			cout << "루트가 없음" << endl;
			return;
		}

		preorder(root);

		cout << endl;
	}

	/// <summary>
	/// 중위 순회
	/// 진짜 중위 순회는 아니고 그냥 나타내주기 위한 중위 순회임
	/// </summary>
	void inorder() {
		cout << "중위 순회 : ";

		if (root == nullptr) {
			cout << "루트가 없음" << endl;
			return;
		}

		inorder(root);

		cout << endl;
	}

	/// <summary>
	/// 후위 순회
	/// 진짜 후위 순회는 아니고 그냥 나타내주기 위한 후위 순회임
	/// </summary>
	void postorder() {

		cout << "후위 순회 : ";

		if (root == nullptr) {
			cout << "루트가 없음" << endl;
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

	/// <summary>
	/// 데이터를 삭제하는 함수이다
	/// 데이터를 삭제하는 경우는 3가지 경우가 있다
	/// 1. 잎 노드를 삭제하는 경우
	/// 2. 삭제하려는 노드가 왼쪽이나 오른쪽 서브 트리 중 하나만 가지고 있는 경우
	/// 3. 삭제하려는 노드가 왼쪽과 오른쪽 서브 트리를 모두 가지고 있는 경우
	/// </summary>
	/// <param name="eraseData">삭제할 값</param>
	void erase(T eraseData) {
		Node<T>* eraseNode = findNode(eraseData);
		if (eraseNode == nullptr) {
			// 삭제할려는 값이 트리에 없음
			cout << "삭제할려는 값이 없음" << endl;
		}
		else {
			if (eraseNode->leftNode == nullptr && eraseNode->rightNode == nullptr) {
				// 1. 잎 노드를 삭제하는 경우 (왼쪽 서브 트리, 오른쪽 서브 트리가 없는 상태이다)
				if (eraseNode->parent == nullptr) {
					// 부모가 비어있는 경우는 루트 노드밖에 없음
					root = nullptr;
					delete eraseNode;
				}
				else {
					Node<T>* parentNode = eraseNode->parent;
					if (parentNode->leftNode == eraseNode) {
						// 삭제할려는 노드가 부모의 왼쪽 노드일 경우
						parentNode->leftNode = nullptr;
						delete eraseNode;
					}
					else {
						// 삭제할려는 노드가 부모의 오른쪽 노드일 경우 
						parentNode->rightNode = nullptr;
						delete eraseNode;
					}
				}
			}
			else if (eraseNode->leftNode != nullptr && eraseNode->rightNode == nullptr) {
				// 오른쪽 서브트리만 비어 있는 노드라면
				if (eraseNode->parent == nullptr) {
					// 부모가 비어있는 경우는 루트 노드밖에 없음
					root = eraseNode->leftNode;
					delete eraseNode;
				}
				else {
					Node<T>* parentNode = eraseNode->parent;			// 삭제할려는 노드의 부모 노드
					if (parentNode->leftNode == eraseNode) {
						// 삭제할려는 노드가 부모의 왼쪽 노드일 경우
						parentNode->leftNode = eraseNode->leftNode;		// 부모의 왼쪽 노드를 삭제할 노드의 왼쪽 노드로 변경
						eraseNode->leftNode->parent = parentNode;		// 삭제할 노드의 왼쪽 노드의 부모를 삭제할 노드의 부모 노드로 변경
						delete eraseNode;
					}
					else {
						// 삭제할려는 노드가 부모의 오른쪽 노드일 경우 
						parentNode->rightNode = eraseNode->leftNode;	// 부모의 오른쪽 노드를 삭제할 노드의 왼쪽 노드로 변경
						eraseNode->leftNode->parent = parentNode;		// 삭제할 노드의 왼쪽 노드의 부모를 삭제할 노드의 부모 노드로 변경
						delete eraseNode;
					}
				}
			}
			else if (eraseNode->leftNode == nullptr && eraseNode->rightNode != nullptr) {
				// 왼쪽 노드만 비어 있는 노드라면
				if (eraseNode->parent == nullptr) {
					// 부모가 비어있는 경우는 루트 노드밖에 없음
					root = eraseNode->rightNode;
					delete eraseNode;
				}
				else {
					Node<T>* parentNode = eraseNode->parent;			// 삭제할려는 노드의 부모 노드
					if (parentNode->leftNode == eraseNode) {
						// 삭제할려는 노드가 부모의 왼쪽 노드일 경우
						parentNode->leftNode = eraseNode->rightNode;	// 부모의 왼쪽 노드를 삭제할 노드의 오른쪽 노드로 변경
						eraseNode->rightNode->parent = parentNode;		// 삭제할 노드의 오른쪽 노드의 부모를 삭제할 노드의 부모 노드로 변경
						delete eraseNode;
					}
					else {
						// 삭제할려는 노드가 부모의 오른쪽 노드일 경우 
						parentNode->rightNode = eraseNode->rightNode;	// 부모의 오른쪽 노드를 삭제할 노드의 오른쪽 노드로 변경
						eraseNode->rightNode->parent = parentNode;		// 삭제할 노드의 오른쪽 노드의 부모를 삭제할 노드의 부모 노드로 변경
						delete eraseNode;
					}
				}
			}
			else if (eraseNode->leftNode != nullptr && eraseNode->rightNode != nullptr) {
				// 둘다 비어있는 노드가 아니라면
				// 두가지 방법이 있습니다
				// 1. 왼쪽 서브트리에서 가장 큰 값을 가진 노드로 대체한다
				// 2. 오른쪽 서브 트리에서 가장 작은 값을 가진 노드로 대체한다 입니다
				// 1번이든 2번이든 반드시 잎 노드 입니다
				// 저는 여기서 2번을 사용하였습니다
				Node<T>* replaceNode = findMinNode(eraseNode);			// 오른쪽 서브 트리에서 가장 작은 값을 가지고 있는 노드의 주소를 대체 노드 변수에 넣음
				if (eraseNode == root) {
					// 만약 지울 노드가 루트라면
					replaceNode->leftNode == root->leftNode;				// 대체할 노드의 왼쪽 노드를 루트의 왼쪽 노드로
					replaceNode->rightNode == root->rightNode;				// 대체할 노드의 오른쪽 노드를 루트의 오른쪽 노드로
					if (replaceNode->parent->leftNode == replaceNode) {		
						// 대체할 노드가 기존 부모의 왼쪽 노드면 부모의 왼쪽 노드를 nullptr로 바꿈
						replaceNode->parent->leftNode = nullptr;
					}
					else {
						// 대체할 노드가 기존 부모의 오른쪽 노드면 부모의 오른쪽 노드를 nullptr로 바꿈
						replaceNode->parent->rightNode = nullptr;
					}
					root = replaceNode;				// 루트 변경
					replaceNode->parent = nullptr;	// 부모를 없엠(오해금지)
				}
				else {
					// 지울 노드가 루트가 아니면
					if (replaceNode->parent->leftNode == replaceNode) {
						// 대체할 노드가 기존 부모의 왼쪽 노드면 부모의 왼쪽 노드를 nullptr로 바꿈
						replaceNode->parent->leftNode = nullptr;
					}
					else {
						// 대체할 노드가 기존 부모의 오른쪽 노드면 부모의 오른쪽 노드를 nullptr로 바꿈
						replaceNode->parent->rightNode = nullptr;
					}

					if (eraseNode->parent->rightNode == eraseNode) {
						//삭제할 노드가 삭제할 부모 노드의 오른쪽 노드면
						eraseNode->parent->rightNode = replaceNode;		// 자식 바꿈
					}
					else {
						//삭제할 노드가 삭제할 부모 노드의 왼쪽 노드면
						eraseNode->parent->leftNode = replaceNode;		// 자식 바꿈
					}


					replaceNode->parent = eraseNode->parent;			// 대체할 노드의 부모를 지울 노드의 부모로
					replaceNode->leftNode = eraseNode->leftNode;		// 대체할 노드의 왼쪽 노드를 지울 노드의 왼쪽 노드로
					replaceNode->rightNode = eraseNode->rightNode;		// 대체할 노드의 오른쪽 노드를 지울 노드의 오른쪽 노드로
				}
				
				delete eraseNode;		// 노드 삭제
			}
		}

		

	}

private:
	Node<T>* root;

	void preorder(Node<T>* checkNode) {
		if (checkNode == nullptr) {
			// 체크 노드가 nullptr이면 종료
			return;
		}
	
		cout << checkNode->data << " ";		// 데이터 출력

		if (checkNode->leftNode != nullptr) {
			// 왼쪽 노드가 nullptr이 아니면 재귀 실행
			preorder(checkNode->leftNode);
		}

		if (checkNode->rightNode != nullptr) {
			// 오른쪽 노드가 nullptr이 아니면 재귀 실행
			preorder(checkNode->rightNode);
		}
	}

	void inorder(Node<T>* checkNode) {
		if (checkNode->leftNode != nullptr) {
			// 왼쪽 노드가 nullptr이 아니면 재귀 실행
			inorder(checkNode->leftNode);
		}

		cout << checkNode->data << " ";		// 데이터 출력

		if (checkNode->rightNode != nullptr) {
			// 오른쪽 노드가 nullptr이 아니면 재귀 실행
			inorder(checkNode->rightNode);
		}
	}

	void postorder(Node<T>* checkNode) {
		if (checkNode->leftNode != nullptr) {
			// 왼쪽 노드가 nullptr이 아니면 재귀 실행
			postorder(checkNode->leftNode);
		}

		if (checkNode->rightNode != nullptr) {
			// 오른쪽 노드가 nullptr이 아니면 재귀 실행
			postorder(checkNode->rightNode);
		}

		cout << checkNode->data << " ";		// 데이터 출력
	}

	Node<T>* findNode(Node<T>* checkNode, T findData) {
		if (checkNode->data == findData) {
			// 체크 노드의 데이터가 찾는 데이터랑 같으면 체크 노드의 주소를 반환한다
			return checkNode;
		}
		else {
			// 체크 노드의 데이터가 찾는 데이터랑 다르면 다음 왼쪽 노드부터 살펴본다 왼쪽 노드에 없으면 오른쪽 노드를 살펴본다
			// 사실 이 방식은 좋지 않다 checkNode의 데이터와 findData와 비교하면 어느 노드를 찾아야 하는지 알 수 있기 때문이다
			// 하지만 데이터가 항상 int나 float같은 비교하기 쉬운 숫자형이 아닐 수 도 있기에 해당 방법은 적지 않았다
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

		return nullptr;	// 만약 찾는 데이터가 없으면 nullptr을 반환한다
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
	testTree.preorder();
	testTree.erase(3);
	cout << "3을 지운 뒤의 ";
	testTree.preorder();

	testTree.erase(12);
	cout << "12를 지운 뒤의 ";
	testTree.preorder();

	testTree.erase(75);
	cout << "75를 지운 뒤의 ";
	testTree.preorder();


	//testTree.erase(50);
	//testTree.preorder();
}


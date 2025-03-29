#include <iostream>

using namespace std;

template <typename T>
class BST 
{
public:
	struct Node
	{
		T data;					// 저장할 데이터
		Node* parent;		// 부모 노드
		Node* left;			// 왼쪽 자식 노드
		Node* right;			// 오른쪽 자식 노드

		Node(T data) : data(data), parent(nullptr), left(nullptr), right(nullptr) {}		// 노드 생성 시 초기화

	};

	Node* root;		// 루트 노드

	BST() : root(nullptr) {}			// 트리 생성 시 초기화

	Node* Root()			// 트리의 루트 노드 반환하는 함수
	{
		if (root == nullptr)
		{
			cout << "트리가 비어있습니다." << endl;
			return nullptr;
		}

		return root;
	}

	void Insert(Node* parent, T data)			// 삽입 함수
	{
		Node* newNode = new Node(data);			// 삽입할 노드 생성

		if (parent == nullptr)			// root 노드가 없으면
		{	
			root = newNode;			// 새로 생성한 노드를 root 노드로 설정
			return;
		}

		if (parent->data >= data)			// 삽입할 데이터가 부모 노드의 데이터보다 작거나 같으면, 부모 노드의 왼쪽에 삽입
		{
			if (parent->left == nullptr)				// 부모 노드의 왼쪽 노드가 비어있으면
			{
				parent->left = newNode;				// 부모 노드의 왼쪽 노드를 새로 생성한 노드로 설정
				parent->left->parent = parent;		// 새로 생성한 노드의 부모 노드 설정
				return;
			}
			else
			{
				Insert(parent->left, data);			// 부모 노드가 비어있지 않으면, 왼쪽 자식 노드로 내려가서 삽입 함수 반복 (재귀)
			}
		}
		else
		{														// 삽입할 데이터가 부모 노드의 데이터보다 크면, 부모 노드의 오른쪽에 삽입 (아래는 위의 내용과 같음. '왼쪽' 대신 '오른쪽' 대입하면 됩니다.)
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

	Node* FindNode(Node* parent, T data)				// 노드 찾는 함수 (삭제 함수에 사용하기 위해 구현)
	{
		if (parent == nullptr || parent->data == data)						// 부모 노드가 null이거나, 찾는 데이터가 부모 노드의 데이터라면, 부모 노드 반환
		{
			return parent;
		}

		if (parent->data >= data)							// 찾는 데이터가 부모 노드의 데이터보다 작거나 같으면, 왼쪽 자식 노드로 내려가서 노드 찾는 함수 반복 (재귀)
		{
			FindNode(parent->left, data);
		}
		else
			FindNode(parent->right, data);						// 찾는 데이터가 부모 노드의 데이터보다 크면, 오른쪽 자식 노드로 내려가서 반복
	}

	void Delete(Node* parent, T data)									// 삭제 함수
	{
		Node* delNode = FindNode(parent, data);							// 삭제할 노드를 찾음

		if (delNode->left == nullptr && delNode->right == nullptr)				// 삭제할 노드가 자식 노드를 가지고 있지 않을 때 : 삭제할 노드만 날려주면 됨
		{
			if (delNode->parent->data >= data)				// 삭제할 노드가 부모 노드의 왼쪽 자식인지, 오른쪽 자식인지 찾음
			{
				delNode->parent->left = nullptr;			//  부모 노드의 데이터보다 작거나 같으면, 왼쪽 자식을 null로 설정
			}
			else
			{
				delNode->parent->right = nullptr;			// 부모 노드의 데이터보다 크면, 오른쪽 자식을 null로 설정
			}	
		}
		else if (delNode->left != nullptr && delNode->right != nullptr)				// 삭제할 노드가 오른쪽, 왼쪽 모두 자식이 있을 때 : 왼쪽 / 오른쪽 선택
		{																											//왼쪽 서브트리를 선택하면, 왼쪽 서브트리에서 최대값을 찾아서 삭제할 노드 자리에 넣어주고 삭제 / 오른쪽 서브트리를 선택하면, 오른쪽 서브트리에서 최소값을 찾아서 삭제할 노드 자리에 넣어주고 삭제
			Node* head = delNode;											// 삭제할 노드를 부모 노드로 두고
			Node* max = delNode->left;										// 왼쪽 서브트리를 선택하여, 최대값 찾을 것.

			do
			{
				if (max->right == nullptr)				// 왼쪽 서브트리에서 최대값을 찾음 (오른쪽 자식이 없는 노드가 최대값)
					break;

				head = max;									// 트리를 내려가면서 최대값 찾음
				max = max->right;						// 오른쪽 자식 노드가 큰 값이니까, 오른쪽 자식 노드로 내려감
			} while (true);

			if (max->left != nullptr)									// 최대값 노드의 왼쪽 자식이 있다면
			{
				head->right = max->left;							// 최대값 노드의 부모 노드의 오른쪽 자식으로 최대값 노드의 왼쪽 자식을 설정
			}
			else
			{																// 왼쪽 자식이 없다면
				if (head->left == max)							// 최대값 노드가 부모 노드의 왼쪽 자식이라면
				{
					head->left = nullptr;							// 부모 노드의 왼쪽 자식을 null로 설정
				}
				else
					head->right = nullptr;				// 부모 노드의 왼쪽 자식이 아니라면, 오른쪽 자식을 null로 설정
			}
			delNode->data = max->data;			// 삭제할 노드의 데이터에 최대값 넣어주고
			delNode = max;								// 삭제할 노드는 최대값 노드로 변경
		}
		else
		{														// 왼쪽 자식 / 오른쪽 자식 둘 중 하나만 있다면
			Node* childNode = (delNode->left != nullptr) ? delNode->left : delNode->right;					// 자식 노드가 왼쪽인지 오른쪽인지 찾고

			if (delNode->parent->data >= data)								// 삭제할 노드가 부모의 데이터보다 작거나 같다면, 부모 노드의 왼쪽에 삭제할 노드의 자식을 넣어줌
			{
				delNode->parent->left = childNode;
			}
			else
			{																				// 삭제할 노드가 부모의 데이터보다 크면, 부모 노드의 오른족에 삭제할 노드의 자식을 넣어줌
				delNode->parent->right = childNode;
			}
			childNode->parent = delNode->parent;				// 삭제할 노드의 자식 노드의 부모를 삭제할 노드의 부모로 설정
		}

		cout << "\nDelete : " << data;
		delNode->parent = nullptr;							// 삭제할 노드의 부모  null 설정
		delete delNode;										// 노드 삭제
		delNode = nullptr;

	}

	// 전위 순회
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

	// 중위 순회
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

	// 후위 순회
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
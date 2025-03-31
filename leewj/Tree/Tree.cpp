#include <iostream>


struct Node {
	int data;
	Node* parant;
	Node* left;
	Node* right;
};

// BST 구현
struct BST {
private:
	Node* head = nullptr;

public:
	// 얘는 재귀로 해보았다
	bool Insert(int data, Node* current = nullptr) {
		if (!head) {
			head = new Node();
			head->data = data;
			return true;
		}

		if (!current) current = head;

		if (data < current->data) {
			if (current->left) {
				return Insert(data, current->left);
			}
			else {
				current->left = new Node();
				current->left->data = data;
				current->left->parant = current;
				return true;
			}
		}
		else {
			if (current->right) {
				return Insert(data, current->right);
			}
			else {
				current->right = new Node();
				current->right->data = data;
				current->right->parant = current;
				return true;
			}
		}

		return false;
	}

	// 얘는 while로 해봤다.
	bool Find(int data) {
		if (!head) return false;

		Node* current = head;

		while (current) {
			if (data < current->data) {
				current = current->left;
			}
			else if (data == current->data) {
				return true;
			}
			else {
				current = current->right;
			}
		}
		return false;
	}

	// Find 로직에 삭제만 추가
	bool Delete(int data) {
		if (!head) return false;

		Node* current = head;

		bool leftFlag = false;

		while (current) {
			if (data < current->data) {
				current = current->left;
				leftFlag = true;
			}
			else if (data == current->data) { // 찾은 데이터 삭제
				if (!current->left && !current->right) {
					if (leftFlag) current->parant->left = nullptr;
					else current->parant->right = nullptr;
				}
				else if (current->left || current->right) {
					if (leftFlag) current->parant->left = current->right ? current->right : current->left;
					else current->parant->right = current->right ? current->right : current->left;
				}
				else {
					if (leftFlag) current->parant->left = current->right;
					else current->parant->right = current->right;
				}
				delete current;

				return true;
			}
			else {
				current = current->right;
				leftFlag = false;
			}
		}
		return false;
	}

	// 전위
	void PreOrderLoop(Node* node) {
		if (!node) return;
		std::cout << node->data << " ";
		PreOrderLoop(node->left);
		PreOrderLoop(node->right);
	}

	// 중위
	void InOrderLoop(Node* node) {
		if (!node) return;
		InOrderLoop(node->left);
		std::cout << node->data << " ";
		InOrderLoop(node->right);
	}

	// 후위
	void PostOrderLoop(Node* node) {
		if (!node) return;
		PostOrderLoop(node->left);
		PostOrderLoop(node->right);
		std::cout << node->data << " ";
	}

	void PreOrder() {
		if (!head) return;

		PreOrderLoop(head);
		std::cout << "\n";
	}
	void InOrder() {
		if (!head) return;

		InOrderLoop(head);
		std::cout << "\n";
	}

	void PostOrder() {
		if (!head) return;

		PostOrderLoop(head);
		std::cout << "\n";
	}
};

int main() {
	BST bst;

	bst.Insert(5);
	bst.Insert(1);
	bst.Insert(8);
	bst.Insert(7);

	bst.Delete(8);

	bst.PreOrder();
	bst.InOrder();
	bst.PostOrder();

	return 0;
}
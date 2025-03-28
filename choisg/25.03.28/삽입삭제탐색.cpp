#include <iostream>
#include <vector>

using namespace std;

struct node {
	int data;
	node* left;
	node* right;

	node(int val) : data(val), left(nullptr), right(nullptr) {}

};


//탐색

node* search(node* root, int key)
{
	if (root == NULL || root->data == key)
		return root;

	if (key< root->data )
	return search(root->left, key);

	return search(root->right, key);
}

//삽입

node* insert(node* root, int key) {
	if (!root)
		return new node(key);

	if (key > root->data)
		root->right = insert(root->right, key);
	else if (key < root->data)
		root->left = insert(root->left, key);
	return root;
}

//삭제

// 노드의 최소값을 가져오는 함수
node* minValueNode(node* current) {

	while (current && current->left != NULL)
		current = current->left;

	return current;
}

node* deleteNode(node* root, int key) {
	
	if (root == NULL)
		return root;


	if (key < root->data)
		root->left = deleteNode(root->left, key);

	else if (key > root->data)
		root->right = deleteNode(root->right, key);


	else {

		node* temp;
		if (root->left == NULL) {
			temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == NULL) {
			temp = root->left;
			delete root;
			return temp;
		}

		temp = minValueNode(root->right);

		root->data = temp->data;
		root->right = deleteNode(root->right, temp->data);
	}
	return root;
}

void PreOrder(node* temp) {
	if (!temp) return;


	cout << temp->data;
	PreOrder(temp->left);
	PreOrder(temp->right);

}


int main()
{
	node* root = nullptr;

	//노드 삽입
	root = insert(root, 50);
	root = insert(root, 30);
	root = insert(root, 70);
	root = insert(root, 20);
	root = insert(root, 40);
	root = insert(root, 60);
	root = insert(root, 80);

	//삽입 테스트
	PreOrder(root);
	cout << " " << endl;

	//검색 테스트
	int searchKey = 40;
	node* found = search(root, searchKey);
	if (found)
		cout << searchKey << " 노드를 찾았습니다!\n";
	else
		cout << searchKey << " 노드를 찾지 못했습니다.\n";

	
	//삭제 테스트
	root = deleteNode(root, 30);
	cout << "\n";

	return 0;
}
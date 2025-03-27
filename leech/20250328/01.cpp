#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node() {
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    Node* root;

public:
    BinaryTree() { root = nullptr; }
    ~BinaryTree() {}

    void addNode(int value);
    void deleteNode(int idx);

    void preOrder();
    void inOrder();
    void postOrder();
    void levelOrder();

    void preOrderLogic(Node* node);
    void inOrderLogic(Node* node);
    void postOrderLogic(Node* node);
};

void BinaryTree::addNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (root == nullptr) {
        root = newNode;
    }
    else {
        queue<Node*> q;
        Node* temp;

        q.push(root);

        while (!q.empty()) {
            temp = q.front();
            q.pop();

            if (temp->left == nullptr) {
                temp->left = newNode;
                break;
            }
            else {
                q.push(temp->left);
            }

            if (temp->right == nullptr) {
                temp->right = newNode;
                break;
            }
            else {
                q.push(temp->right);
            }
        }
    }
}

void BinaryTree::deleteNode(int idx) {

    if (root == nullptr) {
        cout << "삭제할 노드가 없습니다." << '\n';
        exit(EXIT_FAILURE);
    }
    else {
        queue<Node*> q;
        int cnt = 0;
        Node* temp;

        q.push(root);

        while (!q.empty()) {
            temp = q.front();
            q.pop();
            cnt++;

            if (cnt == idx) {
                if (temp->left != nullptr || temp->right != nullptr) {
                    cout << "자식 노드가 있어 삭제가 불가능합니다." << '\n';
                    return;
                }
                else {
                    delete(temp);
                    cout << "삭제 성공" << '\n';
                    return;
                }
            }
            else {
                if (temp->left != nullptr) {
                    q.push(temp->left);
                }
                if (temp->right != nullptr) {
                    q.push(temp->right);
                }
            }
            cout << "인덱스에 원소가 없습니다." << '\n';
            return;
        }
    }
}

void BinaryTree::preOrder() {
    if (root == nullptr) {
        cout << "순회할 노드가 없습니다." << '\n';
        return;
    }
    preOrderLogic(root);
}

void BinaryTree::preOrderLogic(Node* cur) {
    if (cur == nullptr) return;

    cout << cur->data << "  ";
    preOrderLogic(cur->left);
    preOrderLogic(cur->right);
}

void BinaryTree::inOrder() {
    if (root == nullptr) {
        cout << "순회할 노드가 없습니다." << '\n';
        return;
    }
    inOrderLogic(root);
}

void BinaryTree::inOrderLogic(Node* cur) {
    if (cur == nullptr) return;

    inOrderLogic(cur->left);
    cout << cur->data << "  ";
    inOrderLogic(cur->right);
}

void BinaryTree::postOrder() {
    if (root == nullptr) {
        cout << "순회할 노드가 없습니다." << '\n';
        return;
    }
    postOrderLogic(root);
}

void BinaryTree::postOrderLogic(Node* cur) {
    if (cur == nullptr) return;

    postOrderLogic(cur->left);
    postOrderLogic(cur->right);
    cout << cur->data << " ";
}

void menuPrint() {
    cout << "==============Binary Tree==============" << "\n";
    cout << "[1] AddNode" << "\n";
    cout << "[2] DeleteNode" << "\n";
    cout << "[3] preOrder" << "\n";
    cout << "[4] inOrder" << "\n";
    cout << "[5] postOrder" << "\n";
    cout << "[Exit] Exit(1~6제외 아무키나 누르세요)" << "\n";
}

int main() {
    BinaryTree BT;

    while (true) {
        menuPrint();
        char cmd;
        cin >> cmd;
        if (cmd == '1') {
            int input;
            cout << "값을 입력하세요 : ";
            cin >> input;
            BT.addNode(input);
        }
        else if (cmd == '2') {
            int input;
            cout << "삭제할 노드의 레벨을 입력하세요 : ";
            cin >> input;
            BT.deleteNode(input);
        }
        else if (cmd == '3') {
            BT.preOrder();
            cout << '\n';
        }
        else if (cmd == '4') {
            BT.inOrder();
            cout << '\n';
        }
        else if (cmd == '5') {
            BT.postOrder();
            cout << '\n';
        }
        else {
            exit(0);
        }
    }
}
단일 연결 리스트
#include <iostream>
using namespace std;

struct SNode {
    int data;
    SNode* next;
    SNode(int x) : data(x), next(nullptr) {}
};

class SList {
    SNode* head;
public:
    SList() : head(nullptr) {}

    void addLast(int x) {
        SNode* newNode = new SNode(x);
        if (!head) {
            head = newNode;
            return;
        }
        SNode* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = newNode;
    }

    void removeVal(int x) {
        if (!head) return;
        if (head->data == x) {
            SNode* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        SNode* cur = head;
        while (cur->next && cur->next->data != x) cur = cur->next;
        if (!cur->next) return;
        SNode* temp = cur->next;
        cur->next = temp->next;
        delete temp;
    }

    void insertAfter(int t, int x) {
        SNode* cur = head;
        while (cur && cur->data != t) cur = cur->next;
        if (!cur) return;
        SNode* newNode = new SNode(x);
        newNode->next = cur->next;
        cur->next = newNode;
    }

    void showAll() {
        SNode* cur = head;
        while (cur) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};

int main() {
    SList s;
    s.addLast(10);
    s.addLast(20);
    s.addLast(30);
    s.insertAfter(20, 25);
    s.showAll();
    s.removeVal(25);
    s.showAll();
    return 0;
}

이중 연결 리스트
#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int x) : data(x), prev(nullptr), next(nullptr) {}
};

class DList {
    DNode* head;
    DNode* tail;
public:
    DList() : head(nullptr), tail(nullptr) {}

    void addLast(int x) {
        DNode* newNode = new DNode(x);
        if (!head) {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void removeVal(int x) {
        DNode* cur = head;
        while (cur && cur->data != x) cur = cur->next;
        if (!cur) return;
        if (cur == head) {
            head = head->next;
            if (head) head->prev = nullptr;
            else tail = nullptr;
        } else if (cur == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
        }
        delete cur;
    }

    void insertAfter(int t, int x) {
        DNode* cur = head;
        while (cur && cur->data != t) cur = cur->next;
        if (!cur) return;
        DNode* newNode = new DNode(x);
        newNode->next = cur->next;
        newNode->prev = cur;
        if (cur->next) cur->next->prev = newNode;
        else tail = newNode;
        cur->next = newNode;
    }

    void showAll() {
        DNode* cur = head;
        while (cur) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};

int main() {
    DList d;
    d.addLast(1);
    d.addLast(2);
    d.addLast(3);
    d.insertAfter(2, 25);
    d.showAll();
    d.removeVal(25);
    d.showAll();
    return 0;
}


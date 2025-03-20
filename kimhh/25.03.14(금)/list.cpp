#include <iostream>
#include <forward_list>
#include <list>


// 리스트 만들기
std::forward_list<int> fwd_list = { 10,20,30,40,50 };

template<typename T>
struct Node
{
	T data;
	Node* next;

	Node() : next(nullptr) {}
	Node(const T& value) : data(value), next(nullptr) {}
};

template<typename T>
class ForwardList {
private:
	Node* head;
public:
	ForwardList() { head = nullptr; }

	// 노드 추가
	void push_front(T data) {
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;

		if (head == nullptr) {
			head = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
	}

	// 특정 노드 다음에 추가
	void insert_after(Node* prev, T data) {
		Node* newNode = new Node(data);
		newNode->next = prev->next;
		prev->next = newNode;
	}

	// 맨 앞 삭제
	void pop_front() {
		if (head == nullptr) return;
		Node* temp = head;
		head = head->next;
		delete temp;
	}

	// 특정 노드 삭제
	void remove(T data) {
		if (head == nullptr) return;
		if (head->data == data) {
			pop_front();
			return;
		}
		Node current = head;
		while (current->next != nullptr && current->next->data != data) {
			current = current->next;
		}
		if (current->next != nullptr) {
			Node* temp = current->next;
			current->next = temp->next;
			delete temp;
		}
	}

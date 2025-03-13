#include <iostream>
#include <cstdlib> 
#include <malloc.h>
using namespace std;

template <class T>
struct Node
{
	Node* nextNode;
	T data;
	Node* backNode;
	Node(T data) : data(data), nextNode(nullptr), backNode(nullptr){}
};

template <class T>
class doubleLinkList {

public:
	doubleLinkList();

	doubleLinkList(int n);

	doubleLinkList(int n, T data);

	~doubleLinkList();

	T operator[](size_t index) const;

	T at(int index);

	T front();

	T back();

	int size();

	size_t capacity();

	bool empty();

	void push_back(T data);

	void pop_back();

	void insert(int loc, T val);

	void clear();
private:
	Node<T>* head;
	int listSize;
	int maxSize = INT_MAX;
};

template<class T>
doubleLinkList<T>::doubleLinkList()
{
	head = nullptr;
	listSize = 0;
}

template<class T>
doubleLinkList<T>::doubleLinkList(int n)
{
	head = nullptr;
	listSize = n;
}

template<class T>
doubleLinkList<T>::doubleLinkList(int n, T data)
{
	listSize = n;
	Node<T>* node = new Node<T>(data);

	for (int i = 0; i < listSize; ++i) {
		push_back(data);
	}
}


template<class T>
doubleLinkList<T>::~doubleLinkList()
{
}

template<class T>
T doubleLinkList<T>::operator[](size_t index) const
{
	Node<T>* currentNode = head;
	for (int i = 0; i < index; i++) {
		if (currentNode == nullptr) {
			throw 0;
			cout << "이게?" << endl;
		}
		currentNode = currentNode->nextNode;
	}

	return currentNode->data;
}

template<class T>
T doubleLinkList<T>::at(int index)
{
	Node<T>* currentNode = head;
	for (int i = 0; i < index; i++) {
		currentNode = currentNode->nextNode;
		if (currentNode == nullptr) {
			throw 0;
		}
	}

	return currentNode->data;
}

template<class T>
T doubleLinkList<T>::front()
{
	if (head != nullptr) {
		return head->data;
	}
	return T();
}

template<class T>
T doubleLinkList<T>::back()
{
	if (head == nullptr) {
		return T();
	}
	else {
		Node<T>* currentNode = head;
		while (currentNode->nextNode != nullptr) {
			currentNode = currentNode->nextNode;
		}
		return currentNode->data;
	}
}

template<class T>
int doubleLinkList<T>::size()
{
	return listSize;
}

template<class T>
size_t doubleLinkList<T>::capacity()
{
	size_t answer = 0;

	if (head == nullptr) {
		return 0;
	}

	Node<T>* currentNode = head;
	answer += _msize(currentNode);
	while (currentNode->nextNode != nullptr) {
		currentNode = currentNode->nextNode;
		answer += _msize(currentNode);
	}
	return answer;
}

template<class T>
bool doubleLinkList<T>::empty()
{
	if (head == nullptr) {
		cout << "비었음" << endl;
		return true;
	}
	else {
		cout << "내용물이 있음" << endl;
		return false;
	}
}

template<class T>
void doubleLinkList<T>::push_back(T data)
{
	if (head == nullptr) {
		Node<T>* node = new Node<T>(data);
		head = node;
		listSize++;
		return;
	}

	Node<T>* currentNode = head;
	while (currentNode->nextNode != nullptr) {
		currentNode = currentNode->nextNode;
	}
	Node<T>* node = new Node<T>(data);
	currentNode->nextNode = node;
	node->backNode = currentNode;

	listSize++;
}

template<class T>
void doubleLinkList<T>::pop_back()
{
	Node<T>* currentNode = head;
	while (currentNode->nextNode->nextNode != nullptr) {
		currentNode = currentNode->nextNode;
	}
	delete currentNode->nextNode;
	currentNode->nextNode = nullptr;
	listSize--;
}

template<class T>
void doubleLinkList<T>::insert(int loc, T val)
{
	if (loc > listSize) {
		cout << "범위 밖입니다" << endl;
		return;
	}
	else if (loc == 0) {
		Node<T>* node = new Node<T>(val);
		node->nextNode = head;
		head = node;
		listSize++;
		return;
	}
	else {
		Node<T>* currentNode = head;
		for (int i = 0; i < loc - 1; i++) {
			currentNode = currentNode->nextNode;
		}
		Node<T>* node = new Node<T>(val);
		node->nextNode = currentNode->nextNode;
		node->backNode = currentNode;
		currentNode->nextNode = node;

		listSize++;
	}
}

template<class T>
void doubleLinkList<T>::clear()
{
	Node<T>* currentNode = head;
	while (currentNode != nullptr) {
		Node<T>* nextNode = currentNode->nextNode;
		delete currentNode;
		currentNode = nextNode;
	}
	head = nullptr;
}

int main() {
	doubleLinkList<int> list;
	list.push_back(3);
	list.push_back(1);
	list.push_back(4);
	list.push_back(5);

	cout << list[0] << endl;
	cout << list[1] << endl;
	cout << list.at(2) << endl;
	cout << list.at(3) << endl;

	cout << list.back() << endl;

	cout << list.size() << endl;

	cout << list.capacity() << endl;

	list.pop_back();

	list.insert(1, 88);
	list.insert(99, 88);

	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << endl;
	}

	list.clear();

	cout << list.empty();

}
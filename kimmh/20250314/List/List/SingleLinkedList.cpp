#include <iostream>
#include <cstdlib> 
#include <malloc.h>
using namespace std;

template <class T>
struct Node
{
	Node* nextNode;
	T data;
	Node(T data) : data(data), nextNode(nullptr) {}
};

template <class T>
class singleLinkedList {

public:
	singleLinkedList();

	singleLinkedList(int n);

	singleLinkedList(int n, T data);

	~singleLinkedList();

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
singleLinkedList<T>::singleLinkedList()
{
	head = nullptr;
	listSize = 0;
}

template<class T>
singleLinkedList<T>::singleLinkedList(int n)
{
	head = nullptr;
	listSize = n;
}

template<class T>
singleLinkedList<T>::singleLinkedList(int n, T data)
{
	listSize = n;
	Node<T>* node = new Node<T>(data);

	for (int i = 0; i < listSize; ++i) {
		push_back(data);
	}
}


template<class T>
singleLinkedList<T>::~singleLinkedList()
{
}

template<class T>
T singleLinkedList<T>::operator[](size_t index) const
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
T singleLinkedList<T>::at(int index)
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
T singleLinkedList<T>::front()
{
	if (head != nullptr) {
		return head->data;
	}
	return T();
}

template<class T>
T singleLinkedList<T>::back()
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
int singleLinkedList<T>::size()
{
	return listSize;
}

template<class T>
size_t singleLinkedList<T>::capacity()
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
bool singleLinkedList<T>::empty()
{
	if (head == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

template<class T>
void singleLinkedList<T>::push_back(T data)
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

	listSize++;
}

template<class T>
void singleLinkedList<T>::pop_back()
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
void singleLinkedList<T>::insert(int loc, T val)
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
		currentNode->nextNode = node;
		listSize++;
	}
}

template<class T>
void singleLinkedList<T>::clear()
{
	Node<T>* backNode;
	Node<T>* currentNode = head;
	while (currentNode->nextNode != nullptr) {
		backNode = currentNode;
		currentNode = currentNode->nextNode;
		delete backNode;
	}
	delete currentNode;
}

int main() {
	singleLinkedList<int> list;
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
	list.insert(2, 78);

	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << endl;
	}

	list.clear();

	cout << list.empty();

}
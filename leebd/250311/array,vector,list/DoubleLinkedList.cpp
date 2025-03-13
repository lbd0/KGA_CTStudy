#include <iostream>
using namespace std;

template <typename T>
class DoubleLinkedList
{
private:
	struct Node
	{
		T data;		// 데이터 / 자료

		Node* next;		// 다음 노드를 가리키는 포인터
		Node* prev;		// 이전 노드를 가리키는 포인터

		Node(T data) :data(data), next(nullptr), prev(nullptr) {}
	};

	Node* head;		// 리스트의 첫 번째 노드

public:
	DoubleLinkedList() { head = nullptr; }			// 생성자

	// 맨 앞에 추가
	void push_front(T data)
	{
		Node* node = new Node(data);			// 새로운 노드 생성

		if (head == nullptr)		// 리스트가 비어있다면
		{
			head = node;			// 새로운 노드를 리스트의 첫 번째 노드로 설정
		}
		else
		{									// 리스트가 비어있지 않으면
			node->prev = nullptr;	// 첫 번째 노드의 이전 포인터는 널포인터
			node->next = head;		// 새로운 노드의 포인터를 리스트의 첫 번째 노드로 연결
			head = node;				// 리스트의 첫 번째 노드를 새로운 노드로 설정
		}
	}

	// 특정 위치 뒤에 추가
	void insert_after(Node* prev, T data)
	{
		Node* node = new Node(data);				// 새로운 노드 생성
		node->next = prev->next;						// 새로운 노드의 포인터를 추가하려는 위치 다음 노드와 연결
		prev->next = node;								// 추가하려는 위치 앞 노드의 포인터를 새로운 노드로 연결

		node->prev = prev;							// 새 노드의 이전 노드 포인터 연결
		node->next->prev = node;					// 새 노드 다음 노드의 이전 포인터를 새 노드로 연결
	}

	// 맨 뒤에 추가
	void append(T data)
	{
		Node* node = new Node(data);			// 새로운 노드 생성

		if (head == nullptr)			// 리스트가 비어있다면
		{
			head = node;			// 새로운 노드를 첫 번째 노드로 설정
			return;
		}

		// 리스트가 비어있지 않다면
		Node* current = head;		// 현재 노드를 가리키는 포인터 변수 
		while (current->next != nullptr)			// 현재 리스트에서 맨 뒤에 있는 노드 찾기
		{
			current = current->next;
		}
		current->next = node;			// 맨 뒤에 있는 노드의 포인터에 새로운 노드 연결
		node->prev = current;			// 새 노드의 이전 포인터를 맨 뒤에 있던 노드로 연결
	}

	// 맨 앞 삭제
	void pop_front()
	{
		if (head == nullptr) return;

		Node* temp = head;				// 삭제할 노드
		head = head->next;				// 리스트의 첫 번째 노드를 그 다음 노드로 설정
		head->prev = nullptr;			// 새로운 헤드 노드의 이전 포인터를 널포인터로 
		delete temp;							// 노드 삭제
	}

	// 특정 위치 뒤 삭제
	void erase_after(Node* prev)
	{
		Node* temp = prev->next;			// 특정 위치 뒤에 있는 노드가 삭제할 노드
		prev->next = prev->next->next;		// 특정 위치 노드의 포인터를 삭제할 노드 포인터로 연결
		prev->next->prev = prev;				// 삭제할 노드 다음 노드의 이전 포인터를 특정 위치로 연결
		delete temp;									// 노드 삭제
	}

	// data 찾아서 삭제
	void remove(T data)
	{
		Node* current = head;				// 현재 가리키고 있는 노드
		while (current->next != nullptr && current->next->data != data)		// data를 가지고 있는 노드의 앞 노드 찾기
		{
			current = current->next;
		}

		if (current->next != nullptr)
		{
			Node* temp = current->next;				// 삭제할 노드는 현재 노드의 다음 노드
			current->next = current->next->next;		// 현재 노드의 포인터는 삭제할 노드의 포인터와 연결
			current->next->prev = current;				// 삭제할 노드 다음 노드의 이전 포인터를 특정 위치로 연결
			delete temp;				// 노드 삭제
		}
	}

	// 특정 노드 찾기
	Node* findNode(T data)
	{
		Node* current = head;			// 현재 가리키고 있는 노드
		while (current != nullptr && current->data != data)			// 데이터를 가진 노드 찾기
		{
			current = current->next;
		}

		return current;
	}

	// 리스트 출력
	void print()
	{
		Node* current = head;			// 현재 노드
		while (current != nullptr)		// 리스트의 마지막 노드까지 반복
		{
			cout << current->data << " ";			// 데이터 출력
			current = current->next;
		}
		cout << endl;
	}

	void reversePrint()
	{
		Node* current = head;		// 현재 노드를 가리키는 포인터 변수 
		while (current->next != nullptr)			// 현재 리스트에서 맨 뒤에 있는 노드 찾기
		{
			current = current->next;
		}
		Node* tail = current;

		while (tail != nullptr)
		{
			cout << tail->data << " ";
			tail = tail->prev;
		}
		cout << endl;
	}

};

int main()
{
	DoubleLinkedList<int> list;

	list.push_front(0);
	list.print();

	list.append(2);
	list.print();

	list.insert_after(list.findNode(0), 1);
	list.print();

	list.append(3);
	list.append(4);
	list.append(5);
	list.print();

	cout << "reverse print : ";
	list.reversePrint();

	list.erase_after(list.findNode(0));
	list.print();

	list.pop_front();
	list.print();

	list.remove(3);
	list.print();

}
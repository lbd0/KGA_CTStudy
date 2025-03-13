#include <iostream>

using namespace std;

template <typename T>

// 단일 연결 리스트
class SinglyLinkedList {
private:
	struct Node {
		T data;								// 데이터
		Node* next;							// 다음 노드를 가리키는 포인터

		Node(T data) :data(data), next(nullptr) {}
	};

	Node* head;								// 리스트의 첫 번째 노드

public:
	SinglyLinkedList() { head = nullptr; }	// 생성자

	// 맨 앞에 추가
	void push_front(T data) {
		Node* node = new Node(data);		// 새로운 노드 생성

		if (head == nullptr) {				// 리스트가 비었다면
			head = node;					// 새로운 노드를 리스트의 첫 번째 노드로 설정
		}
		else {								// 리스트가 비어있지 않다면
			node->next = head;				// 새로운 노드의 포인터를 리스트의 첫 번째 노드로 연결
			head = node;					// 리스트의 첫 번째 노드를 새로운 노드로 설정
		}
	}

	// 특정 위치 뒤에 추가
	void insert(Node* prev, T data) {
		Node* node = new Node(data);		// 새로운 노드 생성
		node->next = prev->next;			// 새로운 노드의 다음 위치를 추가하려는 위치 다음 노드로 연결
		prev->next = node;					// 추가하려는 위치 앞 노드의 다음 위치를 새로운 노드로 연결
	}

	// 맨 뒤에 추가
	void push_back(T data) {
		Node* node = new Node(data);		// 새로운 노드 생성

		if (head == nullptr) {				// 리스트가 비었다면
			head = node;					// 새로운 노드를 리스트의 첫 번째 노드로 설정
			return;
		}

		Node* current = head;				// 현재 노드를 가리키는 포인터 변수

		while (current->next != nullptr) {	// 리스트의 맨 뒤의 노드 찾기
			current = current->next;
		}

		current->next = node;				// 맨 뒤의 노드에 새로운 노드 연결
	}

	// 맨 앞에 삭제
	void pop_front() {
		if (head == nullptr) return;

		Node* temp = head;					// 삭제할 노드
		head = head->next;					// 리스트의 두번째 노드를 첫 노드로 설정
		delete temp;						// 노드 삭제
	}

	// 특정 위치 뒤에 삭제
	void erase(Node* node) {
		Node* temp = node->next;			// 삭제할 노드
		node->next = node->next->next;		// 삭제할 노드의 다음 노드를 이전 노드에 연결
		delete temp;						// 노드 삭제
	}

	// 특정 Data 삭제
	void remove(T data) {
		Node* current = head;				// 현재 노드

		// 다음 노드가 있고 다음 Data가 찾는 Data가 아니면 다음 노드로
		while (current->next != nullptr && current->next->data != data) {
			current = current->next;
		}

		if (current->next != nullptr) {
			Node* temp = current->next;		// 삭제할 노드는 현재 노드의 다음 노드
			current->next = current->next->next;	// 현재 노드의 포인터를 삭제할 노드의 포인터와 연결
			delete temp;					// 노드 삭제
		}
	}

	// 특정 노드 찾기
	Node* findNode(T data) {
		Node* current = head;

		// 다음 노드가 있고 다음 Data가 찾는 Data가 아니면 다음 노드로
		while (current != nullptr && current->data != data) {
			current = current->next;
		}

		return current;
	}

	// 출력
	void print() {
		Node* current = head;

		while (current != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
};

template <typename T>
// 이중 연결 리스트
class DoublyLinkedList {
private:
	struct Node {
		T data;								// 데이터
		Node* prev;							// 이전 노드를 가리키는 포인터
		Node* next;							// 다음 노드를 가리키는 포인터

		Node(T data) :data(data), prev(nullptr), next(nullptr) {}
	};

	Node* head;

public:
	DoublyLinkedList() { head = nullptr; }	// 생성자

	// 맨 앞에 추가
	void push_front(T data) {
		Node* node = new Node(data);		// 새로운 노드 생성

		if (head == nullptr) {				// 리스트가 비었다면
			head = node;					// 새로운 노드를 리스트의 첫 번째 노드로 설정
		}
		else {								// 리스트가 비어있지 않다면
			node->prev = nullptr;			// 새로운 노드의 이전 포인터를 널로 지정
			node->next = head;				// 새로운 노드의 포인터를 리스트의 첫 번째 노드로 연결
			head = node;					// 리스트의 첫 번째 노드를 새로운 노드로 설정
		}
	}

	// 특정 위치 뒤에 추가
	void insert(Node* prev, T data) {
		Node* node = new Node(data);		// 새로운 노드 생성
		node->next = prev->next;			// 새로운 노드의 다음 위치를 추가하려는 위치 다음 노드로 연결
		prev->next = node;					// 추가하려는 위치 앞 노드의 다음 위치를 새로운 노드로 연결
		node->prev = prev;					// 새로운 노드 이전 노드 설정
		node->next->prev = node;			// 새로운 노드 다음 노드의 이전 노드 설정
	}

	// 맨 뒤에 추가
	void push_back(T data) {
		Node* node = new Node(data);		// 새로운 노드 생성

		if (head == nullptr) {				// 리스트가 비었다면
			head = node;					// 새로운 노드를 리스트의 첫 번째 노드로 설정
			return;
		}

		Node* current = head;				// 현재 노드를 가리키는 포인터 변수

		while (current->next != nullptr) {	// 리스트의 맨 뒤의 노드 찾기
			current = current->next;
		}

		current->next = node;				// 맨 뒤의 노드에 새로운 노드 연결
		node->prev = current;				// 새 노드의 앞 노드 설정
	}

	// 맨 앞에 삭제
	void pop_front() {
		if (head == nullptr) return;

		Node* temp = head;					// 삭제할 노드
		head = head->next;					// 리스트의 두번째 노드를 첫 노드로 설정
		head->prev = nullptr;				// 새로운 head의 앞 노드를 널로 설정
		delete temp;						// 노드 삭제
	}

	// 특정 위치 뒤에 삭제
	void erase(Node* node) {
		Node* temp = node->next;			// 삭제할 노드
		node->next = node->next->next;		// 삭제할 노드의 다음 노드를 이전 노드에 연결
		node->next->prev = node;			// 삭제할 노드의 다음 노드의 이전 노드 설정
		delete temp;						// 노드 삭제
	}

	// 특정 Data 삭제
	void remove(T data) {
		Node* current = head;				// 현재 노드

		// 다음 노드가 있고 다음 Data가 찾는 Data가 아니면 다음 노드로
		while (current->next != nullptr && current->next->data != data) {
			current = current->next;
		}

		if (current->next != nullptr) {
			Node* temp = current->next;		// 삭제할 노드는 현재 노드의 다음 노드
			current->next = current->next->next;	// 현재 노드의 포인터를 삭제할 노드의 포인터와 연결
			current->next->prev = current;	// 삭제할 노드의 다음 노드의 이전 노드 설정
			delete temp;					// 노드 삭제
		}
	}

	// 특정 노드 찾기
	Node* findNode(T data) {
		Node* current = head;

		// 다음 노드가 있고 다음 Data가 찾는 Data가 아니면 다음 노드로
		while (current != nullptr && current->data != data) {
			current = current->next;
		}

		return current;
	}

	// 출력
	void print() {
		Node* current = head;

		while (current != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
};

int main()
{
	SinglyLinkedList<int> slist;

	slist.push_front(0);
	slist.print();
	slist.push_back(3);
	slist.push_back(5);
	slist.print();
	slist.insert(slist.findNode(0), 1);
	slist.print();
	slist.erase(slist.findNode(3));
	slist.print();
	slist.pop_front();
	slist.print();
	slist.remove(5);
	slist.print();

	cout << endl << endl;

	DoublyLinkedList<int> dlist;

	dlist.push_front(0);
	dlist.print();
	dlist.push_back(3);
	dlist.push_back(5);
	dlist.print();
	dlist.insert(dlist.findNode(0), 1);
	dlist.print();
	dlist.erase(dlist.findNode(3));
	dlist.print();
	dlist.pop_front();
	dlist.print();
	dlist.remove(5);
	dlist.print();
}
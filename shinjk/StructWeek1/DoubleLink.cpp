#include<iostream>

using namespace std;

template<typename T>
class List
{
private:
	struct Node
	{
		T data;

		Node* prev;
		Node* next;
		Node(T data) :data(data), prev(nullptr), next(nullptr){}
	};

	Node* head;
	Node* tail;

public:
	List() 
	{ 
		head = nullptr;
		tail = nullptr;
	}


	//맨 앞에 노드 넣기
	void push_front(T data)
	{
		Node* node = new Node(data);
		if (head == nullptr)
		{
			head = node;
			tail = node;
		}
		else
		{
			head->prev = node;
			node->next = head;
			head = node;
		}
	}


	//특정 위치 뒤에 추가
	void insert_push(Node* prev, T data)
	{
		Node* node = new Node(data);

		if (prev->next == nullptr)
		{
			prev->next = node;
			node->prev = prev;
			tail = node;
		}

		else
		{
			node->next = prev->next;
			prev->next->prev = node;
			prev->next = node;
			node->prev = prev;

		}
	}


	//맨 뒤에 추가
	void append(T data)
	{
		Node* node = new Node(data);

		if (head == nullptr)
		{
			head = node;
			tail = node;
		}
		else
		{
			node->prev = tail;
			tail->next = node;
			tail = node;
		}
	}


	//맨 앞 삭제
	void pop_front()
	{
		Node* temp = head;
		head->next->prev = nullptr;
		head = head->next;
		delete temp;
	}

	
	//특정 위치 뒤 삭제
	void erase_after(Node* prev)
	{
		Node* temp = prev->next;
		prev->next->next->prev = prev;
		prev->next = prev->next->next;
		delete temp;
	}


	//data 찾아서 삭제
	void remove(T data)
	{
		Node* current = head;
		while (current->next != nullptr && current->next->data != data)
		{
			current = current->next;
		}

		if (current->next != nullptr)
		{
			Node* temp = current->next;
			current->next->next->prev = current;
			current->next = current->next->next;
			delete temp;
		}
	}


	//특정 노드 찾기
	Node* findNode(T data)
	{
		Node* current = head;
		while (current != nullptr && current->data != data)
		{
			current = current->next;
		}

		return current;
	}


	//리스트 출력
	void print()
	{
		Node* current = head;

		while (current != nullptr)
		{
			cout << current->data << " ";
			current = current->next;
		}

		cout << endl;
	}

	void reverse_print()
	{
		Node* current = tail;
		while (current != nullptr)
		{
			cout << current->data << " ";
			current = current->prev;
		}

		cout << endl;
	}

};


int main()
{
	List<int>list;

	list.push_front(5);
	list.print();
}
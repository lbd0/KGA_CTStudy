#include<iostream>

using namespace std;

template<typename T>
class List
{
private:
	struct Node
	{
		T data;

		Node* next;

		Node(T data) :data(data), next(nullptr){}

	};

	Node* head;

public:
	List() { head = nullptr; }


	//맨 앞에 노드 넣기
	void push_front(T data)
	{
		Node* node = new Node(data);

		if (head == nullptr)
		{
			head = node;
		}
		else
		{
			node->next = head;
			head = node;
		}
	}


	//특정 위치 뒤에 추가
	void insert_push(Node* prev, T data)
	{
		Node* node = new Node(data);
		node->next = prev->next;
		prev->next = node;

	}


	//맨 뒤에 추가
	void append(T data)
	{
		Node* node = new Node(data);
		if (head == nullptr)
		{
			head = node;
			return;
		}

		Node* current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}

		current->next = node;
	}


	//맨앞 삭제
	void pop_front()
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}


	//특정 위치 뒤 삭제
	void erase_after(Node* prev)
	{
		Node* temp = prev->next;
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

		if (current->next!=nullptr)
		{
			Node* temp = current->next;
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

		while (current->next != nullptr)
		{
			cout << current->data<<" ";
			current = currnet->next;
		}
		cout << endl;
	}


};


int main()
{
	List<int>list;


	list.push_front(0);
	list.print();

	list.append(2);
	list.print();

	list.insert_push(list.findNode(0), 1);
	list.print();

	list.append(3);
	list.append(4);
	list.append(5);
	list.print();

	list.erase_after(list.findNode(0));
	list.print();

	list.pop_front();
	list.print();

	list.remove(3);
	list.print();

}

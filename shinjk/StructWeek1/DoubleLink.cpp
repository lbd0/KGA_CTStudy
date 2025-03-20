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


	//�� �տ� ��� �ֱ�
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


	//Ư�� ��ġ �ڿ� �߰�
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


	//�� �ڿ� �߰�
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


	//�� �� ����
	void pop_front()
	{
		Node* temp = head;
		head->next->prev = nullptr;
		head = head->next;
		delete temp;
	}

	
	//Ư�� ��ġ �� ����
	void erase_after(Node* prev)
	{
		Node* temp = prev->next;
		prev->next->next->prev = prev;
		prev->next = prev->next->next;
		delete temp;
	}


	//data ã�Ƽ� ����
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


	//Ư�� ��� ã��
	Node* findNode(T data)
	{
		Node* current = head;
		while (current != nullptr && current->data != data)
		{
			current = current->next;
		}

		return current;
	}


	//����Ʈ ���
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
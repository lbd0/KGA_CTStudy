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


	//�� �տ� ��� �ֱ�
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


	//Ư�� ��ġ �ڿ� �߰�
	void insert_push(Node* prev, T data)
	{
		Node* node = new Node(data);
		node->next = prev->next;
		prev->next = node;

	}


	//�� �ڿ� �߰�
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


	//�Ǿ� ����
	void pop_front()
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}


	//Ư�� ��ġ �� ����
	void erase_after(Node* prev)
	{
		Node* temp = prev->next;
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

		if (current->next!=nullptr)
		{
			Node* temp = current->next;
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

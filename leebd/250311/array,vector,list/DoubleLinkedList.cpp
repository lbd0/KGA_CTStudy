#include <iostream>
using namespace std;

template <typename T>
class DoubleLinkedList
{
private:
	struct Node
	{
		T data;		// ������ / �ڷ�

		Node* next;		// ���� ��带 ����Ű�� ������
		Node* prev;		// ���� ��带 ����Ű�� ������

		Node(T data) :data(data), next(nullptr), prev(nullptr) {}
	};

	Node* head;		// ����Ʈ�� ù ��° ���

public:
	DoubleLinkedList() { head = nullptr; }			// ������

	// �� �տ� �߰�
	void push_front(T data)
	{
		Node* node = new Node(data);			// ���ο� ��� ����

		if (head == nullptr)		// ����Ʈ�� ����ִٸ�
		{
			head = node;			// ���ο� ��带 ����Ʈ�� ù ��° ���� ����
		}
		else
		{									// ����Ʈ�� ������� ������
			node->prev = nullptr;	// ù ��° ����� ���� �����ʹ� ��������
			node->next = head;		// ���ο� ����� �����͸� ����Ʈ�� ù ��° ���� ����
			head = node;				// ����Ʈ�� ù ��° ��带 ���ο� ���� ����
		}
	}

	// Ư�� ��ġ �ڿ� �߰�
	void insert_after(Node* prev, T data)
	{
		Node* node = new Node(data);				// ���ο� ��� ����
		node->next = prev->next;						// ���ο� ����� �����͸� �߰��Ϸ��� ��ġ ���� ���� ����
		prev->next = node;								// �߰��Ϸ��� ��ġ �� ����� �����͸� ���ο� ���� ����

		node->prev = prev;							// �� ����� ���� ��� ������ ����
		node->next->prev = node;					// �� ��� ���� ����� ���� �����͸� �� ���� ����
	}

	// �� �ڿ� �߰�
	void append(T data)
	{
		Node* node = new Node(data);			// ���ο� ��� ����

		if (head == nullptr)			// ����Ʈ�� ����ִٸ�
		{
			head = node;			// ���ο� ��带 ù ��° ���� ����
			return;
		}

		// ����Ʈ�� ������� �ʴٸ�
		Node* current = head;		// ���� ��带 ����Ű�� ������ ���� 
		while (current->next != nullptr)			// ���� ����Ʈ���� �� �ڿ� �ִ� ��� ã��
		{
			current = current->next;
		}
		current->next = node;			// �� �ڿ� �ִ� ����� �����Ϳ� ���ο� ��� ����
		node->prev = current;			// �� ����� ���� �����͸� �� �ڿ� �ִ� ���� ����
	}

	// �� �� ����
	void pop_front()
	{
		if (head == nullptr) return;

		Node* temp = head;				// ������ ���
		head = head->next;				// ����Ʈ�� ù ��° ��带 �� ���� ���� ����
		head->prev = nullptr;			// ���ο� ��� ����� ���� �����͸� �������ͷ� 
		delete temp;							// ��� ����
	}

	// Ư�� ��ġ �� ����
	void erase_after(Node* prev)
	{
		Node* temp = prev->next;			// Ư�� ��ġ �ڿ� �ִ� ��尡 ������ ���
		prev->next = prev->next->next;		// Ư�� ��ġ ����� �����͸� ������ ��� �����ͷ� ����
		prev->next->prev = prev;				// ������ ��� ���� ����� ���� �����͸� Ư�� ��ġ�� ����
		delete temp;									// ��� ����
	}

	// data ã�Ƽ� ����
	void remove(T data)
	{
		Node* current = head;				// ���� ����Ű�� �ִ� ���
		while (current->next != nullptr && current->next->data != data)		// data�� ������ �ִ� ����� �� ��� ã��
		{
			current = current->next;
		}

		if (current->next != nullptr)
		{
			Node* temp = current->next;				// ������ ���� ���� ����� ���� ���
			current->next = current->next->next;		// ���� ����� �����ʹ� ������ ����� �����Ϳ� ����
			current->next->prev = current;				// ������ ��� ���� ����� ���� �����͸� Ư�� ��ġ�� ����
			delete temp;				// ��� ����
		}
	}

	// Ư�� ��� ã��
	Node* findNode(T data)
	{
		Node* current = head;			// ���� ����Ű�� �ִ� ���
		while (current != nullptr && current->data != data)			// �����͸� ���� ��� ã��
		{
			current = current->next;
		}

		return current;
	}

	// ����Ʈ ���
	void print()
	{
		Node* current = head;			// ���� ���
		while (current != nullptr)		// ����Ʈ�� ������ ������ �ݺ�
		{
			cout << current->data << " ";			// ������ ���
			current = current->next;
		}
		cout << endl;
	}

	void reversePrint()
	{
		Node* current = head;		// ���� ��带 ����Ű�� ������ ���� 
		while (current->next != nullptr)			// ���� ����Ʈ���� �� �ڿ� �ִ� ��� ã��
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
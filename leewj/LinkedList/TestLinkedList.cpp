#include <iostream>

template <typename T>
struct Node {
	T data;
	Node* next = nullptr;
};

template <typename T>
class LinkedList {
public:
	LinkedList() { }

	Node<T>* head;

	int Find(T data) {
		int i = 0;
		Node<T>* current = head;

		while (current) {
			if (data == current->data) {
				return i;
			}
			current = current->next;
			++i;
		}

		return -1;
	}

	bool Add(T data, int index) {
		if (index < 0) return false;

		if (index == 0) {
			Node<T>* tmp = head;
			head = new Node<T>();
			head->data = data;
			head->next = tmp;
			return true;
		}

		int i = 1;
		Node<T>* current = head;

		while (current && i < index) {
			current = current->next;
			++i;
		}

		if (!current || i < index) {
			return false;
		}

		Node<T>* tmp = current->next;
		current->next = new Node<T>();
		current->next->data = data;
		current->next->next = tmp;

		return true;
	}

	bool Delete(int index) {
		if (index < 0) return false;

		if (index == 0) {
			if (!head) return false;

			Node<T>* tmp = head->next;
			delete head;
			head = tmp;

			return true;
		}

		int i = 1;
		Node<T>* current = head;
		Node<T>* prev = nullptr;

		while (current && i <= index) {
			prev = current;
			current = current->next;
			++i;
		}

		if (!current || i < index) {
			return false;
		}

		prev->next = current->next;
		delete current;
		current = nullptr;

		return true;
	}

	void PrintList() {
		Node<T>* current = head;
		while (current) {
			std::cout << current->data << "\n";
			current = current->next;
		}
	}
};

int main() {
	LinkedList<int> ll;
	ll.Add(0, 0);

	ll.PrintList();

	ll.Add(1, 1);

	ll.Add(3, 1);

	ll.Add(5, 0);

	std::cout << "\n";
	ll.PrintList();

	ll.Delete(2);

	std::cout << "\n";
	ll.PrintList();

	ll.Delete(ll.Find(1));

	std::cout << "\n";
	ll.PrintList();

	return 0;
}
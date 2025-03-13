#include <iostream>
#include <string>
#include <vector>
#include <list>

//1. 단방향 리스트

using namespace std;



struct DBNode
{
	int data;
	DBNode* next;
	DBNode* prev;

	DBNode(int num)
	{
		data = num;
		next = nullptr;
		prev = nullptr;
	}
};

DBNode* Head = nullptr;
DBNode* CurPointer = nullptr;



#if 단일 연결 리스트

struct Node
{
	int data;
	Node* next;

	Node(int num)
	{
		data = num;
		next = nullptr;
	}
};



Node* Head = nullptr;
Node* CurPointer = nullptr;


void CreateNodeList(int num)
{
	for (int i = 0; i < num; i++)
	{
		//새로운 노드 생성
		Node* node = new Node(i);
		if (Head == nullptr)
		{
			Head = node;
			CurPointer = Head;
		}
		else
		{
			CurPointer->next = node;
			CurPointer = node;
		}
	}
}

void AddNodeList(int num)
{
	Node* node = new Node(num);
	// 새롭게 노드를 추가할 때
	if (Head == nullptr)
	{
		Head = node;
	}
	// 이미 노드가 있을 때
	CurPointer = Head;
	while (CurPointer->next != nullptr)
	{
		CurPointer = CurPointer->next;
	}

	CurPointer->next = node;
}

void PrintNodeList()
{
	CurPointer = Head;
	while (CurPointer != nullptr)
	{
		cout << "data : " << CurPointer->data << endl;
		CurPointer = CurPointer->next;
	}
	cout << "리스트 종료" << endl;
}

void DeleteNodeList(int index)
{
	CurPointer = Head;
	for (int i = 0; i < index - 1; i++)
	{
		CurPointer = CurPointer->next;
	}

	CurPointer->next = CurPointer->next->next;

}

#endif 

// 2. 이중 연결 리스트
void CreateDBNodeList(int num)
{
	for (int i = 0; i < num; i++)
	{
		DBNode* node = new DBNode(i);
		if (Head == nullptr)
		{
			Head = node;
			CurPointer = Head;
		}
		else
		{
			CurPointer->next = node;
			node->prev = CurPointer;
			CurPointer = CurPointer->next;
		}

	}
}

void PrintDBNodeListFromHead()
{
	cout << "머리부터 출력" << endl;
	CurPointer = Head;
	while (CurPointer != nullptr)
	{
		cout << CurPointer->data << endl;
		CurPointer = CurPointer->next;
	}
}

void PrintDBNodeListFromTail()
{
	cout << "꼬리부터 출력" << endl;
	CurPointer = Head;
	while (CurPointer->next != nullptr)
	{
		CurPointer = CurPointer->next;
	}

	while (CurPointer != nullptr)
	{
		cout << CurPointer->data << endl;
		CurPointer = CurPointer->prev;
	}
}


void AddDBNodeList(int index, int data)
{
	CurPointer = Head;


	DBNode* dbNode = new DBNode(data);
	if (Head == nullptr)
	{
		Head = dbNode;
		CurPointer = Head;
		return;
	}

	for (int i = 0; i < index; i++)
	{
		CurPointer = CurPointer->next;
	}

	CurPointer->next->prev = dbNode;
	dbNode->next = CurPointer->next;
	dbNode->prev = CurPointer;
	CurPointer->next = dbNode;


}

void DeleteDBNodeList(int index)
{
	CurPointer = Head;

	if (Head == nullptr)
	{
		return;
	}

	for (int i = 0; i < index - 1; i++)
	{
		CurPointer = CurPointer->next;
	}

	CurPointer->next = CurPointer->next->next;
	delete CurPointer->next->prev;
	CurPointer->next->prev = CurPointer;

}





int main()
{
	// 1. 단일 연결 리스트
	/*CreateNodeList(5);
	PrintNodeList();
	AddNodeList(10);
	cout << "리스트 추가" << endl;
	PrintNodeList();
	cout << "리스트 삭제" << endl;
	DeleteNodeList(2);
	PrintNodeList();*/


	// 2. 이중 연결 리스트
	CreateDBNodeList(5);
	PrintDBNodeListFromHead();
	PrintDBNodeListFromTail();
	AddDBNodeList(2, 100);
	PrintDBNodeListFromHead();
	DeleteDBNodeList(3);
	PrintDBNodeListFromHead();
}


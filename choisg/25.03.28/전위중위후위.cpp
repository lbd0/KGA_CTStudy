//전위식: Root-> Left->Right
//중위식: Left-> Root->Right
//후위식: Left->Right->Root

#include <iostream>
#include <vector>

using namespace std;

struct Tree
{
	int Data;
	Tree* Left;
	Tree* Right;
};

struct TreeRoot
{
	Tree* Root;
};

void PreOrder(Tree* temp) {
	if (!temp) return;

	
		cout << temp->Data;
	PreOrder(temp->Left);
	PreOrder(temp->Right);

	

}

void InOrder(Tree* temp) {
	if (!temp) return;

	
		InOrder(temp->Left);
	cout << temp->Data;
	InOrder(temp->Right);



}

void PostOrder(Tree* temp) {
	if (!temp) return;


		PostOrder(temp->Left);
	PostOrder(temp->Right);
	cout << temp->Data;

}

TreeRoot CreateTree()
{


		//				A(10)
		//		B(5)				C(15)
		//	D(3)	E(7)		F(13)		G(18)

		Tree* A = new Tree{ 10, nullptr, nullptr };
	Tree* B = new Tree{ 5, nullptr, nullptr };
	Tree* C = new Tree{ 15, nullptr, nullptr };
	Tree* D = new Tree{ 3, nullptr, nullptr };
	Tree* E = new Tree{ 7, nullptr, nullptr };
	Tree* F = new Tree{ 13, nullptr, nullptr };
	Tree* G = new Tree{ 18, nullptr, nullptr };

	A->Left = B;
	A->Right = C;
	B->Right = E;
	B->Left = D;
	C->Right = G;
	C->Left = F;

	TreeRoot BinaryTree;
	BinaryTree.Root = A;
	return BinaryTree;


}

int main()
{

	TreeRoot FinalTree = CreateTree();

	PreOrder(FinalTree.Root);
	cout << endl;

	InOrder(FinalTree.Root);
	cout << endl;

	PostOrder(FinalTree.Root);
	cout << endl;

}
#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <stack> // DFS�� stack ���

using namespace std;

// -------------------------------
// ����(Edge) ����ü ����
// -------------------------------
template <typename T>
struct Edge
{
	unsigned src;   // ������ ���� ����
	unsigned dst;   // ������ �� ����
	T weight;       // ������ ����ġ
};

// -------------------------------
// �׷��� Ŭ���� ���� (���� ����Ʈ ���)
// -------------------------------
template <typename T>
class Graph
{
public:
	// N���� �������� �׷��� �ʱ�ȭ
	Graph(unsigned N) : V(N) {}

	// ������ ���� ��ȯ
	auto vertices() const { return V; }

	// ��ü ���� ����Ʈ ��ȯ
	auto& edges() const { return edge_list; }

	// ���� v���� �����ϴ� ��� ������ ��ȯ
	auto edges(unsigned v) const
	{
		vector<Edge<T>> edges_from_v;

		for (auto& e : edge_list)
		{
			if (e.src == v)
			{
				// v���� ����ϴ� ������ ����
				edges_from_v.emplace_back(e);
			}
		}

		return edges_from_v;
	}

	// ���� �߰� �Լ� (���� ID ��ȿ�� �˻� ����)
	void add_edge(Edge<T>&& e)
	{
		if (e.src >= 1 && e.src <= V && e.dst >= 1 && e.dst <= V)
		{
			edge_list.emplace_back(e); // ��ȿ�� �����̸� �߰�
		}
		else
		{
			cerr << "����: ��ȿ ������ ��� ����!" << endl;
		}
	}

	// ��� ������ ���� friend �Լ�
	template <typename U>
	friend ostream& operator<< (ostream& os, const Graph<U>& G);

private:
	unsigned V;                 // ���� ����
	vector<Edge<T>> edge_list;	// ���� ����Ʈ
};

// -------------------------------
// �׷��� ��� �Լ� (������ ����� ������ ���)
// -------------------------------
template <typename U>
ostream& operator<< (ostream& os, const Graph<U>& G)
{
	for (unsigned i = 1; i < G.vertices(); i++)  // 1������ ���
	{
		os << i << ":\t";

		auto edges = G.edges(i);

		for (auto& e : edges)
		{
			os << "{" << e.dst << ": " << e.weight << "}, ";
		}

		os << endl;
	}
	return os;
}

// -------------------------------
// ���ÿ� �׷��� ���� �Լ� (������ �׷���ó�� ����� ���� ����)
// -------------------------------
template <typename T>
auto create_reference_graph()
{
	Graph<T> G(9); // ������ 1~8������ ��� (0�� ����)

	map<unsigned, vector<pair<unsigned, T>>> edge_map;
	// �� ������ ����� ���� ���� (����ġ�� 0)
	edge_map[1] = { {2, 0}, {5, 0} };
	edge_map[2] = { {1, 0}, {5, 0}, {4, 0} };
	edge_map[3] = { {4, 0}, {7, 0} };
	edge_map[4] = { {2, 0}, {3, 0}, {5, 0}, {6, 0}, {8, 0} };
	edge_map[5] = { {1, 0}, {2, 0}, {4, 0}, {8, 0} };
	edge_map[6] = { {4, 0}, {7, 0}, {8, 0} };
	edge_map[7] = { {3, 0}, {6, 0} };
	edge_map[8] = { {4, 0}, {5, 0}, {6, 0} };

	// ���� �߰� (Edge ����ü ���·�)
	for (auto& i : edge_map)
	{
		for (auto& j : i.second)
		{
			G.add_edge(Edge<T>{ i.first, j.first, j.second });
		}
	}

	return G;
}

// -------------------------------
// ���� �켱 Ž�� (DFS) �˰��� ����
// -------------------------------
template <typename T>
auto depth_first_search(const Graph<T>& G, unsigned start)
{
	stack<unsigned> stack;         // DFS�� ������ ���
	set<unsigned> visited;         // �湮�� ���� ����
	vector<unsigned> visit_order;  // �湮 ���� ����

	stack.push(start);             // ���� ���� ���ÿ� push

	while (!stack.empty())
	{
		auto current_vertex = stack.top(); // ���� �������� �߰��� ���� Ȯ��
		stack.pop();					   // �ش� ���� ����

		if (visited.find(current_vertex) == visited.end())
		{
			visited.insert(current_vertex);        // �湮 ǥ��
			visit_order.push_back(current_vertex); // �湮 ���� ���

			// ����� ���� ��ȸ
			for (auto& e : G.edges(current_vertex))
			{
				// �湮���� ���� ���� �����̶�� ���ÿ� push
				if (visited.find(e.dst) == visited.end())
				{
					stack.push(e.dst);
				}
			}
		}
	}

	return visit_order; // ��ü �湮 ���� ��ȯ
}

// -------------------------------
// main �Լ�: �׷��� ����, DFS ����
// -------------------------------
int main()
{
	using T = unsigned; // ����ġ Ÿ�� ����

	auto G = create_reference_graph<T>(); // ���� �׷��� ����

	cout << "[�Է� �׷���]" << endl;
	cout << G << endl;

	cout << "[DFS �湮 ����]" << endl;
	auto dfs_visit_order = depth_first_search(G, 1); // 1�� �������� DFS ����

	for (auto v : dfs_visit_order)
	{
		cout << v << endl; // �湮 ���� ���
	}
}

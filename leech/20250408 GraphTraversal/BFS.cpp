#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <queue>

using namespace std;

// -------------------------------
// �׷������� ����ϴ� ����(Edge) ����ü ����
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

	// ���� ���� ��ȯ
	auto vertices() const { return V; }

	// ��ü ���� ����Ʈ ��ȯ (�б� ����)
	auto& edges() const { return edge_list; }

	// ���� v���� �����ϴ� ������ ��ȯ
	auto edges(unsigned v) const
	{
		vector<Edge<T>> edges_from_v;
		for (auto& e : edge_list)
		{
			if (e.src == v)
			{
				edges_from_v.emplace_back(e); // �ش� �������� ������ ���� ����
			}
		}
		return edges_from_v;
	}

	// ���� �߰�
	void add_edge(Edge<T>&& e)
	{
		// ������ �� �� ������ ��ȿ���� �˻�
		if (e.src >= 1 && e.src <= V && e.dst >= 1 && e.dst <= V)
		{
			edge_list.emplace_back(e); // ��ȿ�ϸ� �߰�
		}
		else
		{
			cerr << "����: ��ȿ ������ ��� ����!" << endl;
		}
	}

	// �׷����� ����ϴ� �Լ� ���� (friend �Լ�)
	template <typename U>
	friend ostream& operator<< (ostream& os, const Graph<U>& G);

private:
	unsigned V;                 // ������ ����
	vector<Edge<T>> edge_list;	// ��ü ���� ����Ʈ
};

// -------------------------------
// �׷��� ��� ������ �����ε�
// �� ������ ����� �������� ���
// -------------------------------
template <typename U>
ostream& operator<< (ostream& os, const Graph<U>& G)
{
	for (unsigned i = 1; i < G.vertices(); i++)		// 1������ ���� (0���� ��� �� ��)
	{
		os << i << ":\t";	// ���� ��ȣ ���

		auto edges = G.edges(i);	// �ش� �������� ������ ������

		for (auto& e : edges)
		{
			os << "{" << e.dst << ": " << e.weight << "}, ";	// �������� ����ġ ���
		}

		os << endl;
	}
	return os;
}

// -------------------------------
// ������ �׷��� ���� �Լ�
// ������ 1~8��, ����ġ�� ��� 0
// -------------------------------
template <typename T>
auto create_reference_graph()
{
	Graph<T> G(9);	// ������ 1~8������ (0���� �̻��, 9���� ����)

	map<unsigned, vector<pair<unsigned, T>>> edge_map;

	// ������ ���� ���� ���� ���� (������ �׷��� ���·� ����� ����)
	edge_map[1] = { {2, 0}, {5, 0} };
	edge_map[2] = { {1, 0}, {5, 0}, {4, 0} };
	edge_map[3] = { {4, 0}, {7, 0} };
	edge_map[4] = { {2, 0}, {3, 0}, {5, 0}, {6, 0}, {8, 0} };
	edge_map[5] = { {1, 0}, {2, 0}, {4, 0}, {8, 0} };
	edge_map[6] = { {4, 0}, {7, 0}, {8, 0} };
	edge_map[7] = { {3, 0}, {6, 0} };
	edge_map[8] = { {4, 0}, {5, 0}, {6, 0} };

	// ���ǵ� edge_map�� �������� ���� �߰�
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
// �ʺ� �켱 Ž�� (BFS) �˰��� ����
// -------------------------------
template <typename T>
auto breadth_first_search(const Graph<T>& G, unsigned start)
{
	queue<unsigned> queue;          // Ž���� ����� ť
	set<unsigned> visited;          // �湮�� ���� ����
	vector<unsigned> visit_order;   // �湮 ������ ����

	queue.push(start);              // ���� ������ ť�� ����

	while (!queue.empty())
	{
		auto current_vertex = queue.front(); // ���� ť�� front ����
		queue.pop();                         // ť���� ����

		// �湮���� ���� �����̶�� ó��
		if (visited.find(current_vertex) == visited.end())
		{
			visited.insert(current_vertex);        // �湮 ǥ��
			visit_order.push_back(current_vertex); // �湮 ���� ���

			// ���� ������ ����� ��� ���� ������ ����
			for (auto& e : G.edges(current_vertex))
			{
				// ���� �湮���� ���� �����̶�� ť�� �߰�
				if (visited.find(e.dst) == visited.end())
				{
					queue.push(e.dst);
				}
			}
		}
	}

	return visit_order; // ��ü �湮 ���� ��ȯ
}

// -------------------------------
// main �Լ�
// -------------------------------
int main()
{
	using T = unsigned; // ����ġ Ÿ���� unsigned�� ����

	// �׷��� ����
	auto G = create_reference_graph<T>();
	cout << "[�Է� �׷���]" << endl;
	cout << G << endl;

	// BFS ����
	cout << "[BFS �湮 ����]" << endl;
	auto bfs_visit_order = breadth_first_search(G, 1); // 1�� �������� ����

	// �湮 ���� ���
	for (auto v : bfs_visit_order)
	{
		cout << v << endl;
	}
}

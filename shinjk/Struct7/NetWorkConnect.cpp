#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;


struct Edge
{
	int a, b, cost; // a�� b�� �����ϴ� ���� ��� cost

	bool operator<(const Edge& other)const // ������ �����ε�
	{
		return cost < other.cost;
	}
};

int findParent(vector<int>& parent, int x) // �θ��� ã��
{
	if (parent[x] != x)
	{
		parent[x] = findParetn(parent, parent[x]); // ��� ����
	}
	return parent[x];
}

void unionParent(vector<int>& parent, int a, int b) // �� ���� ��ġ��
{
	a = findParent(parent, a);
	b = findParent(parent, b);

	if (a < b)
	{
		parent[b] = a;
	}

	else
	{
		parent[a] = b;
	}
}

int main()
{
	int n, m;
	cin >> n >> m; // ��ǻ�� ��, ���ἱ ��

	vector<Edge>edges(m);
	for (int i = 0; i < m; ++i)
	{
		cin >> edges[i].a >> edges[i].b >> edges[i].cost; // ���� �Է�
	}

	sort(edges.begin(), edges.end()); // ����, ��� �������� �������� ����

	vector<int>parent(n + 1); // �� ��� �θ� �ڱ��ڽ����� �ʱ�ȭ
	for (int i = 1; i <= n; ++i)
	{
		parent[i] = i;
	}

	int totalCost = 0; // �ּ� ��� ����

	for (const auto& edge : edges)
	{
		if (findParent(parent, edge.a) != findParent(parent, edge.b))
		{
			unionParent(paretn, edge.a, edge.b); // �� ���� ����
			totalCost += edge.cost; // ��� ����
		}
	}
	cout << totalCost << endl;
	return 0;
}
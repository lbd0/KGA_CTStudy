#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;


struct Edge
{
	int a, b, cost; // a와 b를 연결하는 간선 비용 cost

	bool operator<(const Edge& other)const // 연산자 오버로딩
	{
		return cost < other.cost;
	}
};

int findParent(vector<int>& parent, int x) // 부모노드 찾기
{
	if (parent[x] != x)
	{
		parent[x] = findParetn(parent, parent[x]); // 경로 압축
	}
	return parent[x];
}

void unionParent(vector<int>& parent, int a, int b) // 두 집합 합치기
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
	cin >> n >> m; // 컴퓨터 수, 연결선 수

	vector<Edge>edges(m);
	for (int i = 0; i < m; ++i)
	{
		cin >> edges[i].a >> edges[i].b >> edges[i].cost; // 간선 입력
	}

	sort(edges.begin(), edges.end()); // 간선, 비용 기준으로 오름차순 정렬

	vector<int>parent(n + 1); // 각 노드 부모 자기자신으로 초기화
	for (int i = 1; i <= n; ++i)
	{
		parent[i] = i;
	}

	int totalCost = 0; // 최소 비용 저장

	for (const auto& edge : edges)
	{
		if (findParent(parent, edge.a) != findParent(parent, edge.b))
		{
			unionParent(paretn, edge.a, edge.b); // 두 정점 연결
			totalCost += edge.cost; // 비용 누적
		}
	}
	cout << totalCost << endl;
	return 0;
}
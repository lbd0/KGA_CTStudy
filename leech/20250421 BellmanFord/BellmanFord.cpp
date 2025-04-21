#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int NoConnection = INT_MAX;

struct Edge
{
	int src;
	int dst;
	int wight;
};

vector<int> BellmanFord(vector<Edge> edges, int v, int start) 
{
	// v개의 NoConnection으로 이루어진 백터 생성
	vector<int> distance(v, NoConnection);	
	distance[start] = 0;

	for (int i = 0; i < v - 1; ++i) 
		{
		// v - 1번
		for (Edge& edge : edges) 
		{
			// 시작 정점이 전체 간선과 이어져있지 않다면
			if (distance[edge.src] == NoConnection) 
			{
				continue;
			}

			// 인접한 정점이 새로운 경로보다 크면 갱신
			if (distance[edge.dst] > distance[edge.src] + edge.wight) 
			{
				distance[edge.dst] = distance[edge.src] + edge.wight;
			}
		}
	}

	for (Edge& edge : edges)
	{
		if (distance[edge.src] == NoConnection)
		{
			continue;
		}

		if (distance[edge.dst] > distance[edge.src] + edge.wight)
		{
			cout << "음수 가중치 사이클 발견" << endl;
			return{};
		}
	}

	return distance;
}

int main()
{
	int v = 6;
	vector<Edge>edges;

	vector<vector<int>>edge_map
	{
		{0, 1, 3},
		{1, 3, -8},
		{2, 1, 3},
		{2, 5, 5},
		{3, 2, 3},
		{2, 4, 2},
		{4, 5, -1},
		{5, 1, 8}
	};

	for (auto& edge : edge_map)
	{
		edges.emplace_back(Edge{ edge[0],edge[1],edge[2] });
	}

	int start = 0;
	vector<int>distance = BellmanFord(edges, v, start);

	if (!distance.empty())
	{
		cout << "[" << start << "번 정점으로부터 최소 거리]" << endl;

		for (int i = 0; i < distance.size(); ++i)
		{
			if (distance[i] == NoConnection)
			{
				cout << i << "번 정점: 방문하지 않음" << endl;
			}
			else
			{
				cout << i << "번 정점: " << distance[i] << endl;
			}
		}
	}
}

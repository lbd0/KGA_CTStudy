#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int V;
vector<vector<int>> graph;
vector<int> inDegree;
queue<int> q;

void topologySort()
{
	for (int v = 1; v <= V; ++v)
	{
		if (inDegree[v] == 0)
		{
			q.push(v);
		}
	}

	vector<int> result;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		result.push_back(cur);

		for (int next : graph[cur])
		{
			inDegree[next]--;
			if (inDegree[next] == 0)
			{
				q.push(next);
			}
		}
	}

	if (result.size() != V)
	{
		cout << "사이클 발생 : 위상 정렬 불가\n";
	}
	else
	{
		for (int node : result)
		{
			cout << node << " ";
		}
		cout << "\n";
	}
}

int main()
{
	int m;
	cin >> V>> m;

	graph.assign(V + 1, vector<int>());
	inDegree.assign(V + 1, 0);

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		inDegree[b]++;
	}

	topologySort();

	return 0;
}
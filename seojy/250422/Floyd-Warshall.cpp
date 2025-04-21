#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int main()
{
	int n, m;
	cin >> n >> m;

	//dist 배열 초기화
	vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

	for (int i = 1; i <= n; i++)
	{
		dist[i][i] = 0;
	}

	// 간선 정보 입력
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		dist[u][v] = w;	// 무향 그래프 일 땐 dist[v][u] = w
	}

	//3중 for문으로 경유 노드 k 허용
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (dist[i][k] < INF && dist[k][j] < INF
					&& dist[i][k] + dist[k][j] < dist[i][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dist[i][j] == INF)
				cout << "INF ";
			else
				cout << dist[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}

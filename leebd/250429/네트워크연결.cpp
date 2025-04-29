/*************************네트워크연결*****************************
문제
도현이는 컴퓨터와 컴퓨터를 모두 연결하는 네트워크를 구축하려 한다. 
하지만 아쉽게도 허브가 있지 않아 컴퓨터와 컴퓨터를 직접 연결하여야 한다. 
그런데 모두가 자료를 공유하기 위해서는 모든 컴퓨터가 연결이 되어 있어야 한다. 
(a와 b가 연결이 되어 있다는 말은 a에서 b로의 경로가 존재한다는 것을 의미한다. a에서 b를 연결하는 선이 있고, b와 c를 연결하는 선이 있으면 a와 c는 연결이 되어 있다.)

그런데 이왕이면 컴퓨터를 연결하는 비용을 최소로 하여야 컴퓨터를 연결하는 비용 외에 다른 곳에 돈을 더 쓸 수 있을 것이다. 
이제 각 컴퓨터를 연결하는데 필요한 비용이 주어졌을 때 모든 컴퓨터를 연결하는데 필요한 최소비용을 출력하라. 
모든 컴퓨터를 연결할 수 없는 경우는 없다.

~프림 알고리즘 이용하여 풀었습니다~
*****************************************************************/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MAX = 10001;
const int INF = INT_MAX;

int n, m;
int answer = 0;

int dist[MAX];
bool select[MAX];
vector<pair<int, int>> cost[MAX];

void Prim()
{
	for (int i = 1; i <= n; ++i)
	{
		dist[i] = INF;
		select[i] = false;
	}

	dist[1] = 0;
	select[1] = true;

	for (pair<int, int> edge : cost[1])
	{
		int next = edge.first;
		int w = edge.second;
		dist[next] = w;
	}

	for (int i = 1; i <= n - 1; ++i)
	{
		int minCost = INF;
		int minIdx = -1;

		for (int j = 1; j <= n; ++j)
		{
			if (select[j]) continue;
			if (dist[j] < minCost)
			{
				minCost = dist[j];
				minIdx = j;
			}
		}
		if (minIdx == -1)
		{
			return;
		}

		select[minIdx] = true;
		answer += minCost;

		for (pair<int, int> adj : cost[minIdx])
		{
			int next = adj.first;
			int w = adj.second;

			if (!select[next] && dist[next] > w)
				dist[next] = w;
		}
	}

	cout << answer;
}

int main()
{
	
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		cost[a].push_back({ b, c });
		cost[b].push_back({ a, c });
	}

	Prim();
}
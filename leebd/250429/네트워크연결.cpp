/*************************��Ʈ��ũ����*****************************
����
�����̴� ��ǻ�Ϳ� ��ǻ�͸� ��� �����ϴ� ��Ʈ��ũ�� �����Ϸ� �Ѵ�. 
������ �ƽ��Ե� ��갡 ���� �ʾ� ��ǻ�Ϳ� ��ǻ�͸� ���� �����Ͽ��� �Ѵ�. 
�׷��� ��ΰ� �ڷḦ �����ϱ� ���ؼ��� ��� ��ǻ�Ͱ� ������ �Ǿ� �־�� �Ѵ�. 
(a�� b�� ������ �Ǿ� �ִٴ� ���� a���� b���� ��ΰ� �����Ѵٴ� ���� �ǹ��Ѵ�. a���� b�� �����ϴ� ���� �ְ�, b�� c�� �����ϴ� ���� ������ a�� c�� ������ �Ǿ� �ִ�.)

�׷��� �̿��̸� ��ǻ�͸� �����ϴ� ����� �ּҷ� �Ͽ��� ��ǻ�͸� �����ϴ� ��� �ܿ� �ٸ� ���� ���� �� �� �� ���� ���̴�. 
���� �� ��ǻ�͸� �����ϴµ� �ʿ��� ����� �־����� �� ��� ��ǻ�͸� �����ϴµ� �ʿ��� �ּҺ���� ����϶�. 
��� ��ǻ�͸� ������ �� ���� ���� ����.

~���� �˰��� �̿��Ͽ� Ǯ�����ϴ�~
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
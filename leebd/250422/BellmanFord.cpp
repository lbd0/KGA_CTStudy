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
	vector<int> distance(v, NoConnection);
	distance[start] = 0;

	for (int i = 0; i < v - 1; i++)
	{
		for (Edge& edge : edges)
		{
			if (distance[edge.src] == NoConnection)
			{
				continue;
			}

			if (distance[edge.dst] > distance[edge.src] + edge.wight)
			{
				distance[edge.dst] = distance[edge.src] + edge.wight;
			}
		}
	}

	return distance;
}

int main()
{
	int v = 5;
	vector<Edge> edges;

	edges.emplace_back(Edge{ 0, 1, 3 });
	edges.emplace_back(Edge{ 1, 2, 5 });
	edges.emplace_back(Edge{ 1, 3, 10 });
	edges.emplace_back(Edge{ 3, 2 , -7 });
	edges.emplace_back(Edge{ 2, 4, 2 });

	int start = 0;

	vector<int> distance = BellmanFord(edges, v, start);

	cout << start << "�� �������κ��� �ּ� �Ÿ�" << endl;

	for (int i = 0; i < distance.size(); ++i)
	{
		if (distance[i] == NoConnection)
		{
			cout << i << "�� ������ ����Ǿ� ���� ����" << endl;
		}
		else
		{
			cout << i << "�� ���� : " << distance[i] << endl;
		}
	}
}
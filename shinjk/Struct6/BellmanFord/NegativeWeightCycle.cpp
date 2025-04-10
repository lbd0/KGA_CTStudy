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
	vector<int> distance(v, NoConnection);	// v���� NoConnection���� �̷���� ���� ����
	distance[start] = 0;

	for (int i = 0; i < v - 1; i++) {
		// v-1�� ����
		for (Edge& edge : edges) {
			// ��ü ���� ����
			if (distance[edge.src] == NoConnection) {
				// ���� ������ �Ÿ� ���� �̾��� ���� �ʴٸ�
				continue;
			}

			if (distance[edge.dst] > distance[edge.src] + edge.wight) {
				// ������ ������ �Ÿ� ���� ���ο� ��ο� ���� �Ÿ� ������ ũ�� �Ÿ� ���� ������Ʈ��
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
			cout << "���� ����ġ ����Ŭ �߰�" << endl;
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
		{0,1,3},
		{1,3,-8},
		{2,1,3},
		{2,5,5},
		{3,2,3},
		{2,4,2},
		{4,5,-1},
		{5,1,8}
	};

	for (auto& edge : edge_map)
	{
		edges.emplace_back(Edge{ edge[0],edge[1],edge[2] });
	}

	int start = 0;
	vector<int>distance = BellmanFord(edges, v, start);

	if (!distance.empty())
	{
		cout << "[" << start << "�� �������κ��� �ּ� �Ÿ�]" << endl;

		for (int i = 0; i < distance.size(); i++)
		{
			if (distance[i] == NoConnection)
			{
				cout << i << "�� ����: �湮���� ����" << endl;
			}
			else
			{
				cout<<i<<"�� ����: "<<distance[i]<<endl;
			}
		}
	}

}

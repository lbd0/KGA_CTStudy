#include<iostream>
#include<vector>
#include<climits>

using namespace std;

const int NoConnection = INT_MAX;

struct Edge
{
	int src;
	int dst;
	int weight;
};

vector<int> BellManFord(vector<Edge> edges, int v, int start) {
	vector<int> distance(v, NoConnection);
	distance[start] = 0;

	for (int i = 0; i < v - 1; i++)
	{
		for (Edge& edge : edges) {
			if (distance[edge.src] == NoConnection) {
				continue;
			}
			if (distance[edge.dst] > distance.[edge.src] + edge.weight)
			{
				distance[edge.dst] = distance[edge.src] + edge.weight;
			}
		}
	}
	return distance;
}

int main() {
	int v = 5;
	vector<Edge> edges;

	edges.emplace_back(Edge{ 0, 1, 3 });
	edges.emplace_back(Edge{ 1, 2, 5 });
	edges.emplace_back(Edge{ 1, 3, 10 });
	edges.emplace_back(Edge{ 3,2, -7 });
	edges.emplace_back(Edge{ 2, 4, 2 });

	int start = 0;

	vector<int> distance = BellManFord(edges, v, start);

	cout << start << "번 정점으로부터 최소 거리" << endl;

	for (int i = 0; i < distance.size(); i++)
	{
		if (distance[i] == NoConnection) {
			cout << i << "번 정점은 연결되어 있지 않음" << endl;
		}
		else {
			cout << i << "번 정점: " << distance[i] << endl;
		}
	}
}

#include <iostream>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

const int NoConnection = INT_MAX;

struct Edge
{
	int src;
	int dst;
	int wight;

	void print() { cout << src << " " << dst << " " << wight << endl; }
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

	// ���� ����ġ ����Ŭ Ȯ��
	for (Edge& edge : edges)
	{
		if (distance[edge.src] == NoConnection)
		{
			continue;
		}

		if (distance[edge.dst] > distance[edge.src] + edge.wight)
		{
			cout << -1 << endl;		// ���� ����ġ ����Ŭ ������ -1 ���
			return {};
		}
	}

	return distance;
}

int main()
{
	// ���� ��, ���� �� �Է� �ޱ� -> �������� split
	string Num;
	getline(cin, Num);

	stringstream Ss(Num);

	vector<string> CityAndBus;
	string Temp;
	while (Ss >> Temp)
	{
		CityAndBus.push_back(Temp);
	}

	int City = stoi(CityAndBus[0]);
	int Bus = stoi(CityAndBus[1]);

	// �׷��� ���� ����
	vector<Edge> edges;

	for (int i = 0; i < Bus; ++i)
	{
		// ���� ����ŭ �Է� ����
		string Num;
		getline(cin, Num);

		stringstream Ss(Num);

		vector<string> Buses;
		string Temp;

		while (Ss >> Temp)
		{
			Buses.push_back(Temp);
		}

		// �ε����� 0����, ������ 1���� �̹Ƿ� -1 ����� ��
		edges.emplace_back(Edge{ stoi(Buses[0]) - 1, stoi(Buses[1]) - 1, stoi(Buses[2])});
	}

	int start = 0;

	vector<int> distance = BellmanFord(edges, City, start);

	for (int i = 1; i < distance.size(); ++i)
	{
		if (distance[i] == NoConnection)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << distance[i] << endl;
		}
	}
}
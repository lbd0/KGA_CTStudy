#include"iostream"
#include"vector"

using namespace std;

const int NoConnection = 10001;

struct BusWay
{
	int str;//버스 출발지
	int des;//버스 목적지
	int dist;//거리
};

vector<int> KakaoMap(vector<BusWay>busways, int busstation, int start)
{
	vector<int>distance(busstation, NoConnection);//버스정류장 거리 전부 최대치+1 설정
	distance[start] = 0;//시작정류장 거리 0 설정
	for (int i = 0; i < busstation - 1; ++i)
	{
		for (BusWay& busway : busways)
		{
			if (distance[busway.str] == NoConnection)//버스 시작지가 최대치+1이면, 스킵
			{
				continue;
			}

			if (distance[busway.des] > distance[busway.str] + busway.dist)//버스 목적지까지의 거리가 출발지와 거리를 합친거보다 멀때,
			{
				distance[busway.des] = distance[busway.str] + busway.dist;//버스 목적지까지의 거리는 출발지와 거리의 합으로 변경
			}
		}
	}

	for (BusWay& busway : busways)//이미 Busstation-1(V-1) 만큼 돌려봤음에도 불구하고, 검사를 했을때,
	{

		if (distance[busway.des] > distance[busway.str] + busway.dist)//버스 목적지까지의 거리가 버스 출발지와 거리의 합보다 크다면
		{
			return distance = { 0,-1 };//음수의 가중치가 있다는 것이므로, -1 return(main 함수에서 for문을 사용하여 인덱스 1부터 출력을 할 것이기 때문에)
		}
	}
	for (int i = 0; i < distance.size(); ++i)
	{
		if (distance[i] == NoConnection)//만약 거리 중에 최대치+1로 남아있는 것이 있다면
		{
			distance[i] = -1;//전부 -1로 바꿔주기
		}
	}

	return distance;
}

int main()
{
	int n;
	int m;

	vector<BusWay>temp;

	cin >> n;
	cin >> m;

	for (int i = 0; i < m; ++i)
	{
		int str;
		int des;
		int dist;
		cin >> str;
		cin >> des;
		cin >> dist;

		temp.emplace_back(BusWay{ str-1,des-1,dist });
	}

	int start = 0;

	vector<int>distance = KakaoMap(temp, n, start);

	if (!distance.empty())
	{

		for (int i = 1; i < distance.size(); ++i)
		{
			cout << distance[i] << endl;
		}
	}
}
#include"iostream"
#include"vector"

using namespace std;

const int NoConnection = 10001;

struct BusWay
{
	int str;//���� �����
	int des;//���� ������
	int dist;//�Ÿ�
};

vector<int> KakaoMap(vector<BusWay>busways, int busstation, int start)
{
	vector<int>distance(busstation, NoConnection);//���������� �Ÿ� ���� �ִ�ġ+1 ����
	distance[start] = 0;//���������� �Ÿ� 0 ����
	for (int i = 0; i < busstation - 1; ++i)
	{
		for (BusWay& busway : busways)
		{
			if (distance[busway.str] == NoConnection)//���� �������� �ִ�ġ+1�̸�, ��ŵ
			{
				continue;
			}

			if (distance[busway.des] > distance[busway.str] + busway.dist)//���� ������������ �Ÿ��� ������� �Ÿ��� ��ģ�ź��� �ֶ�,
			{
				distance[busway.des] = distance[busway.str] + busway.dist;//���� ������������ �Ÿ��� ������� �Ÿ��� ������ ����
			}
		}
	}

	for (BusWay& busway : busways)//�̹� Busstation-1(V-1) ��ŭ ������������ �ұ��ϰ�, �˻縦 ������,
	{

		if (distance[busway.des] > distance[busway.str] + busway.dist)//���� ������������ �Ÿ��� ���� ������� �Ÿ��� �պ��� ũ�ٸ�
		{
			return distance = { 0,-1 };//������ ����ġ�� �ִٴ� ���̹Ƿ�, -1 return(main �Լ����� for���� ����Ͽ� �ε��� 1���� ����� �� ���̱� ������)
		}
	}
	for (int i = 0; i < distance.size(); ++i)
	{
		if (distance[i] == NoConnection)//���� �Ÿ� �߿� �ִ�ġ+1�� �����ִ� ���� �ִٸ�
		{
			distance[i] = -1;//���� -1�� �ٲ��ֱ�
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
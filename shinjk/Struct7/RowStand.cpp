#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>>next(N + 1); // next[A]�� A���� �ڿ� ������ �л��� ����
	vector<int>beforeCount(N + 1, 0); // �� �л� �տ� ���� �ϴ� ��� ��

	// �� ���� �Է�
	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;
		next[A].push_back(B); // A�� B���� �տ� ���� �Ѵ�
		beforeCount[B]++;	// B �տ� A�� �Ѹ� �þ
	}

	queue<int>q;

	for (int i = 1; i <= N; i++) // �տ� �ƹ��� ��� �Ǵ� �л��� ť�� �ֱ�
	{
		if (beforeCount[i] == 0)
		{
			q.push(i);
		}
	}

	// �� �����
	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		cout << now << ' '; // ���� �ٿ� �����

		// ���� �л����� �ڿ� ������ �л���
		for (int nextStudent : next[now])
		{
			beforeCount[nextStudent]--; // �ջ�� �Ѹ� ���ֱ�

			if (beforeCount[nextStudent] == 0)
			{
				q.push(nextStudent); // �ջ���� 0�̶��, �� �����
			}
		}
	}

	return 0;
}

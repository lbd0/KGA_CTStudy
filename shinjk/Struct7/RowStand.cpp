#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>>next(N + 1); // next[A]에 A보다 뒤에 서야할 학생들 저장
	vector<int>beforeCount(N + 1, 0); // 각 학생 앞에 서야 하는 사람 수

	// 비교 정보 입력
	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;
		next[A].push_back(B); // A가 B보다 앞에 서야 한다
		beforeCount[B]++;	// B 앞에 A가 한명 늘어남
	}

	queue<int>q;

	for (int i = 1; i <= N; i++) // 앞에 아무도 없어도 되는 학생들 큐에 넣기
	{
		if (beforeCount[i] == 0)
		{
			q.push(i);
		}
	}

	// 줄 세우기
	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		cout << now << ' '; // 현재 줄에 세우기

		// 현재 학생보다 뒤에 서야할 학생들
		for (int nextStudent : next[now])
		{
			beforeCount[nextStudent]--; // 앞사람 한명 없애기

			if (beforeCount[nextStudent] == 0)
			{
				q.push(nextStudent); // 앞사람이 0이라면, 줄 세우기
			}
		}
	}

	return 0;
}

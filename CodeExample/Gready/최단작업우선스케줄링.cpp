/*********최단 작업 우선 스케줄링**********
은행 창구에 줄을 서서 순서를 기다리는 사람들이 있습니다.
은행은 하나의 창구에서만 업무를 보고 있고, 대기열에 N명의 사람이 기다리고 있습니다.
이들은 서로 다른 용무로 방문했기 대문에 일 처리에 필요한 시간은 사람들마다 서로 다릅니다.
평균 대기 시간이 최소화될 수 있도록 대기 순서를 다시 정해주세요.

입력 : 대기하는 사람들의 일 처리 시간을 담은 벡터
출력 : 최소화된 평균 대기 시간

예
입력 : { 8, 1, 2, 4, 9, 2, 3, 5}
출력 : 8.875


문제 풀이 아이디어
- 일 처리 시간이 빠른 사람 순으로 대기하면 평균 대기 시간이 짧아짐.
***************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double WaitingTime(vector<int> workTime)
{
	double sum = 0, avg = 0;// 평균 대기 시간을 구하기 위한 합, 평균 변수
	vector<int> waitingTime;// 대기 시간을 저장할 벡터

	for (int i = 0; i < workTime.size(); i++)// 대기 시간 벡터에  대기 시간 저장
	{
		if (i == 0)
		{
			waitingTime.push_back(0);// 첫 번째 사람은 대기 시간 0
			continue;
		}

		waitingTime.push_back(waitingTime[i - 1] + workTime[i - 1]);// 대기 시간 = 앞 사람의 대기 시간 + 앞 사람의 일처리 시간
	}

	// 평균 대기 시간 구하기
	for (auto w : waitingTime)
	{
		sum += w;// 대기 시간 모두 더하고
	}

	avg = sum / workTime.size();// 대기하는 사람 수로 나누기

	return avg;
}

int main()
{
	vector<int> bank = { 8, 1, 2, 4, 9, 2, 3, 5 };

	// 그리디 알고리즘 적용 전
	cout << "정렬 전 평균 대기 시간 : " << WaitingTime(bank) << endl;

	// 그리디 알고리즘 적용
	sort(bank.begin(), bank.end());// 일 처리 시간 오름차순 정렬
	cout << "정렬 후 평균 대기 시간 : " << WaitingTime(bank);
}

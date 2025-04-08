#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;                 // 수업을 들을 수 있는 학생 수
    vector<int> students(n, 1);     // 체육복을 가진 학생을 확인할 배열

    // 잃어버린 학생 확인
    for (auto& l : lost)
    {
        --students[--l];            // 잃어버린 학생은 -1
    }

    // 여벌의 체육복이 있는 학생 확인
    for (auto& r : reserve)
    {
        ++students[--r];            // 여벌이 있는 학생은 +1
    }

    // 전체 학생의 체육복 검사
    for (int i = 0; i < n; ++i)
    {
        // 첫 번째 학생일 경우, 뒤의 학생만 비교
        if (i == 0)
        {
            // 현재 학생이 2벌이고, 뒤의 학생이 0벌일 때
            if (students[i] == 2 && students[i + 1] == 0)
            {
                --students[i];
                ++students[i + 1];
            }
        }
        // 마지막 학생일 경우, 앞의 학생만 비교
        else if (i == n - 1)
        {
            // 현재 학생이 2벌이고, 앞의 학생이 0벌일 때
            if (students[i] == 2 && students[i - 1] == 0)
            {
                --students[i];
                ++answer;
            }
        }
        // 나머지 학생들 비교
        else
        {
            // 현재 학생이 2벌이고, 앞의 학생이 0벌일 때
            if (students[i] == 2 && students[i - 1] == 0)
            {
                --students[i];
                ++answer;
            }
            // 현재 학생이 2벌이고, 뒤의 학생이 0벌일 때
            if (students[i] == 2 && students[i + 1] == 0)
            {
                --students[i];
                ++students[i + 1];
            }
        }

        // 현재 학생이 1벌 이상이 있다면 수업을 들을 수 있는 학생
        students[i] >= 1 ? ++answer : answer;
    }

    // 수업을 들을 수 있는 학생 수 반환
    return answer;
}

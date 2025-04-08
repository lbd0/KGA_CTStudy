#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    // 정렬한 다음 사용하도록
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    
    // 여분이 있지만, 도둑질 당한 학생 제거
    for(int i = 0; i < lost.size();i++)
    {
        for(int n = 0; n < reserve.size();n++)
        {
            if(lost[i] == reserve[n])
            {
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + n);
            }
        }
    }
    
    // 예외사항을 제외한 뒤, 총 학생 수에서 체육복이 없는 아이들을 뺌
    answer = n - lost.size();
    
    
    for(int i = 0; i < lost.size();i++)
    {
        for(int n = 0;n < reserve.size();n++)
        {
            if(lost[i] - 1 <= reserve[n] && lost[i] + 1 >= reserve[n])
            {
                // 빌려줄 수 있는 친구가 있다면 체육복 있는 학생을 늘리고, 해당 reserve에서 제거(또 빌려줄 수 없음)
                answer++;
                reserve.erase(reserve.begin() + n);
            }
        }
    }
    
    
    
    return answer;
}

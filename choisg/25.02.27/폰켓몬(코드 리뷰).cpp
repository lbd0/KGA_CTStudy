문제
대동소이

답
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> s (nums.begin(), nums.end());
    for(const auto & val : s)
        answer = min(s.size(), nums.size() / 2);
    return answer;
}
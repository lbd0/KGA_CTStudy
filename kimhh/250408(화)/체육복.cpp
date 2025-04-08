#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/////////////////////////////////////////////////////////////
아직 다 못했어요ㅠㅠ
하던거라도 올려요. 다 풀고 다시 수정할게요.
/////////////////////////////////////////////////////////////

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    for (int l : lost)
    {
        for (int r : reserve)
        {
            if ((l + 1) == r)
            {
                answer += 1;
            }
        }
    }
    return answer;
}

int main()
{
    vector<int> lfirst = { 2,4 };
    vector<int> lsecond = { 2,4 };
    vector<int> lthird = { 3 };
    vector<int> rfirst = { 1,3,5 };
    vector<int> rsecond = { 3 };
    vector<int> rthird = { 1 };

    std::cout << solution(5, lfirst, rfirst) << std::endl;
    std::cout << solution(5, lsecond, rsecond) << std::endl;
    std::cout << solution(5, lthird, rthird) << std::endl;
}

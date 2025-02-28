/**************폰켓몬******************

*********************************************************/
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    map<int, int> phoneket;
    pair<map<int, int>::iterator, bool> pr;

    for (auto n : nums)
    {
        pr = phoneket.insert(pair<int, int>(n, 1));
        if (!pr.second)
        {
            phoneket[n]++;
        }
    }

    if (phoneket.size() > nums.size() / 2) answer = nums.size() / 2;
    else answer = phoneket.size();

    return answer;
}
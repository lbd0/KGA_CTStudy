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
    int sum = 0;

    for (auto n : nums)
    {
        pr = phoneket.insert(pair<int, int>(n, 1));
        if (!pr.second)
        {
            phoneket[n]++;
        }
    }

    for (auto it = phoneket.begin(); it != phoneket.end(); it++)
    {
        sum += it->second;
    }

    if (phoneket.size() > sum / 2) answer = sum / 2;
    else answer = phoneket.size();

    return answer;
}
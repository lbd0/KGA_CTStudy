// https://school.programmers.co.kr/learn/courses/30/lessons/1845

#include <vector>
#include <map>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    map<int, int> tmap;
    
    for (int i = 0; i < nums.size(); ++i) {
        ++tmap[nums[i]];
    }
    
    if (nums.size() / 2 > tmap.size()) {
        answer = tmap.size();
    }
    else {
        answer = nums.size() / 2;
    }
    
    return answer;
}

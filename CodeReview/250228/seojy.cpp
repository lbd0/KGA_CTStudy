#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    map<int, int> type;
    int num = 0;
    
    for(int i = 0; i < nums.size();i++)
    {
        type.insert({nums.at(i), i});
    }
    
    if(type.size() < nums.size() / 2)
    {
        answer = type.size();
    }
    else
    {
        answer = nums.size() / 2;
    }
    
    
    return answer;
}

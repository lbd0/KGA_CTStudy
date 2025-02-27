#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    map <int, int> pocketmon;
    for(int n : nums) { pocketmon[n]++; }
    return min(pocketmon.size(), nums.size()/2);
}

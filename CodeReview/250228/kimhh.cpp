#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    map <int, int> pocketmon;
    for(int n : nums) { pocketmon[n]++; }
    return min(pocketmon.size(), nums.size()/2);
}

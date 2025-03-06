#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(), score.end(),greater<int>());
    
    for(int i = 1; i <= score.size();i++)
    {
        if(i % m == 0)
        {
            answer += (score.at(i-1) * m * 1);
        }
    }

    
    return answer;
}

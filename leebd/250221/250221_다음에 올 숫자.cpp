/**************다음에 올 숫자******************
문제 설명
등차수열 혹은 등비수열 common이 매개변수로 주어질 때, 마지막 원소 다음으로 올 숫자를 return 하도록 solution 함수를 완성해보세요.

제한사항
2 < common의 길이 < 1,000
-1,000 < common의 원소 < 2,000
common의 원소는 모두 정수입니다.
등차수열 혹은 등비수열이 아닌 경우는 없습니다.
등비수열인 경우 공비는 0이 아닌 정수입니다.
*********************************************************/
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(vector<int> common) {
    int answer = 0;
    
    int sum = 0;
    int a0 = common[0];
    
    int d = common[1] - common[0];
    int r = 0;
    if(common[0] != 0)
        r = common[1] / common[0];
        
    bool isPlus = false;
    
    for(int i=1; i<common.size(); ++i)
    {
        if(common[i] == a0+i*d)
        {
            isPlus = true;
        }
        else if(common[i] == a0*pow(r, i))
        {
            isPlus = false;
        }
    }
    
    if(isPlus)
    {
        answer = a0+common.size()*d;
    }
    else
    {
        answer = a0*pow(r, common.size());
    }
    
    
    return answer;
}
/*
1. 간단한 논리 연산
boolean 변수 x1, x2, x3, x4가 매개변수로 주어질 때, 다음의 식의 true/false를 return 하는 solution 함수를 작성해 주세요.

(x1 ∨ x2) ∧ (x3 ∨ x4)

*/

#include <string>
#include <vector>

using namespace std;

bool vBool(bool x1, bool x2)
{
    if(x1 == true || x2 == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool nBool(bool x1, bool x2)
{
    if(x1 == false || x2 == false)
    {
        return false;
    }
    return true;
}

bool solution(bool x1, bool x2, bool x3, bool x4) {
    bool answer = true;
    
    answer = nBool((vBool(x1, x2)), (vBool(x3,x4)));
    
    return answer;
}

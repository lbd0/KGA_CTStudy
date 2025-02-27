/*
boolean 변수 x1, x2, x3, x4가 매개변수로 주어질 때, 
다음의 식의 true/false를 return 하는 solution 함수를 작성해 주세요.

(x1 ∨ x2) ∧ (x3 ∨ x4)

x	y	x ∨ y	x ∧ y
T	T	T	T
T	F	T	F
F	T	T	F
F	F	F

*/

#include <string>
#include <vector>

using namespace std;

bool solution(bool x1, bool x2, bool x3, bool x4) {
    bool answer = true;
    bool x5;
    bool x6;
    
    if(x1==x2)
    {
        x5=x1;
    }
    else if(x1!=x2)
    {
        x5=true;
    }
    if(x3==x4)
    {
        x6=x3;
    }
    else if(x3!=x4)
    {
        x6=true;
    }
    
    if(x5==x6)
    {
        answer=x5;
    }
    else if(x5!=x6)
    {
        answer=false;
    }
    
    return answer;
}
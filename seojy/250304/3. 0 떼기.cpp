/*
3. 0 떼기
정수로 이루어진 문자열 n_str이 주어질 때, 
n_str의 가장 왼쪽에 처음으로 등장하는 0들을 뗀 문자열을 
return하도록 solution 함수를 완성해주세요.
*/

#include <string>
#include <vector>

using namespace std;

string solution(string n_str) {
    string answer = "";
    bool bIsStart = false;
    
    for(int i = 0; i < n_str.length();i++)
    {
        if(n_str.at(i) == '0' && !bIsStart)
        {
            continue;
        }
        
        bIsStart = true;
        answer += (n_str.at(i));
        
    }
    
    return answer;
}

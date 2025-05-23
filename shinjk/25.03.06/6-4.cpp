/*
문자열 my_string과 정수 n이 매개변수로 주어질 때, 
my_string의 앞의 n글자로 이루어진 문자열을 return 하는 solution 함수를 작성해 주세요.
*/

#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) {
    string answer = "";
    
    while(true)
    {
        answer += my_string.substr(0,1);
        my_string.erase(0,1);
        --n;
        if(n==0)
        {
            break;
        }
    }
    
    return answer;
}
/*
자연수 n을 뒤집어 각 자리 숫자를 원소로 가지는 배열 형태로 리턴해주세요. 
예를들어 n이 12345이면 [5,4,3,2,1]을 리턴합니다.
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string temp = to_string(n);
    
    for(int i=temp.length()-1; i>=0 ;--i)
    {
        answer.push_back(temp[i]-'0');
    }
    
    
    return answer;
}
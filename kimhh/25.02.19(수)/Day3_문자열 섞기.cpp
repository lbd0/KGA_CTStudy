#include <string>
#include <vector>

using namespace std;

string solution(string str1, string str2) {
    string answer = "";
    
    size_t len1 = str1.size();
    size_t len2 = str2.size();
    size_t maxLen = max(len1, len2);
    
    for(size_t i = 0; i < maxLen; i++)
    {
        answer += str1[i];
        answer += str2[i];
    }
    
    return answer;
}


///////////////////////////////////////////////////////////////////////////////////////
// 이건 vscode로 main함수 추가해서 만들어본거
// 함수 만드는 문제 풀다가 그거 이용해서 출력도 하려니까 어떻게 하는지 까먹음;

#include<iostream>
#include <string>
#include <vector>
using namespace std;

string solution(string str1, string str2) {
    string answer = "";

    size_t len1 = str1.size();
    size_t len2 = str2.size();
    size_t maxLen = max(len1, len2);

    for (size_t i = 0; i < maxLen; i++)
    {
        answer += str1[i];
        answer += str2[i];
    }
    return answer;
}

int main()
{
    string str1 = "aaaaa";
    string str2 = "bbbbb";
    string result = solution(str1, str2);
    std::cout << result;
}

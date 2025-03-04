/*
2. 공백으로 구분하기 2
단어가 공백 한 개 이상으로 구분되어 있는 문자열 my_string이 매개변수로 주어질 때, 
my_string에 나온 단어를 앞에서부터 순서대로 담은 문자열 배열을 return 하는 solution 함수를 작성해 주세요.
*/

#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    string str = "";
    
    for(int i = 0; i < my_string.length();i++)
    {
        if(my_string.at(i) == ' '  && str == "")
        {
            continue;
        }
        else if(my_string.at(i) == ' ' && str != "")
        {
            answer.push_back(str);
            str = "";
        }
        else 
        {
            str += (my_string.at(i));
        }
    }
    
    if(str != "")
    {
        answer.push_back(str);
    }
    return answer;
}

/*
문자열 my_string과 정수 배열 index_list가 매개변수로 주어집니다. 
my_string의 index_list의 원소들에 해당하는 인덱스의 글자들을 순서대로
 이어 붙인 문자열을 return 하는 solution 함수를 작성해 주세요.
*/

#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<int> index_list) {
    string answer = "";
    
    for(int i=0;i<index_list.size();++i)
    {
        answer+=my_string.at(index_list[i]);
    }
    
    return answer;
}
/*
Q. 글자 지우기

문자열 my_string과 정수 배열 indices가 주어질 때, my_string에서 indices의 원소에 해당하는 인덱스의 글자를 지우고 이어 붙인 문자열을 return 하는 solution 함수를 작성해 주세요.
*/

#include <string>
#include <vector>
#include <algorithm>

std::string solution(std::string my_string, std::vector<int> indices) {
    
    sort(indices.rbegin(), indices.rend());
    for (auto i : indices) my_string.erase(i, 1);
    
    return my_string;
}
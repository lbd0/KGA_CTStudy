/*
Q. 문자 개수 세기

알파벳 대소문자로만 이루어진 문자열 my_string이 주어질 때, my_string에서 'A'의 개수, my_string에서 'B'의 개수,..., my_string에서 'Z'의 개수, my_string에서 'a'의 개수, my_string에서 'b'의 개수,..., my_string에서 'z'의 개수를 순서대로 담은 길이 52의 정수 배열을 return 하는 solution 함수를 작성해 주세요.
*/

#include <string>
#include <vector>

std::vector<int> solution(std::string my_string) {
    std::vector<int> answer(52, 0);
    
    for (int i = 0; i < my_string.length(); ++i) {
        if ('A' <= my_string[i] && my_string[i] <= 'Z') ++answer[my_string[i] - 65];
        else if ('a' <= my_string[i] && my_string[i] <= 'z') ++answer[my_string[i] - 71];
    }
    
    return answer;
}
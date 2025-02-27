/*
Q. 문자열 여러 번 뒤집기

문자열 my_string과 이차원 정수 배열 queries가 매개변수로 주어집니다. queries의 원소는 [s, e] 형태로, my_string의 인덱스 s부터 인덱스 e까지를 뒤집으라는 의미입니다. my_string에 queries의 명령을 순서대로 처리한 후의 문자열을 return 하는 solution 함수를 작성해 주세요.
*/

#include <string>
#include <vector>
#include <algorithm>

std::string solution(std::string my_string, std::vector<std::vector<int>> queries) {

    for (int i = 0; i < queries.size(); ++i) {
        std::string find_string = my_string.substr(queries[i][0], queries[i][1] - queries[i][0] + 1);
        reverse(find_string.begin(), find_string.end());
        my_string.replace(queries[i][0], find_string.length(), find_string);
    }  
    return my_string;
}
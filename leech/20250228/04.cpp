/*
Q. 문자열 뒤집기


문자열 my_string과 정수 s, e가 매개변수로 주어질 때, my_string에서 인덱스 s부터 인덱스 e까지를 뒤집은 문자열을 return 하는 solution 함수를 작성해 주세요.
*/

#include <string>
#include <algorithm>

std::string solution(std::string my_string, int s, int e) {
    
    std::string find_string = my_string.substr(s, e - s + 1);
    reverse(find_string.begin(), find_string.end());
    return my_string.replace(s, find_string.length(), find_string);
}
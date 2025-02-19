/*
Q. 문자 리스트를 문자열로 변환하기.

문자들이 담겨있는 배열 arr가 주어집니다.
arr의 원소들을 순서대로 이어 붙인 문자열을
return 하는 solution함수를 작성해 주세요.
*/

#include <string>
#include <vector>

std::string solution(std::vector<std::string> arr) {
    std::string answer = "";

    for (int i = 0; i < arr.size(); i++)
    {
        answer += arr[i];
    }

    return answer;
}
/*
Q. 배열 만들기 5

문자열 배열 intStrs와 정수 k, s, l가 주어집니다. intStrs의 원소는 숫자로 이루어져 있습니다.

배열 intStrs의 각 원소마다 s번 인덱스에서 시작하는 길이 l짜리 부분 문자열을 잘라내 정수로 변환합니다. 
이때 변환한 정수값이 k보다 큰 값들을 담은 배열을 return 하는 solution 함수를 완성해 주세요.
*/

#include <string>
#include <vector>

std::vector<int> solution(std::vector<std::string> intStrs, int k, int s, int l) {
    std::vector<int> answer;
    
    for (auto n : intStrs) {
        int temp = stoi(n.substr(s, l)) > k ? stoi(n.substr(s, l)) : 0;
        if (temp != 0) answer.push_back(temp);
    }
    
    return answer;
}
/*
Q. 2의 영역

정수 배열 arr가 주어집니다. 배열 안의 2가 모두 포함된 가장 작은 연속된 부분 배열을 return 하는 solution 함수를 완성해 주세요.

단, arr에 2가 없는 경우 [-1]을 return 합니다.
*/

#include <vector>

std::vector<int> solution(std::vector<int> arr) {
    std::vector<int> answer;
    int first = -1, end = -1;
    
    for (int i = 0; i < arr.size(); ++i) arr[i] == 2 ? first == -1 ? first = i : end = i : 0;
    
    if (first == -1) answer.emplace_back(-1);
    else if (end == -1) answer.emplace_back(2);
    else for (int i = first; i <= end; ++i) answer.emplace_back(arr[i]);
    
    return answer;
}
// https://school.programmers.co.kr/learn/courses/30/lessons/12906

#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    int prev = -1;
    for (int i = 0; i < arr.size(); ++i) {
        if (prev != arr[i]) { // 이전 값과 다르다면 연속 종료
            answer.push_back(arr[i]); // 큐 로직
            prev = arr[i];
        }
    }

    return answer;
}

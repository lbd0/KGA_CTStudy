/*
    https://school.programmers.co.kr/learn/courses/30/lessons/12906?language=cpp
*/

#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    answer.push_back(arr[0]);
    for (int temp : arr) {
        if (answer.back() != temp)
            answer.push_back(temp);
    }
    return answer;
}
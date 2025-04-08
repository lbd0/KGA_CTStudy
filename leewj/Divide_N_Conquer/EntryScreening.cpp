// https://school.programmers.co.kr/learn/courses/30/lessons/43238

#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;

    long long left = 1;
    long long right = 0;
    long long mid = 0;
    long long num = 0;

    for (int i = 0; i < times.size(); ++i) {
        if (times[i] > right) {
            right = times[i];
        }
    }
    right *= n;
    
    while (left <= right) {
        mid = (left + right) / 2;
        num = 0;

        for (int i = 0; i < times.size(); ++i) {
            num += mid / times[i];
        }

        if (num < n) {
            left = mid + 1;
        }
        else if (num >= n) {
            answer = mid;
            right = mid - 1;
        }
    }

    return answer;
}
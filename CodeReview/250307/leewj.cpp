// https://school.programmers.co.kr/learn/courses/30/lessons/135808?language=cpp

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    if (m > score.size()) {
        return 0;
    }
    
    sort(score.begin(), score.end());
    
    for (int i = score.size() - m; i >= 0; i -= m) {
        int min = 10;
        for (int j = i; j < i + m; ++j) {
            if(score[j] < min) {
                min = score[j];
            }
        }
        answer += min * m;
    }
    
    return answer;
}

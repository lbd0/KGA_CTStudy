// https://school.programmers.co.kr/learn/courses/30/lessons/181942

#include <string>
#include <vector>

using namespace std;

string solution(string str1, string str2) {
    string answer = str1 + str2;

    int j = 0;
    int k = 0;
    for (int i = 0; i < answer.length(); ++i) {
        answer[i] = i % 2 == 0 ? str1[j++] : str2[k++];
    }

    return answer;
}
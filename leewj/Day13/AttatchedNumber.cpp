// https://school.programmers.co.kr/learn/courses/30/lessons/181928

#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    stringstream odd;
    stringstream even;

    for (const int& val : num_list) {
        if (val % 2 == 1) {
            odd << to_string(val);
        }
        else {
            even << to_string(val);
        }
    }
    answer = stoi(odd.str()) + stoi(even.str());

    return answer;
}
/*
* https://school.programmers.co.kr/learn/courses/30/lessons/43165
*/


#include <vector>

using namespace std;

void DFS(int& answer, int i, int sign, int sum, vector<int> &numbers, const int& target) {
    sum += sign * numbers[i];

    if (numbers.size() - 1 == i) {
        if (sum == target) ++answer;
        return;
    }
    else {
        DFS(answer, i + 1, 1, sum, numbers, target);
        DFS(answer, i + 1, -1, sum, numbers, target);
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    DFS(answer, 0, 1, 0, numbers, target);
    DFS(answer, 0, -1, 0, numbers, target);

    return answer;
}

int main() {

    return 0;
}
/*
	https://school.programmers.co.kr/learn/courses/30/lessons/42748
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    // commands 안에 있는 것들을 하나씩 뽑음
    for(vector<int> command : commands) {
        
        // i번째 숫자부터 j번째 숫자까지 자른 임시 백터
        vector<int> tempVector;
        
        // 백터 채워줌
        for(int i = command[0] - 1; i < command[1]; i++ ) {
            tempVector.push_back(array[i]);
        }
        
        // #include <algorithm>를 이용해 정렬
        sort(tempVector.begin(), tempVector.end());
        
        // k번째 숫자 뽑아 answer에 넣음
        answer.push_back(tempVector[command[2] - 1]);
    }
    return answer;
}
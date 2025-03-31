#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> person;
    
    // 참가자 증가
    for (auto& name : participant) {
        person[name]++;
    }
    
    // 완주자 감소
    for (auto& name : completion) {
        person[name]--;
    }
    
    // 남은 사람(비완주자)
    for (auto& pair : person) {
        if (pair.second > 0) return pair.first;
    }
}

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    unordered_map<string, int> map1;

    unordered_map<string, int> map2;

    // 전부 unordered_map에 넣음 이미 있으면 +1을 한다
    for (string name : participant) {
        if (map1.find(name) == map1.end()) {
            map1[name] = 1;
        }
        else {
            map1[name] = map1[name] + 1;
        }
    }


    for (string name : completion) {
        if (map2.find(name) == map2.end()) {
            map2[name] = 1;
        }
        else {
            map2[name] = map2[name] + 1;
        }
    }

    for (auto par : map1) {
        if (map2.find(par.first) == map2.end()) {
            // 만약 map1에 있는 key 값이 map2에 없다면
            // 없는 사람이므로 
            return par.first;
        }
        else if (map2[par.first] != par.second) {
            // 동명이인인데 들어온 사람 수가 다르면
            return par.first;
        }
    }


    return answer;
}
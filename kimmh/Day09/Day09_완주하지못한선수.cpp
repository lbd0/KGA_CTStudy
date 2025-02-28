/*
	https://school.programmers.co.kr/learn/courses/30/lessons/42576
*/


#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    map<string, int> map1;

    map<string, int> map2;

    for(string name : participant) {
        if(map1.find(name) == map1.end()) {
            map1[name] = 1;
        }
        else {
            map1[name] = map1[name] + 1;
        }
    }


    for(string name : completion) {
        if(map2.find(name) == map2.end()) {
            map2[name] = 1;
        }
        else {
            map2[name] = map2[name] + 1;
        }
    }


    for(auto par : map1) {
        if(map2.find(par.first) == map2.end()) {
            // 만약 map1에 있는 key 값이 map2에 없다면
            // 없는 사람이므로 
            return par.first;
        }
        else if(map2[par.first] != par.second) {
            return par.first;
        }
    }


    return answer;
}
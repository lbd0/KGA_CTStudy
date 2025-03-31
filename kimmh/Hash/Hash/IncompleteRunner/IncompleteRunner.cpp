#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    unordered_map<string, int> map1;

    unordered_map<string, int> map2;

    // ���� unordered_map�� ���� �̹� ������ +1�� �Ѵ�
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
            // ���� map1�� �ִ� key ���� map2�� ���ٸ�
            // ���� ����̹Ƿ� 
            return par.first;
        }
        else if (map2[par.first] != par.second) {
            // ���������ε� ���� ��� ���� �ٸ���
            return par.first;
        }
    }


    return answer;
}
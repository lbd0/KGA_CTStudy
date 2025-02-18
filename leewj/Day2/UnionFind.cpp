// https://school.programmers.co.kr/learn/courses/30/lessons/43162

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Find(vector<int>& nodes, int val) {
    if (nodes[val] == val) {
        return val;
    }
    else {
        nodes[val] = Find(nodes, nodes[val]);
        return nodes[val];
    }
}

void Union(vector<int>& nodes, int a, int b) {
    a = Find(nodes, a);
    b = Find(nodes, b);
    
    if (a != b) {
        nodes[b] = Find(nodes, a);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    vector<int> nodes(n, 0);

    for (int i = 0; i < nodes.size(); ++i) {
        nodes[i] = i;
    }

    for (int i = 0; i < computers.size(); ++i) {
        for (int j = 0; j < computers[i].size(); ++j) {
            if (i == j) continue;

            if (computers[i][j]) {
                Union(nodes, i, j);
            }
        }
    }

    for (int i = 0; i < nodes.size(); ++i) {
        std::cout << nodes[i] << "\n";
        if (nodes[i] == i) {
            ++answer;
        }
    }

    return answer;
}
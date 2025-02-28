// https://school.programmers.co.kr/learn/courses/30/lessons/49189

#include <string>
#include <vector>
#include <queue>

using namespace std;

void PushPath(const vector<vector<int>>& vertexes, vector<bool>& visited, queue<pair<int, int>>& q, int i, int distance) {
    for (const int& vertex : vertexes[i]) {
        if (!visited[vertex]) {
            visited[vertex] = true;
            q.push(make_pair(vertex, distance));
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    vector<vector<int>> vertexes(n);
    vector<bool> visited(n);
    vector<int> distances(n);
    queue<pair<int, int>> q;

    for (int i = 0; i < edge.size(); ++i) {
        vertexes[edge[i][0] - 1].push_back(edge[i][1] - 1);
        vertexes[edge[i][1] - 1].push_back(edge[i][0] - 1);
    }

    distances[0] = 0;
    visited[0] = true;
    q.push(make_pair(0, 0));

    while (!q.empty()) {
        int vertex = q.front().first;
        distances[vertex] = q.front().second;
        q.pop();
        PushPath(vertexes, visited, q, vertex, distances[vertex] + 1);
    }

    int max = -1;
    for (const int& val : distances) {
        if (max < val) {
            max = val;
        }
    }

    for (const int& val : distances) {
        if (val == max) {
            ++answer;
        }
    }

    return answer;
}
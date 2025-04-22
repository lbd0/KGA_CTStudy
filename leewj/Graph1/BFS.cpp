// https://school.programmers.co.kr/learn/courses/30/lessons/1844

#include <vector>
#include <queue>

using namespace std;

// 큐에 상하 좌우 노드 넣기 (벽인 경우 빼고)
void InsertPathToQ(const vector<vector<int>>& maps, vector<vector<bool>>& visited, queue<pair<pair<int, int>, int>>& q, int i, int j, int distance) {
    if (0 <= i && i < maps.size() && 0 <= j && j < maps[0].size()) {
        if (i - 1 >= 0 && !visited[i - 1][j]) {
            visited[i - 1][j] = true;
            q.push(make_pair(make_pair(i - 1, j), distance + 1));
        }
        if (i + 1 < maps.size() && !visited[i + 1][j]) {
            visited[i + 1][j] = true;
            q.push(make_pair(make_pair(i + 1, j), distance + 1));
        }
        if (j - 1 >= 0 && !visited[i][j - 1]) {
            visited[i][j - 1] = true;
            q.push(make_pair(make_pair(i, j - 1), distance + 1));
        }
        if (j + 1 < maps[0].size() && !visited[i][j + 1]) {
            visited[i][j + 1] = true;
            q.push(make_pair(make_pair(i, j + 1), distance + 1));
        }
    }
}

int FindMinDistance(const vector<vector<int>>& maps) {
    int minDistance = 1000000000;
    // BFS에 쓸 큐
    queue<pair<pair<int, int>, int>> q;
    // 방문한 노드 저장용
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(), false));
    // 0,0에서부터 시작한다
    visited[0][0] = true;

    // 상하좌우 길을 큐에 넣기
    InsertPathToQ(maps, visited, q, 0, 0, 1);

    // 큐가 빌 때까지 BFS
    while (!q.empty()) {
        // 벽인 경우 다음 놈으로
        if (maps[q.front().first.first][q.front().first.second] == 0) {
            q.pop();
            continue;
        }
        // 최소 거리보다 큰 경우 다음 놈으로
        if (q.front().second > minDistance) {
            q.pop();
            continue;
        }

        // 맵 안벗어나게 하기
        if (q.front().first.first == maps.size() - 1 && q.front().first.second == maps[0].size() - 1) {
            minDistance = q.front().second;
            q.pop();
            continue;
        }

        InsertPathToQ(maps, visited, q, q.front().first.first, q.front().first.second, q.front().second);
        q.pop();
    }

    if (minDistance == 1000000000) return -1;

    return minDistance;
}

int solution(vector<vector<int> > maps)
{
    return FindMinDistance(maps);
}

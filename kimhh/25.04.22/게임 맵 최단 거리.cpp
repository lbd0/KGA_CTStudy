#include<vector>
#include <queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    // 거리 배열, -1은 아직 방문 안 함
    vector<vector<int>> dist(n, vector<int>(m, -1));
    // 네 방향: 동, 서, 남, 북
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    queue<pair<int,int>> q;
    // 시작점 (0,0)
    dist[0][0] = 1;
    q.push({0, 0});

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        // 목표 지점에 도달하면 바로 리턴
        if (x == n-1 && y == m-1) {
            return dist[x][y];
        }
        // 네 방향 탐색
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            // 맵을 벗어나지 않고, 벽이 아니며, 아직 방문하지 않은 경우
            if (nx >= 0 && nx < n && ny >= 0 && ny < m
                && maps[nx][ny] == 1 && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    // 큐가 빌 때까지 목표에 도달하지 못했으면 -1 반환
    return -1;
}

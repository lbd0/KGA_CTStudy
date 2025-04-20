#include <vector>
#include <bits/stdc++.h>

using namespace std;

int dy[] = {-1, 0, 1, 0};    // 상, 우, 하, 좌 이동을 위한 y 좌표 변화량
int dx[] = {0, 1, 0, -1};    // 상, 우, 하, 좌 이동을 위한 x 좌표 변화량

// BFS 함수는 주어진 맵에서 최단 경로를 찾음
int BFS(vector<vector<int>> &maps)
{
    // 탐색을 위한 큐
    queue<pair<int, int>> q;
    
    // 맵의 행 크기
    int n = maps.size();
    // 맵의 열 크기
    int m = maps[0].size();

    // 방문한 위치와 거리를 기록하는 테이블 초기화
    vector<vector<int>> table(n, vector<int>(m, 0));
    // 큐에 시작 위치 삽입
    q.push({0, 0});
    // 시작 위치 거리를 1로 초기화
    table[0][0] = 1;
    
    while (q.size())
    {
        // 현재 위치
        pair<int, int> current = q.front();
        q.pop();
        
        // 상, 우, 하, 좌 방향으로 탐색
        for (int i = 0; i < 4; ++i)
        {
            int ny = current.first + dy[i];
            int nx = current.second + dx[i];
            
            // 맵 범위를 벗어나거나, 벽을 만나거나, 이미 방문했을 경우 무시하고 넘어감
            if (ny < 0 || nx < 0 || ny >= n || nx > m || maps[ny][nx] == 0 || table[ny][nx])
                continue;
            
            // 거리 갱신
            table[ny][nx] = table[current.first][current.second] + 1;
            // 새로운 위치를 큐에 삽입
            q.push({ny, nx});
        }
    }
    
    // 목표 지점에 도달한 경우 거리를 반환하고, 그렇지 않으면 -1 반환
    return table[n - 1][m - 1] > 0 ? table[n - 1][m - 1] : -1;
}

int solution(vector<vector<int>> maps)
{
    return BFS(maps);
}

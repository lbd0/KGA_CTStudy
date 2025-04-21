#include<vector>
#include<queue>

using namespace std;

int solution(vector<vector<int> > maps)
{
    
    // 행
    int n = maps.size();
    
    // 열
    int m = maps[0].size();
    queue<pair<int, int>> q;

    maps[0][0] = 1;
    q.push({0,0});
    
    // 4 방향 델타
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    
    while(!q.empty())
    {
        auto [x, y] = q.front();q.pop();
        for(int d =0; d < 4; ++d)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            
            if(nx >= 0 && nx < n && 
               ny < m && ny >= 0 &&
               maps[nx][ny] == 1 )
            {
                maps[nx][ny] = maps[x][y] + 1;
                q.push({nx, ny});
            }
        
        }
    }
    
    // 방문한 곳에 1이 있다면 ( 방문 했다면)
    if (maps[n-1][m-1] == 1) {
        
        return -1;
    }
    return maps[n-1][m-1];
}

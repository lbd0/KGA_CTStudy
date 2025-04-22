/************게임 맵 최단거리***************
문제 설명
ROR 게임은 두 팀으로 나누어서 진행하며, 상대 팀 진영을 먼저 파괴하면 이기는 게임입니다. 
따라서, 각 팀은 상대 팀 진영에 최대한 빨리 도착하는 것이 유리합니다.

지금부터 당신은 한 팀의 팀원이 되어 게임을 진행하려고 합니다. 
다음은 5 x 5 크기의 맵에, 당신의 캐릭터가 (행: 1, 열: 1) 위치에 있고, 상대 팀 진영은 (행: 5, 열: 5) 위치에 있는 경우의 예시입니다.
게임 맵의 상태 maps가 매개변수로 주어질 때, 캐릭터가 상대 팀 진영에 도착하기 위해서 지나가야 하는 칸의 개수의 최솟값을 return 하도록 solution 함수를 완성해주세요. 
단, 상대 팀 진영에 도착할 수 없을 때는 -1을 return 해주세요.

제한사항
maps는 n x m 크기의 게임 맵의 상태가 들어있는 2차원 배열로, n과 m은 각각 1 이상 100 이하의 자연수입니다.
n과 m은 서로 같을 수도, 다를 수도 있지만, n과 m이 모두 1인 경우는 입력으로 주어지지 않습니다.
maps는 0과 1로만 이루어져 있으며, 0은 벽이 있는 자리, 1은 벽이 없는 자리를 나타냅니다.
처음에 캐릭터는 게임 맵의 좌측 상단인 (1, 1) 위치에 있으며, 상대방 진영은 게임 맵의 우측 하단인 (n, m) 위치에 있습니다.
**********************************************/
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int> > maps)
{
	// 현재 위치, 현재 걸음 수 저장할 queue
    queue<pair<pair<int, int>, int>> queue;
    
    // 방문한 적이 있는지 확인하는 vector
    // 한 번 방문한 곳은 또 방문하지 않음.
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(), false));
    // 플레이어 처음 위치 방문으로 저장.
    visited[0][0] = true;
    
    // 좌,우,상,하 로 이동 시 좌표 변화.
    vector<pair<int, int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

	// 처음 위치 queue에 삽입.
    queue.push(make_pair(make_pair(0,0), 1));
    
    while(!queue.empty())
    {
		// 현재 위치 확인할 경우 꺼내고 삭제.
        pair<pair<int, int>, int> currentPos = queue.front();
        queue.pop();
        
        // 현재 좌표 저장.
        int x = currentPos.first.first;
        int y = currentPos.first.second;
        
        // 현재 걸음 수 저장.
        int steps = currentPos.second;
        
        // 상대 팀 진영에 도착하면, 현재 걸음 수 반환.
        if(x == maps[0].size() - 1 && y == maps.size() - 1)
            return steps;
        
        // 상하좌우로 움직임.
        for(pair<int, int> d : direction)
        {
            int nextX = x + d.first;
            int nextY = y + d.second;
            
            // 좌표 이동 시 범위를 벗어나지 않고, 방문한 타일 혹은 벽이 아니라면
            if(nextX >= 0 && nextX < maps[0].size() && nextY >= 0 && nextY < maps.size() && visited[nextY][nextX] != true && maps[nextY][nextX] != 0)
            {
		            // 현재 타일에 방문 표시.
                visited[nextY][nextX] = true;
                // 현재 위치로 이동한 후 q에 삽입.
                queue.push(make_pair(make_pair(nextX, nextY), steps + 1));
            }
        }
    }
    
    return -1;
}
#include<vector>
#include<queue>
using namespace std;

struct Node
{
    int x; //x값
    int y;  //y값
    int dist;  //거리
};

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    int n= maps.size();  //행
    int m=maps[0].size();  //렬
    
// 이동할 수 있는 4가지 방향: 상,하,좌,우
    int dx[]={-1,1,0,0}; //행 변화량
    int dy[]={0,0,-1,1}; //렬 변화량
    
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    visited[0][0]=true; //방문한 칸을 기록하기 위한 배열
    
    queue<Node>q; 
    q.push({0,0,1}); //시작 위치와 거리 1을 queue에 삽입
    
    while(!q.empty()) //queue가 빌때까지
    {
        Node curr=q.front(); 	
        q.pop();
        

        if(curr.x==n-1&&curr.y==m-1) //현재 위치가 도착지점이면
        {
	    answer=curr.dist
            return  answer; //이동거리 반환
        }
        
        for(int i=0;i<4;++i) // 4방향 모두 탐색
        {
            int nx=curr.x+dx[i]; //다음 위치의 x
            int ny=curr.y+dy[i]; //다음 위치의 y
            
            if(nx>=0&&ny>=0&&nx<n&&ny<m) // 다음 위치가 맵 범위 안에 있고, 방문하지 않았으며, 벽이 아닌 경우
            {
                if(!visited[nx][ny]&&maps[nx][ny]==1)
                {
                    visited[nx][ny]=true; //방문처리
                    q.push({nx,ny,curr.dist+1}); //queue에 다음위치와 거리 +1해서 저장
                }
            }
        }
    }
    
    answer=-1; //queue를 다 돌았는데도 도착하지 못한 경우
    
    return answer;
}
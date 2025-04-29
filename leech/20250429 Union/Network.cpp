#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MAX = 1001;        // 최대 정점 수
const int INF = INT_MAX;     // 무한대

int N, M;                    // 정점과 간선의 수
int answer = 0;              // 총 가중치를 저장할 변수
int Dist[MAX];               // MST에 포함된 정점부터 각 정점까지 연결된 간선 중 최소 가중치
bool Select[MAX];            // 정점이 MST에 포함되었는지 여부
vector<pair<int, int>> Cost[MAX];    // 그래프를 표현할 인접 리스트

// 프림 알고리즘
void Prim()
{
    // 초기화
    for (int i = 1; i <= N; ++i)
    {
        Dist[i] = INF;
        Select[i] = false;
    }
    
    // 시작 정점 설정
    Dist[1] = 0;
    Select[1] = true;
    
    // 시작 정점과 직접 연결된 정점들의 Dist 값 초기화
    for(pair<int, int> edge : Cost[1])
    {
        int next = edge.first;
        int w = edge.second;
        Dist[next] = w;        // 상대 정점까지 거리를 간선의 가중치로 설정
    }
    
    // MST에 정점 추가
    for(int i = 1; i < N; ++i)
    {
        int minCost = INF;
        int minIdx = -1;
        
        // 가장 작은 정점 찾기
        for(int j = 1; j <= N; ++j)
        {
            // 이미 방문했을 경우
            if(Select[j]) continue;
            
            // 최소 비용 갱신
            if(Dist[j] < minCost)
            {
                minCost = Dist[j];
                minIdx = j;
            }
        }
        
        // 그래프가 연결되지 않은 경우 예외 처리
        if(minIdx == -1)
        {
            return;
        }
        
        Select[minIdx] = true;
        answer += minCost;
        
        // 새로 추가된 정점과 연결된 간선을 확인하여 Dist 갱신
        for(pair<int, int> adj : Cost[minIdx])
        {
            int next = adj.first;
            int w = adj.second;
            
            // 상대 정점이 포함되지 않았고, 기존 간선의 값보다 작으면 갱신
            if(!Select[next] && Dist[next] > w)
            {
                Dist[next] = w;
            }
        }
    }
    
    cout << answer;
}

int main()
{
    cin >> N >> M;
    
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        Cost[a].push_back({b, c});
        Cost[b].push_back({a, c});
    }
    Prim();
        
    return 0;
}

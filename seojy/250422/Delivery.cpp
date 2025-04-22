#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;
using pii = pair<int, int>;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    // 그래프 만들어두기
    vector<vector<pii>> graph(N+1);
    for(auto& r : road)
    {
        int u = r[0], v = r[1], w = r[2];
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    
    // 거리 배열 초기화
    const int INF = 1e9;
    vector<int> dist(N+1, INF);
    dist[1] = 0;
    
    // 최소 힙 선언 및 초기 선언
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0,1});
    
    // 다익스트라 메인 루프
    while(!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        
        if(d > dist[u]) continue;
        
        for(auto& [v, w] : graph[u])
        {
            if(dist[v] > d + w)
            {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    answer = 0;
    for(int i = 0; i <= N; i ++)
    {
        if(dist[i] <= K)
            answer++;
    }
    
    return answer;
}

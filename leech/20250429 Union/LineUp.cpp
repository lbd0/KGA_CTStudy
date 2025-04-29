#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int V, M;                     // 정점, 간선 수
vector<vector<int>> graph;    // 인접 리스트
vector<int> inDegree;         // 진입 차수 배열
queue<int> q;                 // 위상 정렬용 큐

// 위상 정렬
void topology_sort()
{
    // 진입 차수가 0인 정점을 큐에 삽입
    for (int i = 1; i <= V; ++i)
    {
        if(inDegree[i] == 0)
        {
            q.push(i);
        }
    }
    
    // 위상 정렬 결과 출력용 벡터
    vector<int> result;
    
    // 모든 정점 방문
    while(!q.empty())
    {
        // 현재 처리할 정점을 큐에 꺼냄
        int cur = q.front();
        q.pop();
        result.push_back(cur);
        
        // 현재 정점에서 나가는 간선 확인
        for (int next : graph[cur])
        {
            // 연결된 정점의 진입 차수 감소
            --inDegree[next];
            // 진입 차수가 0이라면, 큐에 삽입
            if(inDegree[next] == 0)
            {
                q.push(next);
            }
        }
    }
    
    // 모든 정점을 다 방문했는지 확인(사이클 판별)
    if(result.size() == V)
    {
        for(int node : result)
        {
            cout << node << " ";
        }
    }
}

int main()
{
    cin >> V >> M;
    
    graph.assign(V + 1, vector<int>());
    inDegree.assign(V + 1, 0);
    
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        
        graph[a].push_back(b);
        ++inDegree[b];
    }
    
    topology_sort();
        
    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    /*
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
    */
    
    const int INF = numeric_limits<int>::max();
    // 인접 리스트: adj[u] = {(v, w), …}
    vector<vector<pair<int,int>>> adj(N+1);
    for (auto &r : road) {
        int u = r[0], v = r[1], w = r[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // 거리 배열 초기화
    vector<int> dist(N+1, INF);
    dist[1] = 0;

    // 최소 힙 (거리, 정점)
    using pii = pair<int,int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});

    // 다익스트라
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto &[v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    // K 이하인 마을 개수 세기
    int count = 0;
    for (int i = 1; i <= N; ++i) {
        if (dist[i] <= K) ++count;
    }
    return count;
}

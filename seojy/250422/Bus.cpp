/*
GPT의 도움을 받았습니다..

*/


#include <iostream>
#include <vector>
#include <tuple>
#include <limits>

using namespace std;

const long long INF = 1e18;

int main() {
    int N, M;
    cin >> N >> M;

    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    vector<long long> dist(N + 1, INF);
    dist[1] = 0;

    // N-1번 반복
    for (int i = 1; i < N; ++i) {
        for (auto [u, v, w] : edges) {
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // N번째 반복에서 값이 갱신되면 음의 사이클 존재
    for (auto [u, v, w] : edges) {
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            cout << -1 << endl;
            return 0;
        }
    }

    // 결과 출력
    for (int i = 2; i <= N; ++i) {
        if (dist[i] == INF) cout << -1 << '\n';
        else cout << dist[i] << '\n';
    }

    return 0;
}

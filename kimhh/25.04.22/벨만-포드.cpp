#include <iostream>
#include <vector>
#include <limits>

int main() {
    // 입출력 속도 최적화
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int V, E;
    std::cin >> V >> E;  // 정점 수 V, 간선 수 E 입력

    struct Edge {
        int u, v;
        long long w;
    };
    std::vector<Edge> edges(E);

    // 간선 정보 입력 (u에서 v로 가중치 w)
    for (int i = 0; i < E; i++) {
        std::cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int src;
    std::cin >> src;  // 시작 정점 입력

    const long long INF = std::numeric_limits<long long>::max();
    std::vector<long long> dist(V + 1, INF);
    dist[src] = 0;  // 시작 정점 거리는 0

    // V-1번 반복하며 최단 거리 갱신
    for (int i = 1; i <= V - 1; i++) {
        bool updated = false;
        for (auto &e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                updated = true;
            }
        }
        // 더 이상 갱신이 없으면 중단
        if (!updated) break;
    }

    // 음수 사이클 검사
    bool negative_cycle = false;
    for (auto &e : edges) {
        if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
            negative_cycle = true;
            break;
        }
    }

    if (negative_cycle) {
        std::cout << "음수 사이클이 존재합니다\n";
    } else {
        // 각 정점까지의 거리 출력 (도달 불가 시 INF)
        for (int v = 1

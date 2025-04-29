#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>


/// <summary>
/// 위상수... 아니 위상정렬에 더할것도 뺄 것도 없습니다. 안될 코드에 궤..
/// 
/// ppt에 있는 코드 자체가 답이에요
/// </summary>

using namespace std;

vector<vector<int>> graph; // 인접 리스트
vector<int> inDegree;      // 진입 차수 배열
queue<int> q;              // 위상 정렬용 큐

void topology_sort(int V) {
    for (int v = 1; v <= V; ++v) { // 정점 번호는 1부터 V까지 사용
        if (inDegree[v] == 0) {
            q.push(v);
        }
    }

    vector<int> result;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        result.push_back(cur);

        for (int nxt : graph[cur]) {
            inDegree[nxt]--;
            if (inDegree[nxt] == 0) {
                q.push(nxt);
            }
        }
    }

    if (result.size() != V) {
        cout << "사이클 발생: 위상 정렬 불가\n";
    }
    else {
        for (int node : result) {
            cout << node << " ";
        }
        cout << "\n";
    }
}

int main() {
    int V, M; // N: 사람 수, M: 비교 수
    cin >> V >> M;
    graph.assign(V + 1, vector<int>());
    inDegree.assign(V + 1, 0);

    vector<pair<int, int>> edges;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({ u, v });
    }

    for (const auto& edge : edges) {
        int s = edge.first;
        int e = edge.second;
        graph[s].push_back(e);
        inDegree[e]++;
    }

    topology_sort(V);

    return 0;
}

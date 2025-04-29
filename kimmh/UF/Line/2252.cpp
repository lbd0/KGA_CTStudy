#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>


/// <summary>
/// �����... �ƴ� �������Ŀ� ���Ұ͵� �� �͵� �����ϴ�. �ȵ� �ڵ忡 ��..
/// 
/// ppt�� �ִ� �ڵ� ��ü�� ���̿���
/// </summary>

using namespace std;

vector<vector<int>> graph; // ���� ����Ʈ
vector<int> inDegree;      // ���� ���� �迭
queue<int> q;              // ���� ���Ŀ� ť

void topology_sort(int V) {
    for (int v = 1; v <= V; ++v) { // ���� ��ȣ�� 1���� V���� ���
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
        cout << "����Ŭ �߻�: ���� ���� �Ұ�\n";
    }
    else {
        for (int node : result) {
            cout << node << " ";
        }
        cout << "\n";
    }
}

int main() {
    int V, M; // N: ��� ��, M: �� ��
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

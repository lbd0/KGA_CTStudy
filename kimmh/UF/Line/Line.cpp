#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, M; // N: ��� ��, M: �� ��
    cin >> N >> M;

    vector<vector<int>> graph(N + 1); // ���� ����Ʈ, 1���� �����ϱ⿡ 1������
    vector<int> indegree(N + 1, 0);   // ���� ����  �̰͵� ���� ���� ������ 1 ������

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v; // �� �Է�
        graph[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    vector<int> result;

    // ���� ������ 0�� ��� ť�� ����
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);              
        }
    }

    while (!q.empty()) {
        int current = q.front();            
        q.pop();
        result.push_back(current);

        for (int next : graph[current]) {   // ����� ������ ���� ���� ����
            indegree[next]--;
            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    // ����Ŭ�� �ִ� ���
    if (result.size() != N) {
        cout << "����Ŭ�� �����Ͽ� ���� ������ �Ұ����մϴ�.\n";
    }
    else {
        for (int node : result) {
            cout << node << ' ';
        }
        cout << '\n';
    }

    return 0;
}

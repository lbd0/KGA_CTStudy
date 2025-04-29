#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, M; // N: 사람 수, M: 비교 수
    cin >> N >> M;

    vector<vector<int>> graph(N + 1); // 인접 리스트, 1부터 시작하기에 1더해줌
    vector<int> indegree(N + 1, 0);   // 진입 차수  이것도 위와 같은 이유로 1 더해줌

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v; // 비교 입력
        graph[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    vector<int> result;

    // 진입 차수가 0인 노드 큐에 삽입
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);              
        }
    }

    while (!q.empty()) {
        int current = q.front();            
        q.pop();
        result.push_back(current);

        for (int next : graph[current]) {   // 연결된 노드들의 진입 차수 감소
            indegree[next]--;
            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    // 사이클이 있는 경우
    if (result.size() != N) {
        cout << "사이클이 존재하여 위상 정렬이 불가능합니다.\n";
    }
    else {
        for (int node : result) {
            cout << node << ' ';
        }
        cout << '\n';
    }

    return 0;
}

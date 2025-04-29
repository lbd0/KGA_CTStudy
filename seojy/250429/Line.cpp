/* GPT의 힘을 빌렸습니다.. */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> graph(n + 1);
    vector<int> indegree(n + 1, 0);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    
    queue<int> q;
    
    // 진입차수가 0인 노드를 큐에 넣는다
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }
    
    // 위상 정렬
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        
        for (int next : graph[cur]) {
            indegree[next]--;
            if (indegree[next] == 0)
                q.push(next);
        }
    }
    
    return 0;
}

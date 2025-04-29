/*GPT의 힘을 빌렸습니다...흑흑*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int from, to, cost;
};

bool cmp(const Edge &a, const Edge &b) {
    return a.cost < b.cost;
}

vector<int> parent;

// 유니온 파인드 - Find
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

// 유니온 파인드 - Union
void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b)
        parent[b] = a;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) parent[i] = i;
    
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].cost;
    }
    
    sort(edges.begin(), edges.end(), cmp);
    
    int result = 0;
    for (auto &edge : edges) {
        if (find(edge.from) != find(edge.to)) {
            unite(edge.from, edge.to);
            result += edge.cost;
        }
    }
    
    cout << result << endl;
}

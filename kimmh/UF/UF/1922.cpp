#include<iostream>
#include<vector>
#include<algorithm>

// 크루스칼, 프림 둘다 가능할듯?

using namespace std;

struct Edge
{
    int u, v, w;

    Edge() {
        u = 0;
        v = 0;
        w = 0;
    }

    // 생성자를 만들지 않으면 게임 도중에 터져버린다고?
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}

    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

class UnionFind {
private:
    vector<int> parent, rank;
public:
    UnionFind(int n) {
        parent.resize(n);               // 받아온 정점 개수만큼 vector 크기 조정
        rank.resize(n, 0);              // 정점 개수 만큼 rank에 0을 채움
        for (int i = 0; i < n; ++i) {
            parent[i] = i;              // 1~n-1까지 부모로 채움
        }
    }

    int find(int x) {
        if (parent[x] != x)             // 부모가 매개변수가 아닐 때
            parent[x] = find(parent[x]); // 경로 압축
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);            // x 루트 찾고
        int rootY = find(y);            // y 루트 찾고

        if (rootX == rootY) return false;   // 같으면 못 합쳤음

        // union by rank
        if (rank[rootX] < rank[rootY]) {
            // x의 높이가 더 작으므로 y트리에 붙인다
            parent[rootX] = rootY; 
        }
        else {
            // y트리의 높이가 더 작으므로 y트리를 x트리에 붙인다
            parent[rootY] = rootX;

            
            if (rank[rootX] == rank[rootY]) {
                // 만약 두 트리의 높이가 같았으면 x의 트리 높이를 1 높인다
                rank[rootX]++;
            }
        }
        return true;
    }
};

int kruskal(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());   // 가중치 기준 정렬
    UnionFind uf(V);                    // unionfind 만듦
    int totalWeight = 0;                // 총 비용

    for (const auto& edge : edges) {
        if (uf.unite(edge.u, edge.v)) {
            // 두 트리를 합칠 수 있으면
            totalWeight += edge.w;  // 거리 증가
        }
    }

    return totalWeight;
}

int main() {
    int NodeCount;
    cin >> NodeCount;   // 노드 개수


    int EdgeCount;
    cin >> EdgeCount;   // 간선 개수

    vector<Edge> Edges;

    for (int i = 0; i < EdgeCount; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        Edges.push_back(Edge(u, v, w)); // 간선 채우기
    }


    cout << kruskal(NodeCount + 1, Edges) << endl;  // 정점이 1부터 시작해서 그랬음
}



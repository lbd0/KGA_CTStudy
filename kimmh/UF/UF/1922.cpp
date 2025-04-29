#include<iostream>
#include<vector>
#include<algorithm>

// ũ�罺Į, ���� �Ѵ� �����ҵ�?

using namespace std;

struct Edge
{
    int u, v, w;

    Edge() {
        u = 0;
        v = 0;
        w = 0;
    }

    // �����ڸ� ������ ������ ���� ���߿� ���������ٰ�?
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
        parent.resize(n);               // �޾ƿ� ���� ������ŭ vector ũ�� ����
        rank.resize(n, 0);              // ���� ���� ��ŭ rank�� 0�� ä��
        for (int i = 0; i < n; ++i) {
            parent[i] = i;              // 1~n-1���� �θ�� ä��
        }
    }

    int find(int x) {
        if (parent[x] != x)             // �θ� �Ű������� �ƴ� ��
            parent[x] = find(parent[x]); // ��� ����
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);            // x ��Ʈ ã��
        int rootY = find(y);            // y ��Ʈ ã��

        if (rootX == rootY) return false;   // ������ �� ������

        // union by rank
        if (rank[rootX] < rank[rootY]) {
            // x�� ���̰� �� �����Ƿ� yƮ���� ���δ�
            parent[rootX] = rootY; 
        }
        else {
            // yƮ���� ���̰� �� �����Ƿ� yƮ���� xƮ���� ���δ�
            parent[rootY] = rootX;

            
            if (rank[rootX] == rank[rootY]) {
                // ���� �� Ʈ���� ���̰� �������� x�� Ʈ�� ���̸� 1 ���δ�
                rank[rootX]++;
            }
        }
        return true;
    }
};

int kruskal(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());   // ����ġ ���� ����
    UnionFind uf(V);                    // unionfind ����
    int totalWeight = 0;                // �� ���

    for (const auto& edge : edges) {
        if (uf.unite(edge.u, edge.v)) {
            // �� Ʈ���� ��ĥ �� ������
            totalWeight += edge.w;  // �Ÿ� ����
        }
    }

    return totalWeight;
}

int main() {
    int NodeCount;
    cin >> NodeCount;   // ��� ����


    int EdgeCount;
    cin >> EdgeCount;   // ���� ����

    vector<Edge> Edges;

    for (int i = 0; i < EdgeCount; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        Edges.push_back(Edge(u, v, w)); // ���� ä���
    }


    cout << kruskal(NodeCount + 1, Edges) << endl;  // ������ 1���� �����ؼ� �׷���
}



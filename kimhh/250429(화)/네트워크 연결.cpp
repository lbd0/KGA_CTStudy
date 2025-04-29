/*************************************************************************************************************
문제
도현이는 컴퓨터와 컴퓨터를 모두 연결하는 네트워크를 구축하려 한다.
하지만 아쉽게도 허브가 있지 않아 컴퓨터와 컴퓨터를 직접 연결하여야 한다.
그런데 모두가 자료를 공유하기 위해서는 모든 컴퓨터가 연결이 되어 있어야 한다.
(a와 b가 연결이 되어 있다는 말은 a에서 b로의 경로가 존재한다는 것을 의미한다.
a에서 b를 연결하는 선이 있고, b와 c를 연결하는 선이 있으면 a와 c는 연결이 되어 있다.)

그런데 이왕이면 컴퓨터를 연결하는 비용을 최소로 하여야 컴퓨터를 연결하는 비용 외에 다른 곳에 돈을 더 쓸 수 있을 것이다.
이제 각 컴퓨터를 연결하는데 필요한 비용이 주어졌을 때 모든 컴퓨터를 연결하는데 필요한 최소비용을 출력하라.
모든 컴퓨터를 연결할 수 없는 경우는 없다.
**************************************************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 간선(Edge)를 표현하는 구조체
struct Edge {
    int from, to, cost;
    // 정렬을 위해 operator< 오버로딩 (비용 기준 오름차순)
    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

// 각 노드의 부모 정보를 저장할 배열 (유니온 파인드용)
vector<int> parent;

// 특정 노드의 대표(루트) 부모를 찾는 함수 (경로 압축 포함)
int Find(int x) {
    if (parent[x] == x) return x; // 자기 자신이 루트인 경우
    return parent[x] = Find(parent[x]);  // 경로 압축 : 루트를 찾아서 바로 연결
}

// 두 노드를 연결하는 함수 (두 집합을 하나로 합침)
// 이미 같은 집합이면 false 반환, 아니면 union 수행하고 true 반환
bool Union(int a, int b) {
    int rootA = Find(a);
    int rootB = Find(b);
    if (rootA == rootB) return false; // 이미 같은 집합 / 사이클 발생 방지

    parent[rootB] = rootA;  // 루트를 하나로 합치기
    return true;
}

int main() {
    int N, M; // N: 컴퓨터 수, M: 연결 가능한 선의 수
    cin >> N >> M;

    // 각 노드의 부모를 자기 자신으로 초기화
    parent.resize(N + 1);
    for (int i = 1; i <= N; ++i)
        parent[i] = i;

    vector<Edge> edges;

    // 간선 정보 입력 받기
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    // 간선을 비용 기준으로 오름차순 정렬
    sort(edges.begin(), edges.end());

    int totalCost = 0;    // MST의 총 비용
    int edgeCount = 0;    // 현재까지 선택된 간선의 수

    // 정렬된 간선들을 순서대로 탐색
    for (const Edge& e : edges) {
        // 사이클을 만들지 않도록 유니온 수행
        if (Union(e.from, e.to)) {
            totalCost += e.cost;  // 비용 누적
            edgeCount++;          // 간선 하나 추가

            // MST는 N-1개의 간선으로 구선되므로, 모두 연결되었으면 종료
            if (edgeCount == N - 1) break; // MST 완성
        }
    }

    // 모든 컴퓨터를 연결하는 최소 비용 출력
    cout << totalCost << endl;
    return 0;
}

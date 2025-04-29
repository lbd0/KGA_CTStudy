/*
문제
도현이는 컴퓨터와 컴퓨터를 모두 연결하는 네트워크를 구축하려 한다. 하지만 아쉽게도 허브가 있지 않아 컴퓨터와 컴퓨터를 직접 연결하여야 한다. 그런데 모두가 자료를 공유하기 위해서는 모든 컴퓨터가 연결이 되어 있어야 한다. (a와 b가 연결이 되어 있다는 말은 a에서 b로의 경로가 존재한다는 것을 의미한다. a에서 b를 연결하는 선이 있고, b와 c를 연결하는 선이 있으면 a와 c는 연결이 되어 있다.)

그런데 이왕이면 컴퓨터를 연결하는 비용을 최소로 하여야 컴퓨터를 연결하는 비용 외에 다른 곳에 돈을 더 쓸 수 있을 것이다. 이제 각 컴퓨터를 연결하는데 필요한 비용이 주어졌을 때 모든 컴퓨터를 연결하는데 필요한 최소비용을 출력하라. 모든 컴퓨터를 연결할 수 없는 경우는 없다.

입력
첫째 줄에 컴퓨터의 수 N (1 ≤ N ≤ 1000)가 주어진다.

둘째 줄에는 연결할 수 있는 선의 수 M (1 ≤ M ≤ 100,000)가 주어진다.

셋째 줄부터 M+2번째 줄까지 총 M개의 줄에 각 컴퓨터를 연결하는데 드는 비용이 주어진다. 이 비용의 정보는 세 개의 정수로 주어지는데, 만약에 a b c 가 주어져 있다고 하면 a컴퓨터와 b컴퓨터를 연결하는데 비용이 c (1 ≤ c ≤ 10,000) 만큼 든다는 것을 의미한다. a와 b는 같을 수도 있다.

출력
모든 컴퓨터를 연결하는데 필요한 최소비용을 첫째 줄에 출력한다.

예제 입력 1 
6
9
1 2 5
1 3 4
2 3 2
2 4 7
3 4 6
3 5 11
4 5 3
4 6 8
5 6 8

예제 출력 1 
23

*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int V, E;                                   // 컴퓨터(정점), 연결선(간선)

vector<pair<int, pair<int, int>>> edges; //점점 u에서 v로, 가중치까지

vector<int> parent;                        // 유니온-파인드 작업을 위한 부모 선언
vector<int> ran;                           //  랭크(트리 높이), 랭크 압축을 위한 선언


 // find, x가 속한 집합의 대표(루트) 반환
int find(int x)
{
    if (parent[x] == x) return x;          // 루트면 그대로 반환
    return parent[x] = find(parent[x]);   // 재귀 + 경로 압축
}

//유니온-파인드에서 유니온 단계

bool merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b) return false;               // 사이클일 경우 리턴

    // 높이(랭크)가 낮은 트리를 높은 트리 밑으로 붙임
    if (ran[a] < ran[b]) swap(a, b);
    parent[b] = a;
    if (ran[a] == ran[b]) ++ran[a];      // 높이가 같았다면 1 증가
    return true;
}

// 그래프 입력과 정점-간선 초기화 작업

void input()
{
    cin >> V >> E;                          // 정점, 간선 수 입력

    edges.reserve(E);
    for (int i = 0; i < E; ++i) {           //  간선 E개 입력
        int u, v, w;
        cin >> u >> v >> w;                 //   u-v 를 잇는 비용 w
        edges.emplace_back(w, make_pair(u, v));
    }

    // 유니온-파인드 배열 초기화 
    parent.resize(V + 1);
    ran.assign(V + 1, 0);
    for (int i = 1; i <= V; ++i) parent[i] = i;
}

//크루스칼 알고리즘

int kruskal()
{
    // 비용 오름차순 정렬
    sort(edges.begin(), edges.end());

    int used = 0;    // 현재까지 채택한 간선 수
    int cost = 0;    // MST 누적 비용

    // 가장 비용 낮은 간선부터 순회하며 사이클이 안 생기면 채택
    for (auto& e : edges) {
        int w = e.first;            // 비용
        int u = e.second.first;     // 정점 u
        int v = e.second.second;    // 정점 v

        if (merge(u, v)) {          // 사이클 X면 채택 성공
            cost += w;              // 비용 누적
            if (++used == V - 1)    // 간선 V-1개면 MST 완성
                break;
        }
    }
    return cost;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();                    // 그래프(간선) 읽기 & 유니온파인드 준비
    cout << kruskal() ;  // 최소 비용 출력
    
}

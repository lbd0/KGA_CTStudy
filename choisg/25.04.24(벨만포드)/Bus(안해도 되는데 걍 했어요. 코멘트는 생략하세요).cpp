#include<iostream>
#include<vector>
using namespace std;

// 도달할 수 없는 도시를 표현하기 위한 값
int NoConnection = 987654321; 

// 간선 정보를 저장하는 구조체
struct Edge
{
    int src;    // 출발 도시
    int dst;    // 도착 도시
    int weight; // 가중치
};


vector<int> BellManFord(vector<Edge> edges, int v, int start) {
    //최단 거리 저장 배열, 초기값은 도달할 수 없음
    vector<int> distance(v + 1, NoConnection);

    // 시작 도시의 거리는 0
    distance[start] = 0;

    // 벨만-포드 알고리즘 (N-1번)
    // 최단 경로의 간선 수는 최대 v-1개이므로 v-1번 반복
    for (int i = 0; i < v - 1; i++) {
        // 모든 간선에 대해 최단 거리 갱신
        for (int j = 0; j < edges.size(); j++) {
            int u = edges[j].src;   // 출발 도시
            int v = edges[j].dst;   // 도착 도시
            int w = edges[j].weight; // 가중치

            // 출발 도시에 아직 도달할 수 없으면 무시
            if (distance[u] == NoConnection) {
                continue;
            }

            // 더 짧은 경로가 있으면 갱신
            if (distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    //벨만-포드 결과 저장 (음수 사이클 확인 전)
    vector<int> result = distance;

    // 음수 사이클 확인
    // 음수 사이클에 영향을 받는 도시를 표시할 배열
    vector<bool> isAffected(v + 1, false);
    bool hasNegativeCycle = false;

    // 추가로 v번 더 반복하며 업데이트 확인
    // 음수 사이클이 있으면 계속 업데이트가 발생함
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < edges.size(); j++) {
            int u = edges[j].src;
            int v = edges[j].dst;
            int w = edges[j].weight;

            // 출발 도시에 아직 도달할 수 없으면 무시
            if (distance[u] == NoConnection) {
                continue;
            }

            // 더 짧은 경로가 또 있다면 음수 사이클이 있는 것
            if (distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                isAffected[v] = true;  // 음수 사이클의 영향을 받는 도시 표시
                hasNegativeCycle = true;
            }
        }
    }

    // 음수 사이클이 있으면, 그 영향을 받는 모든 도시를 찾음
    if (hasNegativeCycle) {
        // 영향을 받는 도시에서 또 다른 도시로 갈 수 있으면, 그 도시도 영향을 받음
        for (int k = 0; k < v; k++) {
            for (int j = 0; j < edges.size(); j++) {
                int u = edges[j].src;
                int v = edges[j].dst;

                // 출발 도시가 영향을 받고, 도착 도시가 아직 영향을 받지 않았다면
                if (isAffected[u]) {
                    isAffected[v] = true;  // 도착 도시도 영향을 받음
                }
            }
        }

        // 2번 이상의 도시가 음수 사이클의 영향을 받는지 확인
        for (int i = 2; i <= v; i++) {
            if (isAffected[i]) {
                // 영향을 받는 도시가 있으면 결과에 표시
                // 0번 인덱스를 음수 사이클 플래그로 사용
                result[0] = -1;
                break;
            }
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;  // 도시의 개수 n, 버스 노선의 개수 m

    // 버스 정보 저장
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;  // 출발 도시, 도착 도시, 걸리는 시간
        edges[i] = { a, b, c };  // 도시 번호는 1부터 시작
    }


    vector<int> distance = BellManFord(edges, n, 1);

    // 음수 사이클 영향 확인 (0번 인덱스를 플래그로 사용)
    if (distance[0] == -1) {
        cout << -1 << '\n';  // 무한히 시간을 되돌릴 수 있음
    }
    else {
        // 2번 도시부터 N번 도시까지의 최단 거리 출력
        for (int i = 2; i <= n; i++) {
            if (distance[i] == NoConnection) {
                cout << -1 << '\n';  // 도달할 수 없는 도시
            }
            else {
                cout << distance[i] << '\n';  // 최단 거리 출력
            }
        }
    }

    return 0;
}
#include <vector>
#include <queue>

using namespace std;

// 인접 리스트, <인접 노드, 가중치>
vector<pair<int, int>> v[55];
// 최단 거리를 저장
vector<int> Distance;

// 더 작은 값을 반환하는 함수
int Min(int a, int b)
{
    if (a < b)
        return a;

    return b;
}

// 다익스트라
void Dijkstra(int N)
{
    // 거리와 노드 번호를 저장하고, 거리가 짧은 순으로 정렬
    priority_queue<pair<int, int>> pqueue;
    // 시작 노드까지의 거리를 0으로 설정
    pqueue.push(make_pair(0, 1));
    // 시작 노드까지 최단 거리는 0
    Distance[1] = 0;

    // 큐가 빌 때까지
    while (pqueue.empty() == 0)
    {
        // 현재까지 누적 거리
        // 우선순위 큐는 내림차순임으로 음수로 저장
        int cost = -pqueue.top().first;
        // 현재 노드
        int current = pqueue.top().second;
        pqueue.pop();

        // 현재 노드와 연결된 모든 이웃 노드
        for (int i = 0; i < v[current].size(); ++i)
        {
            // 다음 노드
            int next = v[current][i].first;
            // 다음 노드까지의 거리
            int nextCost = v[current][i].second;

            // 기존 최단 거리보다 짧으면 갱신
            if (Distance[next] > cost + nextCost)
            {
                Distance[next] = cost + nextCost;
                pqueue.push(make_pair(-Distance[next], next));
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    // 모든 거리를 무한대로 초기화
    Distance.resize(N + 1, 2e9);

    // 도로 정보를 인접 리스트에 저장
    for (int i = 0; i < road.size(); ++i)
    {
        // 첫 번째 연결 노드
        int node1 = road[i][0];
        // 두 번째 연결 노드
        int node2 = road[i][1];
        // 두 노드 사이의 거리
        int dis = road[i][2];

        // 두 노드 사이 간선 추가
        v[node1].push_back(make_pair(node2, dis));
        v[node2].push_back(make_pair(node1, dis));
    }

    Dijkstra(N);

    int answer = 0;

    // 모든 노드를 순회하며 K 이하의 거리인 노드 체크
    for (int i = 1; i <= N; ++i)
    {
        if (Distance[i] <= K)
        {
            ++answer;
        }
    }

    return answer;
}

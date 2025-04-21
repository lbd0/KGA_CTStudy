#include <iostream>
#include <vector>
#include <limits> // LLONG_MAX 사용을 위한 헤더

using namespace std;

// 무한대
const long long NoConnection = numeric_limits<long long>::max(); 

struct Edge
{
    int src;    	// 간선의 시작 정점
    int dst;    	// 간선의 도착 정점
    int weight; 	// 간선의 가중치
};

// 벨만-포드 알고리즘 함수
// edges: 간선 정보 벡터, v: 정점의 개수, start: 시작 정점
vector<long long> BellmanFord(vector<Edge> edges, int v, int start)
{
	  // 각 정점까지의 최단 거리를 저장
    vector<long long> distance(v + 1, NoConnection); 
    // 시작 정점의 거리는 0으로 초기화
    distance[start] = 0;                            

    // v - 1번 반복하여 모든 간선에 대해 수행
    for (int i = 1; i <= v - 1; ++i)
    {
        // 모든 간선 순회
        for (const auto& edge : edges)
        {
            // 시작 정점까지 연결되어 있지 않으면 건너뜀
            if (distance[edge.src] == NoConnection)
            {
                continue;
            }
            // 현재까지의 거리 + 간선 가중치가 도착 정점의 현재 거리보다 작으면 업데이트
            if (distance[edge.dst] > distance[edge.src] + edge.weight)
            {
                distance[edge.dst] = distance[edge.src] + edge.weight;
            }
        }
    }

    for (const auto& edge : edges)
    {
        // 시작 정점까지의 거리가 연결되어 있지 않으면 건너뜀
        if (distance[edge.src] == NoConnection)
        {
            continue;
        }
        // 음수 사이클 존재
        if (distance[edge.dst] > distance[edge.src] + edge.weight)
        {
            return {};
        }
    }

    return distance;
}

int main()
{
    vector<Edge> bus;             // 버스 노선 저장
    vector<long long> Distance;   // 최단 거리 저장

    int n, m;                     // n: 정점의 개수, m: 간선의 개수

    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int src, dst, weight;
        // 출발 정점, 도착 정점, 가중치 입력
        cin >> src >> dst >> weight;     
      
        bus.emplace_back(Edge{src, dst, weight});
    }

    Distance = BellmanFord(bus, n, 1);

    if (Distance.empty())
    {
        // 음수 사이클이 존재하면 -1 출력
        cout << -1 << endl; 
    }
    else
    {
        // 2번 정점부터 n번 정점까지의 최단 거리 출력
        for (int i = 2; i <= n; ++i)
        {
            if (Distance[i] == NoConnection)
            {
                // 노선이 없을 경우
                cout << -1 << endl;
            }
            else
            {
                cout << Distance[i] << endl;
            }
        }
    }

    return 0;
}

#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

// ---------------------------
// 에지 구조체 정의
// ---------------------------
template <typename T>
struct Edge
{
	unsigned src;  // 출발 정점
	unsigned dst;  // 도착 정점
	T weight;      // 가중치
};

// ---------------------------
// 그래프 클래스 정의
// ---------------------------
template <typename T>
class Graph
{
public:
	Graph(unsigned N) : V(N) {}  // 정점의 개수를 초기화

	// 정점의 수 반환
	auto vertices() const { return V; }

	// 전체 에지 리스트 반환
	auto& edges() const { return edge_list; }

	// 특정 정점에서 나가는 에지들만 반환
	auto edges(unsigned v) const
	{
		vector<Edge<T>> edges_from_v;
		for (auto& e : edge_list)
		{
			if (e.src == v)
			{
				edges_from_v.emplace_back(e);
			}
		}
		return edges_from_v;
	}

	// 에지를 그래프에 추가
	void add_edge(Edge<T>&& e)
	{
		// 유효한 정점 번호인지 확인 후 추가
		if (e.src >= 1 && e.src <= V && e.dst >= 1 && e.dst <= V)
		{
			edge_list.emplace_back(e);
		}
		else
		{
			cerr << "에러: 유효 범위를 벗어난 정점!" << endl;
		}
	}

	// 그래프 출력 지원
	template <typename U>
	friend ostream& operator<< (ostream& os, const Graph<U>& G);

private:
	unsigned V;	// 정점 개수
	vector<Edge<T>> edge_list;	// 전체 에지 리스트
};

// ---------------------------
// 그래프 출력 연산자 오버로딩
// ---------------------------
template <typename U>
ostream& operator<< (ostream& os, const Graph<U>& G)
{
	for (unsigned i = 1; i < G.vertices(); i++)
	{
		os << i << ":\t";

		auto edges = G.edges(i);

		for (auto& e : edges)
		{
			os << "{" << e.dst << ": " << e.weight << "}, ";
		}

		os << endl;
	}
	return os;
}

// ---------------------------
// 테스트용 그래프 생성 함수
// ---------------------------
template <typename T>
auto create_reference_graph()
{
	Graph<T> G(9); // 정점은 1~8번까지 사용 (0번은 무시)

	map<unsigned, vector<pair<unsigned, T>>> edge_map;

	// 각 정점에 연결된 정점과 가중치 설정
	edge_map[1] = { {2, 2}, {5, 3} };
	edge_map[2] = { {1, 2}, {5, 5}, {4, 1} };
	edge_map[3] = { {4, 2}, {7, 3} };
	edge_map[4] = { {2, 1}, {3, 2}, {5, 2}, {6, 4}, {8, 5} };
	edge_map[5] = { {1, 3}, {2, 5}, {4, 2}, {8, 3} };
	edge_map[6] = { {4, 4}, {7, 4}, {8, 1} };
	edge_map[7] = { {3, 3}, {6, 4} };
	edge_map[8] = { {4, 5}, {5, 3}, {6, 1} };

	// 위에서 설정한 edge_map을 이용해 그래프에 에지 추가
	for (auto& i : edge_map)
	{
		for (auto& j : i.second)
		{
			G.add_edge(Edge<T>{ i.first, j.first, j.second });
		}
	}

	return G;
}

// ---------------------------
// 다익스트라 알고리즘용 라벨 구조체
// ---------------------------
template <typename T>
struct Label
{
	unsigned ID;    // 정점 ID
	T distance;     // 시작점으로부터 거리

	// 우선순위 큐에서 사용하기 위한 비교 연산자 (작은 distance가 우선)
	inline bool operator> (const Label<T>& l) const
	{
		return this->distance > l.distance;
	}
};

// ---------------------------
// 다익스트라 최단경로 알고리즘
// ---------------------------
template <typename T>
auto dijkstra_shortest_path(const Graph<T>& G, unsigned src, unsigned dst)
{
	// 최소 힙 선언: 가장 짧은 거리의 정점을 우선으로 처리하기 위한 우선순위 큐
	priority_queue<Label<T>, vector<Label<T>>, greater<Label<T>>> heap;

	vector<T> distance(G.vertices(), numeric_limits<T>::max());		// 모든 정점 거리 초기화
	set<unsigned> visited;					// 방문한 정점 저장
	vector<unsigned> parent(G.vertices());	// 경로 추적용

	heap.emplace(Label<T>{src, 0});  // 시작 정점 거리 0으로 힙에 삽입
	parent[src] = src;		// 시작 정점의 부모를 자기 자신으로 초기화

	while (!heap.empty())
	{
		auto current_vertex = heap.top();	// 힙에서 거리가 가장 짧은 정점 pop
		heap.pop();

		// 목적지 도착 시 종료
		if (current_vertex.ID == dst)
		{
			cout << current_vertex.ID << "번 정점(목적 정점)에 도착!" << endl;
			break;
		}

		// 방문하지 않은 정점인 경우만 처리
		if (visited.find(current_vertex.ID) == visited.end())
		{
			cout << current_vertex.ID << "번 정점에 안착!" << endl;

			// 현재 정점과 연결된 모든 이웃 에지 탐색
			for (auto& e : G.edges(current_vertex.ID))
			{
				// 이웃 정점 ID 가져옴
				auto neighbor = e.dst;
				auto new_distance = current_vertex.distance + e.weight;

				// 새로 계산한 거리가 기존 거리보다 짧으면 갱신
				if (new_distance < distance[neighbor])
				{
					// 힙에 갱신된 이웃 정점 추가
					heap.emplace(Label<T>{neighbor, new_distance});
					// 부모 정보 갱신
					parent[neighbor] = current_vertex.ID;
					// 거리 정보 갱신
					distance[neighbor] = new_distance;
				}
			}
			visited.insert(current_vertex.ID);
		}
	}

	// 경로 추적 (백트래킹 방식)
	vector<unsigned> shortest_path;
	auto current_vertex = dst;		// 목적지 정점부터

	while (current_vertex != src)	// 시작 정점까지
	{
		shortest_path.push_back(current_vertex);	// 현재 정점 경로에 추가
		current_vertex = parent[current_vertex];	// 부모 정점으로 이동
	}

	shortest_path.push_back(src);	// 시작 정점 추가
	// 역순으로 저장된 순서를 뒤집어줌
	reverse(shortest_path.begin(), shortest_path.end());

	return shortest_path;
}

// ---------------------------
// main 함수 - 테스트용
// ---------------------------
int main()
{
	using T = unsigned; // 가중치는 양의 정수형

	auto G = create_reference_graph<T>(); // 그래프 생성
	cout << "[입력 그래프]" << endl;
	cout << G << endl;

	// 1번 정점에서 6번 정점까지의 최단 경로 탐색
	auto shortest_path = dijkstra_shortest_path<T>(G, 1, 6);

	cout << endl << "[1번과 6번 정점 사이의 최단 경로]" << endl;

	for (auto v : shortest_path)
	{
		cout << v << " ";
	}
	cout << endl;
}

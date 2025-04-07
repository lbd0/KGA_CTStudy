#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <queue>

using namespace std;

// -------------------------------
// 그래프에서 사용하는 간선(Edge) 구조체 정의
// -------------------------------
template <typename T>
struct Edge
{
	unsigned src;   // 간선의 시작 정점
	unsigned dst;   // 간선의 끝 정점
	T weight;       // 간선의 가중치
};

// -------------------------------
// 그래프 클래스 정의 (간선 리스트 방식)
// -------------------------------
template <typename T>
class Graph
{
public:
	// N개의 정점으로 그래프 초기화
	Graph(unsigned N) : V(N) {}

	// 정점 개수 반환
	auto vertices() const { return V; }

	// 전체 간선 리스트 반환 (읽기 전용)
	auto& edges() const { return edge_list; }

	// 정점 v에서 시작하는 간선들 반환
	auto edges(unsigned v) const
	{
		vector<Edge<T>> edges_from_v;
		for (auto& e : edge_list)
		{
			if (e.src == v)
			{
				edges_from_v.emplace_back(e); // 해당 정점에서 나가는 간선 수집
			}
		}
		return edges_from_v;
	}

	// 간선 추가
	void add_edge(Edge<T>&& e)
	{
		// 간선의 양 끝 정점이 유효한지 검사
		if (e.src >= 1 && e.src <= V && e.dst >= 1 && e.dst <= V)
		{
			edge_list.emplace_back(e); // 유효하면 추가
		}
		else
		{
			cerr << "에러: 유효 범위를 벗어난 정점!" << endl;
		}
	}

	// 그래프를 출력하는 함수 지원 (friend 함수)
	template <typename U>
	friend ostream& operator<< (ostream& os, const Graph<U>& G);

private:
	unsigned V;                 // 정점의 개수
	vector<Edge<T>> edge_list;	// 전체 간선 리스트
};

// -------------------------------
// 그래프 출력 연산자 오버로딩
// 각 정점과 연결된 간선들을 출력
// -------------------------------
template <typename U>
ostream& operator<< (ostream& os, const Graph<U>& G)
{
	for (unsigned i = 1; i < G.vertices(); i++)		// 1번부터 시작 (0번은 사용 안 함)
	{
		os << i << ":\t";	// 정점 번호 출력

		auto edges = G.edges(i);	// 해당 정점에서 나가는 간선들

		for (auto& e : edges)
		{
			os << "{" << e.dst << ": " << e.weight << "}, ";	// 목적지와 가중치 출력
		}

		os << endl;
	}
	return os;
}

// -------------------------------
// 예제용 그래프 생성 함수
// 정점은 1~8번, 가중치는 모두 0
// -------------------------------
template <typename T>
auto create_reference_graph()
{
	Graph<T> G(9);	// 정점은 1~8번까지 (0번은 미사용, 9개로 설정)

	map<unsigned, vector<pair<unsigned, T>>> edge_map;

	// 정점과 간선 연결 구조 정의 (무방향 그래프 형태로 양방향 간선)
	edge_map[1] = { {2, 0}, {5, 0} };
	edge_map[2] = { {1, 0}, {5, 0}, {4, 0} };
	edge_map[3] = { {4, 0}, {7, 0} };
	edge_map[4] = { {2, 0}, {3, 0}, {5, 0}, {6, 0}, {8, 0} };
	edge_map[5] = { {1, 0}, {2, 0}, {4, 0}, {8, 0} };
	edge_map[6] = { {4, 0}, {7, 0}, {8, 0} };
	edge_map[7] = { {3, 0}, {6, 0} };
	edge_map[8] = { {4, 0}, {5, 0}, {6, 0} };

	// 정의된 edge_map을 바탕으로 간선 추가
	for (auto& i : edge_map)
	{
		for (auto& j : i.second)
		{
			G.add_edge(Edge<T>{ i.first, j.first, j.second });
		}
	}

	return G;
}

// -------------------------------
// 너비 우선 탐색 (BFS) 알고리즘 구현
// -------------------------------
template <typename T>
auto breadth_first_search(const Graph<T>& G, unsigned start)
{
	queue<unsigned> queue;          // 탐색에 사용할 큐
	set<unsigned> visited;          // 방문한 정점 저장
	vector<unsigned> visit_order;   // 방문 순서를 저장

	queue.push(start);              // 시작 정점을 큐에 삽입

	while (!queue.empty())
	{
		auto current_vertex = queue.front(); // 현재 큐의 front 정점
		queue.pop();                         // 큐에서 제거

		// 방문하지 않은 정점이라면 처리
		if (visited.find(current_vertex) == visited.end())
		{
			visited.insert(current_vertex);        // 방문 표시
			visit_order.push_back(current_vertex); // 방문 순서 기록

			// 현재 정점과 연결된 모든 인접 정점에 대해
			for (auto& e : G.edges(current_vertex))
			{
				// 아직 방문하지 않은 정점이라면 큐에 추가
				if (visited.find(e.dst) == visited.end())
				{
					queue.push(e.dst);
				}
			}
		}
	}

	return visit_order; // 전체 방문 순서 반환
}

// -------------------------------
// main 함수
// -------------------------------
int main()
{
	using T = unsigned; // 가중치 타입을 unsigned로 설정

	// 그래프 생성
	auto G = create_reference_graph<T>();
	cout << "[입력 그래프]" << endl;
	cout << G << endl;

	// BFS 실행
	cout << "[BFS 방문 순서]" << endl;
	auto bfs_visit_order = breadth_first_search(G, 1); // 1번 정점부터 시작

	// 방문 순서 출력
	for (auto v : bfs_visit_order)
	{
		cout << v << endl;
	}
}

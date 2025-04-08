#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <stack> // DFS는 stack 사용

using namespace std;

// -------------------------------
// 간선(Edge) 구조체 정의
// -------------------------------
template <typename T>
struct Edge
{
	unsigned src;   // 간선의 시작 정점
	unsigned dst;   // 간선의 끝 정점
	T weight;       // 간선의 가중치
};

// -------------------------------
// 그래프 클래스 정의 (간선 리스트 기반)
// -------------------------------
template <typename T>
class Graph
{
public:
	// N개의 정점으로 그래프 초기화
	Graph(unsigned N) : V(N) {}

	// 정점의 개수 반환
	auto vertices() const { return V; }

	// 전체 간선 리스트 반환
	auto& edges() const { return edge_list; }

	// 정점 v에서 시작하는 모든 간선을 반환
	auto edges(unsigned v) const
	{
		vector<Edge<T>> edges_from_v;

		for (auto& e : edge_list)
		{
			if (e.src == v)
			{
				// v에서 출발하는 간선만 추출
				edges_from_v.emplace_back(e);
			}
		}

		return edges_from_v;
	}

	// 간선 추가 함수 (정점 ID 유효성 검사 포함)
	void add_edge(Edge<T>&& e)
	{
		if (e.src >= 1 && e.src <= V && e.dst >= 1 && e.dst <= V)
		{
			edge_list.emplace_back(e); // 유효한 간선이면 추가
		}
		else
		{
			cerr << "에러: 유효 범위를 벗어난 정점!" << endl;
		}
	}

	// 출력 지원을 위한 friend 함수
	template <typename U>
	friend ostream& operator<< (ostream& os, const Graph<U>& G);

private:
	unsigned V;                 // 정점 개수
	vector<Edge<T>> edge_list;	// 간선 리스트
};

// -------------------------------
// 그래프 출력 함수 (정점과 연결된 간선들 출력)
// -------------------------------
template <typename U>
ostream& operator<< (ostream& os, const Graph<U>& G)
{
	for (unsigned i = 1; i < G.vertices(); i++)  // 1번부터 출력
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

// -------------------------------
// 예시용 그래프 생성 함수 (무방향 그래프처럼 양방향 간선 설정)
// -------------------------------
template <typename T>
auto create_reference_graph()
{
	Graph<T> G(9); // 정점은 1~8번까지 사용 (0번 제외)

	map<unsigned, vector<pair<unsigned, T>>> edge_map;
	// 각 정점에 연결된 간선 정의 (가중치는 0)
	edge_map[1] = { {2, 0}, {5, 0} };
	edge_map[2] = { {1, 0}, {5, 0}, {4, 0} };
	edge_map[3] = { {4, 0}, {7, 0} };
	edge_map[4] = { {2, 0}, {3, 0}, {5, 0}, {6, 0}, {8, 0} };
	edge_map[5] = { {1, 0}, {2, 0}, {4, 0}, {8, 0} };
	edge_map[6] = { {4, 0}, {7, 0}, {8, 0} };
	edge_map[7] = { {3, 0}, {6, 0} };
	edge_map[8] = { {4, 0}, {5, 0}, {6, 0} };

	// 간선 추가 (Edge 구조체 형태로)
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
// 깊이 우선 탐색 (DFS) 알고리즘 구현
// -------------------------------
template <typename T>
auto depth_first_search(const Graph<T>& G, unsigned start)
{
	stack<unsigned> stack;         // DFS는 스택을 사용
	set<unsigned> visited;         // 방문한 정점 저장
	vector<unsigned> visit_order;  // 방문 순서 저장

	stack.push(start);             // 시작 정점 스택에 push

	while (!stack.empty())
	{
		auto current_vertex = stack.top(); // 가장 마지막에 추가된 정점 확인
		stack.pop();					   // 해당 정점 제거

		if (visited.find(current_vertex) == visited.end())
		{
			visited.insert(current_vertex);        // 방문 표시
			visit_order.push_back(current_vertex); // 방문 순서 기록

			// 연결된 간선 순회
			for (auto& e : G.edges(current_vertex))
			{
				// 방문하지 않은 인접 정점이라면 스택에 push
				if (visited.find(e.dst) == visited.end())
				{
					stack.push(e.dst);
				}
			}
		}
	}

	return visit_order; // 전체 방문 순서 반환
}

// -------------------------------
// main 함수: 그래프 생성, DFS 실행
// -------------------------------
int main()
{
	using T = unsigned; // 가중치 타입 지정

	auto G = create_reference_graph<T>(); // 예시 그래프 생성

	cout << "[입력 그래프]" << endl;
	cout << G << endl;

	cout << "[DFS 방문 순서]" << endl;
	auto dfs_visit_order = depth_first_search(G, 1); // 1번 정점부터 DFS 시작

	for (auto v : dfs_visit_order)
	{
		cout << v << endl; // 방문 순서 출력
	}
}

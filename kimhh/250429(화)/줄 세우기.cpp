/*************************************************************************************************************
N명의 학생들을 키 순서대로 줄을 세우려고 한다.
각 학생의 키를 직접 재서 정렬하면 간단하겠지만, 마땅한 방법이 없어서 두 학생의 키를 비교하는 방법을 사용하기로 하였다.
그나마도 모든 학생들을 다 비교해 본 것이 아니고, 일부 학생들의 키만을 비교해 보았다.

일부 학생들의 키를 비교한 결과가 주어졌을 때, 줄을 세우는 프로그램을 작성하시오.
*************************************************************************************************************/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 향상 (C와 C++ 혼용 방지)
    cin.tie(0);                  // cin과 cout의 묶음을 풀어서 성능 향상

    int N, M;
    cin >> N >> M; // N: 학생 수, M: 키 비교 횟수

    // 인접 리스트 그래프 (1번부터 N번까지 사용)
    vector<vector<int>> graph(N + 1);

    // 각 학생의 진입 차수 (자신보다 앞에 있어야 하는 학생 수)
    vector<int> indegree(N + 1, 0);

    // 키 비교 정보 입력
    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;

        // A가 B보다 앞에 선다 → A → B 방향 간선
        graph[A].push_back(B);

        // B는 A보다 뒤에 있어야 하므로, 진입 차수를 1 증가
        indegree[B]++;
    }

    // 위상 정렬에 사용할 큐
    queue<int> q;

    // 진입 차수가 0인 노드를 모두 큐에 넣음 (자기보다 앞에 아무도 없는 학생)
    for (int i = 1; i <= N; ++i) {
        if (indegree[i] == 0) {
            q.push(i); // 맨 앞에 설 수 있는 학생
        }
    }

    // 결과를 저장할 벡터
    vector<int> result;

    // 큐가 빌 때까지 위상 정렬 수행
    while (!q.empty()) {
        int curr = q.front(); // 현재 큐에서 꺼낼 학생
        q.pop();
        result.push_back(curr); // 결과에 추가 (줄 세우기)

        // 현재 학생 다음에 와야 하는 학생들 검사
        for (int next : graph[curr]) {
            indegree[next]--; // 현재 학생이 사라졌으니 진입 차수 감소

            // 진입 차수가 0이 되면 이제 줄에 설 수 있음
            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    // 정렬된 학생 순서 출력
    for (int student : result) {
        cout << student << " ";
    }
    cout << "\n";

    return 0;
}

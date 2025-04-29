/*

문제
N명의 학생들을 키 순서대로 줄을 세우려고 한다. 각 학생의 키를 직접 재서 정렬하면 간단하겠지만, 마땅한 방법이 없어서 두 학생의 키를 비교하는 방법을 사용하기로 하였다. 그나마도 모든 학생들을 다 비교해 본 것이 아니고, 일부 학생들의 키만을 비교해 보았다.

일부 학생들의 키를 비교한 결과가 주어졌을 때, 줄을 세우는 프로그램을 작성하시오.

입력
첫째 줄에 N(1 ≤ N ≤ 32,000), M(1 ≤ M ≤ 100,000)이 주어진다. M은 키를 비교한 횟수이다. 다음 M개의 줄에는 키를 비교한 두 학생의 번호 A, B가 주어진다. 이는 학생 A가 학생 B의 앞에 서야 한다는 의미이다.

학생들의 번호는 1번부터 N번이다.

출력
첫째 줄에 학생들을 앞에서부터 줄을 세운 결과를 출력한다. 답이 여러 가지인 경우에는 아무거나 출력한다.

예제 입력 1 
3 2
1 3
2 3

예제 출력 1 
1 2 3

예제 입력 2 
4 2
4 2
3 1

예제 출력 2 
4 2 3 1

*/


#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

//ppt에 올린 위상정렬 코드에서 순서대로 출력한다는 내용만 담긴? 사실상 거저먹기 문제였습니다

int V, E;                     // 정점 수, 간선 수
vector<vector<int>> graph;    // 인접 리스트
vector<int> inDegree;         // 진입 차수 초기화
queue<int> q;                 // 위상 정렬용 큐

//그래프와 진입차수 초기화
void input() {
    cin >> V >> E;                        // 정점·간선 수

    graph.assign(V + 1, {});              //그래프 초기화 작업
    inDegree.assign(V + 1, 0);

    for (int i = 0; i < E; ++i) {         // 간선 E개 읽기
        int s, e;
        cin >> s >> e;                    // s 앞, e 뒤
        graph[s].push_back(e);            // 인접 리스트 등록
        ++inDegree[e];                    // pushback은 진입차수를 증가시킬 수밖에 없음
    }
}

// 위상 정렬
void topology_sort() {
    //진입 차수 0인 정점 큐 삽입 
    for (int v = 1; v <= V; ++v)
        if (inDegree[v] == 0) q.push(v);

    vector<int> answer;                   // 최종 줄 세우기 결과

    // V번 반복
    for (int cnt = 0; cnt < V; ++cnt) {
        int cur = q.front(); q.pop();
        answer.push_back(cur);            // 출력용 저장

        for (int nxt : graph[cur])        // cur → nxt
            if (--inDegree[nxt] == 0)     // 진입 차수 감소 & 0 체크
                q.push(nxt);
    }

    // 결과 한 줄 출력 
    for (int i = 0; i < V; ++i) {
        cout << answer[i];
        if (i + 1 < V) cout << ' ';
    }
   
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();            // 그래프 구축
    topology_sort();    // 위상 정렬 실행
    return 0;
}

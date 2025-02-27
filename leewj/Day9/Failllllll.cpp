// https://school.programmers.co.kr/learn/courses/30/lessons/43105
// 패배했다
// https://velog.io/@co_ol/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%A0%95%EC%88%98-%EC%82%BC%EA%B0%81%ED%98%95java

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
	int answer = -1;
	for (int i = 1; i < triangle.size(); i++) {
		for (int j = 0; j < triangle[i].size(); j++) {

			if (j == 0) {//왼쪽 끝
				triangle[i][j] += triangle[i - 1][j];
			}
			else if (j == i) {//오른쪽 끝
				triangle[i][j] += triangle[i - 1][j - 1];
			}
			else {
				triangle[i][j] += max(triangle[i - 1][j], triangle[i - 1][j - 1]);
			}

			answer = max(answer, triangle[i][j]);
		}
	}
	return answer;
}

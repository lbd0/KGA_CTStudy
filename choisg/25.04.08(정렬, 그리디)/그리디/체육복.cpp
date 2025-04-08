/*********************************************************************************
https://school.programmers.co.kr/learn/courses/30/lessons/42862
프로그래머스 체육복
점심시간에 도둑이 들어, 일부 학생이 체육복을 도난당했습니다.
다행히 여벌 체육복이 있는 학생이 이들에게 체육복을 빌려주려 합니다.
학생들의 번호는 체격 순으로 매겨져 있어, 바로 앞번호의 학생이나 바로 뒷번호의 학생에게만 체육복을 빌려줄 수 있습니다.
예를 들어, 4번 학생은 3번 학생이나 5번 학생에게만 체육복을 빌려줄 수 있습니다.
체육복이 없으면 수업을 들을 수 없기 때문에 체육복을 적절히 빌려 최대한 많은 학생이 체육수업을 들어야 합니다.

전체 학생의 수 n,
체육복을 도난당한 학생들의 번호가 담긴 배열 lost,
여벌의 체육복을 가져온 학생들의 번호가 담긴 배열 reserve가 매개변수로 주어질 때,
체육수업을 들을 수 있는 학생의 최댓값을 return 하도록 solution 함수를 작성해주세요.

입출력 예
n	  lost	  reserve	    return
5	  [2, 4]	[1, 3, 5]	  5
5	  [2, 4]	[3]	        4
3  	[3]	    [1]	        2
*********************************************************************************/

/*
생각의 단편

잃어버린 사람과 가져온 사람의 번호를 합쳐서 순서대로 정렬한다
앞부터 하나씩 반복하며 reserve 한사람을 찾는다. reserve 뒤로 살펴 lost한 사람이 있으면 max에 1을 더해줌. 
첫번쨰 reserve는 앞도 살핌. max에 reserve 숫자도 더해줌.  -> for문이 너무 많아져 실패

*/

#include<iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {

    int answer = 0;
    // 사람보다는 그 사람이 갖고 있는 유니폼 개수로 판단.

    vector<int> uniformCounts(n, 1);
    // 잃어버린 학생은 유니폼을 1개 뺏는다.
    for (int L : lost) {
        --uniformCounts[L - 1];
    }

    // 유니폼이 더 있는 학생은 유니폼을 1개 준다.
    for (int R : reserve) {
        ++uniformCounts[R - 1];
    }

    //uniformCounts[i]는 학생이 가지고 있는 체육복 수를 나타냄.
    for (int i = 0; i < n; i++) {

        if (uniformCounts[i] == 0) { //0벌이라면
            
            if (i - 1 >= 0 && uniformCounts[i - 1] == 2) { //앞번호 학생에게 빌릴 수 있는지 확인
                uniformCounts[i - 1] = 1;  // 앞번호 학생은 1개를 내주고
                uniformCounts[i] = 1;      // 빌린 학생은 1개를 얻음
            }
            // 앞번호 학생 없으면 뒷번호 학생에게 빌릴 수 있는지 확인
            else if (i + 1 < n && uniformCounts[i + 1] == 2) {
                uniformCounts[i + 1] = 1;  // 뒷번호 학생은 1개를 내주고
                uniformCounts[i] = 1;      // 빌린 학생은 1개를 얻음
            }
        }
    }

    // 유니폼의 개수를 세면 됨
    int canAttendClass = 0;
    for (int count : uniformCounts) {
        if (count >= 1) {
            ++canAttendClass;
            answer = canAttendClass;
        }
    }

    return answer;
}
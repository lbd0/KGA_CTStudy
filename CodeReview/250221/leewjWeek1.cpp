// https://school.programmers.co.kr/learn/courses/30/lessons/159994

#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    // i는 goal 배열을 순회, j는 cards1 배열을 순회, k는cards2 배열을 순회
    int j = 0;
    int k = 0;

    for (int i = 0; i < goal.size(); ++i) {      // 원하는 단어 배열(goal)에서 원하는 단어를 하나씩(goal[i]) 검사
        if (goal[i] == cards1[j]) {              // cards1 뭉치의 제일 윗 장(cards1[j])이 원하는 단어일 경우
            ++j;                                 // 다음장으로 이동.
            continue;
        }
        else if (goal[i] == cards2[k]) {         // cards2 뭉치의 제일 윗 장(cards2[k])이 원하는 단어일 경우
            ++k;                                 // 다음장으로 이동.
            continue;
        }
        else {                                   // 두 카드 뭉치의 제일 윗 장에 원하는 단어가 없을 경우 문장을 완성할 수 없음.
            return "No";                         // -> Noooooooooooooooooooooooooooo
        }
    }
                                                 // for문을 통과했다 -> 원하는 단어 배열을 모두 검사 했지만 No 인 경우가 없었다 -> 문장 완성
    return "Yes";                                // -> Yeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeesssssssssssss
}

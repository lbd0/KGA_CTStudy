// https://school.programmers.co.kr/learn/courses/30/lessons/159994

#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    // i�� goal �迭�� ��ȸ, j�� cards1 �迭�� ��ȸ, k��cards2 �迭�� ��ȸ
    int j = 0;
    int k = 0;

    for (int i = 0; i < goal.size(); ++i) {      // ���ϴ� �ܾ� �迭(goal)���� ���ϴ� �ܾ �ϳ���(goal[i]) �˻�
        if (goal[i] == cards1[j]) {              // cards1 ��ġ�� ���� �� ��(cards1[j])�� ���ϴ� �ܾ��� ���
            ++j;                                 // ���������� �̵�.
            continue;
        }
        else if (goal[i] == cards2[k]) {         // cards2 ��ġ�� ���� �� ��(cards2[k])�� ���ϴ� �ܾ��� ���
            ++k;                                 // ���������� �̵�.
            continue;
        }
        else {                                   // �� ī�� ��ġ�� ���� �� �忡 ���ϴ� �ܾ ���� ��� ������ �ϼ��� �� ����.
            return "No";                         // -> Noooooooooooooooooooooooooooo
        }
    }
                                                 // for���� ����ߴ� -> ���ϴ� �ܾ� �迭�� ��� �˻� ������ No �� ��찡 ������ -> ���� �ϼ�
    return "Yes";                                // -> Yeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeesssssssssssss
}

#include <string>
#include <iostream>
#include <vector>

using namespace std;

// ���� ���ϱ� https://school.programmers.co.kr/learn/courses/30/lessons/76501

/*
���� ����
    � �������� �ֽ��ϴ�. 
    �� �������� ������ ���ʴ�� ���� ���� �迭 absolutes�� �� �������� ��ȣ�� ���ʴ�� ���� �Ҹ��� �迭 signs�� �Ű������� �־����ϴ�. 
    ���� �������� ���� ���Ͽ� return �ϵ��� solution �Լ��� �ϼ����ּ���.
*/

/*
���ѻ���
    absolutes�� ���̴� 1 �̻� 1,000 �����Դϴ�.
    absolutes�� ��� ���� ���� 1 �̻� 1,000 �����Դϴ�.
    signs�� ���̴� absolutes�� ���̿� �����ϴ�.
    signs[i] �� ���̸� absolutes[i] �� ���� ������ �������, �׷��� ������ �������� �ǹ��մϴ�.
*/

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;

    for (int i = 0; i < absolutes.size(); i++) {
        if (signs[i]) {
            answer += absolutes[i];
        }
        else {
            answer -= absolutes[i];
        }
    }

    return answer;
}

/*
int main() {
    vector<int> absolutes;
    vector<bool> signs;

    absolutes.push_back(4);
    absolutes.push_back(7);
    absolutes.push_back(12);

    signs.push_back(true);
    signs.push_back(false);
    signs.push_back(true);

    cout << solution(absolutes, signs) << endl;
}
*/


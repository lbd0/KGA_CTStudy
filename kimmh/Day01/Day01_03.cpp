#include <string>
#include <vector>
using namespace std;

// �ϻ����� �� https://school.programmers.co.kr/learn/courses/30/lessons/12947?language=cpp

/*
���� ����
    ���� ���� x�� �ϻ��� ���̷��� x�� �ڸ����� ������ x�� ���������� �մϴ�. 
    ���� ��� 18�� �ڸ��� ���� 1+8=9�̰�, 18�� 9�� ������ �������Ƿ� 18�� �ϻ��� ���Դϴ�. 
    �ڿ��� x�� �Է¹޾� x�� �ϻ��� ������ �ƴ��� �˻��ϴ� �Լ�, solution�� �ϼ����ּ���.
*/

/*
���� ����
    x�� 1 �̻�, 10000 ������ �����Դϴ�.
*/

bool solution(int x) {

    int copyx = x;
    int sum = 0;

    while (copyx > 0) {
        sum += copyx % 10;
        copyx /= 10;
    }

    return x % sum == 0 ? true : false;
}
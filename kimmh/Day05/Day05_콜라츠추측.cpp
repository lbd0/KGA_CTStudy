/*
    https://school.programmers.co.kr/learn/courses/30/lessons/12943
*/

#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    /*
        �� long�� ��°� ?
        int�� ������ -2,147,483,648 ~ 2,147,483,647 �̴�
        3��° �׽�Ʈ ���̽��� 626331�� ������ ���� 
        626331 -> 1878994-> ... -> 2139935758 -> 1069967879 -> 3209903638 -> 1604951819 -> 4814855458 ... �Ͱ��� ������ �Ѱܹ��� �ٸ� ���� ����Ǵ� ��찡 �����
    */ 
    
    long num2 = num;

    for (int i = 0; i < 500; i++) {
        if (num2 == 1) {
            return answer;
        }
        answer++;
        if (num2 % 2 == 0) {
            num2 /= 2;
        }
        else {
            num2 = num2 * 3 + 1;
        }
    }

    return -1;

}
/*
Q. ���ڿ� ����

���̰� ���� �� ���ڿ� str1�� str2�� �־����ϴ�.
�� ���ڿ��� �� ���ڰ� �տ������� ���� �����ư��鼭
�� ���� �����ϴ� ���ڿ��� ����� return �ϴ�
solution �Լ��� �ϼ��� �ּ���.
*/

#include <string>

std::string solution(std::string str1, std::string str2) {

    std::string answer = "";

    for (int i = 0; i < str1.length(); i++)
    {
        answer += str1[i];
        answer += str2[i];
    }

    return answer;
}
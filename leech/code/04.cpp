/*
Q. ���ڿ� ���ϱ�

���ڿ� my_string�� ���� k�� �־��� ��, 
my_string�� k�� �ݺ��� ���ڿ��� return �ϴ�
solution �Լ��� �ۼ��� �ּ���.
*/

#include <string>

std::string solution(std::string my_string, int k) {
    std::string answer = "";

    for (int i = 0; i < k; i++) answer += my_string;

    return answer;
}
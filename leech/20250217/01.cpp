/*
Q. ���ڿ� ���ľ���

���ڿ� my_string, overwrite_string�� ���� s�� �־����ϴ�.
���ڿ� my_string�� �ε��� s���� overwrite_string�� ���̸�ŭ��
���ڿ� overwrite_string���� �ٲ� ���ڿ��� return �ϴ�
solution �Լ��� �ۼ��� �ּ���.
*/

#include <string>

std::string solution(std::string my_string, std::string overwrite_string, int s) {
    return my_string.replace(s, overwrite_string.length(), overwrite_string);
}
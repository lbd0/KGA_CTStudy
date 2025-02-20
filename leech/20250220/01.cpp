/*
Q. �ڵ� ó���ϱ�

���ڿ� code�� �־����ϴ�.
code�� �տ������� �����鼭 ���� ���ڰ� "1"�̸� mode�� �ٲߴϴ�. mode�� ���� code�� �о�鼭 ���ڿ� ret�� �������ϴ�.

mode�� 0�� 1�� ������, idx�� 0 ���� code�� ���� - 1 ���� 1�� Ű�������鼭 code[idx]�� ���� ���� ������ ���� �ൿ�մϴ�.

mode�� 0�� ��
code[idx]�� "1"�� �ƴϸ� idx�� ¦���� ���� ret�� �� �ڿ� code[idx]�� �߰��մϴ�.
code[idx]�� "1"�̸� mode�� 0���� 1�� �ٲߴϴ�.
mode�� 1�� ��
code[idx]�� "1"�� �ƴϸ� idx�� Ȧ���� ���� ret�� �� �ڿ� code[idx]�� �߰��մϴ�.
code[idx]�� "1"�̸� mode�� 1���� 0���� �ٲߴϴ�.
���ڿ� code�� ���� ������� ���ڿ� ret�� return �ϴ� solution �Լ��� �ϼ��� �ּ���.

��, ������ �� mode�� 0�̸�, return �Ϸ��� ret�� ���� �� ���ڿ��̶�� ��� "EMPTY"�� return �մϴ�.
*/

#include <string>

std::string solution(std::string code) {
    std::string answer = "";
    char mode = '0';

    for (int i = 0; i < code.size(); ++i) {
        if (mode == '0') {
            if (code[i] == '1') mode = '1';
            else if (i % 2 == 0) answer += code[i];
        }
        else if (mode == '1') {
            if (code[i] == '0' || code[i] == '1') mode = '0';
            else if (i % 2 != 0) answer += code[i];
        }
    }

    return answer.empty() ? "EMPTY" : answer;
}
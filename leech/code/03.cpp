/*
Q. ���� ����Ʈ�� ���ڿ��� ��ȯ�ϱ�.

���ڵ��� ����ִ� �迭 arr�� �־����ϴ�.
arr�� ���ҵ��� ������� �̾� ���� ���ڿ���
return �ϴ� solution�Լ��� �ۼ��� �ּ���.
*/

#include <string>
#include <vector>

std::string solution(std::vector<std::string> arr) {
    std::string answer = "";

    for (int i = 0; i < arr.size(); i++)
    {
        answer += arr[i];
    }

    return answer;
}
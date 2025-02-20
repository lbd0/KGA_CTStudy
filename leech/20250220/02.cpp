/*
Q. ���������� Ư���� �׸� ���ϱ�

�� ���� a, d�� ���̰� n�� boolean �迭 included�� �־����ϴ�. 
ù°���� a, ������ d�� ������������ included[i]�� i + 1���� �ǹ��� ��, 
�� ���������� 1�׺��� n�ױ��� included�� true�� �׵鸸 ���� ���� return �ϴ� solution �Լ��� �ۼ��� �ּ���.
*/

#include <vector>

int solution(int a, int d, std::vector<bool> included) {
    int sum = 0;

    for (int i = 0; i < included.size(); ++i)
    {
        if (included[i]) sum += a;
        a += d;
    }

    return sum;
}
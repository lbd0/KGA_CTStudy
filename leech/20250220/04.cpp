/*
Q. ���ڿ� ���ϱ�

���ڿ� my_string�� ���� k�� �־��� ��,
my_string�� k�� �ݺ��� ���ڿ��� return �ϴ�
solution �Լ��� �ۼ��� �ּ���.
*/

#include <vector>
#include <cmath>

int solution(std::vector<int> num_list) {
    int add = 0, mul = 1;

    for (int a : num_list)
    {
        add += a;
        mul *= a;
    }

    return mul < pow(add, 2) ? 1 : 0;
}
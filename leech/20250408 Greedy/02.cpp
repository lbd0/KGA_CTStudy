#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;                 // ������ ���� �� �ִ� �л� ��
    vector<int> students(n, 1);     // ü������ ���� �л��� Ȯ���� �迭

    // �Ҿ���� �л� Ȯ��
    for (auto& l : lost)
    {
        --students[--l];    // �Ҿ���� �л��� -1
    }

    // ������ ü������ �ִ� �л� Ȯ��
    for (auto& r : reserve)
    {
        ++students[--r];    // ������ �ִ� �л��� +1
    }

    // ��ü �л��� ü���� �˻�
    for (int i = 0; i < n; ++i)
    {
        // ù ��° �л��� ���, ���� �л��� ��
        if (i == 0)
        {
            // ���� �л��� 2���̰�, ���� �л��� 0���� ��
            if (students[i] == 2 && students[i + 1] == 0)
            {
                --students[i];
                ++students[i + 1];
            }
        }
        // ������ �л��� ���, ���� �л��� ��
        else if (i == n - 1)
        {
            // ���� �л��� 2���̰�, ���� �л��� 0���� ��
            if (students[i] == 2 && students[i - 1] == 0)
            {
                --students[i];
                ++answer;
            }
        }
        // ������ �л��� ��
        else
        {
            // ���� �л��� 2���̰�, ���� �л��� 0���� ��
            if (students[i] == 2 && students[i - 1] == 0)
            {
                --students[i];
                ++answer;
            }
            // ���� �л��� 2���̰�, ���� �л��� 0���� ��
            if (students[i] == 2 && students[i + 1] == 0)
            {
                --students[i];
                ++students[i + 1];
            }
        }

        // ���� �л��� 1�� �̻��� �ִٸ� ������ ���� �� �ִ� �л�
        students[i] >= 1 ? ++answer : answer;
    }

    // ������ ���� �� �ִ� �л� �� ��ȯ
    return answer;
}
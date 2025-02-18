/*
    https://school.programmers.co.kr/learn/courses/30/lessons/17681
    ��Ʈ�������� �����ϰ� Ǯ���� ������� ���� �� ���� �Ҿ���
    �ٸ� ����� ����� ���� ���� Ǯ�̴� �ƴѰ� ����
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

/// <summary>
/// �������� ���ϴ� �Լ�
/// </summary>
/// <param name="n">�������� ����</param>
/// <param name="intValue">�������� ���� ��</param>
/// <returns>intValue�� n�ڸ� �������� ��ȯ�� ��</returns>
string Binary(int n, int intValue) {
    string tempString = "";

    while (intValue != 0) {
        tempString.insert(0, to_string(intValue % 2));
        intValue /= 2;
    }

    int tempStringLength = tempString.length();

    if (tempString.length() < n) {
        for (int i = 0; i < n - tempStringLength; i++) {
            tempString.insert(0, "0");
        }
    }

    return tempString;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<string> map1;
    vector<string> map2;

    for (int temp : arr1) {
        map1.push_back(Binary(n, temp));
    }

    for (int temp : arr2) {
        map2.push_back(Binary(n, temp));
    }

    string temp = "";

    for (int i = 0; i < n; i++) {
        temp = "";
        for (int j = 0; j < n; j++) {
            if (map1[i][j] == map2[i][j] && map1[i][j] == '0') {
                temp += " ";
            }
            else {
                temp += "#";
            }
        }
        answer.push_back(temp);
    }

    return answer;
}
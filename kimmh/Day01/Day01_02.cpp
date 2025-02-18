#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// ���� ���� �� �����ϱ� https://school.programmers.co.kr/learn/courses/30/lessons/12935?language=cpp

/*
���� ����
    ������ ������ �迭, arr ���� ���� ���� ���� ������ �迭�� �����ϴ� �Լ�, solution�� �ϼ����ּ���. 
    ��, �����Ϸ��� �迭�� �� �迭�� ��쿣 �迭�� -1�� ä�� �����ϼ���. 
    ������� arr�� [4,3,2,1]�� ���� [4,3,2]�� ���� �ϰ�, [10]�� [-1]�� ���� �մϴ�.
*/
    
/* 
���� ����
    arr�� ���� 1 �̻��� �迭�Դϴ�.
    �ε��� i, j�� ���� i �� j�̸� arr[i] �� arr[j] �Դϴ�.
*/

vector<int> solution(vector<int> arr) {
    vector<int> answer;

    if (arr.size() == 1) {
        answer.push_back(-1);
        return answer;
    }
    else {
        int minIndex = min_element(arr.begin(), arr.end()) - arr.begin();
        arr.erase(arr.begin() + minIndex);
        return arr;
    }
    return answer;
}